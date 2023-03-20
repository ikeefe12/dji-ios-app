// The goal of this class is to create the ability to stream data from local UDP port, display the data, and communicate with the drone at the same time.
// Intended use:
// In CameraFPVViewController.swift create an instance of this class when the view is loaded
// In the thermalData button handler within CameraFPVViewController.swift, call enableThermalDataAndDisplay or disableThermalDataAndDisplay depending on button state.
// In the startTracking button handler within CameraFPVViewController.swift, call startTracking
// In the stopTracking button handler within CameraFPVViewController.swift, call stopTracking
import UIKit
import DJISDK
import CoreGraphics
import CocoaAsyncSocket

class HeatSeeking: NSObject, GCDAsyncUdpSocketDelegate {
    // object from which to send drone commands
    private var droneCommand: DroneCommand
    // Wifi socket from which data is read
    private var udpSocketManager: UDPSocketManager
    private var imageView: UIImageView?
    private let getFrameSemaphore = DispatchSemaphore(value: 0)
    // THREADS
    private var dataThread: Thread?
    private var commandThread: Thread?

    // SHARED VARIABLES
    private var sharedVars: SharedVars
    
    override init() {
        // SHARED VARIABLEs Initialized
        sharedVars = SharedVars(frameWidth: UDPSocketManager.frameWidth, frameHeight: UDPSocketManager.frameHeight)
        // Drone Command Object
        droneCommand = DroneCommand()
        // Initialize UDP port
        udpSocketManager = UDPSocketManager()
        super.init()
    }
    
    // This will start streaming data as well as displaying data
    @objc func enableThermalDataAndDisplay(view: UIView) {
        // Create a UIImageView
        imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: UDPSocketManager.frameWidth, height: UDPSocketManager.frameHeight))
        imageView?.contentMode = .scaleAspectFit
        view.addSubview(imageView!)
        
        dataThread = Thread(target: self, selector: #selector(getData), object: nil)
        dataThread?.start()
    }
    
    // Stop streaming data
    @objc func disableThermalDataAndDisplay() {
        dataThread?.cancel()
        dataThread = nil
    }
    
    // start sending commands to the drone, this should only run if the dataThread is running
    @objc func startTracking() {
        // enable virtual sticks on the drone
        droneCommand.toggleVirtualSticks(enabled: true)
        commandThread = Thread(target: self, selector: #selector(sendCommand), object: nil)
        commandThread?.start()
    }
    
    // stop tracking
    @objc func stopTracking() {
        commandThread?.cancel()
        // disable virtual stick commmand of the drone
        droneCommand.toggleVirtualSticks(enabled: false)
        commandThread = nil
    }
    
    @objc private func getData() {
        while !Thread.current.isCancelled {
            autoreleasepool {
                // get processed data (120x84 array of ints)
                udpSocketManager.getFrame { (frameString: String) in
                    // Process Data
                    let frame = self.formatData(hexStr: frameString)
                    // Display Data
                    DispatchQueue.main.async {
                        self.dispData(frame: frame)
                    }
                    
                    self.getFrameSemaphore.signal()
                }
                
                self.getFrameSemaphore.wait()
                
                print("Done")
               
                // Pass data through tracking algorithm (findTrackingCommands is a function TO BE added to this class,
                // which takes a 120x84 array of Ints and returns a tuple (Float, Float) representing the tracking roll and pitch)
            }
        }
    }
    
    // displayThread base function
    @objc func dispData(frame: [[Int]]) {
        guard let imageView = self.imageView else {
            return
        }
        
        print("Display New Frame")
        let gray16Image = frame //thermalData.grey16Image
            
        //  release the memory used by the images at the end of each iteration of the loop
        autoreleasepool {
            // Create a CGContext and draw the pixel values to it
            let colorSpace = CGColorSpaceCreateDeviceGray()
            let bytesPerPixel = MemoryLayout<UInt16>.stride
            let bytesPerRow = bytesPerPixel * UDPSocketManager.frameWidth
            let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.none.rawValue)
            let context = CGContext(data: nil, width: UDPSocketManager.frameWidth, height: UDPSocketManager.frameHeight, bitsPerComponent: 16, bytesPerRow: bytesPerRow, space: colorSpace, bitmapInfo: bitmapInfo.rawValue)!
            context.drawGray16Image(gray16Image)

            // Create a CGImage from the CGContext
            guard let cgImage = context.makeImage() else {
                fatalError("Failed to create CGImage.")
            }

            // Create a UIImage from the CGImage
            let image = UIImage(cgImage: cgImage)

            // Update the UIImageView with the new image
            imageView.image = image
        }
    }
    
    // commandThread base function
    @objc private func sendCommand() {
        var commandRoll : Float = 0.0
        var commandPitch : Float = 0.0
        while !Thread.current.isCancelled {
            print("Command Thread")
            if sharedVars.getNewCommands() {
                print("New Commands:")
                // SHARED VARIABLES
               (commandRoll, commandPitch) = sharedVars.getRollPitch()
               // set newCommands flag to false, allowing the following loop to loop until the other thread sets it back to true
               sharedVars.setNewCommands(false)
                print(commandRoll)
                print(commandPitch)
            }
            sendDroneControlData(commandRoll: commandRoll, commandPitch: commandPitch)
        }
    }

    @objc private func sendDroneControlData(commandRoll: Float, commandPitch: Float) {
        droneCommand.sendControlData(throttle: 0.0, pitch: commandPitch, roll: commandRoll, yaw: 0.0)
        Thread.sleep(forTimeInterval: 0.05) // Sleep for 50 milliseconds to achieve 20Hz frequency
    }
    
    
    @objc private func findTrackingCommands(_ frame: [[Int]]) -> CGPoint {
        // Implement the tracking algorithm here
        // NORMALIZE DATA (normalizeTemperatures)
        let normData = normalizeTemperatures(thermalImage: frame)
        // FIND COORDINATES (findCenterOfHeat)
        let (x, y) = findCenterOfHeat(thermalImage: normData)
        // DECIDE ON COMMANDS
        let xNorm = Double(x) / 119.0 - 0.5
        let yNorm = Double(y) / 83.0 - 0.5
        
        var roll = 0.0
        var pitch = 0.0
        
        if xNorm > 0.1 {
            pitch = 1.0
        } else if xNorm < -0.1 {
            pitch = -1.0
        }
        
        if yNorm > 0.1 {
            roll = 1.0
        } else if yNorm < -0.1 {
            roll = -1.0
        }
        
        return CGPoint(x: roll, y: pitch) // Replace with real values calculated from the tracking algorithm
    }
    
    // Takes a hex string of bytes representing 1 thermal image and returns the 120x84 array of grey16 data
    // TESTED
    func formatData(hexStr: String) -> [[Int]] {
        let numCols = UDPSocketManager.frameWidth

        let hexPairs = stride(from: 0, to: hexStr.count, by: 4).compactMap { i -> Int? in
            let start = hexStr.index(hexStr.startIndex, offsetBy: i)
            let end = min(hexStr.index(start, offsetBy: 4), hexStr.endIndex)
            let substring = String(hexStr[start..<end])
            return Int(substring, radix: 16)
        }

        let reformattedArray = stride(from: 0, to: hexPairs.count, by: numCols).map { rowStart -> [Int] in
            let rowEnd = min(rowStart + numCols, hexPairs.count)
            return Array(hexPairs[rowStart..<rowEnd])
        }

        return reformattedArray
    }
    
    // Normalizes the temperature values of thermal image so they are betwee 0 and 1
    // TESTED
    func normalizeTemperatures(thermalImage: [[Int]]) -> [[Double]] {
        let numRows = UDPSocketManager.frameHeight
        let numCols = UDPSocketManager.frameWidth

        // Find the minimum and maximum values
        var minValue = Int.max
        var maxValue = Int.min

        for row in thermalImage {
            for value in row {
                minValue = min(minValue, value)
                maxValue = max(maxValue, value)
            }
        }

        // Normalize the temperature data
        var normalizedThermalImage: [[Double]] = Array(repeating: Array(repeating: 0.0, count: numCols), count: numRows)

        for i in 0..<numRows {
            for j in 0..<numCols {
                normalizedThermalImage[i][j] = (Double(thermalImage[i][j]) - Double(minValue)) / (Double(maxValue) - Double(minValue))
            }
        }

        return normalizedThermalImage
    }
    
    // This function takes in the normalized data and returns the average position of coordinates above threshhold value
    // TESTED
    func findCenterOfHeat(thermalImage: [[Double]], threshold: Double = 0.85     ) -> (Int, Int) {
        // Find the maximum value in the image
        var coordinates: [[Int]] = []

        // Iterate through all pixels in the image
        for x in 0..<thermalImage.count {
            for y in 0..<thermalImage[0].count {
                // Check if the pixel is above the threshold
                if thermalImage[x][y] >= threshold {
                    coordinates.append([x, y])
                }
            }
        }

        // Calculate the center position
        let centerX = Int(round(Double(coordinates.map { $0[0] }.reduce(0, +)) / Double(coordinates.count)))
        let centerY = Int(round(Double(coordinates.map { $0[1] }.reduce(0, +)) / Double(coordinates.count)))

        return (centerX, centerY)
    }
}

class UDPSocketManager: NSObject, GCDAsyncUdpSocketDelegate {
    static let frameWidth = 120
    static let frameHeight = 84
    private let IP_ADDRESS = "192.168.0.120"
    private let PORT: UInt16 = 30444
    var udpSocket: GCDAsyncUdpSocket?
    private var packetsReceived = -1
    private var frame: [String]
    private let dispatchQueue = DispatchQueue(label: "udpSocketQueue")

    override init() {
        let initialHexString = String(repeating: "00", count: 480)
        frame = Array(repeating: initialHexString, count: 21)
        
        super.init()
        
        // Initialize UDP socket
        do {
            udpSocket = GCDAsyncUdpSocket(delegate: self, delegateQueue: dispatchQueue)
            try udpSocket?.bind(toPort: PORT)
            try udpSocket?.connect(toHost: IP_ADDRESS, onPort: PORT)
            try udpSocket?.beginReceiving()

            // Send "Bind HTPA series device" command
            print("send data: BIND")
            sendString("Bind HTPA series device")

            // Send "K" command
            print("send data: TRIGGER")
            sendString("K")
        } catch {
            print("Error initializing UDP socket: \(error)")
        }
    }
    
    @objc func getFrame(completion: @escaping (String) -> Void) {
        print("Getting Frame Now")
        packetsReceived = 0
        
        do {
            try udpSocket?.beginReceiving()
        } catch {
            print("Error receiving frame: \(error)")
        }
        
        sendString("N")
        
        dispatchQueue.async { [weak self] in
            while self?.packetsReceived < 21 {
                // Wait for packets to be received
            }
            
            self?.udpSocket?.pauseReceiving()
            let frameString = self?.frame.joined() ?? ""
            completion(frameString)
        }
    }
    
    // SOCKET FUNCTIONS
    private func sendData(_ data: Data) {
        udpSocket?.send(data, withTimeout: -1, tag: 0)
    }

    private func sendString(_ string: String) {
        if let data = string.data(using: .utf8) {
            sendData(data)
        }
    }
    
    func udpSocket(_ sock: GCDAsyncUdpSocket, didReceive data: Data, fromAddress address: Data, withFilterContext filterContext: Any?) {
        packetsReceived = packetsReceived + 1
        if packetsReceived == 0 {
            print("Initialization Complete")
            udpSocket?.pauseReceiving()
        } else if packetsReceived > 0 {
            print("Received data packet: \(packetsReceived)")
            let hexData = data.hexString
            let packetNumber = UInt8(hexData.prefix(2), radix: 16)! - 1
            let startIndex = hexData.index(hexData.startIndex, offsetBy: 2)
            print(packetNumber)
            frame[Int(packetNumber)] = String(hexData[startIndex...])
        }
    }
}

class SharedVars {
    private let queue = DispatchQueue(label: "com.example.HeatSeeking.sharedVarQueue", attributes: .concurrent)
    private var _newCommands: Bool = false
    private var _newFrame: Bool = true
    private var _latestFrame: [[Int]]
    private var _roll: Float = 0
    private var _pitch: Float = 0

    // Initialize the shared variables
    init(frameWidth: Int, frameHeight: Int) {
        _latestFrame = [[Int]](repeating: [Int](repeating: 0, count: frameHeight), count: frameWidth)
    }

    // SHARED VARIABLE ACCESS FUNCTIONS
    func setNewCommands(_ value: Bool) {
        queue.async(flags: .barrier) {
            self._newCommands = value
        }
    }
    
    func setRollPitch(_ roll: Float, _ pitch: Float) {
        queue.async(flags: .barrier) {
            self._roll = roll
            self._pitch = pitch
        }
    }
    
    func getNewCommands() -> Bool {
        return queue.sync {
            return _newCommands
        }
    }
    
    func getRollPitch() -> (Float, Float) {
        return queue.sync {
            return (_roll, _pitch)
        }
    }
}

extension CGContext {
    func drawGray16Image(_ gray16Image: [[Int]]) {
        let width = gray16Image.count
        let height = gray16Image[0].count
        for x in 0..<width {
            for y in 0..<height {
                let value = UInt16(gray16Image[x][y])
                let byteOffset = x * height * 2 + y * 2
                data?.storeBytes(of: value, toByteOffset: byteOffset, as: UInt16.self)
            }
        }
    }
}

extension Data {
    var hexString: String {
        return self.map {String(format: "%02x", $0)}.joined()
    }
}


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
        sharedVars = SharedVars()
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
        
        adjustImageView(view: view)
        
        dataThread = Thread(target: self, selector: #selector(getData), object: nil)
        dataThread?.start()
    }
    
    func adjustImageView(view: UIView) {
        guard let imageView = self.imageView else {
            return
        }
        let newOriginX = CGFloat(30)
        let newWidth = imageView.frame.width * 3
        let newHeight = imageView.frame.height * 3
        let newOriginY = (view.frame.height - newHeight)/2
        imageView.frame = CGRect(origin: CGPoint(x: newOriginX, y: newOriginY), size: CGSize(width: newWidth, height: newHeight))
    }
    
    // Stop streaming data
    @objc func disableThermalDataAndDisplay() {
        dataThread?.cancel()
        dataThread = nil
    }
    
    @objc func emergencyLanding(){
        print("LANDING REQUEST")
        droneCommand.emergencyLand()
    }
    
    // start sending commands to the drone, this should only run if the dataThread is running
    @objc func startTracking() {
        // enable virtual sticks on the drone
        droneCommand.enableVirtualSticks()
        commandThread = Thread(target: self, selector: #selector(sendCommand), object: nil)
        commandThread?.start()
    }
    
    // stop tracking
    @objc func stopTracking() {
        commandThread?.cancel()
        // disable virtual stick commmand of the drone
        droneCommand.disableVirtualSticks()
        commandThread = nil
    }
    
    @objc private func getData() {
        while !Thread.current.isCancelled {
            autoreleasepool {
                print("Getting Frame")
                // get processed data (120x84 array of ints)
                udpSocketManager.getFrame { (frameString: String) in
                    // Check correct amount of data recieved
                    if let stringData = frameString.data(using: .utf8) {
                        if stringData.count == 40320 {
                            print("Frame Recieved")
                        } else {
                            print("Invalid Frame")
                            print(stringData.count)
                            self.getFrameSemaphore.signal()
                            return
                        }
                    } else {
                        print("Invalid Frame")
                        self.getFrameSemaphore.signal()
                        return
                    }
                    
                    // Process Data
                    let intFrame = self.formatData(hexStr: frameString)
                    let normFrame = self.normalizeTemperatures(thermalImage: intFrame)
                    print("Frame Processed")
                    // Get and save tracking commands
                    let (x, y) = self.findCenterOfHeat(thermalImage: (normFrame))
                    let (commandPitch, commandRoll) = self.getFlightCommand(x: x,y: y)
                    
                    self.sharedVars.setCommand(commandPitch, commandRoll)
                    self.sharedVars.setNewCommand(true)
                    
                    print("Tracking Commands Set")
                    
                    // Display Data
                    DispatchQueue.main.async {
                        self.dispData(frame: normFrame)
                    }
                    self.getFrameSemaphore.signal()
                }
                
                self.getFrameSemaphore.wait()
            }
        }
    }
    
    // displayThread base function
    @objc func dispData(frame: [[Double]]) {
        guard let imageView = self.imageView else {
            return
        }

        let (xSpeed, ySpeed) = sharedVars.getCommand()

        print("Display New Frame")
        let normalizedImage = frame

        autoreleasepool {
            let colorSpace = CGColorSpaceCreateDeviceRGB()
            let bytesPerPixel = 4
            let bytesPerRow = bytesPerPixel * UDPSocketManager.frameWidth
            let bitmapInfo = CGBitmapInfo.byteOrder32Big.rawValue | CGImageAlphaInfo.premultipliedLast.rawValue
            let context = CGContext(data: nil, width: UDPSocketManager.frameWidth, height: UDPSocketManager.frameHeight, bitsPerComponent: 8, bytesPerRow: bytesPerRow, space: colorSpace, bitmapInfo: bitmapInfo)!

            for (i, row) in normalizedImage.enumerated() {
                for (j, value) in row.enumerated() {
                    let (r, g, b) = jetColorMap(value)
                    context.setFillColor(CGColor(red: CGFloat(r) / 255.0, green: CGFloat(g) / 255.0, blue: CGFloat(b) / 255.0, alpha: 1.0))
                    context.fill(CGRect(x: j, y: UDPSocketManager.frameHeight-1-i, width: 1, height: 1))
                }
            }
            
            // Draw the vector
            let centerX = CGFloat(UDPSocketManager.frameWidth / 2)
            let centerY = CGFloat(UDPSocketManager.frameHeight / 2)
            let vectorEndX = centerX + (CGFloat(xSpeed) * centerX / 2.0)
            let vectorEndY = centerY - (CGFloat(ySpeed) * centerY / 2.0) // Subtract ySpeed to account for the inverted y-axis

            context.setLineWidth(1=a    w2
            context.setStrokeColor(UIColor.black.cgColor)
            context.move(to: CGPoint(x: centerX, y: centerY))
            context.addLine(to: CGPoint(x: vectorEndX, y: vectorEndY))
            context.strokePath()

            guard let cgImage = context.makeImage() else {
                fatalError("Failed to create CGImage.")
            }

            let image = UIImage(cgImage: cgImage)
            imageView.image = image
        }
    }
    
    // commandThread base function
    @objc private func sendCommand() {
        var commandRoll : Float = 0.0
        var commandPitch : Float = 0.0
        while !Thread.current.isCancelled {
            if sharedVars.getNewCommand() {
                // SHARED VARIABLES
                (commandPitch, commandRoll) = sharedVars.getCommand()
               // set newCommands flag to false, allowing the following loop to loop until the other thread sets it back to true
               sharedVars.setNewCommand(false)
            }
            sendDroneControlData(commandRoll: commandRoll, commandPitch: commandPitch)
        }
    }

    @objc private func sendDroneControlData(commandRoll: Float, commandPitch: Float) {
        droneCommand.sendControlData(throttle: 0.0, pitch: commandPitch, roll: commandRoll, yaw: 0.0)
        Thread.sleep(forTimeInterval: 0.05) // Sleep for 50 milliseconds to achieve 20Hz frequency
    }
    
    private func getFlightCommand(x: Int, y: Int) -> (Float, Float) {
        var commandRoll = Float(0.0)
        var commandPitch = Float(0.0)
        var normalizedX = (Float(x)/119.0) - 0.5
        var normalizedY = (Float(y)/83.0) - 0.5
        
        // convert normalized coordinate to +/-(1.0,2.0,3.0,4.0) and multiply by 0.5 to get speed
        if (abs(normalizedX) > 0.1 && abs(normalizedX) < 0.5) {
            normalizedX = Float(Int(normalizedX * 10))
            commandPitch = normalizedX * 0.5
        }
        
        if (abs(normalizedY) > 0.1 && abs(normalizedY) < 0.5) {
            normalizedY = Float(Int(normalizedY * 10))
            commandRoll = normalizedY * 0.5
        }
        
        return (commandPitch, commandRoll)
    }
    
    // Takes a hex string of bytes representing 1 thermal image and returns the 120x84 array of grey16 data
    // TESTED
    
    func formatData(hexStr: String) -> [[Int]] {
        let numCols = UDPSocketManager.frameWidth

        func hexValue(_ char: Character) -> Int? {
            switch char {
            case "0"..."9": return Int(String(char))
            case "a"..."f": return 10 + Int(char.asciiValue!) - Int(Character("a").asciiValue!)
            case "A"..."F": return 10 + Int(char.asciiValue!) - Int(Character("A").asciiValue!)
            default: return nil
            }
        }

        func hexPairValue(_ chars: ArraySlice<Character>) -> Int? {
            guard chars.count == 4,
                  let first = hexValue(chars[chars.startIndex]),
                  let second = hexValue(chars[chars.startIndex + 1]),
                  let third = hexValue(chars[chars.startIndex + 2]),
                  let fourth = hexValue(chars[chars.startIndex + 3]) else {
                return nil
            }
            return (first << 12) | (second << 8) | (third << 4) | fourth
        }

        let hexChars = Array(hexStr)
        let hexPairs = stride(from: 0, to: hexChars.count, by: 4).compactMap { i -> Int? in
            hexPairValue(hexChars[i..<min(i + 4, hexChars.count)])
        }

        let reformattedArray = stride(from: 0, to: hexPairs.count, by: numCols).map { rowStart -> [Int] in
            let rowEnd = min(rowStart + numCols, hexPairs.count)
            return Array(hexPairs[rowStart..<rowEnd]).reversed()
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
        let centerY = Int(round(Double(coordinates.map { $0[0] }.reduce(0, +)) / Double(coordinates.count)))
        let centerX = Int(round(Double(coordinates.map { $0[1] }.reduce(0, +)) / Double(coordinates.count)))

        return (centerX, centerY)
    }
    
    func jetColorMap(_ value: Double) -> (UInt8, UInt8, UInt8) {
        let numberOfColors = 4
        let t = value * CGFloat(numberOfColors - 1)

        let r = UInt8(min(max(1.5 - abs(t - 1), 0), 1) * 255)
        let g = UInt8(min(max(1.5 - abs(t - 2), 0), 1) * 255)
        let b = UInt8(min(max(1.5 - abs(t - 3), 0), 1) * 255)

        return (r, g, b)
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
    private let semaphore = DispatchSemaphore(value: 0)

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
        packetsReceived = 0
        sendString("N")

        do {
            try self.udpSocket?.beginReceiving()
        } catch {
            print("Error receiving frame: \(error)")
        }
        
        while packetsReceived < 21 {
            // Wait for packets to be received
            let result = semaphore.wait(timeout: .now() + 0.5)
            
            if result == .timedOut {
                completion(String())
                return
            }
        }

        udpSocket?.pauseReceiving()
        let frameString = frame.joined()
        completion(frameString)
    }
    
    func udpSocket(_ sock: GCDAsyncUdpSocket, didReceive data: Data, fromAddress address: Data, withFilterContext filterContext: Any?) {
        if packetsReceived == -1 {
            packetsReceived = packetsReceived + 1
            print("Initialization Complete")
        } else if packetsReceived >= 0 {
            let hexData = data.hexString
            let packetNumber = UInt8(hexData.prefix(2), radix: 16)! - 1
            let startIndex = hexData.index(hexData.startIndex, offsetBy: 2)
            frame[Int(packetNumber)] = String(hexData[startIndex...])
            print(packetsReceived)
            print("Received data packet: \(packetNumber)")
            packetsReceived = packetsReceived + 1
            semaphore.signal()
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
}

class SharedVars {
    private let queue = DispatchQueue(label: "com.example.HeatSeeking.sharedVarQueue", attributes: .concurrent)
    private var _newLocation: Bool = false
    private var _x: Float = 0
    private var _y: Float = 0

    // Initialize the shared variables
    init() {
    }

    // SHARED VARIABLE ACCESS FUNCTIONS
    func setNewCommand(_ value: Bool) {
        queue.async(flags: .barrier) {
            self._newLocation = value
        }
    }
    
    func setCommand(_ x: Float, _ y: Float) {
        queue.async(flags: .barrier) {
            self._x = x
            self._y = y
        }
    }
    
    func getNewCommand() -> Bool {
        return queue.sync {
            return _newLocation
        }
    }
    
    func getCommand() -> (Float, Float) {
        return queue.sync {
            return (_x, _y)
        }
    }
}

extension Data {
    var hexString: String {
        return self.map {String(format: "%02x", $0)}.joined()
    }
}


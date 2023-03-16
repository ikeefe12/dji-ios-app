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
    // THREADS
    private var dataThread: Thread?
    private var displayThread: Thread?
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
        dataThread = Thread(target: self, selector: #selector(getData), object: nil)
        dataThread?.start()
        
        displayThread = Thread(target: self, selector: #selector(dispData(view:)), object: nil)
        displayThread?.start()
    }
    
    // Stop streaming data
    @objc func disableThermalDataAndDisplay() {
        dataThread?.cancel()
        displayThread?.cancel()
        dataThread = nil
        displayThread = nil
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
                let binData = udpSocketManager.getFrame()
                // TODO: Set default value since binData is optional
                let frame = formatData(binData ?? Data())
                // Save data to shared variable latesFrame so it can be used in displayThread
                sharedVars.setLatestFrame(frame)
                sharedVars.setNewFrame(true)
                // Pass data through tracking algorithm (findTrackingCommands is a function TO BE added to this class,
                // which takes a 120x84 array of Ints and returns a tuple (Float, Float) representing the tracking roll and pitch)
                let command = findTrackingCommands(frame)
                let newRoll = Float(command.x)
                let newPitch = Float(command.y)
                // Save result in shared variables roll and pitch
                sharedVars.setRollPitch(newRoll, newPitch)
                // set newCommands flag to true, indicating to the sendCommand thread to break the loop and update local command variables
                sharedVars.setNewCommands(true)
            }
        }
    }
    
    // displayThread base function
    @objc private func dispData(view: UIView) {

        // Create a UIImageView
        let imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: UDPSocketManager.frameWidth, height: UDPSocketManager.frameHeight))
        imageView.contentMode = .scaleAspectFit
        view.addSubview(imageView)
        
        while !Thread.current.isCancelled {
            if sharedVars.getNewFrame() {
                let gray16Image = sharedVars.getLatestFrame()
                sharedVars.setNewFrame(false)
                
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
        }
        
        
    }
    
    // commandThread base function
    @objc private func sendCommand() {
        var commandRoll : Float = 0.0
        var commandPitch : Float = 0.0
        while !Thread.current.isCancelled {
            if sharedVars.getNewCommands() {
               // SHARED VARIABLES
               (commandRoll, commandPitch) = sharedVars.getRollPitch()
               // set newCommands flag to false, allowing the following loop to loop until the other thread sets it back to true
               sharedVars.setNewCommands(false)
            }
            sendDroneControlData(commandRoll: commandRoll, commandPitch: commandPitch)
        }
    }

    @objc private func sendDroneControlData(commandRoll: Float, commandPitch: Float) {
        droneCommand.sendControlData(throttle: 0.0, pitch: commandPitch, roll: commandRoll, yaw: 0.0)
        Thread.sleep(forTimeInterval: 0.05) // Sleep for 50 milliseconds to achieve 20Hz frequency
    }
    
    @objc func formatData(_ dataBinary: Data) -> [[Int]] {
        let hexStr = dataBinary.map { String(format: "%02hhx", $0) }.joined()
        var numbers = [String]()
        for i in stride(from: 0, to: hexStr.count, by: 4) {
            let startIndex = hexStr.index(hexStr.startIndex, offsetBy: i)
            let endIndex = hexStr.index(startIndex, offsetBy: 4, limitedBy: hexStr.endIndex) ?? hexStr.endIndex
            numbers.append(String(hexStr[startIndex..<endIndex]))
        }
        let intNumbers = numbers.compactMap { Int($0, radix: 16) }
        var result = [[Int]](repeating: [Int](repeating: 0, count: UDPSocketManager.frameHeight), count: UDPSocketManager.frameWidth)
        for i in 0..<UDPSocketManager.frameWidth {
            for j in 0..<UDPSocketManager.frameHeight {
                result[i][j] = intNumbers[j *  UDPSocketManager.frameWidth + i]
            }
        }
        return result
    }
    
    @objc private func findTrackingCommands(_ frame: [[Int]]) -> CGPoint {
        // Implement the tracking algorithm here
        return CGPoint(x: 0.0, y: 0.0) // Replace with real values calculated from the tracking algorithm
    }
}

class UDPSocketManager: NSObject, GCDAsyncUdpSocketDelegate {
    static let frameWidth = 120
    static let frameHeight = 84
    private let IP_ADDRESS = "192.168.0.120"
    private let PORT: UInt16 = 30444
    var udpSocket: GCDAsyncUdpSocket?

    override init() {
        super.init()
        
        // Initialize UDP socket
        do {
            // Initialize UDP socket
            udpSocket = GCDAsyncUdpSocket(delegate: self, delegateQueue: DispatchQueue.global(qos: .background))
            try udpSocket?.bind(toPort: PORT)
            try udpSocket?.connect(toHost: IP_ADDRESS, onPort: PORT)
            // Send "Bind HTPA series device" command
            print("send data: BIND")
            sendString("Bind HTPA series device")

            // Receive data
            try udpSocket?.receiveOnce()

            // Send "K" command
            print("send data: TRIGGER")
            sendString("K")
        } catch {
            print("Error initializing UDP socket: \(error)")
        }
    }
    
    enum UPDError: Error {
        case bindError
        case connectError
    }
    
    // Get Binary Frame data
    @objc func getFrame() -> Data? {
        print("Receiving THERMAL IMAGE")
    
        // Prepare data buffer and packet information
        var data = Data()
        let numPackets = 21
        // var packetsReceived = 0

        // Send "N" command to request next frame (21 packets)
        sendString("N")
        /* while packetsReceived < numPackets {// Set up semaphore for waiting for data
            let semaphore = DispatchSemaphore(value: 0)
            var receivedData: Data?
            var receivedAddress: Data?

            udpSocket?.receiveOnce { (newData: Data?, address: Data?, _: Error?, _: Bool) in
                receivedData = newData
                receivedAddress = address
                semaphore.signal()
            }

            // Wait for data (timeout after 0.5 second)
            let result = semaphore.wait(timeout: .now() + 0.5)

            if result == .success, let newData = receivedData {
                data.append(newData[1...])
                packetsReceived += 1
            } else {
                print("Socket timed out waiting for thermal image")
                return nil
            }
        }
        return data */
        return data
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
        let receivedString = String(data: data, encoding: .utf8)
        print("Received data: \(receivedString ?? "nil")")
    }
}

class SharedVars {
    private let queue = DispatchQueue(label: "com.example.HeatSeeking.sharedVarQueue", attributes: .concurrent)
    private var _newCommands: Bool = false
    private var _newFrame: Bool = false
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
    
    func setNewFrame(_ value: Bool) {
        queue.async(flags: .barrier) {
            self._newFrame = value
        }
    }
    
    func setLatestFrame(_ value: [[Int]]) {
        queue.async(flags: .barrier) {
            self._latestFrame = value
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
    
    func getNewFrame() -> Bool {
        return queue.sync {
            return _newFrame
        }
    }
    
    func getLatestFrame() -> [[Int]] {
        return queue.sync {
            return _latestFrame
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
        for y in 0..<height {
            for x in 0..<width {
                let value = UInt16(gray16Image[x][y])
                let byteOffset = y * width * 2 + x * 2
                data?.storeBytes(of: value, toByteOffset: byteOffset, as: UInt16.self)
            }
        }
    }
}

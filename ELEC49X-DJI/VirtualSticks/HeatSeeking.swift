// The goal of this class is to create the ability to stream data from local UDP port, display the data, and communicate with the drone at the same time. 
// Intended use:
// In CameraFPVViewController.swift create an instance of this class when the view is loaded
// In the thermalData button handler within CameraFPVViewController.swift, call enableThermalDataAndDisplay or disableThermalDataAndDisplay depending on button state.
// In the startTracking button handler within CameraFPVViewController.swift, call startTracking
// In the stopTracking button handler within CameraFPVViewController.swift, call stopTracking
import UIKit
import DJISDK

class HeatSeeking {
    // instance of DroneCommand class that has the capabilities to send commands to the drone
    var droneCommand: DroneCommand
    // Wifi socket from which data is read
    var udpSocket: GCDAsyncUdpSocket?
    // three threads that will run in parallel
    var dataThread: Thread?
    var displayThread: Thread?
    var commandThread: Thread?
    private let frameWidth = 120
    private let frameHeight = 84
    // SHARED VARIABLES
    private var sharedVars: SharedVars
    
    init() {
        // SHARED VARIABLE Initialized
        sharedVars = SharedVars(frameWidth: frameWidth, frameHeight: frameHeight)
        // this calls the init() function of DroneCommand and gives us an instance of the object from which we can call functions to control DJI drone
        droneCommand = DroneCommand()
        // Initialize UDP port 
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
    }
    
    // start sending commands to the drone, this should only run if the dataThread is running
    @objc func startTracking() {
        // enable virtual sticks on the drone
        droneCommand.toggleVirtualSticks(true)
        commandThread = Thread(target: self, selector: #selector(sendCommand), object: nil)
        commandThread?.start()
    }
    
    // stop tracking
    @objc func stopTracking() {
        commandThread?.cancel()
        // disable virtual stick commmand of the drone
        droneCommand?.toggleVirtualSticks(false)
    }
    
    @objc private func getData() {
        while !Thread.current.isCancelled {
            autoreleasepool {
                // get processed data (120x84 array of ints)
                let frame = sharedVars.getFrame()
                // Save data to shared variable latesFrame so it can be used in displayThread
                sharedVars.setLatestFrame(frame)
                sharedVars.setNewFrame(true)
                // Pass data through tracking algorithm (findTrackingCommands is a function TO BE added to this class, 
                // which takes a 120x84 array of Ints and returns a tuple (Double, Double) representing the tracking roll and pitch)
                let (trackingRoll, trackingPitch) = sharedVars.findTrackingCommands(frame)
                // Save result in shared variables roll and pitch
                sharedVars.setRollPitch(trackingRoll, trackingPitch)
                // set newCommands flag to true, indicating to the sendCommand thread to break the loop and update local command variables
                sharedVars.setNewCommands(true)
            }
        }
    }
    
    // displayThread base function
    @objc private func dispData(view: UIView) {

        // Create a UIImageView
        let imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: frameWidth, height: frameHeight))
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
                    let bytesPerRow = bytesPerPixel * frameWidth
                    let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.none.rawValue)
                    let context = CGContext(data: nil, width: frameWidth, height: frameHeight, bitsPerComponent: 16, bytesPerRow: bytesPerRow, space: colorSpace, bitmapInfo: bitmapInfo.rawValue)!
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
        var commandRoll = 0.0
        var commandPitch = 0.0
        while !Thread.current.isCancelled {
            if sharedVars.getNewCommands() {
               // SHARED VARIABLES
               (commandRoll, commandPitch) = sharedVars.getRollPitch()
               // set newCommands flag to false, allowing the following loop to loop until the other thread sets it back to true
               sharedVars.setNewCommands(false)
            }
            while !sharedVars.getNewCommands() {
                // Send command
                droneCommand.sendControlData(0.0, commandPitch, commandRoll, 0.0)
                // Sleep for 50 milliseconds to achieve 20Hz frequency
                Thread.sleep(forTimeInterval: 0.05)
            }
        }
    }
    
    // TODO: Fill out function that gets frame and formats the data
    @objc private func getFrame() -> [[Int]] {
        var binData = // get frame from port
        return formatData(binData)
    }
    
    @objc private func formatData(_ dataBinary: Data) -> [[Int]] {
        let hexStr = dataBinary.map { String(format: "%02hhx", $0) }.joined()
        var numbers = [String]()
        for i in stride(from: 0, to: hexStr.count, by: 4) {
            let startIndex = hexStr.index(hexStr.startIndex, offsetBy: i)
            let endIndex = hexStr.index(startIndex, offsetBy: 4, limitedBy: hexStr.endIndex) ?? hexStr.endIndex
            numbers.append(String(hexStr[startIndex..<endIndex]))
        }
        let intNumbers = numbers.compactMap { Int($0, radix: 16) }
        var result = [[Int]](repeating: [Int](repeating: 0, count: frameHeight), count: frameWidth)
        for i in 0..<frameWidth {
            for j in 0..<frameHeight {
                result[i][j] = intNumbers[j * frameWidth + i]
            }
        }
        return result
    }
}

struct SharedVars {
    private let queue = DispatchQueue(label: "com.example.HeatSeeking.sharedVarQueue", attributes: .concurrent)
    private var _newCommands: Bool = false
    private var _newFrame: Bool = false
    private var _latestFrame: [[Int]]
    private var _roll: Double = 0
    private var _pitch: Double = 0

    // Initialize the shared variables
    init(frameWidth: Int, frameHeight: Int) {
        _latestFrame = [[Int]](repeating: [Int](repeating: 0, count: frameHeight), count: frameWidth)
    }

    // SHARED VARIABLE ACCESS FUNCTIONS
    private func setNewCommands(_ value: Bool) {
        sharedVarQueue.async(flags: .barrier) {
            self.newCommands = value
        }
    }
    
    private func setNewFrame(_ value: Bool) {
        sharedVarQueue.async(flags: .barrier) {
            self.newFrame = value
        }
    }
    
    private func setLatestFrame(_ value: [[Int]]) {
        sharedVarQueue.async(flags: .barrier) {
            self.latestFrame = value
        }
    }
    
    private func setRollPitch(_ roll: Double, _ pitch: Double) {
        sharedVarQueue.async(flags: .barrier) {
            self.roll = roll
            self.pitch = pitch
        }
    }
    
    private func getNewCommands() -> Bool {
        return sharedVarQueue.sync {
            return self.newCommands
        }
    }
    
    private func getNewFrame() -> Bool {
        return sharedVarQueue.sync {
            return self.newFrame
        }
    }
    
    private func getLatestFrame() -> [[Int]] {
        return sharedVarQueue.sync {
            return self.latestFrame
        }
    }
    
    private func getRollPitch() -> (Double, Double) {
        return sharedVarQueue.sync {
            return (self.roll, self.pitch)
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

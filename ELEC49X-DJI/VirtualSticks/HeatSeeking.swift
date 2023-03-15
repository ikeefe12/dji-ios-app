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
    var droneCommand: DroneCommand?
    // Wifi socket from which data is read
    var udpSocket: GCDAsyncUdpSocket?
    // three threads that will run in parallel
    var dataThread: Thread?
    var displayThread: Thread?
    var commandThread: Thread?
    // SHARED VARIABLES
    // Add a DispatchQueue for protecting shared variables
    private let sharedVarQueue = DispatchQueue(label: "com.example.HeatSeeking.sharedVarQueue", attributes: .concurrent)
    // Commands to  send to the drone
    var roll: Double = 0
    var pitch: Double = 0
    // This is a 120x80 array of integers representing the thermal image data 
    var latestFrame: [[Int]]
    // Flags to tell threads when to update the variables they are using in their loops
    var newCommands: Bool = false
    var newFrame: Bool = false
    
    init() {
      // this calls the init() function of DroneCommand and gives us an instance of the object from which we can call functions to control DJI drone
        droneCommand = DroneCommand()
        latestFrame = [[Int]](repeating: [Int](repeating: 0, count: 84), count: 120)
      // Initialize UDP port 
    }
    
    @objc private func formatData(_ dataBinary: Data) -> [Int] {
        let hexStr = dataBinary.map { String(format: "%02hhx", $0) }.joined()
        var numbers = [String]()
        for i in stride(from: 0, to: hexStr.count, by: 4) {
            let startIndex = hexStr.index(hexStr.startIndex, offsetBy: i)
            let endIndex = hexStr.index(startIndex, offsetBy: 4, limitedBy: hexStr.endIndex) ?? hexStr.endIndex
            numbers.append(String(hexStr[startIndex..<endIndex]))
        }
        return numbers.compactMap { Int($0, radix: 16) }
    }
    
    // This will start streaming data as well as displaying data
    @objc func enableThermalDataAndDisplay() {
        dataThread = Thread(target: self, selector: #selector(getData), object: nil)
        dataThread?.start()
        
        displayThread = Thread(target: self, selector: #selector(dispData), object: nil)
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
    
    // dataThread base function
    @objc private func getData() {
        while !Thread.current.isCancelled {
            // getFrame is a function to be added to this class that will read a frame of data from UDP port
            let recievedData = getFrame()
            // Format data using formatData
            let processedData = formatData(recievedData)
            // Save data to shared variable latesFrame so it can be used in displayThread
            setLatestFrame(processedData)
            setNewFrame(true)
            // Pass data through tracking algorithm (findTrackingCommands is a function TO BE added to this class)
            let (trackingRoll, trackingPitch) = findTrackingCommands(processedData)
            // Save result in shared variables roll and pitch
            setRollPitch(trackingRoll, trackingPitch)
            // set newCommands flag to true, indicating to the sendCommand thread to break the loop and update local command variables
            setNewCommands(true)
        }
    }
    
    // displayThread base function
    @objc private func dispData() {
        // Define the dimensions of the image
        let width = 120
        let height = 84

        // Create a UIImageView
        let imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: width, height: height))
        view.addSubview(imageView)
        
        while !Thread.current.isCancelled {
            if getNewFrame() {
                let gray16Image = getLatestFrame()
                setNewFrame(false)

                // Create a CGContext and draw the pixel values to it
                let colorSpace = CGColorSpaceCreateDeviceGray()
                let bytesPerPixel = MemoryLayout<UInt16>.stride
                let bytesPerRow = bytesPerPixel * width
                let bitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.none.rawValue)
                let context = CGContext(data: nil, width: width, height: height, bitsPerComponent: 16, bytesPerRow: bytesPerRow, space: colorSpace, bitmapInfo: bitmapInfo.rawValue)!
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
    
    // commandThread base function
    @objc private func sendCommand() {
        var commandRoll = 0.0
        var commandPitch = 0.0
        while !Thread.current.isCancelled {
            if getNewCommands() {
               // SHARED VARIABLES
               (commandRoll, commandPitch) = getRollPitch()
               // set newCommands flag to false, allowing the following loop to loop until the other thread sets it back to true
               setNewCommands(false)
            }
            while !getNewCommands() {
                // Send command
                droneCommand.sendControlData(0.0, commandPitch, commandRoll, 0.0)
                // Sleep for 50 milliseconds to achieve 20Hz frequency
                Thread.sleep(forTimeInterval: 0.05)
            }
        }
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

// The goal of this class is to create the ability to stream data and communicate with the drone at the same time. 
// Intended use:
// In CameraFPVViewController.swift when the Start Tracking button is pressed create an instance of this class and then
// run startTracking() from that instance
// startTracking() generates the two threads one to stream and process data and the other to take the result of proccessing and 
// send the correct command to the drone. These threads continue infinitely until stopTracking is called.
// stopTracking() is called in CameraFPVViewController.swift on the same instance of the HeatSeeking class that was created when the Start 
// Tracking button was pressed.
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
    // shared variables that the dataThread writes the results of image processing to so that the commandThread knows what direction to send to drone
    var vertThrottle: Double = 0
    var roll: Double = 0
    var pitch: Double = 0
    var yaw: Double = 0
    // shared variable flag thay indicates whether commandThread should update it's local variables for direction
    var newCommands: Bool = false
    
    init() {
      // this calls the init() function of DroneCommand and gives us an instance of the object from which we can call functions
        droneCommand = DroneCommand()
      // TODO: Initialize port 
    }
    
    @objc func enableThermalDataAndDisplay() {
        dataThread = Thread(target: self, selector: #selector(getData), object: nil)
        dataThread?.start()
        
        displayThread = Thread(target: self, selector: #selector(dispData), object: nil)
        displayThread?.start()
    }
    
    @objc func disableThermalDataAndDisplay() {
        dataThread?.cancel()
        displayThread?.cancel()
    }
    
    @objc func startTracking() {
        // enable virtual sticks on the drone
        droneCommand.toggleVirtualSticks(true)
        commandThread = Thread(target: self, selector: #selector(sendCommand), object: nil)
        commandThread?.start()
    }
    
    @objc func stopTracking() {
        commandThread?.cancel()
        // disable virtual stick commmand of the drone
        droneCommand?.toggleVirtualSticks(false)
    }
    
    // dataThread base function
    @objc private func getData() {
        while !isCancelled {
            // TODO: Read Data from port initialized in init()
            // TODO: Pass data through tracking algorithm (likely a function to be added to this class)
            // TODO: Save result in shared variable between the two threads (trackingData) - Race Condition ?
            // set newCommands flag to true, indicating to the sendCommand thread to break the loop and update local command variables
            newCommands = true
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
        
        while !isCancelled {
            if newFrame {
                // Get the latest grayscale image data (race condition)
                let gray16Image = getGray16Image()

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
        var commandThrottle = 0.0
        var commandRoll = 0.0
        var commandPitch = 0.0
        var commandYaw = 0.0
        while !isCancelled {
            if newCommands {
               // TODO: Get result of thermal image processing from shared variable (trackingData) - Race Condition ?
                commandThrottle = vertThrottle
                commandRoll = roll
                commandPitch = pitch
                commandYaw = yaw
               // set newCommands flag to false, allowing the following loop to loop until the other thread sets it back to true
               newCommands = false
            }
            while !newCommands {
                // TODO: send command based on the newest commands at a rate of 20Hz
                // Example code - probably wrong 
                droneCommand.sendControlData(commandThrottle, commandPitch, commandRoll, commandYaw)
                // Sleep for 50 milliseconds to achieve 20Hz frequency
                Thread.sleep(forTimeInterval: 0.05)
            }
        }
    }
}

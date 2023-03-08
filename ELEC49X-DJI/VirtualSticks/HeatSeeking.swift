// The goal of this class is to create the ability to stream data and communicate with the drone at the same time. 
// Intended use:
// In CameraFPVViewController.swift when the Start Tracking button is pressed create an instance of this class and then
// run startTracking() from that instance
// startTracking() generates the two threads one to stream and process data and the other to take the result of proccessing and 
// send the correct command to the drone. These threads continue infinitely until stopTracking is called.
// stopTracking() is called in CameraFPVViewController.swift on the same instance of the HeatSeeking class that was created when the Start 
// Tracking button was pressed.

import DJISDK

class HeatSeeking {
    // instance of DroneCommand class that has the capabilities to send commands to the drone
    var droneCommand: DroneCommand?
    // Wifi socket from which data is read
    var udpSocket: GCDAsyncUdpSocket?
    // two threads that will run in parallel
    var dataThread: Thread?
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
      // enable virtual sticks on the drone
        droneCommand.toggleVirtualSticks(true)
      // TODO: Initialize port 
    }
    
    func startTracking() {
        // start the two separate while loops as two threads in which the functions trackData and sendCommand represent the loops
        dataThread = Thread(target: self, selector: #selector(trackData), object: nil)
        dataThread?.start()
        
        commandThread = Thread(target: self, selector: #selector(sendCommand), object: nil)
        commandThread?.start()
    }
    
    
    @objc private func trackData() {
        while !isCancelled {
            // TODO: Read Data from port initialized in init()
            // TODO: Pass data through tracking algorithm (likely a function to be added to this class)
            // TODO: Save result in shared variable between the two threads (trackingData) - Race Condition ?
            // set newCommands flag to true, indicating to the sendCommand thread to break the loop and update local command variables
            newCommands = true
        }
    }
    
    // commandThread base function
    @objc private func sendCommand() {
        let commandRoll = 0.0
        let commandPitch = 0.0
        while !isCancelled {
            if newCommands {
               // TODO: Get result of thermal image processing from shared variable (trackingData) - Race Condition ?
                commandRoll = roll
                commandPitch = pitch
               // set newCommands flag to false, allowing the following loop to loop until the other thread sets it back to true
               newCommands = false
            }
            while !newCommands {
                // TODO: send command based on the newest commands at a rate of 20Hz
                // Example code - probably wrong 
                droneCommand.sendControlData(0.0, commandRoll, commandPitch, 0.0)
                // Sleep for 50 milliseconds to achieve 20Hz frequency
                Thread.sleep(forTimeInterval: 0.05)
            }
        }
    }
    
    func stopTracking() {
        // stop the two threads
        dataThread?.cancel()
        commandThread?.cancel()
      
        // disable virtual stick commmand of the drone (extra percaution)
        droneCommand?.toggleVirtualSticks(false)
    }
}

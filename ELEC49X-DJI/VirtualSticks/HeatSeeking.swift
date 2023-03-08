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
    // shared variable that the dataThread writes the results of image processing to so that the commandThread knows what direction to send to drone
    // this will likely end up being two values [x,y] coordinates of heated subject in the image
    var trackingData: Double = 0
    
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
        while true {
            // TODO: Read Data from port initialized in init()
            // TODO: Pass data through tracking algorithm (likely a function to be added to this class)
            // TODO: Save result in shared variable between the two threads (trackingData)
            // interrupt the commandThread so it knows there is new data
            commandThread?.interrupt()
        }
    }
    
    // commandThread base function
    @objc private func sendCommand() {
        while true {
            do {
                try DJISDKManager.keyManager()?.setValue(NSValue(cgPoint: calculateCommand()), for: DJIFlightControllerKey(param: DJIFlightControllerParamVelocity))
                try DJISDKManager.keyManager()?.performAction(for: DJIFlightControllerKey(param: DJIFlightControllerParamVelocity))
                Thread.sleep(forTimeInterval: 0.05)
                Thread.yield()
            } catch {
                print("Error: \(error.localizedDescription)")
            }
        }
    }
    
    private func calculateCommand() -> CGPoint {
        // calculate command based on tracking data
        return CGPoint(x: 0, y: 0)
    }
    
    private func processData(data: Data) -> Double {
        // process data and return result
        return 0.0
    }
    
    func stopTracking() {
        // stop the two threads
        dataThread?.cancel()
        commandThread?.cancel()
      
        // disable virtual stick commmand of the drone (extra percaution)
        droneCommand?.toggleVirtualSticks(false)
    }
}

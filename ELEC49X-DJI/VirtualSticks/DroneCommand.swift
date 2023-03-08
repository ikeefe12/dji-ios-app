//
//  DroneCommand.swift
//  ELEC49X-DJI
//
//  Created by Abby Brennan on 2023-02-14.
//  Copyright © 2023 DJI. All rights reserved.

import DJISDK

class DroneCommand {
    
    var flightController: DJIFlightController?
    
    init() {
        // Grab a reference to the aircraft
        if let aircraft = DJISDKManager.product() as? DJIAircraft {
            
            // Grab a reference to the flight controller
            if let fc = aircraft.flightController {
                
                // Store the flightController
                self.flightController = fc
                
                print("We have a reference to the FC")
                
                // Default the coordinate system to ground ( I think we want drone body system ) 
                self.flightController?.rollPitchCoordinateSystem = DJIVirtualStickFlightCoordinateSystem.body
                
                // Default roll/pitch control mode to velocity ( this is what we want ) 
                self.flightController?.rollPitchControlMode = DJIVirtualStickRollPitchControlMode.velocity
                
                // Set control modes ( good to have but I don't think we are going to rate the drone )
                self.flightController?.yawControlMode = DJIVirtualStickYawControlMode.angularVelocity
            }
            
        }
    }
    
    // User clicks the enter virtual sticks button
    @obj func enableVirtualSticks() {
        toggleVirtualSticks(enabled: true)
    }
    
    // User clicks the exit virtual sticks button
    @obj func disableVirtualSticks() {
        toggleVirtualSticks(enabled: false)
    }
    
    // Handles enabling/disabling the virtual sticks
    private func toggleVirtualSticks(enabled: Bool) {
            
        // Let's set the VS mode
        self.flightController?.setVirtualStickModeEnabled(enabled, withCompletion: { (error: Error?) in
            
            // If there's an error let's stop
            guard error == nil else { return }
            
            print("Are virtual sticks enabled? \(enabled)")
            
        })
        
    }
    
    @obj func sendControlData(throttle: Float, pitch: Float, roll: Float, yaw: Float) {
        print("Sending throttle: \(throttle), pitch: \(pitch), roll: \(roll), yaw: \(yaw)")
        
        // Construct the flight control data object
        var controlData = DJIVirtualStickFlightControlData()
        controlData.verticalThrottle = throttle // in m/s
        controlData.pitch = pitch
        controlData.roll = roll
        controlData.yaw = yaw
        
        // Send the control data to the FC
        self.flightController?.send(controlData, withCompletion: { (error: Error?) in
            
            // There's an error so let's stop
            if error != nil {
                print("Error sending data")
            }
        })
    }
}

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
    @objc func emergencyLand(){
        // Trigger the emergency landing procedure
        self.flightController?.startLanding(completion: { (error) in
            if let error = error {
                print("Error performing emergency landing: \(error.localizedDescription)")
            } else {
                print("Emergency landing procedure started successfully.")
            }
        })
        
        
        self.flightController?.startLanding(completion: nil) // pass nil for default landing

        // Wait for the drone to descend and hover above the landing spot
        //
        /*
        let targetAltitude: Float = 0.5
        var isDescending = true
        while isDescending {
            if let state = self.flightController.getState {
            let altitude = state.altitude
            let verticalSpeed = state.velocityZ
            if altitude <= targetAltitude && verticalSpeed <= 0.2 {
            isDescending = false // Drone has reached the desired hover altitude
            }
        }
         */
        // Add a short delay to avoid overloading the CPU
        Thread.sleep(forTimeInterval: 10.05)
        
        // Confirm the landing action
        self.flightController?.confirmLanding(completion: { (error) in
        if let error = error {
            // Handle error
            print("Failed to land the drone: \(error)")
        } else {
            // Drone has landed
            print("The drone has landed.")
        }
        })
    }
    
    // User clicks the enter virtual sticks button
    @objc func enableVirtualSticks() {
        toggleVirtualSticks(enabled: true)
    }
    
    // User clicks the exit virtual sticks button
    @objc func disableVirtualSticks() {
        toggleVirtualSticks(enabled: false)
    }
    
    // Handles enabling/disabling the virtual sticks
    /*private*/ func toggleVirtualSticks(enabled: Bool) {
            
        // Let's set the VS mode
        self.flightController?.setVirtualStickModeEnabled(enabled, withCompletion: { (error: Error?) in
            
            // If there's an error let's stop
            guard error == nil else { return }
            
            print("Are virtual sticks enabled? \(enabled)")
            
        })
        
    }
    
    @objc func sendControlData(throttle: Float, pitch: Float, roll: Float, yaw: Float) {
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

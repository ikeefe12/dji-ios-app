//
//  DroneCommand.swift
//  ELEC49X-DJI
//
//  Created by Abby Brennan on 2023-02-14.
//  Copyright © 2023 DJI. All rights reserved.
//
//  VirtualSticksViewController.swift
//  Created by Dennis Baldwin on 3/18/20.
//  Copyright © 2020 DroneBlocks, LLC. All rights reserved.
//
import UIKit
import DJISDK
enum FLIGHT_MODE {
    case ROLL_LEFT_RIGHT
    case PITCH_FORWARD_BACK
    case THROTTLE_UP_DOWN
    case HORIZONTAL_ORBIT
    case VERTICAL_ORBIT
    case VERTICAL_SINE_WAVE
    case HORIZONTAL_SINE_WAVE
    case YAW
}

class DroneCommand {
    
    var flightController: DJIFlightController?
    var timer: Timer?
    
    var radians: Float = 0.0
    let velocity: Float = 0.1
    var x: Float = 0.0
    var y: Float = 0.0
    var z: Float = 0.0
    var yaw: Float = 0.0
    var yawSpeed: Float = 30.0
    var throttle: Float = 0.0
    var roll: Float = 0.0
    var pitch: Float = 0.0
    
    var flightMode: FLIGHT_MODE?
    
    init() {
        // Grab a reference to the aircraft
        if let aircraft = DJISDKManager.product() as? DJIAircraft {
            
            // Grab a reference to the flight controller
            if let fc = aircraft.flightController {
                
                // Store the flightController
                self.flightController = fc
                
                print("We have a reference to the FC")
                
                // Default the coordinate system to ground ( I think we want drone coordinate system ) 
                self.flightController?.rollPitchCoordinateSystem = DJIVirtualStickFlightCoordinateSystem.ground
                
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
    
    @obj func rollLeftRight() {
        setupFlightMode()
        flightMode = FLIGHT_MODE.ROLL_LEFT_RIGHT
        
        // Schedule the timer at 20Hz while the default specified for DJI is between 5 and 25Hz
        timer = Timer.scheduledTimer(timeInterval: 0.05, target: self, selector: #selector(timerLoop), userInfo: nil, repeats: true)
    }
    
    @obj func pitchForwardBack() {
        setupFlightMode()
        flightMode = FLIGHT_MODE.PITCH_FORWARD_BACK
        
        // Schedule the timer at 20Hz while the default specified for DJI is between 5 and 25Hz
        // Note: changing the frequency will have an impact on the distance flown so BE CAREFUL
        timer = Timer.scheduledTimer(timeInterval: 0.05, target: self, selector: #selector(timerLoop), userInfo: nil, repeats: true)
    }
    
    @obj func throttleUpDown() {
        setupFlightMode()
        flightMode = FLIGHT_MODE.THROTTLE_UP_DOWN
        
        // Schedule the timer at 20Hz while the default specified for DJI is between 5 and 25Hz
        // Note: changing the frequency will have an impact on the distance flown so BE CAREFUL
        timer = Timer.scheduledTimer(timeInterval: 0.05, target: self, selector: #selector(timerLoop), userInfo: nil, repeats: true)
    }
    
    @obj func horizontalOrbit() {
        setupFlightMode()
        flightMode = FLIGHT_MODE.HORIZONTAL_ORBIT
        
        // Schedule the timer at 20Hz while the default specified for DJI is between 5 and 25Hz
        // Note: changing the frequency will have an impact on the distance flown so BE CAREFUL
        timer = Timer.scheduledTimer(timeInterval: 0.05, target: self, selector: #selector(timerLoop), userInfo: nil, repeats: true)
    }
    
    @obj func verticalOrbit() {
        setupFlightMode()
        flightMode = FLIGHT_MODE.VERTICAL_ORBIT
        
        // Schedule the timer at 20Hz while the default specified for DJI is between 5 and 25Hz
        // Note: changing the frequency will have an impact on the distance flown so BE CAREFUL
        timer = Timer.scheduledTimer(timeInterval: 0.05, target: self, selector: #selector(timerLoop), userInfo: nil, repeats: true)
    }
    
    @obj func sendYaw() {
        setupFlightMode()
        flightMode = FLIGHT_MODE.YAW
        
        //timer = Timer.scheduledTimer(timeInterval: 0.05, target: self, selector: #selector(timerLoop), userInfo: nil, repeats: true)
        
        sendControlData(x: 0, y: 0, z: 0)
        
        timer = Timer.scheduledTimer(timeInterval: 0.05, target: self, selector: #selector(yawLoop), userInfo: nil, repeats: true)
    }
    
    var count = 0
    
    @objc func yawLoop() {
        
        sendControlData(x: x, y: y, z: z)
        
        // Based on 20 hz
        if count > 60 {
            self.timer?.invalidate()
            self.count = 0
            print("done counting")
        }
        
        count = count + 1
        
    }
    
    
    // Timer loop to send values to the flight controller
    // It's recommend to run this in the iOS simulator to see the x/y/z values printed to the debug window
    @objc func timerLoop() {
        
        // Add velocity to radians before we do any calculation
        radians += velocity
        
        // Determine the flight mode so we can set the proper values
        switch flightMode {
        case .ROLL_LEFT_RIGHT:
            x = cos(radians)
            y = 0
            z = 0
            //yaw = 0 let's see if this yaws while rolling
        case .PITCH_FORWARD_BACK:
            x = 0
            y = sin(radians)
            z = 0
            yaw = 0
        case .THROTTLE_UP_DOWN:
            x = 0
            y = 0
            z = sin(radians)
            yaw = 0
        case .HORIZONTAL_ORBIT:
            x = cos(radians)
            y = sin(radians)
            z = 0
            yaw = 0
        case .VERTICAL_ORBIT:
            x = cos(radians)
            y = 0
            z = sin(radians)
            yaw = 0
        case .YAW:
            x = 0
            y = 0
            z = 0
            
            break
        case .VERTICAL_SINE_WAVE:
            break
        case .HORIZONTAL_SINE_WAVE:
            break
        case .none:
            break
        }
        
        sendControlData(x: x, y: y, z: z)
        
    }
    
    private func sendControlData(x: Float, y: Float, z: Float) {
        print("Sending x: \(x), y: \(y), z: \(z), yaw: \(yaw)")
        
        // Construct the flight control data object
        var controlData = DJIVirtualStickFlightControlData()
        controlData.verticalThrottle = throttle // in m/s
        controlData.roll = roll
        controlData.pitch = pitch
        controlData.yaw = yaw
        
        // Send the control data to the FC
        self.flightController?.send(controlData, withCompletion: { (error: Error?) in
            
            // There's an error so let's stop
            if error != nil {
                
                print("Error sending data")
                
                // Disable the timer
                self.timer?.invalidate()
            }
            
        })
    }
    
    // Called before any new flight mode is initiated
    private func setupFlightMode() {
        
        // Reset radians
        radians = 0.0
        
        // Invalidate timer if necessary
        // This allows switching between flight modes
        if timer != nil {
            print("invalidating")
            timer?.invalidate()
        }
    }
}

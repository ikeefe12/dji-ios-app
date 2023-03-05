//
//  DroneCommands.swift
//  ELEC49X-DJI
//
//  Created by Abby Brennan on 2023-01-30.
//  Copyright © 2023 DJI. All rights reserved.
//
/*
import Foundation
import os
import DJISDK
import JavaScriptCore


class VirtualStick : DJIFlightController {
    enum State {
        case takeoffStart
        case takeoffAttempting
        case takeoffComplete
        case virtualStickStart
        case virtualStickAttempting
        case virtualStickComplete
        case deactivated
    }
    
    var virtualStickAttempts = 0
    var state: State = .takeoffStart
    
    let flightController: DJIFlightController
    //let flightState: DJI.common.flightcontroller.FlightControllerState
    
    init(flightController: DJIFlightController) {
        self.flightController = flightController
    }
    
    func start() {
        while true {
            switch state {
                case .takeoffStart:
                    if flightController.isFlying {
                        //skip the takeoff command if the drone is already flying
                        state = .takeoffComplete
                    }
                    else {
                        state = .takeoffAttempting
                        //issue the takeoff command
                        flightController.takeoff { (error) in
                            if error != nil {
                                state = .deactivated
                            }
                            else {
                                state = .takeoffComplete
                            }
                        }
                    }
                    break
                    
                case .takeoffAttempting:
                    //wait while attempting the takeoff command
                    break
                    
                case .takeoffComplete:
                    //even though the takeoff command can succeed right away, that doesn't mean that
                    //the takeoff is actually finished, so check flight controller state to be sure
                    if flightController.isFlying && flightController.flightMode != AutoTakeoff {
                        state = .virtualStickStart
                    }
                    break
                    
                case .virtualStickStart:
                    state = .virtualStickAttempting
                    //issue the command to enable virtual stick
                    flightController.setVirtualStickModeEnabled { (error) in
                        if error != nil{
                            //if it fails, retry it a few times
                            virtualStickAttempts += 1
                            if virtualStickAttempts > 3 {
                                state = .deactivated
                            }
                        }
                        else {
                            state = .virtualStickComplete
                        }
                    }
                    break
                    
                case .virtualStickAttempting:
                    //wait while attempting to enable virtual stick
                    break
                    
                case .virtualStickComplete:
                    //once virtual stick is enabled, the flight mode will change to Joystick,
                    //meaning you can start sending virtual stick commands
                    //if flightController.flightMode == Joystick {
                if isVirtualStickControlModeAvailable() {
                        //your special sauce to calculate commands!
                        //flightController.sendVirtualStickFlightControlData(commands)
                        
                    }
                    else {
                        //if the flight mode is no longer Joystick, it means something has changed
                        //(RTH, GPS signal loss, remote controller flight mode switched, etc)
                        state = .deactivated
                    }
                    break
                    
                case .deactivated:
                    //perform operations that give control back to the operator in a nice way
                    //like stopping camera capture and resetting the gimbal to straight ahead
                    camera.reset()
                    gimbal.reset()
                    return
            }
            
            //wait for the previous commands to reach the drone and for new telemetry to become available
            sleep(50)
        }
    }
}

*/

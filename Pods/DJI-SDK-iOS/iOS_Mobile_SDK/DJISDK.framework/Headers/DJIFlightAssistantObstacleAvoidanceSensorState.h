//
//  DJIFlightAssistantObstacleAvoidanceSensorState.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  Current state of obstacle avoidance sensor.
 */
@interface DJIFlightAssistantObstacleAvoidanceSensorState : NSObject


/**
 *  Determines if upward visual obstacle avoidance sensor is working.
 */
@property(nonatomic, assign) BOOL isUpwardVisualObstacleAvoidanceSensorWorking;


/**
 *  Determines if right side visual obstacle avoidance sensor is working.
 */
@property(nonatomic, assign) BOOL isLeftSideVisualObstacleAvoidanceSensorWorking;


/**
 *  Determines if right side obstacle avoidance sensor is working.
 */
@property(nonatomic, assign) BOOL isRightSideVisualObstacleAvoidanceSensorWorking;


/**
 *  Determines if backward visual obstacle avoidance sensor is working.
 */
@property(nonatomic, assign) BOOL isBackwardVisualObstacleAvoidanceSensorWorking;


/**
 *  Determines if forward visual obstacle avoidance sensor is working.
 */
@property(nonatomic, assign) BOOL isForwardVisualObstacleAvoidanceSensorWorking;


/**
 *  Determines if downward visual obstacle avoidance sensor is working.
 */
@property(nonatomic, assign) BOOL isDownwardVisualObstacleAvoidanceSensorWorking;


/**
 *  Determines if visual obstacle avoidance sensors in vertical direction are
 *  working.
 */
@property(nonatomic, assign) BOOL isVisualObstacleAvoidanceSensorsInVerticalDirectionWorking;


/**
 *  Determines if visual obstacle avoidance sensors in horizontal direction are
 *  working.
 */
@property(nonatomic, assign) BOOL isVisualObstacleAvoidanceSensorInHorizontalDirectionWorking;


/**
 *  Whether the upward visual obstacle avoidance sensor is enabled or not.
 */
@property(nonatomic, assign) BOOL isUpwardVisualObstacleAvoidanceSensorEnabled;


/**
 *  Whether the left side visual obstacle avoidance sensor is enabled or not.
 */
@property(nonatomic, assign) BOOL isLeftSideVisualObstacleAvoidanceSensorEnabled;


/**
 *  Whether the right side visual obstacle avoidance sensor is enabled or not.
 */
@property(nonatomic, assign) BOOL isRightSideVisualObstacleAvoidanceSensorEnabled;


/**
 *  Whether the backward visual obstacle avoidance sensor is enabled or not.
 */
@property(nonatomic, assign) BOOL isBackwardVisualObstacleAvoidanceSensorEnabled;


/**
 *  Whether the forward visual obstacle avoidance sensor is enabled or not.
 */
@property(nonatomic, assign) BOOL isForwardVisualObstacleAvoidanceSensorEnabled;


/**
 *  Whether the downward visual obstacle avoidance sensor is enabled or not.
 */
@property(nonatomic, assign) BOOL isDownwardVisualObstacleAvoidanceSensorEnabled;


/**
 *  Whether the visual obstacle avoidance sensors in vertical direction are enabled
 *  or not.
 */
@property(nonatomic, assign) BOOL isVisualObstacleAvoidanceSensorInVerticalDirectionEnabled;


/**
 *  Whether the visual obstacle avoidance sensors in horizontal direction are
 *  enabled or not.
 */
@property(nonatomic, assign) BOOL isVisualObstacleAvoidanceSensorsInHorizontalDirectionEnabled;

@end

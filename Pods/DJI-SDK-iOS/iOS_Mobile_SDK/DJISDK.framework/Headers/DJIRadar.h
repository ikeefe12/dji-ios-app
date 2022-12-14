//
//  DJIRadar.h
//  DJISDK
//
//  Created by neo.xu on 2020/9/27.
//  Copyright © 2020 DJI. All rights reserved.
//

#import <DJISDK/DJISDK.h>
//#import "SDKSharedLibMacro.h"
#import <DJISDK/DJIBaseComponent.h>

@class DJIFlightAssistantPerceptionInformation;
@class DJIRadar;


@protocol DJIRadarDelegate <NSObject>

@optional


/**
 *  Updates the radar perception information. It is supported only by Matrice 300
 *  RTK.
 *  
 *  @param aradar Radar that has the updated state.
 *  @param information The Radar Perception information.
 */
- (void)radar:(DJIRadar *)radar didUpdateRadarPerceptionInformation:(DJIFlightAssistantPerceptionInformation *)information;

@end


/**
 *  This class contains components of the Radar and provides methods to change its
 *  settings.
 */
@interface DJIRadar : DJIBaseComponent


/**
 *  Delegate that receives the information sent by the Radar.
 */
@property(nonatomic, weak) id<DJIRadarDelegate> delegate;


/**
 *  Sets upward radar obstacle avoidance status (enabled/disabled).
 *  
 *  @param enabled `YES` to enabled the upward radar obstacle avoidance.
 *  @param completion The completion block that receives the execution result.
 */
- (void)setUpwardRadarObstacleAvoidanceEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets upward radar obstacle avoidance status (enabled/disabled).
 *  
 *  @param enabled `YES` if upward radar obstacle avoidance is enabled.
 *  @param completion The completion block that receives the execution result.
 */
- (void)getUpwardRadarObstacleAvoidanceEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Sets horizontal radar obstacle avoidance status (enabled/disabled).
 *  
 *  @param enabled `YES` to enabled the horizontal radar obstacle avoidance.
 *  @param completion The completion block that receives the execution result.
 */
- (void)setHorizontalRadarObstacleAvoidanceEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets upward horizontal obstacle avoidance status (enabled/disabled).
 *  
 *  @param enabled `YES` if horizontal radar obstacle avoidance is enabled.
 *  @param completion The completion block that receives the execution result.
 */
- (void)getHorizontalRadarObstacleAvoidanceEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;

@end


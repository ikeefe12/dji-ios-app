//
//  DJIFlightAssistant.h
//  DJISDK
//
//  Copyright © 2016, DJI. All rights reserved.
//

#import <DJISDK/DJIBaseProduct.h>
#import <DJISDK/DJIVisionTypes.h>
#import <DJISDK/DJISDKFoundation.h>
#import <DJISDK/DJIFlightControllerBaseTypes.h>

NS_ASSUME_NONNULL_BEGIN

@class DJIFlightAssistant;
@class DJIVisionDetectionState;
@class DJIVisionControlState;
@class DJIFlightAssistantObstacleAvoidanceSensorState;
@class DJIFlightAssistantPerceptionInformation;


/**
 *  This protocol provides an delegate method to update the Intelligent Flight
 *  Assistant current state.
 */
@protocol DJIFlightAssistantDelegate <NSObject>

@optional


/**
 *  Callback function that updates the vision detection state. The frequency of this
 *  method is 10Hz.
 *  
 *  @param assistant Intelligent flight assistant that has the updated state.
 *  @param state The state of vision sensor.
 */
- (void)flightAssistant:(DJIFlightAssistant *)assistant
     didUpdateVisionDetectionState:(DJIVisionDetectionState *)state;


/**
 *  Callback function that updates the aircraft state controlled by the intelligent
 *  flight assistant.
 *  
 *  @param assistant Intelligent flight assistant that has the updated state.
 *  @param state The control state.
 */
- (void)flightAssistant:(DJIFlightAssistant *)assistant
       didUpdateVisionControlState:(DJIVisionControlState *)state;


/**
 *  Callback function that updates the FaceAware state. When starting a PalmLaunch,
 *  the aircraft will  start FaceAware. If FaceAware activates successfully, the
 *  motors will start spinning and the  aircraft will hover after releasing it.
 *  
 *  @param assistant Flight assistant that has the updated state.
 *  @param state The FaceAware state.
 */
- (void)flightAssistant:(DJIFlightAssistant *)assistant didUpdateVisionFaceAwareState:(DJIVisionFaceAwareState)state;


/**
 *  Callback function that updates the palm control state.
 *  
 *  @param assistant Flight assistant that has the updated state.
 *  @param state The palm control state.
 */
- (void)flightAssistant:(DJIFlightAssistant *)assistant didUpdateVisionPalmControlState:(DJIVisionPalmControlState)state;


/**
 *  Callback function that updates the SmartCapture state. It is only supported by
 *  Mavic Air.
 *  
 *  @param assistant Flight assistant that has the updated state.
 *  @param state The SmartCapture state.
 */
- (void)flightAssistant:(DJIFlightAssistant *)assistant didUpdateVisionSmartCaptureState:(DJISmartCaptureState *)state;


/**
 *  Updates the obstacle avoidance sensor's state.
 *  
 *  @param assistant Flight assistant that has the updated state.
 *  @param state The Avoidance state.
 */
- (void)flightAssistant:(DJIFlightAssistant *)assistant didUpdateObstacleAvoidanceSensorState:(DJIFlightAssistantObstacleAvoidanceSensorState *)state;


/**
 *  Updates the visual perception information. It is supported only by Matrice 300
 *  RTK, Mavic Air 2, DJI Air 2S.
 *  
 *  @param assistant Flight assistant that has the updated state.
 *  @param information The Visual Perception information.
 */
- (void)flightAssistant:(DJIFlightAssistant *)assistant didUpdateVisualPerceptionInformation:(DJIFlightAssistantPerceptionInformation *)information;


/**
 *  Updates the TOF perception information. It is supported only by Matrice 300 RTK,
 *  Mavic Air 2, DJI Air 2S.
 *  
 *  @param assistant Flight assistant that has the updated state.
 *  @param information The TOF Perception information.
 */
- (void)flightAssistant:(DJIFlightAssistant *)assistant didUpdateToFPerceptionInformation:(DJIFlightAssistantPerceptionInformation *)information;

@end


/**
 *  This class contains components of the Intelligent Flight Assistant and provides
 *  methods to change its settings.
 */
@interface DJIFlightAssistant : NSObject


/**
 *  Intelligent flight assistant delegate.
 */
@property(nonatomic, weak) id<DJIFlightAssistantDelegate> delegate;


/**
 *  Enable collision avoidance. When enabled, the aircraft will stop and try to go
 *  around detected obstacles.
 *  
 *  @param enable A boolean value.
 *  @param completion Completion block that receives the execution result.
 */
- (void)setCollisionAvoidanceEnabled:(BOOL)enable
                      withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets collision avoidance status (enabled/disabled).
 *  
 *  @param enable YES if collision avoidance is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getCollisionAvoidanceEnabledWithCompletion:(void (^_Nonnull)(BOOL enable, NSError *_Nullable error))completion;


/**
 *  Enables/disables precision landing. When enabled, the aircraft will record its
 *  take-off location visually (as well as with GPS). On a Return-To-Home action the
 *  aircraft will attempt to perform a precision landing using the additional visual
 *  information. This method only works on a Return-To-Home action when the home
 *  location is successfully recorded during take-off, and not changed during
 *  flight, It will take effect only after flying 10 meters high at the return
 *  point.
 *  
 *  @param enabled `YES` to enable the precise landing.
 *  @param completion Completion block that receives the setter result.
 */
- (void)setPrecisionLandingEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets precision landing status (enabled/disabled).
 *  
 *  @param enabled YES if precision landing is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getPrecisionLandingEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Enables/disables landing protection. During auto-landing, the downwards facing
 *  vision sensor will check if the ground surface is flat enough for a safe
 *  landing. If it is not and landing protection is enabled, then landing will abort
 *  and need to be manually performed by the user.
 *  
 *  @param enabled `YES` to enable the landing protection.
 *  @param completion Completion block<<>android:Callback> that receives the setter result.
 */
- (void)setLandingProtectionEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets landing protection status (enabled/disabled).
 *  
 *  @param enabled YES if landing protection is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getLandingProtectionEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Enables/disables active obstacle avoidance. When enabled, and an obstacle is
 *  moving toward the aircraft, the aircraft will actively fly away from it. If
 *  while actively avoiding a moving obstacle, the aircraft detects another obstacle
 *  in its avoidance path, it will stop.
 *  `setCollisionAvoidanceEnabled:withCompletion` must also be enabled.
 *  
 *  @param enabled `YES` to enable the active avoidance.
 *  @param completion Completion block that receives the setter result.
 */
- (void)setActiveObstacleAvoidanceEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets active obstacle avoidance status (enabled/disabled).
 *  
 *  @param enabled `YES` if active obstacle avoidance is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getActiveObstacleAvoidanceEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Enables/disables upward avoidance. When the Inspire 2's upwards-facing infrared
 *  sensor detects an obstacle, the aircraft will slow its ascent and maintain a
 *  minimum distance of 1 meter from the obstacle. The sensor has a 10-degree
 *  horizontal field of view (FOV) and 10-degree vertical FOV. The maximum detection
 *  distance is 5m.
 *  
 *  @param enabled `YES` to enable the upwards avoidance.
 *  @param completion Completion block that receives the setter result.
 */
- (void)setUpwardVisionObstacleAvoidanceEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets upward avoidance status (enabled/disabled). It is only supported by Matrice
 *  300 RTK.
 *  
 *  @param enabled `YES` if upwards avoidance is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getUpwardVisionObstacleAvoidanceEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Enables/disables horizontal vision obstacle avoidance.
 *
 *  @param enabled `YES` to enable the Horizontal avoidance.
 *  @param completion Completion block that receives the setter result.
 */
- (void)setHorizontalVisionObstacleAvoidanceEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets horizontal vision obstacle avoidance status (enabled/disabled).
 *
 *  @param enabled `YES`  if Horizontal avoidance is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getHorizontalVisionObstacleAvoidanceEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Enables/disables advanced gesture control. When enabled, users can use
 *  PalmLaunch, PalmLand, PalmControl and Beckon. When enabled, the various modes
 *  can be initiated by the user. In summary:
 *   - Aircraft starts idle on users hand
 *   - User double clicks the power button and FaceAware becomes active
 *   - Once a face is recogized, PalmLaunch will happen
 *   - When flying, the user can control the aircraft position by moving their palm
 *   - If the user waves one hand, the aircraft will fly up and backwards and start
 *  following the user.
 *   - If the user waves both hands, the aircraft will execute Beckon and return to
 *  the user.
 *   It is only supported by Spark.
 *  
 *  @param enabled `YES` to enable advanced gesture control.
 *  @param completion The `completion block` with the returned execution result.
 */
- (void)setAdvancedGestureControlEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether advanced gesture control is enabled. When enabled, users can
 *  use PalmLaunch, PalmLand, PalmControl and Beckon. It is only supported by Spark.
 *  
 *  @param enabled `YES` to enable advanced gesture control.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getAdvancedGestureControlEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Determines if SmartCapture is supported. This feature is only supported by Mavic
 *  Air.
 *  
 *  @return `YES` if Smart Capture is supported.
 */
- (BOOL)isSmartCaptureSupported;


/**
 *  Enables/disables SmartCapture. When enabled, deep learning gesture recognition
 *  allows the user to take selfies, record videos, and control the aircraft
 *  (GestureLaunch, Follow and GestureLand) using simple hand gestures. It is only
 *  supported when `isSmartCaptureSupported` returns `YES`.
 *  
 *  @param enabled `YES` to enable SmartCapture.
 *  @param completion Completion block with the returned execution result.
 */
- (void)setSmartCaptureEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether SmartCapture is enabled. When enabled, users can When
 *  enabled, deep learning gesture recognition allows the user to take selfies,
 *  record videos, and control the aircraft (GestureLaunch, Follow and GestureLand)
 *  using simple hand gestures. It is only supported when `isSmartCaptureSupported`
 *  returns `YES`.
 *  
 *  @param enabled `YES` if SmartCapture is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getSmartCaptureEnabledEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Sets the following mode for SmartCapture. It is only valid when SmartCapture is
 *  enabled.
 *  
 *  @param mode The following mode to set.
 *  @param completion The completion block with the returned execution result.
 */
- (void)setSmartCaptureFollowingMode:(DJISmartCaptureFollowingMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the following mode for SmartCapture. It is only valid when SmartCapture is
 *  enabled.
 *  
 *  @param mode The following mode for SmartCapture.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getSmartCaptureFollowingModeWithCompletion:(void (^_Nonnull)(DJISmartCaptureFollowingMode mode, NSError *_Nullable error))completion;


/**
 *  Enables the Advanced Pilot Assistance System (APAS). When APAS is enabled, the
 *  aircraft continues to respond to user commands and plans its path according to
 *  both control stick inputs and the flight environment. APAS makes it easier to
 *  avoid obstacles and obtain smoother footage, and gives a better fly experiences.
 *  It is only valid when the aircraft is in P-mode. It is only supported by Mavic
 *  Air, Mavic 2 Pro, Mavic 2 Zoom, Mavic 2 Enterprise.
 *  
 *  @param enabled `YES` to enable APAS.
 *  @param completion Completion block with the returned execution result.
 */
- (void)setAdvancedPilotAssistanceSystemEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether the Advanced Pilot Assistance System (APAS) is enabled or
 *  not. When APAS is enabled, the aircraft continues to respond to user commands
 *  and plans its path according to both control stick inputs and the flight
 *  environment. APAS makes it easier to avoid obstacles and obtain smoother
 *  footage, and gives a better fly experiences. It It is only supported by Mavic
 *  Air, Mavic 2 Pro, Mavic 2 Zoom, Mavic 2 Enterprise.
 *  
 *  @param enabled `YES` if APAS is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getAdvancedPilotAssistanceSystemEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Enables Obstacle Avoidance during RTH. This is only active when the environment
 *  is bright enough. It is not active when the aircraft is landing. CAUTION: If RTH
 *  Obstacle Avoidance is disabled, aircraft will not check obstacles during RTH or
 *  ascend to avoid obstacles, which may cause great risks.
 *  
 *  @param enabled `YES` to enable Obstacle Avoidance during RTH.
 *  @param completion Completion block to receive the result.
 */
- (void)setRTHObstacleAvoidanceEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines if Obstacle Avoidance is enabled during RTH. This is only active when
 *  the environment is bright enough. It is not active when the aircraft is landing.
 *  CAUTION: If RTH Obstacle Avoidance is disabled, aircraft will not check
 *  obstacles during RTH or ascend to avoid obstacles, which may cause great risks.
 *  
 *  @param enable `YES` if Obstacle Avoidance during RTH is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getRTHObstacleAvoidanceEnabledWithCompletion:(void(^)(BOOL enable, NSError* error))completion;


/**
 *  Enables Remote Obstacle Avoidance during RTH. Enabling this, the aircraft will
 *  adjust its RTH route automatically to avoid obstacles in far distance. The
 *  gimbal will not respond to any commands from the application or the remote
 *  controller.
 *  
 *  @param enabled `YES` to enable Remote Obstacle Avoidance during RTH.
 *  @param completion Completion block to receive the result.
 */
- (void)setRTHRemoteObstacleAvoidanceEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines if RTH Remote Obstacle Avoidance is enabled or not. When it is
 *  enabled, the aircraft will adjust its RTH route automatically to avoid obstacles
 *  in far distance. The gimbal will not respond to any commands from the
 *  application or the remote controller.
 *  
 *  @param enabled `YES` if Remote RTH Obstacle Avoidance is enabled during RTH.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getRTHRemoteObstacleAvoidanceEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Sets the downward fill light mode. It is supported by Mavic 2 series and Matrice
 *  300 RTK.
 *  
 *  @param mode See enum `DJIFillLightMode`.
 *  @param completion Completion block to receive the result.
 */
- (void)setDownwardFillLightMode:(DJIFillLightMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the downward fill light mode. It is supported by Mavic 2 series and Matrice
 *  300 RTK.
 *  
 *  @param mode See enum `DJIFillLightMode`.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getDownwardFillLightModeWithCompletion:(void (^_Nonnull)(DJIFillLightMode mode, NSError *_Nullable error))completion;


/**
 *  Sets the upward fill light mode. It is only supported by Matrice 300 RTK. The
 *  distance range for `DJIFlightAssistantObstacleSensingDirectionHorizontal` is
 *  1m~5m. The distance range for `DJIFlightAssistantObstacleSensingDirectionUpward`
 *  is 1m~10m. The distance range for
 *  `DJIFlightAssistantObstacleSensingDirectionDownward` is 1dm~30dm.
 *  
 *  @param mode See enum `DJIFillLightMode`.
 *  @param completion Completion block to receive the result.
 */
- (void)setUpwardFillLightMode:(DJIFillLightMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets upward fill light mode. It is only supported by Matrice 300 RTK.
 *  
 *  @param mode See enum `DJIFillLightMode`.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getUpwardFillLightModeWithCompletion:(void (^_Nonnull)(DJIFillLightMode mode, NSError *_Nullable error))completion;


/**
 *  Sets the maximum perception distance that could be measured. It is supported
 *  only by Matrice 300 RTK. The distance range is 5m~45m for all direction.
 *  
 *  @param distance The maximum perception distance that could be measured.
 *  @param direction The perception direction.
 *  @param completion Completion block to receive the result.
 */
- (void)setMaxPerceptionDistance:(NSUInteger)distance
                     onDirection:(DJIFlightAssistantObstacleSensingDirection)direction
                  withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the maximum perception distance that could be measured. It is supported
 *  only by Matrice 300 RTK.
 *  
 *  @param direction The perception direction.
 *  @param distance The maximum perception distance that is measured.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getMaxPerceptionDistanceOnDirection:(DJIFlightAssistantObstacleSensingDirection)direction
                                                withCompletion:(void (^_Nonnull)(NSUInteger distance, NSError *_Nullable error))completion;


/**
 *  Sets the distance to engage Active Brake for obstacles avoidance.
 *  
 *  @param distance The distance to engage Active Brake.
 *  @param direction The perception direction. If is `DJIFlightController_DJIFlightAssistantObstacleSensingDirection_Downward`, the distance range is [0.1, 3], For Matrice 300 RTK the range is [0.4, 3]. If is `DJIFlightController_DJIFlightAssistantObstacleSensingDirection_Upward`, the distance range is [1.0, 10]. If is `DJIFlightController_DJIFlightAssistantObstacleSensingDirection_Horizontal`, the distance range is [1.0, 5].
 *  @param completion Completion block to receive the result.
 */
- (void)setVisualObstaclesAvoidanceDistance:(float)distance
                          onDirection:(DJIFlightAssistantObstacleSensingDirection)direction
                       withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets current distance to engage Active Brake for obstacles avoidance.
 *  
 *  @param direction The perception direction.
 *  @param distance The distance to engage Active Brake
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getVisualObstaclesAvoidanceDistanceOnDirection:(DJIFlightAssistantObstacleSensingDirection)direction
                                  withCompletion:(void (^_Nonnull)(float distance, NSError *_Nullable error))completion;


/**
 *  Enables/Disabled the Forbid Side Fly Switch. In APAS mode when the Forbid Side
 *  Fly Switch is turned on, the aircraft cannot fly sideways. Supported by DJI Air
 *  2S.
 *  
 *  @param enable `YES` to enable forbid side fly.
 *  @param completion Completion block with the returned execution result.
 */
- (void)setForbidSideFlyEnable:(BOOL)enable withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether the Forbid Side Fly Switch is enabled or not.
 *  
 *  @param enabled `YES` if forbid side fly is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getForbidSideFlyEnableWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

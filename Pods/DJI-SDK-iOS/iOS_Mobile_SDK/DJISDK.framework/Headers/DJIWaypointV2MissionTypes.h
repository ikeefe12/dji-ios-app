//
//  DJIWaypointV2MissionTypes.h
//  DJISDK
//
//  Copyright © 2019, DJI. All rights reserved.
//

#ifndef DJIWaypointV2MissionTypes_h
#define DJIWaypointV2MissionTypes_h

#import <Foundation/Foundation.h>

 NS_ASSUME_NONNULL_BEGIN

@class DJIWaypointV2Mission;


/**
 *  Determines the recover mission flying to which point. call
 *  `recoverMissionWithCompletion` to recover mission.  The waypoint mission is
 *  interrupted by invoking `interruptMissionWithCompletion`. The waypoint mission
 *  is  interrupted by moving remote controller's joystick. Other interruption such
 *  as obstacle avoidance.
 */
typedef NS_ENUM (NSInteger, DJIWaypointV2InterruptRecoverAction) {
    

    /**
     *  When the mission is recovered, the aircraft flying to the recorded point.
     */
    DJIWaypointV2InterruptRecoverActionGoBackToRecordedPoint = 0,
    

    /**
     *  When the mission is recovered, the aircraft flying to next waypoint.
     */
    DJIWaypointV2InterruptRecoverActionGoBackToNextWaypoint = 4,
    

    /**
     *  When the mission is recovered, the aircraft will fly to the waypoint next to the
     *  next waypoint.
     */
    DJIWaypointV2InterruptRecoverActionGoBackToNextTwoWaypoint = 5,
    
    
    /**
     *  Unknown.
     */
    DJIWaypointV2InterruptRecoverActionUnknown,
};


/**
 *  The action of waypoint mission that will be executed when the remote controller
 *  signal lost.
 */
typedef NS_ENUM (NSInteger, DJIWaypointV2MissionRCLostAction) {
    

    /**
     *  Stops current mission when the remote controller signal is lost.
     */
    DJIWaypointV2MissionRCLostActionStopMission,
    

    /**
     *  Continues the mission when the remote controller signal is lost.
     */
    DJIWaypointV2MissionRCLostActionContinue,
};


/**
 *  Actions will be taken when the waypoint mission is finished.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2MissionFinishedAction) {
    

    /**
     *  No further action will be taken. The aircraft can be controlled by the remote
     *  controller.
     */
    DJIWaypointV2MissionFinishedActionNoAction,
    

    /**
     *  Goes home when the mission is finished. The aircraft will land directly if it is
     *  within 20  meters away from the home point.
     */
    DJIWaypointV2MissionFinishedActionGoHome,
    

    /**
     *  The aircraft will land automatically at the last waypoint.
     */
    DJIWaypointV2MissionFinishedActionAutoLanding,
    

    /**
     *  The aircraft will go back to the first waypoint and hover.
     */
    DJIWaypointV2MissionFinishedActionGoToFirstWaypoint,
    

    /**
     *  When the aircraft reaches its final waypoint, it will hover without ending the
     *  mission. The joystick  can still be used to pull the aircraft back along its
     *  previous waypoints. The only way this mission  can end is if stopMission is
     *  called.
     */
    DJIWaypointV2MissionFinishedActionContinueUntilStop,
    

    /**
     *  Unknow finished action.
     */
    DJIWaypointV2MissionFinishedActionUnknown = 0xFF,
};


/**
 *  Possible flight mode to executes the mission.
 */
typedef NS_ENUM (NSInteger, DJIWaypointV2MissionGotoFirstWaypointMode) {
    

    /**
     *  Go to the waypoint safely. The aircraft will rise to the same altitude of the
     *  waypoint if the current  altitude is lower then the waypoint altitude. It then
     *  goes to the waypoint coordinate from the current  altitude, and proceeds to the
     *  altitude of the waypoint.
     */
    DJIWaypointV2MissionGotoFirstWaypointModeSafely,
    

    /**
     *  Go to the waypoint from the current aircraft point to the waypoint directly.
     */
    DJIWaypointV2MissionGotoFirstWaypointModePointToPoint,
};


/**
 *  The type of `DJIWaypointV2AssociateTriggerParam`,  Determines the time to
 *  execute the trigger associated with another one.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2TriggerAssociatedTimingType) {
    

    /**
     *  The trigger starts simultaneously with the trigger that is associated.
     */
    DJIWaypointV2TriggerAssociatedTimingTypeSimultaneously,
    

    /**
     *  The trigger starts after the trigger associated has finished.
     */
    DJIWaypointV2TriggerAssociatedTimingTypeAfterFinished,
    

    /**
     *  Unkown timing type.
     */
    DJIWaypointV2TriggerAssociatedTimingTypeUnknown = 0xFF,
};


/**
 *  The type of `DJIWaypointV2IntervalTriggerParam`,  Determines the interval type
 *  of how action repeats.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionIntervalType) {
    

    /**
     *  The action will be repeated after a particular period of time.
     */
    DJIWaypointV2ActionIntervalTypeTime,
    

    /**
     *  The action will be repeated after a particular distance.
     */
    DJIWaypointV2ActionIntervalTypeDistance,
    

    /**
     *  Unknown action trigger type.
     */
    DJIWaypointV2ActionIntervalTypeUnknown = 0xFF,
};


/**
 *  Possible types of action trigger.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionTriggerType) {
    

    /**
     *  The action will be trigger when the aircraft reach the waypoint point. The
     *  parameters should be setting  by `DJIWaypointV2ReachPointTriggerParam`.
     */
    DJIWaypointV2ActionTriggerTypeReachPoint,
        

    /**
     *  The action will be triggered when action associated executes. The parameters
     *  should be defined  by `DJIWaypointV2AssociateTriggerParam`.
     */
    DJIWaypointV2ActionTriggerTypeActionAssociated,
    

    /**
     *  The action will be triggered when the aircraft flies from one waypoint to the
     *  next.  This trigger applies only to
     *  `DJIWaypointV2ActionActuatorGimbalOperationTypeAircraftControlGimbal`.  When
     *  this is triggered, the gimbal will rotate at a constant speed from the start
     *  waypoint index to the end waypoint index. The parameters should be defined by
     *  `DJIWaypointV2TrajectoryTriggerParam`.
     */
    DJIWaypointV2ActionTriggerTypeTrajectory,
    

    /**
     *  The action will be triggered when the aircraft flies between two waypoints The
     *  parameters should be defined by `DJIWaypointV2IntervalTriggerParam`.
     */
    DJIWaypointV2ActionTriggerTypeInterval,
    

    /**
     *  Unknown.
     */
    DJIWaypointV2ActionTriggerTypeUnknown = 0xFF
};


/**
 *  Possible types of action actuator.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionActuatorType) {
    

    /**
     *  The action will be executed by the camera. The parameters should be defined by
     *  `DJIWaypointV2CameraActuatorParam`.
     */
    DJIWaypointV2ActionActuatorTypeCamera = 0,
    

    /**
     *  The action will be executed by the gimbal. The parameters should be defined by
     *  `DJIWaypointV2GimbalActuatorParam`.
     */
    DJIWaypointV2ActionActuatorTypeGimbal = 1,
    

    /**
     *  The action will executes by controlling aircraft. The parameters should be
     *  defined by `DJIWaypointV2AircraftControlParam`.
     */
    DJIWaypointV2ActionActuatorTypeAircraftControl = 2,
    

    /**
     *  The action will executes by the lidar. The parameters should be defined by
     *  `DJIWaypointV2LidarActuatorParam`.
     */
    DJIWaypointV2ActionActuatorTypeLidar = 6,
    

    /**
     *  Unknown actuator type.
     */
    DJIWaypointV2ActionActuatorTypeUnknown = 0xFF
};


/**
 *  The type of gimbal actuator operation.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionActuatorGimbalOperationType) {
    

    /**
     *  Rotates the gimbal. The range of the pitch angle should be gotten from
     *  `DJIGimbalParamAdjustPitch` or `DJIGimbalParamAdjustPitchUpwards`.  Only valid
     *  when the trigger type is `DJIWaypointV2ActionTriggerTypeReachPoint`.
     */
    DJIWaypointV2ActionActuatorGimbalOperationTypeRotateGimbal,
    

    /**
     *  Rotates the gimbal. Only valid when the trigger type is
     *  `DJIWaypointV2ActionTriggerTypeTrajectory`.
     */
    DJIWaypointV2ActionActuatorGimbalOperationTypeAircraftControlGimbal,
    

    /**
     *  Rotates the gimbal then take photos. This type is only Supported by Zenmuse P1.
     *  You can use this type to achieve Smart Oblique Capture.  Elevate the efficiency
     *  of your oblique photography mission using Smart Oblique Capture, where the
     *  gimbal automatically rotates to take photos at the different angles needed.
     *  Only photos essential to the reconstruction will be taken at the edge of the
     *  flight area, increasing the efficiency of post processing by 20% to 50%. Only
     *  valid when the trigger types are `DJIWaypointV2ActionTriggerTypeReachPoint` and
     *  `DJIWaypointV2ActionTriggerTypeActionAssociated`.
     */
    DJIWaypointV2ActionActuatorGimbalOperationTypePathShooting,
    

    /**
     *  Unknown.
     */
    DJIWaypointV2ActionActuatorGimbalOperationTypeUnknown = 0xFF,
};


/**
 *  Possible types of gimbal path cycle mode operation.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionActuatorGimbalPathCycleMode) {
    

    /**
     *  Path shooting will be executed once.
     */
    DJIWaypointV2ActionActuatorGimbalPathCycleModeOnce,
    

    /**
     *  Path shooting will be executed countless times.
     */
    DJIWaypointV2ActionActuatorGimbalPathCycleModeUnlimited,
    

    /**
     * Unknown
     */
    DJIWaypointV2ActionActuatorGimbalPathCycleModeUnknown,
    
};


/**
 *  Possible types of camera actuator operation.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionActuatorCameraOperationType) {
    

    /**
     *  Starts to shoot a photo.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeTakePhoto,
    

    /**
     *  Starts to record a video.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeStartRecordVideo,


    /**
     *  Stops to record a video.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeStopRecordVideo,
    

    /**
     *  You can use this type to point focus or rectangle focus.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeFocus,
    

    /**
     *  Adjust the camera focal length. Only support those support zoom cameras.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeZoom,
    

    /**
     *  Custom Expand File or directory name. You can use this actuator type to
     *  customize the file name and folder name of photos during the flight route,  it
     *  is convenient for users to manage the files after exporting media files from
     *  camera.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeCustomName = 5,
    

    /**
     *  Set the camera focus mode. We currently support auto and manual modes.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeFocusMode = 6,
    

    /**
     *  Start taking interval photos. As we known, we can use
     *  `DJIWaypointV2IntervalTriggerParam` to achieve the function of camera taking
     *  photos at intervals. The trigger will forward the camera instruction through the
     *  flight controller, this will cause system delay and missed shooting.  In order
     *  to solve this problem, we have developed the function of taking pictures at
     *  intervals directly through the camera. It's valid only when the
     *  `actionTriggerType` is `DJIWaypointV2ActionTriggerTypeReachPoint`.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeStartIntervalShoot,
    

    /**
     *  Stop taking interval photos.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeStopIntervalShoot,



    /**
     *  Unknown.
     */
    DJIWaypointV2ActionActuatorCameraOperationTypeUnknown = 0xFF,
};


/**
 *  Possible types of aircraft control actuator operation.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionActuatorAircraftControlOperationType) {
    

    /**
     *  Rotates the aircraft's yaw.
     */
    DJIWaypointV2ActionActuatorAircraftControlOperationTypeRotateYaw,
    

    /**
     *  Keeps the aircraft stop flying or start flying.
     */
    DJIWaypointV2ActionActuatorAircraftControlOperationTypeFlyingControl,
    

    /**
     *  Unknown.
     */
    DJIWaypointV2ActionActuatorAircraftControlOperationTypeUnknown = 0xFF,
};


/**
 *  Possible types of lidar operation.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionActuatorLidarOperationType) {
    

    /**
     *  Point cloud record opration. You can use this type to start,stop,pause,resume
     *  record point cloud when a waypoint mission is executing.
     */
    DJIWaypointV2ActionActuatorLidarOperationTypeRecordPointCloud = 1,
    

    /**
     *  Unknown
     */
    DJIWaypointV2ActionActuatorLidarOperationTypeUnknown = 0xFF,
};


/**
 *  Current waypoint mission executing state.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2MissionExecutionState){
    

    /**
     *  Waypoint mission is initializing, which means the mission has started.
     */
    DJIWaypointV2MissionExecutionStateInitializing,
    

    /**
     *  Aircraft is currently is going to the first waypoint.
     */
    DJIWaypointV2MissionExecutionStateGoToFirstWaypoint,
    

    /**
     *  Aircraft is currently moving.
     */
    DJIWaypointV2MissionExecutionStateMoving,
    

    /**
     *  Aircraft is currently interrupted by user.
     */
    DJIWaypointV2MissionExecutionStateInterrupted,
    

    /**
     *  The aircraft finished the waypoint mission and is leaving from the last
     *  waypoint.
     */
    DJIWaypointV2MissionExecutionStateFinished,
    

    /**
     *  Aircraft has returned to the home point. This happens when the `finishedAction`
     *  is set to `DJIWaypointV2MissionFinishedActionGoHome`.
     */
    DJIWaypointV2MissionExecutionStateGoHome,
    

    /**
     *  Aircraft has been landing. This happens when the `finishedAction` is set  to
     *  `DJIWaypointV2MissionFinishedActionAutoLanding`.
     */
    DJIWaypointV2MissionExecutionStateLanding,
    

    /**
     *  Aircraft has returned to the first waypoint. This happens when the
     *  `finishedAction`  is set to
     *  `DJIWaypointV2MissionFinishedActionGoToFirstWaypoint`.
     */
    DJIWaypointV2MissionExecutionStateReturnToFirstWaypoint,
    

    /**
     *  Unknown execution state.
     */
    DJIWaypointV2MissionExecutionStateUnknown = 0xFF,
};


/**
 *  Current waypoint mission action executing event.
 */
typedef NS_ENUM (uint8_t, DJIWaypointV2ActionExecutionEvent){

    /**
     *  Action begin execute event.
     */
    DJIWaypointV2ActionExecutionEventBeginAction,
    

    /**
     *  Action finished execute event.
     */
    DJIWaypointV2ActionExecutionEventFinishedAction,
    

    /**
     *  Unknown action event.
     */
    DJIWaypointV2ActionExecutionEventUnknown = 0xFF,
};


/**
 *  Possible types of gimbal path shootting operation.
 */
typedef NS_ENUM(NSUInteger, DJIWaypointV2GimbalPathShootingType) {
    

    /**
     *  Stop path shooting.
     */
    DJIWaypointV2GimbalStopPathShooting,
    

    /**
     *  Start path shooting.
     */
    DJIWaypointV2GimbalStartPathShooting,
    

    /**
     *  Unknown type.
     */
    DJIWaypointV2GimbalPathShootingTypeUnknown = 0xFF,
};


/**
 *  Possible types of point cloud record operation.
 */
typedef NS_ENUM(NSUInteger, DJIWaypointV2LidarPointCloudRecordType) {
    

    /**
     *  Stop point cloud recording.
     */
    DJIWaypointV2LidarStopPointCloudRecord,
    

    /**
     *  Start point cloud recording.
     */
    DJIWaypointV2LidarStartPointCloudRecord,
    

    /**
     *  Pause point cloud recording.
     */
    DJIWaypointV2LidarPausePointCloudRecord,
    

    /**
     *  Resume point cloud recording.
     */
    DJIWaypointV2LidarResumePointCloudRecord,
    
    /**
     *  Unknown.
     */
    DJIWaypointV2LidarPointCloudRecordTypeUnknown = 0xFF,
    
};


/**
 *  Possible types of custom expand name actuator operation.
 */
typedef NS_ENUM(NSUInteger, DJIWaypointV2CameraCustomNameType) {

    /**
     * none
     */
    DJIWaypointV2CameraCustomNone = 0,
    

    /**
     *  Custom expand file name. When your set this type in waypoint action, after
     *  aircraft trigger the action,  the name of next media file (video or photo) which
     *  would be stored in camera will be appended by the custom file name you set. For
     *  example, the default photo name is "DJI_2020012091415_999_WIDE.JPG", you could
     *  append "Waypoint1" after the default photo name, so the new photo's name will be
     *  "DJI_2020012091415_999_WIDE_Waypoint1.JPG". This action will only take effect
     *  once, if you want to append the same name for all photos in one mission,  you
     *  need to set this action before taking each photo. Only Supported by Zenmuse P1,
     *  Zenmuse H20 Series.
     */
    DJIWaypointV2CameraCustomFileName = 1,
    

    /**
     *  Custom expand directory name. When your set this type in waypoint action, after
     *  aircraft trigger the action, the newly generated media files (videos or photos)
     *  will be stored in the new folder when taking photo or record video,  this new
     *  folder's name will be appended by your custom directory name. for example by
     *  default, the default folder name is "DJI_202001012359_01",  you could append
     *  "Mission1" after it, so the new folder's name will be
     *  "DJI_202001012359_01_Mission1".  Please notice that the default folder's name
     *  also would be updated automatically when the drone completes the landing,  the
     *  camera will update the last two digits in "DJI_202001012359_01" to
     *  "DJI_202001012359_02", so before your drone taking off again,  if you need to
     *  append the same custom folder name, you need to set the same name with the
     *  action again. This type is only Supported by Zenmuse P1, Zenmuse L1, Zenmuse H20
     *  Series.
     */
    DJIWaypointV2CameraCustomDirectoryName = 2,
    

    /**
     * unknown
     */
    DJIWaypointV2CameraCustomUnknown = 0xFF
};


/**
 *  Possible types of camera focus mode.
 */
typedef NS_ENUM(NSUInteger, DJIWaypointV2CameraFocusModeType) {
    
    DJIWaypointV2CameraFocusMode_Unknow = 0,
    

    /**
     *  Manual focus mode
     */
    DJIWaypointV2CameraFocusMode_Manual = 1,
    

    /**
     *  Auto focus mode
     */
    DJIWaypointV2CameraFocusMode_Auto = 2,
    

    DJIWaypointV2CameraFocusMode_Continuous = 3,
    

    DJIWaypointV2CameraFocusMode_Precise = 4,
};


/**
 *  Possible types of camera focus region.
 */
typedef NS_ENUM(NSUInteger, DJIWaypointV2CameraFocusRegionType) {
    
   
    DJIWaypointV2CameraFocusRegionType_Unknow,
    

    /**
     *  The focus region is a point.
     */
    DJIWaypointV2CameraFocusRegionType_Point,
    

    /**
     *  The focus region is a prectangle.
     */
    DJIWaypointV2CameraFocusRegionType_Rectangle,
};


/**
 *  The upload progress of the waypoint mission operator.
 */
@interface DJIWaypointV2UploadProgress : NSObject


/**
 *  The waypoint mission operator has uploaded the mission's summary (information
 *  except waypoints).
 */
@property(nonatomic, readonly) BOOL isWaypointSummaryUploaded;


/**
 *  The last uploaded waypoint's index. Waypoint is uploaded in ascending order. If
 *  no waypoint has been uploaded,  the value should be -1.
 */
@property(nonatomic, readonly) NSInteger lastUploadedWaypointIndex;


/**
 *  The total count of waypoints in the waypoint mission.
 */
@property(nonatomic, readonly) NSUInteger totalWaypointCount;

@end


/**
 *  The download progress of the waypoint mission operator.
 */
@interface DJIWaypointV2DownloadProgress : NSObject


/**
 *  The last index of downloaded waypoint. Waypoint is downloaded in ascending
 *  order. If no waypoint has been  downloaded, the value shoud be -1.
 */
@property(nonatomic, readonly) NSInteger lastDownloadedWaypointIndex;


/**
 *  The total count of waypoints in the waypoint mission.
 */
@property(nonatomic, readonly) NSUInteger totalWaypointCount;

@end


/**
 *  The mission execution progress of the waypoint mission operator.
 */
@interface DJIWaypointV2ExecutionProgress : NSObject


/**
 *  The index of the waypoint in the mission to which the aircraft will proceed.
 */
@property(nonatomic, readonly) NSInteger targetWaypointIndex;


/**
 *  `YES` when the aircraft reaches a waypoint. After the waypoint actions and
 *  heading change are complete,  the `targetWaypointIndex` will increment and this
 *  property will become `NO`.
 */
@property(nonatomic, readonly) BOOL isWaypointReached;


/**
 *  Current execution state of the aircraft.
 */
@property(nonatomic, readonly) DJIWaypointV2MissionExecutionState executionState;

@end


/**
 *  The upload progress of the waypoint mission operator.
 */
@interface DJIWaypointV2ActionUploadProgress : NSObject


/**
 *  The last index of uploaded waypoint. Information for action is uploaded in
 *  ascending order. If no action has been uploaded, the value should be -1.
 */
@property(nonatomic, readonly) NSInteger lastUploadedActionIndex;


/**
 *  The total count of actions in the waypoint mission.
 */
@property(nonatomic, readonly) NSUInteger totalActionCount;

@end


/**
 *  The download progress of the actions operator.
 */
@interface DJIWaypointV2ActionDownloadProgress : NSObject


/**
 *  The last index of downloaded action. Information for action is downloaded in
 *  ascending order. If no action has been downloaded, the value should be -1.
 */
@property(nonatomic, readonly) NSInteger lastDownloadedActionIndex;


/**
 *  The total count of actions in the waypoint mission.
 */
@property(nonatomic, readonly) NSUInteger totalActionCount;

@end


/**
 *  The mission action execution progress of the waypoint mission operator. It is
 *  `nil` if there is an error during the execution.
 */
@interface DJIWaypointV2ActionExecutionProgress : NSObject


/**
 *  The ID of Action.
 */
@property (nonatomic, readonly) NSUInteger actionId;


/**
 *  The execution result of action.
 */
@property (nonatomic, readonly) BOOL executionResult;


/**
 *  The execution result of action.
 */
@property (nonatomic, readonly) DJIWaypointV2ActionExecutionEvent event;

@end

NS_ASSUME_NONNULL_END

#endif /* DJIWaypointV2MissionTypes_h */

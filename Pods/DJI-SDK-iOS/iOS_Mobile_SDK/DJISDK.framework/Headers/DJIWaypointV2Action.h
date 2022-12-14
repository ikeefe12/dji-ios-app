//
//  DJIWaypointV2Action.h
//  DJIWaypointV2
//
//  Created by DJI on 2019/7/8.
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "DJIWaypointV2MissionTypes.h"
#import "DJIWaypointV2Mission.h"

@class DJIGimbalRotation;

NS_ASSUME_NONNULL_BEGIN


/**
 *  This class defines `DJIWaypointV2ActionTriggerTypeReachPoint`. It describes  an
 *  action will be triggered when the aircraft reach the certain waypoint. We
 *  suggest you use `DJIWaypointV2AircraftControlFlyingParam`  to stop flying before
 *  the action you want to excute. After the action is completed, you should use
 *  `DJIWaypointV2AircraftControlFlyingParam` to start flying.
 */
@interface DJIWaypointV2ReachPointTriggerParam : NSObject


/**
 *  It determines the index of the waypoint at which the action will be triggered.
 */
@property (nonatomic, assign) NSUInteger startIndex;


/**
 *  It determines the waypoint count till the action triggered stops.
 */
@property (nonatomic, assign) NSUInteger waypointCountToTerminate;

@end


/**
 *  This class defines `DJIWaypointV2ActionTriggerTypeActionAssociated`.
 */
@interface DJIWaypointV2AssociateTriggerParam : NSObject


/**
 *  Associated action ID.
 */
@property (nonatomic, assign) NSUInteger actionIdAssociated;


/**
 *  The type of assciate trigger.
 */
@property (nonatomic, assign) DJIWaypointV2TriggerAssociatedTimingType actionAssociatedType;


/**
 *  Waiting time in seconds after ActionTrigger starts.
 */
@property (nonatomic, assign) NSUInteger waitingTime;

@end


/**
 *  This class represents a trajectory trigger action when should be trigger. This
 *  trigger only supported `DJIWaypointV2GimbalActuatorParam`.
 */
@interface DJIWaypointV2TrajectoryTriggerParam : NSObject


/**
 *  It determines the index of the waypoint at which the trigger starts.
 *  
 *  @return An int value of start index.
 */
@property (nonatomic, assign) NSUInteger startIndex;


/**
 *  It determines the waypoint when the trigger stops.
 *  
 *  @return An int value of end index.
 */
@property (nonatomic, assign) NSUInteger endIndex;

@end


/**
 *  This class defines `DJIWaypointV2ActionTriggerTypeTrajectory`. This class only
 *  support the parameters of `DJIWaypointV2CameraActuatorParam`.  You can add
 *  multiple actions to the trigger, For example, if you want to add actions for
 *  camera to take photo and record video,  you should add action with
 *  `DJIWaypointV2AssociateTriggerParam`, and set the associated action ID with
 *  another action,  the `actionAssociatedType` should be
 *  `DJIWaypointV2TriggerAssociatedTimingTypeAfterFinished`.
 */
@interface DJIWaypointV2IntervalTriggerParam : NSObject


/**
 *  It determines the index of the waypoint at which the trigger starts.
 */
@property (nonatomic, assign) NSUInteger startIndex;


/**
 *  The type of interval trigger. See `DJIWaypointV2ActionIntervalType`.
 */
@property (nonatomic, assign) DJIWaypointV2ActionIntervalType actionIntervalType;


/**
 *  If the `actionIntervalType`  is `DJIWaypointV2ActionIntervalTypeTime` The time
 *  interval in seconds  when two action are executed as the aircraft moves from the
 *  current waypoint to the next waypoint.  If the `actionIntervalType`  is
 *  `DJIWaypointV2ActionIntervalTypeDistance` The distance interval in meters  when
 *  two action are executed as the aircraft moves from the current waypoint to the
 *  next waypoint.
 */
@property (nonatomic, assign) float interval;

@end


/**
 *  It determines when an action will be performed while the aircraft executes a
 *  waypoint mission.
 */
@interface DJIWaypointV2Trigger  : NSObject


/**
 *  The type of trigger.
 */
@property (nonatomic, assign) DJIWaypointV2ActionTriggerType actionTriggerType;


/**
 *  The parameters of `DJIWaypointV2ActionTriggerTypeReachPoint`. It's  valid only
 *  when the `actionTriggerType`  is `DJIWaypointV2ActionTriggerTypeReachPoint`.
 */
@property (nonatomic, strong) DJIWaypointV2ReachPointTriggerParam* reachPointTriggerParam;


/**
 *  The parameters of `DJIWaypointV2ActionTriggerTypeActionAssociated`. It's valid
 *  only when the `actionTriggerType`  is
 *  `DJIWaypointV2ActionTriggerTypeActionAssociated`.
 */
@property (nonatomic, strong) DJIWaypointV2AssociateTriggerParam* associateTriggerParam;


/**
 *  The parameters of `DJIWaypointV2ActionTriggerTypeTrajectory`. It's valid only
 *  when the `actionTriggerType` is `DJIWaypointV2ActionTriggerTypeTrajectory`. This
 *  trigger applies only to
 *  `DJIWaypointV2ActionActuatorGimbalOperationTypeAircraftControlGimbal`.  If this
 *  action is triggered, the gimbal will rotate at a constant speed from the start
 *  waypoint index to the end waypoint index.
 */
@property (nonatomic, strong) DJIWaypointV2TrajectoryTriggerParam* trajectoryTriggerParam;


/**
 *  The parameters of `DJIWaypointV2ActionTriggerTypeInterval`. It's valid only when
 *  the `actionTriggerType`  is `DJIWaypointV2ActionTriggerTypeInterval`.
 */
@property (nonatomic, strong) DJIWaypointV2IntervalTriggerParam* intervalTriggerParam;

@end


/**
 *  This class defines a camera expand name operation for
 *  `DJIWaypointV2CameraActuatorParam`.
 */
@interface DJIWaypointV2CameraCustomNameParam : NSObject


/**
 *  Gets the type of camera custom expand name type.
 */
@property (nonatomic, assign) DJIWaypointV2CameraCustomNameType type;


/**
 *  Gets the camera custom expand name.
 */
@property (nonatomic, copy) NSString *customName;

@end



/**
 *  This class defines a camera focus mode operation for
 *  `DJIWaypointV2CameraActuatorParam`.
 */
@interface DJIWaypointV2CameraFocusModeParam : NSObject


/**
 *  Get the camera focus mode.
 */
@property (nonatomic, assign) DJIWaypointV2CameraFocusModeType focusModeType;

@end


/**
 *  This class defines a camera rectangle focus target for
 *  `DJIWaypointV2CameraFocusParam`.
 */
@interface DJIWaypointV2CameraFocusRectangleTargetParam : NSObject


/**
 *  The point at the upper left corner of the rectangle. The range for x and y is
 *  from 0.0 to 1.0. The point [0.0, 0.0] represents the top-left angle of the
 *  screen.
 */
@property (nonatomic, assign) CGPoint referencePoint;


/**
 *  The width of the rectangle. The range of the width is (0.0, 1.0]. The value
 *  increses from left to right from the `referencePoint`.
 */
@property (nonatomic, assign) float width;


/**
 *  The height of the rectangle. The range of the height is (0.0, 1.0]. The value
 *  increases from top to botton from the `referencePoint`.
 */
@property (nonatomic, assign) float height;

@end


/**
 *  This class defines a camera point focus target for
 *  `DJIWaypointV2CameraFocusParam`.
 */
@interface DJIWaypointV2CameraFocusPointTargetParam : NSObject


/**
 *  The lens focus target point. When the focus mode is auto, the target point is
 *  the focal point. When the focus mode is manual, the target point is the zoom out
 *  area if the focus assistant  is enabled for the manual mode. The range for x and
 *  y is from 0.0 to 1.0. The point [0.0, 0.0] represents the top-left angle of the
 *  screen.
 */
@property (nonatomic, assign) CGPoint focusPoint;

@end
          

/**
 *  This class defines a camera focus operation for
 *  `DJIWaypointV2CameraActuatorParam`.
 */
@interface DJIWaypointV2CameraFocusParam : NSObject

/**
 *  Focus region type of camera.
 */
@property (nonatomic, assign) DJIWaypointV2CameraFocusRegionType focusRegionType;


/**
 *  The parameter for rectangle focus. It's valid only when `focusRegionType`
 *    is `DJIWaypointV2CameraFocusRegionType_Rectangle`
 */
@property (nonatomic, strong) DJIWaypointV2CameraFocusRectangleTargetParam *rectangleTargetParam;


/**
 *  The parameter for point focus. It's valid only when `focusRegionType`
 *    is `DJIWaypointV2CameraFocusRegionType_Point`
 */
@property (nonatomic, strong) DJIWaypointV2CameraFocusPointTargetParam *pointTargetParam;

@end


/**
 *  This class defines a camera focal length operation for
 *  `DJIWaypointV2CameraActuatorParam`.
 */
@interface DJIWaypointV2CameraFocalLengthParam : NSObject


/**
 *  Focal length of zoom lens. Valid range is [`minFocalLength`, `minFocalLength`]
 *  and must be a multiple of `focalLengthStep`. Only support by those camera
 *  `isOpticalZoomSupported` return `YES`.
 */
@property (nonatomic, assign) NSUInteger focalLength;

@end


/**
 *  This class defines a camera interval shoot operation for
 *  `DJIWaypointV2CameraActuatorParam`.
 */
@interface DJIWaypointV2CameraStartIntervalShootParam : NSObject


/**
 *  Sets the number of photos you want to take. Valid range is [1-255]. If you set
 *  the number of photos is [1-254], the camera will automatically stop interval
 *  shooting after the number of photos is taken.
 *   If you set number of photos is 255, the camera will keep taking photos until
 *  the camera Received an order to stop taking interval photos.
 */
@property (nonatomic, assign) int shootCount;


/**
 *  The time interval between two photos(unit: second). Valid range is [1-65535].
 */
@property (nonatomic, assign) double shootInterval;

@end


/**
 *  This class defines a camera interval shoot operation for
 *  `DJIWaypointV2CameraActuatorParam`. No parameters required.
 */
@interface DJIWaypointV2CameraStopIntervalShootParam : NSObject
@end


/**
 *  This class defines the parameters for `DJIWaypointV2Actuator`. This determines
 *  how the camera  will be performed when a waypoint mission is executing.
 */
@interface DJIWaypointV2CameraActuatorParam : NSObject


/**
 *  The operation type of camera actuator. See
 *  `DJIWaypointV2ActionActuatorCameraOperationType`.
 */
@property (nonatomic, assign) DJIWaypointV2ActionActuatorCameraOperationType operationType;


/**
 *  The parameter for custom name. It's valid only when `operationType`  is
 *  `DJIWaypointV2ActionActuatorCameraOperationTypeCustomName`
 */
@property (nonatomic, strong) DJIWaypointV2CameraCustomNameParam *customNameParam;


/**
 *  The parameter for camera focus mode. It's valid only when `operationType`  is
 *  `DJIWaypointV2ActionActuatorCameraOperationTypeFocusMode`
 */
@property (nonatomic, strong) DJIWaypointV2CameraFocusModeParam *focusModeParam;

               

/**
 *  The parameter for camrea focus. It's valid only when `operationType`  is
 *  `DJIWaypointV2ActionActuatorCameraOperationTypeFocus`
 */
@property (nonatomic, strong) DJIWaypointV2CameraFocusParam* focusParam;


/**
 *  The parameter for camera zoom. It's valid only when `operationType`  is
 *  `DJIWaypointV2ActionActuatorCameraOperationTypeZoom`
 */
@property (nonatomic, strong) DJIWaypointV2CameraFocalLengthParam* zoomParam;


/**
 *  The parameter for start interval shoot. It's valid only when `operationType`  is
 *  `DJIWaypointV2ActionActuatorCameraOperationTypeStartIntervalShoot`
 */
@property (nonatomic, strong) DJIWaypointV2CameraStartIntervalShootParam* startIntervalShootParam;


/**
 *  The parameter for start interval shoot. It's valid only when `operationType`  is
 *  `DJIWaypointV2ActionActuatorCameraOperationTypeStopIntervalShoot`
 */
@property (nonatomic, strong) DJIWaypointV2CameraStopIntervalShootParam* stopIntervalShootParam;

@end


/**
 *  This class defines the parameters for `DJIWaypointV2LidarPointCloudRecordParam`.
 *   You can use this actuator to start,stop,pause,resume record point cloud when a
 *  waypoint mission is executing.
 */
@interface DJIWaypointV2LidarPointCloudRecordParam : NSObject


/**
 *  The operation type of lidar actuator. See
 *  `DJIWaypointV2LidarPointCloudRecordType`.
 */
@property (nonatomic, assign) DJIWaypointV2LidarPointCloudRecordType pointCloudRecordType;

@end


/**
 *  This class defines the parameters for `DJIWaypointV2Actuator`.
 *   You can use this actuator to start,stop,pause,resume record point cloud when a
 *  waypoint mission is executing.
 */
@interface DJIWaypointV2LidarActuatorParam : NSObject


/**
 *  The operation type of lidar actuator. See `DJIWaypointV2ActionActuatorLidarOperationType`.
 */
@property (nonatomic, assign) DJIWaypointV2ActionActuatorLidarOperationType operationType;


/**
 *  The parameter for record point cloud. It's valid only when
 *  `DJIWaypointV2ActionActuatorLidarOperationType`  is
 *  `DJIWaypointV2ActionActuatorLidarOperationTypeRecordPointCloud`
 */
@property (nonatomic, strong) DJIWaypointV2LidarPointCloudRecordParam* pointCloudRecordParam;

@end



/**
 *  This class defines how the aircraft rotates on the yaw axis.
 */
@interface DJIWaypointV2AircraftControlRotateHeadingParam : NSObject


/**
 *  Determines the aircraft rotate heading relative. If `YES`, when the aircraft is
 *  rotating, relative to the current angle.
 */
@property (nonatomic, assign) BOOL isRelative;


/**
 *  Determines the direction how aircraft changes its heading.
 */
@property (nonatomic, assign) DJIWaypointV2TurnMode direction;


/**
 *  The heading in degrees to which the aircraft will rotate control by action. If
 *  isRelative is `YES` A heading has a range of [-180, 180]  degrees, where 0
 *  represents True North.
 */
@property (nonatomic, assign) float heading;

@end


/**
 *  This class defines if the aircraft starts or stops the flight.
 */
@interface DJIWaypointV2AircraftControlFlyingParam : NSObject


/**
 *  Determines the aircraft start flying or stop flying. `YES` for the aircraft to
 *  start flying.
 */
@property (nonatomic, assign) BOOL isStartFlying;

@end


/**
 *  This class defines the parameters for `DJIWaypointV2Actuator`. It determines how
 *  the  aircraft control actuator will be performed when a waypoint mission is
 *  executed.
 */
@interface DJIWaypointV2AircraftControlParam : NSObject


/**
 *  The operation type of aircraft control actuator. See
 *  `DJIWaypointV2ActionActuatorAircraftControlOperationType`.
 */
@property (nonatomic, assign) DJIWaypointV2ActionActuatorAircraftControlOperationType operationType;


/**
 *  The parameter for rotating the aircraft's heading. It's valid only when
 *  `operationType`  is
 *  `DJIWaypointV2ActionActuatorAircraftControlOperationTypeRotateYaw`
 */
@property (nonatomic, strong) DJIWaypointV2AircraftControlRotateHeadingParam* yawRotatingParam;


/**
 *  The parameters to control flying behavior.  It's valid only when `operationType`
 *  is `DJIWaypointV2ActionActuatorAircraftControlOperationTypeFlyingControl`.
 */
@property (nonatomic, strong) DJIWaypointV2AircraftControlFlyingParam* flyControlParam;

@end


/**
 *  This class defines the gimbal path point info parameters.
 */
@interface DJIWaypointV2GimbalPathPointInfo : NSObject


/**
 *  The rotation time of the gimbal(unit: second). The gimbal will rotate at its
 *  maximum speed when the value is set to 0.
 */
@property (nonatomic, assign) float runningTime;


/**
 *  The time stays at the target location including the time of photo taken(unit:
 *  second). For example: the Zenmuse P1 takes about 0.7s to take a photo. If you
 *  set stay time with 1s, the gimbal will stay for 0.3s after the camera has
 *  finished taking a photo. If the stay time is less than the photo time, the next
 *  PathPoint will be executed immediately after the photo is taken.
 */
@property (nonatomic, assign) float stayTime;


/**
 *  Euler target angle for roll (North East Down coordinate system). Unit: degree.
 *  You should use `DJIGimbalParamAdjustRoll` to get the adjustable roll range.
 */
@property (nonatomic, assign) float eulerRoll;


/**
 *  Euler target angle for pitch(North East Down coordinate system). Unit: degree.
 *  You should use `DJIGimbalParamAdjustPitch` to get the adjustable pitch range.
 */
@property (nonatomic, assign) float eulerPitch;


/**
 *  Euler target angle for yaw (Unit: degree). The yaw angle is relative to the
 *  aircraft heading. If you set yaw angle to 0 degree, the direction of the gimbal
 *  will be the same as the aircraft heading.
 *   You should use `DJIGimbalParamAdjustYaw` to get the adjustable yaw range.
 */
@property (nonatomic, assign) float eulerYaw;

@end


/**
 *  This class defines the gimbal start path shooting parameters.
 */
@interface DJIWaypointV2GimbalStartPathShootingParam : NSObject


/**
 *  Determines whether path shooting is executed once or countless times.
 */
@property (nonatomic, assign) DJIWaypointV2ActionActuatorGimbalPathCycleMode pathCycleMode;


/**
 *  The point number, it is the size of the `pointInfo` list.
 */
@property (nonatomic, assign) int pointNum;


/**
 *  Path shooting point information list which contain parameters for path shooting.
 */
@property (nonatomic, strong) NSMutableArray<DJIWaypointV2GimbalPathPointInfo*> * pointInfo;

@end


/**
 *  This class defines the gimbal stop path shooting parameters.
 */
@interface DJIWaypointV2GimbalStopPathShootingParam : NSObject


/**
 *  Determines whether path shooting is executed once or countless times.
 */
@property (nonatomic, assign) DJIWaypointV2ActionActuatorGimbalPathCycleMode pathCycleMode;

@end


/**
 *  This class defines the parameters for `DJIWaypointV2GimbalActuatorParam`. It
 *  determines how the  gimbal actuator will be performed when a waypoint mission is
 *  executed.
 */
@interface DJIWaypointV2GimbalPathShootingParam : NSObject


/**
 *  The operation type of gimbal actuator. See
 *  `DJIWaypointV2GimbalPathShootingType`.
 */
@property (nonatomic, assign) DJIWaypointV2GimbalPathShootingType pathShootingType;


/**
 *  The parameter for start path shooting. It's valid only when
 *  `DJIWaypointV2GimbalPathShootingType` is `DJIWaypointV2GimbalStartPathShooting`
 */
@property (nonatomic, strong) DJIWaypointV2GimbalStartPathShootingParam* startPathShootingParam;


/**
 *  The parameters for stop path shooting.  It's valid only when
 *  `DJIWaypointV2GimbalPathShootingType` is `DJIWaypointV2GimbalStopPathShooting`.
 */
@property (nonatomic, strong) DJIWaypointV2GimbalStopPathShootingParam* stopPathShootingParam;

@end


/**
 *  This class defines the parameters for `DJIWaypointV2Actuator`. It determines how
 *  the  gimbal actuator will be performed when a waypoint mission is executed.
 */
@interface DJIWaypointV2GimbalActuatorParam : NSObject


/**
 *  The operation type of gimbal actuator. See
 *  `DJIWaypointV2ActionActuatorGimbalOperationType`.
 */
@property (nonatomic, assign) DJIWaypointV2ActionActuatorGimbalOperationType operationType;


/**
 *  The rotation of gimbal actuator.
 */
@property (nonatomic, strong) DJIGimbalRotation* rotation;


/**
 *  The param of path shooting.
 */
@property (nonatomic, strong) DJIWaypointV2GimbalPathShootingParam* pathShootingParam;

@end


/**
 *  This class defines an actuator for `DJIWaypointV2Action`. It determines how the
 *  action is performed when a waypoint mission is executed. You can add multiple
 *  actions with `uploadWaypointActions:withCompletion`.  There are two scenarios
 *  for it. Parallel execution: In parallel scenario, You can excute multiple
 *  actions with one trigger at the same time, the actions must be sent to different
 *  modules. For example, since gimbal and camera are different modules, you can use
 *  a trigger to rotate gimbal pitch and you can also use another triger  with
 *  identical parameters as the previous triger to take photos in order to execute
 *  these two actions at the same time.  You can not use two triggers with identical
 *  parameters to take photos and record videos at the same time, because these two
 *  actions are excuted with the same mudule. Serial execution: In serial scenario,
 *  You can excute multiple actions one by one. For example, if you want to add
 *  actions for camera to take photo and record video, you should add action with
 *  `DJIWaypointV2AssociateTriggerParam`.  and set the associated action ID with
 *  previous action, the `actionAssociatedType` should be
 *  <code>DJIWaypointV2TriggerAssociatedTimingTypeAfterFinished</code>.
 */
@interface DJIWaypointV2Actuator : NSObject


/**
 *  The type of actuator.
 */
@property (nonatomic, assign) DJIWaypointV2ActionActuatorType type;


/**
 *  The index of actuator. It is valid when the diagnostics is related to camera  or
 *  gimbal and the connected product has multiple gimbals and cameras.
 */
@property (nonatomic, assign) NSUInteger actuatorIndex;


/**
 *  The camera actuator param, It is valid only when the `type`  is
 *  `DJIWaypointV2ActionActuatorTypeCamera`.
 */
@property (nonatomic, strong) DJIWaypointV2CameraActuatorParam *cameraActuatorParam;


/**
 *  Parameters for gimbal actuator. It is valid only when the `type`  is
 *  `DJIWaypointV2ActionActuatorTypeGimbal`.
 */
@property (nonatomic, strong) DJIWaypointV2GimbalActuatorParam *gimbalActuatorParam;


/**
 *  Parameters for lidar actuator. It is valid only when the `type`  is
 *  `DJIWaypointV2ActionActuatorTypeAircraftControl`.
 */
@property (nonatomic, strong) DJIWaypointV2AircraftControlParam *aircraftControlActuatorParam;


/**
 *  Parameters for aircraft control actuator. It is valid only when the `type`  is
 *  `DJIWaypointV2ActionActuatorTypeLidar`.
 */
@property (nonatomic, strong) DJIWaypointV2LidarActuatorParam *lidarActuatorParam;

@end


/**
 *  This class represents an action for `DJIWaypointV2Mission`. It determines how
 *  action is performed when a waypoint mission is executed.
 */
@interface DJIWaypointV2Action : NSObject


/**
 *  The ID of Action.
 */
@property (nonatomic, assign) NSUInteger actionId;


/**
 *  The trigger of action.
 */
@property (nonatomic, strong) DJIWaypointV2Trigger* trigger;


/**
 *  The actuator of action.
 */
@property (nonatomic, strong) DJIWaypointV2Actuator* actuator;

@end

NS_ASSUME_NONNULL_END

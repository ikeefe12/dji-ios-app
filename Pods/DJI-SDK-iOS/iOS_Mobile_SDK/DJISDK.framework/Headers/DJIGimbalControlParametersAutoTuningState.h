//
//  DJIGimbalControlParametersAutoTuningState.h
//  DJISDK
//
//  Copyright © 2019, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DJIGimbalBaseTypes.h"


/**
 *  This class provides gimbal's control parameters auto-tuning state.
 */
@interface DJIGimbalControlParametersAutoTuningState : NSObject


/**
 *  The control parameters auto tuning status.
 */
@property (nonatomic, readonly) DJIGimbalControlParametersAutoTuningStatus controlParametersAutoTuningStatus;


/**
 *  Gimbal's control parameters auto-tuning progress in percentage.
 */
@property (nonatomic, readonly) NSUInteger progress;


/**
 *  Checks if the load has been installed.
 */
@property (nonatomic, readonly) BOOL isLoadInstalled;


/**
 *  Checks if the attitude of gimbal base is normal. Returns `NO` if the base is not
 *  placed horizontally.
 */
@property (nonatomic, readonly) BOOL isBaseAttitudeNormal;


/**
 *  Checks if gyro drift is normal. Returns `NO` if the gyro drift is too large.
 */
@property (nonatomic, readonly) BOOL isGyroDriftNormal;


/**
 *  Checks if joint angle deviation is normal. Returns `NO` if the joint angle
 *  deviation is high.
 */
@property (nonatomic, readonly) BOOL isJointAngleDeviationNormal;


/**
 *  Rotational inertia on roll axis.
 */
@property (nonatomic, readonly) DJIGimbalRotationalInertiaState rotationalInertiaOnRoll;


/**
 *  Rotational inertia on pitch axis.
 */
@property (nonatomic, readonly) DJIGimbalRotationalInertiaState rotationalInertiaOnPitch;


/**
 *  Rotational inertia on yaw axis.
 */
@property (nonatomic, readonly) DJIGimbalRotationalInertiaState rotationalInertiaOnYaw;


/**
 *  Stiffness on roll axis.
 */
@property (nonatomic, readonly) DJIGimbalAxialStiffnessState stiffnessOnRoll;


/**
 *  Stiffness on pitch axis.
 */
@property (nonatomic, readonly) DJIGimbalAxialStiffnessState stiffnessOnPitch;


/**
 *  Stiffness on yaw axis.
 */
@property (nonatomic, readonly) DJIGimbalAxialStiffnessState stiffnessOnYaw;


/**
 *  `YES` if gimbal's roll axis is locked.
 */
@property (nonatomic, readonly) BOOL isRollLocked;


/**
 *  `YES` if gimbal's pitch axis is locked.
 */
@property (nonatomic, readonly) BOOL isPitchLocked;


/**
 *  `YES` if gimbal's yaw axis is locked.
 */
@property (nonatomic, readonly) BOOL isYawLocked;


/**
 *  `YES` if gimbal motor is locked-rotor and is being protected.
 */
@property (nonatomic, readonly) BOOL isProtectingGimbalMotorLockedRotor;


/**
 *  `YES` if the aircraft's motor is on.
 */
@property (nonatomic, readonly) BOOL isAircraftMotorOn;





@end

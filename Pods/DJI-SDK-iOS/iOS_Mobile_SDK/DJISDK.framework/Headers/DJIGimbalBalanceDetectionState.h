//
//  DJIGimbalBalanceDetectionState.h
//  DJISDK
//
//  Copyright © 2019, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DJIGimbalBaseTypes.h"
#import "DJIGimbalDirectionState.h"


/**
 *  This class provides current balance detection information of the gimbal.
 */
@interface DJIGimbalBalanceDetectionState : NSObject


/**
 *  The balance detection status.
 */
@property (nonatomic, readonly) DJIGimbalBalanceDetectionProgressStatus balanceDetectionStatus;


/**
 *  Gimbal balance detection result on pitch.
 */
@property (nonatomic, readonly) DJIGimbalDetectionResultOnAxis resultOnPitch;


/**
 *  Gimbal balance detection result on roll.
 */
@property (nonatomic, readonly) DJIGimbalDetectionResultOnAxis resultOnRoll;


/**
 *  Gimbal balance detection result on yaw.
 */
@property (nonatomic, readonly) DJIGimbalDetectionResultOnAxis resultOnYaw;


/**
 *  Direction adjustment state on Pitch.
 */
@property (nonatomic, readonly) DJIGimbalDirectionState *directionAdjustmentStateOnPitch;


/**
 *  Direction adjustment state on roll.
 */
@property (nonatomic, readonly) DJIGimbalDirectionState *directionAdjustmentStateOnRoll;


/**
 *  Direction adjustment state on yaw.
 */
@property (nonatomic, readonly) DJIGimbalDirectionState *directionAdjustmentStateOnYaw;


/**
 *  Gimbal's balance detection progress percentage.
 */
@property (nonatomic, readonly) NSInteger progress;


/**
 *  `NO` if aircraft stability does not meet requirements.
 */
@property (nonatomic, readonly) BOOL isAircraftStabilitySatisfied;


/**
 *  Turn off aircraft motor and run balance detection again if this is `YES`.
 */
@property (nonatomic, readonly) BOOL isAircraftMotorOn;


/**
 *  `YES` if the gimbal motor is overloaded. Unable to test normally.
 */
@property (nonatomic, readonly) BOOL isGimbalMotorOverloaded;

@end

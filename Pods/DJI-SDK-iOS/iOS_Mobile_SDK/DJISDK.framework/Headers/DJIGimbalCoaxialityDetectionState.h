//
//  DJIGimbalCoaxialityDetectionState.h
//  DJISDK
//
//  Copyright © 2019, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DJIGimbalBaseTypes.h"
#import "DJIGimbalDirectionState.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This class provides current coaxiality detection information of the gimbal.
 */
@interface DJIGimbalCoaxialityDetectionState : NSObject


/**
 *  The coaxiality detection status.
 */
@property (nonatomic, readonly) DJIGimbalCoaxialityDetectionProgressStatus coaxialityDetectionStatus;


/**
 *  The Gimbal coaxiality detection result on pitch.
 */
@property (nonatomic, readonly) DJIGimbalDetectionResultOnAxis resultOnPitch;


/**
 *  The angle of the pitch axis deviates from the desired axis, and the counter-
 *  clockwise is positive.
 */
@property (nonatomic, readonly) NSInteger axisDeviationOnPitch;


/**
 *  The Gimbal's coaxiality detection progress percentage.
 */
@property (nonatomic, readonly) NSInteger progress;


/**
 *  `NO` if aircraft stability does not meet requirements.
 */
@property (nonatomic, readonly) BOOL isAircraftStabilitySatisfied;


/**
 *  Turn off aircraft motor and run coaxiality detection again if this is `YES`.
 */
@property (nonatomic, readonly) BOOL isAircraftMotorOn;


/**
 *  `YES` if the gimbal motor is overloaded. Unable to test normally.
 */
@property (nonatomic, readonly) BOOL isGimbalMotorOverloaded;

@end

NS_ASSUME_NONNULL_END

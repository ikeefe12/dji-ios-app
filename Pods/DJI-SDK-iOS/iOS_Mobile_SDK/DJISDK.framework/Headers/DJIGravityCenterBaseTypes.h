//
//  DJIGravityCenterBaseTypes.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  Enum for gravity calibration State.
 */
typedef NS_ENUM(NSInteger, DJIGravityCenterCalibrationState) {

    /**
     *  The aircraft is not calibrating the gravity center.
     */
    DJIGravityCenterCalibrationStateNone,

    /**
     *  The aircraft is calibrating the gravity center.
     */
    DJIGravityCenterCalibrationStateCalibrating,

    /**
     *  The aircraft calibrates the gravity center successfully.
     */
    DJIGravityCenterCalibrationStateSuccessful,

    /**
     *  The aircraft calibrates the gravity center failed.
     */
    DJIGravityCenterCalibrationStateFailed,

    /**
     *  Unknown calibration status.
     */
    DJIGravityCenterCalibrationStateUnknown = 0xFF,
};


/**
 *  This class provides the gravity state information.
 */
@interface DJIGravityCenterState : NSObject


/**
 *  The status of the gravity's calibration.
 */
@property (nonatomic, readonly) DJIGravityCenterCalibrationState calibrationState;


/**
 *  Gets calibration errors. Returns `nil` when gravity calibration is normal.
 */
@property (nonatomic, readonly, nullable) NSError *calibrationError;

@end

NS_ASSUME_NONNULL_END

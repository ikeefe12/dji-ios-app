//
//  DJIUpgradeBaseTypes.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  Upgrade component.
 */
typedef NS_ENUM(uint8_t, DJIUpgradeComponentType) {
    

    /**
     *  The upgrade component is remote controller.
     */
    DJIUpgradeComponentTypeRemoteController,
    

    /**
     *  The upgrade component is aircraft.
     */
    DJIUpgradeComponentTypeAircraft,
    

    /**
     *  The upgrade component is camera.
     */
    DJIUpgradeComponentTypeCamera = 3,
    

    /**
     *  The upgrade component is unknown.
     */
    DJIUpgradeComponentTypeUnknown,
};


/**
 *  Upgrade firmware state.
 */
typedef NS_ENUM(NSUInteger, DJIUpgradeFirmwareState) {

    /**
     *  Initializating.
     */
    DJIUpgradeFirmwareStateInitializating,
    

    /**
     *  Checking firmware information.
     */
    DJIUpgradeFirmwareStateChecking,

    /**
     *  Firmware version is up to date.
     */
    DJIUpgradeFirmwareStateUpToDate,
    

    /**
     *  To ensure flight safety, upgrade device is strongly recommended. Check DJI GO
     *  for  available firmware updates. Find more details in `DJIFirmwareInformation`.
     */
    DJIUpgradeFirmwareStateUpgradeStronglyRecommended,
    

    /**
     *  Optional upgrade is available. Check DJI GO for any available firmware updates.
     */
    DJIUpgradeFirmwareStateOptionalUpgradeAvailable,
    

     /**
      *  Unknown.
      */
    DJIUpgradeFirmwareStateUnknown,
};


/**
 *  Device's firmware upgrading progress state.
 */
typedef NS_ENUM(uint8_t, DJIUpgradingProgressState) {
    

    /**
     *  Upgrading.
     */
    DJIUpgradingProgressStateUpgrading,
    

    /**
     *  Upgrade failed.
     */
    DJIUpgradingProgressStateUpgradeFailed,
    

    /**
     *  Upgrade Successfully.
     */
    DJIUpgradingProgressStateUpgradeSuccessfully,
    

    /**
     *  Unknown.
     */
    DJIUpgradingProgressStateUnknown,
};


/**
 *  Firmware upgrade progress.
 */
@interface DJIFirmwareUpgradeProgress : NSObject


/**
 *  The progress of upgrading firmware.
 */
@property (nonatomic, readonly) float progress;


/**
 *  The state of upgrading firmware.
 */
@property (nonatomic, readonly) DJIUpgradingProgressState state;

@end


/**
 *  Firmware information.
 */
@interface DJIFirmwareInformation : NSObject


/**
 *  The version of the firmware.
 */
@property (nonatomic, readonly) NSString* version;


/**
 *  Firmware release notes.
 */
@property (nonatomic, readonly) NSString* releaseNote;


/**
 *  Firmware release date.
 */
@property (nonatomic, readonly) NSString*  releaseDate;


/**
 *  Firmware file size.
 */
@property (nonatomic, readonly) NSUInteger fileSize;

@end

NS_ASSUME_NONNULL_END

//
//  DJIUpgradeComponent.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "DJIUpgradeBaseTypes.h"
#import "DJISDKFoundation.h"

NS_ASSUME_NONNULL_BEGIN

@class DJIUpgradeComponent;


/**
 *  This protocol provides delegate methods to receive the upgrade information, the
 *  upgrade firmware state and the upgrade progress.
 */
@protocol DJIUpgradeFirmwareDelegate <NSObject>


/**
 *  Called when the upgrade firmware state has been changed.
 *  
 *  @param component The component of which the upgrade firmware state has been changed.
 *  @param state The upgrade firmware state.
 */
- (void)upgradeComponent:(DJIUpgradeComponent *)component didUpdateUpgradeFirmwareState:(DJIUpgradeFirmwareState)state;


/**
 *  Called when the upgrade is in progress.
 *  
 *  @param component The component of which the upgrade progress is updating.
 *  @param progress The upgrade progress information.
 */
- (void)upgradeComponent:(DJIUpgradeComponent *)component didUpdateFirmwareUpgradeProgress:(DJIFirmwareUpgradeProgress *)progress;


/**
 *  Raised when the firmware version is inconsistent among modules in component.
 *    See `DJIUpgradeComponent`. Invoke
 *  `startFirmwareConsistencyUpgradeWithCompletion`  to start consistency upgrade.
 *   The update frequency is 1Hz.
 *   Stop to notify in  following situation:
 *   - Firmware version among modules in component is  consistent.
 *   - Firmware consistency upgrade stops.
 *   - DJIUpgradeComponent_cancelConsistencyUpgrade  is invoked. Reboot the device
 *  to receive this notification again.
 *  
 *  @param component The upgrade component.
 */
- (void)didReceiveConsistencyUpgradeRequest:(DJIUpgradeComponent *)component;


/**
 *  Updates the latest firmware version information when the user is logged in.
 *  Please use DJI GO/DJI Pilot to upgrade to the latest firmware.
 *  
 *  @param component The component of which the latest firmware version information have been updated.
 *  @param firmwareInformation The latest firmware information.
 */
- (void)upgradeComponent:(DJIUpgradeComponent *)component didUpdateLatestFirmareInformation:(DJIFirmwareInformation *)firmwareInformation;

@end


/**
 *  This class is used to control components' upgrade. It also provides methods to
 *  receive  firmware consistency upgrade state and the latest firmware version
 *  information. It is  only supported by Mavic Air, Mavic 2 series, Matrice 300
 *  RTK.
 */
@interface DJIUpgradeComponent : NSObject


/**
 *  Component to upgrade.
 */
@property (nonatomic, readonly) DJIUpgradeComponentType componentType;


/**
 *  Current firmware upgrade state.
 */
@property (atomic, readonly) DJIUpgradeFirmwareState upgradeState;


/**
 *  The latest firmware information.
 */
@property (nonatomic, readonly) DJIFirmwareInformation *latestFirmwareInformation;


/**
 *  Adds a listener to receive the `DJIUpgradeFirmwareDelegate`.
 *  
 *  @param listener Listener to receive the `DJIUpgradeFirmwareDelegate`.  It is used to distinguish different listener and the listener will be retained.
 *  @param queue The dispatch queue to process state. The main queue is used if it is nil.
 */
- (void)addUpgradeFirmwareListener:(id<DJIUpgradeFirmwareDelegate>)listener withQueue:(nullable dispatch_queue_t)queue;


/**
 *  Removes a listener that is added by passing to
 *  `addUpgradeFirmwareListener:withQueue`.
 *  
 *  @param listener The listener to remove.
 */
- (void)removeUpgradeFirmwareListener:(id<DJIUpgradeFirmwareDelegate>)listener;


/**
 *  Remove all the listeners are added by passing to
 *  `addUpgradeFirmwareListener:withQueue`.
 */
- (void)removeAllUpgradeFirmwareListener;


/**
 *  Check if the consistency upgrade can be canceled. If false, please check the
 *  consistency of the firmware to ensure flight safety.  It is only supported by
 *  Mavic Air, Mavic 2 series.
 *  
 *  @return A boolean value.
 */
- (BOOL)canCancelConsistencyUpgrade;


/**
 *  Starts firmware consistency upgrade. If the firmware version of some modules in
 *  the device is not compatible with the firmware version of other modules,  the
 *  firmware will send a request for consistent upgrade. After you start firmware
 *  consistency upgrade, You should Invoke
 *  `upgradeComponent:didUpdateFirmwareUpgradeProgress` to receive upgrade progress
 *  information. Before invoking this method, please make sure that the motors are
 *  turned off and `wifiLink` is not using. It  is only supported by Mavic Air,
 *  Mavic 2 series.
 *  
 *  @param completion Completion block to receive the result.
 */
- (void)startFirmwareConsistencyUpgradeWithCompletion:(DJICompletionBlock)completion;


/**
 *  Cancels firmware consistency upgrade. `didReceiveConsistencyUpgradeRequest` will
 *  stop to notify. Before  invoking this method, please make sure that the motors
 *  are turned off and `wifiLink` is not using. It is only supported  by Mavic Air,
 *  Mavic 2 series.
 *  
 *  @param completion Completion block to receive the result.
 */
- (void)stopFirmwareConsistencyUpgradeWithCompletion:(DJICompletionBlock)completion;


/**
 * The upgrade component index. Index is zero based. A component will have an index
 * greater than zero when there  are multiple components of the same type on the
 * DJI product, and one of the components already has the index 0.  For instance,
 * Matrice 300 RTK series can have three gimbal mounted cameras, and will therefore have
 * three camera components with indices 0, 1 and 4. The index is the same with the ``DJIBaseComponent_index``.
 * Use this interface to determine the same component.
 *
 */
@property (nonatomic, assign, readonly) NSInteger componentIndex;

@end

NS_ASSUME_NONNULL_END


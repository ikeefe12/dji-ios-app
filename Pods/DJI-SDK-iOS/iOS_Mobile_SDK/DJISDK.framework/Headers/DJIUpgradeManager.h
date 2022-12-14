//
//  DJIUpgradeManager.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//


#import <Foundation/Foundation.h>

@class DJIUpgradeComponent;

NS_ASSUME_NONNULL_BEGIN


/**
 *  This class is used to manage the component that can be upgraded. It is only
 *  supported by Mavic Air, Mavic 2 series and Matrice 300 RTK.
 */
@interface DJIUpgradeManager : NSObject

- (instancetype)init OBJC_UNAVAILABLE("You must use the singleton");

+ (instancetype)new OBJC_UNAVAILABLE("You must use the singleton");


/**
 *  The upgrade component is aircraft. Upgrade this component when gimbal, battery,
 *  flight  controller and other internal modules' firmware versions are
 *  inconsistent. It is only  supported by Mavic Air, Mavic 2 series.
 */
@property (nonatomic, strong, nonnull) DJIUpgradeComponent *aircraft;


/**
 *  The upgrade component is remote controller. Upgrade this component when its
 *  internal  modules' firmware versions are inconsistent. It is only supported by
 *  Mavic 2 series.
 */
@property (nonatomic, strong, nonnull) DJIUpgradeComponent *remoteController;


/**
 *  The upgrade component is camera. Upgrade this component when its
 *  camera firmware versions are inconsistent. Some products have multiple cameras. For instance,
 *  Matrice 300 RTK series can have three gimbal mounted cameras at most, and will therefore have
 *  three camera components with indices 0, 1 and 4. Identify camera by componentIndex of upgradeComponent
 */
@property (nonatomic, copy, nonnull) NSDictionary <NSNumber*, DJIUpgradeComponent*> *cameras;

@end

NS_ASSUME_NONNULL_END

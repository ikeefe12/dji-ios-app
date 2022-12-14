//
//  DJILDMModule.h
//  DJISDK
//
//  Copyright © 2021 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  The type of module. The modules that support network service in LDM mode.
 */
typedef NS_ENUM(NSUInteger, DJILDMModuleType) {

    /**
     *  LDM control module on RTK
     */
    DJILDMModuleTypeRTK,

    /**
     *  LDM control module on ``DJIUserAccountManager``
     */
    DJILDMModuleTypeUserAccount,

    /**
     *  The module of FirmwareUpgrade. In LDM mode, You can use this type to enable the
     *  network service for FirmwareUpgrade, so that you can using the FirmwareUpgrade
     *  function as normal.
     */
    DJILDMModuleTypeFirmwareUpgrade,
};


/**
 *  Module definition.
 */
@interface DJILDMModule : NSObject


/**
 *  `YES` if the network service is enabled.
 */
@property (nonatomic, readonly) BOOL isEnabled;


/**
 *  The type of module. The module that you set to enable the network service.
 */
@property (nonatomic, readonly) DJILDMModuleType moduleType;


/**
 *  Initialize instance with the Module.
 *  
 *  @param moduleType the module that you want to enable the network service.
 *  @param isEnabled `YES` to eanbled the network service.
 */
- (instancetype)initWithModule:(DJILDMModuleType)moduleType andEnable:(BOOL)isEnabled;

@end

NS_ASSUME_NONNULL_END

//
//  DJILDMManager.h
//  DJISDK
//
//  Copyright © 2017 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DJISDK/DJILDMModule.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  Notification if LDM support has changed. If LDM support changes from `YES` to
 *  `NO`, and LDM is enabled, then LDM will be disabled after 2 minutes (120s) if
 *  `isLDMSupported` remains `NO`.
 */
extern NSString *DJILDMManagerSupportedChangedNotification;


/**
 *  Notification for when LDM transitions between enabled and disabled (and vise
 *  versa).
 */
extern NSString *DJILDMManagerEnabledChangedNotification;


/**
 *  Notification for when LDM module network services changed. When the notification
 *  comes, you could get the network service status with
 *  `isLDMModuleNetworkServiceEnabled`.
 */
extern NSString *DJILDMManagerModuleNetworkServiceChangedNotification;


/**
 *  Local Data Mode (LDM) manager. When Local Data Mode is enabled, the SDK's access
 *  to the internet is restricted. You should use `registerAppForLDMWithDelegate` to
 *  register the app. Only application registration (confirming the app key is
 *  valid) will be unrestricted. All other SDK services will be restricted. When the
 *  SDK's internet access is restricted, all SDK services that require an internet
 *  connection will not be available or able to update. For instance, the Fly Zone
 *  manager will not be able to update the fly zone data base, retrieve the latest
 *  TFRs (temporary flight restrictions) or unlock fly zones. LDM is therefore most
 *  appropriate for users that have very stringent data requirements, and are able
 *  to accommodate this restricted functionality.
 *  `*DJILDMManagerSupportedChangedNotification` and
 *  `*DJILDMManagerEnabledChangedNotification` can be used to monitor changes in
 *  state for availability of LDM support and whether LDM is enabled or not. When
 *  Local Data Mode is enabled, the UTMISSManager will not report flight dynamic
 *  data to the UTMISS server.
 */
@interface DJILDMManager : NSObject


/**
 *  `YES` if LDM is supported in the current context. The SDK locally uses GPS
 *  location and MCC (mobile country code) to determine the country  of operation.
 *  If LDM is not enabled and the internet is accessible, the IP address is also
 *  used to determine the country of operation. The default value is `YES` after the
 *  first installation.
 *  
 *  @return A bool value to check if LDM is supported.
 */
@property (readonly, nonatomic) BOOL isLDMSupported;


/**
 *  `YES` if LDM is already enabled.
 *  
 *  @return A boolean value to check if LDM is enabled.
 */
@property (readonly, nonatomic) BOOL isLDMEnabled;

- (instancetype)init OBJC_UNAVAILABLE("You must use the singleton");

+ (instancetype)new OBJC_UNAVAILABLE("You must use the singleton");

/*********************************************************************************/
#pragma mark - Local Data Mode (LDM)
/*********************************************************************************/


/**
 *  Get is LDM Supported.
 *  
 *  @param isLDMSupported Check is LDM supported.
 *  @param error Error retrieving the value.
 *  @param completion Completion block.
 */
- (void)getIsLDMSupportedWithCompletion:(void (^_Nonnull)(BOOL isLDMSupported, NSError *_Nullable error))completion;


/**
 *  Enables LDM. Can only be enabled if `isLDMSupported` is `YES`. Please call
 *  `getIsLDMSupportedWithCompletion` methods firstly.  Call this method before
 *  calling the other methods of SDK (including `registerAppWithDelegate`) to
 *  restrict the internet access  of SDK (SDK registration is unrestricted).
 *  
 *  @param error Error retrieving the value.
 *  @param completion Completion block.
 */
- (void)enableLDMWithCompletion:(void (^_Nonnull)(NSError *_Nullable error))completion;


/**
 *  Disables LDM.
 */
- (void)disableLDM;


/**
 *  In LDM mode, You can use this interface to enable network service of the
 *  selected module.
 *  
 *  @param modules The array of the modules need to be enabled.
 */
- (NSError *_Nullable)setModuleNetworkServiceEnabled:(NSArray<DJILDMModule *> *)modules;


/**
 *  `YES` if the network service of the module is enabled.
 *  
 *  @param moduleType The type of module that needs to be checked.
 *  
 *  @return `YES` if the network service of the module is enabled.
 */
- (BOOL)isLDMModuleNetworkServiceEnabled:(DJILDMModuleType)moduleType;

@end

NS_ASSUME_NONNULL_END

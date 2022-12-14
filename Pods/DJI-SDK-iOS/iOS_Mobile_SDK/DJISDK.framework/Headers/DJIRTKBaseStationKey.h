//
//  DJIRTKBaseStationKey.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <DJISDK/DJISDK.h>

NS_ASSUME_NONNULL_BEGIN

EXTERN_KEY NSString *const DJIRTKBaseStationComponent;
EXTERN_KEY NSString *const DJIRTKBaseStationParamBaseStationBatteryState;
EXTERN_KEY NSString *const DJIRTKBaseStationParamBaseStationState;
EXTERN_KEY NSString *const DJIRTKBaseStationParamBaseStationReferencingLocation;
EXTERN_KEY NSString *const DJIRTKBaseStationParamResetRTKBaseStationLocation;

EXTERN_KEY NSString *const DJIRTKBaseStationParamHasDeviceAdminLoggedIn;
EXTERN_KEY NSString *const DJIRTKBaseStationParamLogin;
EXTERN_KEY NSString *const DJIRTKBaseStationParamLogOut;
EXTERN_KEY NSString *const DJIRTKBaseStationChangePassword;
EXTERN_KEY NSString *const DJIRTKBaseStationParamName;


/**
 *  `DJIRTKBaseStationKey` provides dedicated access to the base station attributes.
 */
@interface DJIRTKBaseStationKey : DJIKey

@end

NS_ASSUME_NONNULL_END

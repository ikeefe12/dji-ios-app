//
//  DJIRTKBaseStation.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <DJISDK/DJISDK.h>

@class DJIRTKBaseStation;
@class DJIRTKBaseStationBatteryState;
@class DJIRTKBaseStationState;
NS_ASSUME_NONNULL_BEGIN


/**
 *  This protocol provides a delegate method to update the base station state.
 */
@protocol DJIRTKBaseStationDelegate <NSObject>


/**
 *  Callback function that updates the RTK base station battery state. Only
 *  Supported by Phantom 4 RTK and M200 series v2.
 *  
 *  @param baseStation Instance of the Base Station for which battery state will be updated.
 *  @param state Base station battery State.
 */
- (void)baseStation:(DJIRTKBaseStation *_Nonnull)baseStation didUpdateBaseStationBatteryState:(DJIRTKBaseStationBatteryState *)state;


/**
 *  Callback function that updates the RTK base station state. Only Supported by
 *  Phantom 4 RTK and M200 series v2.
 *  
 *  @param baseStation Instance of the Base Station for which state will be updated.
 *  @param state Base station State.
 */
- (void)baseStation:(DJIRTKBaseStation *_Nonnull)baseStation didUpdateBaseStationState:(DJIRTKBaseStationState *)state;

@end


/**
 *  RTK Base Station.
 */
@interface DJIRTKBaseStation : DJIBaseComponent


/**
 *  DJI base station delegate.
 */
@property(nonatomic, weak) id<DJIRTKBaseStationDelegate> delegate;


/**
 *  Gets the referencing location manually configured to the  base station. When a
 *  user can get a more accurate  location (coordinate with less absolute error) of
 *  the base  station by using external tools, the accurate location can  be set to
 *  the base station to improve the accuracy of the  aircraft location. If the
 *  offset between the referencing  location and the location detected by the ground
 *  system is  larger than 5 meters, the base station will ignore the referencing
 *  location. It is only supported by Phantom 4 RTK and M200 series v2 and Matrice
 *  300 RTK.
 *  
 *  @param location The referencing location of the base station.
 *  @param error Error if there is any.
 *  @param completion Completion block that receives the execution result.
 */
- (void)getBaseStationReferencingLocationWithCompletion:(void (^_Nonnull)(CLLocation *_Nullable location, NSError *_Nullable error))completion;


/**
 *  Sets the referencing location of the base station to improve the accuracy.  When
 *  a user  can get a more accurate location (coordinate with less absolute error)
 *  of the base station  by using external tools, the accurate location can be set
 *  to the  base station to improve  the accuracy of the aircraft location. If the
 *  offset between  the referencing location and  the location detected by the base
 *  station is larger than  5 meters, the base station will ignore the referencing
 *  location. It is only supported  by Phantom 4 RTK and M200 series v2 and Matrice
 *  300 RTK. For Matrice 300 RTK, device  administrator authentication is required
 *  before invoking this method.
 *  
 *  @param location The referencing location of the base station.
 *  @param completion Completion block that receives the execution result.
 */
- (void)setBaseStationReferencingLocation:(CLLocation *)location withCompletion:(DJICompletionBlock)completion;


/**
 *  Reset RTK base station's location. This will make base station's location type
 *  became `DJIRTKBaseStationLocationTypeAuto`. The previously set location  by
 *  `setBaseStationReferencingLocation:withCompletion` will be invalid. For Matrice
 *  300 RTK,  device administrator authentication is required before invoking this
 *  method.
 *  
 *  @param completion Completion block that receives the execution result.
 */
- (void)resetRTKBaseStationLocationWithCompletion:(DJICompletionBlock)completion;


/**
 *  `YES` if device administrator has logged in. For Matrice 300 RTK, device
 *  administrator authentication is required before  changing any settings,
 *  including base station's name, base station's password, and base station's
 *  referencing location.  Device administrator login is required every time when
 *  the application is relaunched. Please login with default password  123456, if
 *  the base station's password is reset. Supported only by Matrice 300 RTK.
 *  
 *  @return The result whether login or not.
 */
- (BOOL)hasDeviceAdminLoggedIn;


/**
 *  Log in as base station administrator account with password to change setting.
 *  User will need to login again in the following scenarios:
 *   -  Enter the application for the first time.
 *   - Re-enter after the application restarts.
 *   - Reset password via the button on the base  station.
 *   - Switch and connect other base stations.
 *   The default password is `123456`. It is only supported by Matrice 300 RTK.
 *  
 *  @param password The password of base station.
 *  @param completion The completion block that receives the execution result.
 */
- (void)logInAsDeviceAdmin:(NSString *)password withCompletion:(DJICompletionBlock)completion;


/**
 *  Log out of the base station. It is only supported by Matrice 300 RTK.
 *  
 *  @param completion Completion block that receives the execution result.
 */
- (void)logOutWithCompletion:(DJICompletionBlock)completion;


/**
 *  Change the password for current base station. The password must be 6 digits. It
 *  is only supported by Matrice 300 RTK.
 *  
 *  @param oldPassword The old password.
 *  @param newPassword The new password that you want to change.
 *  @param completion Completion block that receives the execution result.
 */
- (void)changePassword:(NSString *)oldPassword newPassword:(NSString *)newPassword completion:(DJICompletionBlock)completion;


/**
 *  Change the name of the base station. The name is composed of maximum 4
 *  characters or numbers.  Please log in before invoking this method. It is only
 *  supported by Matrice 300 RTK.
 *  
 *  @param name The name of the base station set by the user.
 *  @param completion Completion block that receives the execution result.
 */
- (void)setName:(NSString *)name withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the name of the base station. Please log in before invoking this method. It
 *  is only supported by Matrice 300 RTK.
 *  
 *  @param name The name set for base station.
 *  @param error Error if there is any.
 *  @param completion Completion block that receives the execution result.
 */
- (void)getNameWithCompletion:(void(^)(NSString *_Nullable name, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

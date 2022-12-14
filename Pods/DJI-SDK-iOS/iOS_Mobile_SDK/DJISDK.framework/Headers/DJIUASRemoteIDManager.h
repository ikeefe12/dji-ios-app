//
//  DJIUASRemoteIDManager.h
//  DJISDK
//
//  Created by neo.xu on 2022/9/15.
//  Copyright © 2022 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DJISDK/DJISDK.h>

@class DJIUASRemoteIDManager;


/**
 *  The remote identification status of the drone.
 */
typedef NS_ENUM(uint8_t, DJIRemoteIDWorkingState) {


    /**
     *  Idle, initialization state.
     */
    DJIRemoteIDWorkingStateIdle,


    /**
     *  Working, it indicates that Remote ID is broadcasting.
     */
    DJIRemoteIDWorkingStateWorking,
    

    /**
     *  Not working, because the operator's position is lost, resulting in the Remote ID
     *  not being broadcast.
     */
    DJIRemoteIDWorkingStateOperatorLocationLostError,
    

    /**
     *  Not working, because the firmware error, resulting in the Remote ID not being
     *  broadcast.
     */
    DJIRemoteIDWorkingStateFirmwareError,
    

    /**
     *  The remote id working state is not working, caused by unknown error.
     */
    DJIRemoteIDWorkingStateUnknownError,
    


    /**
     *  Not working, because the unknown error, resulting in the Remote ID not being
     *  broadcast.
     */
    DJIRemoteIDWorkingStateUnknown = 0xFF,
};


/**
 *  Enums represent the aera code.
 */
typedef NS_ENUM(uint8_t, DJIUASAreaCode) {


    /**
     *  The Area Code is China.
     */
    DJIUASAreaCodeChina,


    /**
     *  America.
     */
    DJIUASAreaCodeUS,
    

    /**
     *  The Area Code is France.
     */
    DJIUASAreaCodeFrance,


    /**
     *  The Area Code is Japan.
     */
    DJIUASAreaCodeJapan,
    

    /**
     *  The Area Code is US.
     */
    DJIUASAreaCodeCanada,
    

    /**
     *  The Area Code is Macau.
     */
    DJIUASAreaCodeMacau,


    /**
     *  The Area Code is HongKong.
     */
    DJIUASAreaCodeHongKong,
    


    /**
     *  The Area Code is unknown.
     */
    DJIUASAreaCodeUnknown = 0xFF,
};


/**
 *  The remote identification status listener of the drone.
 */
@interface DJIUASRemoteIDStatus : NSObject


/**
 *  Returns the working state of UAS remote identification(RID).
 */
@property (nonatomic, readonly) DJIRemoteIDWorkingState remoteIDWorkingState;


/**
 *  Returns whether the RID broadcast function of the drone is enabled.
 */
@property (nonatomic, readonly) BOOL isBroadcastRemoteIdEnabled;

@end


/**
 *  This protocol provides delegate methods to receive the updated status related to
 *  UAS Remote ID.
 */
@protocol DJIUASRemoteIDManagerDelegate <NSObject>

@optional


/**
 *  Called when the UAS Remote ID Status changes.
 *  
 *  @param manager The Remote ID manager that updates the current status.
 *  @param remoteIDStatus An object value of `DJIUASRemoteIDStatus`.
 */
-(void)manager:(DJIUASRemoteIDManager *)manager didUpdateUASRemoteIDStatus:(DJIUASRemoteIDStatus *)remoteIDStatus;

@end


/**
 *  RID management class of the drone system. In order to meet the increasingly
 *  standardized drone regulatory requirements around the world, The drone in flight
 *  should be able to broadcast the identification and location of the operator and
 *  the drone.
 */
@interface DJIUASRemoteIDManager : NSObject


/**
 *  Delegate that receives the UAS Remote ID Status.
 */
@property (nonatomic, weak) id<DJIUASRemoteIDManagerDelegate> delegate;


/**
 *  Set the area code of country or area. The following functions can not be used
 *  unless the corresponding area code is set.
 *  Currently the supported country or area list and the supported function list is
 *  as follows: - USA: remote identification broadcast of drone
 *  
 *  @param areaCode Area code of country or area.
 *  @param completion Completion block.
 */
- (void)setAreaCode:(DJIUASAreaCode)areaCode withCompletion:(DJICompletionBlock)completion;

@end

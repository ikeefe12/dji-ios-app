//
//  DJIRTKNetworkServiceProvider.h
//  DJISDK
//
//  Copyright © 2018 DJI. All rights reserved.
//

#import "DJISDKFoundation.h"
#import <DJISDK/DJIRTKServcieBaseTypes.h>
NS_ASSUME_NONNULL_BEGIN

@class DJIRTKNetworkServiceState;
@class DJIRTKNetworkServiceSettings;


/**
 *  This class is used to control the RTK network service. The
 *  DJIRTKNetworkServiceProvider can  initiate the communication to a third-party
 *  RTK network server. The information from the server can  be streamed to the RTK
 *  airsystem. SDK will not cache the settings to the disk. The provider should be
 *  configured in each life cycle of SDK. The life cycle of the network service
 *  provider is independent  from the aircraft. Therefore, it can be configured
 *  before connecting to DJI aircrafts. It is only supported  by Phantom 4 RTK, P4
 *  Multispectral, Mavic 2 Enterprse Advanced, Matrice 210 RTK V2 and Matrice 300
 *  RTK.
 */
@interface DJIRTKNetworkServiceProvider : NSObject

- (instancetype)init OBJC_UNAVAILABLE("You must use the singleton");

+ (instancetype)new OBJC_UNAVAILABLE("You must use the singleton");


/**
 *  Sets the configuration for the network service that provides network reference
 *  stations.  The network service should use NTRIP (Networked Transport of RTCM via
 *  Internet Protocol).
 *  
 *  @param settings The configuration to set.
 */
- (void)setNetworkServiceSettings:(DJIRTKNetworkServiceSettings *)settings;


/**
 *  Gets the configuration for the network service that provides network reference
 *  stations.  The network service should use NTRIP(Networked Transport of RTCM via
 *  Internet Protocol).
 *  
 *  @return An instance of `DJIRTKNetworkServiceSettings`.
 */
- (DJIRTKNetworkServiceSettings *_Nullable)networkServiceSettings;


/**
 *  Starts the network service as the reference station. This should be called after
 *  setting the  network service (`setNetworkServiceSettings`).
 *  
 *  @param completion The completion block that receives the result.
 */
- (void)startNetworkServiceWithCompletion:(DJICompletionBlock)completion;


/**
 *  Starts the network service as the reference station. This should be called after
 *  setting the  network service (`setNetworkServiceSettings`).
 *  
 *  @param coordinateSystem The coordinateSystem to set when init rtk service
 *  @param completion The completion block that receives the result.
 */
- (void)startNetworkServiceWithCoordinateSystem:(DJIRTKNetworkServiceCoordinateSystem)coordinateSystem WithCompletion:(DJICompletionBlock)completion;


/**
 *  Stops the network service.
 *  
 *  @param completion The completion block that receives the result.
 */
- (void)stopNetworkServiceWithCompletion:(DJICompletionBlock)completion;


/**
 *  Block that receive the network service state.
 *  
 *  @param state The network service state.
 */
typedef void (^_Nullable DJIRTKNetworkServiceStateBlock) (DJIRTKNetworkServiceState *state);


/**
 *  The current network service state.
 */
@property (nonatomic, readonly) DJIRTKNetworkServiceState *currentState;


/**
 *  Adds a listener to receive the latest network service state.
 *  
 *  @param listener Listener to receive network service state. It is used to distinguish different listener and the listener will be retained.
 *  @param queue The dispatch queue to process state. The main queue is used if it is `nil`.
 *  @param block The block that process the latest state.
 */
- (void)addNetworkServiceStateListener:(id)listener
                                 queue:(nullable dispatch_queue_t)queue
                                 block:(DJIRTKNetworkServiceStateBlock)block;


/**
 *  Removes a listener that is added by passing to
 *  `addNetworkServiceStateListener:queue:block`.
 *  
 *  @param listener The listener to remove.
 */
- (void)removeNetworkServiceStateListener:(id)listener;


/**
 *  Gets current network RTK coordinate system.
 *  
 *  @return Current `DJIRTKNetworkServiceCoordinateSystem`.
 */
- (DJIRTKNetworkServiceCoordinateSystem)currentNetworkServiceCoordinateSystem;


/**
 *  Sets coordinate system for rtk network service. Only can be used when  current
 *  `DJIRTKReferenceStationSource` is `DJIRTKReferenceStationSourceNetworkRTK`,  and
 *  please make sure the `channelState` is
 *  `DJIRTKNetworkServiceChannelStateTransmitting`.
 *  
 *  @param coordinateSystem The `DJIRTK_DJIRTKNetworkServiceCoordinateSystem` to set.
 *  @param completion The completion block that receives the result.
 */
- (void)setNetworkServiceCoordinateSystem:(DJIRTKNetworkServiceCoordinateSystem)coordinateSystem completion:(DJICompletionBlock)completion;


/**
 *  Activates network RTK `activateNetworkServiceWithPlanType:completion`.
 *  
 *  @param type Enum of `DJIRTKNetworkServicePlanType`.
 *  @param completion The completion block that receives the result.
 */
- (void)activateNetworkServiceWithPlanType:(DJIRTKNetworkServicePlanType)type completion:(DJICompletionBlock)completion;


/**
 *  Gets network service plans.
 *  
 *  @param plans The value of the `DJIRTKNetworkServicePlansState`.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getNetworkServiceOrderPlansWithCompletion:(void(^)(DJIRTKNetworkServicePlansState *_Nullable plans, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

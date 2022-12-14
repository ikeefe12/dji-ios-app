//
//  DJIRTKServcieBaseTypes.h
//  DJISDK
//
//  Copyright © 2018 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  All the possible state of `DJIRTKReferenceStationSource`.
 */
typedef NS_ENUM(uint8_t, DJIRTKReferenceStationSource) {
    

    /**
     *  RTK is using the D-RTK 2 base station as the reference station. It is supported
     *  by Phantom 4 RTK, P4 Multispectral and Matrice 300 RTK.
     */
    DJIRTKReferenceStationSourceBaseStation,
    

    /**
     *  RTK is using third-party network service as the reference station. The network
     *  service should use  NTRIP(Networked Transport of RTCM via  Internet Protocol).
     *  It is supported by Phantom 4 RTK, P4 Multispectral, Matrice 210 RTK V2 and
     *  Matrice 300 RTK.
     */
    DJIRTKReferenceStationSourceCustomNetworkService,
    

    /**
     *  Default virtual reference station solution to provide cm level accurate
     *  position.  The frame can be either WGS84 or CGCS 2000. Please note that this
     *  default solution can only be used  in China. Please add the
     *  "DJINetworkRTKHelper.framework" ~> '2.0.2' to the project by using Cocoapods
     *  (https://cocoapods.org/pods/DJINetworkRTKHelper) to get the rtcm  data. It is
     *  only supported  by Phantom 4 RTK, P4 Multispectral and Matrice 300 RTK.
     */
    DJIRTKReferenceStationSourceNetworkRTK,


    /**
     *  Unknown reference station source.
     */
    DJIRTKReferenceStationSourceUnknown = 0xFF,
};


/**
 *  All the possible state of `DJIRTKNetworkServiceChannelState`.
 */
typedef NS_ENUM(uint8_t, DJIRTKNetworkServiceChannelState) {

    /**
     *  The network service is not started.
     */
    DJIRTKNetworkServiceChannelStateDisabled,

    /**
     *  The network is not reachable from the mobile device.
     */
    DJIRTKNetworkServiceChannelStateNetworkNotReachable,

    /**
     *  The aircraft is not connected.
     */
    DJIRTKNetworkServiceChannelStateAircraftDisconnected,

    /**
     *  SDK cannot login with the provided username and password.  Check `error`.
     */
    DJIRTKNetworkServiceChannelStateLoginFailure,

    /**
     *  The channel from the server to the aircraft is built up. It is ready  for
     *  transmission.
     */
    DJIRTKNetworkServiceChannelStateReady,

    /**
     *  Data is transmitting through the channel.
     */
    DJIRTKNetworkServiceChannelStateTransmitting,

    /**
     *  The channel is disconnected and the server is not reachable now. Check `error`.
     */
    DJIRTKNetworkServiceChannelStateDisconnected,
    

    /**
     *  User account error. Check `error`.
     */
    DJIRTKNetworkServiceChannelStateAccountError,


    /**
     *  Unable to connect to server.
     */
    DJIRTKNetworkServiceChannelStateServerNotReachable,
    

    /**
     *  Connecting to server.
     */
    DJIRTKNetworkServiceChannelStateConnecting,
    

    /**
     *  The account for network RTK plan A has been expired, please activate plan B.
     */
    DJIRTKNetworkServiceChannelStateServiceSuspension,


    /**
     *  The invalid request is rejected by the server.
     */
    DJIRTKNetworkServiceChannelStateInvalidRequest,
    

    /**
     *  Unknown.
     */
    DJIRTKNetworkServiceChannelStateUnknown = 0xFF,
};


/**
 *  This enum defines the positioning solution currently being used.
 */
typedef NS_ENUM (uint8_t, DJIRTKPositioningSolution){
    

    /**
     *  No positioning solution. This can be caused by an insufficient number of
     *  satellites in view, insufficient time to lock onto the satellites, or a  loss in
     *  communication link between the mobile station and base station.
     */
    DJIRTKPositioningSolutionNone,
    

    /**
     *  RTK point positioning.
     */
    DJIRTKPositioningSolutionSinglePoint,
    

    /**
     *  Float solution positioning.
     */
    DJIRTKPositioningSolutionFloat,
    

    /**
     *  Fixed-point solution positioning (most accurate).
     */
    DJIRTKPositioningSolutionFixedPoint,


    /**
     *  Unknown.
     */
    DJIRTKPositioningSolutionUnknown = 0xFF,
};


/**
 *  This enum defines the Heading solution currently being used. The  heading
 *  solution describes the method used to determine heading. And  Indicates the
 *  accuracy of the `heading`. It is  supported by Phantom 4 RTK and Matrice 200
 *  Series V2.
 */
typedef NS_ENUM (uint8_t, DJIRTKHeadingSolution){
    

    /**
     *  No heading solution. This can be caused by an insufficient number of  satellites
     *  in view, insufficient time to lock onto the satellites, or a  loss in
     *  communication link between the mobile station and base station.
     */
    DJIRTKHeadingSolutionNone,
    

    /**
     *  RTK point Heading.
     */
    DJIRTKHeadingSolutionSinglePoint,
    

    /**
     *  Float solution Heading.
     */
    DJIRTKHeadingSolutionFloat,
    

    /**
     *  Fixed-point solution direction (most accurate).
     */
    DJIRTKHeadingSolutionFixedPoint,
    

    /**
     *  Unknown.
     */
    DJIRTKHeadingSolutionUnknown = 0xFF,
};


/**
 *  This enum defines the data source (either GPS or RTK) of a recorded location,
 *  e.g. home point. Only support by Phantom 4 RTK.
 */
typedef NS_ENUM (uint8_t, DJIRTKDataSource){
    

    /**
     *  The location coordinate is from GPS.
     */
    DJIRTKDataSourceGPS,
    

    /**
     *  The location coordinate is from RTK.
     */
    DJIRTKDataSourceRTK,
    

    /**
     *  Data source is unknown.
     */
    DJIRTKDataSourceUnknown = 0xFF,
};
    

/**
 *  Coordinate System for Network RTK. It is supported by Phantom 4 RTK.
 */
typedef NS_ENUM(uint8_t, DJIRTKNetworkServiceCoordinateSystem) {

    /**
     *  The coordinate system is World Geodetic System 1984.
     */
    DJIRTKNetworkServiceCoordinateSystemWGS84,
    

    /**
     *  The coordinate system is China Geodetic Coordinate System 2000.
     */
    DJIRTKNetworkServiceCoordinateSystemCGCS2000,
    

    /**
     *  The coordinate system is unknown.
     */
    DJIRTKNetworkServiceCoordinateSystemUnknown = 0xFF,
};


/**
 *  All the possible state of `DJIRTKNetworkServiceCoordinateSystem`. It is
 *  supported by Phantom 4 RTK.
 */
typedef NS_ENUM(uint8_t, DJIRTKNetworkServiceAccountState) {

    /**
     *  Network RTK service is not purchased.
     */
    DJIRTKNetworkServiceAccountStateNotPurchased,
    

    /**
     *  Device is not bound.
     */
    DJIRTKNetworkServiceAccountStateUnbound,
    

    /**
     *  Device is bound.
     */
    DJIRTKNetworkServiceAccountStateBound,


    /**
     *  Network RTK service account state is unknown.
     */
    DJIRTKNetworkServiceAccountStateUnknown = 0xFF,
};


/**
 *  Network RTK service plan type.
 */
typedef NS_ENUM(NSUInteger, DJIRTKNetworkServicePlanType){

    /**
     *  Plan type A.
     */
    DJIRTKNetworkServicePlanTypeA,
    

    /**
     *  Plan type B.
     */
    DJIRTKNetworkServicePlanTypeB,
    

    /**
     *  Unknown Plan type.
     */
    DJIRTKNetworkServicePlanTypeUnknown = 0xFF,
};


/**
 *  Network RTK Service Plan's State.
 */
typedef NS_ENUM(NSUInteger, DJIRTKNetworkServicePlanState){

    /**
     *  The plan has not activated.
     */
    DJIRTKNetworkServicePlanStateUnactivated,
    

    /**
     *  The plan has activated.
     */
    DJIRTKNetworkServicePlanStateActivated,
    

    /**
     *  The plan has Expired.
     */
    DJIRTKNetworkServicePlanStateExpired,


    /**
     *  The plan state is unknown.
     */
    DJIRTKNetworkServicePlanStateUnknown = 0xFF,
};


/**
 *  The state of network service that provides reference station information.
 */
@interface DJIRTKNetworkServiceState : NSObject<NSCopying>


/**
 *  The state of the channel from the aircraft to the server that provides RTK
 *  network service.
 */
@property (nonatomic, readonly) DJIRTKNetworkServiceChannelState channelState;


/**
 *  The encountered error if any when building up the channel from the aircraft to
 *  the server  that provides RTK network service.
 */
@property (nonatomic, nullable, readonly) NSError *error;

@end


/**
 *  Network service Plan information.
 */
@interface DJIRTKNetworkServicePlan : NSObject


/**
 *  Gets network RTK plan state.
 */
@property(nonatomic, readonly)  DJIRTKNetworkServicePlanState state;


/**
 *  Gets network RTK plan activation date.
 */
@property(nonatomic, readonly) double activateionDate;


/**
 *  Gets network RTK plan expiration date.
 */
@property(nonatomic, readonly) double expirationDate;


/**
 *  Gets network RTK plan type.
 */
@property(nonatomic, readonly) DJIRTKNetworkServicePlanType planType;

@end


/**
 *  Gets state of network service plans.
 */
@interface DJIRTKNetworkServicePlansState : NSObject


/**
 *  Gets current account state.
 */
@property(nonatomic, readonly) DJIRTKNetworkServiceAccountState state;


/**
 *  Gets current account supported renewal times. If current account state is
 *  `DJIRTKNetworkServiceAccountStateNotPurchased`  or
 *  `DJIRTKNetworkServiceAccountStateUnbound`, the support renewakTimes will always
 *  be 0. If current account state is `DJIRTKNetworkServiceAccountStateBound`, this
 *  will return the supported renewal times. You can only renew at most once before
 *  you activate the renewal phase.
 */
@property(nonatomic, readonly) NSInteger supportedRenewalTimes;


/**
 *  Gets network RTK plans.
 */
@property(nonatomic, readonly) NSArray <DJIRTKNetworkServicePlan *> *plans;

@end


/**
 *  The class is used to save the information of the base station. Only supported by
 *  Matrice 300 RTK series.
 */
@interface DJIRTKBaseStationInformation : NSObject


/**
 *  Gets the scanned base station's ID.
 */
@property(nonatomic, readonly) NSUInteger baseStationID;


/**
 *  Gets the scanned base station's name.
 */
@property(nonatomic, readonly) NSString *baseStationName;


/**
 *  Gets the signal level of the base station. The signal is in range [0, 5], where
 *  5 is the strongest signal.
 */
@property(nonatomic, readonly) int signalLevel;

@end


/**
 *  All the possible connection state of
 *  DJIRTKConnectionStateWithBaseStationReferenceSource  when
 *  `DJIRTKReferenceStationSource`  is  `DJIRTKReferenceStationSourceBaseStation`.
 *  It is only supported by Matrice 300 RTK.
 */
typedef NS_ENUM(uint8_t, DJIRTKConnectionStateWithBaseStationReferenceSource) {
    

    /**
     *  Aircraft RTK is in idle state.
     */
    DJIRTKConnectionStateWithBaseStationReferenceSourceAircraftRTKIdle,
    

    /**
     *  Aircraft is scanning all base stations that are possible to be connected.
     */
    DJIRTKConnectionStateWithBaseStationReferenceSourceAircraftRTKScanning,
    

    /**
     *  The aircraft is connecting with the base station.
     */
    DJIRTKConnectionStateWithBaseStationReferenceSourceBaseStationConnecting,
    

    /**
     *  The aircraft is connected with the base station.
     */
    DJIRTKConnectionStateWithBaseStationReferenceSourceBaseStationConnected,
    

    /**
     *  The aircraft is disconnected from the base station.
     */
    DJIRTKConnectionStateWithBaseStationReferenceSourceBaseStationDisconnected,
    

    /**
     *  Unknown base station location connection state.
     */
    DJIRTKConnectionStateWithBaseStationReferenceSourceUnknown = 0xFF,
};

NS_ASSUME_NONNULL_END

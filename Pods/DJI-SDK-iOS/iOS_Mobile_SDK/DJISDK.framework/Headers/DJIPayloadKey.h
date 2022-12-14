//
//  DJIPayloadKey.h
//  DJISDK
//
//  Copyright © 2018, DJI. All rights reserved.
//

#import "DJIKey.h"

NS_ASSUME_NONNULL_BEGIN

EXTERN_KEY NSString *const DJIPayloadComponent;

EXTERN_KEY NSString *const DJIPayloadParamPayloadName;
EXTERN_KEY NSString *const DJIPayloadParamUpstreamBandwidth;
EXTERN_KEY NSString *const DJIPayloadParamMaximumContractedVolume;
EXTERN_KEY NSString *const DJIPayloadParamConfigureWidgetValue;
EXTERN_KEY NSString *const DJIPayloadParamProductPhase;
EXTERN_KEY NSString *const DJIPayloadParamDeviceType;
EXTERN_KEY NSString *const DJIPayloadParamisFunctionLimited;
EXTERN_KEY NSString *const DJIPayloadParamIsActivated;
EXTERN_KEY NSString *const DJIPayloadParamPayloadIsReady;

EXTERN_KEY NSString *const DJIPayloadParamMainInterfaceWidgets;
EXTERN_KEY NSString *const DJIPayloadParamConfigInterfaceWidgets;


/**
 *  `DJIPayloadKey` provides dedicated access to Flight  controller attributes.
 */
@interface DJIPayloadKey : DJIKey

@end

NS_ASSUME_NONNULL_END

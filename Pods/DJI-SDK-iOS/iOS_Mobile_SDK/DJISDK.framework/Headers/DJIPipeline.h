//
//  DJIPipeline.h
//  DJISDK
//
//  Copyright © 2020 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DJISDKFoundation.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Defines pipeline transmission control type.
 */
typedef NS_ENUM(NSUInteger, DJITransmissionControlType) {

    /**
     *  Guarantees delivery of data and that packets will be delivered in the order they
     *  were sent.
     */
    DJITransmissionControlTypeStable,

    /**
     *  This transmission control type does not provide guaranteed delivery and a
     *  datagram packet may become corrupt or lost in transit.  Suitable for time-
     *  sensitive transmission.
     */
    DJITransmissionControlTypeUnreliable,
};


/**
 *  The enum is used to represent the pipeline device type.
 */
typedef NS_ENUM(NSUInteger, DJIPipelineDeviceType) {

    /**
     *  Onboard device. Please check the developer website: https://developer.dji.com
     *  /onboard-sdk/.
     */
    DJIPipelineDeviceTypeOnboard,

    /**
     *  Payload device. Please check the developer website: https://developer.dji.com
     *  /payload-sdk/.
     */
    DJIPipelineDeviceTypePayload,

    /**
     *  Unknown.
     */
    DJIPipelineDeviceTypeUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark - DJIPipeline
/*********************************************************************************/


/**
 *  Establishes a pipeline connected with Onboard device or Payload device to
 *  transmit data. Uses `connect:pipelineType:withCompletion` to create a pipeline.
 *  `disconnect:withCompletion` can be invoked to destroy the data transmission
 *  channel and disconnect from the Onboard device or Payload device.
 */
@interface DJIPipeline : NSObject


/**
 *  The identification number of the pipeline connected with the Payload or the
 *  Onboard device.
 */
@property (nonatomic, readonly) uint16_t Id;


/**
 *  Transmission processing type.
 */
@property (nonatomic, readonly) DJITransmissionControlType transmissionType;


/**
 *  Device type connected.
 */
@property (nonatomic, readonly) DJIPipelineDeviceType deviceType;


/**
 *  Data to be sent. 1 KB data size is recommended.
 *  
 *  @param data The data needs to be sent.
 *  @param error A pointer to an error object. It is nullable if no further error information is expected.  Tries to invoke `disconnect:withCompletion` and then `disconnect:withCompletion` to reconnect, if the connection is broken due to any exception.
 *  
 *  @return Sent data length.
 */
- (int32_t)writeData:(NSData *)data error:(NSError **)error;


/**
 *  Read data from the pipeline.
 *  
 *  @param readLength Maximum cache length to read
 *  @param error A pointer to an error object. It is nullable if no further error information is expected.
 *  
 *  @return Read data length.
 */
- (NSData *)readData:(uint32_t)readLength error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END

//
//  DJILidarCapabilities.h
//
//  Copyright © 2020 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Some of the lidar's parameters have dynamic ranges. The `DJILidarCapabilities`
 *  class allows you to query the valid range for a parameter. Type-casting is
 *  required to get the corresponding enumerator value for each range element.
 */
__attribute__((objc_runtime_name("dc376214-c374-11eb-a09f-acde48001122"))) 
@interface DJILidarCapabilities : NSObject


/**
 *  Returns the current valid range of sampling rate.
 *  
 *  @return Array of `DJILidarPointCloudSamplingRate` elements. Each element represents one current supported lidar data sample rate.
 */
- (nonnull NSArray<NSNumber *> *)lidarPointCloudSamplingRateRange;

@end

NS_ASSUME_NONNULL_END

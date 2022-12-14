//
//  DJILidarKey.h
//  DJISDK
//
//  Copyright © 2021 DJI. All rights reserved.
//

#import "DJIKey.h"

NS_ASSUME_NONNULL_BEGIN

EXTERN_KEY NSString *const DJILidarComponent;

EXTERN_KEY NSString *const DJILidarParamPointCloudScanMode;
EXTERN_KEY NSString *const DJILidarParamPointCloudReturnMode;
EXTERN_KEY NSString *const DJILidarParamPointCloudHighSensitivityModeEnabled;
EXTERN_KEY NSString *const DJILidarParamPointCloudSampleRate;
EXTERN_KEY NSString *const DJILidarParamPointCloudVisibleLightPixel;
EXTERN_KEY NSString *const DJILidarParamPointCloudRecord;
EXTERN_KEY NSString *const DJILidarParamPointCloudRecordStatus;


/**
 *  `DJILidarKey` provides dedicated access to the lidar attributes.
 */
@interface DJILidarKey : DJIKey

@end

NS_ASSUME_NONNULL_END

//
//  DJILidarPointCloudLiveViewData.h
//  SDKSharedLib
//
//  Created by ethan.jiang on 2021/5/10.
//  Copyright © 2021 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  This class represent the piont cloud live view data.
 */
@interface DJILidarPointCloudLiveViewData : NSObject


/**
 *  The X coordinate of the object position measured by the lidar, using the
 *  NED(North East Down) coordinate system. The position of lidar when starting to
 *  record the point cloud is the origin of the coordinate system(0, 0, 0).
 */
@property (nonatomic, readonly) float x;


/**
 *  The XYcoordinate of the object position measured by the lidar, using the
 *  NED(North East Down) coordinate system.  The position of lidar when starting to
 *  record the point cloud is the origin of the coordinate system(0, 0, 0).
 */
@property (nonatomic, readonly) float y;


/**
 *  The Z coordinate of the object position measured by the lidar, using the
 *  NED(North East Down) coordinate system.  The position of lidar when starting to
 *  record the point cloud is the origin of the coordinate system(0, 0, 0).
 */
@property (nonatomic, readonly) float z;


/**
 *  Intensity is a measurement index (collected for each point) that reflects the
 *  intensity of the lidar pulse echo generated at a certain point. This value is
 *  based in part on the reflectivity of the object swept by the lidar pulse.
 */
@property (nonatomic, readonly) NSUInteger intensity;


/**
 *  RGB data of the object measured by the lidar. If you set visible light pixel
 *  mode to `DJILidarPointCloudVisibleLightPixelOff`, the Data will be (0, 0, 0).
 */
@property (nonatomic, readonly) NSUInteger red;


/**
 *  RGB data of the object measured by the lidar. If you set visible light pixel
 *  mode to `DJILidarPointCloudVisibleLightPixelOff`, the Data will be (0, 0, 0).
 */
@property (nonatomic, readonly) NSUInteger green;


/**
 *  RGB data of the object measured by the lidar. If you set visible light pixel
 *  mode to `DJILidarPointCloudVisibleLightPixelOff`, the Data will be (0, 0, 0).
 */
@property (nonatomic, readonly) NSUInteger blue;

@end

NS_ASSUME_NONNULL_END

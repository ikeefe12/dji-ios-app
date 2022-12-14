//
//  DJILidar.h
//  DJISDK
//
//  Created by neo.xu on 2020/12/6.
//  Copyright © 2020 DJI. All rights reserved.
//

#import <DJISDK/DJISDK.h>
#import <DJISDK/DJIBaseComponent.h>
#import <DJISDK/DJILidarCapabilities.h>

@class DJILidarPayloadPOSStatus;
@class DJILidarPointCloudLiveViewData;


/**
 *  This protocol provides a delegate method to update the lidar state and receive
 *  the lidar data.
 */
@protocol DJILidarDelegate <NSObject>

@optional


/**
 *  When the point cloud record status is changed, the listener will receive this
 *  callback.
 *  
 *  @param lidar Instance of the lidar for which status will be updated.
 *  @param status Point cloud record status
 */
- (void)lidar:(DJILidar *)lidar didUpdatePointCloudRecordStatus:(DJILidarPointCloudRecordStatus)status;


/**
 *  When the IMU preheat status is changed, the listener will receive this
 *  callback.
 *
 *  @param lidar Instance of the lidar for which status will be updated.
 *  @param status The IMU preheat status
 */
- (void)lidar:(DJILidar *)lidar didUpdateIMUPreHeatStatus:(DJILidarIMUPreheatStatus)status;


/**
 *  When the point cloud recording time is updated, the listener will receive this
 *  callback.
 *  
 *  @param lidar Instance of the lidar for which status will be updated.
 *  @param time Point cloud recording time.
 */
- (void)lidar:(DJILidar *)lidar didUpdatePointCloudRecordingTime:(NSUInteger)time;


/**
 *  Update point cloud live view data.
 *  
 *  @param lidar Instance of the lidar for which live view data of point could will be updated.
 *  @param pointCloudLiveViewData The point could live view data
 */
- (void)lidar:(DJILidar *)lidar didReceiveLiveViewData:(NSArray <DJILidarPointCloudLiveViewData *> *)pointCloudLiveViewData;

@end


/**
 *  This class represents the lidar of the aircraft which contanis the related
 *  functions of livox. Current only supported by Zenmuse L1. Note: Zenmuse L1 can
 *  only be set at Gimbal position 0 where it is at the left side of the aircraft.
 *   The Zenmuse L1 integrates a Livox Lidar module, a high-accuracy IMU, and a
 *  camera with a 1-inch CMOS on a 3-axis stabilized gimbal. When used with Matrice
 *  300 RTK and DJI Terra, the L1 forms a complete solution that gives you real-time
 *  3D data throughout the day, efficiently capturing the details of complex
 *  structures and delivering highly accurate reconstructed models.
 *   This object is available from the `DJIAircraft` or `DJIHandheld` object which
 *  is a subclass of `DJIBaseProduct`.
 */
@interface DJILidar : DJIBaseComponent


/**
 *  String that represents name of the Lidar.
 */
@property (nonatomic, readonly) NSString *_Nonnull displayName;


/**
 *  Lidar capabilities. You can you this interface to get the sampling rate range.
 */
@property(nonatomic, readonly) DJILidarCapabilities *capabilities;


/**
 *  Adds the listener for the point cloud status change events.
 *  
 *  @param listener Point cloud status change listener.
 */
- (void)addPointCloudStatusListener:(id<DJILidarDelegate>)listener withQueue:(nullable dispatch_queue_t)queue;


/**
 *  Remove the listener for the point cloud status change events.
 *  
 *  @param listener Point cloud status change listener.
 */
- (void)removePointCloudStatusListener:(id<DJILidarDelegate>)listener;


/**
 *  Remove all point cloud status listeners.
 */
- (void)removeAllPointCloudStatusListener;


/**
 *  Set point cloud scan mode.
 *  
 *  @param mode An enum value of the `DJILidarPointCloudScanMode`
 *  @param completion The completion block that receives the execution result.
 */
- (void)setPointCloudScanMode:(DJILidarPointCloudScanMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Get point cloud scan mode.
 *  
 *  @param completion The completion block that receives the execution result.
 */
- (void)getPointCloudScanModeWithCompletion:(void (^_Nonnull)(DJILidarPointCloudScanMode mode, NSError *_Nullable error))completion;


/**
 *  Set point cloud return mode.
 *  
 *  @param mode An enum value of the `DJILidarPointCloudReturnMode`
 *  @param completion The completion block that receives the execution result.
 */
- (void)setPointCloudReturnMode:(DJILidarPointCloudReturnMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Get point cloud scan mode.
 *  
 *  @param completion The completion block that receives the execution result.
 */
- (void)getPointCloudReturnModeWithCompletion:(void (^_Nonnull)(DJILidarPointCloudReturnMode mode, NSError *_Nullable error))completion;


/**
 *  Enables/Disables high sensitivity mode. In severe weather conditions such as
 *  rain and fog, high sensitivity mode reduces the probability of false detection
 *  of atmospheric particles.
 *  
 *  @param mode An enum value of the `DJILidarPointCloudReturnMode`
 *  @param completion The completion block that receives the execution result.
 */
- (void)setPointCloudHighSensitivityModeEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  `YES` if high sensitivity mode is enabled.
 *  
 *  @param completion The completion block that receives the execution result.
 */
- (void)getPointCloudHighSensitivityModeEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Set point cloud sampling rate. The sampling rate represents the number of
 *  effective acquisitions of the lidar per second, which can be intuitively
 *  understood as the number of point clouds generated in one second. The sampling
 *  rate range depend on the `DJILidarPointCloudReturnMode`. You can use
 *  `lidarPointCloudSamplingRateRange` to get the current support range when you
 *  change the point cloud return mode.
 *  
 *  @param rate An enum value of the `DJILidarPointCloudSamplingRate`
 *  @param completion The completion block that receives the execution result.
 */
- (void)setPointCloudSampleRate:(DJILidarPointCloudSamplingRate)rate withCompletion:(DJICompletionBlock)completion;


/**
 *  Get point cloud sampling rate.
 *  
 *  @param completion The completion block that receives the execution result.
 */
- (void)getPointCloudSampleRateWithCompletion:(void (^_Nonnull)(DJILidarPointCloudSamplingRate rate, NSError *_Nullable error))completion;


/**
 *  Set superimposed visible light pixels for coloring the model
 *  
 *  @param mode An enum value of the `DJILidar_PointCloudVisibleLightPixelMode``
 *  @param completion The completion block that receives the execution result.
 */
- (void)setPointCloudVisibleLightPixel:(DJILidarPointCloudVisibleLightPixelMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Get point cloud visible light pixel.
 *  
 *  @param completion The completion block that receives the execution result.
 */
- (void)getPointCloudVisibleLightPixelWithCompletion:(void (^_Nonnull)(DJILidarPointCloudVisibleLightPixelMode mode, NSError *_Nullable error))completion;


/**
 *  Point cloud record related operations.
 *  
 *  @param cmd An enum value of the `DJILidarPointCloudRecord`
 *  @param completion The completion block that receives the execution result.
 */
- (void)pointCloudRecord:(DJILidarPointCloudRecord)cmd withCompletion:(DJICompletionBlock)completion;


/**
 *  Start to receive the point cloud live view data. Using
 *  `lidar:didReceiveLiveViewData` to receive the data.
 *  
 *  @param completion The completion block that receives the execution result.
 */
- (void)startReadPointCloudLiveViewDataWithCompletion:(DJICompletionBlock)completion;


/**
 *  Stop to receive the point cloud live view data.
 *  
 *  @param completion The completion block that receives the execution result.
 */
- (void)stopReadPointCloudLiveViewDataWithCompletion:(DJICompletionBlock)completion;


/**
 *  Adds the listener to receive point cloud data.
 *  
 *  @param listener Point cloud data listener.
 */
- (void)addPointCloudLiveViewDataListener:(id<DJILidarDelegate>_Nonnull)listener withQueue:(nullable dispatch_queue_t)queue;


/**
 *  Remove the listener to receive point cloud data.
 *  
 *  @param listener Point cloud data update listener.
 */
- (void)removePointCloudLiveViewDataListener:(id<DJILidarDelegate>_Nonnull)listener;

@end


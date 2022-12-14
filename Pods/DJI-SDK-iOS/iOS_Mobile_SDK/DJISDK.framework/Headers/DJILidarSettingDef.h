//
//  DJILidarSettingDef.h
//
//  Copyright © 2020 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  Enums represent the point cloud scan mode of lidar. Supports two scanning modes:
 *  traditional non-repetitive scan mode and repetitive line scan mode. Users can
 *  choose the appropriate scanning point cloud pattern according to their needs.
 *  The repetitive scan mode is a flat FOV(70.4 degree * 4.5 degree), and its
 *  scanning method is more similar to the traditional scanning lidar, which can
 *  obtain a more uniform and higher-precision scanning effect; The non-repetitive
 *  scan mode is a unique scanning method of livox, providing a complete near-
 *  circular FOV(70.4 degree *77.2 degree), which has better scanning static
 *  scanning effect and facade effect, and higher efficiency;
 */
typedef NS_ENUM (NSUInteger, DJILidarPointCloudScanMode) {

    /**
     *  Non-repetitive scan mode.
     */
    DJILidarPointCloudScanModeNonRepeat = 0,

    /**
     *  Repetitive scan mode.
     */
    DJILidarPointCloudScanModeRepeat = 1,

 
    /**
     *  Unknown.
     */
    DJILidarPointCloudScanModeUnknown = 0xFF,
};


/**
 *  Enums represent the point cloud return mode of lidar.
 */
typedef NS_ENUM (NSUInteger, DJILidarPointCloudReturnMode){

    /**
     *  Single return first (default).
     */
    DJILidarPointCloudReturnModeSingleEchoFirst = 0,
    

    /**
     *  Single return strongest.
     */
    DJILidarPointCloudReturnModeSingleEchoStrongest = 1,
    

    /**
     *  Double return.
     */
    DJILidarPointCloudReturnModeDoubleEcho = 2,
    

    /**
     *  Triple return.
     */
    DJILidarPointCloudReturnModeTripleEcho = 3,
    
 
    /**
     *  Unknown.
     */
    DJILidarPointCloudReturnModeUnknown = 0xFF,
};


/**
 *  Enums represent the point cloud sampling rate of lidar.
 */
typedef NS_ENUM (NSUInteger, DJILidarPointCloudSamplingRate){
    

    /**
     *  Sampling rate: 240KHZ
     */
    DJILidarPointCloudSamplingRate240KHZ = 0,
    

    /**
     *  Sampling rate: 160KHZ
     */
    DJILidarPointCloudSamplingRate160KHZ = 1,
    

    /**
     *  Sampling rate: 120KHZ
     */
    DJILidarPointCloudSamplingRate120KHZ = 2,
    

    /**
     *  Sampling rate: 80KHZ
     */
    DJILidarPointCloudSamplingRate80KHZ = 3,
    

    /**
     *  Sampling rate: 180KHZ
     */
    DJILidarPointCloudSamplingRate180KHZ = 4,
    

    /**
     *  Sampling rate: 60KHZ
     */
    DJILidarPointCloudSamplingRate60KHZ = 5,
    
  
    /**
     *  Unknown.
     */
    DJILidarPointCloudSamplingRateUnknown = 0xFF,
};


/**
 *  Enums represent the point visible light pixel mode of lidar.
 */
typedef NS_ENUM (NSUInteger, DJILidarPointCloudVisibleLightPixelMode){
    

    /**
     *  Turn off superimposed visible light pixels.
     */
    DJILidarPointCloudVisibleLightPixelOff = 0,
    

    /**
     *  Turn on superimposed visible light pixels. In this mode camera will take a photo
     *  every 3 seconds. It is recommended to use when flying aircraft manually.
     */
    DJILidarPointCloudVisibleLightPixelOnTimedShotOn = 1,
    

    /**
     *  Turn on superimposed visible light pixels. In this mode camera will not take
     *  photo automatically. It is recommended to use in Waypoint Mission and set the
     *  photo interval to 3 seconds.
     */
    DJILidarPointCloudVisibleLightPixelOnTimedShotOff = 2,
    
    /**
     *  Unknown.
     */
    DJILidarPointCloudVisibleLightPixelUnknown = 0xFF,
};


/**
 *  Point cloud record opration type define for point cloud. When you start point
 *  cloud recording on successfully, `DJILidarPointCloudRecordStatus` will change to
 *  `DJILidarPointCloudRecordStatusStarted`. You can use
 *  `lidar:didReceiveLiveViewData` to receive piont cloud live view data.
 */
typedef NS_ENUM (NSUInteger, DJILidarPointCloudRecord){

    /**
     *  Stop point cloud recording.
     */
    DJILidarPointCloudRecordStop = 0,
    

    /**
     *  Start point cloud recording.
     */
    DJILidarPointCloudRecordStart = 1,
    

    /**
     *  Pause point cloud recording.
     */
    DJILidarPointCloudRecordPause = 2,
    

    /**
     *  Resume point cloud recording.
     */
    DJILidarPointCloudRecordResume = 3,
    

    /**
     *  Unknown.
     */
    DJILidarPointCloudRecordUnknown = 0xFF,
};


/**
 *  Point cloud record status define for point cloud.
 */
typedef NS_ENUM (NSUInteger, DJILidarPointCloudRecordStatus){

    /**
     *  Point cloud record is starting.
     */
    DJILidarPointCloudRecordStatusStarting = 0,
    

    /**
     *  Point cloud is recording.
     */
    DJILidarPointCloudRecordStatusStarted = 1,
    

    /**
     *  Point cloud record is paused.
     */
    DJILidarPointCloudRecordStatusPause = 2,
    

    /**
     *  Point cloud record is resumed.
     */
    DJILidarPointCloudRecordStatusResume = 3,
    

    /**
     *  Point cloud record is stoping.
     */
    DJILidarPointCloudRecordStatusStopping = 4,
    

    /**
     *  Point cloud record is stoped.
     */
    DJILidarPointCloudRecordStatusStopped = 5,
    

    /**
     *  Unknown.
     */
    DJILidarPointCloudRecordStatusUnknown = 0xFF,
};


/**
 *  Point cloud IMU preheat status define for lidar. When the preheating is
 *  complete, the status will change to complete.
 */
typedef NS_ENUM (NSUInteger, DJILidarIMUPreheatStatus){

    /**
     *  IMU is Preheating.
     */
    DJILidarIMUPreheatStatusPreheating = 0,
    

    /**
     *  IMU preheat is Complete.
     */
    DJILidarIMUPreheatStatusPreheatCompleted = 1,
    
    /**
     *  Unknown.
     */
    DJILidarIMUPreheatStatusPreheatUnknown = 0xFF,
};


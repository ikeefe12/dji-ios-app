//
//  DJIUTMISSManager.h
//  DJISDK
//
//  Copyright © 2020 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  The UTMISS flight data upload status.
 */
typedef NS_ENUM(uint8_t, DJIUTMISSFlightDataUploadStatus) {


    /**
     *  The UTMISS flight data upload status is idle.
     */
    DJIUTMISSFlightDataUploadStatusIdle,


    /**
     *  The UTMISS flight data upload status is uploading.
     */
    DJIUTMISSFlightDataUploadStatusUploading,


    /**
     *  The UTMISS flight data upload status is caching.
     */
    DJIUTMISSFlightDataUploadStatusCaching,


    /**
     *  Out of data storage space. No more data can be written.
     */
    DJIUTMISSFlightDataUploadStatusOutOfDataStorageSpace,


    /**
     *  The UTMISS flight data upload status is unknown.
     */
    DJIUTMISSFlightDataUploadStatusUnknown,
};


/**
 *  This class provides necessary infomation to start UTMISS flight data uploading.
 */
@interface DJIUTMISSParam : NSObject


/**
 *  The local save path of flight data to be uploaded.
 */
@property (nonatomic, copy) NSString *savePath;


/**
 *  The token key applied from CAAC.
 */
@property (nonatomic, copy) NSString *tokenKey;


/**
 *  The manufacture ID of the drone.
 */
@property (nonatomic, copy) NSString *manufactureId;


/**
 *  The UAS ID of the drone.
 */
@property (nonatomic, copy) NSString *uasID;

@end


/**
 *  This protocol provides delegate methods to receive the UTMISS flight data upload
 *  status.
 */
@protocol DJIUTMISSManagerDelegate <NSObject>

@optional


/**
 *  Called when the UTMISS (Unmanned Aircraft System Traffic Management Information
 *  Service System) flight data upload status has been updated.
 *  
 *  @param uploadStatus UTMISS flight data upload status.
 */
- (void)didUpdateUTMISSFlightDataUploadStatus:(DJIUTMISSFlightDataUploadStatus)uploadStatus;

@end


/**
 *  This class is to manage UTMISS flight data upload. According to the "Civil
 *  Aviation Administration of China's Light Civil UAV Flight Dynamic Data
 *  Management Regulations ", relevant units, individuals that operate light, small
 *  civil drones and plant protection drones in the airspace provided by the
 *  People's Republic of China with air traffic services need Timely, accurate and
 *  complete real-time reporting to the Civil Aviation Administration to send real
 *  flight dynamic data. If flight dynamic data is not reported or missed in time,
 *  it shall be replaced in accordance with relevant regulations on navigation
 *  flight control. According to the above requirements, this function will report
 *  user flight dynamics data to the UTMISS server. Developers are requested to
 *  enable this function after obtaining user authorization.
 */
@interface DJIUTMISSManager : NSObject


/**
 *  Delegate that receives the UTMISS flight data upload status.
 */
@property (nonatomic, weak) id<DJIUTMISSManagerDelegate> delegate;


/**
 *  Necessary infomation to start UTMISS flight data uploading.
 */
@property (nonatomic, strong) DJIUTMISSParam *UTMISSParam;


/**
 *  The current UTMISS upload status.
 */
@property (nonatomic, assign) DJIUTMISSFlightDataUploadStatus currentStatus;


/**
 *  Start UTMISS flight data upload.
 *  
 *  @return An NSError object.
 */
- (nullable NSError *)startToUpload;


/**
 *  UTMISS Log save path.
 *  
 *  @return An NSString object.
 */
- (NSString *)getUtmissLogPath;


/**
 *  Stop UTMISS flight data upload.
 */
- (void)stopToUpload;

@end

NS_ASSUME_NONNULL_END

//
//  DJIVideoFeeder.h
//  DJISDK
//
//  Copyright © 2017, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DJISDK/DJIVideoFeedBaseTypes.h>
#import <DJISDK/DJICameraSettingsDef.h>
#import <DJISDK/DJIBaseProduct.h>

NS_ASSUME_NONNULL_BEGIN

@class DJIVideoFeed;


/**
 *  Listener that receives notifications when a new video physical source becomes
 *  available.
 */
@protocol DJIVideoFeedSourceListener <NSObject>


/**
 *  Called when a video feed is made available from a new physical source.
 *  
 *  @param videoFeed A `DJIVideoFeed` object.
 *  @param physicalSource An enum value of `DJIVideoFeedPhysicalSource`.
 */
- (void)videoFeed:(nonnull DJIVideoFeed *)videoFeed didChangePhysicalSource:(DJIVideoFeedPhysicalSource)physicalSource;

@optional


/**
 *  Called when a video feed's active status changes.
 *  
 *  @param videoFeed A `DJIVideoFeed` object.
 *  @param active BOOL value indicates if the feed is active.
 */
- (void)videoFeed:(nonnull DJIVideoFeed *)videoFeed didChangeActiveStatus:(BOOL)active;

@end


/**
 *  Represents a single video feed from a single channel or port.
 */
@protocol DJIVideoFeedListener <NSObject>


/**
 *  Called when the video feed receives new video data.
 *  
 *  @param videoFeed A `DJIVideoFeed` object.
 *  @param videoData New video data.
 */
- (void)videoFeed:(nonnull DJIVideoFeed *)videoFeed didUpdateVideoData:(nonnull NSData *)videoData;

@end


/**
 *  Video feed. Use it to receive video data from a physical source.
 */
@interface DJIVideoFeed : NSObject


/**
 *  The physical source of the video feed.
 */
@property (nonatomic, assign, readonly) DJIVideoFeedPhysicalSource physicalSource;


/**
 *  Determins if the video feed is active. Only supported by Matrice 300 RTK.
 */
@property (nonatomic, assign, readonly) BOOL active;


/**
 *  Set the channel priority of the video feed. Priority will affect the bandwidth
 *  allocation if it is  not `DJIVideoFeedPriorityUnknown`, which is the default
 *  value. For example,  if the data comes from the payload device mounted on left
 *  gimbal is prefer, please set the priority to `DJIVideoFeedPriorityHigh`,  and
 *  physicalSource is `DJIVideoFeedPhysicalSourceLeftCamera`. The others should be
 *  set to `DJIVideoFeedPriorityMedium` or `DJIVideoFeedPriorityLow`.  Only
 *  supported by Matrice 300 RTK.
 *  
 *  @param priority Priority for the primary video feed.
 *  @param completion Completion block.
 */
- (void)setPriority:(DJIVideoFeedPriority)priority withCompletion:(DJICompletionBlock)completion;


/**
 *  Get the channel priority of the video feed. Only supported by Matrice 300 RTK.
 *  
 *  @param priority Priority for the primary video feed.
 *  @param error Error encountered during the request. If the request is successful, it will be `nil`.
 *  @param completion Completion block.
 */
- (void)getPriorityWithCompletion:(void (^_Nonnull)(DJIVideoFeedPriority priority, NSError *_Nullable error))completion;


/**
 *  Add listener to receive new video data.
 *  
 *  @param videoFeedListener Listener to receive video data.
 *  @param queue The queue that `videoFeed:didUpdateVideoData` is called in.
 */
- (void)addListener:(id <DJIVideoFeedListener>)videoFeedListener withQueue:(nullable dispatch_queue_t)queue;


/**
 *  Remove listener to stop receiving new video data.
 *  
 *  @param videoFeedListener Listener to remove.
 */
- (void)removeListener:(id <DJIVideoFeedListener>)videoFeedListener;


/**
 *  Remove all Listeners for video feed.
 */
- (void)removeAllListeners;


/**
 *  Parses decoding assistant information for H.264 stream data. The information
 *  will be useful for the H.264 decoder.  This method has been moved from
 *  DJIVideoFeeder to DJIVideoFeed since 4.12 to support multiple channel decoding.
 *  
 *  @param buffer H.264 stream data to parse.
 *  @param length The data's length.
 *  @param assistInfo An allocated memory with at least 8 bytes to receive the assistant information.
 *  
 *  @return `YES` if information is parsed successfully from the stream.
 */
- (BOOL)parseDecodingAssistInfoWithBuffer:(uint8_t *)buffer length:(int)length assistInfo:(void *)assistInfo;


/**
 *  Synchronizes the decoder status (if it is in normal status) to the video feed.
 *  The decoder status is useful for the assistant  information parser. This method
 *  has been moved from DJIVideoFeeder to DJIVideoFeed since 4.12 to support
 *  multiple channel decoding.
 *  
 *  @param isNormal `YES` if the decoder is in normal status.
 */
- (void)syncDecoderStatus:(BOOL)isNormal;


/**
 *  Tells the parser that the decoder has decoded a frame successfully. This method
 *  has been moved from DJIVideoFeeder to DJIVideoFeed since  4.12 to support
 *  multiple channel decoding.
 *  
 *  @param timestamp The timestamp of the decoded frame.
 */
- (void)decodingDidSucceedWithTimestamp:(NSUInteger)timestamp;


/**
 *  Tells the parser that the decoder has failed to decode frames from the video
 *  feed. This method has been moved from DJIVideoFeeder to  DJIVideoFeed since 4.12
 *  to support multiple channel decoding.
 */
- (void)decodingDidFail;

@end


/**
 *  Class that manages live video feed from DJI products to the mobile device.
 */
@interface DJIVideoFeeder : NSObject

- (instancetype)init OBJC_UNAVAILABLE("You must use the singleton");

+ (instancetype)new OBJC_UNAVAILABLE("You must use the singleton");


/**
 *  The primary video feed.
 *   The possible physical sources for the primary video feed include:
 *   - `DJIVideoFeedPhysicalSourceMainCamera`
 *   -  `DJIVideoFeedPhysicalSourceLB`
 *   -  `DJIVideoFeedPhysicalSourceHDMI`
 *   -  `DJIVideoFeedPhysicalSourceLeftCamera`
 *   -  `DJIVideoFeedPhysicalSourceRightCamera`
 *   For M210 and M210 RTK, the  physical sources are controlled by the bandwidth
 *  allocation between the port (left) and starboard  (right) main cameras
 *  (`setBandwidthAllocationForLeftCamera:withCompletion`):
 *   - When bandwidth  is 100% on the left camera, the primary source is
 *  `DJIVideoFeedPhysicalSourceLeftCamera` and the secondary source is
 *  `DJIVideoFeedPhysicalSourceFPVCamera`.
 *   - When bandwidth is 0%  on the left camera, the primary source is
 *  `DJIVideoFeedPhysicalSourceRightCamera`  and the secondary source is
 *  `DJIVideoFeedPhysicalSourceFPVCamera`.
 *   - When  bandwidth is neither 0% nor 100% on the left camera, the primary source
 *  is  `DJIVideoFeedPhysicalSourceLeftCamera` and the secondary source is
 *  `DJIVideoFeedPhysicalSourceRightCamera`.
 *   For Matrice 300 RTK, the physical  source can be:
 *   `DJIVideoFeedPhysicalSourceLeftCamera`,
 *   `DJIVideoFeedPhysicalSourceRightCamera`,
 *   `DJIVideoFeedPhysicalSourceTopCamera`  and
 *   `DJIVideoFeedPhysicalSourceFPVCamera`.
 *   Please note that video playback stream will be received as primary or secondary
 *  video feed, if video playback starts on Zenmuse H20 Series.  Video feed channel
 *  could be assigned by
 *  `assignSourceToPrimaryChannel:secondaryChannel:withCompletion` in
 *  `DJIOcuSyncLink`.
 */
@property (nonatomic, strong, nonnull) DJIVideoFeed *primaryVideoFeed;


/**
 *  The secondary video feed.
 *   The possible physical sources for the secondary video feed include:
 *   - `DJIVideoFeedPhysicalSourceFPVCamera`
 *   -  `DJIVideoFeedPhysicalSourceEXT`
 *   -  `DJIVideoFeedPhysicalSourceAV`
 *   - `DJIVideoFeedPhysicalSourceRightCamera`. For M210 and M210 RTK, the physical
 *  sources are controlled by the bandwidth allocation between the port (left) and
 *  starboard (right) main cameras
 *  (`setBandwidthAllocationForLeftCamera:withCompletion`):
 *   - When bandwidth is 100% on the left camera, the primary  source is
 *  `DJIVideoFeedPhysicalSourceLeftCamera` and the secondary source is
 *  `DJIVideoFeedPhysicalSourceFPVCamera`.
 *   - When bandwidth is 0% on the left camera,  the primary source is
 *  `DJIVideoFeedPhysicalSourceRightCamera` and the secondary source is
 *  `DJIVideoFeedPhysicalSourceFPVCamera`.
 *   - When bandwidth is neither 0% nor 100% on  the left camera, the primary source
 *  is `DJIVideoFeedPhysicalSourceLeftCamera` and the  secondary source is
 *  `DJIVideoFeedPhysicalSourceRightCamera`.
 *   For Matrice 300 RTK, the  physical source can be:
 *  `DJIVideoFeedPhysicalSourceLeftCamera`, `DJIVideoFeedPhysicalSourceRightCamera`,
 *  `DJIVideoFeedPhysicalSourceTopCamera`  and
 *  `DJIVideoFeedPhysicalSourceFPVCamera`. Please note that video playback stream
 *  will be received as primary or secondary video feed,  if video playback starts
 *  on Zenmuse H20 Series. Video feed channel could be assigned by
 *  `assignSourceToPrimaryChannel:secondaryChannel:withCompletion` in
 *  `DJIOcuSyncLink`.
 */
@property (nonatomic, strong, nonnull) DJIVideoFeed *secondaryVideoFeed;


/**
 *  Add listener to receive the physical source changes.
 *  
 *  @param sourceListener Listener to add.
 */
- (void)addVideoFeedSourceListener:(id <DJIVideoFeedSourceListener>)sourceListener;


/**
 *  Remove listener to stop receiving the physical source changes.
 *  
 *  @param sourceListener Listener to remove.
 */
- (void)removeVideoFeedSourceListener:(id <DJIVideoFeedSourceListener>)sourceListener;


/**
 *  Remove all listeners.
 */
- (void)removeAllListeners;

@end

NS_ASSUME_NONNULL_END

//
//  DJIPayload.h
//  DJISDK
//
//  Copyright © 2018 DJI. All rights reserved.
//

#import <DJISDK/DJISDK.h>
#import <DJISDK/DJIPayloadWidget.h>
#import <DJISDK/DJIPayloadBaseTypes.h>

NS_ASSUME_NONNULL_BEGIN

@class DJIPayloadWidget;
@class DJIPayload;
@class DJIPipelines;


/**
 *  Delegate class to receive updated state related to Payload.
 */
@protocol DJIPayloadDelegate <NSObject>

@optional


/**
 *  Receives the command data sent from the payload device. The command data is sent
 *  from the UART/CAN channel of the payload device and the bandwidth of this
 *  channel  is 3K bytes/s on M200 series.
 *  
 *  @param payload The payload instance received the command data from the payload device.
 *  @param data The data that received by the payload instance.
 */
- (void)payload:(DJIPayload *)payload didReceiveCommandData:(NSData *)data;


/**
 *  Receives the stream data sent from the payload device. The stream data is sent
 *  from  the UDP channel of the payload device. This channel has wider bandwidth
 *  than the channel  for command data but data might get lost without re-
 *  transmission.
 *  
 *  @param payload The payload instance received the stream data from the payload device.
 *  @param data The data that received by the payload instance.
 */
- (void)payload:(DJIPayload *)payload didReceiveStreamData:(NSData *)data;


/**
 *  Receives the video data sent from the payload device. The data may be live view
 *  or playback.  Only supported by Matrice 300 RTK.
 *  
 *  @param payload The payload instance received the video data from the payload device.
 *  @param data The video data that received by the payload instance.
 */
- (void)payload:(DJIPayload *)payload didReceiveVideoData:(NSData *)data;


/**
 *  Receives a text message sent from the payload device.
 *  
 *  @param payload The payload instance received the text message from the payload device.
 *  @param message The message that received by the payload instance.
 */
- (void)payload:(DJIPayload *)payload didReceiveMessage:(NSString *)message;


/**
 *  Updates a set of payload shortcuts in main interface. if the pay load's data is
 *  invalid, an  empty array will be updated. It is only supported by DJI Skyport
 *  2.0 and DJI X-Port.
 *  
 *  @param payload The payload instance received the updated widget values.
 *  @param widgets The updated value for widgets.
 */
- (void)payload:(DJIPayload *)payload didUpdateMainInterfaceWidgets:(NSArray<DJIPayloadWidget*> *)widgets;


/**
 *  Updates setting for payload widgets. If the pay load's data is invalid, an empty
 *  array will be updated.
 *  
 *  @param payload The payload instance received the updated widget values.
 *  @param widgets The updated value for widgets.
 */
- (void)payload:(DJIPayload *)payload didUpdateConfigInterfaceWidgets:(NSArray<DJIPayloadWidget*> *)widgets;

@end


/**
 *  Class used to interact with the payload device mounted on DJI aircraft.
 */
@interface DJIPayload : DJIBaseComponent


/**
 *  Delegate to receive the update information.
 */
@property(nonatomic, weak) id<DJIPayloadDelegate> delegate;


/**
 *  The pipelines to transmit data between DJI Payload device and DJI mobile SDK.
 *  This function does not support dual controllers scenarios.  It's only supported
 *  by Matrice 300 RTK.
 */
@property (nonatomic, readonly) DJIPipelines *pipelines;


/**
 *  Gets the bandwidth of the upstream (from Mobile SDK to Payload). The unit is
 *  bytes/s.  The bandwidth is determined by the firmware and currently it is not
 *  larger than 500 bytes/s.
 *  
 *  @param upstreamBandwidth The upstream bandwidth determined by the firmware.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getUpstreamBandwidthWithCompletion:(void (^)(NSUInteger upstreamBandwidth, NSError * _Nullable error))completion;


/**
 *  Gets the product name defined by the manufacturer of the payload device.
 *  
 *  @return The product name of the payload device.
 */
- (NSString * _Nullable)getPayloadProductName;


/**
 *  Gets if function is limited. If Payload's function is limited, it may happen
 *  because:
 *   -  The payload is not functioning properly.
 *   - Skyport or X-Port is not bound.
 *   - The  encryption chip has exception.
 *   - The aircraft doesn't support this Payload model.
 *  
 *  @return `YES` if the product's function is limited.
 */
- (BOOL)isFunctionLimited;


/**
 *  Gets the product activation status.
 *  
 *  @return `YES` if the product is activated.
 */
- (BOOL)isActivated;


/**
 *  When it returns `YES`, video stream type on PSDK is set to DJI video streaming
 *  channel. Please use `DJIVideoFeed` in `DJIVideoFeeder` to receive the video
 *  data. When it returns `NO`, video stream type on PSDK is set to custom video
 *  streaming channel.  Please use `payload:didReceiveVideoData` to receive custom
 *  video data.
 *  
 *  @return `YES` if DJI video streaming channel is available.
 */
- (BOOL)isDJIVideoStreamingChannelAvailable;


/**
 *  Set the value for a widget of the payload device. Different widget types
 *  requires different  value:
 *   - for `DJIPayloadWidgetTypeInput`, the input should be an unsigned 32-bit
 *  integer
 *   - for `DJIPayloadWidgetTypeSwitch`, the input should be value  of
 *  `DJIPayloadSwitchState`
 *   - for `DJIPayloadWidgetTypeRange`, the input should  be a integer from value 0
 *  to 100
 *   - for `DJIPayloadWidgetTypeList`, the input should  be a integer not larger
 *  than list size minus one.
 *   Widget with  type `DJIPayloadWidgetTypeButton` is not configurable.
 *  
 *  @param value The value to configure.
 *  @param type Type of the widget to configure.
 *  @param index Index of the widget to configure.
 *  @param completion Completion block to receive the execution result.
 */
- (void)configureWidgetValue:(NSUInteger)value type:(DJIPayloadWidgetType)type index:(NSUInteger)index withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the switch state for the switch widget with the specific index. It has the
 *  same effect  as `configureWidgetValue:type:index:withCompletion` with
 *  `DJIPayloadWidgetTypeSwitch` as the argument.
 *  
 *  @param state Switch state to set.
 *  @param index Widget index to set.
 *  @param completion Completion block to receive the execution result.
 */
- (void)setSwitchState:(DJIPayloadSwitchState)state index:(NSUInteger)index withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the range value for the range widget with the specific index. It has the
 *  same effect as `configureWidgetValue:type:index:withCompletion`  with
 *  `DJIPayloadWidgetTypeRange` as the argument.
 *  
 *  @param rangeValue Range value to set. The valid range is [0, 100].
 *  @param index Widget index to set.
 *  @param completion Completion block to receive the execution result.
 */
- (void)setRangeValue:(NSUInteger)rangeValue index:(NSUInteger)index withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the selected item index for the list widget with the specific index. It has
 *  the same effect as `configureWidgetValue:type:index:withCompletion`  with
 *  `DJIPayloadWidgetTypeList` as the argument.
 *  
 *  @param selectedItemIndex Index of the selected item. The valid range is from 0 to list size - 1.
 *  @param index Widget index to set.
 *  @param completion Completion block to receive the execution result.
 */
- (void)setSelectedItem:(NSUInteger)selectedItemIndex index:(NSUInteger)index withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the input value for the input widget with the specific index. It has the
 *  same effect as `configureWidgetValue:type:index:withCompletion`  with
 *  `DJIPayloadWidgetTypeList` as the argument.
 *  
 *  @param inputValue Input value to set. The valid value is an unsigned 32-bit integer.
 *  @param index Widget index to set.
 *  @param completion Completion block to receive the execution result.
 */
- (void)setInputValue:(NSUInteger)inputValue index:(NSUInteger)index withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets a widget by specifying the widget type and the index.
 *  
 *  @param widgetType Widget type to get.
 *  @param widgetIndex Widget index to get.
 *  
 *  @return The widget corresponding to the widget type and the index. `nil` if the widgets are not ready or there is no widget corresponding  to the widget type and the index.
 */
- (DJIPayloadWidget * _Nullable)getWidget:(DJIPayloadWidgetType)widgetType index:(NSInteger)widgetIndex;


/**
 *  Gets the main interface widget list on the payload device. An empty array will
 *  be returned if the payload's data is regarded as invalid.
 *  
 *  @return A list of widgets. Returns nil if no widgets are fetched.
 */
- (NSArray<DJIPayloadWidget*> * _Nullable)getMainInterfaceWidgets;


/**
 *  Gets the configuration interface widget list on the payload device. An empty
 *  array will be returned if the payload's data is regarded as invalid.
 *  
 *  @return A list of widgets. Returns nil if no widgets are fetched.
 */
- (NSArray<DJIPayloadWidget*> * _Nullable)getConfigInterfaceWidgets;


/**
 *  Sends data to payload.
 *   - The length of the data to send cannot exceed 32 bytes for Matrice 200 series.
 *   - The length of the  data to send cannot exceed 128 bytes for Matrice 200 V2
 *  series. The throughput cannot exceed the bandwidth returned by
 *  `getUpstreamBandwidthWithCompletion`.
 *  
 *  @param data Data that will be sent to the payload device.
 *  @param completion Completion block to receive the execution result.
 */
- (void)sendDataToPayload:(NSData *)data withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the device type.
 *  
 *  @param deviceType An enum value of the `DJIPayloadDeviceType`.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the execution result.
 */
- (void)getDeviceTypeWithCompletion:(void (^)(DJIPayloadDeviceType deviceType, NSError *_Nullable error))completion;


/**
 *  Gets current payload product phase.
 *  
 *  @param mode An enum value of the `DJIPayloadProductPhase`.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the execution result.
 */
- (void)getProductPhaseWithCompletion:(void (^)(DJIPayloadProductPhase mode, NSError *_Nullable error))completion;


/**
 *  Called when fetching widget data is in progress.
 *  
 *  @param progress An object of `NSProgress`.
 */
typedef void (^_Nullable DJIPayloadFetchWidgetConfigurationProgressBlock)(NSProgress  * _Nullable progress);


/**
 *  Called when fetching widget data successful. An array of DJIPayloadWidget will
 *  be returned.
 */
typedef void (^_Nullable DJIPayloadFetchWidgetConfigurationSuccessBlock)();


/**
 *  Called when fetching widget data failed. Error indicating the reason will be
 *  returned.
 *  
 *  @param error Error retrieving the value.
 */
typedef void (^_Nullable DJIPayloadFetchWidgetConfigurationFailureBlock)(NSError  * _Nullable error);


/**
 *  Fetches widget configuration. Mobile SDK will fetch the configuration when it
 *  first launches.  Returns nil if initial fetching failed. It is only supported by
 *  DJI SKYPORT 2.0.
 *  
 *  @param progressBlock Updates the fetching progress.
 *  @param successBlock Called when the task finishes successfully.
 *  @param failureBlock Called when the task is interrupted by an error.
 */
- (void)fetchWidgetConfigurationWithProgress:(DJIPayloadFetchWidgetConfigurationProgressBlock)progressBlock
                                      success:(DJIPayloadFetchWidgetConfigurationSuccessBlock)successBlock
                                     failure:(DJIPayloadFetchWidgetConfigurationFailureBlock)failureBlock;


/**
 *  Set the channel priority of the payload. Priority will affect the bandwidth
 *  allocation if it is not `DJIVideoFeedPriorityUnknown`,  which is the default
 *  value. For example, if the data that comes from the payload device mounted on
 *  left gimbal is preferred, please set the priority  to
 *  `DJIVideoFeedPriorityHigh`, and physicalSource is
 *  `DJIVideoFeedPhysicalSourceLeftCamera`.  The others should be set to
 *  `DJIVideoFeedPriorityMedium` or `DJIVideoFeedPriorityLow`.  Only supported by
 *  Matrice 300 RTK.
 *  
 *  @param priority The priority to be set, see `DJIVideoFeedPriority`.
 *  @param physicalSource See `DJIVideoFeedPhysicalSource`.
 *  @param completion Completion block to receive the execution result.
 */
- (void)setPayloadChannelPriority:(DJIVideoFeedPriority)priority
                 onPhysicalSource:(DJIVideoFeedPhysicalSource)physicalSource
                   withCompletion:(DJICompletionBlock)completion;


/**
 *  Get the channel priority of the payload. Only supported by Matrice 300 RTK.
 *  
 *  @param physicalSource See `DJIVideoFeedPhysicalSource`.
 *  @param priority An enum value of `DJIVideoFeedPriority`.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the execution result.
 */
- (void)getPayloadChannelPriorityOnPhysicalSource:(DJIVideoFeedPhysicalSource)physicalSource withCompletion:(void (^)(DJIVideoFeedPriority priority, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

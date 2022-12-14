//
//  DJILens.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <DJISDK/DJIBaseComponent.h>
#import <DJISDK/DJICameraSettingsDef.h>
@class DJILens;
@class DJIMediaFile;
@class DJICamera;
@class DJICameraSystemState;
@class DJICameraStorageState;
@class DJICameraPlaybackState;
@class DJICameraFocusState;
@class DJIMediaManager;
@class DJIPlaybackManager;
@class DJICameraCapabilities;
@class UIImage;
@class DJICameraLaserMeasureInformation;

NS_ASSUME_NONNULL_BEGIN

/*********************************************************************************/
#pragma mark - DJILensDelegate
/*********************************************************************************/


/**
 *  This protocol provides delegate methods to receive the updated video data,
 *  current state and information of lens.
 */
@protocol DJILensDelegate <NSObject>

@optional


/**
 *  Called when the focus state has been updated.
 *  
 *  @param lens Instance of the lens for which focus state will be updated.
 *  @param focusState The camera's lens and focus state.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateFocusState:(DJICameraFocusState *_Nonnull)focusState;


/**
 *  Called when there are new min, max, and average temperature values available for
 *  the set spot metering area. Supported by the thermal lens of Zenmuse H20T and
 *  H20N.
 *  
 *  @param lens Instance of the Camera for which area temperature aggregations will be updated.
 *  @param temperatureAggregations The updated aggregate temperature values.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateAreaTemperatureAggregations:(DJICameraThermalAreaTemperatureAggregations)temperatureAggregations;


/**
 *  Called when updated external scene settings are available. Supported by the
 *  thermal lens of Zenmuse H20T and H20N.
 *  
 *  @param lens Instance of the Camera for which external scene settings will be updated.
 *  @param settings The updated external scene settings values.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateExternalSceneSettings:(DJICameraThermalExternalSceneSettings)settings;


/**
 *  Called whenever the lens parameters change. In automatic exposure modes
 *  (Program, Shutter Priority and Aperture Priority) the lens may be automatically
 *  changing aperture, shutter speed and ISO (depending on the mode and camera) when
 *  lighting conditions change. In Manual mode, the exposure compensation is
 *  automatically updated to let the user know how much compensation the exposure
 *  needs to get to an exposure the camera calculates as correct.
 *  
 *  @param lens Instance of the Camera for which exposure settings will be updated.
 *  @param settings The updated real values for parameters.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateExposureSettings:(DJICameraExposureSettings)settings;


/**
 *  Received temperature in degrees Celsius of image. The thermal imaging camera
 *  will only update the temperature if the temperature data is enabled. Supported
 *  by the thermal lens of Zenmuse H20T and H20N.
 *  
 *  @param lens Instance of the Camera for which temperature data will be updated.
 *  @param temperature The camera's temperature data in degrees Celsius.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateTemperatureData:(float)temperature;


/**
 *  Called when the camera's zoom state is updated. Supported by the zoom lens and
 *  the wide lens of Zenmuse H20 Series.
 *  
 *  @param lens Instance of the Camera for which tap zoom state will be updated.
 *  @param state The camera's current zoom state.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateTapZoomState:(DJICameraTapZoomState)state;


/**
 *  Called when the laser measure information updated. The laser sensor must be at
 *  least 3 meters away from the target point. Supported by the zoom lens and the
 *  wide lens of Zenmuse H20 Series.
 *  
 *  @param lens Instance of the Camera for which laser measure information will be updated.
 *  @param information The laser measure information.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateLaserMeasureInformation:(DJICameraLaserMeasureInformation *)information;


/**
 *  Called when the temperature range changes. Only Supported by the thermal lens of
 *  Zenmuse H20T and H20N.
 *  
 *  @param lens Instance of the lens for which temperature range will be updated.
 *  @param range The temperature range. The array contains min value, max value.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateGlobalTemperatureRange:(NSArray *)range;

/**
 *  Called when the infrared thermal camera status changes.
 *  Only supported by the thermal lens of Zenmuse H20T.
 *
 *  @param lens Instance of the lens for which sensor enabled status will be updated.
 *  @param isEnabled Indicates whether the infrared sensor is enabled or not.
 */
- (void)lens:(DJILens *_Nonnull)lens didUpdateInfraredSensorState:(DJICameraInfraredSensorState *)sensorState;

@end

/*********************************************************************************/
#pragma mark DJILens
/*********************************************************************************/

/**
 *  The class is used to manage all lens feature. It is only supported by Zenmuse
 *  H20 Series and Mavic 2 Enterprise Advanced.
 */
@interface DJILens : DJIBaseComponent


/**
 *  Gets the type of the current lens.
 */
@property (nonatomic, readonly) DJILensType lensType;


/**
 *  The index of the camera to which the lens belongs.
 */
@property (nonatomic, readonly) NSUInteger cameraIndex;


/**
 *  Delegate that receives the information sent by the lens.
 */
@property (nonatomic, weak) id<DJILensDelegate> delegate;


/**
 *  Gets the name of the current lens.
 */
@property (nonatomic, readonly) NSString *_Nonnull displayName;


/**
 *  Lens capabilities. Supported by Zenmuse H20 Series.
 */
@property (nonatomic, readonly) DJICameraCapabilities *capabilities;

/*********************************************************************************/
#pragma mark Video related
/*********************************************************************************/


/**
 *  Sets the lens' analog video standard. Setting the video standard to PAL or NTSC
 *  will limit the available resolutions and frame rates to those compatible with
 *  the chosen video standard.
 *  
 *  @param videoStandard Video standard value to be set for the lens.
 *  @param completion Remote execution result error block.
 */
- (void)setVideoStandard:(DJICameraVideoStandard)videoStandard withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the lens' video standard value.
 *  
 *  @param videoStandard The value of the `DJICameraVideoStandard` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Remote execution result error block.
 */
- (void)getVideoStandardWithCompletion:(void (^_Nonnull)(DJICameraVideoStandard videoStandard, NSError *_Nullable error))completion;


/**
 *  Sets the video resolution and frame rate of the current lens. @warning The
 *  supported resolutions and frame rates for the two different analog television
 *  standards PAL and NTSC are below:
 *   <b>NTSC:</b>
 *   Resolution_4096x2160, FrameRate_24fps
 *   Resolution_3840x2160, FrameRate_30fps
 *   Resolution_3840x2160, FrameRate_24fps
 *   Resolution_2704X1520, FrameRate_30fps
 *   Resolution_2704X1520, FrameRate_24fps
 *   Resolution_1920x1080, FrameRate_120fps (Slow Motion)
 *   Resolution_1920x1080, FrameRate_60fps
 *   Resolution_1920x1080, FrameRate_48fps
 *   Resolution_1920x1080, FrameRate_30fps
 *   Resolution_1920x1080, FrameRate_24fps
 *   Resolution_1280x720,  FrameRate_60fps
 *   Resolution_1280x720,  FrameRate_48fps
 *   Resolution_1280x720,  FrameRate_30fps
 *   Resolution_1280x720,  FrameRate_24fps
 *   <b>PAL:</b>
 *   Resolution_4096x2160, FrameRate_25fps
 *   Resolution_4096x2160, FrameRate_24fps
 *   Resolution_3840x2160, FrameRate_25fps
 *   Resolution_3840x2160, FrameRate_24fps
 *   Resolution_2704X1520, FrameRate_25fps
 *   Resolution_2704X1520, FrameRate_24fps
 *   Resolution_1920x1080, FrameRate_120fps (Slow Motion)
 *   Resolution_1920x1080, FrameRate_50fps
 *   Resolution_1920x1080, FrameRate_48fps
 *   Resolution_1920x1080, FrameRate_25fps
 *   Resolution_1920x1080, FrameRate_24fps
 *   Resolution_1280x720, FrameRate_50fps
 *   Resolution_1280x720, FrameRate_48fps
 *   Resolution_1280x720, FrameRate_25fps
 *   Resolution_1280x720, FrameRate_24fps
 *  
 *  @param resolutionAndFrameRate Resolution to be set for the video.
 *  @param completion Remote execution result error block.
 */
- (void)setVideoResolutionAndFrameRate:(DJICameraVideoResolutionAndFrameRate *)resolutionAndFrameRate
                        withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the video resolution and frame rate values of the current lens.
 *  
 *  @param resolutionAndFrameRate The value of the `DJICameraVideoResolutionAndFrameRate` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getVideoResolutionAndFrameRateWithCompletion:(void (^_Nonnull)(DJICameraVideoResolutionAndFrameRate *_Nullable resolutionAndFrameRate,
                                                                       NSError *_Nullable error))completion;


/**
 *  Sets the video file format of the current lens. The default value is
 *  `DJICameraVideoFileFormatMOV`.
 *  
 *  @param format Video file format to be set for videos.
 *  @param completion Remote execution result error block.
 */
- (void)setVideoFileFormat:(DJICameraVideoFileFormat)format withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the video file format of the current lens.
 *  
 *  @param format The value of the `DJICameraVideoFileFormat` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to return the current video file format.
 */
- (void)getVideoFileFormatWithCompletion:(void (^_Nonnull)(DJICameraVideoFileFormat format, NSError *_Nullable error))completion;

/*********************************************************************************/
#pragma mark Photo related
/*********************************************************************************/


/**
 *  Sets the aspect ratio for photos of the current lens. See
 *  `DJICameraPhotoAspectRatio` to view all possible ratios.
 *  
 *  @param aspectRatio Aspect ratio for photos to be taken by camera.
 *  @param completion Remote execution result error block.
 */
- (void)setPhotoAspectRatio:(DJICameraPhotoAspectRatio)aspectRatio withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the aspect ratio for photos of the current lens.
 *  
 *  @param aspectRatio The value of the `DJICameraPhotoAspectRatio` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Remote execution result callback block.
 */
- (void)getPhotoAspectRatioWithCompletion:(void (^_Nonnull)(DJICameraPhotoAspectRatio aspectRatio, NSError *_Nullable error))completion;


/**
 *  Sets the photo file format of the current lens. See `DJICameraPhotoFileFormat`
 *  to view all possible photo formats to which the lens can be set. Not supported
 *  by Zenmuse H20 Series.
 *  
 *  @param format Photo file format used when the camera takes a photo.
 *  @param completion Completion block.
 */
- (void)setPhotoFileFormat:(DJICameraPhotoFileFormat)format withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the photo file format of the current lens.
 *  
 *  @param format The value of the `DJICameraPhotoFileFormat` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getPhotoFileFormatWithCompletion:(void (^_Nonnull)(DJICameraPhotoFileFormat format, NSError *_Nullable error))completion;

/*********************************************************************************/
#pragma mark Exposure Settings
/*********************************************************************************/


/**
 *  Sets the exposure mode of the current lens. Check `DJICameraExposureMode` to
 *  view all possible camera exposure modes. Please note that in different exposure
 *  mode, it will have different values for the same setting.
 *  
 *  @param mode Camera exposure mode to set.
 *  @param completion Remote execution result error block.
 */
- (void)setExposureMode:(DJICameraExposureMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the exposure mode of the current lens.
 *  
 *  @param mode The value of the `DJICameraExposureMode` of the Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getExposureModeWithCompletion:(void (^_Nonnull)(DJICameraExposureMode mode, NSError *_Nullable error))completion;


/**
 *  Sets the ISO value of the current lens. See `DJICameraISO` to view all possible
 *  ISO settings for the lens.
 *  
 *  @param iso ISO value to be set.
 *  @param completion Completion block.
 */
- (void)setISO:(DJICameraISO)iso withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the ISO value of the current lens.
 *  
 *  @param iso The value of the `DJICameraISO` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getISOWithCompletion:(void (^_Nonnull)(DJICameraISO iso, NSError *_Nullable error))completion;


/**
 *  Sets the shutter speed of the current lens. To see all available "shutterSpeed"
 *  value settings, see `DJICameraShutterSpeed`. The shutter speed should not be set
 *  slower than the video frame rate when the camera's mode is
 *  `DJICameraModeRecordVideo`. For example, if the video frame rate is 30fps, the
 *  `shutterSpeed` must be <= 1/30. Precondition: The shutter speed can be set only
 *  when the lens exposure mode is Shutter mode or Manual mode.
 *  
 *  @param shutterSpeed Shutter speed value to be set for the lens. For all available values shutterSpeed can be set to, please check `DJICameraShutterSpeed`. <br> The shutter speed should not be set slower than the video frame rate when the camera's mode is `DJICameraModeRecordVideo`. For example, if the video frame rate = 30fps, then the shutterSpeed must be <= 1/30.
 *  @param completion Remote execution result error block.
 */
- (void)setShutterSpeed:(DJICameraShutterSpeed)shutterSpeed withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the shutter speed of the current lens.
 *  
 *  @param shutterSpeed The value of the `DJICameraShutterSpeed` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getShutterSpeedWithCompletion:(void (^_Nonnull)(DJICameraShutterSpeed shutterSpeed, NSError *_Nullable error))completion;


/**
 *  Determine if the current lens supports Metering.
 *  
 *  @return A boolean value.
 */
- (BOOL)isMeteringSupported;


/**
 *  Sets the exposure metering of the current lens. See `DJICameraMeteringMode` to
 *  view all possible exposure metering settings for the lens.
 *  
 *  @param mode Exposure metering to be set. Check the enum `DJICameraMeteringMode` to find all possible exposure metering the camera can be set to.
 *  @param completion Completion block.
 */
- (void)setMeteringMode:(DJICameraMeteringMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the exposure metering of the current lens.
 *  
 *  @param mode The value of the `DJICameraMeteringMode` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getMeteringModeWithCompletion:(void (^_Nonnull)(DJICameraMeteringMode mode, NSError *_Nullable error))completion;


/**
 *  Sets the spot metering area index of the current lens. The lens image is divided
 *  into 225 spots defined by 15 columns and 15 rows. The row index range is [0,14],
 *  where the values increase top to bottom across the image. The column index range
 *  is [0, 14], where the values increase left to right. In order to make the method
 *  work, The camera exposure mode should be `Program`, `Shutter` or `Aperture`, the
 *  exposure metering mode must be `DJICameraMeteringModeSpot`, and
 *  `setAELock:withCompletion` must be `NO`.
 *  
 *  @param rowIndex Spot metering row index to be set. The value should falls in [0, 14], where the values increase top to bottom across the image.
 *  @param columnIndex Spot metering column index to be set. The value should falls in [0, 14], where the values increase left to right.
 *  @param completion Remote execution result error block.
 */
- (void)setSpotMeteringTargetRowIndex:(uint8_t)rowIndex columnIndex:(uint8_t)columnIndex withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the spot metering area row index and column index of the current lens. In
 *  order to make the method work, The lens exposure mode should be
 *  `DJICameraExposureModeProgram`, `DJICameraExposureModeShutterPriority` or
 *  `DJICameraExposureModeAperturePriority`, the exposure metering mode must be
 *  `DJICameraMeteringModeSpot`, and `getAELockWithCompletion` must be `NO`.
 *  
 *  @param rowIndex The rowIndex value.
 *  @param columnIndex The colIndex value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getSpotMeteringTargetWithCompletion:(void (^_Nonnull)(uint8_t rowIndex, uint8_t columnIndex, NSError *_Nullable error))completion;


/**
 *  Sets the exposure compensation of the current lens. See
 *  `DJICameraExposureCompensation` to view all possible exposure compensations to
 *  which the camera can be set. In order to use this function, set the lens
 *  exposure mode to `shutter`, `program` or `aperture`.
 *  
 *  @param compensation Exposure compensation value to be set for the camera.
 *  @param completion Completion block.
 */
- (void)setExposureCompensation:(DJICameraExposureCompensation)compensation withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the exposure compensation of the current lens.
 *  
 *  @param compensation The value of the `DJICameraExposureCompensation` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getExposureCompensationWithCompletion:(void (^_Nonnull)(DJICameraExposureCompensation compensation, NSError *_Nullable error))completion;


/**
 *  Locks or unlocks the lens' AE (auto exposure). Post condition: If the AE lock is
 *  enabled, the spot metering area cannot be set.
 *  
 *  @param isLocked `YES` if the camera AE is locked, `NO` if it is unlocked.
 *  @param completion The execution callback with the returned execution result.
 */
- (void)setAELock:(BOOL)isLocked withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines if the lens' AE (auto exposure) is locked.
 *  
 *  @param isLocked The isLocked value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getAELockWithCompletion:(void (^_Nonnull)(BOOL isLocked, NSError *_Nullable error))completion;


/**
 *  Enables/disables auto-unlocking of AE lock after shooting a photo. If it is
 *  enabled, the Auto Exposure will unlock after each shot. If disabled, Auto
 *  Exposure will change when calling `setAELock:withCompletion`.
 *  
 *  @param enabled `YES` if the camera AE will automatically unlock.
 *  @param completion Completion block that receives the setter result.
 */
- (void)setAutoAEUnlockEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether auto-unlocking of AE lock is enabled.
 *  
 *  @param enabled The enabled value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getAutoAEUnlockEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;

/*********************************************************************************/
#pragma mark White Balance
/*********************************************************************************/


/**
 *  Sets the white balance of the current lens. When the white balance is a preset
 *  value (values except `DJICameraWhiteBalancePresetCustom`), the
 *  `colorTemperature` argument does not take effect. When the white balance is
 *  `DJICameraWhiteBalancePresetCustom`, the `colorTemperature` value is used
 *  instead. See Also: `DJICameraWhiteBalancePreset` to view all possible white
 *  balance setting options for the camera.
 *  
 *  @param whiteBalance White balance value to be set.
 *  @param completion Completion block.
 */
- (void)setWhiteBalance:(DJICameraWhiteBalance *)whiteBalance withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the white balance and color temperature of the current lens.
 *  
 *  @param whiteBalance The `DJICameraWhiteBalance` object.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getWhiteBalanceWithCompletion:(void (^_Nonnull)(DJICameraWhiteBalance *_Nullable whiteBalance, NSError *_Nullable error))completion;

/*********************************************************************************/
#pragma mark Other settings
/*********************************************************************************/


/**
 *  Sets the sharpness of the current lens. The default value is 0.
 *  
 *  @param sharpness Sharpness value to be set in the range of [-3, 3].
 *  @param completion Asynchronous execution result.
 */
- (void)setSharpness:(int8_t)sharpness withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the sharpness of the current lens.
 *  
 *  @param sharpness The value of the sharpness with range [-3, 3].
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getSharpnessWithCompletion:(void (^_Nonnull)(int8_t sharpness, NSError *_Nullable error))completion;


/**
 *  Sets the contrast of the current lens. The default saturation value is 0.
 *  
 *  @param contrast Contrast value to be set in the range of [-3, 3].
 *  @param completion Completion block.
 */
- (void)setContrast:(int8_t)contrast withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the contrast of the current lens.
 *  
 *  @param contrast The value of the contrast with range [-3, 3].
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getContrastWithCompletion:(void (^_Nonnull)(int8_t contrast, NSError *_Nullable error))completion;


/**
 *  Sets the saturation of the current lens. The default saturation value is 0.
 *  
 *  @param saturation Saturation value to be set in the range of [-3, 3]. The default value of the saturation value is 0.
 *  @param completion Remote execution result error block.
 */
- (void)setSaturation:(int8_t)saturation withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the saturation of the current lens.
 *  
 *  @param saturation The saturation value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getSaturationWithCompletion:(void (^_Nonnull)(int8_t saturation, NSError *_Nullable error))completion;


/**
 *  Sets the color of the current lens. The default value is `DJICameraColorNone`.
 *  For a list of all possible camera colors, see `DJICameraColor`.
 *  
 *  @param color Camera color to be applied to the camera.
 *  @param completion Remote execution result error block.
 */
- (void)setColor:(DJICameraColor)color withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the color of the current lens.
 *  
 *  @param color Camera color to be applied to the camera.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getColorWithCompletion:(void (^_Nonnull)(DJICameraColor color, NSError *_Nullable error))completion;


/**
 *  Enables/disables the IR filter (infared filter). Disabling the IR filter can
 *  enhance the image in low light environments. Enabling the IR filter can reduce
 *  the color distortion caused by the infared light. Supported by the zoom lens of
 *  Zenmuse H20 Series.
 *  
 *  @param enabled `YES` to enable IR-Cut filter.
 *  @param completion Completion block that receives the setter result.
 */
- (void)setIRFilterEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether IR filter (infared filter) is enabled. Disabling the IR
 *  filter can enhance the image in low light environments. Enabling the IR filter
 *  can reduce the color distortion caused by the infared light. Supported by the
 *  zoom lens of Zenmuse H20 Series.
 *  
 *  @param enabled `YES` if IR-Cut filter is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getIRFilterEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;

/*********************************************************************************/
#pragma mark Digital Zoom
/*********************************************************************************/


/**
 *  Determine if the current device supports digital zoom scale. Not supported by
 *  Zenmuse H20 Series.
 *  
 *  @return A boolean value.
 */
- (BOOL)isDigitalZoomSupported;


/**
 *  Sets the digital zoom factor of the current lens. Not supported by Zenmuse H20
 *  Series.
 *  
 *  @param factor The valid range is from 1.0 to 2.0.
 *  @param completion The completion block with the returned execution result.
 */
- (void)setDigitalZoomFactor:(float)factor withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets current digital zoom factor of the current lens.  Not supported by Zenmuse
 *  H20 Series.
 *  
 *  @param factor The scale value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getDigitalZoomFactorWithCompletion:(void (^_Nonnull)(float factor, NSError *_Nullable error))completion;

/*********************************************************************************/
#pragma mark Optical Zoom
/*********************************************************************************/


/**
 *  Determine if the current lens supports optical zoom. Not supported by Zenmuse
 *  H20 Series.
 *  
 *  @return `YES` if lens supports optical zoom.
 */
-(BOOL)isOpticalZoomSupported;


/**
 *  Gets the specification of the current lens. Not supported by Zenmuse H20 Series.
 *  
 *  @param spec The value of the `DJICameraOpticalZoomSpec` Struct.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
-(void)getOpticalZoomSpecWithCompletion:(void(^_Nonnull)(DJICameraOpticalZoomSpec spec, NSError *_Nullable error))completion;


/**
 *  Sets focal length of the current lens. Not supported by Zenmuse H20 Series.
 *  
 *  @param focalLength Focal length of zoom lens. Valid range is [`minFocalLength`, `maxFocalLength`] and must be a multiple of `focalLengthStep`.
 *  @param completion The completion block with the returned execution result.
 */
-(void)setOpticalZoomFocalLength:(NSUInteger)focalLength withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the optical zoom focal length of the current lens in units of 0.1mm. Not
 *  supported by Zenmuse H20 Series.
 *  
 *  @param focalLength The focalLength value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
-(void)getOpticalZoomFocalLengthWithCompletion:(void (^_Nonnull)(NSUInteger focalLength, NSError *_Nullable error))completion;


/**
 *  Gets current optical zoom factor with range [1, 30]. Not supported by Zenmuse
 *  H20 Series.
 *  
 *  @param factor The zoom factor value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
-(void)getOpticalZoomFactorWithCompletion:(void (^_Nonnull)(float factor, NSError *_Nullable error))completion;


/**
 *  Start changing the focal length of the lens in specified direction with
 *  specified speed. Focal length change (zooming) will halt when maximum or minimum
 *  focal lengths are reached, or `stopContinuousOpticalZoomWithCompletion` is
 *  called. Supported by the zoom lens of Zenmuse H20 Series and Mavic 2 Enterprise
 *  Advanced.
 *  
 *  @param direction Direction to zoom.
 *  @param speed Zoom speed.
 *  @param completion The execution callback with the returned execution result.
 */
-(void)startContinuousOpticalZoomInDirection:(DJICameraZoomDirection)direction
                                   withSpeed:(DJICameraZoomSpeed)speed
                              withCompletion:(DJICompletionBlock)completion;


/**
 *  Called to stop focal length changing, when it currently is from calling
 *  `startContinuousOpticalZoomInDirection:withSpeed:withCompletion`. Supported by
 *  the zoom lens of Zenmuse H20 Series and Mavic 2 Enterprise Advanced.
 *  
 *  @param completion The execution callback with the returned execution result.
 */
-(void)stopContinuousOpticalZoomWithCompletion:(DJICompletionBlock)completion;

/*********************************************************************************/
#pragma mark - Hybrid Zoom
/*********************************************************************************/


/**
 *  Hybrid zoom is combining optical and digital zoom. Lens will automatically
 *  switch over to digital zoom when optical zoom range is exceeded. Check if lens
 *  supports hybrid zoom. Supported by the zoom lens of Zenmuse H20 Series.
 *  
 *  @return `YES` if camera supports hybrid zoom.
 */
-(BOOL)isHybridZoomSupported;


/**
 *  Hybrid zoom is combining optical and digital zoom. Lens will automatically
 *  switch over to digital zoom when optical zoom range is exceeded. Gets the
 *  specification of the zoom lens. Supported by the zoom lens of Zenmuse H20
 *  Series.
 *  
 *  @param spec The value of the `DJICameraHybridZoomSpec` Struct.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
-(void)getHybridZoomSpecWithCompletion:(void(^_Nonnull)(DJICameraHybridZoomSpec spec, NSError *_Nullable error))completion;


/**
 *  Hybrid zoom is combining optical and digital zoom. Lens will automatically
 *  switch over to digital zoom when optical zoom range is exceeded. Sets focal
 *  length of the zoom lens. Supported by the zoom lens of Zenmuse H20 Series.
 *  
 *  @param focalLength Focal length of zoom lens. Valid range is [`minHybridFocalLength`, `maxHybridFocalLength`] and must be a multiple of `focalLengthStep`.
 *  @param completion The completion block with the returned execution result.
 */
-(void)setHybridZoomFocalLength:(NSUInteger)focalLength withCompletion:(DJICompletionBlock)completion;


/**
 *  Hybrid zoom is combining optical and digital zoom. Lens will automatically
 *  switch over to digital zoom when optical zoom range is exceeded.  Gets zoom lens
 *  focal length in units of 0.1mm. Supported by the zoom lens of Zenmuse H20
 *  Series.
 *  
 *  @param focalLength Focal length of zoom lens.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
-(void)getHybridZoomFocalLengthWithCompletion:(void(^_Nonnull)(NSUInteger focalLength, NSError *_Nullable error))completion;

/*********************************************************************************/
#pragma mark - TapZoom
/*********************************************************************************/


/**
 *  Determines if the current lens supports TapZoom feature.
 *  
 *  @return `YES` if camera supports tap zoom.
 */
-(BOOL)isTapZoomSupported;


/**
 *  Enable/disable TapZoom. `tapZoomAtTarget:withCompletion` can only be called when
 *  TapZoom is enabled. Supported by Mavic 2 Enterprise Advanced, the zoom lens and
 *  the wide lens of Zenmuse H20 Series.
 *  
 *  @param enabled `YES` to enable TapZoom feature.
 *  @param completion Completion block that receives the setter result.
 */
-(void)setTapZoomEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines if TapZoom is enabled.
 *  
 *  @param enabled The enabled value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
-(void)getTapZoomEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  TapZoom uses a multiplier to change the zoom scale when called. The final zoom
 *  scale for a TapZoom will be: Current Zoom Scale x Multiplier. The multiplier
 *  range is [1,5]. A multiplier of 1 will not change the zoom. When the multiplier
 *  is 1, the zoom scale will not change during TapZoom. Supported by the zoom lens
 *  and the wide lens of Zenmuse H20 Series. The tap zoom multiplier of Zenmuse H20
 *  Series must be 1.
 *  
 *  @param multiplier Multiplier of TapZoom.
 *  @param completion Completion block that receives the setter result.
 */
-(void)setTapZoomMultiplier:(uint8_t)multiplier withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the multiplier for TapZoom. Supported by the zoom lens and the wide lens of
 *  Zenmuse H20 Series. The tap zoom multiplier of Zenmuse H20 Series must be 1.
 *  
 *  @param step The step value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block that receives the setter result.
 */
-(void)getTapZoomMultiplierWithCompletion:(void (^_Nonnull)(uint8_t step, NSError *_Nullable error))completion;


/**
 *  TapZoom at the target. It can be called only when TapZoom is enabled.  When a
 *  new target is set, the gimbal will rotate and locate the target in the center of
 *  the screen. At the same time, the camera will zoom by multiplying the TapZoom
 *  multiplier. Supported by Mavic 2 Enterprise Advanced, the zoom lens and the wide
 *  lens of Zenmuse H20 Series. It will only work when the tap zoom multiplier of
 *  Zenmuse H20 Series is 1.
 *  
 *  @param target The target to zoom. The range for x and y is from 0.0 to 1.0. The point [0.0, 0.0] represents the top-left corner of the screen.
 *  @param completion Completion block that receives the execution result.
 */
-(void)tapZoomAtTarget:(CGPoint)target withCompletion:(DJICompletionBlock)completion;

/*********************************************************************************/
#pragma mark Advanced Camera Settings
/*********************************************************************************/


/**
 *  Gets whether the lens supports an adjustable aperture. Currently adjustable
 *  aperture is supported only by the zoom lens of Zenmuse H20 Series.
 *  
 *  @return A boolean value.
 */
- (BOOL)isAdjustableApertureSupported;


/**
 *  Sets the aperture value of the current lens. This feature is available only when
 *  `isAdjustableApertureSupported` returns `YES`. Precondition: The exposure mode
 *  `DJICameraExposureMode` must be in `DJICameraExposureModeManual` or
 *  `DJICameraExposureModeAperturePriority`. </br> Supported only by the zoom lens
 *  of Zenmuse H20 Series and Mavic 2 Enterprise Advanced.
 *  
 *  @param aperture The aperture to set. See `DJICameraFocusMode`.
 *  @param completion The execution callback with the returned execution result.
 */
- (void)setAperture:(DJICameraAperture)aperture withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the aperture of the current lens. This feature is available only when
 *  `isAdjustableApertureSupported` returns `YES`.
 *  
 *  @param aperture The value of the `DJICameraAperture` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getApertureWithCompletion:(void (^_Nonnull)(DJICameraAperture aperture, NSError *_Nullable error))completion;


/**
 *  Determines whether the lens supports an adjustable focal point. Currently, the
 *  adjustable focal point is supported by the zoom lens of Zenmuse H20 Series.
 *  
 *  @return A boolean value.
 */
- (BOOL)isAdjustableFocalPointSupported;


/**
 *  Sets the focus mode of the current lens. See `DJICameraFocusMode`. It is
 *  available only when `isAdjustableFocalPointSupported` returns `YES`. Supported
 *  by the zoom lens of Zenmuse H20 Series. Not supported by Mavic 2 Enterprise
 *  Advanced.
 *  
 *  @param focusMode Focus mode to set. Check `DJICameraFocusMode` for more detail.
 *  @param completion The execution block with the returned execution result.
 */
- (void)setFocusMode:(DJICameraFocusMode)focusMode withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the focus mode of the current lens. Please check `DJICameraFocusMode`. It
 *  is available only when `isAdjustableFocalPointSupported` returns `YES`.
 *  Supported by the zoom lens of Zenmuse H20 Series. Not supported by Mavic 2
 *  Enterprise Advanced.
 *  
 *  @param focusMode The value of the `DJICameraFocusMode` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getFocusModeWithCompletion:(void (^_Nonnull)(DJICameraFocusMode focusMode, NSError *_Nullable error))completion;


/**
 *  Sets the lens focus target point. When the focus mode is auto, the target point
 *  is the focal point. When the focus mode is manual, the target point is the zoom
 *  out area if the focus assistant is enabled for the manual mode. It is available
 *  only when `isAdjustableFocalPointSupported` returns `YES`. Supported by the zoom
 *  lens of Zenmuse H20 Series. Not supported by Mavic 2 Enterprise Advanced.
 *  
 *  @param focusTarget The focus target to set. The range for x and y is from 0.0 to 1.0. The point [0.0, 0.0] represents the top-left angle of the screen.
 *  @param completion The execution callback with the returned execution result.
 */
- (void)setFocusTarget:(CGPoint)focusTarget withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the lens focus target point. It is available only when
 *  `isAdjustableFocalPointSupported` returns `YES`. Supported by the zoom lens of
 *  Zenmuse H20 Series. Not supported by Mavic 2 Enterprise Advanced.
 *  
 *  @param focusTarget The CGPoint struct.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getFocusTargetWithCompletion:(void (^_Nonnull)(CGPoint focusTarget, NSError *_Nullable error))completion;


/**
 *  Used to enable/disable the lens focus assistant. When the focus assistant is
 *  enabled, the camera live view will digitally zoom into the focus target area so
 *  the user can see the quality of focus. Focus assistant can be used for both
 *  manual focus (MF) and auto focus (AF). It is available only when
 *  `isAdjustableFocalPointSupported` returns `YES`. Not supported by Mavic 2
 *  Enterprise Advanced.
 *  
 *  @param settings Sets whether the lens focus assistant for AF and MF mode is enabled.
 *  @param completion The execution callback with the returned execution result.
 */
- (void)setFocusAssistantSettings:(DJICameraFocusAssistantSettings)settings
                   withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether the lens focus assistant is enabled. When the focus assistant
 *  is enabled, the camera live view will digitally zoom into the focus target area
 *  so the user can see the quality of focus. Focus assistant can be used for both
 *  manual focus (MF) and auto focus (AF). It is available only when
 *  `isAdjustableFocalPointSupported` returns `YES`. Supported by the zoom lens of
 *  Zenmuse H20 Series. Not supported by Mavic 2 Enterprise Advanced.
 *  
 *  @param settings Sets whether the lens focus assistant under AF and MF mode is enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getFocusAssistantSettingsWithCompletion:(void (^_Nonnull)(DJICameraFocusAssistantSettings settings,
                                                                  NSError *_Nullable error))completion;


/**
 *  Gets the lens focusing ring value's max value. It is available only when
 *  `isAdjustableFocalPointSupported` returns `YES`. Supported by the zoom lens of
 *  Zenmuse H20 Series. Not supported by Mavic 2 Enterprise Advanced.
 *  
 *  @param upperBound The upperBound value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getFocusRingValueUpperBoundWithCompletion:(void (^_Nonnull)(NSUInteger upperBound, NSError *_Nullable error))completion;


/**
 *  Set the focal distance by simulating the focus ring adjustment. Value can have a
 *  range of 0, `getFocusRingValueUpperBoundWithCompletion`], which represents
 *  infinity and the closest possible focal distance. It is available only when
 *  `isAdjustableFocalPointSupported` returns `YES`. For some lenses, the minimum
 *  focus ring value is larger than 0. For example the minimum of DJI MFT 15mm f/1.7
 *  ASPH is 270. To retrieve the minimum value, perform the following steps: - Call
 *  `setFocusMode:withCompletion` with `DJICameraFocusModeAuto`. - Call
 *  `setFocusTarget:withCompletion` with the furthest target (>30m). - Call
 *  `getFocusRingValueWithCompletion` to get the current focus ring value. This is
 *  the minimum value. The maximum value can be retrieved using
 *  `getFocusRingValueUpperBoundWithCompletion`. Supported by the zoom lens of
 *  Zenmuse H20 Series. Not supported by Mavic 2 Enterprise Advanced.
 *  
 *  @param value Value to adjust focus ring to. The minimum value is 0, the maximum value depends on the installed lens. Please use method `getFocusRingValueUpperBoundWithCompletion` to ensure the input argument is valid.
 *  @param completion Completion block to receive the result.
 */
- (void)setFocusRingValue:(NSUInteger)value withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the lens focus ring value. It is available only when
 *  `isAdjustableFocalPointSupported` returns `YES`. Supported by the zoom lens of
 *  Zenmuse H20 Series. Not supported by Mavic 2 Enterprise Advanced.
 *  
 *  @param distance The distance value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getFocusRingValueWithCompletion:(void (^_Nonnull)(NSUInteger distance, NSError *_Nullable error))completion;

/*********************************************************************************/
#pragma mark Mechanical Shutter Speed
/*********************************************************************************/

/**
 *  Determines whether the mechanical shutter speed is supported by the camera or
 *  the lens.
 *  
 *  @return `YES` if the mechanical shutter is supported, otherwise `NO`.
 */
- (BOOL)isMechanicalShutterSupported;


/**
 *  Enables the mechanical shutter. It is only valid when
 *  `isMechanicalShutterSupported` returns `YES`.
 *  
 *  @param enabled `YES` to enable the mechanical shutter.
 *  @param completion Completion block to receive the result.
 */
- (void)setMechanicalShutterEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether the mechanical shutter is enabled. It is only valid when
 *  `isMechanicalShutterSupported` returns `YES`.
 *  
 *  @param enabled `YES` if the mechanical shutter is enabled.
 *  @param error Error if there is any.
 *  @param completion Completion block to receive the getter result.
 */
- (void)getMechanicalShutterEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;

@end

/*********************************************************************************/
#pragma mark - Thermal Imaging Camera
/*********************************************************************************/

@interface DJILens (ThermalCamera)


/**
 *  Return `YES` if the current connected device is a thermal imaging lens.
 *  
 *  @return A boolean value.
 */
- (BOOL)isThermalLens;


/**
 *  `YES` if the infrared sensor in camera is enabled.
 *  
 *  @return A boolean value.
 */
- (BOOL)isInfraredThermalCameraShutterEnabled;


/**
 *  `YES` if the infrared sensor protection is enabled.
 *  
 *  @return A boolean value.
 */
- (BOOL)isInfraredSensorBurningProtectionEnabled;


/**
 *  Sets the region of interest (ROI). Used to manage color range distribution
 *  across the screen to maximize contrast for regions of highest interest.
 *  Supported by the thermal lens of Zenmuse H20T and H20N.
 *  
 *  @param roi An enum type of the Region of Interest to be used. Please refer to `DJICameraThermalROI`.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalROI:(DJICameraThermalROI)roi withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the region of interest.
 *  
 *  @param roi The value of the `DJICameraThermalROI` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalROIWithCompletion:(void (^_Nonnull)(DJICameraThermalROI roi, NSError *_Nullable error))completion;


/**
 *  Sets the palette. Each palette is a unique look-up table that maps 8-bit
 *  temperature values to different colors. Different palettes can be used to help
 *  the user better visualize temperature contrast or specific temperature bands.
 *  The valid range can be fetched from `DJISupportedCameraThermalPaletteRange`.
 *  
 *  @param palette An enum type of the `DJICameraThermalPalette` to be used.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalPalette:(DJICameraThermalPalette)palette withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the palette. Supported by the thermal lens of Zenmuse H20T and H20N.
 *  
 *  @param palette The value of the `DJICameraThermalPalette` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalPaletteWithCompletion:(void (^_Nonnull)(DJICameraThermalPalette palette, NSError *_Nullable error))completion;


/**
 *  Sets the scene to instantly enhance your image. In all modes except Manual and
 *  User modes, the DDE, ACE, SSO, brightness and contrast are set automatically to
 *  obtain the best result. In User modes, the contrast and brightness are set
 *  automatically to obtain the best results. Any settings that are made in these
 *  modes are retained if the scene is changed. In Manual mode, DDE, contrast and
 *  brightness are set manually.
 *  
 *  @param scene An enum type for the `DJICameraThermalScene` to be used.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalScene:(DJICameraThermalScene)scene withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets current scene.
 *  
 *  @param scene The value of the `DJICameraThermalScene` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalSceneWithCompletion:(void (^_Nonnull)(DJICameraThermalScene scene, NSError *_Nullable error))completion;


/**
 *  Sets the Digital Data Enhancement index (for DDE dynamic mode). DDE can be used
 *  to enhance image details (sharpen, higher index) and/or suppress fixed pattern
 *  noise (soften, lower index). It can be set manually only when the Scene mode is
 *  Manual, User1, User2 or User3.
 *  
 *  @param value Integer in range [-20, 100]. Values less than 0 soften the image and filter fixed pattern noise. Values greater than 0 sharpen the details in the image. Value of 0 results in no enhancement.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalDDE:(NSInteger)value withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the value of Digital Data Enhancement. The value is available only when the
 *  Scene mode is Manual, User1, User2 or User3.
 *  
 *  @param value The value of Digital Data Enhancement.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalDDEWithCompletion:(void (^_Nonnull)(NSInteger value, NSError *_Nullable error))completion;


/**
 *  Set the value of Active Contrast Enhancement. Active contrast enhancement allows
 *  for a contrast trade-off between hotter and colder scenes when using 8-bit pixel
 *  data. It can be set manually only when the Scene mode is User1, User2 or User3.
 *  Not supported by Zenmuse H20T and H20N.
 *  
 *  @param value Integer in range [-8, 8]. <br> value > 0: more contrast in hotter scene content and less contrast in colder scene content (sky, ocean etc.). <br> value < 0: more contrast in colder scene content and less contrast in hotter scene content. <br> value = 0: neutral <br> value = 3: recommended for generic use.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalACE:(NSInteger)value withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the value of Active Contrast Enhancement. The value is available only when
 *  the Scene mode is Manual, User1, User2 or User3. Not supported by Zenmuse H20T
 *  and H20N.
 *  
 *  @param value The value of Active Contrast Enhancement.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalACEWithCompletion:(void (^_Nonnull)(NSInteger value, NSError *_Nullable error))completion;


/**
 *  Sets the value of Smart Scene Optimization. When using non-linear histogram
 *  equalization to map the 14-bit sensor pixel values to 8-bit pixel values, it can
 *  become difficult to determine the difference in temperature of two objects from
 *  their different shades of gray. SSO allows a percentage of the 14-bit histogram
 *  to be mapped linearly to the 8-bit histogram, which will compromise local
 *  contrast, but allow for more accurate visual radiometric measurements. This is
 *  particularly useful for bi-modal scenes. It can be set manually only when the
 *  Scene mode is User1, User2 or User3. Not supported by Zenmuse H20T and H20N.
 *  
 *  @param value Percentage of histogram to map linearly [0, 100].
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalSSO:(NSInteger)value withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the value of Smart Scene Optimization. The value is available only when the
 *  Scene mode is Manual, User1, User2 or User3. Not supported by Zenmuse H20T and
 *  H20N.
 *  
 *  @param value The value of Smart Scene Optimization.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalSSOWithCompletion:(void (^_Nonnull)(NSInteger value, NSError *_Nullable error))completion;


/**
 *  Sets the brightness of the image. It can be set manually only when the Scene
 *  mode is Manual.
 *  
 *  @param brightness The integer value falls in [0, 16383].
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalBrightness:(NSUInteger)brightness withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the value of brightness. The value is available only when the Scene mode is
 *  Manual, User1, User2 or User3.
 *  
 *  @param brightness The value of brightness.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalBrightnessWithCompletion:(void (^_Nonnull)(NSUInteger brightness, NSError *_Nullable error))completion;


/**
 *  Sets the value of contrast, with larger values having higher contrast. It can be
 *  set manually only when the Scene mode is Manual.
 *  
 *  @param contrast Contrast value as an integer with range [0, 255].
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalContrast:(NSUInteger)contrast withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets contrast value. The value is available only when the Scene mode is Manual,
 *  User1, User2 or User3.
 *  
 *  @param Contrast The contrast value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalContrastWithCompletion:(void (^_Nonnull)(NSUInteger Contrast, NSError *_Nullable error))completion;


/**
 *  Enable or disable Isotherms. Isotherms can be used to highlight specific
 *  temperature ranges: When disabled, all 256 values (8-bits) are dedicated to the
 *  temperature histogram of the scene. When enabled, only 128 values (0-127) are
 *  mapped linearly to temperature. Then three bands 128-175, 176-223 and 224-255
 *  can be mapped to the user defined temperatures to highlight them to the user.
 *  Using some of the false color palettes (like RainbowIso) results in a thermal
 *  image that is grey scale except for three specific bands highlighted by either
 *  reds, blues or greens. Not supported by Mavic 2 Enterprise Advanced.
 *  
 *  @param enabled `YES` if isotherms are enabled.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalIsothermEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Determines whether Isotherms are enabled. `YES` if Isotherms are enabled.
 *  Supported by the thermal lens of Zenmuse H20T and H20N.
 *  
 *  @param enabled `YES` if Isotherms are enabled.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalIsothermEnabledWithCompletion:(void (^_Nonnull)(BOOL enabled, NSError *_Nullable error))completion;


/**
 *  Sets the unit of the Isotherm ranges to either Celsius or percent. Different
 *  units results in different value ranges for Isotherms.
 *  
 *  @param unit An enum type of the `DJICameraThermalIsothermUnit` to be used. Please refer to `DJICameraThermalIsothermUnit`.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalIsothermUnit:(DJICameraThermalIsothermUnit)unit withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the units for Isotherm ranges.
 *  
 *  @param unit The value of the `DJICameraThermalIsothermUnit` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)getThermalIsothermUnitWithCompletion:(void (^_Nonnull)(DJICameraThermalIsothermUnit unit, NSError *_Nullable error))completion;


/**
 *  Sets the upper threshold value for Isotherm. All temperature values above this
 *  will use colors 224-255 from the palette.
 *  
 *  @param value If the unit is percentage, the allowed range is [0,100].
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalIsothermUpperValue:(NSInteger)value withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the upper threshold value for Isotherm. Supported by the thermal lens of
 *  Zenmuse H20T and H20N.
 *  
 *  @param value The upper threshold value.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalIsothermUpperValueWithCompletion:(void (^_Nonnull)(NSInteger value, NSError *_Nullable error))completion;


/**
 *  Sets the middle threshold value for Isotherm. Temperature values between the
 *  middle and upper Isotherm threshold will be displayed with colors 176-223 from
 *  the palette. Not supported by Zenmuse H20T and H20N.
 *  
 *  @param value If the unit is percentage, the value falls in [0,100]. If the unit is Celsius, the value range is [-40, 550]. The value can only be equal or larger than lower threshold and equal or smaller than upper threshold.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalIsothermMiddleValue:(NSInteger)value withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the middle threshold value for Isotherm. Not supported by Zenmuse H20T and
 *  H20N.
 *  
 *  @param value The middle threshold value for Isotherm.
 *  @param error Error retrieving the value.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)getThermalIsothermMiddleValueWithCompletion:(void (^_Nonnull)(NSInteger value, NSError *_Nullable error))completion;


/**
 *  Sets the lower threshold value for Isotherm. Temperature values between the
 *  lower and middle Isotherm threshold will be displayed with colors 128-175 from
 *  the palette. Supported by the thermal lens of Zenmuse H20T and H20N.
 *  
 *  @param value If the unit is percentage, the value falls in [0,100].
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalIsothermLowerValue:(NSInteger)value withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the lower threshold value for Isotherm. Supported by the thermal lens of
 *  Zenmuse H20T and H20N.
 *  
 *  @param value The lower threshold value for Isotherm.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalIsothermLowerValueWithCompletion:(void (^_Nonnull)(NSInteger value, NSError *_Nullable error))completion;


/**
 *  Sets the gain mode. Low gain mode can be used for scenes with temperatures
 *  ranging from -40 to 550 degrees Celsius. For higher contrast, the high gain mode
 *  can be used by for temperatures between -25 to 135 degrees Celsius for the
 *  640x512 camera and -25 to 100 degrees Celsius for 324 x 256 camera. Mavic 2
 *  Enterprise Dual has different temperature range from other thermal imaging
 *  cameras. Therefore, for Mavic 2 Enterprise Dual, the low gain mode can be used
 *  from -10 to 140 degrees Celsius. The high gain mode can be used from -10 to 400
 *  degree Celsius, for Mavic 2 Enterprise Advanced, the low gain mode can be used
 *  from -20 to 450 degrees Celsius. The high gain mode can be used from -20 to 150
 *  degree Celsius
 *  
 *  @param mode An enum type of the `DJICameraThermalGainMode` to be used.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalGainMode:(DJICameraThermalGainMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the gain mode. Supported by the thermal lens of Zenmuse H20T and H20N.
 *  
 *  @param mode The value of the ```DJICamera_DJICameraThermalGainMode` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalGainModeWithCompletion:(void (^_Nonnull)(DJICameraThermalGainMode mode, NSError *_Nullable error))completion;


/**
 *  Sets the mode for thermal measurement. Use delegate method
 *  `camera:didUpdateTemperatureData` or
 *  `camera:didUpdateAreaTemperatureAggregations` to receive the measurement result.
 *  Supported only by thermal imaging cameras. Supported by the thermal lens of
 *  Zenmuse H20T and H20N and Mavic 2 Enterprise Advanced.
 *  
 *  @param mode The desired measurement mode.
 *  @param completion Completion block that receives the getter execution result.
 */
- (void)setThermalMeasurementMode:(DJICameraThermalMeasurementMode)mode
                   withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the mode for thermal measurement. Supported by the thermal lens of Zenmuse
 *  H20T and H20N.
 *  
 *  @param mode The value of the `DJICameraThermalMeasurementMode` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalMeasurementModeWithCompletion:(void (^_Nonnull)(DJICameraThermalMeasurementMode mode,
                                                                  NSError *_Nullable error))completion;


/**
 *  Adjusts the digital zoom. Supported by the thermal lens of Zenmuse H20T and
 *  H20N.
 *  
 *  @param factor For resolution 640 x 512, x1,x2,x4,x8 can be set. For resolution 336 x 256, only x1,x2,x4 can be set. Please refer to `DJICameraThermalDigitalZoomFactor` in DJICameraSettingsDef.
 *  @param completion The execution callback with the returned execution result.
 */
- (void)setThermalDigitalZoomFactor:(DJICameraThermalDigitalZoomFactor)factor withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets current digital zoom.
 *  
 *  @param factor The value of the `DJICameraThermalDigitalZoomFactor` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalDigitalZoomFactorWithCompletion:(void (^_Nonnull)(DJICameraThermalDigitalZoomFactor factor, NSError *_Nullable error))completion;


/**
 *  Gets the thermal imaging camera profile. The profile includes information about
 *  resolution, frame rate and focal length. Supported by the thermal lens of
 *  Zenmuse H20T and H20N.
 *  
 *  @param profile The value of the `DJICameraThermalProfile` Struct.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalProfileWithCompletion:(void (^_Nonnull)(DJICameraThermalProfile profile, NSError *_Nullable error))completion;


/**
 *  Gets the spot metering target point if one is set, if not then returns
 *  CGPointZero.
 *   Supported by the thermal lens of Zenmuse H20T and H20N and Mavic 2 Enterprise
 *  Advanced.
 *  
 *  @param targetPoint The CGPoint struct.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalSpotMeteringTargetPointWithCompletion:(void (^_Nonnull)(CGPoint targetPoint, NSError *_Nullable error))completion;


/**
 *  Sets the spot metering target point which then . This method requires a relative
 *  point that is proportional to the dimension
 *  of the camera video dimension, the x, and y values must all be between 0 and
 *  1.0. You should call `setThermalMeasurementMode:withCompletion` to set  the
 *  measurement mode to `DJICameraThermalMeasurementModeSpotMetering` first.
 *  Supported by the thermal lens of Zenmuse H20T and H20N and Mavic 2 Enterprise
 *  Advanced.
 *  
 *  @param targetPoint The desired target point.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalSpotMeteringTargetPoint:(CGPoint)targetPoint withCompletion:(DJICompletionBlock)completion;


/**
 *  Get a rect representing the currently set metering area for the thermal scene.
 *  Supported by the thermal lens of Zenmuse H20T and H20N.
 *  
 *  @param area The CGRect struct.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalMeteringAreaWithCompletion:(void (^_Nonnull)(CGRect area, NSError *_Nullable error))completion;


/**
 *  Set the metering area for a rectangle inside the thermal ismage scene, which
 *  allows the camera to transmit aggregate temperature computations via the
 *  `camera:didUpdateAreaTemperatureAggregations` delegate method. See
 *  `DJICameraThermalAreaTemperatureAggregations` for the statistical values that
 *  are available. This method requires a relative rect that is proportional to the
 *  rect of the thermal scene, the x, y, width, and height values must all be
 *  between 0 and 1.0. You should call `setThermalMeasurementMode:withCompletion` to
 *  set  the measurement mode to `DJICameraThermalMeasurementModeAreaMetering`
 *  first. Supported by the thermal lens of Zenmuse H20T and H20N and Mavic 2
 *  Enterprise Advanced.
 *  
 *  @param area The desired thermal metering area.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalMeteringArea:(CGRect)area withCompletion:(DJICompletionBlock)completion;


/**
 *  Get the currently set flat-field correction (FFC) mode.
 *  
 *  @param mode The value of the `DJICameraThermalFFCMode` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalFFCModeWithCompletion:(void (^_Nonnull)(DJICameraThermalFFCMode mode, NSError *_Nullable error))completion;


/**
 *  Set the flat-field correction (FFC) mode. Supported by the thermal lens of
 *  Zenmuse H20T and H20N.
 *  
 *  @param mode The desired FFC mode.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalFFCMode:(DJICameraThermalFFCMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Trigger flat-field correction. Supported by the thermal lens of Zenmuse H20T and
 *  H20N.
 *  
 *  @param completion Completion block that receives the execution result of the trigger action.
 */
- (void)triggerThermalFFCWithCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the currently set custom user profile. This profile represents user-set
 *  external scene parameters for the thermal scene. Not supported by Zenmuse H20T
 *  and H20N.
 *  
 *  @param profile The value of the `DJICameraThermalCustomExternalSceneSettingsProfile` Enum.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalCustomExternalSceneSettingsProfileWithCompletion:(void (^_Nonnull)(DJICameraThermalCustomExternalSceneSettingsProfile profile, NSError *_Nullable error))completion;


/**
 *  Sets the custom user profile. This profile represents user-set external scene
 *  parameters for the thermal scene. Not supported by Zenmuse H20T and H20N.
 *  
 *  @param profile The desired user profile setting.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalCustomExternalSceneSettingsProfile:(DJICameraThermalCustomExternalSceneSettingsProfile)profile withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the temperature unit. Not supported by Mavic 2 Enterprise Advanced.
 *  
 *  @param temperatureUnit Temperature unit to set.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalTemperatureUnit:(DJICameraTemperatureUnit)temperatureUnit withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the temperature unit.
 *  
 *  @param temperatureUnit The current temperature unit.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getThermalTemperatureUnitWithCompletion:(void (^_Nonnull)(DJICameraTemperatureUnit temperatureUnit, NSError *_Nullable error))completion;


/**
 *  Sets the display mode to coordinate the video feeds from both the visual camera
 *  and the thermal camera. Only applies to the thermal infrared video feed. For
 *  Zemmuse H20T and H20N, you should set
 *  `setCameraVideoStreamSource:withCompletion` with
 *  `DJICameraVideoStreamSourceInfraredThermal` first. Only supported by Zenmuse
 *  H20T and H20N.and Mavic 2 Enterprise Advanced.
 *  
 *  @param mode The display mode to set.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setDisplayMode:(DJICameraDisplayMode)mode withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the display mode. The display mode determine the way to coordinate the
 *  video feeds from both the visual camera and the thermal camera.
 *  
 *  @param mode The current display mode.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getDisplayModeWithCompletion:(void (^_Nonnull)(DJICameraDisplayMode mode, NSError *_Nullable error))completion;


/**
 *  Sets the thermal window's position relative to the visual window. Only applies
 *  to the thermal infrared video feed. The setting is valid when the display mode
 *  is `DJICameraDisplayModePIP`. Refer to `setDisplayMode:withCompletion` and
 *  `getDisplayModeWithCompletion`.
 *  
 *  @param position The position to set.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setPIPPosition:(DJICameraPIPPosition)position withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the PIP position which determines the thermal window's position relative to
 *  the visual window. The setting is valid when the display mode is
 *  `DJICameraDisplayModePIP`. Refer to `setDisplayMode:withCompletion` and
 *  `getDisplayModeWithCompletion`.
 *  
 *  @param position The current position.
 *  @param error Error retrieving the value.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)getPIPPositionWithCompletion:(void (^_Nonnull)(DJICameraPIPPosition position, NSError *_Nullable error))completion;


/**
 *  Sets the level for MSX display mode. The range for level is [0, 100]. When it is
 *  0, the visible spectrum definition is invisible. When it is 100, the visual
 *  spectrum definition is the most obvious. Only applies to the thermal infrared
 *  video feed.
 *  
 *  @param level The MSX level to set with range [0, 100].
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setMSXLevel:(uint8_t)level withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the level for MSX display mode. The range for level is [0, 100]. When it is
 *  0, the visible spectrum definition is invisible. When it is 100, the visual
 *  spectrum definition is the most obvious. Supported by the thermal lens of
 *  Zenmuse H20T and H20N.
 *  
 *  @param level The current MSX level.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getMSXLevelWithCompletion:(void (^_Nonnull)(uint8_t level, NSError *_Nullable error))completion;


/**
 *  Sets the temperature of the atmosphere between the scene and the camera. Not
 *  supported by Zenmuse H20T and H20N.
 *  
 *  @param temperature The assumed temperature of the atmosphere between the camera and the scene, can be between -50 and 327.67 degrees Celsius.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalAtmosphericTemperature:(float)temperature withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the transmission coefficient of the atmosphere between the scene and the
 *  camera. Not supported by Zenmuse H20T and H20N.
 *  
 *  @param coefficient The desired atmospheric temperature, can be between 50 and 100.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalAtmosphericTransmissionCoefficient:(float)coefficient withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the assumed temperature reflected by the background of the scene, can be
 *  between -50 and 327.67 degrees Celsius. Not supported by Zenmuse H20T and H20N.
 *  
 *  @param temperature The desired background reflected temperature.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalBackgroundTemperature:(float)temperature withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the emissivity of the thermal scene, can be between 50 and 100. Not
 *  supported by Zenmuse H20T and H20N.
 *  
 *  @param emissivity The desired scene emissivity.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalSceneEmissivity:(float)emissivity withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets assumed window reflection coefficient, can be between 0 and X where X is
 *  the window transmission coefficient parameter. Not supported by Zenmuse H20T and
 *  H20N.
 *  
 *  @param reflection The desired window reflection coefficient.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalWindowReflection:(float)reflection withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the temperature reflected in the window, can be between -50 and 327.67
 *  degrees Celsius. Not supported by Zenmuse H20T and H20N.
 *  
 *  @param temperature The desired window reflected temperature.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalWindowReflectedTemperature:(float)temperature withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the window temperature, can be between -50 and 327.67 degrees Celsius. Not
 *  supported by Zenmuse H20T and H20N.
 *  
 *  @param temperature The desired window temperature.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalWindowTemperature:(float)temperature withCompletion:(DJICompletionBlock)completion;


/**
 *  Sets the window transmission coefficient, can be between 50 and 100-X where X is
 *  the window reflection. Not supported by Zenmuse H20T and H20N.
 *  
 *  @param coefficient The desired window transmission coefficient.
 *  @param completion Completion block that receives the setter execution result.
 */
- (void)setThermalWindowTransmissionCoefficient:(float)coefficient withCompletion:(DJICompletionBlock)completion;


/**
 *  Enables or disables the infrared sensor protection. If the sensor protection is
 *  enabled, the infrared thermal camera shutter might be closed. Only supported by
 *  Zenmuse H20T and H20N.
 *  
 *  @param isEnabled Enable or disable infrared sensor protection.
 *  @param completion The completion block that receives the execution result.
 */
- (void)setInfraredThermalCameraSensorBurningProtectionEnabled:(BOOL)isEnabled withCompletion:(DJICompletionBlock)completion;


/**
 *  Enables the infrared thermal camera. Infrared thermal camera shutter may be
 *  closed, if the sensor protection is enabled. Only supported by Zenmuse H20T and
 *  H20N.
 *  
 *  @param completion The completion block that receives the execution result.
 */
- (void)setInfraredThermalCameraShutterEnabled:(DJICompletionBlock)completion;


/**
 *  Gets temperature range of specific gain mode. Only Supported by the thermal lens
 *  of Zenmuse H20T and H20N.
 *  
 *  @param mode Given camera gain mode.
 *  @param range The temperature measurement range of given gain mode.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)getTemperatureMeasurementRangeWithGainMode:(DJICameraThermalGainMode)mode completion:(void (^_Nonnull)(NSArray <NSNumber *> *range, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

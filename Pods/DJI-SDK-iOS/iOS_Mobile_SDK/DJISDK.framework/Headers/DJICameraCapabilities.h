//
//  DJICameraCapabilities.h
//  DJISDK
//
//  Copyright © 2017, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DJICameraSettingsDef.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Range Key of the change dictionary.


/**
 *  CameraVideoCompressionStandardRange key.
 */
extern NSString *const DJISupportedCameraVideoFileCompressionStandardRange;


/**
 *  CameraVideoResolutionAndFrameRateRange key.
 */
extern NSString *const DJISupportedCameraVideoResolutionAndFrameRateRange;


/**
 *  CameraVideoStandardRange key.
 */
extern NSString *const DJISupportedCameraVideoStandardRange;


/**
 *  DJISupportedCameraVideoFOVRange key.
 */
extern NSString *const DJISupportedCameraVideoFOVRange;


/**
 *  CameraModeRange key.
 */
extern NSString *const DJISupportedCameraModeRange;


/**
 *  CameraExposureModeRange key.
 */
extern NSString *const DJISupportedCameraExposureModeRange;


/**
 *  CameraISORange key.
 */
extern NSString *const DJISupportedCameraISORange;


/**
 *  CameraShutterSpeedRange key.
 */
extern NSString *const DJISupportedCameraShutterSpeedRange;


/**
 *  CameraExposureCompensationRange key.
 */
extern NSString *const DJISupportedCameraExposureCompensationRange;


/**
 *  CameraApertureRange key.
 */
extern NSString *const DJISupportedCameraApertureRange;


/**
 *  Key to query the supported RAW video resolution. It is supported by X5S camera.
 */
extern NSString *const DJISupportedCameraSSDVideoResolutionRange;


/**
 *  Number of photos using burst capture mode return a array of
 *  `DJICameraPhotoBurstCount`.
 */
extern NSString *const DJISupportedCameraBurstCaptureCountRange;


/**
 *  Number of photos using RAWBurst capture mode return a array of
 *  `DJICameraPhotoBurstCount`.
 */
extern NSString *const DJISupportedCameraRAWBurstCaptureCountRange;


/**
 *  The number of pictures to continuously take at one time in AEB mode return a
 *  array of `DJICameraPhotoAEBCount`.
 */
extern NSString *const DJISupportedCameraAEBCaptureNumRange;


/**
 *  Interval range of camera timed shot return a array contains min value, max value
 *  in seconds.
 */
extern NSString *const DJISupportedCameraPhotoIntervalRange;


/**
 *  Count range of camera timed shot return a array contains min value, max value in
 *  seconds.
 */
extern NSString *const DJISupportedCameraPhotoCountRange;


/**
 *  Camera photo file formats return a list of `DJICameraPhotoFileFormat`.
 */
extern NSString *const DJISupportedCameraPhotoFileFormatRange;


/**
 *  Camera video file formats return a list of `DJICameraVideoFileFormat`.
 */
extern NSString *const DJISupportedCameraVideoFileFormatRange;


/**
 *  Return an array contains min wb color temp value and max value, for example
 *  value 20 is 20*100 = 2000k.
 */
extern NSString *const DJISupportedCameraWhiteBalanceCustomColorTemperatureRange;


/**
 *  Return an array contains min and max value for custom picture style saturation.
 */
extern NSString *const DJISupportedCameraPictureStyleCustomSaturationRange;


/**
 *  Return an array contains min and max value for custom picture style sharpness.
 */
extern NSString *const DJISupportedCameraPictureStyleCustomSharpnessRange;


/**
 *  Return an array contains min and max value for custom picture style contrast.
 */
extern NSString *const DJISupportedCameraPictureStyleCustomContrastRange;


/**
 *  Return a list contains camera color supported.
 */
extern NSString *const DJISupportedCameraColorRange;


/**
 *  Return a list of `DJICameraWhiteBalancePreset`.
 */
extern NSString *const DJISupportedCameraWhiteBalancePresetRange;


/**
 *  Return a list of `DJICameraPhotoAspectRatio`.
 */
extern NSString *const DJISupportedCameraPhotoAspectRatioRange;


/**
 *  Return a list of `DJICameraShootPhotoMode` elements.
 */
extern NSString *const DJISupportedCameraPhotoShootModeRange;


/**
 *  Use this key to fetch all the file formats of original images supported by the
 *  camera in panorama mode.
 */
extern NSString *const DJISupportedCameraPanoOriginalImagesFormatRange;


/**
 *  Use this key to fetch the panorama modes supported by the camera.
 */
extern NSString *const DJISupportedCameraPhotoPanoramaModeRange;


/**
 *  Use this key to fetch the orientations supported by the camera.
 */
extern NSString *const DJISupportedCameraOrientationRange;


/**
 *  Use this key to fetch the anti flicker frequency supported by the camera.
 */
extern NSString *const DJISupportedCameraAntiFlickerFrequencyRange;


/**
 *  Use this key to fetch the long exposure preview time supported by the camera.
 */
extern NSString *const DJISupportedCameraLongExposurePreviewTimeRange;


/**
 *  Use this key to fetch the thermal palettes supported by the camera.
 */
extern NSString *const DJISupportedCameraThermalPaletteRange;


/**
 *  Use this key to fetch the thermal scene supported by the camera.
 */
extern NSString *const DJISupportedCameraThermalSceneRange;


/**
 *  Use this key to fetch the Iso therm unit supported by the camera.
 */
extern NSString *const DJISupportedCameraThermalIsoThermUnitRange;


/**
 *  Use this key to fetch the display mode supported by the thermal camera.
 */
extern NSString *const DJISupportedCameraDisplayMode;


/**
 *  Use this key to fetch the temperature units supported by the thermal camera.
 */
extern NSString *const DJISupportedCameraTemperatureUnitRange;


/**
 *  Use this key to fetch the dual feed vertical alignment offset supported by the
 *  thermal camera. Return a array contains min value, max value.
 */
extern NSString *const DJISupportedCameraDualFeedVerticalAlignmentOffsetRange;


/**
 *  Use this key to fetch the dual feed horizontal alignment offset supported by the
 *  thermal camera. Returns an array contains min value, max value.
 */
extern NSString *const DJISupportedCameraDualFeedHorizontalAlignmentOffsetRange;


/**
 *  Use this key to fetch the exposure compensation supported by the multispectral
 *  camera single-band sensors (sensors except the RGB one).  Only supported by
 *  multispectral camera of P4 Multispectral.
 */
extern NSString *const DJISupportedCameraMultispectralExposureCompensationRange;


/**
 *  Use this key to fetch the shutter speed supported by the multispectral camera
 *  single-band sensors (sensors except the RGB one).  Only supported by
 *  multispectral camera of P4 Multispectral.
 */
extern NSString *const DJISupportedCameraMultispectralShutterSpeedRange;


/**
 *  Fetches the camera video stream sources supported by current camera. Return an
 *  array of `DJICameraVideoStreamSource`.
 */
extern NSString *const DJISupportedCameraVideoStreamSourceRange;


/**
 *  Use this key to fetch the supported flat camera mode (see `DJIFlatCameraMode`).
 */
extern NSString *const DJISupportedFlatCameraModeRange;


/**
 *  Use this key to fetch the supported temperature range for current gain mode.
 *  Return a array contains min value, max value.
 */
extern NSString *const DJISupportedThermalGainModeTemperatureRange;

@class DJICameraCapabilities;


/**
 *  This protocol provides a method that is notified when the camera parameters'
 *  range changes.
 */
@protocol DJICameraCapabilitiesListener <NSObject>

@optional


/**
 *  When a parameter range is changed, the listener will receive this callback.
 *  
 *  @param capabilities The parameters.
 *  @param change The new range and key.
 */
- (void)cameraCapabilities:(nonnull DJICameraCapabilities *)capabilities change:(nonnull NSDictionary<id, NSString *> *)change;

@end


/**
 *  Some of the camera's parameters have dynamic ranges. The `DJICameraCapabilities`
 *  class allows you to query the valid range for a parameter. Type-casting is
 *  required to get the corresponding enumerator value for each range element.
 */
@interface DJICameraCapabilities : NSObject


/**
 *  Returns the current valid range for video file compression standard range.
 *  
 *  @return Array of NSNumber. Each element represents one current supported video file compression standard.
 */
- (nonnull NSArray<NSNumber *> *)videoFileCompressionStandardRange;


/**
 *  Returns the current valid range for video resolution DJICameraVideoResolution
 *  and frame rate `DJICameraVideoFrameRate`. Returns `nil` if the current camera
 *  does  not support any video resolution or frame rate setting, or if the camera
 *  is disconnected.
 *  
 *  @return Array of pairs. Each pair represents a valid `DJICameraVideoResolution` value and `DJICameraVideoFrameRate` value.
 */
- (nonnull NSArray<DJICameraVideoResolutionAndFrameRate *> *)videoResolutionAndFrameRateRange;


/**
 *  Returns the current valid range for video standard. Returns `nil` if the current
 *  camera does not support any video standard, or if the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported video standard.
 */
- (nonnull NSArray<NSNumber *> *)videoStandardRange;


/**
 *  Returns the current valid range for camera mode (`DJICameraMode`). Returns `nil`
 *  if  current camera has no supported camera mode or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera mode.
 */
- (nonnull NSArray<NSNumber *> *)modeRange;


/**
 *  Returns the current valid range for camera's exposure mode
 *  (`DJICameraExposureMode`). Returns  `nil` if current camera does not support any
 *  exposure mode or the camera is disconnected.  @return Array of NSNumber. Each
 *  element represents one current supported exposure mode.
 *  
 *  @return Array of `NSNumber`. Each element represents one current supported exposure mode.
 */
- (nonnull NSArray<NSNumber *> *)exposureModeRange;


/**
 *  Returns the current valid range for camera's ISO (see `DJICameraISO`). Returns
 *  `nil` if current camera does not support any ISO value or the camera is
 *  disconnected. @return An NSNumber array. Each element represent one current
 *  supported ISO value.
 *  
 *  @return Array of NSNumber. Each element represents one current supported ISO value.
 */
- (nonnull NSArray<NSNumber *> *)ISORange;


/**
 *  Returns the current valid range for camera's shutter speed (see
 *  `DJICameraShutterSpeed`). Returns  `nil` if current camera does not support any
 *  shutter speed value or the camera is  disconnected. @return Array of NSNumber.
 *  Each element represents one current  supported shutter speed value.
 *  
 *  @return Array of NSNumber. Each element represents one current supported shutter speed value.
 */
- (nonnull NSArray<NSNumber *> *)shutterSpeedRange;


/**
 *  Returns the current valid range for camera's exposure compensation (see
 *  `DJICameraExposureCompensation`).  Returns `nil` if current camera does not
 *  support any exposure compensation value or the camera  is disconnected. @return
 *  Array of NSNumber. Each element represents one  current supported exposure
 *  compensation value.
 *  
 *  @return Array of NSNumber. Each element represents one current supported exposure compensation value.
 */
- (nonnull NSArray<NSNumber *> *)exposureCompensationRange;


/**
 *  Returns the current valid range for camera's aperture (see `DJICameraAperture`).
 *  Returns  `nil` if current camera does not support any aperture value or the
 *  camera is disconnected.  @return Array of NSNumber. Each element represents one
 *  current supported aperture  value.
 *  
 *  @return Array of NSNumber. Each element represents one current supported aperture value.
 */
- (nonnull NSArray<NSNumber *> *)apertureRange;


/**
 *  Returns the current valid range for camera's RAW video resolution. Returns 'nil'
 *  if current  camera does not support any RAW video resolution or the camera is
 *  disconnected.
 *  
 *  @return Array of pairs. Each pair represents a valid `DJICameraVideoResolution` value and `DJICameraVideoFrameRate` value.
 */
- (NSArray<DJICameraVideoResolutionAndFrameRate *> *)SSDVideoResolutionRange;


/**
 *  Returns the photo formats supported by the camera for saving the original images
 *  of panorama.  The return value is `nil` if current camera does not support any
 *  photo formats or is disconnected.
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraPhotoFileFormat`.
 */
- (nonnull NSArray<NSNumber *> *)panoOriginalImagesFormatRange;


/**
 *  Returns the current valid range for camera's photo aspect ratio (See
 *  `DJICameraPhotoAspectRatio`).  Returns `nil` if current camera does not support
 *  any photo aspect ratio value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported photo aspect ratio value.
 */
- (nonnull NSArray<NSNumber *> *)photoAspectRatioRange;


/**
 *  Returns the current valid video format range for h1 cameras in raw mode. Returns
 *  `nil` if current camera does not support any value or the camera is
 *  disconnected.
 *  
 *  @return Array of pairs, each consisting of a valid 'DJIH1RawModeEnum' value, a valid `DJICameraVideoResolution` value and `DJICameraVideoFrameRate`.
 */
- (nonnull NSArray<NSNumber *> *)H1VideoFormatRange;


/**
 *  Returns the current valid video file format. Returns `nil` if current camera
 *  does not support any value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera video file format range.
 */
- (nonnull NSArray<NSNumber *> *)videoFileFormatRange;


/**
 *  Returns the current valid camera photo file format range. Returns `nil` if
 *  current camera does not support any value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera photo file format range.
 */
- (nonnull NSArray<NSNumber *> *)photoFileFormatRange;


/**
 *  Returns the current valid camera picture style custom saturation range. Returns
 *  `nil` if current camera does not support any value or the camera is
 *  disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera picture style custom saturation range.
 */
- (nonnull NSArray<NSNumber *> *)pictureStyleCustomSaturationRange;


/**
 *  Returns the current valid camera picture style custom sharpness range. Returns
 *  `nil` if current camera does not support any value or the camera is
 *  disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera picture style custom sharpness range.
 */
- (nonnull NSArray<NSNumber *> *)pictureStyleCustomSharpnessRange;


/**
 *  Returns the current valid camera picture style custom contrast range. Returns
 *  `nil` if current camera does not support any value or the camera is
 *  disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera picture style custom contrast range.
 */
- (nonnull NSArray<NSNumber *> *)pictureStyleCustomContrastRange;


/**
 *  Returns the current valid presets for camera's white balance (see
 *  `DJICameraWhiteBalancePreset`). Returns `nil` if current camera does not support
 *  any white balance value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera white balance preset range.
 */
- (nonnull NSArray<NSNumber *> *)whiteBalancePresetRange;


/**
 *  Returns the current valid range for camera's custom color temperature.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera white balance custom color temperature range.
 */
- (nonnull NSArray<NSNumber *> *)whiteBalanceCustomColorTemperatureRange;


/**
 *  Returns the current valid camera color range. Returns `nil` if current camera
 *  does not support any value  or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera color range.
 */
- (nonnull NSArray<NSNumber *> *)colorRange;


/**
 *  Returns the current valid camera burst count range. Returns `nil` if current
 *  camera does not support any value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera burst capture count range.
 */
- (nonnull NSArray<NSNumber *> *)burstCaptureCountRange;


/**
 *  Returns the current valid range for camera's AEB (see `DJICameraPhotoAEBCount`).
 *  Returns `nil` if current camera does not support any AEB value or the camera is
 *  disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera AEB capture num range.
 */
- (nonnull NSArray<NSNumber *> *)AEBCaptureNumRange;


/**
 *  Returns the current valid camera photo interval range. Returns `nil` if current
 *  camera does not support  any value or the camera is disconnected. Used for
 *  `DJICameraPhotoTimeIntervalSettings`.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera photo interval range.
 */
- (nonnull NSArray<NSNumber *> *)photoIntervalRange;


/**
 *  Returns the current valid camera photo count range. Used for
 *  `DJICameraPhotoTimeIntervalSettings`.
 *  
 *  @return Array of NSNumber. Each element represents one current supported camera photo count range.
 */
- (nonnull NSArray<NSNumber *> *)photoCountRange;


/**
 *  Returns the supported camera shoot photo modes. Returns `nil` if current camera
 *  does not support any value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element represents one supported camera shoot photo mode.
 */
- (nonnull NSArray<NSNumber *> *)photoShootModeRange;


/**
 *  Returns the panorama modes supported by the camera. Returns `nil` if current
 *  camera does  not support any value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraPhotoPanoramaMode`.
 */
- (nonnull NSArray<NSNumber *> *)photoPanoramaModeRange;


/**
 *  Returns the orientations supported by the camera. Returns `nil` if current
 *  camera does  not support any value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraOrientation`.
 */
- (nonnull NSArray<NSNumber *> *)orientationRange;


/**
 *  Returns the anti flicker frequency supported by the camera. Returns `nil` if
 *  current camera does  not support any value or the camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraAntiFlickerFrequency`.
 */
- (nonnull NSArray<NSNumber *> *)antiFlickerFrequencyRange;


/**
 *  Returns the long exposure preview time supported by the camera. Returns `nil` if
 *  current camera does  not support any value or the camera is disconnected.
 *  
 *  @return Array of NSNumber.
 */
- (nonnull NSArray<NSNumber *> *)longExposurePreviewTimeRange;


/**
 *  Returns the current valid range for thermal camera's palette (see
 *  `DJICameraThermalPalette`).  Returns `NULL` if  current thermal camera has not
 *  supported palette or the thermal camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraThermalPalette`.
 */
- (nonnull NSArray<NSNumber *> *)thermalPaletteRange;


/**
 *  Returns the current valid range for thermal camera's palette (see
 *  `DJICameraThermalPalette`).  Returns `NULL` if  current thermal camera has not
 *  supported palette or the thermal camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraThermalScene`.
 */
- (nonnull NSArray<NSNumber *> *)thermalSceneRange;


/**
 *  Returns the current valid range for thermal camera's iso therm unit (see
 *  `DJICameraThermalIsothermUnit`).  Returns `nil` if  current thermal camera has
 *  not supported iso therm unit or the thermal camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraThermalIsothermUnit`.
 */
- (nonnull NSArray<NSNumber *> *)isoThermUnitRange;


/**
 *  Returns the current valid range for thermal camera's temperatureUnits (see
 *  `DJICameraTemperatureUnit`).  Returns `NULL` if  current thermal camera has not
 *  supported temperatureUnits or the thermal camera is disconnected.
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraTemperatureUnit`.
 */
- (nonnull NSArray<NSNumber *> *)temperatureUnitsRange;


/**
 *  Returns the current valid range for thermal camera's displayMode (see
 *  `DJICameraDisplayMode`).
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraDisplayMode`.
 */
- (nonnull NSArray<NSNumber *> *)displayModeRange;


/**
 *  Returns the current valid range for multispectral camera's single-band sensors's
 *  (sensors except the RGB one). Exposure compensation (see
 *  `DJICameraExposureCompensation`).   Returns `NULL` if current camera does not
 *  support any exposure compensation value or the multispectral camera is
 *  disconnected. Only supported by multispectral camera of P4 Multispectral.
 *  
 *  @return Array of NSNumber. Each element represents one current supported exposure compensation value.
 */
- (nonnull NSArray<NSNumber *> *)multispectralExposureCompensationRange;


/**
 *  Returns the current valid range for multispectral camera's single-band sensors's
 *  (sensors except the RGB one). shutter speed (see `DJICameraShutterSpeed`).
 *  Returns `nil` if current camera does not support any shutter speed value or the
 *  camera is disconnected. Only supported by multispectral camera of P4
 *  Multispectral.
 *  
 *  @return Array of NSNumber. Each element represents one current supported shutter speed value.
 */
- (nonnull NSArray<NSNumber *> *)multispectralShutterSpeedRange;


/**
 *  Returns the current valid range for camera's stream id (see
 *  `DJICameraVideoStreamSource`).
 *  
 *  @return Array of NSNumber. Each element is a value of `DJICameraVideoStreamSource`.
 */
- (nonnull NSArray<NSNumber *> *)videoStreamSourceRange;


/**
 *  Returns the current valid range for flat mode (see `DJIFlatCameraMode`).
 *  
 *  @return Array of NSNumber. Each element is a value of `DJIFlatCameraMode`.
 */
- (nonnull NSArray<NSNumber *> *)flatModeRange;


/**
 *  Returns the temperature range supported by current gain mode.
 *  
 *  @return Array of NSNumber contains min value, max value.
 */
- (nonnull NSArray<NSNumber *> *)thermalGainModeTemperatureRange;

@end

/**
 *  A category of DJICameraCapabilities. It provides methods to add or remove listeners for valid range change.
 */
@interface DJICameraCapabilities (Listener)


/**
 *  Add listener to listen for the camera range change.
 *  
 *  @param listener listener
 */
- (void)addListener:(nonnull id<DJICameraCapabilitiesListener>)listener;


/**
 *  Remove listener which is listening to the camera range change.
 *  
 *  @param listener listener
 */
- (void)removeListener:(nonnull id<DJICameraCapabilitiesListener>)listener;


/**
 *  Remove all listeners.
 */
- (void)removeAllListeners;

@end

NS_ASSUME_NONNULL_END

//
//  NSError+DJISDK.h
//  DJISDK
//
//  Copyright © 2015, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*********************************************************************************/
#pragma mark - Error Domains
/*********************************************************************************/


/**
 *  SDK common error domain.
 */
FOUNDATION_EXPORT NSString * _Nonnull const DJISDKErrorDomain;


/**
 *  SDK camera error domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKCameraErrorDomain;


/**
 *  SDK mission error domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKMissionErrorDomain;


/**
 *  SDK battery error domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKBatteryErrorDomain;


/**
 *  SDK gimbal error domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKGimbalErrorDomain;


/**
 *  SDK flight controller domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKFlightControllerErrorDomain;


/**
 *  SDK remote controller domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKRemoteControllerErrorDomain;


/**
 *  SDK registration error domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKRegistrationErrorDomain;


/**
 *  SDK GEO error domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKFlySafeErrorDomain;


/**
 *  SDK FlightHub error domain.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJISDKFlightHubErrorDomain;


/**
 *  The error domain used to describe errors produced by the `DJITakeOffAction`
 *  object.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJITakeOffActionErrorDomain;


/**
 *  The error domain used to describe errors produced by the
 *  `DJIRTKNetworkServiceProvider`.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJIRTKNetworkServiceErrorDomain;


/**
 *  The error domain used to describe errors produced by the
 *  `DJIAccessoryAggregation` object.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJIAccessoryAggregationErrorDomain;


/**
 *  The error domain used to describe errors produced by the `DJIAccessLocker`
 *  object.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJIAccessLockerErrorDomain;


/**
 *  Defines the domain of "Pipeline" error.
 */
FOUNDATION_EXPORT NSString *_Nonnull const DJIPipelineErrorDomain;

/*********************************************************************************/
#pragma mark DJISDKRegistrationError
/*********************************************************************************/


/**
 *  The Error of SDK Registration.
 */
typedef NS_ENUM (NSInteger, DJISDKRegistrationError){
 

    /**
     *  The application is not able to connect to the Internet the first time it tries
     *  to register the API Key.
     */
    DJISDKRegistrationErrorCouldNotConnectToInternet = -1L,


    /**
     *  The application key you provided is incorrect.
     */
    DJISDKRegistrationErrorInvalidAppKey = -2L,


    /**
     *  The network you are trying to reach is busy, or the server is unreachable.
     */
    DJISDKRegistrationErrorHTTPTimeout = -3L,


    /**
     *  The attempt to copy metadata from another registered device to a device that is
     *  currently connected is not permitted. For example, if a developer has two
     *  devices and the application is activated with the app key on one of the devices
     *  and if the other device is plugged in and tries to register the application,
     *  this error will occur.
     */
    DJISDKRegistrationErrorDeviceDoesNotMatch = -4L,


    /**
     *  The bundle identifier of your application does not match the bundle identifier
     *  you registered on the developer website when you applied to obtain an
     *  application key.
     */
    DJISDKRegistrationErrorBundleIdDoesNotMatch = -5L,


    /**
     *  The application key is prohibited. This occurs when an application key that has
     *  already been released by DJI is revoked. Please contact DJI for assistance.
     */
    DJISDKRegistrationErrorAppKeyProhibited = -6L,


    /**
     *  There is a maximum number of devices one application key can be used to
     *  activate. The maximum number of devices is given when an application is
     *  registered on the DJI developer website. This error will occur if the maximum
     *  number of activations has been reached.
     */
    DJISDKRegistrationErrorMaxActivationCountReached = -7L,


    /**
     *  This error occurs when an application key was given for a specific platform and
     *  is trying to be used to activate an application for another platform. For
     *  instance, if an application key was given for an iOS application and is used to
     *  activate an Android application, this error will occur.
     */
    DJISDKRegistrationErrorAppKeyInvalidPlatformError = -8L,


    /**
     *  The application key does not exist. Please make sure the application key you are
     *  entering is correct.
     */
    DJISDKRegistrationErrorAppKeyDoesNotExist = -9L,


    /**
     *  There are two levels for the SDK framework, level 1 and level 2. If an
     *  application key was given under one level and is trying to be used to active an
     *  application using another level SDK framework, this error will occur.
     */
    DJISDKRegistrationErrorAppKeyLevelNotPermitted = -10L,


    /**
     *  There is a server error. Please contact DJI for assistance.
     */
    DJISDKRegistrationErrorServerParseFailure = -11L,


    /**
     *  There is a server error. Please contact DJI for assistance.
     */
    DJISDKRegistrationErrorServerWriteError = -12L,


    /**
     *  There is a server error. Please contact DJI for assistance.
     */
    DJISDKRegistrationErrorServerDataAbnormal = -13L,


    /**
     *  The activation data received from server is invalid. Please reconnect to the
     *  internet and try again.
     */
    DJISDKRegistrationErrorInvalidMetaData = -14L,


    /**
     *  No application key was provided.
     */
    DJISDKRegistrationErrorEmptyAppKey = -15L,


    /**
     *  Applications under basic develop account could only have the maximum of 20
     *  unique activations. Visit DJI developer center
     *  <https://developer.dji.com/user/membership/> to upgrade the membership.
     */
	DJISDKRegistrationErrorOverMaxActivationsCount = -16L,


	/**
	 *  The application is not enrolled in the Beta Program. Use an app key under the
	 *  Beta Program instead.
	 */
	DJISDKRegistrationErrorAppKeyNotEnrolledByBetaSDK = -17L,
	

	/**
	 *  The app key is invalid for this beta version.
	 */
	DJISDKRegistrationErrorInvalidAppKeyForBetaVersion = -18L,
	

    /**
     *  Download flysafe database failed. You can close LDM mode to retry register App
     *  or Use cocoapods to embed flysafe database.
     */
    DJISDKRegistrationErrorDownloadFlySafeDatabaseFailedWithLDMModeOn = -19L,
    

    /**
     *  App activation failed.
     */
    DJISDKRegistrationErrorActivateFailed = -20L,


    /**
     *  SDK Version is blocked.
     */
    DJISDKRegistrationErrorSDKVersionBlocked = -21L,
    

    /**
     *  App key is blocked.
     */
    DJISDKRegistrationErrorAppKeyBlocked = -22L,
    

    /**
     *  An unknown error occurred when the application was trying to register. Please
     *  contact DJI for assistance.
     */
    DJISDKRegistrationErrorUnknown = -999L
};

/*********************************************************************************/
#pragma mark DJISDKError
/*********************************************************************************/


/**
 *  DJI SDK Error.
 */
typedef NS_ENUM (NSInteger, DJISDKError){
 

    /**
     *  Feature not supported error.
     */
    DJISDKErrorSDKFeatureNotSupported = -1000L,
 

    /**
     *  Application not activated error.
     */
    DJISDKErrorApplicationNotActivated = -1001L,
 

    /**
     *  SDKLevel not permitted error.
     */
    DJISDKErrorSDKLevelNotPermitted = -1002L,
 

    /**
     *  Timeout error.
     */
    DJISDKErrorTimeout = -1003L,
 

    /**
     *  System busy error.
     */
    DJISDKErrorSystemBusy = -1004L,
 

    /**
     *  Parameters invalid error.
     */
    DJISDKErrorInvalidParameters = -1005L,
 

    /**
     *  Get parameter failed error.
     */
    DJISDKErrorParameterGetFailed = -1006L,
 

    /**
     *  Setting parameters operation failed.
     */
    DJISDKErrorParameterSetFailed = -1007L,
 

    /**
     *  Command execute failed error.
     */
    DJISDKErrorCommandExecutionFailed = -1008L,
 

    /**
     *  Send data failed error.
     */
    DJISDKErrorSendDataFailed = -1009L,
 

    /**
     *  Connection to SDK failed error.
     */
    DJISDKErrorConnectionToSDKFailed = -1010L,
 

    /**
     *  Server data not ready.
     */
    DJISDKErrorServerDataNotReady = -1011L,
 

    /**
     *  Product unknown.
     */
    DJISDKErrorProductUnknown = -1012L,
 

    /**
     *  Product not support.
     */
    DJISDKErrorProductNotSupport = -1013L,
 

    /**
     *  Device not found.
     */
    DJISDKErrorDeviceNotFound = -1014L,
 

    /**
     *  The command is not supported by the current firmware version.
     */
    DJISDKErrorNotSupportedByFirmware = -1015L,
 

    /**
     *  The received data is invalid.
     */
    DJISDKErrorReceivedDataInvalid = -1016L,
 

    /**
     *  No data is received.
     */
    DJISDKErrorNoReceivedData = -1017L,
 

    /**
     *  The Bluetooth is off. Turn it on in iOS settings menu.
     */
    DJISDKErrorBluetoothOff = -1018L,


    /**
     *  Operation is cancelled.
     */
    DJISDKErrorOperationCancelled = -1019L,


    /**
     *  The Internet is not reachable.
     */
    DJISDKErrorInternetNetworkIsNotReachable = -1020L,
    

    /**
     *  Local Data Mode (LDM) is not supported in your context.
     */
    DJISDKErrorLDMIsNotSupported = -1021L,
    

    /**
     *  There are no existing archived logs.
     */
    DJISDKErrorNoExistingArchiveLogs = -1022L,
    

    /**
     *  The pack to send is more than the maximum allowed size.
     */
    DJISDKErrorBeyondMaximumAllowedSize = -1023L,
    

    /**
     *  The current transmission rate already reached the channel's bandwidth. Re-send
     *  data later.
     */
    DJISDKErrorReachChannelBandwidth = -1024L,
    

    /**
     *  The operation can't be executed in current state.
     */
    DJISDKErrorCanNotExecute = -1025L,
    

    /**
     *  The operation can't be executed because a higher level task is executing.
     */
    DJISDKErrorHigherLevelTaskExecuting = -1026L,
    

    /**
     *  The operation can't be executed because the command can not be executed in the
     *  current state of product.
     */
    DJISDKErrorCommandNotSupportByCurrentState = -1027L,


    /**
     *  The aircraft has not connected.
     */
    DJISDKErrorAircraftNotConnected = -1028L,

    /**
     *  The operation can't be executed by multi-lens camera. Please use lens object.
     */
    DJISDKErrorInvalidCameraObject = -1029L,
    

    /**
     *  The set area code is inconsistent with the local area code.
     */
    DJISDKErrorRemoteIDAreaCodeNotSame = -1030L,
    

    /**
     *  Not defined error.
     */
    DJISDKErrorNotDefined = -1999L,
};

/*********************************************************************************/
#pragma mark DJISDKCameraError
/*********************************************************************************/


/**
 *  DJI SDK Camera Error.
 */
typedef NS_ENUM (NSInteger, DJISDKCameraError){
 

    /**
     *  Not supported command or command not support in this firmware.
     */
    DJISDKCameraErrorFirmwareDoesNotSupportCommand = -3000L,
 

    /**
     *  Camera memory allocation failed error.
     */
    DJISDKCameraErrorMemoryAllocationFailed = -3001L,
 

    /**
     *  Camera busy or command could not execute in current state.
     */
    DJISDKCameraErrorCommandCurrentlyNotEnabled = -3002L,
 

    /**
     *  Camera time not synced.
     */
    DJISDKCameraErrorTimeNotSynced = -3003L,
 

    /**
     *  No SD card.
     */
    DJISDKCameraErrorSDCardNotInserted = -3004L,
 

    /**
     *  SD card full.
     */
    DJISDKCameraErrorSDCardFull = -3005L,
 

    /**
     *  SD card error.
     */
    DJISDKCameraErrorSDCardError = -3006L,
 

    /**
     *  Camera sensor error.
     */
    DJISDKCameraErrorSensorError = -3007L,
 

    /**
     *  Camera system error.
     */
    DJISDKCameraErrorSystemError = -3008L,
 

    /**
     *  The command is not supported by the media file type.
     */
    DJISDKCameraErrorMediaTypeError = -3009L,
 

    /**
     *  The media file is not found in SD card.
     */
    DJISDKCameraErrorNoSuchMediaFile = -3010L,
 

    /**
     *  The command is aborted unexpectedly.
     */
    DJISDKCameraErrorMediaCommandAborted = -3011L,
 

    /**
     *  Data is corrupted during the file transmission.
     */
    DJISDKCameraErrorMediaFileDataCorrupted = -3012L,
 

    /**
     *  The media command is invalid.
     */
    DJISDKCameraErrorInvalidMediaCommand = -3013L,
 

    /**
     *  There is no permission to access the media file.
     */
    DJISDKCameraErrorNoPermission = -3014L,
 

    /**
     *  The download process of DJIPlaybackManager is interrupted.
     */
    DJISDKCameraErrorPlaybackDownloadInterruption = -3015L,
 

    /**
     *  There is no downloading files to stop.
     */
    DJISDKCameraErrorPlaybackNoDownloadingFiles = -3016L,
 

    /**
     *  Error accessing the SSD.
     */
    DJISDKCameraErrorSSDNotInserted = -3017L,
    

    /**
     *  The Camera's SSD is full.
     */
    DJISDKCameraErrorSSDFull = -3018L,
    

    /**
     *  Camera has no SSD.
     */
    DJISDKCameraErrorSSDError = -3019L,
    

    /**
     *  Media file is reset. The operation cannot be executed.
     */
    DJISDKCameraErrorMediaFileReset = -3020L,
    

    /**
     *  Not supported in current mode, please change to RECORD_VIDEO mode.
     */
    DJISDKCameraErrorCurrentModeNotSupported = -3021L,
    

    /**
     *  The laser sensor is too close to the target object.
     */
    DJISDKCameraErrorLaserMeasureFailedForTooClose = -3022L,
    

    /**
     *  The laser sensor is too far from the target object.
     */
    DJISDKCameraErrorLaserMeasureFailedForTooFar = -3023L,
    

    /**
     *  The laser sensor has no signal.
     */
    DJISDKCameraErrorLaserMeasureFailedForNoSignal = -3024L,
    

    /**
     *  Panorama mode cannot work until the aircraft takes off.
     */
    DJISDKCameraErrorPanoramaNotFlying = -3025L,
    

    /**
     *  The laser sensor is too close or too far away from the target object, please
     *  make sure the distance to the target object is greater than 3m.
     */
    DJISDKCameraErrorLaserMeasureFailedForTooCloseOrTooFar = -3026L,

};

/*********************************************************************************/
#pragma mark DJISDKFlightControllerError
/*********************************************************************************/


/**
 *  DJI SDK Flight Controller Error.
 */
typedef NS_ENUM (NSInteger, DJISDKFlightControllerError) {
 

    /**
     *  Mode error.
     */
    DJISDKFlightControllerErrorModeError = -4000L,
 

    /**
     *  Aircraft too close to the home point.
     */
    DJISDKFlightControllerErrorNearHomePoint = -4001L,
 

    /**
     *  Aircraft currently running a mission.
     */
    DJISDKFlightControllerErrorRunningMission = -4002L,
 

    /**
     *  Aircraft currently running virtual stick.
     */
    DJISDKFlightControllerErrorRunningVirtualStick = -4003L,
 

    /**
     *  Aircraft not in the air.
     */
    DJISDKFlightControllerErrorAircraftNotInTheAir = -4004L,
 

    /**
     *  Aircraft flight limited.
     */
    DJISDKFlightControllerErrorFlightLimited = -4005L,
 

    /**
     *  GPS level is not high enough to allow flight controller to obtain accurate
     *  location.
     */
    DJISDKFlightControllerErrorGPSSignalWeak = -4006L,
 

    /**
     *  Aircraft low battery.
     */
    DJISDKFlightControllerErrorLowBattery = -4007L,
 

    /**
     *  Aircraft home point not recorded.
     */
    DJISDKFlightControllerErrorHomePointNotRecorded = -4008L,
 

    /**
     *  Aircraft taking off.
     */
    DJISDKFlightControllerErrorTakingOff = -4009L,
 

    /**
     *  Aircraft landing.
     */
    DJISDKFlightControllerErrorLanding = -4010L,
 

    /**
     *  Aircraft going home.
     */
    DJISDKFlightControllerErrorGoingHome = -4011L,
 

    /**
     *  Aircraft starting engine.
     */
    DJISDKFlightControllerErrorStartingEngine = -4012L,
 

    /**
     *  Aircraft in a no fly zone.
     */
    DJISDKFlightControllerErrorInNoFlyZone = -4013L,
 

    /**
     *  Command can not be executed because the motors started.
     */
    DJISDKFlightControllerErrorMotorsStarted = -4013L,
 

    /**
     *  Aircraft could not enter transport mode, since the gimbal is still connected.
     */
    DJISDKFlightControllerErrorGimbalNotRemoved = -4014L,
 

    /**
     *  The aircraft is flying. For safety consideration, the motors could not be shut
     *  down.
     */
    DJISDKFlightControllerErrorCannotTurnOffMotorsWhileAircraftFlying = -4015L,
 

    /**
     *  The new home point is too far.
     */
    DJISDKFlightControllerErrorHomePointTooFar = -4016L,
 

    /**
     *  The new home altitude is too low. (Lower than 20m).
     */
    DJISDKFlightControllerErrorGoHomeAltitudeTooLow = -4017L,
 

    /**
     *  The new home altitude is too high. (higher than 500m).
     */
    DJISDKFlightControllerErrorGoHomeAltitudeTooHigh = -4018L,
 

    /**
     *  The remote controller's mode switch is not in correct mode.
     */
    DJISDKFlightControllerErrorRemoteControllerModeError = -4019L,
 

    /**
     *  The virtual stick control mode is not available.
     */
    DJISDKFlightControllerErrorVirtualStickControlModeError = -4020L,
 

    /**
     *  The aircraft is not at auto landing state.
     */
    DJISDKFlightControllerErrorAircraftNotAutoLanding = -4021L,
 

    /**
     *  The aircraft is not at go home state.
     */
    DJISDKFlightControllerErrorAircraftNotGoingHome = -4022L,
 

    /**
     *  RTK cannot start properly. Please reboot.
     */
    DJISDKFlightControllerErrorRTKCannotStart = -4023L,
 

    /**
     *  Connection between base station and mobile station is broken.
     */
    DJISDKFlightControllerErrorRTKConnectionBroken = -4024L,
 

    /**
     *  RTK base station antenna error. Check if the antenna is connected to the correct
     *  port.
     */
    DJISDKFlightControllerErrorRTKBSAntennaError = -4025L,
 

    /**
     *  RTK base station's coordinate resets.
     */
    DJISDKFlightControllerErrorRTKBSCoordinatesReset = -4026L,
 

    /**
     *  Illegal battery.
     */
    DJISDKFlightControllerErrorIllegalBattery = -4027L,
 

    /**
     *  Aircraft is in tripod mode.
     */
    DJISDKFlightControllerErrorInTripodMode = -4028L,
    

    /**
     *  Base station internal error. Parameter numbers do not match. Please contact <dev@dji.com>.
     */
    DJISDKFlightControllerErrorRTKBasestationParameterNumberNotMatch = -4029L,
    

    /**
     *  Base station internal error. Parameters' length do not match. Please contact <dev@dji.com>.
     */
    DJISDKFlightControllerErrorRTKBasestationParameterLengthNotMatch = -4030L,


    /**
     *  Base station internal error. Parameters read only. Please contact
     *  <https://djisdksupport.zendesk.com/hc/requests/new>.
     */
    DJISDKFlightControllerErrorRTKBasestationParameterReadOnly = -4031L,


    /**
     *  Base station parameters internal error. Please contact
     *  <https://djisdksupport.zendesk.com/hc/requests/new>.
     */
    DJISDKFlightControllerErrorRTKBasestationParameterUnknownError = -4032L,
    

    /**
     *  The base station isn't activated.
     */
    DJISDKFlightControllerErrorBaseStationNotActivated = -4033L,
    

    /**
     *  The base station is moved. Land the aircraft to re-establish the connection to
     *  the ground station.
     */
    DJISDKFlightControllerErrorBaseStationIsMoved = -4034L,
    

    /**
     *  The base station fell. Land the aircraft to re-establish the connection to the
     *  base station.
     */
    DJISDKFlightControllerErrorBaseStationFell = -4035L,
    

    /**
     *  The aircraft cannot start the gravity center calibration because it is not
     *  flying.
     */
    DJISDKFlightControllerErrorGravityCenterCalibrationNotFlying = -4036L,
    

    /**
     *  The aircraft cannot start the gravity center calibration because the simulator
     *  starts.
     */
    DJISDKFlightControllerErrorGravityCenterCalibrationCanNotWorkInSimulator = -4037L,
    

    /**
     *  The aircraft cannot start the gravity center calibration before the previous
     *  calibration finishes.
     */
    DJISDKFlightControllerErrorGravityCenterCalibrationIsRunning = -4038L,
    

    /**
     *  The aircraft cannot start the gravity center calibration because it is not
     *  hovering.
     */
    DJISDKFlightControllerErrorGravityCenterCalibrationNotHovering = -4039L,
    

    /**
     *  The gravity center calibration is stopped by the user.
     */
    DJISDKFlightControllerErrorGravityCenterCalibrationStoppedByUser = -4040L,
    

    /**
     *  The gravity center calibration is interrupted because the wind is too strong.
     */
    DJISDKFlightControllerErrorGravityCenterCalibrationFailedInBigWind = -4041L,
    

    /**
     *  The command cannot be executed with the current attitude.
     */
    DJISDKFlightControllerErrorCannotBeExecutedWithCurrentAttitude = -4042L,


    /**
     *  For Matrice 300 RTK, you must login before you can set name, or use
     *  `setBaseStationReferencingLocation:withCompletion` etc.
     */
    DJISDKFlightControllerErrorRTKBasestationNeedLogin = -4043L,
    

    /**
     *  Base station administrator account password is invalid. Please login again. If
     *  you reset your password, please use the default password.
     */
    DJISDKFlightControllerErrorRTKBasestationPasswordInvalid = -4044L,
    

    /**
     *  The selection of navigation satellite system is only supported when the RTK
     *  function is turned off, and cannot be modified in the air.
     */
    DJISDKFlightControllerErrorNavigationSatelliteSystemCanNotSet = -4045L,
    
    /// 刷新返航点失败 --  未知原因
    DJISDKFlightControllerErrorSetHomeLocationUnknownReason = -4036L,
    
    /// 刷新返航点失败 --  不合法的GPS
    DJISDKFlightControllerErrorSetHomeLocationInvalidGpsCoordinate = -4037L,
    
    /// 刷新返航点失败 --  飞控尚未自动记录HOME点
    DJISDKFlightControllerErrorSetHomeLocationHomepointNotBeRecord = -4038L,
    
    /// 刷新返航点失败 --  gps信号不足(level < 4) 无法设置
    DJISDKFlightControllerErrorSetHomeLocationGpsNotReady = -4039L,
    
    /// 刷新返航点失败 --  home点和飞机过远(>20km)
    DJISDKFlightControllerErrorSetHomeLocationDistanceTooFar = -4040L
};

/*********************************************************************************/
#pragma mark DJISDKMissionError
/*********************************************************************************/


/**
 *  DJI SDK Mission Error.
 */
typedef NS_ENUM (NSInteger, DJISDKMissionError){


    /**
     *  Cannot execute in the current mode. For products and flight controller firmware
     *  versions that support 'F' mode (e.g. Phantom 3 Professional, Inspire 1, A3 with
     *  flight controller firmware version lower than 3.2.10.0, etc), please make sure
     *  the remote controller's mode switch is in 'F' mode. For the others, please make
     *  sure the remote controller's mode switch is in 'P' mode.
     */
    DJISDKMissionErrorModeError = -5000L,
 

    /**
     *  The GPS signal of the aircraft is weak.
     */
    DJISDKMissionErrorGPSSignalWeak = -5001L,
 

    /**
     *  Low battery level warning.
     */
    DJISDKMissionErrorAircraftLowBattery = -5002L,
 

    /**
     *  The aircraft is not in the air.
     */
    DJISDKMissionErrorAircraftNotInTheAir = -5003L,
 

    /**
     *  The aircraft's altitude is too high.
     */
    DJISDKMissionErrorAircraftAltitudeTooHigh = -5004L,
 

    /**
     *  The aircraft's altitude is too low.
     */
    DJISDKMissionErrorAircraftAltitudeTooLow = -5005L,
 

    /**
     *  Aircraft is taking off.
     */
    DJISDKMissionErrorAircraftTakingOff = -5006L,
 

    /**
     *  Aircraft is landing.
     */
    DJISDKMissionErrorAircraftLanding = -5007L,
 

    /**
     *  Aircraft is going home.
     */
    DJISDKMissionErrorAircraftGoingHome = -5008L,
 

    /**
     *  Aircraft is starting engine.
     */
    DJISDKMissionErrorAircraftStartingEngine = -5009L,
 

    /**
     *  The home point of the aircraft is not recorded.
     */
    DJISDKMissionErrorAircraftHomePointNotRecorded = -5010L,
 

    /**
     *  Aircraft lost the follow target.
     */
    DJISDKMissionErrorAircraftLostFollowMeTarget = -5011L,
 

    /**
     *  Aircraft is in novice mode.
     */
    DJISDKMissionErrorAircraftInNoviceMode = -5012L,
 

    /**
     *  Aircraft is in a no fly zone.
     */
    DJISDKMissionErrorAircraftInNoFlyZone = -5013L,
 

    /**
     *  The aircraft has reached the flight limitation.
     */
    DJISDKMissionErrorReachFlightLimitation = -5014L,
 

    /**
     *  The aircraft is running a mission.
     */
    DJISDKMissionErrorAircraftRunningMission = -5015L,
 

    /**
     *  Aircraft is not running a mission.
     */
    DJISDKMissionErrorAircraftNoRunningMission = -5016L,
 

    /**
     *  No aircraft mission.
     */
    DJISDKMissionErrorAircraftNoMission = -5017L,
 

    /**
     *  Aircraft is too close to the home point.
     */
    DJISDKMissionErrorAircraftNearHomePoint = -5018L,
 

    /**
     *  Aircraft is too far away from the mission.
     */
    DJISDKMissionErrorAircraftFarAwayMission = -5019L,
 

    /**
     *  The parameters of the mission are invalid.
     */
    DJISDKMissionErrorMissionParametersInvalid = -5020L,
 

    /**
     *  Mission's total distance is too large.
     */
    DJISDKMissionErrorMissionTotalDistanceTooLarge = -5021L,
 

    /**
     *  Mission needs too much time to execute.
     */
    DJISDKMissionErrorMissionNeedTooMuchTime = -5022L,
 

    /**
     *  Mission resume failed.
     */
    DJISDKMissionErrorMissionResumeFailed = -5023L,
 

    /**
     *  Command can not be executed. This is sometimes because commands are sent too
     *  frequently.
     */
    DJISDKMissionErrorCommandCanNotExecute = -5024L,
 

    /**
     *  Aircraft already in command state. Repeating the same command results in this
     *  error.
     */
    DJISDKMissionErrorAircraftAlreadyInCommandState = -5025L,
 

    /**
     *  Mission not prepared.
     */
    DJISDKMissionErrorMissionNotReady = -5026L,
 

    /**
     *  Custom mission step can not be paused.
     */
    DJISDKMissionErrorCustomMissionStepCannotPause = -5027L,
 

    /**
     *  Custom mission is not initialized with the mission steps.  The Steps array is
     *  empty.
     */
    DJISDKMissionErrorCustomMissionStepsNotInitialized = -5028L,
 

    /**
     *  Current mission step is initializing.
     */
    DJISDKMissionErrorCustomMissionStepInitializing = -5029L,
 

    /**
     *  The tracking target is lost.
     */
    DJISDKMissionErrorTrackingTargetLost = -5030L,
 

    /**
     *  No live video feed is captured for the ActiveTrack Mission.
     */
    DJISDKMissionErrorNoVideoFeed = -5031L,
 

    /**
     *  The frame rate of the live video feed is too low.
     */
    DJISDKMissionErrorVideoFrameRateTooLow = -5032L,
 

    /**
     *  The vision system cannot get the authorization to control the aircraft.
     */
    DJISDKMissionErrorVisionSystemNotAuthorized = -5033L,
 

    /**
     *  The vision system encounters system error.
     */
    DJISDKMissionErrorVisionSystemError = -5034L,
 

    /**
     *  The aircraft cannot bypass the obstacle.
     */
    DJISDKMissionErrorCannotBypassObstacle = -5035L,
 

    /**
     *  Mission was stopped by the user.
     */
    DJISDKMissionErrorStoppedByUser = -5036L,
 

    /**
     *  The vision system requires calibration.
     */
    DJISDKMissionErrorVisionSystemNeedsCalibration = -5037L,
 

    /**
     *  The vision sensors are overexposed.
     */
    DJISDKMissionErrorVisionSensorOverexposed = -5038L,
 

    /**
     *  The vision sensors are underexposed.
     */
    DJISDKMissionErrorVisionSensorUnderexposed = -5039L,
 

    /**
     *  The data from the vision system is abnormal.
     */
    DJISDKMissionErrorVisionDataAbnormal = -5040L,
 

    /**
     *  The feature points found by both vision sensors cannot match.
     */
    DJISDKMissionErrorFeaturePointCannotMatch = -5041L,
 

    /**
     *  The tracking rectangle is too small.
     */
    DJISDKMissionErrorTrackingRectTooSmall = -5042L,
 

    /**
     *  The tracking rectangle is too large.
     */
    DJISDKMissionErrorTrackingRectTooLarge = -5043L,
 

    /**
     *  The tracking target doesn't have enough features to lock onto.
     */
    DJISDKMissionErrorTrackingTargetNotEnoughFeatures = -5044L,
 

    /**
     *  The Tracking target is too close to the aircraft.
     */
    DJISDKMissionErrorTrackingTargetTooClose = -5045L,
 

    /**
     *  The tracking target is too far away from the aircraft.
     */
    DJISDKMissionErrorTrackingTargetTooFar = -5046L,
 

    /**
     *  The tracking target is too high.
     */
    DJISDKMissionErrorTrackingTargetTooHigh = -5047L,
 

    /**
     *  The tracking target is shaking too much.
     */
    DJISDKMissionErrorTrackingTargetShaking = -5048L,
 

    /**
     *  The ActiveTrack mission is too unsure the tracking object and confirmation is
     *  required.
     */
    DJISDKMissionErrorTrackingTargetLowConfidence = -5049L,
 

    /**
     *  Mission is paused by user.
     */
    DJISDKMissionErrorTrackingPausedByUser = -5050L,
 

    /**
     *  Gimbal pitch is too low.
     */
    DJISDKMissionErrorGimbalPitchTooLow = -5051L,
 

    /**
     *  Gimbal pitch is too large.
     */
    DJISDKMissionErrorGimbalPitchTooLarge = -5052L,
 

    /**
     *  Encounter an obstacle.
     */
    DJISDKMissionErrorTrackingObstacleDetected = -5053L,
 

    /**
     *  TapFly direction invalid.
     */
    DJISDKMissionErrorTapFlyDirectionInvalid = -5054L,
 

    /**
     *  The front vision system is not available.
     */
    DJISDKMissionErrorVisionSystemNotAvailable = -5055L,
 

    /**
     *  The initialization of the mission failed.
     */
    DJISDKMissionErrorInitializationFailed = -5056L,
 

    /**
     *  Mission can not pause or resume.
     */
    DJISDKMissionErrorCannotPauseOrResume = -5057L,
 

    /**
     *  The aircraft reaches the altitude lower bound of the TapFly Mission.
     */
    DJISDKMissionErrorReachAltitudeLowerBound = -5058L,
 

    /**
     *  RTK's signal is weak.
     */
    DJISDKMissionErrorRTKSignalWeak = -5059L,


    /**
     *  Aircraft's landing gear is deployed.
     */
    DJISDKMissionErrorLandingGearDeployed = -5060L,


    /**
     *  The mission cannot start when multi-mode is disabled.
     */
    DJISDKMissionErrorMultiModeDisabled = -5061L,
    

    /**
     *  Max Flight speed value provided is invalid.
     */
    DJISDKWaypointMissionParameterErrorMaxFlightSpeed = -5100L,


    /**
     *  Auto flight speed value provided is invalid.
     */
    DJISDKWaypointMissionParameterErrorAutoFlightSpeed = -5101L,
    

    /**
     *  Repeat time value provided is invalid.
     */
    DJISDKWaypointMissionParameterErrorRepeatTime = -5102L,
    

    /**
     *  Waypoint count exceeds the maximum limit.
     */
    DJISDKWaypointMissionParameterErrorWaypointCount = -5103L,

    

    /**
     *  Waypoint mission is absent from the operator (upload failed somehow).
     */
    DJISDKWaypointMissionAbsentError = -5110L,
    

    /**
     *  Waypoint coordinate provided is invalid.
     */
    DJISDKWaypointParameterErrorCoordinate = -5120L,
    

    /**
     *  Waypoint altitude provided is invalid.
     */
    DJISDKWaypointParameterErrorAltitude = -5121L,
    

    /**
     *  Waypoint heading provided is invalid.
     */
    DJISDKWaypointParameterErrorHeading = -5122L,
    

    /**
     *  Waypoint repeat time provided is invalid.
     */
    DJISDKWaypointParameterErrorActionRepeatTime = -5123L,
    

    /**
     *  Waypoint action timeout provided is invalid.
     */
    DJISDKWaypointParameterErrorActionTimeout = -5124L,
    

    /**
     *  Waypoint corner radius provided is invalid.
     */
    DJISDKWaypointParameterErrorCornerRadius = -5125L,
    

    /**
     *  Waypoint gimbal pitch provided is invalid.
     */
    DJISDKWaypointParameterErrorGimbalPitch = -5126L,
    

    /**
     *  Waypoint speed provided is invalid.
     */
    DJISDKWaypointParameterErrorSpeed = -5127L,
    

    /**
     *  Waypoint shoot photo distance provided is invalid.
     */
    DJISDKWaypointParameterErrorShootPhotoDistance = -5128L,
    

    /**
     *  Waypoint stay action param provided is invalid.
     */
    DJISDKWaypointParameterErrorStayActionParam = -5129L,
    

    /**
     *  Waypoint rotate gimbal action param provided is invalid.
     */
    DJISDKWaypointParameterErrorRotateGimbalActionParam = -5130L,
    

    /**
     *  Waypoint rotate aircraft action param provided is invalid.
     */
    DJISDKWaypointParameterErrorRotateAircraftActionParam = -5131L,
    

    /**
     *  Waypoint indecies are discontinuous.
     */
    DJISDKWaypointParameterErrorIndeciesAreDiscontinuous = -5132L,
    

    /**
     *  Waypoint index out of range.
     */
    DJISDKWaypointParameterErrorIndexOutOfRange = -5133L,


    /**
     *  Waypoint data size is invalid. It is for internal usage.
     */
    DJISDKWaypointParameterErrorInvalidDataSize = -5134L,
    

    /**
     *  The aircraft cannot take off because of improper aircraft's attitude.
     */
    DJISDKWaypointParameterErrorTakeoffFailureCausedByAttitude = -5135L,
    

    /**
     *  The time interval or the distance interval is invalid.
     */
    DJISDKWaypointParameterErrorInvalidIntervalShootParam = -5136L,
    

    /**
     *  The waypoint mission interruption is not available because the last mission
     *  completed successfully.
     */
    DJISDKWaypointGetInterruptionFailureForCompleteMission = -5137L,
    

    /**
     *  The waypoint mission interruption is not available because the aircraft didn't
     *  reach the first waypoint in the last mission.
     */
    DJISDKWaypointGetInterruptionFailureWithoutReachingFirstWaypoint = -5138L,
    

    /**
     *  System error, please try again. If the error continues, restart the aircraft.
     */
    DJISDKHotpointErrorSystemAbnormal = -5301L,
    

    /**
     *  Frame selection subject too small.
     */
    DJISDKHotpointErrorTargetAreaIsTooSmall = -5302L,
    

    /**
     *  Frame selection subject texture not obvious.
     */
    DJISDKHotpointErrorInsufficientFeaturesInTargetArea = -5303L,
    

    /**
     *  Tracking subject lost while watching.
     */
    DJISDKHotpointErrorLostTargetWhileWatching = -5304L,
    

    /**
     *  Tracking subject lost while executing.
     */
    DJISDKHotpointErrorLostTargetWhileExecuting = -5305L,
    

    /**
     *  Failed to estimate, please try again.
     */
    DJISDKHotpointErrorReprojectionFailedWhileExecuting = -5306L,
    

    /**
     *  Frame subject too close.
     */
    DJISDKHotpointErrorTargetTooClose = -5307L,
    

    /**
     *  Target size changed, please try again. If the error persists, restart the
     *  aircraft.
     */
    DJISDKHotpointErrorTargetSizeChanged = -5308L,
    

    /**
     *  GPS signal weak. Please try again in an open area.
     */
    DJISDKHotpointErrorGPSAbnormal = -5309L,
    

    /**
     *  Hotpoint parameter do not meet requirements.
     */
    DJISDKHotpointErrorHotpointInvalid = -5310L,
    

    /**
     *  Gimbal reached movement limit, subjecting failed. Please try again.
     */
    DJISDKHotpointErrorWatchTargetFailed = -5311L,
    

    /**
     *  Estimate timeout, mission exit.
     */
    DJISDKHotpointErrorEstimateTimeout = -5312L,
    

    /**
     *  Failed to estimate subject location.
     */
    DJISDKHotpointErrorEstimateResultInvalid = -5313L,
    

    /**
     *  Current mission exit by user button.
     */
    DJISDKHotpointErrorExitByUserButton = -5314L,
    

    /**
     *  The aircraft reach the distance limit. Please operate the aircraft within the
     *  distance limit.
     */
    DJISDKHotpointErrorRadiusLimit = -5315L,
    

    /**
     *  The aircraft reach the altitude limit. Please operate the aircraft within the
     *  Altitude limit.
     */
    DJISDKHotpointErrorAlitudeLimit = -5316L,
    

    /**
     *  Intelligent Hotpoint mission execute failed, the description is the fail reason.
     */
    DJISDKHotpointErrorControlFailed = -5317L,


    /**
     *  Lost connection with remoteController.
     */
    DJISDKHotpointErrorLostConnectionWithRemoteController = -5318L,


    /**
     *  Obstacles encountered while estimating, current mission quitted.
     */
    DJISDKHotpointErrorObstacleEncounteredWhileEstimating = -5319L,


    /**
     *  Obstacles encountered while surrounding, current mission suspended.
     */
    DJISDKHotpointErrorObstacleEncounteredWhileSurrounding = -5320L,
    

    /**
     *  Target is too faraway, the aircraft needs to continue to measure distance.
     */
    DJISDKHotpointErrorTargetIsTooFaraway  = -5321L,
    

    /**
     *  Aircraft's altitude is too low to execute hotpoint mission.
     */
    DJISDKHotpointErrorAltitudeTooLow = -5322L,

};
/*********************************************************************************/
#pragma mark GEO Error
/*********************************************************************************/


/**
 *  DJI SDK GEO Error.
 */
typedef NS_ENUM(NSInteger, DJISDKFlySafeError){
 

    /**
     *  User is not logged in.
     */
    DJISDKFlySafeErrorNotLoggedIn = -6001L,
 

    /**
     *  The operation is cancelled.
     */
    DJISDKFlySafeErrorOperationCancelled = -6002L,
 

    /**
     *  Aircraft's location is not available.
     */
    DJISDKFlySafeErrorAircraftLocationNotAvailable = -6003L,
 

    /**
     *  Aircraft's serial number is not available.
     */
    DJISDKFlySafeErrorAircraftSerialNumberNotAvailable = -6004L,
 

    /**
     *  The token is invalid.
     */
    DJISDKFlySafeErrorInvalidToken = -6005L,
 

    /**
     *  User is not authorized.
     */
    DJISDKFlySafeErrorNotAuthorized = -6006L,
 

    /**
     *  Data returned by server is invalid.
     */
    DJISDKFlySafeErrorInvalidServerData = -6007L,
 

    /**
     *  The system is still initializing.
     */
    DJISDKFlySafeErrorInitializationNotFinished = -6008L,
 

    /**
     *  Aircraft's location does not support GEO.
     */
    DJISDKFlySafeErrorNotSupportGEO = -6009L,
 

    /**
     *  This area is not eligible for unlocking.
     */
    DJISDKFlySafeErrorAreaNotEligibleUnlock = -6010L,
 

    /**
     *  This enum value is deprecated. The simulated aircraft location is not valid.
     *  During the simulation, a location is valid if it is within 50km of (37.460484,
     *  -122.115312).
     */
	DJISDKFlySafeErrorInvalidSimulatedLocation = -6011L,
    

    /**
     *  The Account login is out of date, Need login again.
     */
    DJISDKFlySafeErrorTokenOutOfDate = -6012L,
    

    /**
     *  Package error, time out when waiting for the Ack package from the drone.
     */
    DJISDKFlySafeErrorPackManagerTimeout = -6013L,
    

    /**
     *  Unlock error, unlock version from the drone should be "0, 1, or 2".
     */
    DJISDKFlySafeErrorPackManagerWrongUnlockVersion = -6014L,
    

    /**
     *  Send Wrong Device ID.
    */
    DJISDKFlySafeErrorPackManagerWrongDeviceID = -6015L,
    

    /**
     *  No MCSN Error.
     */
    DJISDKFlySafeErrorNoMCSN = -6016L,
    

    /**
     *  Unlock error, area ID is not exist in the license.
     */
    DJISDKFlySafeErrorInvalidAreaIds = -6017L,
    

    /**
     *  Unlock error, can't get license from the drone.
     */
    DJISDKFlySafeErrorFCQueryFailed = -6018L,
    

    /**
     *  Unlock error, can't enable license.
     */
    DJISDKFlySafeErrorFCSetEnableFailed = -6019L,
    

    /**
     *  Set enabled with invalid user id.
     */
    DJISDKFlySafeErrorSetEnableWithInvalidUserId = -6020L,
    

    /**
     *  License error, can't find the correct license.
     */
    DJISDKFlySafeErrorSetEnableWithNoExistLicense = -6021L,
    

    /**
     *  License error, incorrect length of request data.
     */
    DJISDKFlySafeErrorSetEnableVersionNotMatch = -6022L,
    

    /**
     *  License error, incorrect value of request data.
     */
    DJISDKFlySafeErrorSetEnableParamError = -6023L,
    

    /**
     *  License error, can't set license when the drone is flying.
     */
    DJISDKFlySafeErrorSetEnableDroneInSky = -6024L,
    

    /**
     *  License error, incorrect checksum.
     */
    DJISDKFlySafeErrorUploadLicenseDataUserIdError = -6025L,
    

    /**
     *  License error, wrong index please retry.
     */
    DJISDKFlySafeErrorUploadLicenseDataIndexError = -6026L,
    

    /**
     *  Upload license data with error data.
     */
    DJISDKFlySafeErrorUploadLicenseDataError = -6027L,
    

    /**
     *  License error, incorrect crc.
     */
    DJISDKFlySafeErrorUploadLicenseDataCrcCheckFailed = -6028L,
    

    /**
     *  SLicense error, incorrect serial number.
     */
    DJISDKFlySafeErrorUploadLicenseDataSNCheckFailed = -6029L,
    

    /**
     *  License error, wrong version, please try to update the firmware of the drone.
     */
    DJISDKFlySafeErrorUploadLicenseDataVersionCheckError = -6030L,
    

    /**
     *  License error, can't update license when the drone is flying.
     */
    DJISDKFlySafeErrorUploadLicenseDataDroneInSky = -6031L,
    

    /**
     *  Unlock error, not supported by the drone.
     */
    DJISDKFlySafeErrorLicenseUnlockNotSupported = -6032L,
    

    /**
     *  License error, can't delete license when the drone is flying.
     */
    DJISDKFlySafeErrorRemoveLicensesFailedForAircraftInAir = -6033L,
    

    /**
     *  License error, not supported by the drone.
     */
    DJISDKFlySafeErrorRemoveLicensesNotSupport = -6034L,
    

    /**
     *  License error, no data.
     */
    DJISDKFlySafeErrorNoDataError = -6035L,
    

    /**
     *  License error, please update the firmware of the drone.
     */
    DJISDKFlySafeErrorLowFirwareVersionError = -6036L,
    

    /**
     *  License error, invalid key version.
     */
    DJISDKFlySafeErrorInvalidKeyVersionError = -6037L,
    

    /**
     *  License error, license ID is not exist.
     */
    DJISDKFlySafeErrorQueryAreaIdNoExistLicenseError = -6038L,
    

    /**
     *  Server error, invalid token.
     */
    DJISDKFlySafeErrorInvalidTokenOnServerError = -6039L,
    

    /**
     *  Server error, unknown phone.
     */
    DJISDKFlySafeErrorUnidentifiedPhone = -6040L,
    

    /**
     *  Server error, invalid area.
     */
    DJISDKFlySafeErrorUnlockNotUnlockableArea = -6041L,
    

    /**
     *  Server error, too many areas.
     */
    DJISDKFlySafeErrorUnlockTooManyAreas = -6042L,
    

    /**
     *  Server error, too many licenses.
     */
    DJISDKFlySafeErrorTooMuchLicense = -6043L,
    

    /**
     *  Network error, invalid network.
     */
    DJISDKFlySafeErrorNoNetwork = -6044L,
    

    /**
     *  Network error, data parsing failed in server.
     */
    DJISDKFlySafeErrorNetworkServerDataError = -6045L,
    

    /**
     *  Network error, invalid signature.
     */
    DJISDKFlySafeErrorNetworkSignatureError = -6046L,
    

    /**
     *  Network error, invalid signature (deprecated).
     */
    DJISDKFlySafeErrorNetworkCheckServerSignatureError = -6047L,
    

    /**
     *  Network error, invalid request.
     */
    DJISDKFlySafeErrorNetworkInvalidRequeset = -6048L,
    

    /**
     *  Network error, user is not login.
     */
    DJISDKFlySafeErrorNetworkUserIsNotLogin = -6049L,
    

    /**
     *  Network error, canceled by user(deprecated).
     */
    DJISDKFlySafeErrorNetworkOperationCancelByUser = -6050L,
    

    /**
     *  Network error, invalid token.
     */
    DJISDKFlySafeErrorLocalUserTokenIsInvalid = -6051L,
    

    /**
     *  Network error, page not found(deprecated).
     */
    DJISDKFlySafeErrorNetworkPageNotFound = -6052L,
    

    /**
     *  Package error, wrong serial number of the drone.
     */
    DJISDKFlySafeErrorPackManagerWrongSerialNumber = -6053L,
    

    /**
     *  Database error, can't unzip the database.
     */
    DJISDKFlySafeErrorDataBaseFileError = -6054L,
    

    /**
     *  Database error, invalid parameters when updating database.
     */
    DJISDKFlySafeErrorDataBaseInvalidParams = -6055L,
    

    /**
     *  Database error, load database fail.
     */
    DJISDKFlySafeErrorDataBaseNotReady = -6056L,
    

    /**
     *  License error, local data is obsolete.
     */
    DJISDKFlySafeErrorOldDataError = -6057L,
    

    /**
     *  Server error, incorrect Json data.
     */
    DJISDKFlySafeErrorServerJsonDataParseError = -6058L,
    

    /**
     *  Unlock error, incorrect unlock version.
     */
    DJISDKFlySafeErrorUnlockVersionError = -6059L,
};

/*********************************************************************************/
#pragma mark FlightHub Error
/*********************************************************************************/


/**
 *  DJI SDK FlightHub Error.
 */
typedef NS_ENUM(NSInteger, DJISDKFlightHubError){

	/**
	 *  Server rejected the request because the signature is invalid.
	 */
	DJISDKFlightHubErrorSignatureInvalid = -7001L,

	/**
	 *  Server rejected the request because the user does not have the permission.
	 */
	DJISDKFlightHubErrorNoRightToAccess = -7002L,

	/**
	 *  Invalid parameter(s).
	 */
	DJISDKFlightHubErrorParametersInvalid = -7003L,

	/**
	 *  No authorization information found.
	 */
	DJISDKFlightHubErrorNoAuthorizationInformationFound = -7004L,

	/**
	 *  The account information is not found.
	 */
	DJISDKFlightHubErrorUserNotFoundInUserCenter = -7005L,

	/**
	 *  Authorization information has expired. Please authorize again.
	 */
	DJISDKFlightHubErrorAuthorizationExpired = -7006L,

	/**
	 *  User not found in DJI FlightHub system.
	 */
	DJISDKFlightHubErrorUserNotFoundInFlightHub = -7007L,

	/**
	 *  The service package has been expired.
	 */
	DJISDKFlightHubErrorServicePackageExpired = -7008L,

	/**
	 *  The service package has reached the limit of device numbers.
	 */
	DJISDKFlightHubErrorServicePackageLimitationReached = -7009L,

	/**
	 *  The service package does not have permission to access SDK service.
	 */
	DJISDKFlightHubErrorUserHasNoSDKPermissionForServicePackage = -7010L,

	/**
	 *  No team found.
	 */
	DJISDKFlightHubErrorNoTeamFound = -7011L,

	/**
	 *  No aircraft found.
	 */
	DJISDKFlightHubErrorNoAircraftFound = -7012L,

	/**
	 *  The aircraft has already been bound in the chosen team.
	 */
	DJISDKFlightHubErrorAircraftAlreadyBoundInTeamChosen = -7013L,

	/**
	 *  No record found.
	 */
	DJISDKFlightHubErrorNoRecordFound = -7014L,

	/**
	 *  No user is logged in.
	 */
	DJISDKFlightHubErrorNotLoggedIn = -7015L,

	/**
	 *  Aircraft's serial number is not available.
	 */
	DJISDKFlightHubErrorAircraftSerialNumberNotAvailable = -7016L,

	/**
	 *  The aircraft has already been bound in the other team. Please unbind it first.
	 */
	DJISDKFlightHubErrorAircraftAlreadyBoundInTeamChosenInOtherTeam = -7017L,

	/**
	 *  Bound device number has reached the limit of your service package.
	 */
	DJISDKFlightHubErrorBoundDeviceLimitationReached = -7018L,

    /**
     *  SDK does not have authorization to access hardware information.
     */
    DJISDKFlightHubErrorNoHardwareInfoAuthorization = -7019L,
};

/*********************************************************************************/
#pragma mark Take-off Action Error
/*********************************************************************************/

/**
 *  Error codes for errors specific to `DJITakeOffActionErrorDomain`.
 */
typedef NS_ENUM(NSInteger, DJITakeOffActionError) {

    /**
     *  Motors should be off before Take-off action is executed.
     */
    DJITakeOffActionErrorMotorsAlreadyOn = 100,


    /**
     *  Unknown.
     */
    DJITakeOffActionErrorUnknown = -1,
};

/*********************************************************************************/
#pragma mark RTK Error
/*********************************************************************************/

/**
 *  Errors related to RTK network services.
 */
typedef NS_ENUM(NSInteger, DJIRTKNetworkServiceError) {

    /**
     *  The authentication failed when trying to access to the server.
     */
    DJIRTKNetworkServiceErrorAuthenticationFailure = -8000L,
    

    /**
     *  Network settings are not configured yet or invalid.
     */
    DJIRTKNetworkServiceErrorInvalidSettings = -8001L,
    

    /**
     *  The service is already started. Stop it first to re-start the service.
     */
    DJIRTKNetworkServiceErrorAlreadyStarted = -8002L,
    

    /**
     *  The GPS location of the aircraft is invalid. The RTK network service requires
     *  the location of the air system.
     */
    DJIRTKNetworkServiceErrorInvalidGPSData = -8003L,
    

    /**
     *  Please choose correct reference station srouce.
     */
    DJIRTKNetworkServiceErrorIncorrectReferenceStationSource = -8004L,
    

    /**
     *  No logged in account or the login session has expired, please login DJI Account
     *  and try again.
     */
    DJIRTKNetworkServiceErrorAccountNotLoginOrExpired = -8105L,


    /**
     *  Account not activated, please contact DJI Support. Use
     *  `activateNetworkServiceWithPlanType:completion` to activate your account.
     */
    DJIRTKNetworkServiceErrorAccountUnactivated = -8106L,
    

    /**
     *  Invalid request for the RTK service. Please check if the network RTK service is
     *  purchased or activated. After purchasing, within 3 minutes, you might also get
     *  this error.
     */
    DJIRTKNetworkServiceErrorInvalidRequest = -8107L,


    /**
     *  Unable to connect to server.
     */
    DJIRTKNetworkServiceErrorServerNotReachable = -8108L,


    /**
     *  Unknown account error, please contact DJI Support.
     */
    DJIRTKNetworkServiceErrorAccountError = -8109L,
    

    /**
     *  Please add the "DJINetworkRTKHelper.framework" to the project by using Cocoapods
     *  (https://cocoapods.org/pods/DJINetworkRTKHelper) to use the network RTK.
     */
    DJIRTKNetworkServiceErrorMissingHelperFramework = -8010L,
    

    /**
     *  Cannot scan for a base station while the aircraft is flying.
     */
    DJIRTKNetworkServiceErrorStartScanFailedForAircraftIsFlying = -8011L,
};

/*********************************************************************************/
#pragma mark Accessory Error
/*********************************************************************************/


/**
 *  Errors related to accessories on the aircraft (e.g. spotlights, speakers).
 */
typedef NS_ENUM(NSInteger, DJIAccessoryAggregationError) {

    /**
     *  The accessory is not connected. Also update the implementation.
     */
    DJIAccessoryAggregationErrorNotConnected = -8000L,

    /**
     *  The file name exceeds the maximum length (20 characters).
     */
    DJIAccessoryAggregationErrorFileNameLengthInvalid = -8001L,

    /**
     *  The file name is already taken in the aircraft. Choose a different file name.
     */
    DJIAccessoryAggregationErrorFileNameDuplicated = -8002L,

    /**
     *  A file name cannot be empty.
     */
    DJIAccessoryAggregationErrorFileNameEmpty = -8003L,

    /**
     *  The file does not exist in the aircraft.
     */
    DJIAccessoryAggregationErrorFileNotExist = -8004L,

    /**
     *  An error occurs when creating the file.
     */
    DJIAccessoryAggregationErrorFileCreated = -8005L,

    /**
     *  There is no more file index available for the file.
     */
    DJIAccessoryAggregationErrorFileIndexUnavailable = -8006L,

    /**
     *  Error occurs when renaming the file.
     */
    DJIAccessoryAggregationErrorRenameFile = -8007L,

    /**
     *  The connection of the speaker is broken and data transmission cannot start.
     */
    DJIAccessoryAggregationErrorDataTransmissionDisconnection = -8008L,

    /**
     *  The data transimission operation cannot be executed in the current state.
     */
    DJIAccessoryAggregationErrorWrongDataTransmissionState = -8009L,

    /**
     *  Data validation failed. Data is corrupted during the transmission.
     */
    DJIAccessoryAggregationErrorDataCorruption = -8010L,

    /**
     *  The ongoing data transmission is cancelled.
     */
    DJIAccessoryAggregationErrorCancelledByUser = -8011L,

    /**
     *  The ongoing data transmission is interrupted by timeout error.
     */
    DJIAccessoryAggregationErrorInterruptedByTimeout = -8012L,

    /**
     *  The storage is full.
     */
    DJIAccessoryAggregationErrorStorageFull = -8013L,
};

/*********************************************************************************/
#pragma mark AccessLocker Error
/*********************************************************************************/


/**
 *  Errors related to the access locker.
 */
typedef NS_ENUM(NSInteger, DJIAccessLockerError) {

    /**
     *  The command is not valid in current state.
     */
    DJIAccessLockerErrorInvalidState = -9000L,

    /**
     *  Write failure when updating data in the firmware.
     */
    DJIAccessLockerErrorFirmwareWrite = -9001L,

    /**
     *  Read failure when accessing data in the firmware.
     */
    DJIAccessLockerErrorFirmwareRead = -9002L,

    /**
     *  The Security Code is incorrect.
     */
    DJIAccessLockerErrorSecurityCodeIncorrect = -9003L,

    /**
     *  The user account is not set up for the security feature yet.
     */
    DJIAccessLockerErrorNotSetUp = -9004L,

    /**
     *  The aircraft is already unlocked.
     */
    DJIAccessLockerErrorAlreadyUnlocked = -9005L,

    /**
     *  Attempt with wrong Security Code more than 5 times. The aircraft is disable and
     *  try again in 1 minute.
     */
    DJIAccessLockerErrorSecurityCodeIncorrectFiveTimes = -9006L,

    /**
     *  Attempt with wrong Security Code more than 20 times. The aircraft is disable and
     *  try again in 24 hours.
     */
    DJIAccessLockerErrorSecurityCodeIncorrectTwentyTimes = -9007L,

    /**
     *  The username does not exist.
     */
    DJIAccessLockerErrorUsernameNotExist = -9008L,

    /**
     *  The new security code is not valid. A valid security code should contain only
     *  numbers and letters and its length is not less than 4 characters and not longer
     *  than 8 characters.
     */
    DJIAccessLockerErrorSecurityCodeFormatInvalid = -9009L,
};


/**
 *  Errors related to the UTMISS.
 */
typedef NS_ENUM(NSInteger, DJIUTMISSError) {
    

    /**
     *  Wrong order of invoking functions. Failed to initialize.
     */
    DJIUTMISSErrorWrongFunctionOrder = -11000L,
    

    /**
     *  Failed to create database.
     */
    DJIUTMISSErrorInvalidDB = -11001L,
    

    /**
     *  Failed to insert the data. The data has been lost.
     */
    DJIUTMISSErrorCacheFailed = -11002L,
    

    /**
     *  The database is currently empty.
     */
    DJIUTMISSErrorEmptyDB = -11003L,
    

    /**
     *  Failed to upload. Request code is bigger than 299.
     */
    DJIUTMISSErrorUploadFailed = -11004L,
    

    /**
     *  Current area does not support this function.
     */
    DJIUTMISSErrorAreaNotSupport = -11005L,
    

    /**
     *  UTMISS has started already.
     */
    DJIUTMISSErrorStartedAlready = -11006L,
};


/**
 *  Errors related to the LDM.
 */
typedef NS_ENUM(NSInteger, DJILDMError) {
    

    /**
     *  Area code not available.
     */
    DJILDMErrorAreaCodeNotAvailable = - 12000L,
    

    /**
     *  Network access failed.
     */
    DJILDMErrorNetworkAccessFailed = - 12001L,

    /**
     *  Signature error.
     */
    DJILDMErrorSignError = -12002L,
    

    /**
     *  LDM is not supported in the current area.
     */
    DJILDMErrorAreaCodeRestricted = -12003L,
    

    /**
     *  App does not exist.
     */
    DJILDMErrorAppNotFound = -12004L,
    

    /**
     *  No valid LDM certificate exists.
     */
    DJILDMErrorLDMLicenseNotValid = -12005L,
    

    /**
     *  Client's current time is invalid.
     */
    DJILDMErrorClientTimeNotValid = 12006L,
    

    /**
     *  License has expired.
     */
    DJILDMErrorLicenseOutDated = -12007L,
    

    /**
     *  Only available when the Local Data Mode is enabled.
     */
    DJILDMErrorUnavailable = -12008L,
    

    /**
     *  In Local Data Mode. Network access failed!
     */
    DJILDMErrorLDMNetworkAccessFailed = -12009L,
    

    /**
     *  LDM unknown error.
     */
    DJILDMErrorLDMUnknownError = -12010L,
};


/*********************************************************************************/
#pragma mark Payload Error
/*********************************************************************************/


/**
 *  Errors related to the payload.
 */
typedef NS_ENUM(NSInteger, DJIPayloadError) {
    

    /**
     *  The format of widget configuration is invalid.
     */
    DJIPayloadErrorInvalidFormatOfWidgetConfiguration = -11000L,
    

    /**
     *  The command cannot be executed in current payload mode. See
     *  `DJIPayloadProductPhase`.
     */
    DJIPayloadErrorCommandCannotBeExecutedInCurrentMode = -11001L,
    

    /**
     *  Device does not support this method, it can connect the aircraft automatically.
     */
    DJIPayloadErrorCommandDeviceShouldUsePayloadInterface = -11002L,
};


/*********************************************************************************/
#pragma mark Upgrade Error
/*********************************************************************************/


/**
 *  Errors related to the upgrade.
 */
typedef NS_ENUM(NSInteger, DJIUpgradeError) {

    /**
     *  Cannot upgrade when using `DJIWiFiLink`.
     */
    DJIUpgradeErrorInWifiLink = 10000,
    

    /**
     *  Versions are consistent. No need to upgrade.
     */
    DJIUpgradeErrorDoNotNeedConsistentUpgrade = 10001,
};

/*********************************************************************************/
#pragma mark WaypointV2 Error
/*********************************************************************************/


/**
 *  Errors related to the payload.
 */
typedef NS_ENUM(NSInteger, DJIWaypointV2Error) {    

    /**
     *  The mission waypoint count is larger than max waypoint count 65535.
     */
    DJIWaypointV2ErrorMissionCountOverRange = 9001L,
    

    /**
     *  The mission waypoint count is less than min waypoint count 2.
     */
    DJIWaypointV2ErrorMissionCountTooFew = 9002L,
    

    /**
     *  The mission `maxFlightSpeed` is greater than 15m/s or less than 2m/s. See
     *  `maxFlightSpeed`.
     */
    DJIWaypointV2ErrorMissionMaxFlightSpeedInvalid = 9003L,
    

    /**
     *  The mission `autoFlightSpeed` is greater than `maxFlightSpeed`.
     */
    DJIWaypointV2ErrorMissionAutoFlightSpeedInvalid = 9004L,
    

    /**
     *  The mission `gotoFirstWaypointMode` is out of range of
     *  `DJIWaypointV2MissionGotoFirstWaypointMode`.
     */
    DJIWaypointV2ErrorMissionGotoFirstWaypointModeInvalid = 9005L,
    

    /**
     *  The mission `finishedAction` is out of range of
     *  `DJIWaypointV2MissionFinishedAction`.
     */
    DJIWaypointV2ErrorMissionFinishedActionInvalid = 9006L,
    

    /**
     *  The mission `exitMissionOnRCSignalLost` is invalid.
     */
    DJIWaypointV2ErrorMissionExitMissionOnRCSignalLostInvalid = 9007L,
    

    /**
     *  There is already a mission executing when trying to upload a new mission.
     */
    DJIWaypointV2ErrorMissionAlreadyExecuting = 9008,
    

    /**
     *  The upload waypoint count is bigger than mission waypoint count.
     */
    DJIWaypointV2ErrorUploadWaypointCountOverMissionWaypointCount = 9009L,
        

    /**
     *  Waypoint is too close to two adjacent waypoints. The min distance is 0.5m.
     */
    DJIWaypointV2ErrorMissionWaypointDistanceTooClose = 9010L,
    

    /**
     *  Waypoint is too far from two adjacent waypoints, The max distance is 5km.
     */
    DJIWaypointV2ErrorMissionWaypointDistanceToFar = 9011L,
    

    /**
     *  The upload waypoints have a `maxFlightSpeed` is greater than `maxFlightSpeed`
     *  waypoint.
     */
    DJIWaypointV2ErrorMissionWaypointMaxFlightSpeedOverMissionMaxFlightSpeed = 9012L,
    

    /**
     *  The upload waypoint has a `autoFlightSpeed` is greater than `maxFlightSpeed`
     *  waypoint.
     */
    DJIWaypointV2ErrorWaypointAutoFlightSpeedOverWaypointMaxFlightSpeed = 9013L,
    

    /**
     *  The upload waypoints have a  `autoFlightSpeed` is greater than `maxFlightSpeed`
     *  waypoint.
     */
    DJIWaypointV2ErrorWaypointAutoFlightSpeedOverMissionMaxFlightSpeed = 9014L,
    

    /**
     *  The waypoint `headingMode` is invalid.
     */
    DJIWaypointV2ErrorWaypointHeadingModeInvalid = 9015L,
    

    /**
     *  The waypoint `heading` is invalid. See `heading`.
     */
    DJIWaypointV2ErrorWaypointHeadingInvalid = 9016L,
    

    /**
     *  The waypoint `turnMode` is invalid.
     */
    DJIWaypointV2ErrorWaypointTurnModeInvalid = 9017L,
    

    /**
     *  The waypoint `flightPathMode` is invalid.
     */
    DJIWaypointV2ErrorWaypointFlightPathModeInvalid = 9018L,
    

    /**
     *  The waypoint `dampingDistance` is greater than or equal to the distance of
     *  adjacent waypoint.
     */
    DJIWaypointV2ErrorWaypointDampingDistanceInvalid = 9019L,
    

    /**
     *  The waypoint `flightPathMode` is invalid for last waypoint.
     */
    DJIWaypointV2ErrorLastWaypointFlightPathModeInvalid = 9020L,
    

    /**
     *  The index of upload waypoint is not continue after the stored waypoint.
     */
    DJIWaypointV2ErrorUploadWaypointIndexNotContinue = 9021L,
    

    /**
     *  The waypoint `flightPathMode` is invalid for first waypoint.
     */
    DJIWaypointV2ErrorFirstWaypointFlightPathModeInvalid = 9022L,
    

    /**
     *  The waypoint position coordinate exceeds rational range.
     */
    DJIWaypointV2ErrorWaypointCoordinateInvalid = 9023L,
    

    /**
     *  The waypoint position exceeds radius limit.
     */
    DJIWaypointV2ErrorExceedFlyingRadiusLimit = 9024L,
    

    /**
     *  The waypoint position exceeds height limit.
     */
    DJIWaypointV2ErrorExceedFlyingHeightLimit = 9025L,
    

    /**
     *  The version of the SDK doesn't match the firmware version.
     */
    DJIWaypointV2ErrorSDKVersionNotMatched = 9026L,
    

    /**
     *  The index of first and last waypoint expected to download is not in range of
     *  waypoints stored in aircraft.
     */
    DJIWaypointV2ErrorDownloadMissionRangeOverStorageCount = 9027L,
    

    /**
     *  There is no mission uploaded in aircraft.
     */
    DJIWaypointV2ErrorNoMissionUploadedInAircraft = 9028L,
    

    /**
     *  The mission info is not uploaded yet.
     */
    DJIWaypointV2ErrorDownloadWaypointNotUploaded = 9029L,
    

    /**
     *  The aircraft current position is too far away from the first waypoint.
     */
    DJIWaypointV2ErrorAircraftCurrentPostionToFirstWaypointTooFar = 9030L,
    

    /**
     *  The uploaded waypoints are too few.
     */
    DJIWaypointV2ErrorUploadedWaypointsTooFew = 9031L,
    

    /**
     *  There is no mission executing.
     */
    DJIWaypointV2ErrorNoMissionExecuting = 9032L,
    

    /**
     *  The mission has already started by calling `startMissionWithCompletion`.
     */
    DJIWaypointV2ErrorMissionAlreadyStarted = 9033L,
    

    /**
     *  The mission has already stopped by calling `stopMissionWithCompletion`.
     */
    DJIWaypointV2ErrorMissionAlreadyStopped = 9034L,
    

    /**
     *  There is no executing mission to recover when calling
     *  `recoverMissionWithCompletion`.
     */
    DJIWaypointV2ErrorNoExecutingMissionToRecover = 9035L,
    

    /**
     *  The mission has already been interrupted by calling
     *  `interruptMissionWithCompletion`.
     */
    DJIWaypointV2ErrorMissionAlreadyInterrupted = 9036L,
    

    /**
     *  There is no waypoint recorded to recover the mission when
     *  `recoverMissionWithCompletion` is called.
     */
    DJIWaypointV2ErrorRecoverNoRecordedPoint = 9037L,
    

    /**
     *  The aircraft flying status is bad.
     */
    DJIWaypointV2ErrorAircraftFlyingStatusError = 9038L,
    

    /**
     *  The aircraft home point is not recorded yet.
     */
    DJIWaypointV2ErrorAircraftStateHomePointNotRecord = 9039L,
    

    /**
     *  The aircraft GPS signal is weak.
     */
    DJIWaypointV2ErrorAircraftGPSSignalWeak = 9040L,
    

    /**
     *  The aircraft RTK is not ready.
     */
    DJIWaypointV2ErrorAircraftRTKNotReady = 9041L,
    

    /**
     *  The mission is across the no-fly zone.
     */
    DJIWaypointV2ErrorMissionCrossNoFlyZone = 9042L,
    

    /**
     *  The aircraft battery is low.
     */
    DJIWaypointV2ErrorAircraftLowBattery = 9043L,
    

    /**
     *  The uploaded action ID is duplicated.
     */
    DJIWaypointV2ErrorUploadedActionIdDuplicated = 9044L,
    

    /**
     *  There is not enough space to store actions in aircraft.
     */
    DJIWaypointV2ErrorActionStorageNotEnough = 9045L,
    

    /**
     *  Download actions failed.
     */
    DJIWaypointV2ErrorDownloadActionsFailed = 9046L,
    

    /**
     *  The upload action trigger type is invalid.
     */
    DJIWaypointV2ErrorUploadActionTriggerTypeInvalid = 9047L,
            

    /**
     *  The action associate trigger `actionAssociatedType` is invalid.
     */
    DJIWaypointV2ErrorActionAssociateTriggerTypeInvalid = 9048L,
    

    /**
     *  The action associate trigger `actionIntervalType` is invalid.
     */
    DJIWaypointV2ErrorActionIntervalTriggerTypeInvalid = 9049L,
    

    /**
     *  The action actuator is not supported.
     */
    DJIWaypointV2ErrorActionActuatorNotSupport = 9050L,
    

    /**
     *  The action actuator `type` is invalid.
     */
    DJIWaypointV2ErrorActionActuatorTypeInvalid = 9051L,
    

    /**
     *  The action actuator operation type is invalid. See `operationType` or
     *  `operationType` or `operationType`.
     */
    DJIWaypointV2ErrorActionActuatorOperationTypeInvalid = 9052L,
    

    /**
     *  The action gimbal actuator parameters are invalid.
     */
    DJIWaypointV2ErrorActionActuatorGimbalParamInvalid = 9053L,
    

    /**
     *  The action actuator rotate gimbal failed.
     */
    DJIWaypointV2ErrorActionRotateGimbalFailed = 9054L,
    

    /**
     *  The action `DJIWaypointV2AircraftControlParam` parameters are invalid.
     */
    DJIWaypointV2ErrorActionRotateAircraftYawParamInvalid = 9055L,
    

    /**
     *  The action actuator rotate aircraft yaw execute failed.
     */
    DJIWaypointV2ErrorActionRotateAircraftYawFailed = 9056L,
    

    /**
     *  The action actuator and the trigger type do not match.
     */
    DJIWaypointV2ErrorActionActuatorAndTriggerDoNotMatch = 9057L,
    

    /**
     *  The waypoint mission is interrupted by by obstacle avoidance system.
     */
    DJIWaypointV2ErrorMissionWaypointInterruptReasonAvoid = 9058L,
    

    /**
     *  The waypoint mission is interrupted because of radius limit.
     */
    DJIWaypointV2ErrorMissionWaypointInterruptReasonAvoidRadiusLimit = 9059L,
    

    /**
     *  The waypoint mission is interrupted because of height limit.
     */
    DJIWaypointV2ErrorMissionWaypointInterruptReasonAvoidHeightLimit = 9060L,
    

    /**
     *  The waypoint mission is interrupted because of RTK week signal.
     */
    DJIWaypointV2ErrorMissionWaypointInterruptReasonAvoidRTKUnhealthy = 9061L,
    

    /**
     *  The waypoint mission is interrupted because of user request.
     */
    DJIWaypointV2ErrorMissionWaypointInterruptReasonAvoidUserReqBreak = 9062L,
    

    /**
     *  The action actuator aircraft start or stop fly execute failed. For example: when
     *  the aircraft is flying, an error will occur when the `isStartFlying`(TRUE)
     *  action is executed. You should execute `isStartFlying`(FALSE) first.
     */
    DJIWaypointV2ErrorActionAircraftStartStopFlyFailed = 9063L,
    

    /**
     *  Command cannot execute.
     */
    DJIWaypointV2ErrorMissionWaypointCommandCannotExecute = 9064L,
    

    /**
     *  Command execution failed.
     */
    DJIWaypointV2ErrorMissionWaypointCommandExecutionFailed = 9065L,
    

    /**
     *  Invalid parameters.
     */
    DJIWaypointV2ErrorMissionWaypointInvalidParameters = 9066L,
    

    /**
     *  Common timeout.
     */
    DJIWaypointV2ErrorMissionWaypointCommonTimeout = 9067L,
    

    /**
     *  Product connection failed.
     */
    DJIWaypointV2ErrorMissionWaypointProductConnectFailed = 9068L,
    

    /**
     *  System busy.
     */
    DJIWaypointV2ErrorMissionWaypointSystemBusy = 9069L,
    

    /**
     *  Operation cancel by user.
     */
    DJIWaypointV2ErrorMissionWaypointOperationCancelByUser = 9070L,
    

    /**
     *  Upload media file failed.
     */
    DJIWaypointV2ErrorMissionWaypointUploadMediaFileFailed = 9071L,
    

    /**
     *  SDR reserve failed.
     */
    DJIWaypointV2ErrorMissionWaypointSdrReserveFailed = 9072L,
    

    /**
     *  Check photo storage pack error.
     */
    DJIWaypointV2ErrorMissionWaypointCheckPhotoStoragePackError = 9073L,
    

    /**
     *  SDR link reserve failed because motor is on.
     */
    DJIWaypointV2ErrorMissionWaypointSdrLinkReserveFailedCauseMotorOn = 9074L,
    

    /**
     *  The trajectory replay's location is invalid.
     */
    DJIWaypointV2ErrorMissionWaypointTrajectoryReplayInvalidLocation = 9075L,
    

    /**
     *  The trajectory replay has no waypoint to remove.
     */
    DJIWaypointV2ErrorMissionWaypointTrajectoryReplayNoWaypointToRemove = 9076L,
    

    /**
     *  The trajectory replay's gimbal attitude has error.
     */
    DJIWaypointV2ErrorMissionWaypointTrajectoryReplayGimbalAttiError = 9077L,
    

    /**
     *  Data transmission does not match protocols.
     */
    DJIWaypointV2ErrorMissionWaypointInvalidInputDataFCLength = 9078L,
    

    /**
     *  Invalid floating number.
     */
    DJIWaypointV2ErrorMissionWaypointInvalidInputDataFloatNumber = 9079L,
    

    /**
     *  Last waypoint index is invalid.
     */
    DJIWaypointV2ErrorMissionEndIndexInvalid = 9080L,
    

    /**
     *  Invalid reference location point, please check your aircraft location with your
     *  waypoints.
     */
    DJIWaypointV2ErrorMissionReferenceLocationInvalid = 9081L,
    

    /**
     *  Invalid waypoint index, please check your waypoint index with waypoint count.
     */
    DJIWaypointV2ErrorMissionWaypointIndexInvalid = 9082L,
    

    /**
     *  The upload waypoint start index isn't in the given range.
     */
    DJIWaypointV2ErrorMissionWaypointStartIndexNotInEndOfLastUpload = 9083L,
    

    /**
     *  The aircraft start waypoint is too far away from the stop waypoint.
     */
    DJIWaypointV2ErrorMissionControlStartStopInvalid = 9084L,
    

    /**
     *  Invalid pause resume operation.
     */
    DJIWaypointV2ErrorMissionControlPauseResumeInvalid = 9085L,
    

    /**
     *  Invalid interrupt recover operation.
     */
    DJIWaypointV2ErrorMissionControlInterruptRecoverInvalid = 9086L,
    

    /**
     *  The mission is already paused.
     */
    DJIWaypointV2ErrorMissionControlMissionAlreadyPaused = 9087L,
    

    /**
     *  The mission cannot resume because it is not running.
     */
    DJIWaypointV2ErrorMissionControlNoRunningMissionForResume = 9088L,
    

    /**
     *  The mission cannot be paused or resumed now.
     */
    DJIWaypointV2ErrorMissionControlNotSupportPauseResume = 9089L,
    

    /**
     *  The mission cannot be interrupted or recovered now.
     */
    DJIWaypointV2ErrorMissionControlNotSupportInterruptResume = 9090L,
    

    /**
     *  No recorded waypoint for recovery currently.
     */
    DJIWaypointV2ErrorRecoverNoCurrentProjectionPoint = 9091L,
    

    /**
     *  No recorded waypoint for next waypoint recovery.
     */
    DJIWaypointV2ErrorRecoverNoNextProjectionPoint = 9092L,
    

    /**
     *  No recorded waypoint for next 2 waypoint recovery.
     */
    DJIWaypointV2ErrorRecoverNoNextTwoProjectionPoint = 9093L,
    

    /**
     *  Uploaded reach trigger invalid.
     */
    DJIWaypointV2ErrorUploadActionTriggerReachEndIndexLessStartIndex = 9094L,
    

    /**
     *  Uploaded reach trigger invalid.
     */
    DJIWaypointV2ErrorUploadActionTriggerReachIntervalCountInvalid = 9095L,
    

    /**
     *  Uploaded reach trigger invalid.
     */
    DJIWaypointV2ErrorUploadActionTriggerReachAutoTerminateInvalid = 9096L,
    

    /**
     *  Uploaded spray actuator is invalid.
     */
    DJIWaypointV2ErrorUploadActionActuatorSprayExternalSprayModeInvalid = 9097L,
    

    /**
     *  Uploaded spray actuator is invalid.
     */
    DJIWaypointV2ErrorUploadActionActuatorSprayFlowSpeedInvalid = 9098L,
    

    /**
     *  Uploaded spray actuator is invalid.
     */
    DJIWaypointV2ErrorUploadActionActuatorSprayFlowSpeedPreMuInvalid = 9099L,

    /**
     *  Uploaded payload actuator is invalid.
     */
    DJIWaypointV2ErrorActionActuatorPayloadFailToSendCMDToPayload = 9100L,
    

    /**
     *  Uploaded payload actuator is invalid.
     */
    DJIWaypointV2ErrorActionActuatorPayloadExecFailed = 9101L,
    

    /**
     *  Gimbal is not mounted or unable to execute stop rotation command.
     */
    DJIWaypointV2ErrorActionStopGimbalUniformControlFailed = 9102L,
    

    /**
     *  The current waypoint type(Coordinated turn or Curved route Aircraft continues)
     *  does not support setting the action when the waypoint is reached.
     */
    DJIWaypointV2ErrorActionFlightTypeNotSupportHover = 9103L,
    

    /**
     * Take precise photo failed.
     */
    DJIWaypointV2ErrorActionActuatorNavigationFailtoPreciseShootPhoto = 9104L,
    

    /**
     * Take precise photo timeout.
     */
    DJIWaypointV2ErrorActionActuatorNavigationPreciseShootPhotoTimeout = 9105L,
    

    /**
     * Navigation command execute failed
     */
    DJIWaypointV2ErrorActionActuatorNavigationExecuteFailed = 9106L,
    

    /**
     *  Failed to send shoot photo command to camera cause of no camera or camera is
     *  busy.
     */
    DJIWaypointV2ErrorActionActuatorCameraSendSingleShotCmdFail = 9107L,
    

    /**
     *  Failed to send start record command to camera cause of no camera or camera is
     *  busy.
     */
    DJIWaypointV2ErrorActionActuatorCameraSendVideoStartCmdFail = 9108L,
    

    /**
     *  Failed to send video stop command to camera cause of no camera or camera is not
     *  busy.
     */
    DJIWaypointV2ErrorActionActuatorCameraSendVideoStopCmdFail = 9109L,
    

    /**
     *  Camera focus param xy exceed valid range [0, 1].
     */
    DJIWaypointV2ErrorActionActuatorCameraFocusParamXYInvalid = 9110L,
    

    /**
     *  Failed to send camera focus command cause of no camera or camera is busy.
     */
    DJIWaypointV2ErrorActionActuatorCameraSendForcusCmdFail = 9111L,
    

    /**
     *  Failed to send camera zoom command cause of no camera or camera is busy.
     */
    DJIWaypointV2ErrorActionActuatorCameraSendFocalizeCmdFail = 9112L,
    

    /**
     *  Illegal zoom focal length.
     */
    DJIWaypointV2ErrorActionActuatorCameraFocalDistanceInvalid = 9113L,
    

    /**
     * Illegal waypoint index parameter.
     */
    DJIWaypointV2ErrorActionTriggerWaypointIndexParameterIllegal = 9114L,
    

    /**
     *  Unknown error type.
     */
    DJIWaypointV2ErrorUnknown = 10010,
};

/*********************************************************************************/
#pragma mark Pipeline Error
/*********************************************************************************/


/**
 *  Errors related to the `DJIPipelines`.
 */
typedef NS_ENUM(NSInteger, DJIPipelineError) {

    /**
     *  Unknown.
     */
    DJIPipelineErrorUnknown = -10001,

    /**
     *  CRC check failed.
     */
    DJIPipelineErrorCRCCheckFailed = -10002,

    /**
     *  Invalid Parameters.
     */
    DJIPipelineErrorInvalidParameters = -10003,

    /**
     *  Not enough memory.
     */
    DJIPipelineNotEnoughMemory = -10004,

    /**
     *  Usually occurs when allocating the local pipeline ID.
     */
    DJIPipelineErrorNotReady = -10005,

    /**
     *  Send data exception.
     */
    DJIPipelineErrorSendFailed = -10006,

    /**
     *  Receiving data exceptions.
     */
    DJIPipelineErrorReceiveFailed = -10007,

    /**
     *  Timeout error.
     */
    DJIPipelineErrorTimeout = -10008,

    /**
     *  Busy now, please try again later.
     */
    DJIPipelineErrorBusyOperation = -10009,

    /**
     *  Resource occupied, please select another ID connection.
     */
    DJIPipelineErrorUnacceptableOperations = -10010,

    /**
     *  Connection closed, no need to call again.
     */
    DJIPipelineErrorConnectionClosed = -10011,

    /**
     *  Connecting, no need to call again.
     */
    DJIPipelineErrorConnectionConnecting = -10012,

    /**
     *  Local resources are ineffective and unavailable. Please recreate.
     */
    DJIPipelineErrorResourcesNotAvailable = -10013,

    /**
     *  Connection closing, no need to call again.
     */
    DJIPipelineErrorConnectionClosing = -10014,

    /**
     *  Connection has not established.
     */
    DJIPipelineErrorNotConnected = -10015,

    /**
     *  Link broken, please check the connection with the aircraft.
     */
    DJIPipelineErrorLinkBreak = -10016,

    /**
     *  The target device refuses to connect.
     */
    DJIPipelineErrorConnectionRefused = -10017,

    /**
     *  Duplicated binding is not allowed. Please try to bind with a new ID.
     */
    DJIPipelineErrorIdIsOccupied = -10018,

    /**
     *  Internal status error. Please recreate the Pipeline object.
     */
    DJIPipelineErrorInternalStatusError = -10019,
};


/**
 *  NSError's DJISDK category. It contains methods to create custom NSErrors.
 */
@interface NSError (DJISDK)


/**
 *  Get DJISDKError.
 *  
 *  @param errorCode errorCode for `DJISDKError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKErrorForCode:(NSInteger)errorCode;


/**
 *  Get DJISDKCameraError.
 *  
 *  @param errorCode errorCode for `DJISDKCameraError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKCameraErrorForCode:(NSInteger)errorCode;


/**
 *  Get DJISDKFlightControllerError.
 *  
 *  @param errorCode errorCode for `DJISDKFlightControllerError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKFlightControllerErrorForCode:(NSInteger)errorCode;


/**
 *  Get DJISDKMissionError.
 *  
 *  @param errorCode errorCode for `DJISDKMissionError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKMissionErrorForCode:(NSInteger)errorCode;


/**
 *  Get DJISDKRegistrationError.
 *  
 *  @param errorCode errorCode for `DJISDKRegistrationError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKRegistrationErrorForCode:(DJISDKRegistrationError)errorCode;


/**
 *  Get DJISDKFlySafeError.
 *  
 *  @param errorCode errorCode for `DJISDKFlySafeError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKFlySafeErrorForCode:(DJISDKFlySafeError)errorCode;


/**
 *  Returns the specific error in the `DJISDKFlightHubError` according to the error
 *  code.
 *  
 *  @param errorCode errorCode for `DJISDKFlightHubError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKFlightHubErrorForCode:(DJISDKFlightHubError)errorCode;


/**
 *  Get DJIRTKNetworkServiceError.
 *  
 *  @param errorCode errorCode for `DJIRTKNetworkServiceError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJIRTKNetworkServiceErrorForCode:(DJIRTKNetworkServiceError)errorCode;


/**
 *  Get DJIAccessoryAggregationError.
 *  
 *  @param errorCode errorCode for `DJIAccessoryAggregationError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJIAccessoryAggregationErrorForCode:(DJIAccessoryAggregationError)errorCode;


/**
 *  Get DJIAccessoryLockerError.
 *  
 *  @param errorCode errorCode for `DJIAccessLockerError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJIAccessLockerErrorForCode:(DJIAccessLockerError)errorCode;


/**
 *  Get DJIAccessoryLockerError.
 *  
 *  @param errorCode errorCode for `DJIPayloadError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJIPayloadErrorForCode:(DJIPayloadError)errorCode;


/**
 *  Get DJIUpgradeError.
 *  
 *  @param errorCode Error code for `DJIUpgradeError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJIUpgradeErrorForCode:(DJIUpgradeError)errorCode;


/**
 *  Get DJIUTMISSError.
 *  
 *  @param errorCode Error code for `DJIUTMISSError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJIUTMISSErrorForCode:(DJIUTMISSError)errorCode;


/**
 *  Get DJILDMError.
 *  
 *  @param errorCode Error code for `DJILDMError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKLDMErrorForCode:(DJILDMError)errorCode;


/**
 *  Get DJIWaypointV2Error.
 *  
 *  @param errorCode Error code for `DJISDKWaypointV2ErrorForCode`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJISDKWaypointV2ErrorForCode:(DJIWaypointV2Error)errorCode;


/**
 *  Gets the DJIPipelineError.
 *  
 *  @param errorCode Error code for `DJIPipelineError`.
 *  
 *  @return An NSError object initialized with errorCode. If the errorCode was 0, returns nil.
 */
+ (_Nullable instancetype)DJIPipelineErrorForCode:(DJIPipelineError)errorCode;


/**
 *  Get DJISDKError.
 *  
 *  @param errorCode Error code for `DJISDKError`.
 *  @param errorDomain Domain for `DJISDKError`.
 *  @param desc Description for `DJISDKError`.
 *  
 *  @return An NSError object initialized with errorCode, errorDomain and desc.
 */
+ (_Nullable instancetype)DJISDKErrorForCode:(NSInteger)errorCode domain:(NSString *_Nonnull)errorDomain desc:(const NSString *_Nonnull)desc;

@end

NS_ASSUME_NONNULL_END

//
//  DJIRemoteControllerKey.h
//  DJISDK
//
//  Copyright © 2017, DJI. All rights reserved.
//

#import "DJIKey.h"

NS_ASSUME_NONNULL_BEGIN

EXTERN_KEY NSString *const DJIRemoteControllerComponent;
EXTERN_KEY NSString *const DJIRemoteControllerParamDisplayName;

EXTERN_KEY NSString *const DJIRemoteControllerParamStartPairing;
EXTERN_KEY NSString *const DJIRemoteControllerParamStopPairing;
EXTERN_KEY NSString *const DJIRemoteControllerParamStartMultiDevicePairing;
EXTERN_KEY NSString *const DJIRemoteControllerParamStopMultiDevicePairing;
EXTERN_KEY NSString *const DJIRemoteControllerParamPairingState;
EXTERN_KEY NSString *const DJIRemoteControllerParamMultiDevicePairingState;
EXTERN_KEY NSString *const DJIRemoteControllerParamAircraftMappingStyle;
EXTERN_KEY NSString *const DJIRemoteControllerParamCustomAircraftMapping;
EXTERN_KEY NSString *const DJIRemoteControllerParamLeftWheelGimbalControlAxis;
EXTERN_KEY NSString *const DJIRemoteControllerParamCustomButtonTags;
EXTERN_KEY NSString *const DJIRemoteControllerParamC1ButtonBindingEnabled;
EXTERN_KEY NSString *const DJIRemoteControllerParamRTKChannelEnabled;
EXTERN_KEY NSString *const DJIRemoteControllerParamChargeMobileMode;
EXTERN_KEY NSString *const DJIRemoteControllerParamIsMasterSlaveModeSupported;
EXTERN_KEY NSString *const DJIRemoteControllerParamIsMultiDevicePairingSupported;
EXTERN_KEY NSString *const DJIRemoteControllerParamMode;
EXTERN_KEY NSString *const DJIRemoteControllerParamMasterSlaveConnectionState;
EXTERN_KEY NSString *const DJIRemoteControllerParamName;
EXTERN_KEY NSString *const DJIRemoteControllerParamPassword;
EXTERN_KEY NSString *const DJIRemoteControllerParamSlaveList;
EXTERN_KEY NSString *const DJIRemoteControllerParamStartMasterSearching;
EXTERN_KEY NSString *const DJIRemoteControllerParamStopMasterSearching;
EXTERN_KEY NSString *const DJIRemoteControllerParamMasterSearchingState;
EXTERN_KEY NSString *const DJIRemoteControllerParamConnectToMasterWithCredentials;
EXTERN_KEY NSString *const DJIRemoteControllerParamMasterAuthorizationCode;
EXTERN_KEY NSString *const DJIRemoteControllerParamMasters;
EXTERN_KEY NSString *const DJIRemoteControllerParamConnectToMasterWithIDAndAuthorizationCode;
EXTERN_KEY NSString *const DJIRemoteControllerParamRespondToRequestForGimbalControl;
EXTERN_KEY NSString *const DJIRemoteControllerParamRequestLegacyGimbalControl;
EXTERN_KEY NSString *const DJIRemoteControllerParamGimbalMappingStyle;
EXTERN_KEY NSString *const DJIRemoteControllerParamCustomGimbalMapping;
EXTERN_KEY NSString *const DJIRemoteControllerParamGimbalControlSpeedCoefficient;
EXTERN_KEY NSString *const DJIRemoteControllerParamIsFocusControllerSupported;
EXTERN_KEY NSString *const DJIRemoteControllerParamGPSData;
EXTERN_KEY NSString *const DJIRemoteControllerParamBatteryState;
EXTERN_KEY NSString *const DJIRemoteControllerParamIsChargeRemainingLow;
EXTERN_KEY NSString *const DJIRemoteControllerParamMasterSlaveState;
EXTERN_KEY NSString *const DJIRemoteControllerParamFocusControllerIsWorking;
EXTERN_KEY NSString *const DJIRemoteControllerParamFocusControllerControlType;
EXTERN_KEY NSString *const DJIRemoteControllerParamFocusControllerDirection;
EXTERN_KEY NSString *const DJIRemoteControllerParamConnectedMasterCredentials;
EXTERN_KEY NSString *const DJIRemoteControllerParamRequestGimbalControl;
// Hardware
EXTERN_KEY NSString *const DJIRemoteControllerParamLeftHorizontalValue;
EXTERN_KEY NSString *const DJIRemoteControllerParamLeftVerticalValue;
EXTERN_KEY NSString *const DJIRemoteControllerParamRightVerticalValue;
EXTERN_KEY NSString *const DJIRemoteControllerParamRightHorizontalValue;
EXTERN_KEY NSString *const DJIRemoteControllerParamLeftWheelValue;
EXTERN_KEY NSString *const DJIRemoteControllerParamRightWheelValue;
EXTERN_KEY NSString *const DJIRemoteControllerParamRightWheelButtonDown;
EXTERN_KEY NSString *const DJIRemoteControllerParamTransformationSwitchState;
EXTERN_KEY NSString *const DJIRemoteControllerParamRCHardwareFlightModeSwitchState;
EXTERN_KEY NSString *const DJIRemoteControllerParamGohomeButtonDown;
EXTERN_KEY NSString *const DJIRemoteControllerParamRecodeButtonDown;
EXTERN_KEY NSString *const DJIRemoteControllerParamShutterButtonDown;
EXTERN_KEY NSString *const DJIRemoteControllerParamPlaybackButtonDown;
EXTERN_KEY NSString *const DJIRemoteControllerParamCustomButton1Down;
EXTERN_KEY NSString *const DJIRemoteControllerParamCustomButton2Down;
EXTERN_KEY NSString *const DJIRemoteControllerParamRightDialsValue;
EXTERN_KEY NSString *const DJIRemoteControllerParamLeftDialsValue;

EXTERN_KEY NSString *const DJIRemoteControllerParamIsNewMasterSlaveModeSupported;

// Calibration
EXTERN_KEY NSString *const DJIRemoteControllerParamChannelsCalibrate;
EXTERN_KEY NSString *const DJIRemoteControllerParamIsCalibrationSupported;

EXTERN_KEY NSString *const DJIRemoteControllerParamControllingGimbalIndex;
EXTERN_KEY NSString *const DJIRemoteControllerParamLiveViewSimultaneousOutputEnabled;

EXTERN_KEY NSString *const DJIRemoteControllerParamShutterButtonBindingEnabled;
EXTERN_KEY NSString *const DJIRemoteControllerParamRecordButtonBindingEnabled;

EXTERN_KEY NSString *const DJIRemoteControllerParamPhotoAndVideoToggleButtonBindingEnabled;
EXTERN_KEY NSString *const DJIRemoteControllerParamShootPhotoAndRecordButtonBindingEnabled;

/*********************************************************************************/
#pragma mark - Secondary Video
/*********************************************************************************/

EXTERN_KEY NSString *const DJIRemoteControllerParamIsSecondaryVideoOutputSupported;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOutputEnabled;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOutputPort;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoDisplayMode;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOSDEnabled;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOSDTopMargin;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOSDLeftMargin;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOSDBottomMargin;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOSDRightMargin;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOSDUnit;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOutputFormatForHDMI;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoOutputFormatForSDI;
EXTERN_KEY NSString *const DJIRemoteControllerParamSecondaryVideoPIPPosition;


/**
 *  `DJIRemoteControllerKey` provides dedicated access to remote controller
 *  attributes.
 */
@interface DJIRemoteControllerKey : DJIKey

@end

NS_ASSUME_NONNULL_END

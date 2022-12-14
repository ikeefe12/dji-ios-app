//
//  DJIFlightControllerKey.h
//  DJISDK
//
//  Copyright © 2017, DJI. All rights reserved.
//

#import "DJIKey.h"

NS_ASSUME_NONNULL_BEGIN

EXTERN_KEY NSString *const DJIFlightControllerComponent;

EXTERN_KEY NSString *const DJIFlightControllerParamName;

EXTERN_KEY NSString *const DJIFlightControllerParamVelocity;
EXTERN_KEY NSString *const DJIFlightControllerParamAltitudeInMeters;
EXTERN_KEY NSString *const DJIFlightControllerParamConfigRTHInCurrentAltitude;
EXTERN_KEY NSString *const DJIFlightControllerParamTakeoffLocationAltitude;
EXTERN_KEY NSString *const DJIFlightControllerParamFlightTimeInSeconds;

EXTERN_KEY NSString *const DJIFlightControllerParamAircraftLocation;

EXTERN_KEY NSString *const DJIFlightControllerParamSatelliteCount;
EXTERN_KEY NSString *const DJIFlightControllerParamGPSSignalStatus;

EXTERN_KEY NSString *const DJIFlightControllerParamBatteryThresholdBehavior;

EXTERN_KEY NSString *const DJIFlightControllerParamStartTakeoff;
EXTERN_KEY NSString *const DJIFlightControllerParamStartPrecisionTakeoff;
EXTERN_KEY NSString *const DJIFlightControllerParamTurnOnMotors;
EXTERN_KEY NSString *const DJIFlightControllerParamTurnOffMotors;

EXTERN_KEY NSString *const DJIFlightControllerParamESCBeepEnabled;

EXTERN_KEY NSString *const DJIFlightControllerParamHomeLocation;
EXTERN_KEY NSString *const DJIFlightControllerParamRemainingFlightTime;
EXTERN_KEY NSString *const DJIFlightControllerParamBatteryPercentageNeededToLandFromCurrentHeight;
EXTERN_KEY NSString *const DJIFlightControllerParamBatteryPercentageNeededToGoHome;

EXTERN_KEY NSString *const DJIFlightControllerParamAttitude;
EXTERN_KEY NSString *const DJIFlightControllerParamIsHomeLocationSet;
EXTERN_KEY NSString *const DJIFlightControllerParamHomeLocationUsingCurrentAircraftLocation;

EXTERN_KEY NSString *const DJIFlightAssistantParamIsSensorBeingUsed;
EXTERN_KEY NSString *const DJIFlightControllerFlightAssistantSubComponent;
EXTERN_KEY NSString *const DJIFlightAssistantParamSystemWarning;
EXTERN_KEY NSString *const DJIFlightAssistantParamDetectionSectors;

EXTERN_KEY NSString *const DJIFlightAssistantParamVisionControlState;
EXTERN_KEY NSString *const DJIFlightAssistantParamVisionDetectionNoseState;
EXTERN_KEY NSString *const DJIFlightAssistantParamVisionDetectionTailState;
EXTERN_KEY NSString *const DJIFlightAssistantParamVisionDetectionRightState;
EXTERN_KEY NSString *const DJIFlightAssistantParamVisionDetectionLeftState;
EXTERN_KEY NSString *const DJIFlightAssistantParamVisionLeftRightSensorEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamVisionNoseTailSensorEnabled;

EXTERN_KEY NSString *const DJIFlightAssistantParamAdvancedPilotAssistanceSystemEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamIsAdvancedPilotAssistanceSystemActive;
EXTERN_KEY NSString *const DJIFlightControllerParamIsActiveBrakeEngaged;

EXTERN_KEY NSString *const DJIFlightControllerParamIsFlying;
EXTERN_KEY NSString *const DJIFlightControllerParamIsLanding;
EXTERN_KEY NSString *const DJIFlightControllerParamIsGoingHome;
EXTERN_KEY NSString *const DJIFlightControllerParamIsCancelAutoLandingDisabled;
EXTERN_KEY NSString *const DJIFlightControllerParamIsCancelReturnToHomeDisabled;
EXTERN_KEY NSString *const DJIFlightControllerParamFlightMode;

EXTERN_KEY NSString *const DJIFlightControllerParamIsFailSafe;
EXTERN_KEY NSString *const DJIFlightControllerParamIsIMUPreheating;
EXTERN_KEY NSString *const DJIFlightControllerParamIsUltrasonicBeingUsed;
EXTERN_KEY NSString *const DJIFlightControllerParamUltrasonicHeightInMeters;
EXTERN_KEY NSString *const DJIFlightControllerParamDoesUltrasonicHaveError;

EXTERN_KEY NSString *const DJIFlightControllerParamVisionAssistedPositioningEnabled;

EXTERN_KEY NSString *const DJIFlightControllerParamUrgentStopModeEnabled;

EXTERN_KEY NSString *const DJIFlightControllerParamCancelTakeoff;

EXTERN_KEY NSString *const DJIFlightControllerParamAutoLanding;
EXTERN_KEY NSString *const DJIFlightControllerParamCancelAutoLanding;
EXTERN_KEY NSString *const DJIFlightControllerParamAreMotorsOn;

EXTERN_KEY NSString *const DJIFlightControllerParamNeedLimitFlightHeight;
EXTERN_KEY NSString *const DJIFlightControllerParamMaxFlightHeight;
EXTERN_KEY NSString *const DJIFlightControllerParamMaxFlightHeightRange;
EXTERN_KEY NSString *const DJIFlightControllerParamMaxFlightRadius;
EXTERN_KEY NSString *const DJIFlightControllerParamMaxFlightRadiusRange;
EXTERN_KEY NSString *const DJIFlightControllerParamMaxFlightRadiusEnabled;

EXTERN_KEY NSString *const DJIFlightControllerParamGoHome;
EXTERN_KEY NSString *const DJIFlightControllerParamCancelGoHome;

EXTERN_KEY NSString *const DJIFlightControllerParamGoHomeAssessment;
EXTERN_KEY NSString *const DJIFlightControllerParamGoHomeExecutionState;
EXTERN_KEY NSString *const DJIFlightControllerParamFlightModeString;

EXTERN_KEY NSString *const DJIFlightControllerParamIsLandingConfirmationNeeded;

EXTERN_KEY NSString *const DJIFlightControllerParamVerticalControlMode;
EXTERN_KEY NSString *const DJIFlightControllerParamRollPitchControlMode;
EXTERN_KEY NSString *const DJIFlightControllerParamYawControlMode;
EXTERN_KEY NSString *const DJIFlightControllerParamRollPitchCoordinateSystem;
EXTERN_KEY NSString *const DJIFlightControllerParamVirtualStickControlModeAvailable;
EXTERN_KEY NSString *const DJIFlightControllerParamVirtualStickAdvancedControlModeEnabled;

EXTERN_KEY NSString *const DJIFlightControllerParamIsLandingGearMovable;

EXTERN_KEY NSString *const DJIFlightControllerParamGoHomeHeightInMeters;
EXTERN_KEY NSString *const DJIFlightControllerParamConnectionFailSafeBehavior;

EXTERN_KEY NSString *const DJIFlightControllerParamLowBatteryWarningThreshold;
EXTERN_KEY NSString *const DJIFlightControllerParamSeriousLowBatteryWarningThreshold;
EXTERN_KEY NSString *const DJIFlightControllerParamIsLowerThanBatteryWarningThreshold;
EXTERN_KEY NSString *const DJIFlightControllerParamIsLowerThanSeriousBatteryWarningThreshold;

EXTERN_KEY NSString *const DJIFlightControllerParamSmartReturnToHomeEnabled;
EXTERN_KEY NSString *const DJIFlightControllerParamConfirmSmartReturnToHomeRequest;
EXTERN_KEY NSString *const DJIFlightControllerParamReturnToHomeState;

EXTERN_KEY NSString *const DJIFlightControllerParamStartIMUCalibration;
EXTERN_KEY NSString *const DJIFlightControllerParamStartIMUCalibrationWithID;

EXTERN_KEY NSString *const DJIFlightControllerParamConfirmLanding;
EXTERN_KEY NSString *const DJIFlightControllerParamForceLandingHeight;
EXTERN_KEY NSString *const DJIFlightControllerParamLEDsEnabledSettings;
EXTERN_KEY NSString *const DJIFlightControllerParamControlMode;
EXTERN_KEY NSString *const DJIFlightControllerParamTripodModeEnabled;
EXTERN_KEY NSString *const DJIFlightControllerParamTerrainFollowModeEnabled;
EXTERN_KEY NSString *const DJIFlightControllerParamAutoQuickSpinEnabled;

EXTERN_KEY NSString *const DJIFlightControllerParamFCControlChannel0Mapping;
EXTERN_KEY NSString *const DJIFlightControllerParamFCControlChannel1Mapping;
EXTERN_KEY NSString *const DJIFlightControllerParamFCControlChannel2Mapping;

EXTERN_KEY NSString *const DJIFlightControllerParamFlightOrientationMode;
EXTERN_KEY NSString *const DJIFlightControllerParamLockCourseUsingCurrentHeading;

EXTERN_KEY NSString *const DJIFlightControllerParamVirtualStickControlModeEnabled;
EXTERN_KEY NSString *const DJIFlightControllerParamSendVirtualStickFlightControlData;

EXTERN_KEY NSString *const DJIFlightControllerParamHasReachedMaxFlightHeight;
EXTERN_KEY NSString *const DJIFlightControllerParamHasReachedMaxFlightRadius;

EXTERN_KEY NSString *const DJIFlightControllerParamLandingGearState;
EXTERN_KEY NSString *const DJIFlightControllerParamLandingGearMode;
EXTERN_KEY NSString *const DJIFlightControllerParamLandingGearAutomaticMovementEnabled;
EXTERN_KEY NSString *const DJIFlightControllerParamLandingGearEnterTransportMode;
EXTERN_KEY NSString *const DJIFlightControllerParamLandingGearExitTransportMode;
EXTERN_KEY NSString *const DJIFlightControllerParamLandingGearRetractLandingGear;
EXTERN_KEY NSString *const DJIFlightControllerParamLandingGearDeployLandingGear;

EXTERN_KEY NSString *const DJIFlightControllerParamLandingProtectionState;

EXTERN_KEY NSString *const DJIFlightControllerParamMultipleFlightModeEnabled;
EXTERN_KEY NSString *const DJIFlightControllerParamNoviceModeEnabled;

//Flight Assistant
EXTERN_KEY NSString *const DJIFlightAssistantParamCollisionAvoidanceEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamPrecisionLandingEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamLandingProtectionEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamActiveObstacleAvoidanceEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamUpwardsAvoidanceEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamHorizontalAvoidanceEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamAvoidanceState;
EXTERN_KEY NSString *const DJIFlightAssistantParamToFAvoidanceState;

EXTERN_KEY NSString *const DJIFlightAssistantParamIsBraking;

EXTERN_KEY NSString *const DJIFlightAssistantParamAdvancedGestureControlEnabled;
EXTERN_KEY NSString *const DJIFlightAssistantParamSmartCaptureEnabled;

//Compass
EXTERN_KEY NSString *const DJIFlightControllerParamCompassHeading;
EXTERN_KEY NSString *const DJIFlightControllerParamCompassIsCalibrating;
EXTERN_KEY NSString *const DJIFlightControllerParamCompassHasError;
EXTERN_KEY NSString *const DJIFlightControllerParamCompassCalibrationState;
EXTERN_KEY NSString *const DJIFlightControllerParamCompassStartCalibration;
EXTERN_KEY NSString *const DJIFlightControllerParamCompassStopCalibration;

//IMU
EXTERN_KEY NSString *const DJIFlightControllerParamIMUState;
EXTERN_KEY NSString *const DJIFlightControllerParamIMUsCount;

//Gravity
EXTERN_KEY NSString *const DJIFlightControllerParamGravityCenterState;
EXTERN_KEY NSString *const DJIFlightControllerParamStartGravityCenterCalibration;
EXTERN_KEY NSString *const DJIFlightControllerParamStopGravityCenterCalibration;

EXTERN_KEY NSString *const DJIFlightControllerParamIMUStateGyroscopeState;
EXTERN_KEY NSString *const DJIFlightControllerParamIMUAccelerometerState;
EXTERN_KEY NSString *const DJIFlightControllerParamIMUStateCalibrationProgress;
EXTERN_KEY NSString *const DJIFlightControllerParamIMUStateCalibrationState;
EXTERN_KEY NSString *const DJIFlightControllerParamCompassState;

//Simulator
EXTERN_KEY NSString *const DJIFlightControllerParamSimulatorState;
EXTERN_KEY NSString *const DJIFlightControllerParamIsSimulatorActive;
EXTERN_KEY NSString *const DJIFlightControllerParamStartSimulator;
EXTERN_KEY NSString *const DJIFlightControllerParamStopSimulator;
EXTERN_KEY NSString *const DJIFlightControllerParamSimulatorFlyZoneLimitationEnabled;
EXTERN_KEY NSString *const DJIFlightControllerParamSimulatorWindSpeed;

EXTERN_KEY NSString *const DJIFlightControllerParamWaypointMissionInterruption;

// capability
EXTERN_KEY NSString *const DJIFlightControllerParamCinematicBrakeSensitivity;
EXTERN_KEY NSString *const DJIFlightControllerParamCinematicBrakeSensitivityRange;
EXTERN_KEY NSString *const DJIFlightControllerParamCinematicYawSpeed;
EXTERN_KEY NSString *const DJIFlightControllerParamCinematicYawSpeedRange;

//AirSense
EXTERN_KEY NSString *const DJIFlightControllerParamAirSenseSystemWarningLevel;
EXTERN_KEY NSString *const DJIFlightControllerParamAirSenseAirplaneStates;
EXTERN_KEY NSString *const DJIFlightControllerParamAirSenseSystemConnected;

//Hotpoint
EXTERN_KEY NSString *const DJIFlightAssistantParamIsHotpointIntelligentModeSupport;
EXTERN_KEY NSString *const DJIFlightAssistantParamPOIEnabled;

////////////////////////////////////////////////////////////////////////////////
#pragma mark - Onboard
////////////////////////////////////////////////////////////////////////////////

EXTERN_KEY NSString *const DJIFlightControllerParamIsOnboardSDKAvailable;
EXTERN_KEY NSString *const DJIFlightControllerParamOnboardSDKDeviceData;
EXTERN_KEY NSString *const DJIFlightControllerParamSendDataToOnboardSDKDevice;
EXTERN_KEY NSString *const DJIFlightControllerParamOnboardSDKDeviceActive;
EXTERN_KEY NSString *const DJIFlightControllerParamOnboardSDKDeviceVersion;
EXTERN_KEY NSString *const DJIFlightControllerParamPowerSupplyPortEnabled;

////////////////////////////////////////////////////////////////////////////////
#pragma mark - Access Locker
////////////////////////////////////////////////////////////////////////////////

EXTERN_KEY NSString *const DJIFlightControllerAccessLockerSubComponent;
EXTERN_KEY NSString *const DJIAccessLockerParamVersion;
EXTERN_KEY NSString *const DJIAccessLockerParamState;
EXTERN_KEY NSString *const DJIAccessLockerParamUsername;
EXTERN_KEY NSString *const DJIAccessLockerParamSetUpUserAccount;
EXTERN_KEY NSString *const DJIAccessLockerParamLogin;
EXTERN_KEY NSString *const DJIAccessLockerParamModifyUserAccount;
EXTERN_KEY NSString *const DJIAccessLockerParamResetUserAccount;
EXTERN_KEY NSString *const DJIAccessLockerParamFormat;
EXTERN_KEY NSString *const DJIAccessLockerParamFormatState;

////////////////////////////////////////////////////////////////////////////////
#pragma mark - RTK
////////////////////////////////////////////////////////////////////////////////

EXTERN_KEY NSString *const DJIFlightControllerRTKSubComponent;

EXTERN_KEY NSString *const DJIFlightControllerParamRTKSupported;
EXTERN_KEY NSString *const DJIRTKParamEnabled;
EXTERN_KEY NSString *const DJIRTKParamStatus;
EXTERN_KEY NSString *const DJIRTKParamError;
EXTERN_KEY NSString *const DJIRTKParamPositioningSolution;
EXTERN_KEY NSString *const DJIRTKParamHeadingSolution;
EXTERN_KEY NSString *const DJIRTKParamMainGPSCount;
EXTERN_KEY NSString *const DJIRTKParamMainBeidouCount;
EXTERN_KEY NSString *const DJIRTKParamMainGlonassCount;
EXTERN_KEY NSString *const DJIRTKParamMainGalileoCount;
EXTERN_KEY NSString *const DJIRTKParamSatelliteGPSCount;
EXTERN_KEY NSString *const DJIRTKParamSatelliteBeidouCount;
EXTERN_KEY NSString *const DJIRTKParamSatelliteGlonassCount;
EXTERN_KEY NSString *const DJIRTKParamSatelliteGalileoCount;
EXTERN_KEY NSString *const DJIRTKParamBaseStationGPSCount;
EXTERN_KEY NSString *const DJIRTKParamBaseStationBeidouCount;
EXTERN_KEY NSString *const DJIRTKParamBaseStationGlonassCount;
EXTERN_KEY NSString *const DJIRTKParamBaseStationGalileoCount;
EXTERN_KEY NSString *const DJIRTKParamMobileStationFusionHeadingAngle;
EXTERN_KEY NSString *const DJIRTKParamMobileStationFusionAltitude;
EXTERN_KEY NSString *const DJIRTKParamMobileStationFusionLocation;
EXTERN_KEY NSString *const DJIRTKParamMobileStationLocation;
EXTERN_KEY NSString *const DJIRTKParamMobileStationAltitude;
EXTERN_KEY NSString *const DJIRTKParamFusionHomeLocation;
EXTERN_KEY NSString *const DJIRTKParamFusionTakeOffAltitude;
EXTERN_KEY NSString *const DJIRTKParamBaseStationLocation;
EXTERN_KEY NSString *const DJIRTKParamBaseStationAltitude;
EXTERN_KEY NSString *const DJIRTKParamMobileStationLongtitudeStandardDeviation;
EXTERN_KEY NSString *const DJIRTKParamMobileStationLatitudeStandardDeviation;
EXTERN_KEY NSString *const DJIRTKParamMobileStationAltitudeStandardDeviation;
EXTERN_KEY NSString *const DJIRTKParamReferenceStationSource;
EXTERN_KEY NSString *const DJIRTKParamPPKModeEnabled;
EXTERN_KEY NSString *const DJIRTKParamPPKModeState;

EXTERN_KEY NSString *const DJIRTKParamHeadingAngle;
EXTERN_KEY NSString *const DJIRTKParamIsHeadingValid;
EXTERN_KEY NSString *const DJIRTKParamIsRTKBeingUsed;

EXTERN_KEY NSString *const DJIRTKParamStartRTKBaseStationScanning;
EXTERN_KEY NSString *const DJIRTKParamStopRTKBaseStationScanning;
EXTERN_KEY NSString *const DJIRTKParamSelectRTKBaseStation;
EXTERN_KEY NSString *const DJIRTKParamBaseStationList;
EXTERN_KEY NSString *const DJIRTKParamBaseStationConnectionState;


/**
 *  `DJIFlightControllerKey` provides dedicated access to Flight  controller
 *  attributes.
 */
@interface DJIFlightControllerKey : DJIKey

@end

NS_ASSUME_NONNULL_END

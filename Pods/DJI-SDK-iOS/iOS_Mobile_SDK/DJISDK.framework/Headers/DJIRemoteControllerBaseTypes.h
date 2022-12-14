//
//  DJIRemoteControllerBaseTypes.h
//  DJISDK
//
//  Copyright © 2016, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "DJIStick.h"

#define DJI_RC_CONTROL_CHANNEL_SIZE     (4)

NS_ASSUME_NONNULL_BEGIN

/*********************************************************************************/
#pragma mark - Data Structs and Enums
/*********************************************************************************/

/*********************************************************************************/
#pragma mark DJIRCMode
/*********************************************************************************/


/**
 *  Remote Controller mode of operation can be normal (single RC connected to
 *  aircraft), master, slave, or unknown.
 */
typedef NS_ENUM (uint8_t, DJIRCMode){


    /**
     *  Remote Controller is not connected to another Remote Controller.
     */
    DJIRCModeNormal,


    /**
     *  Remote Controller is a master (will route a connected slave Remote
     *   Controller's commands to the aircraft).
     */
    DJIRCModeMaster,

    /**
     *  Remote Controller is currently a slave Remote Controller (sends commands to
     *  aircraft through a master Remote Controller).
     */
    DJIRCModeSlave,


    /**
     *  The Remote Controller's mode is unknown.
     */
    DJIRCModeUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCCalibrationState
/*********************************************************************************/


/**
 *  Remote Controller's calibration state.
 */
typedef NS_ENUM(uint8_t, DJIRCCalibrationState){
    

    /**
     *  There is currently no Remote Controller calibration happening.
     */
    DJIRCCalibrationStateNotCalibrating,
    

    /**
     *  Currently recording the joystick in its center position (joystick is untouched).
     */
    DJIRCCalibrationStateRecordingCenterPosition,
    

    /**
     *  Currently recording the extreme joystick positions, when joysticks are all the
     *  way to their max in any direction (left, right, up, or down).
     */
    DJIRCCalibrationStateRecordingExtremePositions,
    

    /**
     *  The Remote Controller is exiting calibration.
     */
    DJIRCCalibrationStateExit,
};

/*********************************************************************************/
#pragma mark DJIRCAircraftMappingStyle
/*********************************************************************************/


/**
 *  The predefined mapping styles available to use. Custom allow to specify all
 *  mapping configurations.
 */
typedef NS_ENUM (uint8_t, DJIRCAircraftMappingStyle){
    

    /**
     *  Style 1.(Japanese Mode)
     */
    DJIRCAircraftMappingStyle1,
    

    /**
     *  Style 2.(American Mode)
     */
    DJIRCAircraftMappingStyle2,
    

    /**
     *  Style 3.(Chinese Mode)
     */
    DJIRCAircraftMappingStyle3,
    

    /**
     *  Custom Style. Requires all mapping configurations.
     */
    DJIRCAircraftMappingStyleCustom,
    

    /**
     *  Unknown style.
     */
    DJIRCAircraftMappingStyleUnknown = 0xFF,
};


/**
 *  The list of controls that may be mapped on a stick.
 */
typedef NS_ENUM (uint8_t, DJIRCAircraftStickMappingTarget) {
    

    /**
     *  None
     */
    DJIRCAircraftStickMappingTargetNone,


    /**
     *  Controls Throttle
     */
    DJIRCAircraftStickMappingTargetThrottle,
    

    /**
     *  Controls Pitch
     */
    DJIRCAircraftStickMappingTargetPitch,
    

    /**
     *  Controls Roll
     */
    DJIRCAircraftStickMappingTargetRoll,
    

    /**
     *  Controls Yaw
     */
    DJIRCAircraftStickMappingTargetYaw,


	/**
	 *  Unknown.
	 */
	DJIRCAircraftStickMappingUnknown = 0xFF,
};


/**
 *  A struct representing a mapping configuration which includes the particular
 *  control and whether or not it is reversed.
 */
typedef struct
{

    /**
     *  The defined control to be mapped.
     */
    DJIRCAircraftStickMappingTarget target;
    

    /**
     *  whether or not the control is to be reversed.
     */
    BOOL isReversed;
} DJIRCAircraftStickMapping;


/**
 *  The gimbal control stick mapping styles.
 */
typedef NS_ENUM (uint8_t, DJIRCGimbalMappingStyle){
    

    /**
     *  Default
     */
    DJIRCGimbalMappingStyleDefault,
    

    /**
     *  Custom
     */
    DJIRCGimbalMappingStyleCustom,
    

    /**
     *  Unknown
     */
    DJIRCGimbalMappingStyleUnknown = 0xFF,
};


/**
 *  The list of available control to be used when creating custom mapping
 *  configurations
 */
typedef NS_ENUM (uint8_t, DJIRCGimbalStickMappingTarget) {
    

    /**
     *  None
     */
    DJIRCGimbalStickMappingTargetNone,
    

    /**
     *  Pitch
     */
    DJIRCGimbalStickMappingTargetPitch,
    

    /**
     *  Roll
     */
    DJIRCGimbalStickMappingTargetRoll,
    

    /**
     *  Yaw
     */
    DJIRCGimbalStickMappingTargetYaw
};


/**
 *  A struct representing a custom mapping configuration.
 */
typedef struct
{

    /**
     *  The specific control to be mapped.
     */
    DJIRCGimbalStickMappingTarget target;
    

    /**
     *  whether or not the control is to be reversed.
     */
    BOOL isReversed;
    
} DJIRCGimbalStickMapping;


/*********************************************************************************/
#pragma mark DJIRCRequestGimbalControlResult
/*********************************************************************************/


/**
 *  Result when a slave Remote Controller requests permission to control the gimbal.
 */
typedef NS_ENUM (uint8_t, DJIRCRequestGimbalControlResult) {
 

    /**
     *  The master Remote Controller agrees to the slave's request.
     */
    DJIRCRequestGimbalControlResultAccepted,
 

    /**
     *  The master Remote Controller denies the slave's request. If the slave Remote
     *  Controller wants to control the gimbal, it must send a request to the master
     *  Remote Controller first. Then the master Remote Controller can decide to approve
     *  or deny the request.
     */
    DJIRCRequestGimbalControlResultRejected,
 

    /**
     *  The slave Remote Controller's request timed out.
     */
    DJIRCRequestGimbalControlResultTimeout,
    

    /**
     *  The slave Remote Controller's request is unknown.
     */
    DJIRCRequestGimbalControlResultUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCGimbalControlSpeedCoefficient
/*********************************************************************************/


/**
 *  Remote Controller's gimbal control speed.
 */
typedef struct
{

    /**
     *  Gimbal's pitch speed with range [0, 100].
     */
    uint8_t pitchSpeedCoefficient;
    

    /**
     *  Gimbal's roll speed with range [0, 100].
     */
    uint8_t rollSpeedCoefficient;
    

    /**
     *  Gimbal's yaw speed with range [0, 100].
     */
    uint8_t yawSpeedCoefficient;
} DJIRCGimbalControlSpeedCoefficient;

/*********************************************************************************/
#pragma mark DJIRCPairingState
/*********************************************************************************/


/**
 *  Remote Controller pairing state.
 */
typedef NS_ENUM (uint8_t, DJIRCPairingState){

    /**
     *  The Remote Controller is not pairing.
     */
    DJIRCPairingStateStateUnpaired,
    

    /**
     *  The Remote Controller is currently pairing.
     */
    DJIRCPairingStateStatePairing,
    

    /**
     *  The Remote Controller's pairing was completed.
     */
    DJIRCPairingStateStatePaired,
    

    /**
     *  The Remote Controller is switching rc firmware.
     */
    DJIRCPairingStateStateSwitching,


    /**
     *  The remote control has finished switching RC firmware.
     */
    DJIRCPairingStateStateSwitchingEnd,
    

    /**
     *  The Remote Controller's pairing state is unknown.
     */
    DJIRCPairingStateStateUnknown = 0xFF,
};


/*********************************************************************************/
#pragma mark DJIRCConnectToMasterResult
/*********************************************************************************/


/**
 *  Result when a slave Remote Controller tries to join a master Remote Controller.
 */
typedef NS_ENUM (uint8_t, DJIRCConnectToMasterResult){
 

    /**
     *  The slave Remote Controller's attempt to join the master Remote Controller was
     *  successful.
     */
    DJIRCConnectToMasterResultAccepted,
 

    /**
     *  The slave Remote Controller's attempt to join the master Remote Controller was
     *  unsuccessful due to a password error.
     */
    DJIRCConnectToMasterResultPasswordError,
 

    /**
     *  The slave Remote Controller's attempt to join the master Remote Controller was
     *  rejected.
     */
    DJIRCConnectToMasterResultRejected,
 

    /**
     *  The slave Remote Controller's attempt to join the master Remote Controller was
     *  unsuccessful because the master Remote Controller is at the maximum number of
     *  slaves it can have.
     */
    DJIRCConnectToMasterResultMaximumCapacity,


    /**
     *  The slave Remote Controller's attempt to join the master Remote Controller was
     *  unsuccessful because the request timed out.
     */
    DJIRCConnectToMasterResultTimeout,
    

    /**
     *  The result of the slave Remote Controller's attempt to join the master Remote
     *  Controller is unknown.
     */
    DJIRCConnectToMasterResultUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCBatteryState
/*********************************************************************************/


/**
 *  Remote Controller's battery information. Only supported by DJI Smart Controller
 *  Enterprise with  firmware version v01.00.01.01 and above.
 */
typedef struct
{

    /**
     *  The remaining power in the Remote Controller's battery in milliamp hours (mAh).
     */
    uint32_t remainingChargeInmAh;
    

    /**
     *  The remaining power in the Remote Controller's battery as a percentage in the
     *  range of [0, 100].
     */
    uint8_t remainingChargeInPercent;
    

    /**
     *  Whether battery of remote controller is charging. The battery may be fully
     *  charged when it returns false.
     */
    bool isCharging;
} DJIRCBatteryState;

/*********************************************************************************/
#pragma mark DJIRCGPSTime
/*********************************************************************************/


/**
 *  Remote Controller's GPS time.
 */
typedef struct
{

    /**
     *  Hour value of Remote Controller's GPS time.
     */
    uint8_t hour;
    

    /**
     *  Minute value of Remote Controller's GPS time.
     */
    uint8_t minute;
    

    /**
     *  Second value of Remote Controller's GPS time.
     */
    uint8_t second;
    

    /**
     *  Year value of Remote Controller's GPS time.
     */
    uint16_t year;
    

    /**
     *  Month value of Remote Controller's GPS time.
     */
    uint8_t month;
    

    /**
     *  Day value of Remote Controller's GPS time.
     */
    uint8_t day;
} DJIRCGPSTime;

/*********************************************************************************/
#pragma mark DJIRCGPSData
/*********************************************************************************/


/**
 *  Remote Controller's GPS data. Only supported by Remote Controller using DJI
 *  Lightbridge.
 */
typedef struct
{

    /**
     *  The Remote Controller's GPS time.
     */
    DJIRCGPSTime time;
    

    /**
     *  The Remote Controller's location.
     */
    CLLocationCoordinate2D location;
    

    /**
     *  The Remote Controller's speed in the East direction in meters/second. A negative
     *  speed means the Remote  Controller is moving in the West direction.
     */
    float eastSpeed;
    

    /**
     *  The Remote Controller's speed in the North direction in meters/second. A
     *  negative speed means the Remote  Controller is moving in the South direction.
     */
    float northSpeed;
    

    /**
     *  The number of GPS satellites the Remote Controller detects.
     */
    int satelliteCount;
    

    /**
     *  The the margin of error, in meters, for the GPS location.
     */
    float accuracy;
    

    /**
     *  `YES` if the GPS data is valid. The data is not valid if there are too few
     *  satellites  or the signal strength is too low.
     */
    BOOL isValid;
} DJIRCGPSData;

/*********************************************************************************/
#pragma mark DJIRCGimbalAxis
/*********************************************************************************/


/**
 *  Defines what the Gimbal Dial (upper left dial on the Remote Controller) will
 *  control.
 */
typedef NS_ENUM (uint8_t, DJIRCGimbalAxis){
 

    /**
     *  The upper left dial will control the gimbal's pitch.
     */
    DJIRCGimbalAxisPitch,
 

    /**
     *  The upper left dial will control the gimbal's roll.
     */
    DJIRCGimbalAxisRoll,
 

    /**
     *  The upper left dial will control the gimbal's yaw.
     */
    DJIRCGimbalAxisYaw,
};

/*********************************************************************************/
#pragma mark DJIRCRightWheel
/*********************************************************************************/


/**
 *  Current state of the Camera Settings Dial (upper right dial on the Remote
 *  Controller).
 */
typedef struct
{

    /**
     *  `YES` if right wheel present.
     */
    BOOL isPresent;
    

    /**
     *  `YES` if dial value has changed.
     */
    BOOL isTurned;
    

    /**
     *  `YES` if wheel is being pressed.
     */
    BOOL isClicked;
    

    /**
     *  Dial value in the range of [-660, 660]. The value represents the difference in
     *  an operation.
     */
    NSInteger value;
} DJIRCRightWheel;

/*********************************************************************************/
#pragma mark DJIRCTransformationSwitchState
/*********************************************************************************/


/**
 *  Transformation Switch position states.
 */
typedef NS_ENUM (uint8_t, DJIRCTransformationSwitchState){
 

    /**
     *  Retract landing gear switch state.
     */
    DJIRCTransformationSwitchStateRetract,
 

    /**
     *  Deploy landing gear switch state.
     */
    DJIRCTransformationSwitchStateDeploy,
	

	/**
	 *  Unknown.
	 */
	DJIRCTransformationSwitchStateUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCHardwareTransformSwitch
/*********************************************************************************/


/**
 *  Transformation Switch position. The Transformation Switch is around the Return
 *  To Home Button on Inspire,  Inspire 1 and M100 Remote Controllers, and controls
 *  the state of the aircraft's landing gear.
 */
typedef struct
{

    /**
     *  `YES` if the Transformation Switch present.
     */
    BOOL isPresent;
    

    /**
     *  Current transformation switch state.
     */
    DJIRCTransformationSwitchState state;
    
} DJIRCTransformationSwitch;

/*********************************************************************************/
#pragma mark DJIRCFlightModeSwitch
/*********************************************************************************/


/**
 *  Remote Controller Flight Mode switch position.
 */
typedef NS_ENUM (uint8_t, DJIRCFlightModeSwitch){


    /**
     *  Position One. For all products except Mavic Pro, this is the left most position
     *  of the flight mode switch on a remote controller from the perspective of the
     *  pilot. For example, on a Phantom 4 remote controller,  Position One is labeled
     *  "A". For Mavic Pro, Spark and Mavic Air, this is  the position that is furthest
     *  away from the pilot and labeled "Sport".
     */
    DJIRCFlightModeSwitchOne,


    /**
     *  Position Two. For all products except Mavic Pro, this is the middle position of
     *  the flight mode switch on a remote controller from the perspective of the pilot.
     *  For example, on a Phantom 4 remote controller, Position Two is labeled "S". For
     *  Mavic Pro, Spark and Mavic Air, this is the position that is closest  to the
     *  pilot (the P position).
     */
    DJIRCFlightModeSwitchTwo,


    /**
     *  Position Three. For all products except Mavic Pro, this is the right most
     *  position of the flight mode switch on a remote controller from the perspective
     *  of the pilot. For example, on a Phantom 4 remote controller, Position Two is
     *  labeled "P". Mavic Pro, Spark or Mavic Air does not have  a third position for
     *  the flight mode switch.
     */
    DJIRCFlightModeSwitchThree,
};

/*********************************************************************************/
#pragma mark DJIRCButton
/*********************************************************************************/


/**
 *  Remote Controller has numerous momentary push buttons, which will use this
 *  state.
 */
typedef struct
{

    /**
     *  `YES` if the hardware button is present.
     */
    BOOL isPresent;
    

    /**
     *  `YES` if button is pressed down.
     */
    BOOL isClicked;
} DJIRCButton;

/*********************************************************************************/
#pragma mark DJIRCFiveDButton
/*********************************************************************************/


/**
 *  Movement direction of the remote controller's 5D button.
 */
typedef NS_ENUM(NSUInteger, DJIRCFiveDButtonDirection) {
 

    /**
     *  Button has no movement in either the vertical direction or the horizontal
     *  direction.
     */
    DJIRCFiveDButtonDirectionMiddle,
 

    /**
     *  Button is moved in the positive direction which is up or right.
     */
    DJIRCFiveDButtonDirectionPositive,
 

    /**
     *  Button is moved in the negative direction which is down or left.
     */
    DJIRCFiveDButtonDirectionNegative,
};


/**
 *  State of the 5D button on the remote controller. Vertical movement, horizontal
 *  movement and if it is pressed are  not exclusive.
 */
typedef struct{
    

    /**
     *  `YES` if 5D button is present.
     */
    BOOL isPresent;
    

    /**
     *  Get the movement in the vertical direction of the 5D button. Up is the positive
     *  direction and down is the  negative direction.
     */
    DJIRCFiveDButtonDirection verticalDirection;
    

    /**
     *  Get the movement in the horizontal direction of the 5D button. Right is the
     *  positive direction and left is the  negative direction.
     */
    DJIRCFiveDButtonDirection horizontalDirection;
    

    /**
     *  `YES` if the 5D button is pressed down.
     */
    BOOL isClicked;
}DJIRCFiveDButton;

/*********************************************************************************/
#pragma mark DJIRCHardwareState
/*********************************************************************************/


/**
 *  Remote Controller's current state.
 */
typedef struct
{

    /**
     *  Get left stick.
     *  
     *  @return An instance of `DJIStick`.
     */
    DJIStick leftStick;


    /**
     *  Get right stick.
     *  
     *  @return An instance of `DJIStick`.
     */
    DJIStick rightStick;


    /**
     *  Gimbal Dial's (upper left dial) value in the range of [-660,660], where 0 is
     *  untouched and positive is turned in the clockwise direction.
     *  
     *  @return Gimbal dial value.
     */
    int leftWheel;
    

    /**
     *  Current state of the Camera Settings Dial (upper right dial) on the Remote
     *  Controller.
     */
    DJIRCRightWheel rightWheel;
	

	/**
	 *  Dials value in the range of [-660, 660]. The value represents the difference in
	 *  an operation. Only Supported by Cendence.
	 *  
	 *  @return Gimbal dials value.
	 */
	int leftDials;
	

	/**
	 *  Dials value in the range of [-660, 660]. The value represents the difference in
	 *  an operation. Only Supported by Cendence.
	 *  
	 *  @return Gimbal dials value.
	 */
	int rightDials;
	

    /**
     *  Current state of the Transformation Switch on the Remote Controller.
     */
    DJIRCTransformationSwitch transformationSwitch;
    

    /**
     *  Current position of the Flight Mode Switch on the Remote Controller.
     */
    DJIRCFlightModeSwitch flightModeSwitch;
    

    /**
     *  Current state of the Return To Home Button.
     */
    DJIRCButton goHomeButton;
    

    /**
     *  Current state of the Video Recording Button.
     */
    DJIRCButton recordButton;
    

    /**
     *  Current state of the Shutter Button.
     */
    DJIRCButton shutterButton;
    

    /**
     *  Current state of the Playback Button. The Playback Button is not supported on
     *  Phantom 4 remote controllers.
     */
    DJIRCButton playbackButton;
    

    /**
     *  Current state of the Photo and Video Toggle Button.
     */
    DJIRCButton photoAndVideoToggleButton;
    

    /**
     *  Current state of the Photo and Record Button.
     */
    DJIRCButton shootPhotoAndRecordButton;
    

    /**
     *  Current state of the Pause Button. The Pause button is only supported on Phantom
     *  4 remote controllers.
     */
    DJIRCButton pauseButton;
    

    /**
     *  Current state of custom button 1 (left Back Button). For Mavic Air 2 and DJI Air
     *  2S, There is no custom button 1, we use Fn button instead, one click on Fn
     *  button represents custom button 1. It is not supported by remote controllers for
     *  Mavic Air or Spark.
     */
    DJIRCButton c1Button;
    

    /**
     *  Current state of custom button 2 (right Back Button). For Mavic Air 2 and DJI
     *  Air 2S, There is no custom button 2, we use Fn button instead, double clicks on
     *  Fn button represents custom button 2.
     */
    DJIRCButton c2Button;
    

    /**
     *  Current state of fn button. It is only supported by remote controllers for Spark
     *  or Mavic Air.
     */
    DJIRCButton fnButton;
    

    /**
     *  Current state of the 5D button. The button can be moved up, down, left and right
     *  and can be pressed. The 5D  button is supported by Mavic Pro and Mavic 2 remote
     *  controllers.
     */
    DJIRCFiveDButton fiveDButton;
} DJIRCHardwareState;

/*********************************************************************************/
#pragma mark DJIRCSecondaryVideoOutputPort
/*********************************************************************************/


/**
 *  Remote Controller port to which to send secondary video (in addition to USB
 *  video sent to the Mobile Device).
 */
typedef NS_ENUM (uint8_t, DJIRCSecondaryVideoOutputPort) {
    

    /**
     *  HDMI port.
     */
    DJIRCSecondaryVideoOutputPortHDMI,
    

    /**
     *  SDI port.
     */
    DJIRCSecondaryVideoOutputPortSDI,
    

    /**
     *  Unknown.
     */
    DJIRCSecondaryVideoOutputPortUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCSecondaryVideoDisplayMode
/*********************************************************************************/


/**
 *  Defines the combination of video sources to form the secondary output video. The
 *  secondary output can display video streams from one or two input sources. When
 *  the encode mode is single: Source 1 represents video from one of the Source1Only
 *  input ports (HDMI or AV). Source 2 represents video from EXT input port  (HD
 *  Gimbal Camera). When the encode mode is dual: Source 1 represents video from
 *  HDMI input port.  Source 2 represents video from AV input port.
 */
typedef NS_ENUM (uint8_t, DJIRCSecondaryVideoDisplayMode) {
    

    /**
     *  Displays video from Source 1 only. When the current encode  mode is single, the
     *  secondary output will display  video from HDMI or AV input.  When the current
     *  encode mode is dual, the secondary output will display video from HDMI input.
     */
    DJIRCSecondaryVideoDisplayModeSource1Only,
    

    /**
     *  Displays video from Source 2 only. When the current encode mode is single, the
     *  secondary output  will display video from HD Gimbal camera. When the current
     *  encode mode is dual, the secondary output  will display video from  AV input.
     */
    DJIRCSecondaryVideoDisplayModeSource2Only,
    

    /**
     *  Displays the video from Source 1 as the main subject, and the video from Source
     *  2 in a mini  window (Picture in  Picture, or PIP).
     */
    DJIRCSecondaryVideoDisplayModePIPSource1Main,
    

    /**
     *  Displays the video from Source 2 as the main subject, and the video from Source
     *  1 in a mini window (Picture in  Picture, or PIP).
     */
    DJIRCSecondaryVideoDisplayModePIPSource2Main,
    

    /**
     *  Unknown output mode.
     */
    DJIRCSecondaryVideoDisplayModeUnknown,
};

/*********************************************************************************/
#pragma mark DJIRCSecondaryVideoOSDUnit
/*********************************************************************************/


/**
 *  OSD data units.
 */
typedef NS_ENUM (uint8_t, DJIRCSecondaryVideoOSDUnit) {
    

    /**
     *  Imperial.
     */
    DJIRCSecondaryVideoOSDUnitImperial,
    

    /**
     *  Metric.
     */
    DJIRCSecondaryVideoOSDUnitMetric,
    

    /**
     *  Unknown.
     */
    DJIRCSecondaryVideoOSDUnitUnknown,
};

/*********************************************************************************/
#pragma mark DJIRCSecondaryVideoFormat
/*********************************************************************************/


/**
 *  Secondary output video resolution and frame rate.
 */
typedef NS_ENUM (uint8_t, DJIRCSecondaryVideoFormat) {
    

    /**
     *  1080I 60FPS.
     */
    DJIRCSecondaryVideoFormat1080I60FPS,
    

    /**
     *  1080I 50FPS.
     */
    DJIRCSecondaryVideoFormat1080I50FPS,
    

    /**
     *  1080P 60FPS.
     */
    DJIRCSecondaryVideoFormat1080P60FPS,
    

    /**
     *  1080P 50FPS.
     */
    DJIRCSecondaryVideoFormat1080P50FPS,
    

    /**
     *  1080P 30FPS.
     */
    DJIRCSecondaryVideoFormat1080P30FPS,
    

    /**
     *  1080P 25FPS.
     */
    DJIRCSecondaryVideoFormat1080P25FPS,
    

    /**
     *  1080P 24FPS.
     */
    DJIRCSecondaryVideoFormat1080P24FPS,
    

    /**
     *  720P 60FPS.
     */
    DJIRCSecondaryVideoFormat720P60FPS,
    

    /**
     *  720P 50FPS.
     */
    DJIRCSecondaryVideoFormat720P50FPS,
    

    /**
     *  720P 30FPS.
     */
    DJIRCSecondaryVideoFormat720P30FPS,
    

    /**
     *  720P 25FPS.
     */
    DJIRCSecondaryVideoFormat720P25FPS,
    

    /**
     *  720P 24FPS.
     */
    DJIRCSecondaryVideoFormat720P24FPS,
    

    /**
     *  Unknown.
     */
    DJIRCSecondaryVideoFormatUnknown,
};

/*********************************************************************************/
#pragma mark DJIRCPIPPosition
/*********************************************************************************/


/**
 *  PIP (Picture In Picture) position on the screen relative to the main subject
 *  video.
 */
typedef NS_ENUM (uint8_t, DJIRCPIPPosition) {
    

    /**
     *  PIP is on the screen's top left.
     */
    DJIRCPIPPositionTopLeft,
    

    /**
     *  PIP is on the screen's top right.
     */
    DJIRCPIPPositionTopRight,
    

    /**
     *  PIP is on the screen's bottom left.
     */
    DJIRCPIPPositionBottomLeft,
    

    /**
     *  PIP is on the screen's bottom right.
     */
    DJIRCPIPPositionBottomRight,
    

    /**
     *  PIP is on the screen's bottom right.
     */
    DJIRCPIPPositionUnknown,
};

/*********************************************************************************/
#pragma mark DJIRCFocusControllerControlType
/*********************************************************************************/


/**
 *  Remote Focus Control Type.
 */
typedef NS_ENUM (uint8_t, DJIRCFocusControllerControlType){
    

    /**
     *  Control Aperture.
     */
    DJIRCFocusControllerControlTypeAperture,
    

    /**
     *  Control Focal Length.
     */
    DJIRCFocusControllerControlTypeFocalLength,


    /**
     *  Adjust focus distance.
     */
    DJIRCFocusControllerControlTypeFocusDistance,

    /**
     *  Unknown types.
     */
    DJIRCFocusControllerControlTypeUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCFocusControllerDirection
/*********************************************************************************/


/**
 *  Remote Focus Control Direction.
 */
typedef NS_ENUM (uint8_t, DJIRCFocusControllerDirection){
    

    /**
     *  Clockwise.
     */
    DJIRCRemoteFocusControlDirectionClockwise,
 

    /**
     *  CounterClockwise.
     */
    DJIRCRemoteFocusControlDirectionCounterClockwise,
    

    /**
     *  Unknown.
     */
    DJIRCRemoteFocusControlDirectionUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCChargeMobileMode
/*********************************************************************************/


/**
 *  Modes to charge an iOS mobile device. Only supported by Inspire 2.
 */
typedef NS_ENUM (uint8_t, DJIRCChargeMobileMode){
 

    /**
     *  The remote controller does not charge the mobile device.
     */
    DJIRCChargeMobileModeNever,
 

    /**
     *  The remote controller charges the mobile device until the the mobile device is
     *  fully charged.
     */
    DJIRCChargeMobileModeAlways,
 

    /**
     *  The remote controller charges the mobile device in an intelligent mode: The
     *  remote controller starts charging when the mobile device's battery is lowered
     *  then 20% and stops charging when the mobile device's battery is above 50%. It is
     *  only supported by Inspire 2.
     */
    DJIRCChargeMobileModeIntelligent,
 

    /**
     *  The Remote Controller's charging mode is unknown.
     */
    DJIRCChargeMobileModeUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCCalibrationComponent
/*********************************************************************************/


/**
 *  The components on the remote controller that requires calibration.
 */
typedef NS_ENUM (uint8_t, DJIRCCalibrationComponent){

	/**
	 *  The components on the remote controller that requires calibration.
	 */
	DJIRCCalibrationComponentLeftStickVertical,
	

	/**
	 *  The horizontal dimension of the left stick. To calibrate it, user should move
	 *  the left stick left and right.
	 */
	DJIRCCalibrationComponentLeftStickHorizontal,
	

	/**
	 *  The vertical dimension of the right stick. To calibrate it, user should move the
	 *  right stick up and down.
	 */
	DJIRCCalibrationComponentRightStickVertical,
	

	/**
	 *  The horizontal dimension of the right stick. To calibrate it, user should move
	 *  the right stick left and right.
	 */
	DJIRCCalibrationComponentRightStickHorizontal,
	

	/**
	 *  The upper left wheel (gimbal dial).
	 */
	DJIRCCalibrationComponentLeftWheel,


    /**
     *  The upper right wheel.
     */
    DJIRCCalibrationComponentRightWheel,
    

    /**
     *  The left lever.
     */
    DJIRCCalibrationComponentLeftLever,
    

    /**
     *  The right lever.
     */
    DJIRCCalibrationComponentRightLever,
    

	/**
	 *  Unknown.
	 */
	DJIRCCalibrationComponentUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCCalibrationOverallState
/*********************************************************************************/


/**
 *  The overall state of the remote controller's calibration.
 */
typedef NS_ENUM (uint8_t, DJIRCCalibrationOverallState){
	

	/**
	 *  The calibration is started and the remote controller is recording the center
	 *  position of components. In this phase, user should not move the components.
	 */
	DJIRCCalibrationOverallStateRecordingCenter,
	

	/**
	 *  The remote controller has recorded the center position of components and is
	 *  recording the physical limits. In this phase, user should move components
	 *  (sticks and wheels) all the way to the physical limits in any direction.
	 */
	DJIRCCalibrationOverallStateRecordingPhysicalLimits,
	

	/**
	 *  The calibration took too long to finish.
	 */
	DJIRCCalibrationOverallStateTimeout,
	

	/**
	 *  The calibration failed. Use `error` to check the reason.
	 */
	DJIRCCalibrationOverallStateFailed,
	

	/**
	 *  The calibration succeeded.
	 */
	DJIRCCalibrationOverallStateSucceeded,
	

	/**
	 *  Unknown.
	 */
	DJIRCCalibrationOverallStateUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIRCCalibrationComponentState
/*********************************************************************************/


/**
 *  The calibration state for each component on the remote controller.
 */
@interface DJIRCCalibrationComponentState : NSObject

/**
 *  The calibration state for each component on the remote controller.
 */
@property (nonatomic, readonly) DJIRCCalibrationComponent component;


/**
 *  `YES` if the minimum physical limit is recorded.
 */
@property (nonatomic, readonly) BOOL isMinLimitRecorded;


/**
 *  `YES` if the maximum physical limit is recorded.
 */
@property (nonatomic, readonly) BOOL isMaxLimitRecorded;

@end



/**
 *  The progress for the whole calibration operation.
 */
@interface DJIRCCalibrationProgress : NSObject


/**
 *  The overall state of the calibration operation.
 */
@property (nonatomic, readonly) DJIRCCalibrationOverallState state;


/**
 *  The calibration states for components.
 */
@property (nonatomic, nullable, readonly) NSArray<DJIRCCalibrationComponentState *> *componentStates;


/**
 *  The error causes the calibration failure.
 */
@property (nonatomic, nullable, readonly) NSError *error;

@end


/*********************************************************************************/
#pragma mark DJIRCFocusControllerState
/*********************************************************************************/


/**
 *  Remote Controller's Remote Focus State. The focus product has one dial (focus
 *  control) that controls two separate parts of the camera: focal length and
 *  aperture. However it can only control one of these at any one time and is an
 *  absolute dial, meaning that a specific rotational position of the dial
 *  corresponds to a specific focal length or aperture. This means that whenever the
 *  dial control mode is changed, the dial first has to be reset to the new mode's
 *  previous dial position before the dial can be used to adjust the setting of the
 *  new mode. Example workflow:<br/><ol> - Use dial to set an Aperture of f2.2
 *   - Change dial control mode to focal length (set
 *  `DJIRCFocusControllerControlType`)
 *  - Use the dial to change the focal length
 *  - Change dial control mode back to aperture
 *  -  set `DJIRCFocusControllerControlType`
 *   - `isWorking` will now be NO
 *  -  Adjust dial back to f2.2
 *  - `DJIRCFocusControllerDirection` is the direction the dial should be rotated
 *  - `isWorking` will become YES when set back to f2.2
 *  - Now the dial can be used to adjust the aperture.</ol>
 */
typedef struct
{

    /**
     *  `YES` if the focus control works. The control can be either changing the
     *  Aperture or  Focal Length. If it is `NO`, follow  the
     *  `DJIRCFocusControllerDirection` to rotate the Remote Focus Device until it
     *  turns to `YES` again.
     */
    BOOL isWorking;
    

    /**
     *  Remote Focus Control Type.
     */
    DJIRCFocusControllerControlType controlType;
    

    /**
     *  Remote Focus Control Direction. Use this with  the `isWorking` value. It will
     *  give you the correct  rotation direction when `isWorking` is  `NO`.
     */
    DJIRCFocusControllerDirection direction;
    
} DJIRCFocusControllerState;

/*********************************************************************************/
#pragma mark - DJIRCInformation
/*********************************************************************************/


/**
 *  This class contains the information for a remote controller.
 */
@interface DJIRCInformation : NSObject


/**
 *  Remote Controller's unique identifier.
 */
@property(nonatomic, readonly) uint32_t ID;


/**
 *  Remote Controller's name.
 */
@property(nonatomic, readonly) NSString *_Nullable name;


/**
 *  Remote Controller's password.
 */
@property(nonatomic, readonly) NSString *_Nullable password;


/**
 *  Signal quality of a connected master or slave Remote Controller in percent [0,
 *  100].
 */
@property(nonatomic, readonly) uint8_t signalQuality;


/**
 *  `YES` if the slave remote controller can control the aircraft's gimbal.  Always
 *  `YES` for a master remote controller.
 */
@property(nonatomic, readonly) BOOL hasGimbalControlPermission;


/**
 *  Converts the Remote Controller's unique identifier from the  property `ID` to a
 *  string. Return the Remote Controller's identifier  as a string.
 *  
 *  @return A NSString object of the Remote Controller's unique identifier.
 */
- (NSString *_Nullable)RCIdentifier;

@end

/*********************************************************************************/
#pragma mark - DJIRCMasterSlaveState
/*********************************************************************************/


/**
 *  State of the remote controller related to the master and slave mode.
 */
@interface DJIRCMasterSlaveState : NSObject


/**
 *  The master/slave mode of the remote controller.
 */
@property(nonatomic, readonly) DJIRCMode mode;


/**
 *  `YES` if a slave remote controller joins a master remote controller.
 */
@property(nonatomic, readonly) BOOL isConnected;


/**
 *  ID of the master remote controller.
 */
@property(nonatomic, readonly) NSString *masterID;


/**
 *  ID of the slave remote controller.
 */
@property(nonatomic, readonly) NSString *slaveID;


/**
 *  Authorization code of the master remote controller that is a 6 element string of
 *  numbers.
 */
@property(nonatomic, readonly) NSString *authorizationCode;


/**
 *  `YES` if the remote controller has gimbal control.  Call
 *  `requestGimbalControlWithCompletion` to attain the gimbal control.
 *  
 *  @return `YES` if the remote controller has gimbal control.
 */
@property(nonatomic, readonly) BOOL hasGimbalControl;

@end


/**
 *  Remote controller credentials.
 */
@interface DJIRCCredentials : NSObject


/**
 *  Remote Controller's ID.
 */
@property(nonatomic, readonly) uint32_t ID;


/**
 *  Remote Controller's name.
 */
@property(nonatomic, readonly) NSString *_Nullable name;


/**
 *  Remote Controller's password.
 */
@property(nonatomic, readonly) NSString *_Nullable password;

+(instancetype) credentialsWithID:(uint32_t)ID name:(NSString * _Nullable)name password:(NSString * _Nullable)password;

@end


/**
 *  The object representing the stick mapping configuration of the remote
 *  controller.
 */
@interface DJIRCAircraftMapping : NSObject


/**
 *  Creates an instance of `DJIRCAircraftMapping` with the given style.
 *  
 *  @param style Error code.
 */
+(instancetype) mappingWithStyle:(DJIRCAircraftMappingStyle)style;


/**
 *  Creates an instance of `DJIRCAircraftMapping` with a custom style and given
 *  mapping configurations.
 *  
 *  @param leftVertical DJIRCAircraftStickMapping object.
 *  @param leftHorizontal DJIRCAircraftStickMapping object.
 *  @param rightVertical DJIRCAircraftStickMapping object.
 *  @param rightHorizontal DJIRCAircraftStickMapping object.
 */
+(instancetype) mappingWithCustomMappingLeftVertical:(DJIRCAircraftStickMapping)leftVertical
                                     leftHorizontal:(DJIRCAircraftStickMapping)leftHorizontal
                                      rightVertical:(DJIRCAircraftStickMapping)rightVertical
                                    rightHorizontal:(DJIRCAircraftStickMapping)rightHorizontal;


/**
 *  The mapping configuration for the left stick on the vertical axis.
 */
@property(nonatomic, readonly) DJIRCAircraftStickMapping leftVertical;


/**
 *  The mapping configuration for the left stick on the horizontal axis.
 */
@property(nonatomic, readonly) DJIRCAircraftStickMapping leftHorizontal;


/**
 *  The mapping configuration for the right stick on the vertical axis.
 */
@property(nonatomic, readonly) DJIRCAircraftStickMapping rightVertical;


/**
 *  The mapping configuration for the right stick on the horizontal axis.
 */
@property(nonatomic, readonly) DJIRCAircraftStickMapping rightHorizontal;


@end


/**
 *  The mapping styles to control the Gimbal.
 */
@interface DJIRCGimbalMapping : NSObject


/**
 *  Creates an instance of `DJIRCGimbalMapping` with the default mapping style.
 */
+(instancetype) mappingWithDefaultStyle;


/**
 *  Creates an instance of `DJIRCGimbalMapping` with a custom mapping style which
 *  will be defined using the passed mapping configurations.
 *  
 *  @param leftVertical The `DJIRCGimbalStickMapping` object.
 *  @param leftHorizontal The `DJIRCGimbalStickMapping` object.
 *  @param rightVertical The `DJIRCGimbalStickMapping` object.
 *  @param rightHorizontal The `DJIRCGimbalStickMapping` object.
 */
+(instancetype) mappingWithCustomMappingLeftVertical:(DJIRCGimbalStickMapping)leftVertical
                                     leftHorizontal:(DJIRCGimbalStickMapping)leftHorizontal
                                      rightVertical:(DJIRCGimbalStickMapping)rightVertical
                                    rightHorizontal:(DJIRCGimbalStickMapping)rightHorizontal;


/**
 *  The mapping configuration for the left stick on the vertical axis.
 */
@property(nonatomic, readonly) DJIRCGimbalStickMapping leftVertical;


/**
 *  The mapping configuration for the left stick on the horizontal axis.
 */
@property(nonatomic, readonly) DJIRCGimbalStickMapping leftHorizontal;


/**
 *  The mapping configuration for the right stick on the vertical axis.
 */
@property(nonatomic, readonly) DJIRCGimbalStickMapping rightVertical;


/**
 *  The mapping configuration for the right stick on the horizontal axis.
 */
@property(nonatomic, readonly) DJIRCGimbalStickMapping rightHorizontal;

@end

/*********************************************************************************/
#pragma mark DJIRCCustomButtonTags
/*********************************************************************************/

/**
 *  Tags for C1 and C2 buttons on the remote controller
 */
@interface DJIRCCustomButtonTags : NSObject


/**
 *  Button tag for custom button 2.
 *  
 *  @return Value that is the tag
 */
@property (nonatomic, nullable, readonly) NSNumber *c1ButtonTag;


/**
 *  Button tag for custom button 2
 *  
 *  @return Value that is the tag
 */
@property (nonatomic, nullable, readonly) NSNumber *c2ButtonTag;


/**
 *  Create a `DJIRCCustomButtonTags` instance with values for C1 and C2. A valid tag
 *  is an integer in range [0, 255].
 *  
 *  @param c1ButtonTag Button tag for custom button 1 with range [0, 255].
 *  @param c2ButtonTag Button tag for custom button 2 with range [0, 255].
 *  
 *  @return Instance of `DJIRCCustomButtonTags`. `nil` if the value is invalid, or both c1ButtonTag and c2ButtonTag are `nil`.
 */
-(nullable instancetype)initWithC1ButtonTag:(NSNumber *_Nullable)c1ButtonTag
                             andC2ButtonTag:(NSNumber *_Nullable)c2ButtonTag;

@end

/*********************************************************************************/
#pragma mark Customizable Buttons (Cendence)
/*********************************************************************************/


/**
 *  Actions that can be assigned to a customizable button. Some of the actions are
 *  reserved and the firmware will execute the corresponding actions even when the
 *  application is not connected. Some of the actions are defined by the mobile
 *  applications. The application is responsible for implementing the non firmware
 *  actions. The definitions used in DJI Go are provided. It is usually recommended
 *  to follow DJI Go's definitions for compability so if DJI Go is used at the same
 *  time as the SDK application the actions will be expected in both applications.
 */
typedef NS_ENUM(NSUInteger, DJIRCButtonAction) {

    /**
     *  Toggle the camera setting view. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom0                                = 0,

    /**
     *  Resets the gimbal attitude. The pitch and the yaw will point to the origin. It
     *  is supported by the firmware of Matrice 200 series v2. For the other products,
     *  the action has to be implemented by the application itself.
     */
    DJIRCButtonActionResetGimbal                            = 1,

    /**
     *  Switch the live view and the map view. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom3                                = 3,

    /**
     *  Clear the flight path in the map view. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom4                                = 4,

    /**
     *  Toggle the battery setting view. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom5                                = 5,

    /**
     *  Trigger central exposure metering. It is supported by the firmware of Matrice
     *  200 series v2. For the other products, the action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCentralExposureMetering                = 7,

    /**
     *  Toggles the AE Lock setting. The action has to be implemented by the application
     *  itself.
     */
    DJIRCButtonActionCustom8                                = 8,

    /**
     *  Toggle the LEDs on the four arms. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom9                                = 9,

    /**
     *  Reset FPV gimbal attitude to the center, the gimbal will rotate 45 degrees in
     *  pitch axis up and down when the action is trigger. It is supported by the
     *  firmware of Matrice 200 series and Matrice 200 V2 series. For the other
     *  products, the action has to be implemented by the application itself.
     */
    DJIRCButtonActionResetFPVGimbal                         = 12,

    /**
     *  Expand the live view from the FPV camera. The action has to be implemented by
     *  the application itself.
     */
    DJIRCButtonActionCustom13                               = 13,

    /**
     *  Trigger a Quick Spin. It is supported by the firmware of Inspire 2. For the
     *  other products, the action has to be implemented by the application itself.
     */
    DJIRCButtonActionQuickSpin                              = 14,

    /**
     *  Toggle the playback view. The action has to be implemented by the application
     *  itself.
     */
    DJIRCButtonActionCustom16                               = 16,

    /**
     *  Triggers focusing at the center of the live view. It is supported by the
     *  firmware of Matrice 200 series v2. For the other products, the action has to be
     *  implemented by the application itself.
     */
    DJIRCButtonActionCenterFocus                            = 17,

    /**
     *  Request gimbal control (for the slave remote controller). The action has to be
     *  implemented by the application itself.
     */
    DJIRCButtonActionCustom23                               = 23,

    /**
     *  Toggle `DJIGimbalModeYawFollow` and `DJIGimbalModeFree` for gimbal. It is
     *  supported by the firmware of Matrice 200 series v2. For the other products, the
     *  action has to be implemented by the application itself.
     */
    DJIRCButtonActionToggleGimbalMode                       = 24,

    /**
     *  Toggle the customizable button setting view. The action has to be implemented by
     *  the application itself.
     */
    DJIRCButtonActionCustom25                               = 25,

    /**
     *  Toggle AF and MF for camera. It is supported by the firmware of Matrice 200
     *  series v2. For the other products, the action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionToggleFocus                            = 26,

    /**
     *  Dismiss the warning tips. The action has to be implemented by the application
     *  itself.
     */
    DJIRCButtonActionCustom27                               = 27,

    /**
     *  Toggle the automatic movement of the landing gear. The action has to be
     *  implemented by the application itself.
     */
    DJIRCButtonActionCustom28                               = 28,

    /**
     *  Toggle the warning list view. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom29                               = 29,

    /**
     *  Switch frequency bands of the remote controller. It is supported by the firmware
     *  of Matrice 200 series. For the other products, the action has to be implemented
     *  by the application itself.
     */
    DJIRCButtonActionSwitchFrequency                        = 30,

    /**
     *  Set the home location of the aircraft to the current location of the aircraft.
     *  The action has to be implemented by the application itself.
     */
    DJIRCButtonActionCustom31                               = 31,

    /**
     *  Set the home location of the aircraft to the current location of the remote
     *  controller. The action has to be implemented by the application itself.
     */
    DJIRCButtonActionCustom32                               = 32,

    /**
     *  Trigger the camera focus. It is supported by the firmware of Matrice 200 series
     *  and Matrice 200 series v2. For the other products, the action has to be
     *  implemented by the application itself.
     */
    DJIRCButtonActionFocus                                  = 37,

    /**
     *  Toggle the composition mode for the Spotlight. The action has to be implemented
     *  by the application itself.
     */
    DJIRCButtonActionCustom41                               = 41,

    /**
     *  Toggle the peak focus. The action has to be implemented by the application
     *  itself.
     */
    DJIRCButtonActionCustom43                               = 43,

    /**
     *  Toggle the display of grid. The action has to be implemented by the application
     *  itself.
     */
    DJIRCButtonActionCustom44                               = 44,

    /**
     *  Toggle the display of histogram. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom45                               = 45,

    /**
     *  Switch the white balance settings. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom46                               = 46,

    /**
     *  Toggle the over-exposure warning. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom47                               = 47,

    /**
     *  Reset the gimbal yaw to align with the aircraft heading. The action has to be
     *  implemented by the application itself.
     */
    DJIRCButtonActionCustom52                               = 52,

    /**
     *  Retract or deploy the landing gear. It is supported by the firmware of Inspire
     *  2. For the other products, the action has to be implemented by the application
     *  itself.
     */
    DJIRCButtonActionToggleLandingGear                      = 54,

    /**
     *  Toggle the radar map. The action has to be implemented by the application
     *  itself.
     */
    DJIRCButtonActionCustom59                               = 59,

    /**
     *  Toggle the downward vision sensors. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom60                               = 60,

    /**
     *  Toggle the forward obstacle avoidance. The action has to be implemented by the
     *  application itself.
     */
    DJIRCButtonActionCustom61                               = 61,

    /**
     *  Switch the video source of the secondary video feeder between fpv and camera.
     *  The action has to be implemented by the application itself.
     */
    DJIRCButtonActionCustom62                               = 62,

    /**
     *  Toggle the full screen mode. The action has to be implemented by the application
     *  itself.
     */
    DJIRCButtonActionCustom63                               = 63,
    
    /**
     *  EV+
     */
    DJIRCButtonActionEvAdd                                  = 83,
    
    /**
     *  EV-
     */
    DJIRCButtonActionEvMinus                                = 84,
    
    /**
     *  Aperture+
     */
    DJIRCButtonActionApertureAdd                            = 91,
    
    /**
     *  Aperture-
     */
    DJIRCButtonActionApertureMinus                          = 92,
    
    /**
     *  IRCUTSwitch
     */
    DJIRCButtonActionIRCUTSwitch                            = 93,
    
    /**
     *  Metering/Focus Switch
     */
    DJIRCButtonActionMeteringFocusSwitch                    = 94,
    
    /**
     *  Wide/Zoom Switch
     */
    DJIRCButtonActionWideZoomSwitch                         = 95,
    
    /**
     *  IR/VL Switch
     */
    DJIRCButtonActionIRVLSwitch                             = 96,
    
    /**
     *  FFCTriger
     */
    DJIRCButtonActionFFCTriger                              = 97,
    
    /**
     *  Beacon Switch
     */
    DJIRCButtonActionMeteringBeaconSwitch                   = 98,
    
    /**
     *  Flight Hub LiveView Switch
     */
     DJIRCButtonActionFlightHubLiveViewSwitch               = 99,

    /**
     *  Zoom out. It is only supported by Z30 camera. It is supported by the firmware of
     *  Matrice 200 V2 series. For the other products, the action has to be implemented
     *  by the application itself.
     */
    DJIRCButtonActionZoomOut                                = 100,

    /**
     *  Zoom in. It is only supported by Z30 camera. It is supported by the firmware of
     *  Matrice 200 V2 series. For the other products, the action has to be implemented
     *  by the application itself.
     */
    DJIRCButtonActionZoomIn                                 = 101,

    /**
     *  Custom action with value 102. This value is reserved for SDK applications.
     */
    DJIRCButtonActionCustom102                              = 102,

    /**
     *  Toggle the `DJICameraDisplayMode`. It is only supported by XT2 camera. It is
     *  supported by the firmware of Matrice 200 series v2. For the other products, the
     *  action has to be implemented by the application itself.
     */
    DJIRCButtonActionToggleDisplayMode                      = 103,

    /**
     *  Custom action with value 104. This value is reserved for SDK applications.
     */
    DJIRCButtonActionCustom104                              = 104,

    /**
     *  Custom action with value 105. This value is reserved for SDK applications.
     */
    DJIRCButtonActionCustom105                              = 105,

    /**
     *  Custom action with value 106. This value is reserved for SDK applications.
     */
    DJIRCButtonActionCustom106                              = 106,

    /**
     *  Custom action with value 107. This value is reserved for SDK applications.
     */
    DJIRCButtonActionCustom107                              = 107,

    /**
     *  Custom action with value 108. This value is reserved for SDK applications.
     */
    DJIRCButtonActionCustom108                              = 108,

    /**
     *  Custom action with value 109. This value is reserved for SDK applications.
     */
    DJIRCButtonActionCustom109                              = 109,

    /**
     *  Not defined. It is used to present that no action is bound to a button.
     */
    DJIRCButtonActionNotDefined                             = 110,
    
    /**
     *  SDR LTE Switch.
     */
     DJIRCButtonActionSDRLTESwitch                          = 141,
    
    /**
     *  Temperature Alert Switch
     */
     DJIRCButtonActionTemperatureAlertSwitch                = 142,
    
    /**
     *  Thermometric Switch
     */
     DJIRCButtonActionThermometricSwitch                    = 143,
    
    /**
     *  Switch To Left Camera
     */
     DJIRCButtonActionSwitchToLeftCamera                    = 144,
    
    /**
     *  Switch To Right Camera
     */
     DJIRCButtonActionSwitchToRightCamera                    = 145,
    
    /**
     *  Switch To Up Camera
     */
     DJIRCButtonActionSwitchToUpCamera                       = 146,

    /**
     *  Triggers the widget of the payload device in the index of 0. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom150                              = 150,

    /**
     *  Triggers the widget of the payload device in the index of 1. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom151                              = 151,

    /**
     *  Triggers the widget of the payload device in the index of 2. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom152                              = 152,

    /**
     *  Triggers the widget of the payload device in the index of 3. It is supported by
     *  the firmware of Matrice 200 V2 series. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom153                              = 153,

    /**
     *  Triggers the widget of the payload device in the index of 4. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom154                              = 154,

    /**
     *  Triggers the widget of the payload device in the index of 5. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom155                              = 155,

    /**
     *  Triggers the widget of the payload device in the index of 6. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom156                              = 156,

    /**
     *  Triggers the widget of the payload device in the index of 7. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom157                              = 157,

    /**
     *  Triggers the widget of the payload device in the index of 8. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom158                              = 158,

    /**
     *  Triggers the widget of the payload device in the index of 9. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom159                              = 159,

    /**
     *  Triggers the widget of the payload device in the index of 10. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom160                              = 160,

    /**
     *  Triggers the widget of the payload device in the index of 11. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom161                              = 161,

    /**
     *  Triggers the widget of the payload device in the index of 12. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom162                              = 162,

    /**
     *  Triggers the widget of the payload device in the index of 13. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom163                              = 163,

    /**
     *  Triggers the widget of the payload device in the index of 14. It is supported by
     *  the firmware of Matrice 200 series v2. For the other products, the action has to
     *  be implemented by the application itself.
     */
    DJIRCButtonActionCustom164                              = 164,
    /**
     * Pitch Down.
     */
    DJIRCButtonActionGimbalPitchDown                        = 205,
    /**
     * Pitch Reset/Down.
     */
    DJIRCButtonActionGimbalPitchCenterDown                  = 206,
    /**
     * Gimbal Down.
     */
    DJIRCButtonActionGimbalDown                             = 207,
};


/**
 *  The customizable buttons.
 */
typedef NS_ENUM(NSUInteger, DJIRCCustomizableButton) {

	/**
	 *  The button with C1 label.
	 */
	DJIRCCustomizableButtonC1,

	/**
	 *  The button with C2 label.
	 */
	DJIRCCustomizableButtonC2,

	/**
	 *  The button with C3 label.
	 */
	DJIRCCustomizableButtonC3,

	/**
	 *  The button with C4 label.
	 */
	DJIRCCustomizableButtonC4,

	/**
	 *  The button with BA label.
	 */
	DJIRCCustomizableButtonBA,

	/**
	 *  The button with BB label.
	 */
	DJIRCCustomizableButtonBB,

	/**
	 *  The button with BC label.
	 */
	DJIRCCustomizableButtonBC,

	/**
	 *  The button with BD label.
	 */
	DJIRCCustomizableButtonBD,

	/**
	 *  The button with BE label.
	 */
	DJIRCCustomizableButtonBE,

	/**
	 *  The button with BF label.
	 */
	DJIRCCustomizableButtonBF,

	/**
	 *  The button with BG label.
	 */
	DJIRCCustomizableButtonBG,

	/**
	 *  The button with BH label.
	 */
	DJIRCCustomizableButtonBH,

	/**
	 *  The button with MENU label.
	 */
	DJIRCCustomizableButtonMENU = 16,

    /**
     *  The button with TD label.
     */
    DJIRCCustomizableButtonTD,

    /**
     *  The button with LW label.
     */
    DJIRCCustomizableButtonLW,

    /**
     *  The button with RW label.
     */
    DJIRCCustomizableButtonRW,

    /**
     *  The button with LS label.
     */
    DJIRCCustomizableButtonLS,

    /**
     *  The button with RS label.
     */
    DJIRCCustomizableButtonRS,
    //hidden DJIRemoteController_DJIRCCustomizableButton_FIVE_D_DOWN
    /**
     *  Five dimension down.
     */
    DJIRCCustomizableButtonFiveDimensionDown,
    //hidden: DJIRemoteController_DJIRCCustomizableButton_FIVE_D_UP
    /**
     *  Five dimension up.
     */
    DJIRCCustomizableButtonFiveDimensionUp,
    //hidden: DJIRemoteController_DJIRCCustomizableButton_FIVE_D_LEFT
    /**
     *  Five dimension left.
     */
    DJIRCCustomizableButtonFiveDimensionLeft,
    //hidden: DJIRemoteController_DJIRCCustomizableButton_FIVE_D_RIGHT
    /**
     *  Five dimension right.
     */
    DJIRCCustomizableButtonFiveDimensionRight,
    //hidden: DJIRemoteController_DJIRCCustomizableButton_FIVE_D_PRESSED
    /**
     *  Five dimension pressed.
     */
    DJIRCCustomizableButtonFiveDimensionPressed,

    /**
     *  Unknown.
     */
	DJIRCCustomizableButtonUnknown = 0xFF,
};

@class DJIMutableRCButtonConfiguration;


/**
 *  The configuration for the customizable buttons on the remote controller. The
 *  configuration returned by SDK interfaces is immutable. Call `mutableCopy` to get
 *  a mutable copy in class `DJIMutableRCButtonConfiguration` and change the
 *  configuration.
 */
@interface DJIRCButtonConfiguration : NSObject <NSCopying, NSMutableCopying>


/**
 *  Action bound to the C1 button.
 */
@property (nonatomic, readonly) DJIRCButtonAction C1Action;


/**
 *  Action bound to the C2 button.
 */
@property (nonatomic, readonly) DJIRCButtonAction C2Action;


/**
 *  Action bound to the C3 button.
 */
@property (nonatomic, readonly) DJIRCButtonAction C3Action;


/**
 *  Action bound to the C4 button.
 */
@property (nonatomic, readonly) DJIRCButtonAction C4Action;


/**
 *  Action bound to the BA button.
 */
@property (nonatomic, readonly) DJIRCButtonAction BAAction;


/**
 *  Action bound to the BB button.
 */
@property (nonatomic, readonly) DJIRCButtonAction BBAction;


/**
 *  Action bound to the BC button.
 */
@property (nonatomic, readonly) DJIRCButtonAction BCAction;


/**
 *  Action bound to the BD button.
 */
@property (nonatomic, readonly) DJIRCButtonAction BDAction;


/**
 *  Action bound to the BE button.
 */
@property (nonatomic, readonly) DJIRCButtonAction BEAction;


/**
 *  Action bound to the BF button.
 */
@property (nonatomic, readonly) DJIRCButtonAction BFAction;


/**
 *  Action bound to the BG button.
 */
@property (nonatomic, readonly) DJIRCButtonAction BGAction;


/**
 *  Action bound to the BH button.
 */
@property (nonatomic, readonly) DJIRCButtonAction BHAction;


/**
 *  Action bound to the TD button.
 */
@property (nonatomic, readonly) DJIRCButtonAction TDAction;


/**
 *  Action bound to the MENU button.
 */
@property (nonatomic, readonly) DJIRCButtonAction MENUAction;


/**
 *  Action bound to the LS button.
 */
@property (nonatomic, readonly) DJIRCButtonAction LSAction;


/**
 *  Action bound to the RS button.
 */
@property (nonatomic, readonly) DJIRCButtonAction RSAction;


/**
 *  A dictionary representing the mapping between a customizable button and its
 *  action. The key is a `NSNumber` with value among `DJIRCCustomizableButton` and
 *  the value is a `NSNumber` with value among `DJIRCButtonAction`.
 */
@property (nonatomic, readonly)  NSDictionary<NSNumber *, NSNumber *> *buttonActions;


/**
 *  Fetch a dictionary representing the mapping between a customizable button and
 *  its action. The key is a `NSNumber` with value among `DJIRCCustomizableButton`
 *  and the value is a `NSNumber` with value among `DJIRCButtonAction`.
 *  
 *  @return An NSDictionary of NSNumber objects.
 */
+(NSDictionary<NSNumber *,NSNumber *> *)defaultButtonActions;


/**
 *  Gets the valid actions for a button. For the compatbility with DJI Go, there are
 *  rules to follow when assigning an action to a button:
 *   - `DJIRCButtonActionNotDefined` is valid for all buttons and it can be assigned
 *  to multiple buttons.
 *   - An action can be only assigned to one button.
 *   - For Button TD, the possible valid actions include
 *  `DJIRCButtonActionNotDefined`, `DJIRCButtonActionFocus` and the actions reserved
 *  by SDK (e.g. `DJIRCButtonActionZoomOut`).
 *  
 *  @param button The button to check.
 *  
 *  @return The list of valid actions for a button.
 */
- (NSArray *)getValidActionsForButton:(DJIRCCustomizableButton)button;

@end


/**
 *  The mutable configuration for the customizable buttons on the remote controller.
 *  For the compatibility with DJI Go, there are rules to follow when assigning an
 *  action to a button. Refer to `getValidActionsForButton` for more detail.
 */
@interface DJIMutableRCButtonConfiguration : DJIRCButtonConfiguration


/**
 *  Action bound to the C1 button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction C1Action;


/**
 *  Action bound to the C2 button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction C2Action;


/**
 *  Action bound to the C3 button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction C3Action;


/**
 *  Action bound to the C4 button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction C4Action;


/**
 *  Action bound to the BA button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction BAAction;


/**
 *  Action bound to the BB button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction BBAction;


/**
 *  Action bound to the BC button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction BCAction;


/**
 *  Action bound to the BD button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction BDAction;


/**
 *  Action bound to the BE button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction BEAction;


/**
 *  Action bound to the BF button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction BFAction;


/**
 *  Action bound to the BG button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction BGAction;


/**
 *  Action bound to the BH button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction BHAction;


/**
 *  Action bound to the TD button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction TDAction;


/**
 *  Action bound to the MENU button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction MENUAction;


/**
 *  Action bound to the LS button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction LSAction;


/**
 *  Action bound to the RS button.
 */
@property (nonatomic, readwrite) DJIRCButtonAction RSAction;


/**
 *  Configures a button with an action.
 *  
 *  @param button The button to configure.
 *  @param action The action to be bound with the button.
 *  
 *  @return `YES` if the configuration succeeds.
 */
- (BOOL)configButton:(DJIRCCustomizableButton)button withAction:(DJIRCButtonAction)action;
@end



/*********************************************************************************/
#pragma mark - Multi-device Pairing Types
/*********************************************************************************/


/**
 *  Types of the device that the remote controller can pair with. It is only used
 *  when the remote controller supports multi-device pairing. Only Supported by
 *  Phantom 4 RTK.
 */
typedef NS_ENUM (uint8_t, DJIRCPairingDevice){

    /**
     *  The device to be paired with is an aircraft.
     */
    DJIRCPairingDeviceAircraft,


    /**
     *  The device to be paired with is an RTK base station.
     */
    DJIRCPairingDeviceRTKBaseStation,


    /**
     *  Unknown.
     */
    DJIRCPairingDeviceUnknown = 0xFF,
};


/**
 *  The state (e.g. unpaired, paired, connected, etc.) of a device that may
 *  connected to the remote controller. It is only used when the remote controller
 *  supports multi-device pairing. Only supported by DJI Phantom 4 RTK.
 */
typedef NS_ENUM(uint8_t, DJIRCMultiDeviceState) {

    /**
     *  The remote controller is unpaired with the device. This state is for both
     *  aircraft and base station.
     */
    DJIRCMultiDeviceStateUnpaired = 0,

    /**
     *  The remote controller is pairing with the device. This state is only for
     *  aircraft.
     */
    DJIRCMultiDeviceStatePairing,

    /**
     *  The remote controller is paired. This state is only for aircraft.
     */
    DJIRCMultiDeviceStatePaired,


    /**
     *  The remote controller is paired with the device but the connection between the
     *  device  and the remote controller is broken. The remote controller already
     *  remembers the device and the connection will receover automatically when it is
     *  possible. This state is only for base station. Only Supported by Phantom 4 RTK.
     */
    DJIRCMultiDeviceStateDisconnected,


    /**
     *  The remote controller is paired with the device and it is connected to the
     *  device. This state is only for base station.
     */
    DJIRCMultiDeviceStateConnected,


    /**
     *  Unknown.
     */
    DJIRCMultiDeviceStateUnknown = 0xFF,
};

#pragma mark - Soft-switch Joystick Mode


/**
 *  Joy stick mode on the remote controller. It is only used when the remote
 *  controller doesn't have a mode switch. Only Supported by Mavic Mini, DJI Mini
 *  SE.
 */
typedef NS_ENUM (uint8_t, DJIRCSoftSwitchJoyStickMode){

    /**
     *  Set the joy stick to sport mode. Only Supported by Mavic Mini, DJI Mini SE.
     */
    DJIRCSoftSwitchJoyStickMode_S = 0,
    

    /**
     *  Set the joy stick to position mode. Only Supported by Mavic Mini, DJI Mini SE.
     */
    DJIRCSoftSwitchJoyStickMode_P,
    

    /**
     *  Set the joy stick to tripod mode. Only Supported by Mavic Mini, DJI Mini SE.
     */
    DJIRCSoftSwitchJoyStickMode_T,
    

    /**
     *  Unknown.
     */
    DJIRCSoftSwitchJoyStickModeUnknown = 0xFF
};


/**
 *  The aggregation state related to devices that can pair to the remote controller.
 *  It contains the pairing  state and the connection state of the device (aircraft
 *  or RTK base station). It is only used when the remote controller supports multi-
 *  device pairing. Only Supported by Phantom 4 RTK.
 */
@interface DJIRCMultiDeviceAggregationState : NSObject


/**
 *  The device state of aircraft.
 */
@property (nonatomic, readonly) DJIRCMultiDeviceState aircraftState;


/**
 *  The device state of RTK base station.
 */
@property (nonatomic, readonly) DJIRCMultiDeviceState RTKBaseStationState;

@end

NS_ASSUME_NONNULL_END

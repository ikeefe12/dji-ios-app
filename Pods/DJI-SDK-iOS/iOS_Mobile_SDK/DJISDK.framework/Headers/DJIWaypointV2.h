//
//  DJIWaypointV2.h
//  DJISDK
//
//  Copyright © 2019, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "DJISDKFoundation.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  Waypoint flight path mode.
 */
typedef NS_ENUM (NSUInteger, DJIWaypointV2FlightPathMode){
    

    /**
     *  In the mission, the aircraft will go to the waypoint along a curve and fly past
     *  the waypoint.
     */
    DJIWaypointV2FlightPathModeGoToPointAlongACurve,
    

    /**
     *  In the mission, the aircraft will go to the waypoint along a curve and stop at
     *  the waypoint.
     */
    DJIWaypointV2FlightPathModeGoToPointAlongACurveAndStop,
    

    /**
     *  In the mission, the aircraft will go to the waypoint along a straight line and
     *  stop at the waypoint.
     */
    DJIWaypointV2FlightPathModeGoToPointInAStraightLineAndStop,
    

    /**
     *  In the mission, the aircraft will fly from the previous waypoint to the next
     *  waypoint along a smooth curve  without stopping at this waypoint. the next in a
     *  curved motion, adhering to the `dampingDistance`,  which is set in
     *  `DJIWaypointV2`.
     */
    DJIWaypointV2FlightPathModeCoordinateTurn,
    

    /**
     *  In the mission, the aircraft will go to the first waypoint along a straight
     *  line. This is only valid for the first waypoint.
     */
    DJIWaypointV2FlightPathModeGoToFirstPointAlongAStraightLine,
    

    /**
     *  Straight exit the Last waypoint, Only valid for last waypoint.
     */
    DJIWaypointV2FlightPathModeStraightOut,
    

    /**
     *  Unknown.
     */
    DJIWaypointV2FlightPathModeUnknown = 0xFF,
};


/**
 *  Represents current aircraft's heading mode on current waypoint.
 */
typedef NS_ENUM (NSUInteger, DJIWaypointV2HeadingMode){
    

    /**
     *  Aircraft's heading will always be in the direction of flight.
     */
    DJIWaypointV2HeadingModeAuto,
    

    /**
     *  Aircraft's heading will be set to the heading when reaching the first waypoint.
     *  Before reaching the  first waypoint, the aircraft's heading can be controlled by
     *  the remote controller. When the aircraft  reaches the first waypoint, its
     *  heading will be fixed.
     */
    DJIWaypointV2HeadingModeFixed,
    

    /**
     *  The aircraft's heading in the mission can be controlled by the remote
     *  controller.
     */
    DJIWaypointV2HeadingModeManual,
    

    /**
     *  In the mission, the aircraft's heading will change dynamically and adapt to the
     *  heading set at the next waypoint.  See `heading` to preset the heading.
     */
    DJIWaypointV2HeadingModeWaypointCustom,
    

    /**
     *  After the first waypoint has been reached, aircraft heading will always toward
     *  to the point of interest. Using `pointOfInterest` and `pointOfInterestAltitude`
     *  to set the coordinate of point of interest.
     */
    DJIWaypointV2HeadingModeTowardPointOfInterest,
    

    /**
     *  The aircraft's heading rotates simultaneously with its gimbal's yaw.
     */
    DJIWaypointV2HeadingModeGimbalYawFollow,
    

    /**
     *  Unknown.
     */
    DJIWaypointV2HeadingModeUnknown = 0xFF,
};


/**
 *  The direction when the aircraft changes its heading to adapt to the heading at
 *  the waypoint.
 */
typedef NS_ENUM (NSUInteger, DJIWaypointV2TurnMode){


    /**
     *  The aircraft's heading rotates clockwise.
     */
    DJIWaypointV2TurnModeClockwise,


    /**
     *  The aircraft's heading rotates counterclockwise.
     */
    DJIWaypointV2TurnModeCounterClockwise,


    /**
     *  Changes the heading of the aircraft by rotating the aircraft anti-clockwise.
     */
    DJIWaypointV2TurnModeUnknown = 0xFF,
};


/**
 *  The class represents a target point in the waypoint mission. For a waypoint
 *  mission, a flight route consists of multiple `DJIWaypointV2` objects.
 */
@interface DJIWaypointV2 : NSObject


/**
 *  Waypoint coordinate latitude and longitude in degrees.
 */
@property(nonatomic, assign) CLLocationCoordinate2D coordinate;


/**
 *  Altitude of the aircraft in meters when it reaches waypoint. The altitude of the
 *  aircraft is relative to  the ground at the take-off location, has a  range of
 *  [-200,500], and should not be larger than the aircraft's maximum altitude. If
 *  two adjacent waypoints have different altitudes, the altitude  will gradually
 *  change as the aircraft flies between waypoints.
 */
@property(nonatomic, assign) float altitude;


/**
 *  Property is used when `headingMode` is
 *  `DJIWaypointV2HeadingModeTowardPointOfInterest`. Aircraft will always be heading
 *  to  point while executing mission. Default is "kCLLocationCoordinate2DInvalid".
 */
@property(nonatomic, assign) CLLocationCoordinate2D pointOfInterest;


/**
 *  Property is used when `headingMode` is
 *  `DJIWaypointV2HeadingModeTowardPointOfInterest`. The altitude of the aircraft is
 *  relative  to the ground at the take-off location, has a range of [-200,500], and
 *  should not be larger than the  aircraft's maximum altitude.
 */
@property(nonatomic, assign) float pointOfInterestAltitude;


/**
 *  Flight path mode waypoint of the aircraft as it moves between waypoints. Default
 *  is `DJIWaypointV2FlightPathModeGoToPointAlongACurveAndStop`.
 */
@property(nonatomic, assign) DJIWaypointV2FlightPathMode flightPathMode;


/**
 *  Heading of the aircraft as it moves between waypoints. Default is
 *  `DJIWaypointV2HeadingModeAuto`.
 */
@property(nonatomic, assign) DJIWaypointV2HeadingMode headingMode;


/**
 *  The heading to which the aircraft will rotate by the time it reaches the
 *  waypoint. The aircraft heading  will gradually change between two waypoints with
 *  different headings if the waypoint mission's `DJIWaypointV2HeadingMode` is set
 *  to `DJIWaypointV2HeadingModeWaypointCustom`. A heading has a range  of [-180,
 *  180] degrees, where 0 represents True North.
 */
@property(nonatomic, assign) NSInteger heading;


/**
 *  Determines whether the aircraft will turn clockwise or anticlockwise when
 *  changing its heading.
 */
@property(nonatomic, assign) DJIWaypointV2TurnMode turnMode;


/**
 *  Determines whether the aircraft using waypoint max flight speed executing
 *  waypoint mission. If `YES`, the aircraft will use waypoint max flight speed
 *  between two waypoints.  Otherwise, will use `maxFlightSpeed` as max flight
 *  speed.
 */
@property(nonatomic, assign) BOOL isUsingWaypointMaxFlightSpeed;


/**
 *  While the aircraft is travelling between waypoints, you can offset its speed by
 *  using the throttle joystick on the remote controller. `maxFlightSpeed` is this
 *  offset  when the joystick is pushed to maximum deflection. For example, If
 *  maxFlightSpeed is 10 m/s, then pushing the throttle joystick all the way up will
 *  add 10 m/s to the aircraft speed,  while pushing down will subtract 10 m/s from
 *  the aircraft speed. If the remote controller stick is not at maximum deflection,
 *  then the offset speed will be interpolated  between "[0, `maxFlightSpeed`]""
 *  with a resolution of 1000 steps. If the offset speed is negative, then the
 *  aircraft will fly backwards to previous waypoints. When it  reaches the first
 *  waypoint, it will then hover in place until a positive speed is applied.
 *  `maxFlightSpeed` has a range of [2,15] m/s.
 */
@property(nonatomic, assign) float maxFlightSpeed;


/**
 *  Determines whether the aircraft using waypoint auto flight speed executing
 *  waypoint mission. If `YES`, the aircraft will use waypoint auto flight speed
 *  between two waypoints. Otherwise,  will use `autoFlightSpeed` as max flight
 *  speed.
 */
@property(nonatomic, assign) BOOL isUsingWaypointAutoFlightSpeed;


/**
 *  The base automatic speed of the aircraft as it moves between waypoints with
 *  range [-15, 15] m/s. The aircraft's actual speed is a combination of the base
 *  automatic speed, and the speed control  given by the throttle joystick on the
 *  remote controller. If "`autoFlightSpeed` >0": Actual speed is `autoFlightSpeed`
 *  + Joystick Speed (with combined max  of `maxFlightSpeed`) If "`autoFlightSpeed`
 *  =0": Actual speed is controlled only by the remote controller joystick. If
 *  "`autoFlightSpeed` <0" and  the aircraft is at the first waypoint, the aircraft
 *  will hover in place until the speed is made positive by the remote controller
 *  joystick. In flight controller firmware 3.2.10.0 or above,  different speeds
 *  between individual waypoints can also be set in waypoint objects which will
 *  overwrite `autoFlightSpeed`.
 */
@property(nonatomic, assign) float autoFlightSpeed;


/**
 *  Corner radius of the waypoint. When the flight path mode is
 *  `DJIWaypointV2FlightPathModeCoordinateTurn` the flight path near a waypoint will
 *  be acurve (rounded corner) with  radius [0.2,1000]. When there is a corner
 *  radius, the aircraft will never pass the waypoint. By default, the radius is 0.2
 *  m. If the corner is made of three adjacent waypoints (Short for A,B,C).  Then
 *  the radius of A(short for Ra) plus radius of B(short for Rb) must be smaller
 *  than the distance between  A and B. The radius of the first and the last
 *  waypoint in a mission does not affect the  flight path and it should keep the
 *  default value (0.2m). When the flight path mode is
 *  `DJIWaypointV2FlightPathModeGoToFirstPointAlongAStraightLine` When aircraft
 *  reaches the first waypoint,  The flight path will be a straight flight with this
 *  distance. When the flight path mode is `DJIWaypointV2FlightPathModeStraightOut`
 *  The flight path will be a straight flight with this distance  before until last
 *  waypoint.
 */
@property(nonatomic, readwrite) float dampingDistance;


/**
 *  Initiate instance with specific waypoint.
 *  
 *  @param coordinate Coordinate Object.
 *  
 *  @return A `DJIWaypointV2` object initialized with CLLocationCoordinate2D struct.
 */
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

@end

NS_ASSUME_NONNULL_END

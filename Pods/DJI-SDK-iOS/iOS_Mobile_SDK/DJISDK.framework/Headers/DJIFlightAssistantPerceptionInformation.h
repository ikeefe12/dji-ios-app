//
//  DJIFlightAssistantPerceptionInformation.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  This class contains the aircraft's perception information. It is supported only
 *  by Matrice 300 RTK.
 */
@interface DJIFlightAssistantPerceptionInformation : NSObject


/**
 *  The perception package count.
 */
@property(nonatomic, readonly) NSUInteger dataPackageIndex;


/**
 *  Distance value detected away from the obstacles are at an interval of angle
 *  around the aircraft in 360 degrees horizontally.
 */
@property(nonatomic, readonly) NSUInteger horizontalObjectCount;


/**
 *  Each value represents the distance in millimeters away from the obstacles
 *  detected around in 360 degrees horizontally at an interval of angle. Please
 *  refer to `dataPackageIndex` to get the interval of angle. 0 degree points to the
 *  aircraft's heading. 90 degrees point to the right of the aircraft. 180 degrees
 *  point to the aircraft's tail.
 */
@property(nonatomic, readonly) NSArray<NSNumber*>* distanceArray;


/**
 *  The upward obstacle distance.
 */
@property(nonatomic, readonly) NSUInteger upwardObstacleDistance;


/**
 *  The downward obstacle distance. Not supported by Mavic Air 2 and DJI Air 2S
 *  
 *  @return An int value of downward obstacle distance.
 */
@property(nonatomic, readonly) NSUInteger downwardObstacleDistance;

@end

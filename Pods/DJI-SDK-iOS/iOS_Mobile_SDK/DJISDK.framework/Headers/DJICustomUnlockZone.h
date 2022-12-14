//
//  DJICustomUnlockZone.h
//  DJISDK
//
//  Copyright © 2017, DJI. All rights reserved.
//

#import "DJISDKFoundation.h"
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  An enum class represents the type of custom unlocking.
 */
typedef NS_ENUM(NSUInteger, DJICustomUnlockType) {
    

    /**
     *  The custom unlock zone is a circle.
     */
    DJICustomUnlockTypeCircle,
    

    /**
     *  The custom unlock zone is a country.
     */
    DJICustomUnlockTypeCountry,
    

    /**
     *  Unlock the max flight altitude limit in the custom unlock zone.
     */
    DJICustomUnlockTypeMaxFlightAltitudeLimit,
    

    /**
     *  The custom unlock zone is a polygon.
     */
    DJICustomUnlockTypePolygon,
    

    /**
     *  The custom unlock type is unknown.
     */
    DJICustomUnlockTypeUnknown = 0xFF,
};


/**
 *  Users can unlock areas of a restricted fly zone through
 *  <http://www.dji.com/flysafe/custom-unlock>.  A user needs to show special
 *  authorization (usually from a third party such as a regulatory  or managing
 *  agency) as part of the process to unlock the area within the restricted fly
 *  zone.  Therefore each request is unique and customized to the individual. If the
 *  request is successful,  the unlocked area is tied to the user's account as an
 *  Custom Unlock Zone.
 *  This class contains the properties of an Custom Unlock Zone.
 */
@interface DJICustomUnlockZone : NSObject


/**
 *  The unique ID of the Custom Unlock Zone.
 */
@property(nonatomic, readonly) NSUInteger ID;


/**
 *  The type of custom unlocking.
 */
@property(nonatomic, readonly) DJICustomUnlockType type;


/**
 *  Name of the Custom Unlock Zone.
 */
@property(nonatomic, readonly) NSString* name;


/**
 *  The coordinate of the Custom Unlock Zone's center. Only used when `type`  is
 *  `DJICustomUnlockTypeCircle`.
 */
@property(nonatomic, readonly) CLLocationCoordinate2D center;


/**
 *  The radius of the Custom Unlock Zone in meters. Valid when `type`  is
 *  `DJICustomUnlockTypeCircle`.
 */
@property(nonatomic, readonly) double radius;


/**
 *  Check country code (https://www.iso.org/iso-3166-country-codes.html) for the
 *  custom unlock zone's shape.  Valid when `type` is `DJICustomUnlockTypeCountry`.
 */
@property(nonatomic, readonly) NSString* countryCode;


/**
 *  The unlocked max flight altitude limit in the custom unlock zone. Valid when
 *  `type`  is `DJICustomUnlockTypeMaxFlightAltitudeLimit`.
 */
@property(nonatomic, readonly) float maxFlightAltitude;


/**
 *  The vertices (locations) that make up the custom unlock zone shape. Only used
 *  when `type` is `DJICustomUnlockTypePolygon`.
 */
@property(nonatomic, readonly) NSArray<NSValue *> *vertices;


/**
 *  The timestamp of when the unlocking begins, formatted in UTC (YYYY-MM-DD
 *  hh:mm:ss).  When the time is not available from the server,
 *  `DJIFlyZoneInformationInvalidTimestamp` will be returned.
 */
@property(nonatomic, readonly) NSString* startTime;


/**
 *  The timestamp of when the unlocking ends, formatted in UTC (YYYY-MM-DD
 *  hh:mm:ss).  When the time is not available from the server,
 *  `DJIFlyZoneInformationInvalidTimestamp` will be returned.
 */
@property(nonatomic, readonly) NSString* endTime;


/**
 *  `YES` if the Custom Unlock Zone has expired. After a zone is expired,  the
 *  location will be locked.
 */
@property(nonatomic, readonly) BOOL isExpired;

@end

NS_ASSUME_NONNULL_END

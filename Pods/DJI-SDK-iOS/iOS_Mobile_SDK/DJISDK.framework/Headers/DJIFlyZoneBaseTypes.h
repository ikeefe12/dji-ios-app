//
//  DJIFlyZoneBaseTypes.h
//  DJISDK
//
//  Copyright © 2015, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DJIFlyZoneInformation;

NS_ASSUME_NONNULL_BEGIN


/**
 *  DJI Fly Safe notification types.
 */
typedef NS_ENUM(NSUInteger, DJIFlySafeNotificationType) {
    

    /**
     *  DJI Fly Safe notification related to returning to home.
     */
    DJIFlySafeNotificationTypeReturnToHome,
    

    /**
     *  DJI Fly Safe tip.
     */
    DJIFlySafeNotificationTypeFlyingSafetyTip,
    

    /**
     *  DJI Fly Safe warning notification.
     */
    DJIFlySafeNotificationTypeWarning,
    

    /**
     *  DJI Fly Safe serious warning notification.
     */
    DJIFlySafeNotificationTypeSeriousWarning,
    

    /**
     *  DJI Fly Safe unknown notification type.
     */
    DJIFlySafeNotificationTypeUnknown = 0xFF,
};


/**
 *  Fly zone ReturnToHome events. DJI Fly Safe notification when the aircraft
 *  returns to home.
 */
typedef NS_ENUM(NSUInteger, DJIFlySafeReturnToHomeEvent) {
    

    /**
     *  Approaching a No-Fly Zone. Return to home may be affected. Fly with caution.
     */
    DJIFlySafeReturnToHomeEventNearNoFlyZone,
    

    /**
     *  Current Return to home route will pass a No-Fly zone. Pay attention to the
     *  aircraft's position  to avoid Return to home failure.
     */
    DJIFlySafeReturnToHomeEventCrossNoFlyZone,
    

    /**
     *  Unknown.
     */
    DJIFlySafeReturnToHomeEventUnknown = 0xFF,
};


/**
 *  DJI Fly Safe warning events of fly zones.
 */
typedef NS_ENUM(NSUInteger, DJIFlySafeWarningEvent) {
    

    /**
     *  The aircraft was unable to take off in the no-fly zone.
     */
    DJIFlySafeWarningEventTakeoffFailedInNoFlyZone,
    

    /**
     *  The mobile device is in the no-fly zone, and the GPS signal of the aircraft is
     *  not good enough to take off.
     */
    DJIFlySafeWarningEventTakeOffFailedInNoFlyZoneWithoutGps,
    

    /**
     *  Cannot take off. You have not applied to fly in this zone.
     */
    DJIFlySafeWarningEventTakeOffFailedWithoutCustomUnlocking,
    

    /**
     *  The mobile device is in the authorized area, and the GPS signal of the aircraft
     *  is not good, and it cannot take off before unlocking.
     */
    DJIFlySafeWarningEventTakeOffFailedInAuthorizedZoneWithoutGpsAndUnlocking,
    

    /**
     *  The aircraft is not allowed to take off before being unlocked in the authorized
     *  area.
     */
    DJIFlySafeWarningEventTakeOffFailedInAuthorizedZoneWithoutUnlocking,
    

    /**
     *  The aircraft is in the authorized area and you have obtained a flight
     *  certificate.
     */
    DJIFlySafeWarningEventTakeOffFailedInAuthorizedZone,
    

    /**
     *  The aircraft is in the enhanced warning zone, please pay attention to flight
     *  safety.
     */
    DJIFlySafeWarningEventTakeOffInEnhancedWarningZone,
    

    /**
     *  There is a no-fly zone nearby and there are flight restrictions.
     */
    DJIFlySafeWarningEventTakeOffNearNoFlyZone,
    

    /**
     *  There are limited restrictions in the nearby area.
     */
    DJIFlySafeWarningEventLimitedRestrictionsNearby,
    

    /**
     *  There are authorized areas nearby and there are flight restrictions.
     */
    DJIFlySafeWarningEventAuthorizedZoneWithoutUnlockingNearby,
    

    /**
     *  There are authorized areas nearby and you have obtained a flight certificate.
     */
    DJIFlySafeWarningEventAuthorizedZoneAndRestrictionsNearby,
    

    /**
     *  There are flight restrictions in the nearby limited flight area.
     */
    DJIFlySafeWarningEventRestrictionsInLimitedFlyZoneNearby,
    

    /**
     *  The aircraft is in the authorized area and you have obtained a flight
     *  certificate.
     */
    DJIFlySafeWarningEventInAuthorizationZone,
    

    /**
     *  The mobile device is in the no-fly zone, and the GPS signal of the aircraft is
     *  not good enough to take off.
     */
    DJIFlySafeWarningEventTakeOffFailedInNoFlyZoneWithWeakGps,
    

    /**
     *  Unknown.
     */
    DJIFlySafeWarningEventUnknown = 0xFF,
};


/**
 *  Fly zone serious warning events.
 */
typedef NS_ENUM(NSUInteger, DJIFlySafeSeriousWarningEvent) {
    

    /**
     *  The aircraft is in the no-fly zone. After the countdown is over, it will force
     *  an automatic drop.  You will not be able to control the throttle, but you can
     *  adjust the horizontal direction to avoid obstacles.
     */
    DJIFlySafeSeriousWarningEventInNoFlyZone,
    

    /**
     *  The aircraft is in the height limit zone. After the countdown is over, it will
     *  automatically drop to the limit height,  you will not be able to control the
     *  throttle, but you can adjust the horizontal direction to avoid obstacles.
     */
    DJIFlySafeSeriousWarningEventInHeightLimitZone,
    

    /**
     *  The aircraft is in the authorized zone. After the countdown is over, it will
     *  automatically drop and you will not be able to  control the throttle, but you
     *  can adjust the horizontal direction to avoid obstacles.
     */
    DJIFlySafeSeriousWarningEventInAuthorizationZoneWithoutUnlocking,
    

    /**
     *  The aircraft is in the authorized area and you have obtained a flight
     *  certificate. After the countdown is over, it will  automatically drop and you
     *  will not be able to control the throttle, Please confirm the fly limit zone and
     *  than open it.
     */
    DJIFlySafeSeriousWarningEventInUnlockedAuthorizationZone,
    

    /**
     *  Unknown.
     */
    DJIFlySafeSeriousWarningEventUnknown = 0xFF,
};


/**
 *  DJI Flying safety tip.
 */
typedef NS_ENUM(NSUInteger, DJIFlyingSafetyTipEvent) {
    

    /**
     *  The aircraft is below the height limit zone and has no GPS signal, please pay
     *  attention to flight safety.
     */
    DJIFlyingSafetyTipEventTakeOffInHeightLimitZoneWithoutGps,
    

    /**
     *  The aircraft is below the height limit zone, please pay attention to flight
     *  safety.
     */
    DJIFlyingSafetyTipEventTakeOffInHeightLimitZone,
    

    /**
     *  The aircraft is in the warning zone, please pay attention to flight safety.
     */
    DJIFlyingSafetyTipEventTakeOffInWarningArea,
    

    /**
     *  The aircraft has touched the no-fly zone, please control the aircraft as far as
     *  possible.
     */
    DJIFlyingSafetyTipEventTouchNoFlyZone,
    

    /**
     *  The aircraft has touched the authorized area, please control the aircraft as far
     *  as possible.
     */
    DJIFlyingSafetyTipEventTouchAuthorizationZone,
    

    /**
     *  The aircraft has reached the maximum flight height in the height limit zone.
     */
    DJIFlyingSafetyTipEventReachMaximumFlightHeight,
    

    /**
     *  Your aircraft is at the boundary of a GEO Zone, Return To Home may be affected.
     *  Please fly away with caution.
     */
    DJIFlyingSafetyTipEventRTHAffectedAtBoundaryOfGEOZone,
    

    /**
     *  Your aircraft is at the boundary of an Custom Unlocking Zone.
     */
    DJIFlyingSafetyTipEventAtBoundaryOfCustomUnlockZone,
    

    /**
     *  Unknown.
     */
    DJIFlyingSafetyTipEventUnknown = 0xFF,
};


/**
 *  This class contains DJI flying safety warning information related to fly zones.
 *  The `event` indicates the reason. Use `description` method to get detail
 *  information.
 */
@interface DJIFlyingSafetyWarningInformation : NSObject


/**
 *  Returns the event of DJI flying safety warning.
 */
@property(nonatomic, readonly) DJIFlySafeWarningEvent event;


/**
 *  Returns the height limit of current fly zone.
 */
@property(nonatomic, readonly) NSInteger heightLimit;


/**
 *  Returns information about the fly zones.
 */
@property(nonatomic, readonly) NSArray <DJIFlyZoneInformation *> *flyZoneInformation;

@end


/**
 *  This class contains DJI flying safety serious warning information related to fly
 *  zones. The aircraft will  land when there is a serious warning. The `event`
 *  indicates the reason. Use `description` method to get  detail information.
 */
@interface DJIFlyingSafetySeriousWarningInformation : NSObject


/**
 *  Returns the event of DJI flying safety serious warning.
 */
@property(nonatomic, readonly) DJIFlySafeSeriousWarningEvent event;


/**
 *  Returns the height limit of current fly zone.
 */
@property(nonatomic, readonly) NSInteger heightLimit;


/**
 *  Returns the countdown to start automatically landing.
 */
@property(nonatomic, readonly) NSInteger countDown;


/**
 *  Returns information about the fly zones.
 */
@property(nonatomic, readonly) NSArray <DJIFlyZoneInformation *> *flyZoneInformation;

@end


/**
 *  This class contains DJI flying safety tip related to fly zones. The `event`
 *  indicates the reason. Use `description`  method to get detail information.
 */
@interface DJIFlyingSafetyTip : NSObject


/**
 *  Returns the event of DJI flying safety tip.
 */
@property(nonatomic, readonly) DJIFlyingSafetyTipEvent event;


/**
 *  Returns the height limit of current fly zone.
 */
@property(nonatomic, readonly) NSInteger heightLimit;


/**
 *  Returns information about the fly zones.
 */
@property(nonatomic, readonly) NSArray <DJIFlyZoneInformation *> *flyZoneInformations;

@end


/**
 *  This class contains DJI flying safety notification related to returning to home.
 *  The `event` indicates the reason. Use `description` method to get detail
 *  information.
 */
@interface DJIFlySafeReturnToHomeInformation : NSObject


/**
 *  Returns the event of DJI flying safety notification related to returning to
 *  home.
 */
@property(nonatomic, readonly) DJIFlySafeReturnToHomeEvent event;

@end


/**
 *  This class contains DJI flying safety notification. The `type` indicates the
 *  type of notification.  Check corresponding object for detail information.
 */
@interface DJIFlySafeNotification : NSObject


/**
 *  Returns the type of notification.
 */
@property(nonatomic, readonly) DJIFlySafeNotificationType type;


/**
 *  Returns the notice information.
 */
@property(nonatomic, readonly) DJIFlyingSafetyTip *tip;


/**
 *  Returns the warning information.
 */
@property(nonatomic, readonly) DJIFlyingSafetyWarningInformation *warningInformation;


/**
 *  Returns the serious warning information.
 */
@property(nonatomic, readonly) DJIFlyingSafetySeriousWarningInformation *seriousWarningInformation;


/**
 *  Returns the return to home information.
 */
@property(nonatomic, readonly) DJIFlySafeReturnToHomeInformation *returnToHomeInformation;

@end

NS_ASSUME_NONNULL_END

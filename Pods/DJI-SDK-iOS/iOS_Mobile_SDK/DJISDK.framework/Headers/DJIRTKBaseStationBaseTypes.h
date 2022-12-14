//
//  DJIRTKBaseStationBaseTypes.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  All the possible basestation location type of `DJIRTKBaseStationLocationType`.
 */
typedef NS_ENUM(uint8_t, DJIRTKBaseStationLocationType) {
    

    /**
     *  BaseStation current location is auto calculateed by BaseStation itself.
     */
    DJIRTKBaseStationLocationTypeAuto,
    

    /**
     *  BaseStation current location is manually set by user.
     */
    DJIRTKBaseStationLocationTypeManual,
    

    /**
     *  Unknown BaseStation location type.
     */
    DJIRTKBaseStationLocationTypeUnknown = 0xFF,
};


/**
 *  RTK Base Station Current Battery State.
 */
@interface DJIRTKBaseStationBatteryState : NSObject


/**
 *  Returns the current RTK base station battery voltage (mV).
 */
@property(nonatomic, readonly) uint32_t voltage;


/**
 *  Returns the real time current draw of the RTK base station battery (mA).
 */
@property(nonatomic, readonly) uint32_t current;


/**
 *  Returns the current RTK base station battery's temperature, in Celsius, with
 *  range [-128, 127] degrees.
 */
@property(nonatomic, readonly) int16_t temperature;



/**
 *  Returns the battery's remaining lifetime as a percentage, with range [0, 100]. A
 *  new battery will be close  to 100%. As a battery experiences charge/discharge
 *  cycles, the value will go down.
 */
@property(nonatomic, readonly) uint8_t capacityPercent;

@end


/**
 *  RTK Base Station Current State.
 */
@interface DJIRTKBaseStationState : NSObject


/**
 *  Gets if the base station is allowed to use in current country.
 */
@property(nonatomic, readonly) BOOL isAllowedToUse;


/**
 *  Gets RTK baseStation location type. See `DJIRTKBaseStationLocationType`.
 */
@property(nonatomic, readonly) DJIRTKBaseStationLocationType baseStationLocationType;

@end

NS_ASSUME_NONNULL_END

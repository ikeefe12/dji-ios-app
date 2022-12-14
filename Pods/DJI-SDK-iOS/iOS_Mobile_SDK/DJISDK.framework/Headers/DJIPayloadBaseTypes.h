//
//  DJIPayloadBaseTypes.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  Development phase has more settings than product phase, including control
 *  parameters auto-tuning,  coaxiality detection, balance detection, stiffness
 *  adjustment. Please note that this phase should be  used with DJI Assistant 2,
 *  which has bound with Payload SDK developer account. Product phase means  that
 *  the product is in the stage ready to sell. During this stage, development
 *  settings, i.e., control  parameters auto-tuning, coaxiality detection, balance
 *  detection, stiffness adjustment, should be hidden from user interface.
 */
typedef NS_ENUM(uint8_t, DJIPayloadProductPhase) {


  /**
   *  The product is in the development phase.
   */
  DJIPayloadProductPhaseDevelopment,


  /**
   *  The product is in the release phase.
   */
  DJIPayloadProductPhaseRelease,


  /**
   *  Unknown.
   */
  DJIPayloadProductPhaseUnknown = 0xFF,
};


/**
 *  All the possible mode of `DJIPayloadDeviceType`.
 */
typedef NS_ENUM(uint8_t, DJIPayloadDeviceType) {


  /**
   *  DJI Skyport 1.0.
   */
  DJIPayloadDeviceType_DJI_Skyport_1,


  /**
   *  DJI Skyport 2.0.
   */
  DJIPayloadDeviceType_DJI_Skyport_2,


  /**
   *  DJI X-Port.
   */
  DJIPayloadDeviceType_DJI_X_Port,
    

  /**
   *  Unknown.
   */
  DJIPayloadDeviceTypeUnknown = 0xFF,
};

NS_ASSUME_NONNULL_END

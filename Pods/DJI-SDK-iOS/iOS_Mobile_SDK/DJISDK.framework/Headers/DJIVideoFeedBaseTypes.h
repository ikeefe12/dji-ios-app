//
//  DJIVideoFeedBaseTypes.h
//  DJISDK
//
//  Copyright © 2019 DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  The physical source of a video feed.
 */
typedef NS_ENUM(NSInteger, DJIVideoFeedPhysicalSource) {

    /**
     *  The video feed is from the main camera. It is the physical source used by most
     *  of DJI products.  `DJIVideoFeedPhysicalSourceLeftCamera`  and
     *  `DJIVideoFeedPhysicalSourceRightCamera` are used instead in  M210 series and
     *  M210 V2 series.
     */
    DJIVideoFeedPhysicalSourceMainCamera,
    

    /**
     *  The video feed is from the FPV camera on Inspire 2, M200 series and M200 series
     *  v2 and Matrice 300 RTK.
     */
    DJIVideoFeedPhysicalSourceFPVCamera,
    

    /**
     *  The video feed is from one of the LB ports (AV or HDMI) while EXT Port is
     *  enabled.  It is only used for stand-alone Lightbridge 2 or aircraft with stand-
     *  alone Lightbridge 2 modules (e.g. M600).
     */
    DJIVideoFeedPhysicalSourceLB,
    

    /**
     *  The video feed is from EXT port while EXT port is enabled. It is only used for
     *  Lightbridge 2 or aircrafts with Lightbridge 2 (e.g. M600).
     */
    DJIVideoFeedPhysicalSourceEXT,
    

    /**
     *  The video feed is from the HDMI port while EXT port is disabled.  It is only
     *  used for stand-alone Lightbridge 2 or aircraft with stand-alone Lightbridge 2
     *  modules.
     */
    DJIVideoFeedPhysicalSourceHDMI,
    

    /**
     *  The video feed is from AV port while EXT port is disabled. It is only used for
     *  stand-alone Lightbridge 2 or aircraft with stand-alone Lightbridge 2 modules.
     */
    DJIVideoFeedPhysicalSourceAV,
    

    /**
     *  The video feed is from the port (left) main camera. It is only used for M210
     *  series and M210 V2 series and Matrice 300 RTK.
     */
    DJIVideoFeedPhysicalSourceLeftCamera,
    

    /**
     *  The video feed is from the starboard (right) main camera. It is only used for
     *  M210 series and M210 V2 series and Matrice 300 RTK.
     */
    DJIVideoFeedPhysicalSourceRightCamera,
    

    /**
     *  The video feed is from the camera above the aircraft. It is only used for
     *  Matrice 300 RTK.
     */
    DJIVideoFeedPhysicalSourceTopCamera,
    

    /**
     *  Unknown video physical source.
     */
    DJIVideoFeedPhysicalSourceUnknown = 0xFF,
};

/*********************************************************************************/
#pragma mark DJIVideoFeedPriority
/*********************************************************************************/


/**
 *  The enum is used to represent priority of a stream channel. It is supported only
 *  by Matrice 300 RTK.
 */
typedef NS_ENUM (NSUInteger, DJIVideoFeedPriority){
    

    /**
     *  The stream channel's priority is high.
     */
    DJIVideoFeedPriorityHigh,
    

    /**
     *  The stream channel's priority is medium.
     */
    DJIVideoFeedPriorityMedium,
    

    /**
     *  The stream channel's priority is low.
     */
    DJIVideoFeedPriorityLow,
    

    /**
     *  The stream channel's priority is unknown.
     */
    DJIVideoFeedPriorityUnknown = 0xFF,
};

NS_ASSUME_NONNULL_END

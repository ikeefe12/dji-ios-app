//
//  DJIWarningStatusItem.h
//  DJISDK
//
//  Copyright © 2019, DJI. All rights reserved.
//
//

#import <Foundation/Foundation.h>


/**
 *  The warning level of the status.
 */
typedef NS_ENUM(NSUInteger, DJIWarningStatusLevel) {
    

    /**
     *  The status has an undetermined warning level.
     */
     DJIWarningStatusLevelNone,
    

    /**
     *  The status is offline.
     */
     DJIWarningStatusLevelOffline,
    

    /**
     *  The status is good.
     */
     DJIWarningStatusLevelGood,
    

    /**
     *  The status is a warning.
     */
     DJIWarningStatusLevelWarning,
    

    /**
     *  The status is an error.
     */
     DJIWarningStatusLevelError
};


/**
 *  This class wraps the required elements of the status into one WarningStatusItem.
 */
@interface DJIWarningStatusItem : NSObject <NSCopying>

//For internal use - get the order of the status warning item
@property (nonatomic, assign, readonly) NSInteger order;


/**
 *  The warning level of the message.
 */
@property (nonatomic, assign, readonly) DJIWarningStatusLevel warningLevel;


/**
 *  Get the message of the warning status item.
 */
@property (nonatomic, copy, readonly) NSString* message;


/**
 *  Get the urgency of the message.
 */
@property (nonatomic, assign, readonly) BOOL isUrgent;


/**
 *  Additional information. For example: Height limit, Distance from the home point,
 *  etc.
 */
@property (nonatomic, copy, readonly) NSDictionary* extraInfo;


/**
 *  Whether to remove automatically when the aircraft is disconnected.
 */
@property (nonatomic, assign, readonly) BOOL shouldRemoveWhenAircraftDisconnected;

@end

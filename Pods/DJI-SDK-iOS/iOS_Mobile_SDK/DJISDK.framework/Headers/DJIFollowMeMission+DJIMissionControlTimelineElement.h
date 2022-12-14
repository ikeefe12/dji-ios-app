//
//  DJIFollowMeMission+DJIMissionControlTimelineElement.h
//  DJISDK
//
//  Copyright © 2017, DJI. All rights reserved.
//

#import <DJISDK/DJISDK.h>

/**
 This category makes the DJIFollowMeMission operatable inside the Mission
 Control timeline.
 */
@interface DJIFollowMeMission (DJIMissionControlTimelineElement) <DJIMissionControlTimelineElement>


/**
 *  The time to delay the start of the mission
 */
@property (nonatomic, assign) NSUInteger delayTime;

@end

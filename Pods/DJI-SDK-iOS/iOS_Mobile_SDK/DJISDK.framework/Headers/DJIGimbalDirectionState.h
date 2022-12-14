//
//  DJIGimbalDirectionState.h
//  DJISDK
//
//  Copyright © 2019, DJI. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DJIGimbalBaseTypes.h"

NS_ASSUME_NONNULL_BEGIN


/**
 *  This class provides gimbal direction adjustment result and adjustment suggestion
 *  on axis.
 */
@interface DJIGimbalDirectionState : NSObject


/**
 *  Gimbal direction adjustment result for direction left and right.
 */
@property (nonatomic, readonly) DJIGimbalDirectionAdjustmentResult adjustmentResultLR;


/**
 *  Suggestion for adjusting the gimbal to the left or to the right.
 */
@property (nonatomic, readonly) DJIGimbalSuggestedDirectionAdjustment adjustmentSuggestionLR;


/**
 *  Gimbal direction adjustment result for direction upwards or downwards.
 */
@property (nonatomic, readonly) DJIGimbalDirectionAdjustmentResult adjustmentResultUD;


/**
 *  Suggestion for adjusting the gimbal upwards or downwards.
 */
@property (nonatomic, readonly) DJIGimbalSuggestedDirectionAdjustment adjustmentSuggestionUD;


/**
 *  Gimbal direction adjustment result for direction forwards or backwards.
 */
@property (nonatomic, readonly) DJIGimbalDirectionAdjustmentResult adjustmentResultFB;


/**
 *  Suggestion for adjusting the camera forwards or backwards.
 */
@property (nonatomic, readonly) DJIGimbalSuggestedDirectionAdjustment adjustmentSuggestionFB;

@end

NS_ASSUME_NONNULL_END

//
//  DJIRadarKey.h
//  DJISDK
//
//  Created by neo.xu on 2020/12/1.
//  Copyright © 2020 DJI. All rights reserved.
//

#import "DJIKey.h"

NS_ASSUME_NONNULL_BEGIN

EXTERN_KEY NSString *const DJIRadarComponent;
EXTERN_KEY NSString *const DJIRadarParamUpwardsRadarObstacleAvoidanceEnabled;
EXTERN_KEY NSString *const DJIRadarParamUpwardsRadarObstacleAvoidanceU2Enabled;
EXTERN_KEY NSString *const DJIRadarParamHorizontalRadarObstacleAvoidanceEnabled;
EXTERN_KEY NSString *const DJIRadarParamRadarPerceptionState;


/**
 *  `DJIRadarKey` provides dedicated access to radar attributes.
 */
__attribute__((objc_runtime_name("2ff4bc23-4e42-11eb-b188-faffc242a0e6"))) 
@interface DJIRadarKey : DJIKey

@end

NS_ASSUME_NONNULL_END

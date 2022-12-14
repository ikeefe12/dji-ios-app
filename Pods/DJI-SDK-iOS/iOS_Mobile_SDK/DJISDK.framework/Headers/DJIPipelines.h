//
//  DJIPipelines.h
//  DJISDK
//
//  Copyright © 2020 DJI. All rights reserved.
//

#import <DJISDK/DJISDK.h>
#import "DJIPipeline.h"

NS_ASSUME_NONNULL_BEGIN

/*********************************************************************************/
#pragma mark - DJIPipelines
/*********************************************************************************/


/**
 *  Manage multiple pipelines. Only supported by Matrice 300 RTK with firmware
 *  version v01.00.01.01 and above.
 */
@interface DJIPipelines : DJIBaseComponent


/**
 *  Retrieves instances of the products's pipelines. The key of the map table refers
 *  to the pipeline ID that connected  with the Payload or the Onboard device, and
 *  the value refers to the pipeline instance object. When the pipeline  connection
 *  is established successfully, a pipeline object is created and placed in the map
 *  table. When `disconnect:withCompletion`  is invoked, the expired pipeline will
 *  be removed from the pipelins map table.
 */
@property (nonatomic, readonly) NSDictionary<NSNumber *, DJIPipeline *> *pipelines;


/**
 *  Establishes the pipeline connection with the pipeline's ID. Returns an instance
 *  of the pipeline when it is connected successfully,  otherwise, error information
 *  will be returned.
 *  
 *  @param Id The pipeline id.
 *  @param transferType The pipeline type.
 *  @param pipeline An object of `DJIPipeline`.
 *  @param error Error retrieving the value.
 *  @param completion Completion block to receive the result.
 */
- (void)connect:(uint16_t)Id pipelineType:(DJITransmissionControlType)transferType withCompletion:(void (^_Nullable)(DJIPipeline *_Nullable pipeline, NSError *_Nullable error))completion;


/**
 *  Disconnects from the Payload or the Onboard device by pipeline ID, and clear the
 *  cached data in pipeline. If it is disconnected successfully,  the pipeline
 *  instance will be removed from the pipeline map table, otherwise, error
 *  information will be returned.
 *  
 *  @param Id The pipeline id.
 *  @param completion Completion block to receive the result.
 */
- (void)disconnect:(uint16_t)Id withCompletion:(DJICompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END

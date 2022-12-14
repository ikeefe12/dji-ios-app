//
//  DJIWaypointV2MissionOperator.h
//  DJISDK
//
//  Copyright © 2019, DJI. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "DJISDKFoundation.h"
#import "DJIWaypointV2MissionTypes.h"

@class DJIWaypointV2Mission;
@class DJIWaypointV2Action;

NS_ASSUME_NONNULL_BEGIN


/**
 *  All the possible state of `DJIWaypointV2MissionOperator`.
 */
typedef NS_ENUM(NSInteger, DJIWaypointV2MissionState) {

    /**
     *  The state of the operator is unknown.
     */
    DJIWaypointV2MissionStateUnknown = -1,
    

    /**
     *  The connection between the mobile device, remote controller and aircraft is
     *  broken.
     */
    DJIWaypointV2MissionStateDisconnected,
    

    /**
     *  The connection between the mobile device, remote controller and aircraft is
     *  built-up.  The operator is synchronizing the state from the aircraft.
     */
    DJIWaypointV2MissionStateRecovering,
    

    /**
     *  The connected product does not support waypoint mission 2.0.
     */
    DJIWaypointV2MissionStateNotSupported,
    

    /**
     *  The aircraft is ready to upload a mission.
     */
    DJIWaypointV2MissionStateReadyToUpload,
    

    /**
     *  The uploading is started successfully. Detail information for each waypoint is
     *  being uploaded one by one.
     */
    DJIWaypointV2MissionStateUploading,
    

    /**
     *  Waypoint mission is uploaded completely and the aircraft is ready to start the
     *  execution.
     */
    DJIWaypointV2MissionStateReadyToExecute,
    

    /**
     *  The execution is started successfully.
     */
    DJIWaypointV2MissionStateExecuting,
    

    /**
     *  Waypoint mission is paused successfully. User can call
     *  `interruptMissionWithCompletion` to continue the execution.
     */
    DJIWaypointV2MissionStateInterrupted,
};


/**
 *  All the possible action state of `DJIWaypointV2MissionOperator`.
 */
typedef NS_ENUM(NSInteger, DJIWaypointV2MissionActionState) {

    /**
     *  The state of the operator is unknown. It is the initial action state when the
     *  operator is just created.
     */
    DJIWaypointV2MissionActionStateUnknown = -1,
    

    /**
     *  The connection between the mobile device, remote controller and aircraft is
     *  broken.
     */
    DJIWaypointV2MissionActionStateDisconnected,
    

    /**
     *  The connection between the mobile device, remote controller and aircraft is
     *  built-up.  The operator is synchronizing the action state from the aircraft.
     */
    DJIWaypointV2MissionActionStateRecovering,
    

    /**
     *  The connected product does not support waypoint mission 2.0.
     */
    DJIWaypointV2MissionActionStateNotSupported,
    

    /**
     *  The aircraft is ready to upload actions.
     */
    DJIWaypointV2MissionActionStateReadyToUpload,
    

    /**
     *  The uploading is started successfully. Detail information for each action is
     *  being uploaded one by one.
     */
    DJIWaypointV2MissionActionStateUploading,
    

    /**
     *  Waypoint mission is uploaded completely and the aircraft is ready to start the
     *  execution.
     */
    DJIWaypointV2MissionActionStateReadyToExecute,
    

    /**
     *  The execution is started successfully.
     */
    DJIWaypointV2MissionActionStateExecuting,
    

    /**
     *  Waypoint mission is interrupted successfully. User can call
     *  `interruptMissionWithCompletion` to continue the execution.
     */
    DJIWaypointV2MissionActionStateInterrupted,
};


/**
 *  The upload event of a waypoint mission.
 */
@interface DJIWaypointV2MissionUploadEvent : NSObject


/**
 *  The previous state of the operator.
 */
@property (nonatomic, readonly) DJIWaypointV2MissionState previousState;


/**
 *  The current state of the operator.
 */
@property (nonatomic, readonly) DJIWaypointV2MissionState currentState;


/**
 *  The upload progress of the mission. It is `nil` if there is an error during
 *  uploading.
 */
@property (nonatomic, readonly, nullable) DJIWaypointV2UploadProgress *progress;


/**
 *  The encountered error during upload if there is any. Otherwise, it is `nil`.
 */
@property (nonatomic, readonly, nullable) NSError *error;

@end


/**
 *  The download event of a waypoint mission.
 */
@interface DJIWaypointV2MissionDownloadEvent : NSObject


/**
 *  The download progress of the mission. It is `nil` if there is an error during
 *  download.
 */
@property (nonatomic, readonly, nullable) DJIWaypointV2DownloadProgress *progress;


/**
 *  The encountered error during download if there is any. Otherwise, it is `nil`.
 */
@property (nonatomic, readonly, nullable) NSError *error;

@end


/**
 *  The execution event of a waypoint mission.
 */
@interface DJIWaypointV2MissionExecutionEvent : NSObject


/**
 *  The previous state of the operator.
 */
@property (nonatomic, readonly) DJIWaypointV2MissionState previousState;


/**
 *  The current state of the operator.
 */
@property (nonatomic, readonly) DJIWaypointV2MissionState currentState;


/**
 *  The execution progress of the mission. It is `nil` if there is an error during
 *  the execution.
 */
@property (nonatomic, readonly, nullable) DJIWaypointV2ExecutionProgress *progress;


/**
 *  The encountered error during the execution if there is any. Otherwise, it is
 *  `nil`.
 */
@property (nonatomic, readonly, nullable) NSError *error;

@end


/**
 *  The upload event of a waypoint mission.
 */
@interface DJIWaypointV2MissionActionUploadEvent : NSObject


/**
 *  The previous state of the operator.
 */
@property (nonatomic, readonly) DJIWaypointV2MissionActionState previousState;


/**
 *  The current state of the operator.
 */
@property (nonatomic, readonly) DJIWaypointV2MissionActionState currentState;


/**
 *  The upload progress of the mission. It is `nil` if there is an error during
 *  upload.
 */
@property (nonatomic, readonly, nullable) DJIWaypointV2ActionUploadProgress *progress;


/**
 *  The encountered error during upload if there is any. Otherwise, it is `nil`.
 */
@property (nonatomic, readonly, nullable) NSError *error;

@end


/**
 *  The download event of a waypoint mission.
 */
@interface DJIWaypointV2MissionActionDownloadEvent : NSObject


/**
 *  The download progress of the mission. It is `nil` if there is an error during
 *  download.
 */
@property (nonatomic, readonly, nullable) DJIWaypointV2ActionDownloadProgress *progress;


/**
 *  The encountered error during download if there is any. Otherwise, it is `nil`.
 */
@property (nonatomic, readonly, nullable) NSError *error;

@end


/**
 *  The execution event of a waypoint mission.
 */
@interface DJIWaypointV2MissionActionExecutionEvent : NSObject


/**
 *  The previous state of the operator.
 */
@property (nonatomic, readonly) DJIWaypointV2MissionActionState previousState;


/**
 *  The current state of the operator.
 */
@property (nonatomic, readonly) DJIWaypointV2MissionActionState currentState;


/**
 *  The execution progress of the mission. It is `nil` if there is an error during
 *  the execution.
 */
@property (nonatomic, readonly, nullable) DJIWaypointV2ActionExecutionProgress *progress;


/**
 *  The encountered error during the execution if there is any. Otherwise, it is
 *  `nil`.
 */
@property (nonatomic, readonly, nullable) NSError *error;

@end


/**
 *  The waypoint operator is the only object that controls, runs and monitors
 *  Waypoint V2 Missions. It can be accessed from `DJIMissionControl`.
 */
@interface DJIWaypointV2MissionOperator : NSObject


/**
 *  Gets the currently loaded mission of the operator. There are two ways to load a
 *  mission. 1. A mission can be  loaded by user through
 *  `loadMission:withCompletion`. 2. If the aircraft is already executing  a
 *  waypoint mission when SDK is re-connected, the operator will download part of
 *  the mission's information from  the aircraft and load it automatically. In that
 *  case, the loaded mission will only contain the summary of the  executing mission
 *  but information for each waypoint is absent. User can call
 *  `downloadMissionWithCompletion`  to get all the information for the loaded
 *  mission. The `loadedMission` will be reset to `nil`  when the execution of the
 *  loadedMission is stopped, finished.
 */
@property (readonly, nonatomic, nullable) DJIWaypointV2Mission *loadedMission;


/**
 *  Loads a waypoint mission into the operator. A mission can be loaded only when
 *  the `DJIWaypointV2MissionState` is one of the  following :
 *   - `DJIWaypointV2MissionStateReadyToUpload`
 *   - `DJIWaypointV2MissionStateReadyToExecute`
 *   Calling `loadMission:withCompletion`  when the current state is
 *  `DJIWaypointV2MissionStateReadyToExecute` will change the state to
 *  `DJIWaypointV2MissionStateReadyToUpload`.  After calling `loadedMission`,
 *  
 *  @param mission Waypoint mission to load.
 *  @param completion Completion block to receive the result.
 */
-(void)loadMission:(DJIWaypointV2Mission *)mission withCompletion:(DJICompletionBlock)completion;


/**
 *  Gets the currently loaded actions count of the operator. There are two ways to
 *  load a mission. 1. Actions can be loaded by user through
 *  `loadMission:withCompletion`.  2. If the aircraft is already executing a
 *  waypoint mission and it has uploaded actions when SDK is re-connected, the
 *  operator will recover uploaded action count.
 */
@property (readonly, nonatomic) NSUInteger loadedActionCount;


/**
 *  Gets the count of loaded actions in current operator. There are two ways to load
 *  a mission. 1. Actions can be loaded by user through
 *  `loadMission:withCompletion`.  2. If the aircraft is already executing a
 *  waypoint mission and it has uploaded actions when SDK is re-connected, the
 *  operator will recover uploaded action count. load it automatically.  In that
 *  case, the loaded actions will be `nil`, if user want get summary of the
 *  executing actions user can call `downloadMissionWithCompletion` to get all the
 *  information  for the loaded actions. The `loadedActions` will be reset to `nil`
 *  when the execution of the getLoadedMission is stopped, finished.
 */
@property (readonly, nonatomic) NSArray<DJIWaypointV2Action *>* loadedActions;


/**
 *  The current state of the operator.
 */
@property (readonly, nonatomic) DJIWaypointV2MissionState currentState;


/**
 *  The current action state of the operator.
 */
@property (readonly, nonatomic) DJIWaypointV2MissionActionState currentActionState;

/*********************************************************************************/
#pragma mark Listener
/*********************************************************************************/


/**
 *  Block that receive the updated upload event.
 *  
 *  @param event The updated upload event.
 */
typedef void (^DJIWaypointV2MissionOperatorUploadEventBlock)(DJIWaypointV2MissionUploadEvent *event);


/**
 *  Adds listener to receive the event related to upload.
 *  
 *  @param listener Listener that is interested on upload event.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when there is event updated related to upload.
 */
- (void)addListenerToUploadEvent:(id)listener
                       withQueue:(nullable dispatch_queue_t)queue
                        andBlock:(DJIWaypointV2MissionOperatorUploadEventBlock)block;


/**
 *  Block to receive the updated download event.
 *  
 *  @param event The updated download event.
 */
typedef void (^DJIWaypointV2MissionOperatorDownloadEventBlock)(DJIWaypointV2MissionDownloadEvent *event);


/**
 *  Adds listener to receive the event related to download.
 *  
 *  @param listener Listener that is interested on download event.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when there is event updated related to download.
 */
- (void)addListenerToDownloadEvent:(id)listener
                         withQueue:(nullable dispatch_queue_t)queue
                          andBlock:(DJIWaypointV2MissionOperatorDownloadEventBlock)block;


/**
 *  Block to receive the updated execution event.
 *  
 *  @param event The updated execution event.
 */
typedef void (^DJIWaypointV2MissionOperatorExecutionEventBlock)(DJIWaypointV2MissionExecutionEvent *event);


/**
 *  Adds listener to receive the event related to execution.
 *  
 *  @param listener Listener that is interested on execution event.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when there is event updated related to execution.
 */
- (void)addListenerToExecutionEvent:(id)listener
                          withQueue:(nullable dispatch_queue_t)queue
                           andBlock:(DJIWaypointV2MissionOperatorExecutionEventBlock)block;


/**
 *  Block that receive the actions updated upload event.
 *  
 *  @param event The updated upload event.
 */
typedef void (^DJIWaypointV2MissionOperatorActionUploadEventBlock)(DJIWaypointV2MissionActionUploadEvent *event);


/**
 *  Adds listener to receive the event related to action upload.
 *  
 *  @param listener Listener that is interested on upload event.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when there is event updated related to upload.
 */
- (void)addListenerToActionUploadEvent:(id)listener
                             withQueue:(nullable dispatch_queue_t)queue
                              andBlock:(DJIWaypointV2MissionOperatorActionUploadEventBlock)block;


/**
 *  Block to receive the updated download event.
 *  
 *  @param event The updated download event.
 */
typedef void (^DJIWaypointV2MissionOperatorActionDownloadEventBlock)(DJIWaypointV2MissionActionDownloadEvent *event);


/**
 *  Adds listener to receive the event related to download.
 *  
 *  @param listener Listener that is interested on download event.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when there is event updated related to download.
 */
- (void)addListenerToActionDownloadEvent:(id)listener
                               withQueue:(nullable dispatch_queue_t)queue
                                andBlock:(DJIWaypointV2MissionOperatorActionDownloadEventBlock)block;


/**
 *  Block to receive the updated execution event.
 *  
 *  @param event The updated execution event.
 */
typedef void (^DJIWaypointV2MissionOperatorActionExecutionEventBlock)(DJIWaypointV2MissionActionExecutionEvent *event);


/**
 *  Adds listener to receive the event related to execution.
 *  
 *  @param listener Listener that is interested on execution event.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when there is an event updated related to execution.
 */
- (void)addListenerToActionExecutionEvent:(id)listener
                                withQueue:(nullable dispatch_queue_t)queue
                                 andBlock:(DJIWaypointV2MissionOperatorActionExecutionEventBlock)block;


/**
 *  Block to receive the notification that a waypoint mission is started
 *  successfully.
 */
typedef void (^DJIWaypointV2MissionOperatorSimpleEventBlock)(void);


/**
 *  Adds listener to receive the notification when a waypoint mission is started.
 *  
 *  @param listener Listener that is interested on the start of waypoint mission.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when a waypoint mission is started.
 */
- (void)addListenerToStarted:(id)listener
                   withQueue:(nullable dispatch_queue_t)queue
                    andBlock:(DJIWaypointV2MissionOperatorSimpleEventBlock)block;


/**
 *  Adds listener to receive the notification when a waypoint mission is finished.
 *  
 *  @param listener Listener that is interested on the finish of waypoint mission.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when a waypoint mission is finished. If the mission is interrupted with an error, the error will be passed to the block.
 */
- (void)addListenerToFinished:(id)listener
                    withQueue:(nullable dispatch_queue_t)queue
                     andBlock:(DJICompletionBlock)block;


/**
 *  Adds listener to receive the notification when a waypoint mission is stopped by
 *  the user.
 *  
 *  @param listener Listener that is interested on the stop of waypoint mission.
 *  @param queue The dispatch queue that `block` will be called on.
 *  @param block Block will be called when a waypoint mission is stopped by the user.
 */
- (void)addListenerToStopped:(id)listener
                   withQueue:(nullable dispatch_queue_t)queue
                    andBlock:(DJICompletionBlock)block;


/**
 *  Removes listener. If the same listener is listening to multiple events and
 *  notifications (e.g. upload event and download event), it will not receive any
 *  update of them.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListener:(id)listener;


/**
 *  Removes listener to stop listening to upload events.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListenerOfUploadEvents:(id)listener;


/**
 *  Removes listener to stop listening to download events.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListenerOfDownloadEvents:(id)listener;


/**
 *  Removes listener to stop listening to execution events.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListenerOfExecutionEvents:(id)listener;


/**
 *  Removes listener to stop listening to action upload events.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListenerOfActionUploadEvents:(id)listener;


/**
 *  Removes listener to stop listening to action download events.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListenerOfActionDownloadEvents:(id)listener;


/**
 *  Removes listener to stop listening to action execution events.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListenerOfActionExecutionEvents:(id)listener;


/**
 *  Removes listener to stop listening to the notification that a mission is
 *  started.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListenerOfStarted:(id)listener;


/**
 *  Removes listener to stop listening to the notification that a mission is
 *  finished.
 *  
 *  @param listener Listener to be removed.
 */
- (void)removeListenerOfFinished:(id)listener;


/**
 *  Removes listener to stop listening to the notification that a mission is stopped
 *  by the user.
 *  
 *  @param listener Listener to be stopped.
 */
- (void)removeListenerOfStopped:(id)listener;


/**
 *  Remove all listeners.
 */
- (void)removeAllListeners;

/*********************************************************************************/
#pragma mark - Mission Operation
/*********************************************************************************/


/**
 *  Starts to upload the `loadedMission` to the aircraft. It can only be called when
 *  the `loadedMission` is complete and the `currentState`  is
 *  `DJIWaypointV2MissionStateReadyToUpload`. If a timeout error occurs during the
 *  previous upload, the upload operation will  resume from the previous break-
 *  point. After a mission is uploaded successfully, the `DJIWaypointV2MissionState`
 *  will  become `DJIWaypointV2MissionStateReadyToExecute`.
 *  
 *  @param completion Completion block will be invoked with the result if the upload command has been received successfully by the aircraft. If the upload command is successfully sent,  use `addListenerToUploadEvent:withQueue:andBlock` to check the detailed progress.
 */
- (void)uploadMissionWithCompletion:(DJICompletionBlock)completion;


/**
 *  Starts to upload the `loadedActions` to the aircraft. It can only be called when
 *  the `loadedActions`  is complete and the `currentState` is
 *  `DJIWaypointV2MissionStateReadyToExecute`. If a timeout error occurs during the
 *  previous upload, the upload operation will resume from the previous break-point.
 *  After a mission is uploaded successfully, the
 *  <code>DJIWaypointV2MissionActionState</code>  will become
 *  `DJIWaypointV2MissionActionStateReadyToExecute`.
 *  
 *  @param actions An array of waypoint actions.
 *  @param completion Completion block will be invoked with the result if the upload action command has been received successfully by the aircraft. If the upload command is successfully sent,  use `addListenerToActionUploadEvent:withQueue:andBlock` to receive the detailed progress.
 */
- (void)uploadWaypointActions:(NSArray*)actions withCompletion:(DJICompletionBlock)completion;


/**
 *  Downloads information of each waypoint from aircraft and save it to
 *  `loadedMission`.  If a download operation starts, the operator will  download
 *  the information of waypoints missing in `loadedMission` ascending order. If
 *  `loadedMission` is  already complete (containing all the waypoints), this method
 *  will call `completion` immediately without error. It can only be called when the
 *  `currentState`  is one of the following: -
 *  `DJIWaypointV2MissionActionStateExecuting` -
 *  `DJIWaypointV2MissionStateInterrupted`
 *  
 *  @param completion Completion block that will be called when the download operation succeeds or fails to start. If it is started successfully, use `addListenerToDownloadEvent:withQueue:andBlock` to receive the detailed progress.
 */
- (void)downloadMissionWithCompletion:(DJICompletionBlock)completion;


/**
 *  Downloads information of each waypoint from aircraft and save it to
 *  `loadedMission`. If a download operation starts, the operator will download the
 *  information of waypoints missing in `loadedMission`  one-by-one in ascending
 *  order. If `loadedMission` is already complete (containing all the waypoints),
 *  this method will call `completion` immediately without error. It can only be
 *  called when the `currentState`  is one of the following:
 *   - `DJIWaypointV2MissionActionStateExecuting`
 *   - `DJIWaypointV2MissionStateInterrupted`.
 *  
 *  @param completion Completion block that will be called when the download operation succeeds or fails to start. If it is started successfully, use `addListenerToDownloadEvent:withQueue:andBlock` to receive the detailed progress.
 */
- (void)downloadActionsWithCompletion:(DJICompletionBlock)completion;


/**
 *  Starts the execution of the uploaded mission. It can only be called when the
 *  `currentState` is `DJIWaypointV2MissionStateReadyToExecute`. After a mission is
 *  started successfully, the `currentState`  will become
 *  `DJIWaypointV2MissionActionStateExecuting`.
 *  
 *  @param completion Completion block that will be called when the operator succeeds or fails to start the execution. If it fails, an error will be returned.
 */
- (void)startMissionWithCompletion:(DJICompletionBlock)completion;


/**
 *  Pauses the executing mission. It can only be called when the
 *  `DJIWaypointV2MissionState` is `DJIWaypointV2MissionActionStateExecuting`. After
 *  a mission is  paused successfully, the `currentState` will become
 *  `DJIWaypointV2MissionStateInterrupted`.
 *  
 *  @param completion Completion block that will be called when the operator succeeds or fails to pause the mission. If it fails, an error will be returned.
 */
- (void)interruptMissionWithCompletion:(DJICompletionBlock)completion;


/**
 *  Resumes the paused mission. It can only be called when the `currentState` is
 *  `DJIWaypointV2MissionStateInterrupted`.  After a mission is resumed
 *  successfully, the `currentState` will become
 *  `DJIWaypointV2MissionActionStateExecuting`.
 *  
 *  @param completion Completion block that will be called when the operator succeeds or fails to resume the mission. If it fails, an error will be returned.
 */
- (void)recoverMissionWithCompletion:(DJICompletionBlock)completion;


/**
 *  Resumes the paused mission with recover type. It can only be called when the
 *  `currentState` is `DJIWaypointV2MissionStateInterrupted`.  After a mission is
 *  resumed successfully, the `currentState` will become
 *  `DJIWaypointV2MissionActionStateExecuting`.
 *  
 *  @param recoverType An enum value of `DJIWaypointV2InterruptRecoverAction`
 *  @param completion Completion block that will be called when the operator succeeds or fails to resume the mission. If it fails, an error will be returned.
 */
- (void)recoverMission:(DJIWaypointV2InterruptRecoverAction)recoverType withCompletion:(DJICompletionBlock)completion;


/**
 *  Stops the executing or paused mission. It can only be called when the
 *  `currentState` is one of the  following:
 *   - `DJIWaypointV2MissionActionStateExecuting`
 *   - `DJIWaypointV2MissionStateInterrupted` After a mission finishes
 *  successfully, `currentState` will become
 *  `DJIWaypointV2MissionStateReadyToUpload`.
 *  
 *  @param completion Completion block that will be called when the operator succeeds or fails to resume the mission. If it fails, an error will be returned.
 */
- (void)stopMissionWithCompletion:(DJICompletionBlock)completion;


/**
 *  Set the flight speed while the mission is executing automatically (without
 *  manual joystick speed input). This is the only property or method in this  class
 *  that can communicate with the aircraft during a mission. All other properties
 *  and methods are used offline to prepare the mission which is then  uploaded to
 *  the aircraft.
 *  
 *  @param speed Auto flight speed to be set. The absolute value of the auto flight speed should be less than or equal to the `maxFlightSpeed`. Its range is [-`maxFlightSpeed`, `maxFlightSpeed`] m/s.
 *  @param completion Completion block.
 */
- (void)setAutoFlightSpeed:(float)speed withCompletion:(DJICompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END

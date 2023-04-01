# dji-ios-app
AUTHOURS: Fiona Whitfield, Eva Blainey, Abby Brennan, Ian Keefe

An IOS application that uses the MSDK provided by DJI to connect with a DJI Mavic and communicate flight instructions to drone.

This application take infrared image (IR) data from an Arduino Board that is connected to WIFI.

It will use this data to send flight commands to the drone to track the heated subject that has been placed in the sensors FOV.

CURRENT PROGRESS:
- The application is set to run out of the box, no need for an additional pod install.
- The application has successfully binded with the drone and streamed the fpv video
- Application has successfull binded with the sensor
- The data can be successfully streamed at a rate of 1fps (Hoping this will increase outside of debug mode)
- UI is in place and button handlers are hooked up properly
- Threads can run in parallel and shared data safely
All testing below completed successfully for Horizontal movement
- Test control of drone using the app (Emergency land functionality)
- Test functionality of tracking commands (ie display calculated commands but don't send them)
- Test sending tracking commands (ie test set of tracking commands individually)
- Test the entire flow (take drone off, enable IR, start tracking, stop tracking, land)

NEXT Steps:
- Test Forward/Backward Commands
- Test combination of movements

SPECS:
- Thermal Camera Streams at max 9fps and min 5fps (losing frames due to UDP connection can hurt rate)
- Processing in synch with frame rate, the drone gets a new command 5-9 times per second
- Tapping on thermal image will toggle a line that represents the velocity of the drone command that has been calculated to track the heated subject


UI Without Tracking Line
![UI without showing](https://user-images.githubusercontent.com/83965677/229313138-d7b60eb8-ce94-412f-8eed-307ca77d4c84.png)

UI With Tracking Line
![UI with Line](https://user-images.githubusercontent.com/83965677/229313215-a7c4dd4c-66d9-4190-a2ed-261a87f2f7de.png)



# dji-ios-app
AUTHOURS: Fiona Whitfield, Eva Blainey, Abby Brennan, Ian Keefe

An IOS application that uses the MSDK provided by DJI to communicate flight instructions to drone.

This application take infrared image (IR) data from an Arduino Board that is connected to WIFI.

It will use this data to send flight commands to the drone to track the heated subject that has been placed in the sensors FOV.

CURRENT PROGRESS:
- The application is set to run out of the box, no need for an additional pod install.
- The application has been run successfully on an iPhone running the latest iOS (16.2)
- The application is mainly sample code provided by DJI to demonstrate how to use the MSDK

NEXT STEPS:
- Test connection between the application and the drone through use of the drones controller (code is in place)
- Set up wifi connection between the application and the Arduino Board

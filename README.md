# dji-ios-app
AUTHOURS: Fiona Whitfield!!!, Eva Blainey, Abby Brennan, Ian Keefe

An IOS application that uses the MSDK provided by DJI to communicate flight instructions to drone.

This application take infrared image (IR) data from an Arduino Board that is connected to WIFI.

It will use this data to send flight commands to the drone to track the heated subject that has been placed in the sensors FOV.

CURRENT PROGRESS:
- The application is set to run out of the box, no need for an additional pod install.
- The application has been run successfully on an iPhone running the latest iOS (16.2)
- The application is mainly sample code provided by DJI to demonstrate how to use the MSDK
- Application has successfull binded with the sensor
- UI is in place and button handlers are hooked up properly

NEXT Steps:
- Figure out how to get data from port (where is it going when recieved)
- Test cotrol of drone using the app (Emergency land functionality)
- Unit test all logic, including data parsing, tracking algorithm, threading?
- Try and visualize sample frame of IR data within the app

https://github.com/eblainey/thermalthings

Documentation for the UDP connection: https://github.com/robbiehanson/CocoaAsyncSocket/blob/master/Source/GCD/GCDAsyncUdpSocket.h


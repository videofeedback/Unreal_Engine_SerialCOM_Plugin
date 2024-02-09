[![Discord Follow](https://discord.gg/feYhyYznDf)](https://discord.gg/feYhyYznDf)



# Serial Communication Plugin for Unreal Engine
Serial Com Port Library for Unreal Engine 5.3.2

## "Serial COM" v5.5.3.2 RELEASE NOTES (11/1/2023)

- Fully compatible with Unreal Engine 5.3.2


## Downloads (Releases):

[SerialCOM v4.5.3.2 Plugin for Unreal Engine 5.3.2 (With Blueprint Example)](https://github.com/videofeedback/Unreal_Engine_SerialCOM_Plugin/releases/download/SerialCOM_v5.5.3.2/SerialCOM_5_UE532.zip)

[SerialCOM v4.5.2.1 Plugin for Unreal Engine 5.2.1 (With Blueprint Example)](https://github.com/videofeedback/Unreal_Engine_SerialCOM_Plugin/releases/download/SerialCOM_v5.5.2.1/SerialCOM_5_UE521.zip)

[SerialCOM v4.5.1.1 Plugin for Unreal Engine 5.1.1 (With Blueprint Example)](https://github.com/videofeedback/Unreal_Engine_SerialCOM_Plugin/tree/main/_PLUGINS_REPOSITORY/SERIALCOM_4_UE511)

[SerialCOM v4.5.1.0 Plugin for Unreal Engine 5.1.0 (With Blueprint Example)](https://github.com/videofeedback/Unreal_Engine_SerialCOM_Plugin/tree/main/_PLUGINS_REPOSITORY/SERIALCOM_4_UE510)

[SerialCOM v4.5.0.3 Plugin for Unreal Engine 5.0.3 (With Blueprint Example)](https://github.com/videofeedback/Unreal_Engine_SerialCOM_Plugin/tree/main/_PLUGINS_REPOSITORY/SRIALCOM_4_UE503)

[SerialCOM v3.0.0.6 Plugin for Unreal Engine 4.27 (With Blueprint Example)](https://github.com/videofeedback/Unreal_Engine_SerialCOM_Plugin/tree/main/_PLUGINS_REPOSITORY/SERIALCOM_UE427)

-----------------------------------------------------------------------------

## "Serial COM" (Fork of UE4Duino)


[![](https://raw.githubusercontent.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/main/images/serial_com_fork_05.png)](hhttps://raw.githubusercontent.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/main/images/serial_com_fork_05.png)

## List of Functions:

[![](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/images/serialcom_list_of_functions_01.png)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/images/serialcom_list_of_functions_01.png)



### Renamed Functions:
-----------------------------------------------------------------------------------
	UE4Duino v2.2.5				Serial COM v5
	- Close Port 				- Close Serial Port
	- Flash Port 				- Flash Serial Port
	- Open Port 				- Open Serial Port
	- ----------				- (New) Open Serial Port with Flow Control
	- Open Port with Target			- (New) Open Serial Port with Target and Flow Control
	- Get Port Number			- Get Serial Port Number
	- Get Port Baudrate			- Get Serial Port Baudrate
	- Serial Port Open			- Is Serial Port Open?
	- Print 				- Serial Print
	- Print Line				- Serial Print Line
	- Line End to String			- Serial Line End to String
	- Write a Byte				- Serial Write Byte
	- Write Bytes				- Serial Write Bytes
	- Read a Bytes				- Serial Read Byte
	- Read a Float				- Serial Read Float
	- Read a Line				- Serial Read Line
	- Read a String				- Serial Read a String
	- Bytes to Float			- Serial Bytes to Float
	- Bytes to int 				- Serial Bytes to Int
	- Float to Bytes			- Serial Float to Bytes
	- Int to Bytes				- Serial Int to Bytes
  
  
  
### "Serial COM" v3.0.0 (Beta) PREVIOUS RELEASES NOTES

- The "Serial COM" 3.0.0 Plugin now works nativelley in Unreal Engine 4.27/4.26/4.24 (PARTIAL SUPPORT WITH UE 5EA*) without having to re-build the project and possibly not be able to re-build for the lack of missing SDK's requirements. 
* Unreal Engine 5(Early Access) still requires to rebuild the plugin. UE5 is able to rebuild the plugin. Until a new method to rebuild the plugin for UE5 is available, this is the only version compatible with UE5.

- The new plugin will appear in your plugin list as "Communication Serial Port (Serial COM)". On your blueprints, is going to be listed in the "Communication Serial" category list instead of "UE4Duino". Search for "Arduino, Serial, Communication" will also show the results for these functions. 

- Added Flow Control from the last UE4Duino 2.2.5's Pull request from "SG1EmberWolf"(https://github.com/SG1EmberWolf) 
	- Added "Open Serial Port with Flow Control"
	- Added "Open Serial Port with Target and Flow Control"
  
  - The new module name changed from "UE4Duino" to "SERIALCOM". That also means that both plugins (potentially) can live together inside a blueprint without causing conflicts, but is not recommended.

- Internally, changed naming of "Serial.h" files includes name. This "Serial.h" is very popular in many libraries. To avoid possible future corruption and confusion, it was renamed to "SerialCom.h".

- The BETA version will continue to stay in BETA mode until no serious problems get reported and the final version will be 100% compatible with this release.

GITHUB REPOSITORY (this one): https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/

-----------------------------------------------------------------------------------------------------

Known Issues:
----------------------------

- "Serial COM" will not be compatible with "UE4Duino" 2.2.5 because the library doesn't share the "UE4DUINO" name anymore, using its own new "SERIALCOM" identifier. Changing to this library will make the old EU4Duino modules in red, indicating that those components are not available anymore.
Solution: Each component can be replaced with the current version by replacing each one by hand. The replacement equivalent chart is available at:
https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port  (Modules lists comparison chart)

- Arduino doesn't connects again if you close the project without closing the port.
Solution:  Use the best practice of creating an "Event End Play" with "Close Serial Port" connected to the event. This is the cleanest solution for this problem and best practice. 
For more information, visit https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port where we describe the best practices for the use of this plugin.



## Opening Port Example

[![](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/images/serialcom_opening_port_example_02.png)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/images/serialcom_opening_port_example_02.png)



## Blueprint Example

Each Zip file contains the correstpondent blueprint for each UE version. Drag and drop the .uasset (Blueprint) file to your project. Read the complete insturctions inside the "BLUEPRINT" folder of this plugin.

[![](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/images/serialcom_blueprint_example_01.png)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/images/serialcom_blueprint_example_01.png)

----------------------------------------------------------------------------------------------------------


### Serial Communication Useful information:

["Serial Communication" (Wikipedia)](https://en.wikipedia.org/wiki/Serial_communication)

["Flow Control" (Wikipedia)](https://en.wikipedia.org/wiki/Flow_control_(data))

["Software Flow Control (XON/XOFF)" (Wikipedia)](https://en.wikipedia.org/wiki/Software_flow_control)

["Serial Communication" (Contec)](https://www.contec.com/support/basic-knowledge/daq-control/serial-communicatin/)

["Serial Communication" (Sparkfun)](https://learn.sparkfun.com/tutorials/serial-communication/all)

["Serial Communication" (Adafruit)](https://learn.adafruit.com/circuit-playground-express-serial-communications/what-is-serial-communications)

["RS-232 vs TTL Serial Communication" (Sparkfun)](https://www.sparkfun.com/tutorials/215)



----------------------------------------------------------------------------------------------------------



### Useful Lab Tools:

["USB to TTL Serial Cable" (Sparkfun)](https://www.adafruit.com/product/954)

["Arduino Uno Rev3" (Arduino.cc)](https://store-usa.arduino.cc/collections/boards/products/arduino-uno-rev3)

["Arduino Mega Rev3" (Arduino.cc)](https://store-usa.arduino.cc/collections/boards/products/arduino-mega-2560-rev3)

["Arduino Portenta H7 Lite Connected" (Arduino.cc)](https://store-usa.arduino.cc/collections/boards/products/portenta-h7-lite-connected)







-----------------------------------------------------------------------------------------------------
Ramiro Montes De Oca (Ramiro's Lab)

Discord: https://discord.ramiroslab.com

YouTube: https://youtube.ramiroslab.com

Github: https://github.ramiroslab.com

----------------------------------------------------------------------------------------------------

### Copyright Notice:

[MIT License](https://github.com/videofeedback/Unreal_Engine_SerialCOM/blob/main/LICENSE)

[Copyright (c) 2015 v1 FusionLabz/Gryzly32 (UE4Duino)](https://forums.unrealengine.com/t/ue4duino-arduino-to-ue4-plugin-release/28963)

[Copyright (c) 2017-2020 v2 Rodrigo Villani Pereira (UE4Duino)](https://forums.unrealengine.com/t/free-windows-only-ue4duino-2-arduino-com-port-communication/95217#post728834)

[Copyright (c) 2021-2022 v3 Ramiro Montes De Oca (SerialCOM) fork of (UE4Duino 2.2.5)](https://github.com/videofeedback/Unreal_Engine_SerialCOM/)

[Copyright (c) 2023 v4 Ramiro Montes De Oca (SerialCOM)](https://github.com/videofeedback/Unreal_Engine_SerialCOM/)
  

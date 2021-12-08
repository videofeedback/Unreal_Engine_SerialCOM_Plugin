# Serial Communication Plugin for Unreal Engine
Serial Com Port Library for Unreal Engine 4 and Unreal Engine 5

## "Serial COM" v3.0.0.5 (Beta) RELEASE NOTES

- Small but significant change. Internally changed the function from "USerial" to "USerialCom" to avoid problems if another UE4Duino plugin is running at the same time. This change makes is to avoid any conflict with old functions and corruption of plugins.

## "Serial COM" v3.0.0.4 (Beta) (Fork of UE4Duino)


[![](https://raw.githubusercontent.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/main/SerialCOM/images/serial_com_fork_02.png)](hhttps://raw.githubusercontent.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/main/SerialCOM/images/serial_com_fork_02.png)


## Downloads:

[Plugin for Unreal Engine 4.25 (With Blueprint Example)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/releases/download/SerialCOM_v3.0.0.05/SERIALCOM_UE425.zip)

[Plugin for Unreal Engine 4.26 (With Blueprint Example)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/releases/download/SerialCOM_v3.0.0.05/SERIALCOM_UE426.zip)

[Plugin for Unreal Engine 4.27 (With Blueprint Example)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/releases/download/SerialCOM_v3.0.0.05/SERIALCOM_UE427.zip)

[Plugin for Unreal Engine 5.0 EA (With Blueprint Example) ](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/releases/download/SerialCOM_v3.0.0.05/SERIALCOM_UE5EA.zip)


[![](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/SerialCOM/images/serialcom_list_of_functions_01.png)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/SerialCOM/images/serialcom_list_of_functions_01.png)



### Renamed Functions:
-----------------------------------------------------------------------------------
	UE4Duino v2.2.5				Serial COM v 3.0.0 (Beta)
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
  
  
  
### "Serial COM" v3.0.0 (Beta) RELEASE NOTES

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

- "Serial COM" 3.0.0 will not be compatible with "UE4Duino" 2.2.5 because the library doesn't share the "UE4DUINO" name anymore, using its own new "SERIALCOM" identifier. Changing to this library will make the old EU4Duino modules in red, indicating that those components are not available anymore.
Solution: Each component can be replaced with the current version by replacing each one by hand. The replacement equivalent chart is available at:
https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port  (Modules lists comparison chart)

- Arduino doesn't connects again if you close the project without closing the port.
Solution:  Use the best practice of creating an "Event End Play" with "Close Serial Port" connected to the event. This is the cleanest solution for this problem and best practice. 
For more information, visit https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port where we describe the best practices for the use of this plugin.



## Opening Port Example

[![](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/SerialCOM/images/serialcom_opening_port_example_02.png)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/SerialCOM/images/serialcom_opening_port_example_02.png)



## Blueprint Example

Each Zip file contains the correstpondent blueprint for each UE version. Drag and drop the .uasset (Blueprint) file to your project. Read the complete insturctions inside the "BLUEPRINT" folder of this plugin.

[![](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/SerialCOM/images/serialcom_blueprint_example_01.png)](https://github.com/videofeedback/Unreal-Engine-Plugin-Communication-Serial-Port/blob/main/SerialCOM/images/serialcom_blueprint_example_01.png)


-----------------------------------------------------------------------------------------------------
Ramiro Montes De Oca (Ramiro's Lab)

Discord: https://discord.ramiroslab.com

YouTube: https://youtube.ramiroslab.com

Github: https://github.ramiroslab.com

----------------------------------------------------------------------------------------------------
Copyright (c) 2015 v1 FusionLabz/Gryzly32 (UE4Duino)

Copyright (c) 2018-2020 v2 Rodrigo Villani Pereira (UE4Duino)

Copyright (c) 2021-2022 v3 Ramiro Montes De Oca (SerialCOM) fork of (UE4Duino 2.2.5)


  

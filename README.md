# Advanced Bot Works' Sensors

## Summary

This is a library is utilised by all of the sensors manufactured by Advanced Bot Works. The program that runs on the Sensors can be found in this library and may be edited to help with specific scenarios. It may be downloaded as a ZIP file and installed as a library on Arduino IDE. The chips in all of the sensors emulate a Spike Prime Colour Sensor and send relevant data across the RED, Green and Blue (RGB) channels.

Apologies for the lack of commenting - this will be rectified when I next have time.

## Supported Platforms

This library is designed to work with Arduino IDE versions 2.3.x or later. Testing has not been done on older versions. The sensors are designed to work with LEGO Spike Prime platforms only.

## Getting Started

Advanced Bot Works sensors can be purchased from the [Advanced Bot Works] (https://advancedbotworks.com) website. Please read through product descriptions carefully before purchasing to ensure you are not disappointed.

A LEGO Spike Prime Hub will be required to connect to the sensor using the cable that is included in the package.

From there you can use the [online](https://spike.legoeducation.com/prime/lobby/) version of Spike Prime to program the Spike. Start a new project, When the Spike Hub is connected to your computer, it will appear as a Colour Sensor 

## Software

If you are using version 2.3.4 or later of the [Arduino software (IDE)](http://www.arduino.cc/en/Main/Software), you can use the Library Manager to install this library:

1. Download the [latest release archive from GitHub](https://github.com/aparajb/Advanced_Bot_Works_Sensors) as a .ZIP file.
2. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then "Add .ZIP Library...".
3. Navigate your file explorer to where the Advanced_Bot_Works_Sensors ZIP file is stored and select it.
4. Follow any further prompts given.

If this does not work, you can manually install the library:

1. Download the [latest release archive from GitHub](https://github.com/aparajb/Advanced_Bot_Works_Sensors) as a .ZIP file and decompress it.
2. Rename the folder "Advanced_Bot_Works_Sensors-main" to "Advanced_Bot_Works_Sensors".
3. Move the "Advanced_Bot_Works_Sensors" folder into the "libraries" directory inside your Arduino sketchbook directory.  You can view your sketchbook location by opening the "File" menu and selecting "Preferences" in the Arduino IDE.  If there is not already a "libraries" folder in that location, you should make the folder yourself.
4. After installing the library, restart the Arduino IDE.

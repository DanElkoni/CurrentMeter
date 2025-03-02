# CurrentMeter
## Overview
This project is a current meter that I designed and built for FSAE. This device was needed to accurately measure and log current for testing the custom internal fuses in our battery pack. I used altium to design the board, and C++ to program the boards logic

## The Schematic
![Schematic](/imgs/CurrentMeterSchematic.png)
This is the board schematic for the current meter device. The actual current sensor used is a DHAB S/137, which runs off of 5V and goes from -1000A to 1000A at 0V and 5V respectively. The brain of this board is an ESP32, which runs off of 3.3V. The board is powered by 5V so it contains a 3.3V regulator to continously power the board, and an RC circuit to boot up the board in the correct manner. Another main component of the board is the two voltage dividers on the high and low sensing pins off of the sensor, which bring the 5V down a third to 3.3V so that the ESP32 can properly read the sensor values.

## The Completed Device
![CompletedImage](/imgs/completed.jpg)

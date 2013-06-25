BlinkLed
========

The main goal of this project was to learn how to create an Arduino library.

BlinkLed creates a led object that can be turned on and off within a sketch and the library takes care of the blinking or breathing in the background.  This is basically the Arduino BlinkWithoutDelay tutorial made into a library with breathing added.  A sine wave function is used to create the breathing pattern.  Implementing the BlinkWithoutDelay code for several leds at once gets messy very quickly with all the different variables that are needed.  This library makes the process easier and neater.

To install, download the .zip file: https://github.com/bborncr/BlinkLed/archive/master.zip and rename the BlinkLed-master folder to BlinkLed.  Move the BlinkLed folder to your Arduino/libraries folder and restart the Arduino IDE.  This library should work for Arduino IDE v1.0 and newer.

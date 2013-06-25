/************************************************************************************
 * 	
 * 	Name    : BlinkLed.h                        
 * 	Author  : Bentley Born CRCibernetica                     
 * 	Date    : June 24, 2013                                    
 * 	Version : 0.1                                              
 * 	Notes   : A test Arduno library that hopefully demonstrates using classes to aid in multitasking             
 * 
 * 	Copyright (c) 2013 CRCibernetica All right reserved.
 * 
 * 	
 *          BlinkLed is free software: you can redistribute it and/or modify
 * 		    it under the terms of the GNU General Public License as published by
 * 		    the Free Software Foundation, either version 3 of the License, or
 * 		    (at your option) any later version.
 * 
 * 		    BlinkLed is distributed in the hope that it will be useful,
 * 		    but WITHOUT ANY WARRANTY; without even the implied warranty of
 * 		    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * 		    GNU General Public License for more details.
 * 
 * 		    You should have received a copy of the GNU General Public License
 * 		    along with BlinkLed.  If not, see <http://www.gnu.org/licenses/>.
 * 
 ***********************************************************************************/


//include guard
#ifndef BLINK_LED_H
#define BLINK_LED_H

#include "Arduino.h"

//Start of the class, change ExampleLib to your library name
class BlinkLed {
 
public: //everything under here is public, accessible outside of the class

//the class constructor
BlinkLed(int pin, long interval);

    void begin();
    void update();
	void turnOn(int blinktype);
	void turnOff();
 
private: //everything under here is private, only accessible inside the class

	int _pin;
	long _interval;
	boolean _LED_ON;
	int _ledState;
	long _previousMillis;
	int _blinktype; // blink=0, breathe=1
	float _ledStateBreathe;
	int _ledValueBreathe;
 
}; //end of class
 
#endif
//include guard end if
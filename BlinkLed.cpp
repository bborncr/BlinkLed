/************************************************************************************
 * 	
 * 	Name    : BlinkLed.cpp                        
 * 	Author  : Bentley Born                        
 * 	Date    : June 24, 2013                                    
 * 	Version : 0.1                                              
 * 	Notes   : A test Arduno library that hopefully demonstrates using classes to aid in multitasking               
 * 
 * 	Copyright (c) 2013 CRCibernetica All right reserved.
 * 
 * 
 * 		    BlinkLed is free software: you can redistribute it and/or modify
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

#include "Arduino.h"
#include "BlinkLed.h"
 
//the constructor
BlinkLed::BlinkLed(int pin, long interval){
  
  _pin = pin;
  _interval = interval;
}
 
//the body of begin function
void BlinkLed::begin(){
   _ledState = LOW;
   _previousMillis = 0;
   _LED_ON=false;
   _blinktype = 0;
   _ledStateBreathe = 0;
   _ledValueBreathe = 0;
   pinMode(_pin, OUTPUT);
}
 
//the body of the update function
void BlinkLed::update(){

  unsigned long currentMillis = millis();
 if(_LED_ON==true){
 if(_blinktype==0){
  if(currentMillis - _previousMillis > _interval) {
    // save the last time you blinked the LED 
    _previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (_ledState == LOW)
      _ledState = HIGH;
    else
      _ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(_pin, _ledState);
  }
  }else if(_blinktype==1){
   if(currentMillis - _previousMillis > _interval/62) {
    // save the last time you blinked the LED 
    _previousMillis = currentMillis; 
	if (_ledStateBreathe>6.2)  { 
      _ledStateBreathe=0;
    } else {
      _ledStateBreathe=_ledStateBreathe+.1;
    }
    _ledValueBreathe=(sin(_ledStateBreathe)+.65)*127;
    _ledValueBreathe=constrain(_ledValueBreathe,0,255);
    analogWrite(_pin,_ledValueBreathe);
	}
  }
  } else{
  _ledState=LOW;
  digitalWrite(_pin, _ledState);
  _ledStateBreathe=0;
  analogWrite(_pin, _ledStateBreathe);}

}

void BlinkLed::turnOn(int blinktype){
_LED_ON=true;
_blinktype=blinktype;
}

void BlinkLed::turnOff(){
_LED_ON=false;
}
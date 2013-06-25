#include "BlinkLed.h"

//constructor= BlinkLed <name_of_led>(<PWM pin>,<interval_millis>);
BlinkLed led1(9,1000); //on pin 9 create a 1 second led (choose a PWM pin)
BlinkLed led2(10,2000);//on pin 10 create a 2 second led (choose a PWM pin)
 
void setup(){
 
   led1.begin(); //initialize led1
   led2.begin(); //initialize led2

//turnOn(blinktype) - blinktype 0 = BLINK, 1 = BREATHE
//turnOff() turns the led off
   led1.turnOn(0); //or led1.turnOff() - this can be used anywhere in your code
   led2.turnOn(1); //or led2.turnOff() - this can be used anywhere in your code

}
 
void loop(){
  // try to NEVER use delay() especially with BREATHE
  // BREATHE contains 62 steps per cycle and needs to be updated often for smoothness
  led1.update();
  led2.update();

}



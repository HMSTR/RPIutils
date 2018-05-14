#include "LED.h"

void LEDinit(){
    wiringPiSetup();
    pinMode(LED_RED,OUT);
    pinMode(LED_BL1,OUT);
    pinMode(LED_BL2,OUT);
    pinMode(LED_BL3,OUT);
    pinMode(LED_GRE,OUT);
    pinMode(LED_YEL,OUT);
}

void LEDbroadcast(int val){
    digitalWrite(LED_RED,val);
    digitalWrite(LED_BL1,val);
    digitalWrite(LED_BL2,val);
    digitalWrite(LED_BL3,val);
    digitalWrite(LED_GRE,val);
    digitalWrite(LED_YEL,val);
}

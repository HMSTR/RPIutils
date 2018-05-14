#include "LED.h"

void LEDinit(){
    wiringPiSetup();
    pinMode(LED_RED,OUTPUT);
    pinMode(LED_BL1,OUTPUT);
    pinMode(LED_BL2,OUTPUT);
    pinMode(LED_BL3,OUTPUT);
    pinMode(LED_GRE,OUTPUT);
    pinMode(LED_YEL,OUTPUT);
}

void LEDbroadcast(int val){
    digitalWrite(LED_RED,val);
    digitalWrite(LED_BL1,val);
    digitalWrite(LED_BL2,val);
    digitalWrite(LED_BL3,val);
    digitalWrite(LED_GRE,val);
    digitalWrite(LED_YEL,val);
}

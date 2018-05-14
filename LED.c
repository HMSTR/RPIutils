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
    digitalWrite(LED_RED,1);
    digitalWrite(LED_BL1,1);
    digitalWrite(LED_BL2,1);
    digitalWrite(LED_BL3,1);
    digitalWrite(LED_GRE,1);
    digitalWrite(LED_YEL,1);
}

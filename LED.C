#include "LED.h"

void LEDinit(){
    pinMode(LED_RED,OUTPUT);
    pinMode(LED_BL1,OUTPUT);
    pinMode(LED_BL2,OUTPUT);
    pinMode(LED_BL3,OUTPUT);
    pinMode(LED_GRE,OUTPUT);
    pinMode(LED_YEL,OUTPUT);
}

void LEDbroadcast(int val){
    digitalWrite(LED_RED,(val)?1:0);
    digitalWrite(LED_BL1,(val)?1:0);
    digitalWrite(LED_BL2,(val)?1:0);
    digitalWrite(LED_BL3,(val)?1:0);
    digitalWrite(LED_GRE,(val)?1:0);
    digitalWrite(LED_YEL,(val)?1:0);
}
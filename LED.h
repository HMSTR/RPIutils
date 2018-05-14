#pragma once
#include <wiringPi.h>

#define LED_RED 7
#define LED_YEL 9
#define LED_GRE 8
#define LED_BL1 0
#define LED_BL2 2
#define LED_BL3 3


void LEDbroadcast(int val);
void LEDinit();
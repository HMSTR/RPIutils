#pragma once
#include <wiringPi.h>

#define LED_RED 7
#define LED_YEL 5
#define LED_GRE 3
#define LED_BL1 11
#define LED_BL2 13
#define LED_BL3 15


void LEDbroadcast(int val);
void LEDinit();
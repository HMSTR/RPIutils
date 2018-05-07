#pragma once
#include "I2C.h"
#define LCD_ADDR  0x27
#define LCD_WIDTH 20


#define LCD_DATA 1
#define LCD_SERV  0

#define LCD_LINE_0 0x00
#define LCD_LINE_1 0x80
#define LCD_LINE_2 0xC0
#define LCD_LINE_3 0x94
#define LCD_LINE_4 0xD4

#define LIGHT_ON 0x08
#define LIGHT_OFF 0x00
#define LIGHT_STATE LIGHT_ON


#define ENABLE 0b00000100

void LCDinit();
void LCDprint(char* message,int line);
void LCDclose();
void LCDgoto(int x,int y);
void LCDlightOff();
void LCDlightOn();
#include "LCD.h"
extern i2c;
void delay(int k){
    int i;
    for(i=0;i<k*1e4;i++);
}

int LCDwrite(char byte,int mode)
{
    char bits_high[1] = {mode | (byte & 0xF0) | LIGHT_STATE};
    char bits_low[1] = {mode | ((byte<<4) & 0xF0) | LIGHT_STATE};
    I2Cwrite(bits_high,1);
    toggle(bits_high,1);
    I2Cwrite(bits_low,1);
    toggle(bits_low);
}


void toggle(char byte[])
{
    delay(10);
    char tmpbuf[1];
    tmpbuf[0] = (byte[0] | ENABLE);
    I2Cwrite(tmpbuf,1);
    delay(10);
    tmpbuf[0] = (byte[0] & ~ENABLE);
    I2Cwrite(tmpbuf,1);
    delay(10);
}
int getLength(char* str){
    int i=0;
    while((str[i++]!='\0') && (i<255));
    return i;

}
void LCDprint(char* message,int line)
{
  int i;
  int length = getLength(message);
  LCDgoto(-1,line);
  for(i=0;i<length-1;i++){
    if((i % LCD_WIDTH) == 0)
        LCDgoto(0,++line);
    LCDwrite(message[i],LCD_DATA);
    
  }

}

void LCDgoto(int x,int y){
    switch(y){
        case 0: 
            y=LCD_LINE_0;
            break;
        case 1: 
            y=LCD_LINE_1;
            break;
        case 2: 
            y=LCD_LINE_2;
            break;
        case 3: 
            y=LCD_LINE_3;
            break;
        case 4: 
            y=LCD_LINE_4;
            break;
        default: 
            y=LCD_LINE_1;
            break;
    }
      LCDwrite(y,LCD_SERV);
      int i;
    for(i=0;i<x;i++)
        LCDwrite(' ',LCD_DATA);
}

void LCDinit()
{
    I2Copen(LCD_ADDR);
    LCDwrite(0x33,LCD_SERV);
    LCDwrite(0x32,LCD_SERV);
    LCDwrite(0x06,LCD_SERV);
    LCDwrite(0x0C,LCD_SERV); 
    LCDwrite(0x28,LCD_SERV);
    LCDwrite(0x01,LCD_SERV);
    delay(10);

}

void LCDclose()
{
    close(i2c);
}

// void LiquidCrystal_I2C::noBacklight(void) {
// 	_backlightval=LCD_NOBACKLIGHT;
// 	expanderWrite(0);
// }

// void LiquidCrystal_I2C::backlight(void) {
// 	_backlightval=LCD_BACKLIGHT;
// 	expanderWrite(0);
// }

void LCDlightOn(){
	I2Cwrite(LIGHT_ON);
}

void LCDlightOff(){
	I2Cwrite(LIGHT_OFF);
}

/*
int Exmaple(){

    LCDinit();
    int i,j;
    char buf[20];
    for(i=0;i<4;i++){
        for(j=0;j<20;j++)
            buf[j] = 56+j+i*j;
        LCDprint(buf,i);
    }
    LCDclose();
    return 1;
}
*/
#include "LCD.h"

extern i2c;
int LIGHT_STATE;

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
    Udelay(1);
    char tmpbuf[1];
    tmpbuf[0] = (byte[0] | ENABLE);
    I2Cwrite(tmpbuf,1);
    Udelay(10);
    tmpbuf[0] = (byte[0] & ~ENABLE);
    I2Cwrite(tmpbuf,1);
    Udelay(1);
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
    Udelay(1);
    LIGHT_STATE = LIGHT_ON;

}

void LCDclose()
{
    close(i2c);
}


void LCDlightOn(){
	LIGHT_STATE = LIGHT_ON;
    LCDwrite(0,LCD_SERV);
}

void LCDlightOff(){
    LIGHT_STATE = LIGHT_OFF;
    LCDwrite(0,LCD_SERV);
}

void LCDclear(){
    LCDwrite(0x01,LCD_SERV);
}


void LCDExample(){
     char *buf = "Current Time:";
     LCDinit();
     while(1){
         LCDprint(buf,0);
         const time_t timer = time(NULL);
         char *strTime = ctime(&timer);
         LCDprint(strTime,1);
     }
     LCDclose();
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

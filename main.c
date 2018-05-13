#include <time.h>

void lcdEtime(){
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

void lcdELED(){
    LEDinit();
    LEDbroadcast(1);
}


int main(){
    //lcdEtime();
    lcdELED();
}
#include"I2C.h"
#include"LCD.h"
#include <time.h>

int main(){
    char *buf = "Current Time:";
    LCDinit();
    while(1){
        LCDprint(buf,1);
        const time_t timer = time(NULL);
        char *strTime = ctime(&timer);
        LCDprint(strTime,2);
        if(timer % 2)
            LCDlightOn();
        else
            LCDlightOff();
    }
    LCDclose();
    return 1;
}
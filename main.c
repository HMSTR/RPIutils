#include <time.h>

int main(){
    char *buf = "Current Time:";
    LCDinit();
    while(1){
        LCDprint(buf,0);
        const time_t timer = time(NULL);
        char *strTime = ctime(&timer);
        LCDprint(strTime,1);
        if(timer % 2)
            LCDlightOn();
        else{
            LCDlightOff();
            delay(10);
            LCDlightOn();
            LCDclear();
            delay(10);
    }
    }
    LCDclose();
    return 1;
}
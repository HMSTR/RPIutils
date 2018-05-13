#include "utils.h"

void delay(int sec){
    unsigned int timer = clock()+sec*100;
    while(clock()<timer);
}


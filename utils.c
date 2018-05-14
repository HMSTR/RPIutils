#include "utils.h"

void Udelay(int sec){
    unsigned int timer = clock()+sec*100;
    while(clock()<timer);
}


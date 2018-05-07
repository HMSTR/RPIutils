#include "utils.h"

void delay(int sec){
    unsigned int retTime = time(0) + sec;
    while (time(0) < retTime);
    }
#include "utils.h"

void delay(int sec){
    unsigned int timer = time(0)+sec;
    while(time(0)<timer);
}
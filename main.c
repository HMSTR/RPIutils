#include "LED.h"

void LEDExample(){
    LEDinit();
    LEDbroadcast(1);
}


int main(){
    LEDExample();
}
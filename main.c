#include "LED.h"

void LEDExample(){
    LEDinit();
    LEDbroadcast(1);
}

#define LED 13
int main(){
    //LEDExample();
    wiringPiSetup();
    pinMode (LED, OUTPUT);

  for (;;)
  {
    digitalWrite (LED, HIGH) ;	// On
    delay (500) ;		// mS
    digitalWrite (LED, LOW) ;	// Off
    delay (500) ;
  }
  return 0 ;
}
}
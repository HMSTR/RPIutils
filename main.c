#include "LED.h"
int main(){
LEDinit();
while(1){
LEDbroadcast(1);
delay(500);
LEDbroadcast(0);
delay(500);

}
return 1;
}

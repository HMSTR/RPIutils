#include "LED.h"
#include "utils.h"
int main(){
LEDinit();
while(1){
LEDbroadcast(1);
delay(1);
LEDbroadcast(0);

}
return 1;
}

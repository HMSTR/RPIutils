//#include "LED.h"
// int main(){
// LEDinit();
// while(1){
// LEDbroadcast(1);
// delay(500);
// LEDbroadcast(0);
// delay(500);

// }
// return 1;
// }
#include "1-wire.c"
int main(){
    OneWire reader = new OneWire(6);
    reader.oneWireInit();
    int n = 100;
    uint64_t rom = reader.readRom();
    cout << "---------------------------------" << endl;
    cout << "rom = " << rom << endl;
    cout << "---------------------------------" << endl;

    return 1;
}
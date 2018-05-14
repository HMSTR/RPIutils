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
#include "1-wire.h"
#include<iostream>
using namespace std;
int main(){
    OneWire *reader = new OneWire(6);
    reader->oneWireInit();
    int n = 15;
    uint64_t roms[n];
    reader->searchRom(roms, n);
    cout << "We've found "<< n << "roms"<<endl;
    for (int i = 0; i < n; i++) {
      cout << "addr T[" << (i + 1) << "] = " << roms[i] << endl;
    }
    return 1;
}
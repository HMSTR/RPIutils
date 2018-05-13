#include <iostream>
#include <wiringPi.h>
#include "1-wire.h"
 
using namespace std;
 
int main() {
  OneWire * reader = new OneWire(22);
  try {
    reader->oneWireInit();
    uint64_t roms[n];
    reader->searchRom(roms, n);
    cout << "---------------------------------" << endl;
    cout << "devices = " << n << endl;
    cout << "---------------------------------" << endl;
  }
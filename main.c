#include <iostream>
#include <wiringPi.h>
#include "1-wire.h"
 
using namespace std;
 
double getTemp(OneWire * oneWire, uint64_t ds18b20s) {
  uint8_t data[9];
 
  do {
    oneWire->setDevice(ds18b20s);
    oneWire->writeByte(CMD_CONVERTTEMP);
 
    delay(750);
 
    oneWire->setDevice(ds18b20s);
    oneWire->writeByte(CMD_RSCRATCHPAD);
 
    for (int i = 0; i < 9; i++) {
      data[i] = oneWire->readByte();
    }
  } while (oneWire->crc8(data, 8) != data[8]);
 
  return ((data[1] << 8) + data[0]) * 0.0625;
}
 
int main() {
  OneWire * reader = new OneWire(22);
  try {
    ds18b20->oneWireInit();
 
    uint64_t roms[n];
    ds18b20->searchRom(roms, n);
    cout << "---------------------------------" << endl;
    cout << "devices = " << n << endl;
    cout << "---------------------------------" << endl;
 
}
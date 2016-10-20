#include <Wire.h>

#define SLAVE_ADDRESS 0x04

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}

void loop() {
  
}
void receiveData(int byteCount) {

  while (Wire.available()) {
    DATA_TO_BE_READ = Wire.read();
    
  }
}

void sendData() {
  Wire.write(DATA_TO_BE_SEND);
}

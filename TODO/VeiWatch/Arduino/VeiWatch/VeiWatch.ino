#include<Wire.h>
uint8_t sensorTemp = A0;
uint8_t sensorPulse = A1;
void setup() {
  pinMode(sensorTemp,INPUT);
  pinMode(sensorPulse,INPUT);
}
void getTemp(){
  uint16_t getTemp = 0;
  getTemp = analogRead(sensorTemp);
}
void getPulse(){
  uint16_t getPulse = 0;
  getPulse = analogRead(getPulse);
}
void loop() {
  
}

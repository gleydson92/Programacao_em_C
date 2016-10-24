#include <Wire.h>

#define alpha 0.75  //Signal Treatment Constant

#define KY039 A0 // Heartbeat Module 
#define LM35  A1 // Temperatura Sensor

#define SLAVE_ADDRESS 0x04  //Device(ATMEGA328) Address for I2C Protocol


/*Global Variables to be sended to RPi*/
unsigned int pulse = 0;
unsigned int temperature = 0;

/*This function do not seen to be confiable because it takes a signal
from de finger and do not care about heart frequency and dont even gets 
the same value from the different positions of the fingerstip*/
int getPulse(){
  static double oldValue = 0;
  int leitura=analogRead(A0);
  double value = alpha*leitura+(1-alpha)*oldValue;

  oldValue = value;
  return (int)oldValue/5;
}
unsigned int getTemperature(){
  unsigned int temp = (float(analogRead(LM35))*5/(1023))/0.01;
  return temp;
}

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Wire.begin(SLAVE_ADDRESS);
 //Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}

void loop() {
  temperature = getTemperature();
  pulse = (unsigned int)getPulse;
}
/*void receiveData(int byteCount) {

  while (Wire.available()) {
    DATA_TO_BE_READ = Wire.read();
    
  }
}*/

void sendData() {
  Wire.write(temperature);
  delay(100);
  Wire.write(pulse);
}

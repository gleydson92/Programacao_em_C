
#define SENSORPULSE 13
#define LM35 A1
#define NSAMPLES 10
#define AUXSIZE 5
#define STRSIZE 10
/* Global Variables */
unsigned int times[NSAMPLES],aux=0,iCount=0,cont=0;

uint8_t Data_Sended = false;

void setup() {
  pinMode(LM35,INPUT);
  Serial.begin(9600);
  times[0]=millis();
  aux = times[0];
}

char *tempFormat(int temperature){
  char *toReturn,toFormat[AUXSIZE];
  memset(toFormat,'\0',AUXSIZE);
  if     (temperature  <   10)  snprintf(toFormat,AUXSIZE,"000%d",temperature);
  else if( temperature <  100)  snprintf(toFormat,AUXSIZE," 00%d",temperature);
  else if( temperature < 1000)  snprintf(toFormat,AUXSIZE,"  0%d",temperature);
  else                          snprintf(toFormat,AUXSIZE,"   %d",temperature);
  toReturn = toFormat;
  return toReturn;
}
char *bpmFormat(int bpm){
  char *toReturn, toFormat[AUXSIZE];
  memset(toFormat,'\0',AUXSIZE);
  if     (bpm <  10)  snprintf(toFormat,AUXSIZE,"00%d",bpm);
  else if(bpm < 100)  snprintf(toFormat,AUXSIZE," 0%d",bpm);
  else                snprintf(toFormat,AUXSIZE,"  %d",bpm);
  toReturn = toFormat;
  return toReturn;
}

void loop() {
  int analogTemp ;
  while(analogRead(A0) < 800){   
    pinMode(SENSORPULSE,INPUT);
    if(digitalRead(SENSORPULSE)==HIGH){
      while(digitalRead(SENSORPULSE)==HIGH){}
      cont++;
      iCount++;
    }
    times[1]=millis();
    if((times[1]-aux) > 10000){
      
      Data_Sended = false;
      analogTemp = analogRead(LM35);
      Serial.write(analogRead(LM35));
      Serial.write(iCount*6);
      aux = millis();
      iCount = 0;
    }
    if((times[1]-times[0]) > 60000){
      Serial.write(analogRead(LM35));
      Serial.write(cont);
      times[0]=millis();
      cont = 0;
    }
  }
  if(Data_Sended == false){
    pinMode(SENSORPULSE,OUTPUT);// Only to do not receive any data in this pin
    Serial.write(0);
    Serial.write(0);
    Data_Sended = true;
  }
}

#include<Servo.h>
#define pot A0
#define percent 0.05
Servo servo;
int firstread=0, valbaixo = 0, valcima = 0;
void setup()
{
  pinMode(pot,INPUT);
  servo.attach(9);
  firstread = map(analogRead(pot),0,1023,15,180);
  valbaixo = map(analogRead(pot),0,1023,15,180)-(map(analogRead(pot),0,1023,15,180)*percent);
  valcima = map(analogRead(pot),0,1023,15,180)+(map(analogRead(pot),0,1023,15,180)*percent);
}
void loop()
{
  if(analogRead(pot)>valcima || analogRead(pot)<valbaixo)
  {
    valbaixo = map(analogRead(pot),0,1023,15,180)-(map(analogRead(pot),0,1023,15,180)*percent);
    valcima = map(analogRead(pot),0,1023,15,180)+(map(analogRead(pot),0,1023,15,180)*percent);
    servo.write(map(analogRead(pot),0,1023,15,180));
  }
}

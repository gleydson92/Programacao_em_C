#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include<Servo.h>
#define percent 0.05
Adafruit_PCD8544 display = Adafruit_PCD8544(8, 4, 5, 7, 6);
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int pot1 = A0,pot2 = A1,pot3 = A2,pot4 = A3,valpot1=0,valpot2=0,valpot3=0,valpot4=0; // Variáveis para o Potenciometro
int botao1 = 2 , botao2 = 12, botao3 = 13;// Entrada dos Botões
//int estadobotao1=0,estadobotao2=0,estadobotao3=0;// Estados dos Botões
int vetor1[50],vetor2[50],vetor3[50],vetor4[50], contador=0;
int firstread1=0, valbaixo1 = 0, valcima1 = 0;
int firstread2=0, valbaixo2 = 0, valcima2 = 0;
int firstread3=0, valbaixo3 = 0, valcima3 = 0;
int firstread4=0, valbaixo4 = 0, valcima4 = 0;
/*Referência:http://www.arduinoecia.com.br/2013/05/display-lcd-nokia-5110.html */
void setup()
{
  for(int cont = 0 ; cont < 50 ; cont ++)
  {
    vetor1[cont] = 0;
    vetor2[cont] = 0;
    vetor3[cont] = 0;
    vetor4[cont] = 0;
  }
  display.begin();//Inicia o Display
  display.clearDisplay();// Limpa o Display
  Serial.begin(9600);
  servo1.attach(3);// Definir os Pinos PWM para os servos
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  pinMode(botao1,INPUT);
  pinMode(botao2,INPUT);
  pinMode(botao3,INPUT);
  pinMode(pot1,INPUT);
  pinMode(pot2,INPUT);
  pinMode(pot3,INPUT);
  pinMode(pot4, INPUT);
  //primeiraleitura();
}
void loop()
{
  lepotenciometros();
  lebotoes();
}
/*void primeiraleitura()
{
  firstread1 = map(analogRead(pot1),0,1023,15,180);
  valbaixo1 = map(analogRead(pot1),0,1023,15,180)-(map(analogRead(pot1),0,1023,15,180)*percent);
  valcima1 = map(analogRead(pot1),0,1023,15,180)+(map(analogRead(pot1),0,1023,15,180)*percent);
  firstread2 = map(analogRead(pot2),0,1023,15,180);
  valbaixo2 = map(analogRead(pot2),0,1023,15,180)-(map(analogRead(pot2),0,1023,15,180)*percent);
  valcima2 = map(analogRead(pot2),0,1023,15,180)+(map(analogRead(pot2),0,1023,15,180)*percent);
  firstread3 = map(analogRead(pot3),0,1023,15,180);
  valbaixo3 = map(analogRead(pot3),0,1023,15,180)-(map(analogRead(pot3),0,1023,15,180)*percent);
  valcima3 = map(analogRead(pot3),0,1023,15,180)+(map(analogRead(pot3),0,1023,15,180)*percent);
  firstread4 = map(analogRead(pot4),0,1023,15,180);
  valbaixo4 = map(analogRead(pot4),0,1023,15,180)-(map(analogRead(pot4),0,1023,15,180)*percent);
  valcima4 = map(analogRead(pot4),0,1023,15,180)+(map(analogRead(pot4),0,1023,15,180)*percent);
}*/
void lepotenciometros()
{
  //if(estadobotao1 == 0)
    /*if(analogRead(pot1)>valcima1 || analogRead(pot1)<valbaixo1)
    {
      valbaixo1 = map(analogRead(pot1),0,1023,0,180)-(map(analogRead(pot1),0,1023,0,180)*percent);
      valcima1 = map(analogRead(pot1),0,1023,0,180)+(map(analogRead(pot1),0,1023,0,180)*percent);
      servo1.write(map(analogRead(pot1),0,1023,0,180));
    }
    if(analogRead(pot2)>valcima2 || analogRead(pot2)<valbaixo2)
    {
      valbaixo2 = map(analogRead(pot2),0,1023,0,180)-(map(analogRead(pot2),0,1023,0,180)*percent);
      valcima2 = map(analogRead(pot2),0,1023,0,180)+(map(analogRead(pot2),0,1023,0,180)*percent);
      servo2.write(map(analogRead(pot2),0,1023,0,180));
    }
    if(analogRead(pot3)>valcima3 || analogRead(pot3)<valbaixo3)
    {
      valbaixo3 = map(analogRead(pot3),0,1023,0,180)-(map(analogRead(pot3),0,1023,0,180)*percent);
      valcima3 = map(analogRead(pot3),0,1023,0,180)+(map(analogRead(pot3),0,1023,0,180)*percent);
      servo3.write(map(analogRead(pot3),0,1023,0,180));
    }
    if(analogRead(pot4)>valcima4 || analogRead(pot4)<valbaixo4)
    {
      valbaixo4 = map(analogRead(pot4),0,1023,0,180)-(map(analogRead(pot4),0,1023,0,180)*percent);
      valcima4 = map(analogRead(pot4),0,1023,0,180)+(map(analogRead(pot4),0,1023,0,180)*percent);
      servo4.write(map(analogRead(pot4),0,1023,0,180));
    }*/
      //nokia();
      servo1.write(map(analogRead(pot1),0,1023,0,180));
      servo2.write(map(analogRead(pot2),0,1023,0,180));
      servo3.write(map(analogRead(pot3),0,1023,0,180));
      servo4.write(map(analogRead(pot4),0,1023,0,180));
}
void lebotoes()
{
  if(digitalRead(botao1) == HIGH)
  {
      armazena();
      while(digitalRead(botao1)==HIGH){}
  }
  if(digitalRead(botao2) == HIGH)
  {
    executa();
    //estadobotao2 = 1;
    while(digitalRead(botao2)==HIGH){}
  }
  if(digitalRead(botao3) == HIGH)
  {
    apaga();
    while(digitalRead(botao3)==HIGH){}
  }
}
void armazena()
{
  vetor1[contador] = map(analogRead(pot1),0,1023,0,180);
  vetor2[contador] = map(analogRead(pot2),0,1023,0,180);
  vetor3[contador] = map(analogRead(pot3),0,1023,0,180);
  vetor4[contador] = map(analogRead(pot4),0,1023,0,180);
  contador++;
}
void executa(){
  for(int cont=0;cont<contador;cont++)
  {
    servo1.write(vetor1[cont]);
    delay(500);
    servo2.write(vetor2[cont]);
    delay(500);
    servo3.write(vetor3[cont]);
    delay(500);
    servo4.write(vetor4[cont]);
    delay(500);
  }
  //estadobotao2 = 0;
}
void apaga(){
  for(int cont=0;cont<contador;cont++)
  {
      vetor1[cont] = 0;
      vetor2[cont] = 0;
      vetor3[cont] = 0;
      vetor4[cont] = 0;
  }
  contador = 0;
}
void nokia(){
  /*Função Utilizada para Imprimir para o Usuário o ângulo do servo motor na Função Manual*/
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setContrast(0);
  display.setCursor(0, 0);
  display.println(" ## Manual ##");
  display.setCursor(0,20);
  display.println("Angulo:");
  display.setCursor(65, 20);
  display.println(valpot1);
  display.setCursor(65, 30);
  display.println(contador);
  display.setCursor(0, 30);
  display.println("Pos.Arm:");
  display.display();
}

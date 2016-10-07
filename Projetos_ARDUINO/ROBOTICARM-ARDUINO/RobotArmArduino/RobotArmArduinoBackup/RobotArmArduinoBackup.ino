#include<Servo.h>
Servo servo1; // Inicialização de Objeto, SERVO
Servo servo2;
Servo servo3;
Servo servo4;
int pot1 = A0,pot2 = A1,pot3 = A2,pot4 = A3,valpot1=0,valpot2=0,valpot3=0,valpot4=0; // Variáveis para o Potenciometro
int botao1 = 2 , botao2 = 3, botao3 = 4;// Entrada dos Botões
int vetor1[150],vetor2[150],vetor3[150],vetor4[150], contador=0;
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
  //Serial.begin(9600);
  servo1.attach(6);// Definir os Pinos PWM para os servos
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
}
void loop()
{
  Serial.println(analogRead(pot1));
  lepotenciometros();
  lebotoes();
}
void lepotenciometros()
{
  servo1.write(map(analogRead(pot1),0,1023,0,180));
  servo2.write(map(analogRead(pot2),0,1023,0,180));
  servo3.write(map(analogRead(pot3),0,1023,0,180));
  servo4.write(map(analogRead(pot4),0,1023,0,180));
}
void lebotoes()
{
  if(digitalRead(botao1) == HIGH)
  {
    while(digitalRead(botao1)==HIGH){}
    armazena();
  }
  if(digitalRead(botao2) == HIGH)
  {
    while(digitalRead(botao2)==HIGH){}
    executa();
  }
  if(digitalRead(botao3) == HIGH)
  {
    while(digitalRead(botao3)==HIGH){}
    apaga();
  }
}
void armazena()
{
  vetor1[contador] = map(analogRead(pot1),0,1023,0,180);
  vetor2[contador] = map(analogRead(pot2),0,1023,0,180);
  vetor3[contador] = map(analogRead(pot3),0,1023,0,180);
  vetor4[contador] = map(analogRead(pot4),0,1023,0,180);
  Serial.println("Posicao Servo1 armazenada:");
  Serial.println(vetor1[contador]);
  Serial.println("Posicao Servo2 armazenada:");
  Serial.println(vetor2[contador]);
  Serial.println("Posicao Servo3 armazenada:");
  Serial.println(vetor3[contador]);
  Serial.println("Posicao Servo4 armazenada:");
  Serial.println(vetor4[contador]);
  contador++;
  Serial.println("Contador");
  Serial.println(contador);
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

unsigned long tempodelay = 32767;
unsigned long tempodelay1= 153000/2; // 500ms
unsigned const int led = 13 ;
unsigned const int botao = 10;
unsigned int minutos=0;
 float tempo = 0;
unsigned int segundos=0;
String minuto = " ";
String segundo = " ";
void setup(){
  pinMode(led,OUTPUT);
  pinMode(botao,INPUT);
  Serial.begin(9600);
}
void loop(){
  if(Serial.available()){
  Serial.println("Insira os Minutos:");
  minuto = Serial.readString();
  Serial.flush();
  tempo = minuto.toFloat();
  Serial.println(tempo);
  minutos = tempo;
  segundos = (tempo - minutos)*100;
  segundos = segundos + 0.0100001191;
  Serial.println("Minutos:");
  Serial.println(minutos);
  Serial.println("Segundos:");
  Serial.println(segundos);
  }
  
  if(digitalRead(botao) == HIGH){ while(digitalRead(botao) == HIGH){}
  for(int cont1 = minutos ; cont1 >=0;cont1--){
   for(int cont2 = segundos ; cont2 >=0;cont2--){
    Serial.println("Minutos:");
    Serial.println(cont1);
    Serial.println("Segundos:");
    Serial.println(cont2);
    for(int cont = 0 ; cont < tempodelay1 ; cont ++){digitalWrite(led,LOW);}
    for(int cont = 0 ; cont < tempodelay1 ; cont ++){digitalWrite(led,HIGH);}
   }
  }
}
}


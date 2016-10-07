#define maxleitura 10
int leituras[maxleitura];
int contleitura = 0;
int total =0 ;
int media =0 ;
int pot = A0;

void setup()
{
  pinMode(pot, INPUT);
  for(int cont = 0 ; cont < maxleitura ; cont ++)
    leituras[cont] = 0;
}
void loop()
{
  total = total - leituras[contleitura];
  leituras[contleitura]=analogRead(pot);
  total=total+leituras[contleitura];
  contleitura++;
  if(contleitura>=10)
    contleitura = 0;
  media = total/10;
  delay(1);
}

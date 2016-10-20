uint8_t sensor = A0;
void setup() {
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = 0;
  leitura = analogRead(sensor);
  Serial.println(leitura);
  delay(100);
}

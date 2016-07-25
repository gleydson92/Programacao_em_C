unsigned const int sensor = A0;

// NO VOID_SETUP FAÇA:	pinMode(sensor,INPUT);

int hall(int n_amostras){
	long int media = 0;
	long int soma = 0;
	int a = 0;
	int val = 0;
	analogReference(EXTERNAL);
	for(int contador = 0 ; contador < n_amostras;contador++){
		val = analogRead(sensor);
		a = 1023 - val;
		soma = soma + a;
	}
	media = soma /(n_amostras);
	return media;
}

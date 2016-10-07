#include<stdio.h>
#include<time.h>
int main(void){
	clock_t tempoInicial=0,tempoFinal=0;
	double tempoGasto=0;
	int numero=0;
	tempoInicial = clock();
	printf("Insira um Número maior que 0 para entrar no programa");
	do{scanf("%d",&numero);}while(numero<=0);
	tempoFinal = clock();
	tempoGasto = tempoFinal-tempoInicial;
	tempoGasto = ((double)tempoGasto / CLOCKS_PER_SEC)*1000.0;
	printf("Parabéns!!! Você demorou %f segundos para entrar no programa!\n",tempoGasto);
}

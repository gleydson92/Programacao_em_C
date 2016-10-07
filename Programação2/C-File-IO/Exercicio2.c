/*
Em uma cidade do interior, sabe-se que de janeiro a abril de 1990 (121 dias)
não ocorreu temperatura inferior a 15.5 graus centígrados nem superior a
39.7 graus centígrados. Considere um arquivo texto (denominado
“temperat.txt”) que contém todas as temperaturas ocorridas nestes 121 dias
(uma temperatura por linha). Faça um programa que calcule e apresente:
• a menor temperatura ocorrida;
• a maior temperatura ocorrida;
• a temperatura média;
• número de dias nos quais a temperatura foi inferior à temperatura média;
• número de dias nos quais a temperatura foi superior à temperatura média.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
	float temperaturas[121],menor=0,maior=0,media=0;
	int contador=0,diasmenor=0,diasmaior=0;
	time_t t;
    srand((unsigned) time(&t));
	FILE *temperatura;
	temperatura = fopen("temperat.txt","r+");
	if(temperatura == NULL){	
		temperatura = fopen("temperat.txt","a+");
		for(contador = 0; contador < 121;contador++){
			temperaturas[contador]=155+rand()%397;
			temperaturas[contador]=temperaturas[contador]/10;
			fprintf(temperatura,"%.2f\n",temperaturas[contador]);
		}
	}
	while(!feof(temperatura)|| contador<121){
	contador++;
	fscanf(temperatura,"%f",&temperaturas[contador]);
	media=media+temperaturas[contador];
	}
	media = media/121;
	menor = media;
	for(int cont = 0 ; cont < 121;cont ++){
		if(temperaturas[cont]<menor)
			menor = temperaturas[cont];
		if(temperaturas[cont]<media)
			diasmenor++;
	}
	for(int cont = 0 ; cont < 121;cont++){
		if(temperaturas[cont]>maior)
			maior=temperaturas[cont];
		if(temperaturas[cont]>media)
			diasmaior++;
	}
	printf("Menor Temperatura:\t%.2f\nMaior Temperatura:\t%.2f\nTemperatura Media:\t%.2f\n",menor,maior,media);
	printf("Número de dias com a temperatura menor que a média:\t%d\n",diasmenor);
	printf("Número de dias com a temperatura maior que a média:\t%d\n",diasmaior);
	fclose(temperatura);
}

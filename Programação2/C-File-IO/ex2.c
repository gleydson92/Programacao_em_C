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

int main (void)
{
	float temperaturas[121],media=0, maior=0,menor=0;
	int cont =0, cont2=0, cont3=0;	
	FILE *temp;
	temp = fopen("temperat2.txt", "r");
	if(temp == NULL){
	printf("Erro ao abrir o arquivo");
	temp = fopen("temperat2.txt", "w+");
	for(float temperatura = 15.5; temperatura<= 39.7; temperatura+=0.2)
		fprintf(temp ,"%f\n", temperatura);
	}
	while(!feof(temp)){
	fscanf(temp, "%f", &temperaturas[cont]);
	media= media+temperaturas[cont];
	cont++;
	}
	media = media/121;
	menor=temperaturas[0];
	for(cont=0;cont<121;cont++){
		if(temperaturas[cont]<menor)
		menor = temperaturas[cont];
		if(temperaturas[cont]<media);
		cont2++;
	}
	for(cont=0;cont<121;cont++){	
		if(temperaturas[cont]>media);
		cont3++;
		if(temperaturas[cont]>maior)
		maior = temperaturas[cont];
	}
	fprintf(stdout,"Menor:%f\nMaior:%f\nMedia:%f\nDias menor:%d\nDias maior:%d\n", menor,maior,media, cont2,cont3);
	fclose(temp);
}

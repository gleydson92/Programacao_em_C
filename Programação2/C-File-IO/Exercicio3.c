/*Faça um programa que apure o resultado de uma eleição que possua, no
máximo, 100 eleitores. Suponha que existam 5 candidatos cujos códigos de
identificação são: 1, 2, 3, 4, 5. Considere um arquivo texto (denominado
“votos.txt”) que contém, em cada linha, um determinado voto (um voto é
representado pelo código de identificação do candidato). O programa deverá
apresentar, como resultado, o código de identificação e a quantidade de
votos do candidato mais votado, o código de identificação e a quantidade de
votos do candidato menos votado e a quantidade de votos nulos (um voto
nulo é um voto cujo código de identificação é inválido).*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void){
	FILE *voto;
	voto = fopen("votos.txt","r+");
	time_t t;
    srand((unsigned) time(&t));
	int votos[100],candA=0,candB=0,candC=0,candD=0,candE=0,nulos=0,maior=0,menor=0;
	if(voto==NULL){
		voto = fopen("votos.txt","w+");
		for(int contador = 0 ; contador < 100; contador++)
			fprintf(voto,"%d\n",1+rand()%5);
	}
	for(int cont=0;cont<100;cont++){
		fscanf(voto,"%d",&voto[cont]);
		if(votos[cont] == 1)	candA++;
		else if(votos[cont] == 2) candB++;
		else if(votos[cont] == 3) candC++;
		else if(votos[cont] == 4) candD++;
		else if(votos[cont] == 5) candE++;
		else nulos++;
	}
	if(candA>candB && candA>candC && candA>candD && candA>candE)	printf("Candidato 1 Venceu com %d votos!\n",candA);
	if(candB>candA && candB>candC && candB>candD && candB>candE)	printf("Candidato 2 Venceu com %d votos!\n",candB);
	if(candC>candA && candC>candB && candC>candD && candC>candE)	printf("Candidato 3 Venceu com %d votos!\n",candC);
	if(candD>candA && candD>candB && candD>candC && candD>candE)	printf("Candidato 4 Venceu com %d votos!\n",candD);
	if(candE>candA && candE>candB && candE>candC && candE>candD)	printf("Candidato 5 Venceu com %d votos!\n",candE);

	if(candA<candB && candA<candC && candA<candD && candA<candE)	printf("Candidato 1 Perdeu com %d votos!\n",candA);
	if(candB<candA && candB<candC && candB<candD && candB<candE)	printf("Candidato 2 Perdeu com %d votos!\n",candB);
	if(candC<candA && candC<candB && candC<candD && candC<candE)	printf("Candidato 3 Perdeu com %d votos!\n",candC);
	if(candD<candA && candD<candB && candD<candC && candD<candE)	printf("Candidato 4 Perdeu com %d votos!\n",candD);
	if(candE<candA && candE<candB && candE<candC && candE<candD)	printf("Candidato 5 Perdeu com %d votos!\n",candE);
	printf("\nVotos Nulos:%d\n");
	fclose(voto);
}

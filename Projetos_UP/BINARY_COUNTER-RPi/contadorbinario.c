#include"RaspberryGPIO.h"
void binary(int decimal1,int binario1[]);
int main(void){	
	GPIOexport(14);
	GPIOexport(15);
	GPIOexport(18);
	GPIOexport(23);
	GPIOexport(25);
	GPIOexport(5);
	GPIOdirection(5,SAIDA);
	GPIOdirection(14,SAIDA);
	GPIOdirection(15,SAIDA);
	GPIOdirection(18,SAIDA);
	GPIOdirection(23,SAIDA);
	GPIOdirection(25,ENTRADA);
	int decimal = 0,binario[4];
	while(1){
		for(int cont1 = 0; cont1<4;cont1++)
			binario[cont1]=0;
		binary(decimal,binario);
		if((int)GPIORead(25)==1){
		while(GPIORead(25)==1){}
			GPIOWrite(14,binario[0]);
			GPIOWrite(15,binario[1]);
			GPIOWrite(18,binario[2]);
			GPIOWrite(23,binario[3]);
			printf("Posição 1 do Vetor: %d\n",binario[0]);
			printf("Posição 2 do Vetor: %d\n",binario[1]);
			printf("Posição 3 do Vetor: %d\n",binario[2]);
			printf("Posição 4 do Vetor: %d\n",binario[3]);
			decimal++;
		}
	}
}
void binary(int decimal1,int binario1[])
{
	int cont = 0,resto=0;
	while(decimal1!=0){
	resto = decimal1%2;
	binario1[cont] = resto == 0? 0:1;
	decimal1 = decimal1/2;
	cont++;
	}
}

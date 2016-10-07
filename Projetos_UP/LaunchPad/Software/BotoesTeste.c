#include<stdio.h>
#include"RaspberryGPIO.h"
#include<stdlib.h>
#include<stdint.h>

const uint8_t colLed[4]={21,20,16,12};
const uint8_t rowLed[4]={26,19,13,6};
const uint8_t colBot[4]={25,24,23,18};
const uint8_t rowBot[4]={5,17,22,27};
struct Argumentos{
	unsigned int row;
	unsigned int col;
};
bool ledControl(unsigned const int row,unsigned const int col,unsigned int state){
	state == 1?HIGH:LOW;
	if(!GPIOWrite(rowLed[row],state)) return false;
	if(!GPIOWrite(colLed[col],state)) return false;
	else return true;
}
void buttonVerify(void){
	//struct Argumentos *Arg = sArguments;
	//unsigned int iCol = Arg->col;
	for(register unsigned int iRow = 0 ; iRow < 4 ; iRow++){
		GPIOWrite(rowBot[iRow],HIGH);
		for(register unsigned int iCol = 0; iCol < 4; iCol++){
			if(GPIORead(colBot[iCol])==HIGH){
				while(GPIORead(colBot[iCol])==HIGH){
					ledControl(iRow,iCol,1);
				}
			//push(iRow,iCol,&sFila);
			}			
			ledControl(iRow,iCol,0);
		}
		GPIOWrite(rowBot[iRow],LOW);
	}
}
int main(void){
	printf("Teste do Projeto LaunchPad");
		
	printf("\nExportando Terminais...\n");
	/*	
	for(register unsigned int iCount=0;iCount<4;iCount=0){
		GPIOSetup(colLed[iCount],SAIDA);	
		GPIOSetup(rowLed[iCount],SAIDA);
		GPIOSetup(colBot[iCount],ENTRADA);
		GPIOSetup(rowBot[iCount],SAIDA);
	}	
	*/	
	GPIOSetup(colLed[0],SAIDA);	
	GPIOSetup(rowLed[0],SAIDA);
	GPIOSetup(colBot[0],ENTRADA);
	GPIOSetup(rowBot[0],SAIDA);
	GPIOSetup(colLed[1],SAIDA);	
	GPIOSetup(rowLed[1],SAIDA);
	GPIOSetup(colBot[1],ENTRADA);
	GPIOSetup(rowBot[1],SAIDA);
	GPIOSetup(colLed[2],SAIDA);	
	GPIOSetup(rowLed[2],SAIDA);
	GPIOSetup(colBot[2],ENTRADA);
	GPIOSetup(rowBot[2],SAIDA);
	GPIOSetup(colLed[3],SAIDA);	
	GPIOSetup(rowLed[3],SAIDA);
	GPIOSetup(colBot[3],ENTRADA);
	GPIOSetup(rowBot[3],SAIDA);

	printf("Terminais Exportados!!!\n");
	while(1){
		buttonVerify();
	}
}

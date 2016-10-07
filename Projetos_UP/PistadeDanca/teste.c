#include"RaspberryGPIO.h"
unsigned const int coluna[4]={16,12,25,24};//CONTROLA AS COLUNAS DAS LAMPADAS
unsigned const int linha[3]={17,27,22};//LÂMPADAS DA COR "AZUL"
int main(void){
	for(int cont =0;cont < 3; cont++){
		GPIOExport(linha[cont]);
		GPIODirection(linha[cont],SAIDA);
	}
	for(int cont =0;cont < 4; cont++){
		GPIOExport(coluna[cont]);
		GPIODirection(coluna[cont],SAIDA);
	}
	while(1){
		for(int cont = 0 ; cont < 4 ; cont++){
			for(int cont1 = 0 ; cont1 < 3;cont1++){
				GPIOWrite(coluna[cont],HIGH);
				GPIOWrite(linha[cont1],HIGH);
				delay_s(1);
				GPIOWrite(linha[cont1],LOW);
			}
				GPIOWrite(coluna[cont],LOW);
		}
	}
}

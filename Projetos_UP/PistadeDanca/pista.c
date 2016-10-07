#include"RaspberryGPIO.h"
#include<time.h>
/*Objetivo:	Desenvolver um software para controlar uma matriz de botões 3X4, e Duas matrizes de lâmpadas 3X4... As matrizes de controle são separadas

				ASCII Art Raspberry Pi 2 B2 GPIO
			              	  PINOS
					   +3V3 [01] [02] +5V
			 SDA1 / GPIO  2 [03] [04] +5V
			 SCL1 / GPIO  3 [05] [06] GND
   				    GPIO  4 [07] [08] GPIO 14 / TXD0
   			            GND [09] [10] GPIO 15 / RXD0
   				    GPIO 17 [11] [12] GPIO 18
					GPIO 27 [13] [14] GND
					GPIO 22 [15] [16] GPIO 23
					   +3V3 [17] [18] GPIO 24
		     MOSI / GPIO 10 [19] [20] GND
		     MISO / GPIO  9 [21] [22] GPIO 25
 			 SCLK / GPIO 11 [23] [24] GPIO  8 / CE0#
					    GND [25] [26] GPIO  7 / CE1#
			ID_SD / GPIO  0 [27] [28] GPIO  1 / ID_SC
					GPIO  5 [29] [30] GND
					GPIO  6 [31] [32] GPIO 12
					GPIO 13 [33] [34] GND
	 		 MISO / GPIO 19 [35] [36] GPIO 16 / CE2#
					GPIO 26 [37] [38] GPIO 20 / MOSI
		    			GND [39] [40] GPIO 21 / SCLK
*/
unsigned const int colBot[4]={5,6,13,19};//CONTROLA AS COLUNAS DOS BOTÕES
unsigned const int linBot[3]={26,21,20};//CONTROLA AS LINHAS DOS BOTÕES
unsigned const int colLamp[4]={16,12,25,24};//CONTROLA AS COLUNAS DAS LAMPADAS
unsigned const int linLampA[3]={17,27,22};//LÂMPADAS DA COR "AZUL"
unsigned const int linLampB[3]={14,15,18};// LÂMPADAS DA COR "VERMELHA"
double tempoStandby=0;
clock_t tempoInicial=0;
int acendeLampadas(unsigned const int linha,unsigned const int coluna);
int main(void){
	tempoInicial = clock();
	time_t t;
	srand((unsigned) time(&t));
	for(int cont = 0 ; cont < 4 ;cont++){
		GPIOExport(colBot[cont]);
		GPIODirection(colBot[cont],SAIDA);
		GPIOExport(colLamp[cont]);
		GPIODirection(colLamp[cont],SAIDA);
	}
	for(int cont = 0 ; cont < 3; cont++){
		GPIOExport(linBot[cont]);
		GPIODirection(linBot[cont],ENTRADA);
		GPIOExport(linLampA[cont]);
		GPIODirection(linLampA[cont],SAIDA);
		GPIOExport(linLampB[cont]);
		GPIODirection(linLampB[cont],SAIDA);
	}
	while(1){
		while(tempoStandby < 600.00){//10 minutos
			tempoStandby = (double)((clock()-tempoInicial)/CLOCKS_PER_SEC);
			for(int cont = 0 ;cont< 4;cont++){
				for(int cont1=0 ; cont1<3;cont1++){
					GPIOWrite(colBot[cont],HIGH);
					if(GPIORead(linBot[cont1]) == HIGH){
						printf("A lampada de linha %d e coluna %d e da cor: %d AZUL[1] ou VERMELHA[2] acendeu !\n",cont1,cont,acendeLampadas(cont1,cont));
					while(GPIORead(linBot[cont1]) == HIGH){}	
						acendeLampadas(cont1,cont);
					}
					GPIOWrite(colBot[cont],LOW);
					GPIOWrite(linLampA[cont1],LOW);
					GPIOWrite(linLampB[cont1],LOW);
					GPIOWrite(colLamp[cont],LOW);

				}
			}
		}
		acendeLampadas(((unsigned int)0+rand()%2),((unsigned int)0+rand()%3));
		tempoInicial = clock();
		delay_s(1);
		for(int cont=0;cont<3;cont++)	GPIOWrite(linLampA[cont],LOW);
		for(int cont=0;cont<4;cont++) GPIOWrite(colLamp[cont],LOW);
	}
}
int acendeLampadas(unsigned const int linha,unsigned const int coluna){
	int randon=0;
	randon = 1+rand()%2;
	switch(randon){
	case 1:
		GPIOWrite(linLampA[linha],HIGH);
		GPIOWrite(colLamp[coluna],HIGH);
		return 1;
		break;
	case 2:
		GPIOWrite(linLampB[linha],HIGH);
		GPIOWrite(colLamp[coluna],HIGH);
		return 2;
		break;
	default:
		return 0;
	}
}

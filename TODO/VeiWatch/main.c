/*
				ASCII Art Raspberry Pi 1 GPIO
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
 			 SCLK / GPIO 11 [23] [24] GPIO  8 / CE0#	CE_NOKIA
					    GND [25] [26] GPIO  7 / CE1#	RST_NOKIA
*/
#include<stdio.h>
#include"wiringSerial.h"
#include"RaspberryGPIO.h"
#include"PCD8544.h"
#include"HeartBeat.h"
#include"Logo.h"

#include"VeiWatch.h"

/*Display NOKIA*/
#define RST 7
#define CE 8
#define DC 25
#define DIN 24
#define CLK 23

/*Buttons*/
#define backLight	17
#define changeDisplay 27

struct Data{
	unsigned int BPM;
	float Temp;
}Sensors;

#define contrast 50
int lcdDisplaySensors(char *state_BPM, char *state_Temp){
	char Nokia_Temp[30],Nokia_BPM[30];
	snprintf(Nokia_Temp,30,"%.1f*C",Sensors.Temp);
	snprintf(Nokia_BPM,30,"%dBPM",Sensors.BPM);
	LCDclear();
	printf("Temp:%.1f\n",Sensors.Temp);
	printf("BPM:%d\n",Sensors.BPM);
	LCDdrawstring(20,0,"SENSORES");
	LCDdrawstring(25,10,Nokia_Temp);
	LCDdrawstring(20,20,state_Temp);
	LCDdrawstring(25,30,Nokia_BPM);
	LCDdrawstring(20,40,state_BPM);

	LCDdisplay();
}

const unsigned char SERIAL_PORT[2][30] = {"/dev/ttyAMA0","/dev/ttyUSB0"};

const unsigned int BAUDS[2] = {115200,9600};

int main(void){
	/*Iniciar o Display antes, para ficar mostrando o logo da Raspberry enquanto é feito o cadastro */
	/*E utilizar a Biblioteca PCD8544 ao inves de RPiNOKIA*/
	/*system("clear");
	printf("Deseja Sobrescrever os Dados ? S/N\n");
	int choose;
	do{choose = (int)getchar();}while(choose != 115 && choose != 83 && choose != 110 && choose != 78);
	if(choose == 115 || choose == 83){
		printf("Cadastro:\n");getchar();
		//cadastro();
	}else{
		printf("Inicia Programa!\n");getchar();
		system("clear");
	}*/
	int raspDuino = serialOpen(SERIAL_PORT[1],BAUDS[1]);
	if(raspDuino == -1){
		printf("Houve um erro ao Abrir a porta Serial!\n");
		return -1;
	}
	LCDInit(CLK, DIN, DC, CE,RST, contrast);
	struct sGENERAL person;
	if(healthInit(0,1,&person)==false)	printf("No data in BPM!\n");
	serialFlush(raspDuino);
	while(1){
		
		if(serialDataAvail(raspDuino)!=-1){
			Sensors.BPM = (unsigned int)serialGetchar(raspDuino);
			Sensors.Temp = ((float)serialGetchar(raspDuino)*5/(1023))/0.01;
			//displaySensors(lcd_NOKIA);
			lcdDisplaySensors(healthState(person,Sensors.BPM),isNormal(Sensors.Temp));
		}
	}
}

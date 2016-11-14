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

#include"SystemClock.h"
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
/*Output GPIO*/
#define BL 18

#define contrast 50

struct Data{
	unsigned int BPM;
	float Temp;
	char *BPMState,*TempState;	
}Sensors;


void lcdDisplayMain(unsigned int display,unsigned int fd){
	
	//while(GPIORead(changeDisplay)!=HIGH){
		char	Nokia_Temp[10],Nokia_BPM[10],INFO[15]={0,};
	
		Sensors.BPM = (unsigned int)serialGetchar(fd);
		Sensors.Temp = ((float)serialGetchar(fd)*5/(1023))/0.01;			
	
		snprintf(Nokia_Temp,10,"%.1f*C",Sensors.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",Sensors.BPM);	
	
		NOKIAClear(display);
		getClockInformation(&info);
	
		printf("Data:%s\n",info.date);
		printf("Hora:%s\n",info.time);
		printf("Temp:%.1f\n",Sensors.Temp);
		printf("BPM:%d\n",Sensors.BPM);

		NOKIAString(display,0,0,"PRINCIPAL");
		NOKIAString(display,1,0,Nokia_Temp);
		NOKIAString(display,1,50,Nokia_BPM);
		NOKIAString(display,2,0,info.date);
		NOKIAString(display,2,50,info.time);
	
//		LCDdrawline(0, 35, 83, 35, BLACK);
		// informações
//		LCDdisplay();
	//}
}

void lcdDisplayProfile(struct sGENERAL perfil){
	//while(GPIORead(changeDisplay)!=HIGH){		
		char	Nokia_Nome[25],Nokia_Genero[10],Nokia_Idade[10];
		unsigned int idade = perfil.Age;

		snprintf(Nokia_Nome,25,"Nome:%s",perfil.Name);
		snprintf(Nokia_Genero,10,"Genero:%s",perfil.Sex);
		snprintf(Nokia_Idade,10,"Idade:%d",perfil.Age); 
	
		LCDclear();

		LCDdrawstring(25,0,"PERFIL");
		LCDdrawline(0, 9, 83, 9, BLACK);
		LCDdrawstring(0,11,Nokia_Nome);
		LCDdrawstring(0,29,Nokia_Genero);
		LCDdrawstring(0,39,Nokia_Idade);
	
		LCDdisplay();
	//}
}	

void lcdDisplaySensors(unsigned int fd,struct sGENERAL patient){

	//while(GPIORead(changeDisplay)!=HIGH){
		char Nokia_Temp[10],Nokia_BPM[10];	
	
		Sensors.BPM = (unsigned int)serialGetchar(fd);
		Sensors.Temp = ((float)serialGetchar(fd)*5/(1023))/0.01;			
		Sensors.BPMState = healthState(patient,Sensors.BPM);
		Sensors.TempState = isNormal(Sensors.Temp);
	
		snprintf(Nokia_Temp,10,"%.1f*C",Sensors.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",Sensors.BPM);	
	
		LCDclear();

		printf("Temp:%.1f\n",Sensors.Temp);
		printf("BPM:%d\n",Sensors.BPM);
		LCDdrawstring(20,0,"SENSORES");
		LCDdrawstring(25,10,Nokia_Temp);
		LCDdrawstring(20,20,Sensors.TempState);
		LCDdrawstring(25,30,Nokia_BPM);
		LCDdrawstring(20,40,Sensors.BPMState);
	
		LCDdisplay();
	//}
}	

int main(void){

	LCDInit(CLK, DIN, DC, CE,RST, contrast);

  	LCDclear();
	LCDshowLogo();
	struct sGENERAL person;
	delay_ms(1000);

	system("clear");
	printf("Deseja Sobrescrever os Dados ? S/N\n");
	unsigned int choose;
	do{choose = (int)getchar();}while(choose != 115 && choose != 83 && choose != 110 && choose != 78);
	getchar();
	if(choose == 115 || choose == 83){
		LCDDrawBitmap(profile);
		if(healthProfile(&person) == false){
			printf("Falha ao realizar o Cadastro!\n");
			return -1;
		}
	}else{
		system("clear");
		LCDDrawBitmap(profile);
		if(importData(&person)==false){
			printf("Falha ao importar dados!\n");
			return -1;
		}
	}
	LCDDrawBitmap(sensors);
	int raspDuino = serialOpen(SERIAL_PORT[1],BAUDS[1]);
	if(raspDuino == -1){
		printf("Houve um erro ao Abrir a porta Serial!\n");
		return -1;
	}

	serialFlush(raspDuino);
	
	GPIOExport(changeDisplay);	GPIODirection(changeDisplay,INPUT);
	GPIOExport(backLight);		GPIODirection(backLight,INPUT);
	GPIOExport(BL);				GPIODirection(BL,OUTPUT);
	GPIOWrite(BL,HIGH);

	uint8_t change_Layer = 0;

	while(1){
		if(GPIORead(changeDisplay) == HIGH){
			while(GPIORead(changeDisplay) == HIGH){}
			change_Layer++;
			if(change_Layer > 2)	change_Layer = 0;
		}
		if(GPIORead(backLight) == HIGH){
			while(GPIORead(backLight) == HIGH){}
			GPIOWrite(BL,!GPIORead(BL));
		}
		switch(change_Layer){
			case 0:
				lcdDisplayMain(raspDuino);
				break;
			case 1:
				lcdDisplayProfile(person);
				break;
			case 2:
				lcdDisplaySensors(raspDuino,person);
				break;
		}
		/*if(serialDataAvail(raspDuino)!=-1){ // Usar Threads 
			Sensors.BPM = (unsigned int)serialGetchar(raspDuino);
			Sensors.Temp = ((float)serialGetchar(raspDuino)*5/(1023))/0.01;
			
			Sensors.BPMState = healthState(person,Sensors.BPM);
			Sensors.TempState = isNormal(Sensors.Temp);
		}*/
	}
}

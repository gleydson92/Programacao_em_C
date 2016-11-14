#include"RaspberryGPIO.h"
#include<stdint.h>
#include"RPiNOKIA.h"
#include"HeartBeat.h"
#include"Logo.h"
#include"wiringSerial.h"
#include"SystemClock.h"
#include"VeiWatch.h"

#define RST 7
#define CE 	8
#define DC 	25
#define DIN 24
#define CLK 23

#define backLight		17
#define changeDisplay	27
/*Output GPIO*/
#define BL 18

typedef struct{
	uint8_t BPM;
	uint8_t lastMinute,lastBPM;	//Armazena os últimos estados
	uint8_t mViewed,pViewed,sViewed; // Armazena estado da Tela: Se está vista[1], se não [0]
	uint8_t mWatching,pWatching,sWatching;
	float Temp;
	char *BPMState,*TempState;
}Vei_Data;

uint8_t change_Layer = 0;

Vei_Data control;

void lcdDisplayMain(LCD display,unsigned int fd){

	char	Nokia_Temp[10],Nokia_BPM[10],INFO[15]={0,};
	
	control.BPM = (unsigned int)serialGetchar(fd);
	control.Temp = ((float)serialGetchar(fd)*5/(1023))/0.01;			
	
	getClockInformation(&info);
	if(change_Layer == 0 && control.mWatching == 0){
		control.mWatching = 1;
		control.lastMinute = info.minute;
		printf("1-)Tela Principal!\n");
		snprintf(Nokia_Temp,10,"%.1f*C",control.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",control.BPM);	
		control.lastMinute = info.minute;
		control.lastBPM = control.BPM;
		NOKIAClear(display);

		NOKIAString(display,0,0,"PRINCIPAL");
		NOKIAString(display,0,1,Nokia_Temp);
		NOKIAString(display,50,1,Nokia_BPM);
		NOKIAString(display,0,2,info.date);
		NOKIAString(display,50,2,info.time);
	}
	if(change_Layer == 0 && control.mWatching == 1 && (info.minute != control.lastMinute || control.BPM != control.lastBPM)){
		
		snprintf(Nokia_Temp,10,"%.1f*C",control.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",control.BPM);	
		NOKIAString(display,0,0,"PRINCIPAL");
		NOKIAString(display,0,1,Nokia_Temp);
		NOKIAString(display,50,1,Nokia_BPM);
		NOKIAString(display,0,2,info.date);
		NOKIAString(display,50,2,info.time);
	}
}
void lcdDisplayProfile(LCD display, struct sGENERAL perfil){

	char	Nokia_Nome[25],Nokia_Genero[10],Nokia_Idade[10];

	if(change_Layer ==1 && control.pWatching == 0){	
		
		control.pWatching = 1;
		printf("2-)Tela de Perfil!\n");
		snprintf(Nokia_Nome,25,"Nome:%s",perfil.Name);
		snprintf(Nokia_Genero,10,"Genero:%s",perfil.Sex);
		snprintf(Nokia_Idade,10,"Idade:%d",perfil.Age); 
		NOKIAClear(display);
		NOKIAString(display,25,0,"PERFIL");
		NOKIAString(display,0,1,Nokia_Nome);
		NOKIAString(display,0,3,Nokia_Genero);
		NOKIAString(display,0,4,Nokia_Idade);
	}
}	 

void lcdDisplaySensors(LCD display, unsigned int fd,struct sGENERAL patient){
	char Nokia_Temp[10],Nokia_BPM[10];
	control.BPM = (unsigned int)serialGetchar(fd);
	control.Temp = ((float)serialGetchar(fd)*5/(1023))/0.01;			
	control.BPMState = healthState(patient,control.BPM);
	control.TempState = isNormal(control.Temp);

	if(change_Layer == 2 && control.sWatching == 0){
		control.sWatching = 1;
		control.lastBPM = control.BPM;
		printf("3-)Tela de Sensores!\n");
		snprintf(Nokia_Temp,10,"%.1f*C",control.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",control.BPM);	
		NOKIAClear(display);
		NOKIAString(display,20,0,"SENSORES");
		NOKIAString(display,25,1,Nokia_Temp);
		NOKIAString(display,20,2,control.TempState);
		NOKIAString(display,25,3,Nokia_BPM);
		NOKIAString(display,20,4,control.BPMState);
	}

	if(change_Layer == 2 && control.sWatching == 1 && control.BPM != control.lastBPM){
		control.lastBPM = control.BPM;
		snprintf(Nokia_Temp,10,"%.1f*C",control.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",control.BPM);	
		NOKIAString(display,20,0,"SENSORES");
		NOKIAString(display,25,1,Nokia_Temp);
		NOKIAString(display,20,2,control.TempState);
		NOKIAString(display,25,3,Nokia_BPM);
		NOKIAString(display,20,4,control.BPMState);
	}
}	

int main(void){
	LCD	nokia= NOKIAInit(CE,RST,DC,DIN,CLK);

	NOKIABitmap(nokia,RPi);	delay_ms(1000);

	struct sGENERAL person;

	unsigned int raspDuino;

	GPIOExport(changeDisplay);	GPIODirection(changeDisplay,INPUT);
	GPIOExport(backLight);		GPIODirection(backLight,INPUT);
	GPIOExport(BL);				GPIODirection(BL,OUTPUT);
	GPIOWrite(BL,HIGH);

	control.Temp = 36.5;
	control.BPM = 75;

	while(1){
		if(GPIORead(changeDisplay) == HIGH){
			while(GPIORead(changeDisplay) == HIGH){}
			change_Layer++;
			if(change_Layer > 2)	change_Layer = 0;
		}
		if(GPIORead(backLight) == HIGH){
			while(GPIORead(backLight) == HIGH){}
			GPIOWrite(BL,!GPIORead(BL));
			printf("Luz [1]Acesa-[0]Apagada:%d\n",GPIORead(BL));
		}
		switch(change_Layer){
			case 0:
				NOKIABitmap(nokia,main_display);		delay_ms(1000);	
				control.pWatching = control.sWatching = 0;
				lcdDisplayMain(nokia,raspDuino);
				break;
			case 1:
				NOKIABitmap(nokia,profile);				delay_ms(1000);
				control.mWatching = control.sWatching = 0;
				lcdDisplayProfile(nokia, person);
				break;
			case 2:
				NOKIABitmap(nokia,sensors);				delay_ms(1000);
				control.mWatching = control.pWatching = 0;
				lcdDisplaySensors(nokia, raspDuino,person);
				break;
		}
	}	
}

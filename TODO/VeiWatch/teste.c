#include"RaspberryGPIO.h"
#include<stdint.h>
#include"RPiNOKIA.h"
#include"HeartBeat.h"
#include"Logo.h"
#include"wiringSerial.h"
#include"SystemClock.h"
#include"VeiWatch.h"

#define RST 7
#define CE 8
#define DC 25
#define DIN 24
#define CLK 23

#define backLight	17
#define changeDisplay 27
/*Output GPIO*/
#define BL 18

struct Data{
	unsigned int BPM;
	float Temp;
	char *BPMState,*TempState;	
}Sensors;

uint8_t change_Layer = 0, profileViewed = 0;
unsigned int displayMain = 0, displayProfile = 0,displaySensors=0;

void lcdDisplayMain(LCD display,unsigned int fd){

	static int lanstMinute = 0;
	char	Nokia_Temp[10],Nokia_BPM[10],INFO[15]={0,};
	
	//Sensors.BPM = (unsigned int)serialGetchar(fd);
	//Sensors.Temp = ((float)serialGetchar(fd)*5/(1023))/0.01;			
	
	getClockInformation(&info);

	if(change_Layer == 0 && minute!=lastMinute){
		
		printf("1-)Tela Principal!\n");
		snprintf(Nokia_Temp,10,"%.1f*C",Sensors.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",Sensors.BPM);	
		lastMinute = info.minute;
		NOKIAClear(display);
		NOKIAString(display,0,0,"PRINCIPAL");
		NOKIAString(display,0,1,Nokia_Temp);
		NOKIAString(display,50,1,Nokia_BPM);
		NOKIAString(display,0,2,info.date);
		NOKIAString(display,50,2,info.time);
	}
}
void lcdDisplayProfile(LCD display, struct sGENERAL perfil){

	char	Nokia_Nome[25],Nokia_Genero[10],Nokia_Idade[10];
	unsigned int idade = perfil.Age;

	if(change_Layer ==1 && profileViewed == 0){	

		printf("2-)Tela de Perfil!\n");
		snprintf(Nokia_Nome,25,"Nome:%s",perfil.Name);
		snprintf(Nokia_Genero,10,"Genero:%s",perfil.Sex);
		snprintf(Nokia_Idade,10,"Idade:%d",perfil.Age); 
	
		NOKIAClear(display);
		NOKIAString(display,25,0,"PERFIL");
		NOKIAString(display,0,1,Nokia_Nome);
		NOKIAString(display,0,3,Nokia_Genero);
		NOKIAString(display,0,4,Nokia_Idade);
		profileViewed = 1;
	}
}	

void lcdDisplaySensors(LCD display, unsigned int fd,struct sGENERAL patient){
	char Nokia_Temp[10],Nokia_BPM[10];
	//Sensors.BPM = (unsigned int)serialGetchar(fd);
	//Sensors.Temp = ((float)serialGetchar(fd)*5/(1023))/0.01;			
	//Sensors.BPMState = healthState(patient,Sensors.BPM);
	//Sensors.TempState = isNormal(Sensors.Temp);

	if(change_Layer == 2 && lastBPM != Sensor.BPM){

		printf("3-)Tela de Sensores!\n");
		static lastBPM = Sensors.BPM;
		snprintf(Nokia_Temp,10,"%.1f*C",Sensors.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",Sensors.BPM);	
		NOKIAClear(display);
		NOKIAString(display,20,0,"SENSORES");
		NOKIAString(display,25,1,Nokia_Temp);
		NOKIAString(display,20,2,Sensors.TempState);
		NOKIAString(display,25,3,Nokia_BPM);
		NOKIAString(display,20,4,Sensors.BPMState);
	}
}	

int main(void){
	LCD	nokia= NOKIAInit(CE,RST,DC,DIN,CLK);

	NOKIABitmap(nokia,RPi);	

	struct sGENERAL person;

	unsigned int raspDuino;

	GPIOExport(changeDisplay);	GPIODirection(changeDisplay,INPUT);
	GPIOExport(backLight);		GPIODirection(backLight,INPUT);
	GPIOExport(BL);				GPIODirection(BL,OUTPUT);
	GPIOWrite(BL,HIGH);

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
				//profileViewed=1;
				lcdDisplayMain(nokia,raspDuino);
				break;
			case 1:
				profileViewed=0;
				lcdDisplayProfile(nokia, person);
				break;
			case 2:
				//profileViewed=1;
				lcdDisplaySensors(nokia, raspDuino,person);
				break;
		}
	}	
}

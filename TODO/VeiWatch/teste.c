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

void lcdDisplayMain(LCD display,unsigned int fd){
	
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
void lcdDisplayProfile(LCD display, struct sGENERAL perfil){
	//while(GPIORead(changeDisplay)!=HIGH){		
		char	Nokia_Nome[25],Nokia_Genero[10],Nokia_Idade[10];
		unsigned int idade = perfil.Age;

		snprintf(Nokia_Nome,25,"Nome:%s",perfil.Name);
		snprintf(Nokia_Genero,10,"Genero:%s",perfil.Sex);
		snprintf(Nokia_Idade,10,"Idade:%d",perfil.Age); 
	
		NOKIAClear(display);

		NOKIAString(display,0,25,"PERFIL");
		//LCDdrawline(0, 9, 83, 9, BLACK);
		NOKIAString(display,1,0,Nokia_Nome);
		NOKIAString(display,3,0,Nokia_Genero);
		NOKIAString(display,4,0,Nokia_Idade);
	
	//}
}	

void lcdDisplaySensors(LCD display, unsigned int fd,struct sGENERAL patient){

	//while(GPIORead(changeDisplay)!=HIGH){
		char Nokia_Temp[10],Nokia_BPM[10];	
	
		Sensors.BPM = (unsigned int)serialGetchar(fd);
		Sensors.Temp = ((float)serialGetchar(fd)*5/(1023))/0.01;			
		Sensors.BPMState = healthState(patient,Sensors.BPM);
		Sensors.TempState = isNormal(Sensors.Temp);
	
		snprintf(Nokia_Temp,10,"%.1f*C",Sensors.Temp);
		snprintf(Nokia_BPM,10,"%dBPM",Sensors.BPM);	
	
		NOKIAClear(display);

		printf("Temp:%.1f\n",Sensors.Temp);
		printf("BPM:%d\n",Sensors.BPM);
		NOKIAString(display,0,20,"SENSORES");
		NOKIAString(display,1,25,Nokia_Temp);
		NOKIAString(display,2,20,Sensors.TempState);
		NOKIAString(display,3,25,Nokia_BPM);
		NOKIAString(display,4,20,Sensors.BPMState);
	
	//}
}	

int main(void){
	LCD	nokia= NOKIAInit(CE,RST,DC,DIN,CLK);
	NOKIABitmap(nokia,RPi);	

	struct sGENERAL person;

	unsigned int estado = LOW,raspDuino;

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
			printf("Luz [1]Acesa-[0]Apagada:%d\n",GPIORead(BL));
		}
		switch(change_Layer){
			case 0:
				lcdDisplayMain(nokia,raspDuino);
				printf("1-)Tela Principal!\n");
				break;
			case 1:
				lcdDisplayProfile(nokia, person);
				printf("2-)Tela de Perfil!\n");
				break;
			case 2:
				lcdDisplaySensors(nokia, raspDuino,person);
				printf("3-)Tela de Sensores!\n");
				break;
		}
	}	
}

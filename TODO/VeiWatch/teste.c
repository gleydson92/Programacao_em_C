#include"RaspberryGPIO.h"
#include<stdint.h>
#define backLight	17
#define changeDisplay 27
/*Output GPIO*/
#define BL 18

int main(void){
	unsigned int estado = LOW;
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
				//lcdDisplayMain(raspDuino);
				printf("1-)Tela Principal!\n");
				break;
			case 1:
				//lcdDisplayProfile(person);
				printf("2-)Tela de Perfil!\n");
				break;
			case 2:
				//lcdDisplaySensors(raspDuino,person);
				printf("3-)Tela de Sensores!\n");
				break;
		}
	}	
}

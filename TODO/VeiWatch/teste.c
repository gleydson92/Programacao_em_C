#include"HeartBeat.h"
#include"VeiWatch.h"
#include"PCD8544.h"
#include"SystemClock.h"
#include<string.h>
#include"wiringSerial.h"
#include<unistd.h>
const unsigned char SERIAL_PORT[2][30] = {"/dev/ttyAMA0","/dev/ttyUSB0"};

const unsigned int BAUDS[2] = {115200,9600};

struct Data{
	unsigned int BPM;
	float Temp;
	char *BPMState,*TempState;
}Sensors;

int main(void){
	//LCDInit(CLK, DIN, DC, CE,RST, contrast);
	struct sGENERAL person;
	system("clear");
	printf("Deseja Sobrescrever os Dados ? S/N\n");
	unsigned int choose;
	do{choose = (int)getchar();}while(choose != 115 && choose != 83 && choose != 110 && choose != 78);
	getchar();
	if(choose == 115 || choose == 83){
		//LCDDrawBitmap(profile);
		if(healthProfile(&person) == false){
			printf("Falha ao realizar o Cadastro!\n");
			return -1;
		}
	}else{
		system("clear");
		//LCDDrawBitmap(profile);
		if(importData(&person)==false){
			printf("Falha ao importar dados!\n");
			return -1;
		}
	}
	
	//healthProfile(&patient);
	healthInit(MALE,2,&person);
 
	Sensors.BPM = 90;
	Sensors.Temp = 37.8;
	Sensors.BPMState = healthState(person,Sensors.BPM);
	Sensors.TempState = isNormal(Sensors.Temp);

	printf("Nome:%s\n",person.Name);
	printf("Genero:%s\n",person.Sex);
	printf("Idade:%d\n",person.Age);
	/*int raspDuino = serialOpen(SERIAL_PORT[1],BAUDS[1]);
		if(raspDuino == -1){
			printf("Houve um erro ao Abrir a porta Serial!\n");
			return -1;
	}	
	serialFlush(raspDuino);
	while(1){
		char serialData[10];
		//if(serialDataAvail(raspDuino)!=-1){ // Usar Thre
		for(int cont = 0 ; cont < 10; cont++){
			serialData[cont] = serialGetchar(raspDuino);
		}
		printf("%s\n",serialData);
		for(int cont = 0 ;cont  < 10; cont++)
			serialData[cont] = '\0';
	}*/
}

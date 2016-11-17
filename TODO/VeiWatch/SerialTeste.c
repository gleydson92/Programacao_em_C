#include<string.h>
#include <sys/ioctl.h>
#include"wiringSerial.h"
#include<stdio.h>
#include<unistd.h>
#include"VeiWatch.h"
#include"HeartBeat.h"
const unsigned char SERIAL_PORT[2][30] = {"/dev/ttyAMA0","/dev/ttyUSB0"};

const unsigned int BAUDS[2] = {115200,9600};
Vei_Data control;

Vei_Data getData(unsigned int fd, struct sGENERAL perfil){
	Vei_Data receive;

	int result=0,bpm=0,temp=0;
	
	if(ioctl (fd, FIONREAD, &result) != -1){
		if(result>2){
			int temp=0,bpm=0;
			read(fd,&bpm,1);
			read(fd,&temp,1);
			if(bpm == 0 && temp == 0){
				strcpy(receive.BPMState,"Desconec.");
				strcpy(receive.TempState,"Desconec.");
				receive.Temp = temp;
				receive.BPM = bpm;		
				//printf("Estado Sensor BPM:%s\n",receive.BPMState);
				//printf("Estado Sensor Temp:%s\n",receive.TempState);
				//printf("BPM:%d\n",receive.BPM);
				//printf("Temp:%d\n",receive.Temp);
			}else{
				receive.Temp = ((float)temp*5/(1023))/0.01;
				receive.BPM = bpm;		
				receive.BPMState = healthState(perfil,bpm);
				receive.TempState = isNormal(temp);
				//printf("Estado Sensor BPM:%s\n",receive.BPMState);
				//printf("Estado Sensor Temp:%s\n",receive.TempState);
				//printf("BPM:%d\n",receive.BPM);
				//printf("Temp:%d\n",receive.Temp);
			}
		return receive;
		}
	}	
}

int main(void){
	int result=0;
	int raspDuino = serialOpen(SERIAL_PORT[1],BAUDS[1]);
	if(raspDuino == -1){
		printf("Houve um erro ao Abrir a porta Serial!\n");
		return -1;
	}
	struct sGENERAL person;
	importData(&person);
	
	serialFlush(raspDuino);
	while(1){	
		control = getData(raspDuino,person);
		printf("Estado Sensor BPM:%s\n",control.BPMState);
		printf("Estado Sensor Temp:%s\n",control.TempState);
		printf("BPM:%d\n",control.BPM);
		printf("Temp:%f\n",control.Temp);
		printf("Sem Dados!\n");
		usleep(1000*1000);
	}
	
}

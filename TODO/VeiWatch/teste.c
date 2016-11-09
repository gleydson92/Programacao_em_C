#include"HeartBeat.h"
#include"VeiWatch.h"
#include"PCD8544.h"
#include"SystemClock.h"
struct Data{
	unsigned int BPM;
	float Temp;
	char *BPMState,*TempState;
	
}Sensors;
#define RST 7
#define CE 8
#define DC 25
#define DIN 24
#define CLK 23
#define contrast 50 	
void lcdDisplayMain(){
	/* Inicialização do Relógio do Sistema	*/
	char	Nokia_Temp[10],Nokia_BPM[10];;	
	snprintf(Nokia_Temp,10,"%.1f*C",Sensors.Temp);
	snprintf(Nokia_BPM,10,"%dBPM",Sensors.BPM);	

	LCDclear();

	getClockInformation(&info);

	printf("Data:%s\n",info.date);
	printf("Hora:%s\n",info.time);
	printf("Temp:%.1f\n",Sensors.Temp);
	printf("BPM:%d\n",Sensors.BPM);

	LCDdrawstring(20,0,"PRINCIPAL");
	LCDdrawstring(0,10,Nokia_Temp);
	LCDdrawstring(25,10,Nokia_BPM);
	LCDdrawstring(0,23,info.date);
	LCDdrawstring(25,23,info.time);

	LCDdisplay();
}
int main(void){
	LCDInit(CLK, DIN, DC, CE,RST, contrast);
	struct sGENERAL patient;
	healthInit(MALE,2,&patient);
/*	printf("Excelente:%d\n",patient.Excellent);
	printf("%s\n",patient.Sex);
	unsigned int num = 1;
	char *string = healthState(patient,num);
	while(num!=0){
		scanf("%d",&num); 
		string = healthState(patient,num);
		printf("%s\n",string);
	}
*/
	Sensors.BPM = 90;
	Sensors.Temp = 37.8;
	Sensors.BPMState = healthState(patient,Sensors.BPM);
	Sensors.TempState = isNormal(Sensors.Temp);
	
//	printf("BPM:%s\n",Sensors.BPMState);
//	printf("Temp:%s\n",Sensors.TempState);
	lcdDisplayMain();
}

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
	char	data_sistema[100],hora_sistema[10], Nokia_Temp[10],Nokia_BPM[10];
	sprintf(data_sistema,"%s",data());
	sprintf(hora_sistema,"%s",hora());
	snprintf(Nokia_Temp,10,"%.1f*C",Sensors.Temp);
	snprintf(Nokia_BPM,10,"%dBPM",Sensors.BPM);	

	LCDclear();
	
	printf("Data:%s\n",data_sistema);
	printf("Hora:%s\n",hora_sistema);
	printf("Temp:%.1f\n",Sensors.Temp);
	printf("BPM:%d\n",Sensors.BPM);

	LCDdrawstring(20,0,"PRINCIPAL");
	LCDdrawline(0, 10, 83, 10, BLACK);
	LCDdrawstring(0,13,Nokia_Temp);
	LCDdrawstring(50,13,Nokia_BPM);
	LCDdrawstring(0,26,data_sistema);
	LCDdrawstring(50,26,hora_sistema);

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
	
	printf("BPM:%s\n",Sensors.BPMState);
	printf("Temp:%s\n",Sensors.TempState);
	lcdDisplayMain();
}

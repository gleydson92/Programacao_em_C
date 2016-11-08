#include"HeartBeat.h"
#include"VeiWatch.h"
struct Data{
	unsigned int BPM;
	float Temp;
	char *BPMState,*TempState;
	
}Sensors;

int main(void){
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
}

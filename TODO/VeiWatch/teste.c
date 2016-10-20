#include"HeartBeat.h"
int main(void){
	struct sGENERAL patient;
	healthInit(MALE,2,&patient);
	printf("Excelente:%d\n",patient.Excellent);
	printf("%s\n",patient.Sex);
	unsigned int num = 1;
	char *string = healthState(patient,num);
	while(num!=0){
		scanf("%d",&num); 
		string = healthState(patient,num);
		printf("%s\n",string);
	}
		
}

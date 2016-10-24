#include<stdio.h>

#define alpha 0.75

int pulse(int analogRead);

int main(void){
	const int vetor[25]={286,285,300,298,302,295,298,295,293,301,313,327,332,333,335,341,351,351,347,348,350,347,343,337,333};	
	for(unsigned register int Count = 0;Count <25;Count++){
		printf("BPM:%d\n",pulse(vetor[Count]));
		//printf("BPM:%d\n",(vetor[Count]/10)*2);
	}
}
int pulse(int analogRead){
	static double oldValue=0;
	double value = alpha*analogRead+(1-alpha)*oldValue;
	printf("Value:%f\n",value);
	oldValue = value;
	return (value/5);
}

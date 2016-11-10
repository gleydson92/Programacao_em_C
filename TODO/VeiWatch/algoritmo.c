#include<stdio.h>
#include<time.h>
#include<stdint.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/time.h>

void getPulse(uint8_t pin){
	unsigned int times[5],count=0;
	float average=0;
	while(count < 5)
		if(GPIORead(pin) == HIGH)
			times[count] = getTime_ms();
	average = average+(times[count]-times[count-1]);
}



static struct timeval tm1,tm2;

static inline void start()
{
    gettimeofday(&tm1, NULL);
}

static inline void stop()
{
//    struct timeval tm2;
    gettimeofday(&tm2, NULL);

    unsigned long long t = 1000 * (tm2.tv_sec - tm1.tv_sec) + (tm2.tv_usec - tm1.tv_usec) / 1000;
    printf("%llu ms\n", t);
}
unsigned long getTime_ms(void){
	struct timeval time;
	gettimeofday(&time,NULL);
	unsigned long long t = (1000*time.tv_sec)+(time.tv_usec/1000);
	//printf("%llu ms\n",t);
	return t;
}
int pulse(char *sex,unsigned int age);
uint8_t getPulse(void);
double getTime(void){
	clock_t start,end;
	double time;
	start = clock();
	usleep(1000000);
	end = clock();
	time = ((double)end-start)/CLOCKS_PER_SEC;
	return time;
}
int main(void){
	//Insira o Sexo;
	//	* Omi ou Muié
	//Insira a Faixa Etária;
	/*
		1-)	18-25
		2-)	26-35
		3-)	36-45
		4-)	46-55
		5-)	56-65
		6-)	65+
	*/
	/*Tabela para as Mulheres:
	+-----+-----------+-----------+-----+----------------+--------+----------------+-----+
	|Idade|	Excelente |	Muito bom |	Bom | Acima da média |	Média |	Abaixo da Média|Ruim |
	|18-25|	  54-60   |	  61-65	  |66-69|	  70-73	     | 74-78  |	    79-84	   | 85+ |
	|26-35|	  54-59	  |   60-64   |65-68|	  69-72      | 73-76  |     77-82	   | 83+ |
	|36-45|	  54-59	  |	  60-64	  |65-69| 	  70-73	     | 74-78  |		79-84      | 85+ |
	|46-55|	  54-60	  |   61-65   |66-69|	  70-73	     | 74-77  |		78-83	   | 84+ |
	|56-65|	  54-59	  |   60-64	  |65-68|	  69-73	     | 74-77  |		78-83	   | 84+ |
	|65+  |	  54-59	  |   60-64	  |65-68|	  69-72	     | 73-76  |		77-84	   | 84+ |
	+-----+-----------+-----------+-----+----------------+--------+----------------+-----+ */
	/*Tabela para os Homens:
	+-----+-----------+-----------+-------+----------------+-------+-----------------+--------+
	|Idade|	Excelente |	Muito bom |	 Bom  |	Acima da média | Média | Abaixo da média |	Ruim  |
	|18-25|	  49-55	  |	  56-61	  |	62-65 |		66-69	   | 70-73 |	  74-81		 |	 82+  |
	|26-35|	  49-54	  |	  55-61   |	62-65 |		66-70	   | 71-74 |	  75-81		 |	 82+  |	
	|36-45|	  50-56	  |	  57-62	  |	63-66 |		67-70	   | 71-75 |	  76-82		 |	 83+  |
	|46-55|	  50-57	  |	  58-63	  |	64-67 |		68-71	   | 72-76 |	  77-83		 |	 84+  |
	|56-65|	  51-56	  |	  57-61	  |	62-67 |		68-71	   | 72-75 |	  76-81		 |	 82+  |
	| 65+ |	  50-55	  |	  56-61	  |	62-65 |		66-69	   | 70-73 |	  74-79		 |	 80+  |
	+-----+-----------+-----------+-------+----------------+-------+-----------------+--------+

	*/
	//unsigned long long t1,t2;
	int t1,t2;
	t1 = getTime_ms();
	
	//start();
	usleep(2000000);
	stop();
	t2 = getTime_ms();
	printf("%llu ms ",t2-t1);
}
uint8_t getPulse(void){
	return 67;
}
int pulse(char *sex,unsigned int age){
	uint8_t pulse = 0;
	pulse = getPulse();
	if(sex == "woman"){
		if(age==1){
			
		}
		else if(age == 2){

		}
		else if(age == 3){

		}
		else if(age == 4){

		}
		else if(age == 5){

		}
		else if(age == 6){

		}
	}
	else if(sex == "man"){
		if(age==1){
			
		}
		else if(age == 2){

		}
		else if(age == 3){

		}
		else if(age == 4){

		}
		else if(age == 5){

		}
		else if(age == 6){

		}
	}
	else return 0;
}

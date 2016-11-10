#include"HeartBeat.h"
#include"VeiWatch.h"
#include"PCD8544.h"
#include"SystemClock.h"
#include<string.h>
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
void lcdDisplayProfile(struct sGENERAL perfil){
	char	Nokia_Nome[25],Nokia_Genero[10],Nokia_Idade[10];
	unsigned int idade = perfil.Age;
	snprintf(Nokia_Nome,25,"Nome:%s",perfil.Name);
	snprintf(Nokia_Genero,10,"Genero:%s",perfil.Sex);
	snprintf(Nokia_Idade,10,"Idade:%d",perfil.Age); 

	LCDclear();
	LCDdisplay();
	getClockInformation(&info);


	LCDdrawstring(25,0,"PERFIL");
	LCDdrawline(0, 9, 83, 9, BLACK);
	LCDdrawstring(0,11,Nokia_Nome);
	LCDdrawstring(0,29,Nokia_Genero);
	LCDdrawstring(0,39,Nokia_Idade);
	
	//LCDdrawline(0, 41, 83, 41, BLACK);

	LCDdisplay();
}
int main(void){
	LCDInit(CLK, DIN, DC, CE,RST, contrast);
	struct sGENERAL patient;
	healthProfile(&patient);
	healthInit(MALE,2,&patient);
 
	Sensors.BPM = 90;
	Sensors.Temp = 37.8;
	Sensors.BPMState = healthState(patient,Sensors.BPM);
	Sensors.TempState = isNormal(Sensors.Temp);
	
	lcdDisplayProfile(patient);
}

#include"VeiWatch.h"

char Temp_Report[4][15]={"Hypothermia","Normal","Fever","Hyperpyrexia"};

char *isNormal(float Temp){
	while(Temp < 35.0)	return Temp_Report[0];
	while(Temp > 36.2 && Temp < 37.6)	return Temp_Report[1];
	while(Temp > 37.6 && Temp < 38.3)	return Temp_Report[2];
	while(Temp > 40.0)	return Temp_Report[3];
}


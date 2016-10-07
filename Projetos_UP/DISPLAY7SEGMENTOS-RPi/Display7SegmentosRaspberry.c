#include"RaspberryGPIO.h"
/************************************************************************************
	ASCII Art Display 7 Segmentos		ASCII Art Raspberry Pi 2 B2
							  				  GPIO

		  g f gnd a b		              	  PINOS
		 _|_|__|__|_|_				   +3V3 [01] [02] +5V
		|	      	  |		 SDA1 / GPIO  2 [03] [04] +5V
		| _____a_____ |		 SCL1 / GPIO  3 [05] [06] GND
		||	     	 ||	   	        GPIO  4 [07] [08] GPIO 14 / TXD0
		||	         ||	                GND [09] [10] GPIO 15 / RXD0
		|f	         b|		        GPIO 17 [11] [12] GPIO 18
		||	         ||				GPIO 27 [13] [14] GND
		| _____g_____ |				GPIO 22 [15] [16] GPIO 23
		||	         ||				   +3V3 [17] [18] GPIO 24
		||	         ||	     MOSI / GPIO 10 [19] [20] GND
		|e	         c|	     MISO / GPIO  9 [21] [22] GPIO 25
		||	         ||      SCLK / GPIO 11 [23] [24] GPIO  8 / CE0#
		| _____d_____ |				    GND [25] [26] GPIO  7 / CE1#
		|         DP* |		ID_SD / GPIO  0 [27] [28] GPIO  1 / ID_SC
		|_____________|				GPIO  5 [29] [30] GND
		  | |  |  | |				GPIO  6 [31] [32] GPIO 12
		  e d gnd c DP				GPIO 13 [33] [34] GND
					 		 MISO / GPIO 19 [35] [36] GPIO 16 / CE2#
									GPIO 26 [37] [38] GPIO 20 / MOSI
						    			GND [39] [40] GPIO 21 / SCLK

***************************************************************************************/
int a = 5,b = 6,c=13,d=19,e=26,f=21,g=20,transistor1=25,transistor2=12;
const float tempo = 20000;//50Hz
int display(int numero){
	switch(numero){
	case 0:
		GPIOWrite(a,HIGH);
		GPIOWrite(b,HIGH);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,HIGH);
		GPIOWrite(e,HIGH);
		GPIOWrite(f,HIGH);
		GPIOWrite(g,LOW);
		return 1;
		break;
	case 1:
		GPIOWrite(a,LOW);
		GPIOWrite(b,HIGH);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,LOW);
		GPIOWrite(e,LOW);
		GPIOWrite(f,LOW);
		GPIOWrite(g,LOW);
		return 1;
		break;
	case 2:
		GPIOWrite(a,HIGH);
		GPIOWrite(b,HIGH);
		GPIOWrite(c,LOW);
		GPIOWrite(d,HIGH);
		GPIOWrite(e,HIGH);
		GPIOWrite(f,LOW);
		GPIOWrite(g,HIGH);
		return 1;
		break;
	case 3:
		GPIOWrite(a,HIGH);
		GPIOWrite(b,HIGH);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,HIGH);
		GPIOWrite(e,LOW);
		GPIOWrite(f,LOW);
		GPIOWrite(g,HIGH);
		return 1;
		break;
	case 4:
		GPIOWrite(a,LOW);
		GPIOWrite(b,HIGH);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,LOW);
		GPIOWrite(e,LOW);
		GPIOWrite(f,HIGH);
		GPIOWrite(g,HIGH);
		return 1;
		break;
	case 5:
		GPIOWrite(a,HIGH);
		GPIOWrite(b,LOW);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,HIGH);
		GPIOWrite(e,LOW);
		GPIOWrite(f,HIGH);
		GPIOWrite(g,HIGH);
		return 1;
		break;
	case 6:
		GPIOWrite(a,HIGH);
		GPIOWrite(b,LOW);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,HIGH);
		GPIOWrite(e,HIGH);
		GPIOWrite(f,HIGH);
		GPIOWrite(g,HIGH);
		return 1;
		break;
	case 7:
		GPIOWrite(a,HIGH);
		GPIOWrite(b,HIGH);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,LOW);
		GPIOWrite(e,LOW);
		GPIOWrite(f,LOW);
		GPIOWrite(g,LOW);
		return 1;
		break;

	case 8:
		GPIOWrite(a,HIGH);
		GPIOWrite(b,HIGH);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,HIGH);
		GPIOWrite(e,HIGH);
		GPIOWrite(f,HIGH);
		GPIOWrite(g,HIGH);
		return 1;
		break;

	case 9:
		GPIOWrite(a,HIGH);
		GPIOWrite(b,HIGH);
		GPIOWrite(c,HIGH);
		GPIOWrite(d,LOW);
		GPIOWrite(e,LOW);
		GPIOWrite(f,HIGH);
		GPIOWrite(g,HIGH);
		return 1;
		break;
	default:
		return 0;
	}
}
int convert(int num, int *dezl ,int *unil){
	float aux,cte = 0.0100001191;
	(*dezl) = num / 10;
	aux = (float)num / 10;
	aux = aux - (*dezl);
	aux = aux + cte;
	(*unil) = aux * 10;
}
int main (){
	int selec = 0;
	do{
		printf("\nDeseja Iniciar o Programa ? S[1]/N[2]\t");
		scanf("%d",&selec);
		if(selec == 1)	break;
		else{
			if(GPIOUnexport(a) == 1 && GPIOUnexport(b) == 1 && GPIOUnexport(c) == 1 && GPIOUnexport(d) == 1 && GPIOUnexport(e) == 1 && GPIOUnexport(f) == 1 && GPIOUnexport(g) == 1 && GPIOUnexport(transistor1) == 1 && GPIOUnexport(transistor2) == 1){
				printf("Programa Encerrado com Sucesso! \n"); getchar();
				return 0;
			}else{
				printf("\n\tHouve Erros ao encerrar o programa!\n\tVerifique os Terminais GPIO!\n");
				return 0;
			}
		}
	}while(selec > 0 && selec < 3);
	GPIOExport(a);
	GPIOExport(b);
	GPIOExport(c);
	GPIOExport(d);
	GPIOExport(e);
	GPIOExport(f);
	GPIOExport(g);
	GPIOExport(transistor1);
	GPIOExport(transistor2);
	GPIODirection(a,OUTPUT);
	GPIODirection(b,OUTPUT);
	GPIODirection(c,OUTPUT);
	GPIODirection(d,OUTPUT);
	GPIODirection(e,OUTPUT);
	GPIODirection(f,OUTPUT);
	GPIODirection(g,OUTPUT);
	GPIODirection(transistor1,OUTPUT);
	GPIODirection(transistor2,OUTPUT);
	int dez,uni,num,cont = 0, cont2 =0;
	while(1){
	do{system("clear");
	printf("Insira um número para a Contagem decrescente!\n");
	scanf("%d",&num);
	}while (num < 0 || num > 59);
	if(num>9){
		for(cont = num; cont>=0 ; cont--){
			for(cont2 = 0; cont2 < 25; cont2++){
				 convert(cont,&dez,&uni);
				 GPIOWrite(transistor2, HIGH);
				 display(dez);
				 usleep(tempo);
				 GPIOWrite(transistor2,LOW);
				 GPIOWrite(transistor1,HIGH);
				 display(uni);
				 usleep(tempo);
				 GPIOWrite(transistor1, LOW);
			}
		}
	}
	else{
		for(cont = num ;cont>=0;cont --){
			GPIOWrite(transistor1,HIGH);
			display(cont);
			usleep(1000000);
		}
	}
}
}

#include"RaspberryGPIO.h"
/************************************************************************************
	ASCII Art Display 7 Segmentos		ASCII Art CD4511


		  g f gnd a b			              	 	
		 _|_|__|__|_|_				 +---\/---+  
		|	      	  |		  In-A1	_|1     16|_VDD
		| _____a_____ |		  In-A2	_|2  C  15|_Segmento-f
		||	     	 ||	   	     LT	_|3  D  14|_Segmento-g
		||	     	 ||	         BL _|4  4  13|_Segmento-a
		|f	         b|		     LE	_|5  5  12|_Segmento-b
		||	     	 ||		  In-A3	_|6  1  11|_Segmento-c
		| _____g_____ |		  In-A0	_|7  1  10|_Segmento-d
		||	     	 ||		    VSS	_|8     09|_Segmento-e
		||	      	 ||	        	 +--------+
		|e	     	 c|	       
		||	     	 ||         
		| _____d_____ |		
		|         DP* |	
		|_____________|		
		  | |  |  | |			
		  e d gnd c DP		
					 
					
					

***************************************************************************************/
int a = 5,b = 6,c=13,d=19,e=26,f=21,g=20,h=25;
void binary(int decimal1,int binario1[]);
int main(void){
	int selec = 0;
	do{
		printf("\nDeseja Iniciar o Programa ? S[1]/N[2]\t");
		scanf("%d",&selec);
		if(selec == 1)	break;
		else{
			if(GPIOUnexport(a) == 1 && GPIOUnexport(b) == 1 && GPIOUnexport(c) == 1 && GPIOUnexport(d) == 1 && GPIOUnexport(e) == 1 && GPIOUnexport(f) == 1 && GPIOUnexport(g) == 1 && GPIOUnexport(h) == 1){
				printf("Programa Encerrado com Sucesso! \n"); getchar();
				return 0;
			}else{
				printf("\n\tHouve Erros ao encerrar o programa!\n\tVerifique os Terminais GPIO!\n");
				return 0;
			}
	}
	}while(selec > 0 && selec < 3);	
	int decimal = 0,binario[8];
	while(1){
	int num = 0;
	do{system("clear");
	printf("Insira um número para a Contagem decrescente!\n");
	scanf("%d",&num);
	}while (num < 0 || num > 59);
	for(int cont = num ; cont >= 0 ; cont --){
		binary(cont,binario);
		GPIOWrite(a,binario[0]);
		GPIOWrite(b,binario[1]);
		GPIOWrite(c,binario[2]);
		GPIOWrite(d,binario[3]);
		GPIOWrite(e,binario[4]);
		GPIOWrite(f,binario[5]);
		GPIOWrite(g,binario[6]);
		GPIOWrite(h,binario[7]);
		usleep(1000000);
	}
}
}
void binary(int decimal1,int binario1[]){
	for(int cont1 = 0; cont1<8;cont1++)
		binario1[cont1]=0;
	int cont = 0,resto=0;
	while(decimal1!=0){
	resto = decimal1%2;
	binario1[cont] = resto == 0? 0:1;
	decimal1 = decimal1/2;
	cont++;
	}
}

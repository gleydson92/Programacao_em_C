#include"RaspberryGPIO.h"
int main()
{
	int botao[3] = {5,6,13};
	int matriz[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	int selec = 0;
	do{
		printf("\nDeseja Iniciar o Programa ? S[1]/N[2]\t");
		scanf("%d",&selec);
		if(selec == 1)	break;
		else{
			if(GPIOUnexport(5) == 1 && GPIOUnexport(6) == 1 && GPIOUnexport(13) == 1){
				printf("Programa Encerrado com Sucesso! \n"); getchar();
				return 0;
			}else{
				printf("\n\tHouve Erros ao encerrar o programa!\n\tVerifique os Terminais GPIO!\n");
				return 0;
			}
		}
	}while(selec > 0 && selec < 3);
	for(int count = 0; count < 3 ; count ++)
	{
		GPIOExport(botao[count]);
		GPIODirection(botao[count],ENTRADA);
	}
	int countL = 0,countC=0;
	while(1)
	{
		int selecL = 0;
		printf("Digite a Linha para Verificar o Botão!\n");
		do{
		scanf("%d",&selecL);
		}while(selecL>=0 && selecL<3);
		if(selecL == 0){
			matriz[selecL][0] = (int)GPIORead(botao[0]);
			matriz[selecL][1] = (int)GPIORead(botao[1]);
			matriz[selecL][2] = (int)GPIORead(botao[2]);
			if(matriz[countL][0] == 1)	printf("Botão 'A' pressionado!\n");
			if(matriz[countL][1] == 1)	printf("Botão 'B' pressionado!\n");
			if(matriz[countL][2] == 1)	printf("Botão 'C' pressionado!\n");
		}
		else if(selecL == 1){
			matriz[selecL][0] = (int)GPIORead(botao[0]);
			matriz[selecL][1] = (int)GPIORead(botao[1]);
			matriz[selecL][2] = (int)GPIORead(botao[2]);
			if(matriz[countL][0] == 1)	printf("Botão 'D' pressionado!\n");
			if(matriz[countL][1] == 1)	printf("Botão 'E' pressionado!\n");
			if(matriz[countL][2] == 1)	printf("Botão 'F' pressionado!\n");
		}
		else if(selecL == 2){
			matriz[selecL][0] = (int)GPIORead(botao[0]);
			matriz[selecL][1] = (int)GPIORead(botao[1]);
			matriz[selecL][2] = (int)GPIORead(botao[2]);
			if(matriz[countL][0] == 1)	printf("Botão 'G' pressionado!\n");
			if(matriz[countL][1] == 1)	printf("Botão 'H' pressionado!\n");
			if(matriz[countL][2] == 1)	printf("Botão 'I' pressionado!\n");
		}
	}
}

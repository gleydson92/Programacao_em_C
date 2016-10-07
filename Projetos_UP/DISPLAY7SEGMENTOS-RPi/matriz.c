#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int matriz[2][8],terminal=0;
	time_t t;
	srand((unsigned) time(&t));
	for(int cont=0;cont<8;cont++)
		matriz[0][cont]=cont+1;
	for(int cont1=0;cont1<8;cont1++)
		matriz[1][cont1] = rand();
	for(int cont=0;cont<2;cont++)
	{
		for(int cont1=0;cont1<8;cont1++)
			printf("%d,",matriz[cont][cont1]);
		printf("\n");
	}
	printf("Insira o terminal que você quer saber o valor contido nele(1-8)\n");
	scanf("%d",&terminal);
	printf("%d",matriz[1][terminal-1]);
}

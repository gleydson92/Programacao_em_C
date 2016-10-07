#include<stdio.h>

int main(void)
{
	int decimal = 0,binario[4],resto=0;
	printf("Insira um numero decimal:\n");
	scanf("%d",&decimal);
	int cont = 0;
	for(int cont = 0; cont<4;cont++)
		binario[cont]=0;
	while(decimal!=0)
	{
		resto = decimal%2;
		binario[cont] = resto == 0? 0:1;
		decimal = decimal/2;
		cont++;
	}
	printf("\n");
	for(int cont = 3 ; cont>=0;cont--)
		printf("%d",binario[cont]);
}

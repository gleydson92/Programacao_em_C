#include<stdio.h>
int main(void){
	for (int cont=0;cont<9;cont++){
		int valor = 0;
		valor|=(1UL<<(cont));
		printf("Valor com: (value) |= (1UL << (bit)) %d\n",valor);
	}
	printf("\n\n");
	for(int cont = 0;cont<9;cont++)			printf("Valor com: (value) = (1UL << (bit)) %d\n",(1UL<<cont));
}

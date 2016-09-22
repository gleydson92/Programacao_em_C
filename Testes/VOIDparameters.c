#include<stdio.h>
int teste(void *Argumentos){
	int *num = (int*)Argumentos;
	printf("Teste!\n");
	printf("Imprima os Argumentos %d!\n",*num);
}
int main(void){
	int numero = 6;
	teste((void*)&numero);
	teste();
}

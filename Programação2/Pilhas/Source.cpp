#include "Pilha.h"
#include <stdio.h>
#include <malloc.h>
int main(){
	Pilha myStack;
	int *estado_atual;
	unsigned int qtde;
	iniciar(7, &myStack);
	push(53, &myStack);
	push(77, &myStack);
	push(65, &myStack);
	estado_atual = listar(myStack, &qtde);
	for (int i = 0; i < qtde; i++)
		printf("%d-", estado_atual[i]);
	printf("\nRemovendo 1 elemento\n");
	pop(&myStack);
	free(estado_atual);
	estado_atual = listar(myStack, &qtde);
	for (int i = 0; i < qtde; i++)
		printf("%d-", estado_atual[i]);
	getchar();
	return 0;
}
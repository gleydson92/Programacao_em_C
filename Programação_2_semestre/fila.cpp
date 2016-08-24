#include "fila.h"
#include <stdlib.h>

bool iniciar(unsigned int tamanho, stFila *qual)
{
	qual->tamanho = tamanho;
	qual->elem = (int*)malloc(sizeof(int)*tamanho);
	qual->inicio = qual->fim = 0;
	return qual->elem != 0;
}
bool push(int valor, stFila *qual)
{
	if (cheia(*qual)) return false;
	qual->elem[qual->fim] = valor;
	qual->fim++;
	return true;
}
bool pop(stFila *qual)
{
	if (vazia(*qual)) return false;
	qual->inicio++;
	return true;
}

int* listar(stFila qual, unsigned int *qtde)
{
	int *retorno;
	*qtde = qual.fim - qual.inicio;
	retorno = (int*)malloc(sizeof(int)*(*qtde));
	for (unsigned int i = 0; i < qtde; i++)
		retorno[i] = qual.elem[qual.inicio + i];
	return retorno;
}
bool vazia(stFila qual)
{
	if (qual.inicio == qual.fim) return true;
	return false;
}
bool cheia(stFila qual)
{
	if (qual.fim == qual.tamanho) return true;
	return false;
}

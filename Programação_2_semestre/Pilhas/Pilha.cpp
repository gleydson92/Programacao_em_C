#include "Pilha.h"
#include <malloc.h>
#include<stdbool.h>
bool iniciar(unsigned int tamanho, Pilha *qual){
	qual->elem = (int*)malloc(sizeof(int)*tamanho);
	qual->tamanho = tamanho;
	qual->topo = 0;
	return qual->elem != 0;
}
bool push(int valor, Pilha *qual)
{
	if (cheia(*qual)) return false;
	qual->elem[qual->topo] = valor;
	qual->topo++;
	return true;
}
bool pop(Pilha *qual)
{
	if (vazia(*qual)) return false;
	qual->topo--;
	return true;
}
int* listar(Pilha qual, unsigned int *qtde)
{
	int *retorno = (int*)malloc(sizeof(int)*qual.topo);
	*qtde = qual.topo;
	for (int i = 1; i <= qual.topo; i++)
		retorno[i-1] = qual.elem[qual.topo - i];
	return retorno;
}
bool cheia(Pilha qual)
{
	return qual.topo == qual.tamanho;
}
bool vazia(Pilha qual)
{
	return qual.topo == 0;
}

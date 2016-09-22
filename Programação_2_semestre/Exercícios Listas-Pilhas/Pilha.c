#include "Pilha.h"
#include <malloc.h>
#include<stdbool.h>

int iniciar_stack(unsigned int tamanho, Pilha *qual){
	qual->elem = (int*)malloc(sizeof(int)*tamanho);
	qual->tamanho = tamanho;
	qual->topo = 0;
	return qual->elem != 0;
}
int push_stack(int valor, Pilha *qual)
{
	if (cheia_stack(*qual)) return false;
	qual->elem[qual->topo] = valor;
	qual->topo++;
	return true;
}
int pop_stack(Pilha *qual)
{
	if (vazia_stack(*qual)) return false;
	qual->topo--;
	return true;
}
int* listar_stack(Pilha qual, unsigned int *qtde)
{
	int *retorno = (int*)malloc(sizeof(int)*qual.topo);
	*qtde = qual.topo;
	for (int i = 1; i <= qual.topo; i++)
		retorno[i-1] = qual.elem[qual.topo - i];
	return retorno;
}
int cheia_stack(Pilha qual)
{
	return qual.topo == qual.tamanho;
}
int vazia_stack(Pilha qual)
{
	return qual.topo == 0;
}	

#pragma once

typedef struct
{
	int *elem;
	unsigned int tamanho;
	unsigned int topo;
} Pilha;

int iniciar_stack(unsigned int tamanho, Pilha *qual);
int push_stack(int valor, Pilha *qual);
int pop_stack(Pilha *qual);
int* listar_stack(Pilha qual, unsigned int *qtde);
int cheia_stack(Pilha qual);
int vazia_stack(Pilha qual);

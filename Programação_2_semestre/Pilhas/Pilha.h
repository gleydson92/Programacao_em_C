#pragma once

typedef struct
{
	int *elem;
	unsigned int tamanho;
	unsigned int topo;
} Pilha;

bool iniciar(unsigned int tamanho, Pilha *qual);
bool push(int valor, Pilha *qual);
bool pop(Pilha *qual);
int* listar(Pilha qual, unsigned int *qtde);
bool cheia(Pilha qual);
bool vazia(Pilha qual);

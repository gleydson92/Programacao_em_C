#pragma once

typedef struct {
	int *elem;
	unsigned int tamanho;
	unsigned int inicio, fim;
}stFila;

bool iniciar(unsigned int tamanho, stFila *qual);
bool push(int valor, stFila *qual);
bool pop(stFila *qual);
int* listar(stFila qual, unsigned int *qtde);
bool vazia(stFila qual);
bool cheia(stFila qual);

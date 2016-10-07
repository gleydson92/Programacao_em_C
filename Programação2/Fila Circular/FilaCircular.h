#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#ifndef	_FILACIRCULAR_H_
#define _FILACIRCULAR_H_
/*Cabeçalho com os prótotipos de filas*/
typedef struct{
	int *elementos;
	unsigned int tamanho;
	unsigned int inicio,fim;
}fila;
bool iniciar(unsigned int tamanho, fila *qual);
bool push(int info, fila *qual);
bool pop(fila *qual);
int	*listar(fila qual,unsigned int *qtde);
bool cheia(fila qual);
bool vazia(fila qual);
#endif

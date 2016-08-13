#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*Cabeçalho com os prótotipos de filas*/
typedef struct{
	int *elementos;
	unsigned int tamanho;
	unsigned int inicio,fim;
}fila;
bool iniciar(unsigned int tamanho, struct fila *qual);
bool push(int info, struct fila *qual);
bool pop(struct fila *qual);
int	*listar(struct fila qual);
bool cheia(struct fila qual);
bool vazia(struct fila qual);

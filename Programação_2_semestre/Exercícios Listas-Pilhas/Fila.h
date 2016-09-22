#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*Cabeçalho com os prótotipos de filas*/
typedef struct{
	int *elementos;
	unsigned int tamanho;
	unsigned int inicio,fim;
}fila;
bool iniciar_queue(unsigned int tamanho, fila *qual);
bool push_queue(int info, fila *qual);
bool pop_queue(fila *qual);
int	*listar_queue(fila qual);
bool cheia_queue(fila qual);
bool vazia_queue(fila qual);

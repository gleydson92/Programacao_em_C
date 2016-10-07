#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*Cabeçalho com os prótotipos de filas*/
#ifndef _FILACIRCULAR_H_
#define _FILACIRCULAR_H_
typedef struct{
	int *run,*row,*col;
	unsigned int tamanho;
	unsigned int inicio,fim;
}fila;
int MIDILogo(char *cMenssagen);
bool iniciar(unsigned int tamanho, fila *qual);
bool encerrar(fila *qual);
bool push(unsigned int row,unsigned int col, fila *qual);
bool pop(fila *qual,unsigned int *row, unsigned int *col);
bool listar(fila qual,unsigned int *qtde, unsigned int *row, unsigned *col);
bool cheia(fila qual);
bool vazia(fila qual);
#endif

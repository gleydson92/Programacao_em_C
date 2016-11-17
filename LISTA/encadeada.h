#include<stdio.h>
#include<stdlib.h>
struct lista{
	int data;
	struct lista *next;
};

typedef struct lista Node;

int cria(Node *myList);
int vazia(Node *myList);
int insereFim(Node *myList,int elemento);
void exibe(Node *myList);
void insereInicio(Node *myList,int value);
int buscar(Node *root,int value);
int remover(Node *myList,int value);
void destruir(Node *myList);

#include<stdio.h>
#include<stdlib.h>
struct lista{
	int data;
	struct lista *next;
};
typedef struct lista Node;

int vazia(Node *myList);
int cria(Node *myList);
Node *criaNo();
int insereFim(Node *myList,int elemento);
void insereInicio(Node *myList,int value);
void exibe(Node *myList);
int buscar(Node *myList,int value);
void destruir(Node *myList);
void insere (Node *myList);
Node *retiraInicio(Node *myList);
Node *retiraFim(Node *myList);
Node *retira(Node *myList);

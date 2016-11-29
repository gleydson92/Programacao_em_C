#include <stdio.h>
#include <stdlib.h>


struct no{
	int infoTree;
	struct no *direita, *esquerda;
}no;


void rm_ELEMENTO(struct no **raiz, int elemento);
void c_TREE(struct no **raiz);
void add_ELEMENTO(struct no **raiz, int elemento);
int find_ELEMENTO(struct no **raiz, int elemento);
void Ordem(struct no *raiz);
void PreOrdem(struct no *raiz);
void PosOrdem(struct no *raiz);

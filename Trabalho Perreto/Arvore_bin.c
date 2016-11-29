#include <stdio.h>
#include <stdlib.h>
#include "Arvore_bin.h"

//void B_Tree(){}


void c_TREE(struct no **raiz){
	
	*raiz == NULL;
}

void add_ELEMENTO(struct no **raiz, int elemento){
	
	if (*raiz == NULL){
		*raiz = (struct no*) malloc(sizeof(struct no));
			(*raiz) -> direita = NULL;
			(*raiz) -> esquerda = NULL;
			(*raiz) -> infoTree = elemento;		
	}else{
	//if (elemento > (*raiz) -> infoTree)
		//add_ELEMENTO(&(*raiz) -> direita, elemento);
	//else
		//add_ELEMENTO(&(*raiz) -> esquerda, elemento);
	//return;// Acho que da no mesmo....

	if (elemento > (*raiz) -> infoTree){
		add_ELEMENTO(&(*raiz) -> direita, elemento);
		return;
	}
	
	if (elemento < (*raiz) -> infoTree){
		add_ELEMENTO(&(*raiz) -> esquerda, elemento);
		return;	
	} 
	}

}

struct no *Dois_Filhos(struct no *root){
	if (root == NULL) 
		return NULL;
	else if (root -> esquerda == NULL) 
		return root;
	else 
		return Dois_Filhos(root -> esquerda);
}

void rm_ELEMENTO(struct no **raiz, int elemento)
{
	if (elemento < (*raiz) -> infoTree)
		rm_ELEMENTO(&(*raiz) -> esquerda, elemento);	
	else if (elemento > (*raiz) -> infoTree)
		rm_ELEMENTO(&(*raiz) -> direita, elemento);	
	else if((*raiz) -> esquerda != NULL && (*raiz) -> direita != NULL)
	{
		struct no *aux;
		aux = NULL;
		aux = Dois_Filhos((*raiz) -> direita);
		(*raiz) -> infoTree = aux -> infoTree;
		rm_ELEMENTO(&(*raiz) -> direita , (*raiz) -> infoTree);	
		
	}
	else 
	{
		struct no *aux;
		aux = (*raiz);
		if ((*raiz) -> esquerda == NULL)
		{	
			(*raiz) = (*raiz) -> direita;
		}	
		else
		{	
			(*raiz) = (*raiz) -> esquerda;		
		}
		//printf("ELEMENTO %d REMOVIDO\n",elemento);
		free(aux);
		
	}
}

int find_ELEMENTO(struct no **raiz, int elemento)
{
   while (*raiz != NULL)
   {
         if (elemento < (*raiz) -> infoTree)
               (*raiz) = (*raiz) -> esquerda;
         else if (elemento > (*raiz) -> infoTree)
               (*raiz) = (*raiz) -> direita;
         else
         {
              printf("Elemento %d encontrado\n", elemento);
              return(elemento);
         }
   }
   printf("Elemento %d nao encontrado\n",elemento); 
   return -1;
}

void PreOrdem(struct no *raiz)
{
	if (raiz != NULL){
	printf("%d ", raiz -> infoTree);
	PreOrdem(raiz -> esquerda);
	PreOrdem(raiz -> direita);
	}
}

void Ordem(struct no *raiz)
{
	if(raiz != NULL){
	Ordem(raiz -> esquerda);
	printf("%d ", raiz -> infoTree);
	Ordem(raiz -> direita);
	}
}

void PosOrdem(struct no *raiz)
{
	if(raiz != NULL){
	PosOrdem(raiz -> esquerda);
	PosOrdem(raiz -> direita);
	printf("%d ", raiz -> infoTree);
	}
}



int main(){

struct no *raiz;
raiz == NULL;
add_ELEMENTO(&raiz,10);
add_ELEMENTO(&raiz,9);
add_ELEMENTO(&raiz,8);
add_ELEMENTO(&raiz,5);
add_ELEMENTO(&raiz,4);
add_ELEMENTO(&raiz,7);
add_ELEMENTO(&raiz,6);
printf("Pre Ordem : ");
PreOrdem(raiz);
printf("\n");
printf("Ordem : ");
Ordem(raiz);
printf("\n");
printf("Pos Ordem : ");
PosOrdem(raiz);
printf("\n");
rm_ELEMENTO(&raiz,6);
//rm_ELEMENTO(&raiz,11);
printf("Pre Ordem : ");
PreOrdem(raiz);
printf("\n");
printf("Ordem : ");
Ordem(raiz);
printf("\n");
printf("Pos Ordem : ");
PosOrdem(raiz);
printf("\n");
find_ELEMENTO(&raiz,8);
find_ELEMENTO(&raiz,6);



return 0;
}


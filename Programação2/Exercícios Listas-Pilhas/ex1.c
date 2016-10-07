/*
1) Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas os testes de fila e pilha vazias, as operações push e pop das duas estruturas, e uma variável aux do TipoItem, escreva uma função que inverta a ordem dos elementos da fila.*/

#include"Fila.h"
#include"Pilha.h"
#include<stdio.h>
int tamanho=10;
int main(void){
	Pilha my_stack;
	fila my_queue;
	iniciar_stack(tamanho,&my_stack);
	iniciar_queue(tamanho,&my_queue);
	
	for(register unsigned int cont = 0 ; cont < 10 ; cont ++){
		push_queue(cont,&my_queue);
		printf("Fila(%d):%d\n",cont+1,cont);
	}
	int *aux;
	aux = (int*)malloc((sizeof(tamanho)));
	aux = listar_queue(my_queue);
	for(register unsigned int cont = 0 ; cont < 10 ; cont ++){
		int valor = aux[cont];
		push_stack(valor,&my_stack);
		printf("Fila(%d):%d\n",cont+1,aux[cont]);
		pop_queue(&my_queue);
	}
	int quantidade;
	aux = listar_stack(my_stack,&quantidade);
	for(register unsigned int cont = 0 ; cont < 10 ; cont ++){
		int valor = aux[cont];
		push_queue(valor,&my_queue);
		printf("Fila(%d):%d\n",cont+1,aux[cont]);
	}
	free(aux);
}

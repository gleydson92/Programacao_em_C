#include"encadeada.h"
int cria(Node *myList){
	myList = (Node*)malloc(sizeof(Node));
	myList->data = 0;
	myList->next = NULL;;
}
int vazia(Node *myList){
	if(myList->next == NULL)	return 1;
	else return 0;	
}
int insereFim(Node *myList,int elemento){
	Node *nova = (Node*)malloc(sizeof(Node));
	nova->data = elemento;
	nova->next = NULL;
	if(vazia(myList) == 1)	myList->next = nova;
	else{
		Node *temporaria;
		temporaria = myList->next;
		while(temporaria->next!=NULL)	temporaria = temporaria->next;
		temporaria->next = nova;
	}
}
void exibe(Node *myList){
	if(vazia(myList) != 1){
		Node *node = myList;
		node = node->next; // Para desconsiderar o primeiro nó
		while(node!=NULL){	
			printf("%d\n",node->data);
			node = node->next;
		}
		printf("\n");
	}
}
void insereInicio(Node *myList,int value){
	Node *novo = (Node*)malloc(sizeof(Node));
	if(!novo){
		printf("Sem Memoria!\n");
		exit(1);
	}
	Node *oldHead = myList->next;
	novo->next = oldHead;
	novo->data = value;
}
int buscar(Node *root,int value){
	if(vazia(root)==1)	return 0;
	else{
		while(root !=NULL){
			if(root->data == value)
				return root->data;
			root = root->next;
		}
	}
}
int remover(Node *myList,int value){
	if(myList == NULL)	return 0;
	if(myList->data == value){
		myList = myList->next;
		return 1;
	}
	Node *aux = myList;
	while(aux->next != NULL){
		if(aux->next->data == value){
			Node *aux2 = aux->next;
			aux->next = aux2->next;
			free(aux2);
			return 1;
		}
		aux = aux->next;
	}
	return 0;
}
void destruir(Node *myList){
	static int chamada = 0;
	while (myList != NULL){
		chamada++;
		remover(myList,myList->data);
		myList = myList->next;
	}
}


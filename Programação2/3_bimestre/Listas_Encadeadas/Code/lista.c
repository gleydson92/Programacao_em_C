#ifndef	LIST_H
#define LIST_H
#endif
#include<stdio.h>
#include<stdlib.h>
void begin(struct list *root){
	root = 0;
}
void push(int value,struct list *root){
	struct list *element = (struct list*)malloc(sizeof(struct list));
	element->info = value;
	element->next = 0;
	if(root == 0)	root = element;
	else{
		struct list *aux = root;
		while(aux->next !=0)	aux = aux->next;
		aux->next = element;
	}
}
int pop(int value,list *root){

}
void find(int value,struct list *root);
void destroy(struct list *root);
int *list(struct list *root);

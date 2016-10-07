#include<stdio.h>
#include"lista.h"
int main(void){
	struct list *root;
	
	begin(root);
	
	push(1,root);
	push(3,root);
	push(5,root);
	
	pop(3,root);
	if(find(3,root))	printf("Não encontrou!\n");
	else 	printf("Encontrou!\n");
	int *ret=list(root);
	destroy(root);
}

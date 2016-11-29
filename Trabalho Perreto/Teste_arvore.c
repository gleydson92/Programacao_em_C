#include"binary_tree.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int strToNum(char *string_to_num){
	while (*string_to_num) {
    	if (isdigit(*string_to_num)){ 
    	    long val = strtol(string_to_num, &string_to_num, 10); 
			return val;
    	} else  string_to_num++;
	}
}
char comandos[][30]={"add 15","add 18","find 15","end"};
int command(treeNode *root,char *actions[]){
	char *string,*command;
	strcpy(string,*actions);
	if(string == NULL)	return 0; //verificação na chamada de Função
	else    command = strsep(&string," ");
	if(command == NULL)	return 0;// Verifica se a String Commando é nula
	if(string!=NULL)		string[strlen(string)-1] = '\0'; //Verifica se a String SubComando é nula, se não,remove '\n'
	//else return 0;

	int elemento = strToNum(string);

	if(strcmp(command,"add")==0){
		printf("Deu ADD:%d\n",strToNum(string));
        root = add(root, elemento);
		//return root;
	}
	else if(strcmp(command,"rm")==0){
		printf("Deu RM:%d\n",strToNum(string));
        root = rm(root,elemento);
		//return root;
	}
	else if(strcmp(command,"find")==0){
        treeNode * temp;
		printf("Deu FIND:%d\n",strToNum(string));
        temp = find(root,elemento);
		if(temp != NULL)		printf("Elemento %d Encontrado!\n",temp->data);
		else printf("Elemento %d não Encontrado!\n",elemento);
		//return root;
	}
	else if(strcmp(command,"print")==0){
		if(strcmp(string,"-pre-order")==0){
			printf("Deu PRINT:%s\n",string);
			pre_order(root);
			//return root;
		}
		else if(strcmp(string,"-in-order")==0){
			printf("Deu PRINT:%s\n",string);
			in_order(root);
			//return root;
		}
		else if(strcmp(string,"-post-order")==0){	
			printf("Deu PRINT:%s\n",string);
			post_order(root);
			//return root;
		}
		//else return root;
	}
	else if(strcmp(command,"balance")==0){
		printf("Deu BALANCE:%s\n",string);
		//return root;
	}
	else if(strcmp(command,"end")==0 || strcmp(command,"end") == 10){
		printf("Deu END!\n");
		//root = NULL;
		return -1;
	}
	//else return root;
}
int main()
{		
        treeNode *root = NULL;
	for(int cont =0 ; cont<4;cont++){
		if(command(root,comandos[cont])==-1)	return 0;
	}
/*
        root = add(root, 5);
        root = add(root, -1);
        root = add(root, 2);	
        root = add(root, -14);
        root = add(root, 8); 
        root = add(root, 10);
		root = add(root, 9);
        root = add(root, 6); 
		in_order(root);
        printf("\n");
       	root = rm(root,5);
        root = rm(root,-1);
        in_order(root);
        printf("\n");
		post_order(root);
		printf("\n");
		pre_order(root);
		printf("\n");
        treeNode * temp;
        temp = Find_Min(root);
        printf("Minimum element is %d\n",temp->data);
        temp = Find_Max(root);
        printf("Maximum element is %d\n",temp->data);
        
		temp = find(root,-5);
        	if(temp!=NULL)		printf("Element %d Found\n", temp -> data);
        	else				printf("Element not found\n");
        
        temp = find(root,2);
        	if(temp!=NULL)		printf("Element %d found\n", temp -> data);
        	else				printf("Element not Found\n");
*/
}

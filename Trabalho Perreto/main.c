#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"binary_tree.h"
int strToNum(char *string_to_num){
	while (*string_to_num) {
    	if (isdigit(*string_to_num)){ 
    	    long val = strtol(string_to_num, &string_to_num, 10); 
			return val;
    	} else  string_to_num++;
	}
}
/********Função Command:***********
Função responsável pela conversão da string lida do arquivo em 2 comandos(1 Comando e 1 Subcomando ou 1 Valor)
	Exemplo:	add 18	->add(comando) , 18(valor)
				print -pre-order -> print(comando) , -pre-order(Subcomando)
Retorno:	Se for encontrado comando e subcomando, retorna 1, se não, retorna 0
	(*Fazer com que retorne -1 ao encontrar erro)		*/
treeNode *command(treeNode *root,char *string){
	char *command = strsep(&string," ");
	//if(string == NULL)	return 0; //verificação na chamada de Função
	//else    command = strsep(&string," ");
	//if(command == NULL)	return 0;// Verifica se a String Commando é nula
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
		return root;
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
		else return root;
	}
	else if(strcmp(command,"balance")==0){
		printf("Deu BALANCE:%s\n",string);
		//return root;
	}
	else if(strcmp(command,"end")==0 || strcmp(command,"end") == 10){
		printf("Deu END!\n");
		root = NULL;
		return NULL;
	}
	//else return root;
}
int main(int argc,char *argv[]){
	if(argc < 2){
		printf("Sem Argumentos da Linha de Comando!\n");
		return -1;
	}
	char caminho_arquivo[30],*line = NULL,*string= NULL;
	strcpy(caminho_arquivo,argv[1]);
	FILE *arquivo = fopen(caminho_arquivo,"r+");
	if(arquivo == NULL){
		printf("Não pode Abrir o Arquivo!\n");
		return -1;
	}

    treeNode *root = NULL;

	size_t len = 0;
	int read;
	while ((read = getline(&line, &len, arquivo)) != -1) {
		//if(command(root,line) == 0)	return 0;
		if(line == NULL)	return 0;
		root = command(root,line);
		//if(root == NULL)	return 0;
    }
	fclose(arquivo)	;
}

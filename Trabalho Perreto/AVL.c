#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//#include"Arvore_bin.h"
/*
	Split Function:	What i've tried...
	   #include <string.h>

       char *strtok(char *str, const char *delim);

       char *strtok_r(char *str, const char *delim, char **saveptr);
	
	That worked verry well!
	   #include <string.h>

       char *strsep(char **stringp, const char *delim);
*/
struct no{
	int infoTree;
	struct no *direita, *esquerda;
}no;

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
		free(aux);
		//printf("ELEMENTO %d REMOVIDO\n",elemento);
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
int command(struct no *root,char *string){
	char *command;
	if(string == NULL)	return 0; //verificação na chamada de Função
	else    command = strsep(&string," ");
	if(command == NULL)	return 0;// Verifica se a String Commando é nula
	if(string!=NULL)		string[strlen(string)-1] = '\0'; //Verifica se a String SubComando é nula, se não,remove '\n'
	else return 0;

	int elemento = strToNum(string);

	if(strcmp(command,"add")==0){
		printf("Deu ADD:%d\n",strToNum(string));
		add_ELEMENTO(&root,elemento);
		return 1;
	}
	else if(strcmp(command,"rm")==0){
		printf("Deu RM:%d\n",strToNum(string));
		rm_ELEMENTO(&root,elemento);
		return 1;
	}
	else if(strcmp(command,"find")==0){
		printf("Deu FIND:%d\n",strToNum(string));
		if(find_ELEMENTO(&root, strToNum(string)) != -1)	printf("Elemento %d Encontrado!\n",elemento);
		else printf("Elemento %d não Encontrado!\n",elemento);
		return 1;
	}
	else if(strcmp(command,"print")==0){
		if(strcmp(string,"-pre-order")==0){
			printf("Deu PRINT:%s\n",string);
			PreOrdem(root);
			return 1;
		}
		else if(strcmp(string,"-in-order")==0){
			printf("Deu PRINT:%s\n",string);
			Ordem(root);
			return 1;
		}
		else if(strcmp(string,"-post-order")==0){	
			printf("Deu PRINT:%s\n",string);
			PosOrdem(root);
			return 1;
		}
		else return 0;
		return 1;
	}
	else if(strcmp(command,"balance")==0){
		printf("Deu BALANCE:%s\n",string);
		return 1;
	}
	else if(strcmp(command,"end")==0 || strcmp(command,"end") == 10){
		printf("Deu END!\n");
		return 1;
	}
	else return 0;
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

	struct no *raiz;
	c_TREE(&raiz);
	size_t len = 0;
	int read;
	while ((read = getline(&line, &len, arquivo)) != -1) {
		if(command(raiz,line) == 0)	return 0;
    }
	fclose(arquivo)	;
}

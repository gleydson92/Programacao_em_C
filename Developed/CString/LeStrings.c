/****************************************************************************************************
|	Autor: Edimar Calebe Castanho
|
|Este Código pode Ser utilizado para Ler Strings com um menor risco de estouro de Buffer.
|Não é um código 100% revisado, porém apresentou resultados satisfatórios nos testes.
|
|Para se utilizar deste código. O seu ponteiro deverá impreterívelmente ser uma variável Global.
|Caso contrário o conteúdo da sua String será NULL, a menos que você acesse o seu conteúdo 
|somente dentro da Função 'lestring()' 
|
|#Protótipo:	char *lestring(int min, int max);
|Função Recebe como parâmetros dois inteiros, um deles serve para comparar o tamanho mínimo da String, 
|e o outro compara o tamanho máximo da string. Se esses valores forem desobedecidos a função retorna ao
|início da função e realiza a leitura novamente.
|
|#Se o Valor máximo for passado com valor igual a 0(zero), o mesmo é assumido como o valor do Buffer,
|ou seja, valor muito grande.
+*****************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *lestring(int min, int max);
int main(void){	
	char *nome;
	nome = lestring(3,10);
	printf("%s",nome);
	free(nome);
}
char *lestring(int min,int max){ 
	int tamanho = 0,vezes = 0;
	if(max == 0)	max = BUFSIZ;
	char aux;
	char *string;
	string = (char *)malloc(tamanho);
	do{
		tamanho = 0;
		if(vezes > 0){
			free(string);			
			string = (char*)malloc(tamanho);
		}
		while((aux = getchar()) != '\n'){
			string = (char *)realloc(string,tamanho + 1*sizeof(char));
			string[tamanho++] = aux ;
		}
		vezes ++;
	}while(strlen(string) < min || strlen(string) > max);
	string[tamanho++] = '\0';
	return realloc(string,sizeof(char)*tamanho);
}

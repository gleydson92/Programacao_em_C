#include<stdio.h>
int strlen(char *string){
	int tamanho = 0;
	while(*string){
		*string++;
		tamanho++;
	}
	return tamanho;
}
int main(void){
	int tamanho=0;
	char string[30];
	printf("Insira uma String:\n");
	scanf("%[^\n]s",string);
	tamanho = strlen(string);
	printf("O tamanho da String é:%d\n",tamanho);
}

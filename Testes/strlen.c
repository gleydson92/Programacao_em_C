#include<stdio.h>
int strlen1(char *string){
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
	tamanho = strlen1(string);
	printf("O tamanho da String é:%d\n",tamanho);
}

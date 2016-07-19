#include<stdio.h>

int main(void){
	printf("Teste de operadores lógicos! \n");
	int num1=4,num2=10,logico=0;
	
	num1=num1>>4;
	logico = (num1) & num2;
	
	printf("%d\n",logico);
}

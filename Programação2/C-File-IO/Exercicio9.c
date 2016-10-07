/*Considere os seguintes arquivos binários:
• “contas.bin”: contém registros de contas bancárias de uma determinada agência. Cada
registro armazena as seguintes informações sobre uma conta bancária: número da conta
(cadeia de 5 caracteres), nome do cliente (cadeia de 40 caracteres) e saldo (valor real);
• “moviment.bin”: contém registros de movimentações feitas (depósitos ou saques) em
contas bancárias. Cada registro armazena as seguintes informações sobre uma
movimentação: número da conta movimentada (cadeia de 5 caracteres), tipo da
movimentação (um caractere, podendo ser ‘S’ para saque e ‘D’ para depósito) e valor da
movimentação (valor real).
Faça um programa que atualize o saldo das contas bancárias contidas no arquivo“contas.bin” de
acordo com as movimentações contidas no arquivo “moviment.bin”.*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
struct contas{
	char conta[5];
	char nomecliente[40];
	float saldo;
}cont[50];
struct movimenta{
	char conta[5];
	char tipo;
	float movimenta;
}mov[50];
int main(void){
	FILE *conta,*movimenta;
	conta = fopen("contas.bin","r");
	movimenta = fopen("moviment.bin","r");
	int contador1=0,contador2=0;
	if(conta == NULL){
		conta = fopen("contas.bin","w+");
		strcpy(cont[0].conta,"12345");
		strcpy(cont[0].nomecliente,"Edimar Calebe Castanho");
		cont[0].saldo = 500;
		fwrite(&cont[0],sizeof(struct contas),1,conta);
	}if(movimenta == NULL){
		movimenta = fopen("moviment.bin","w+");
		strcpy(mov[0].conta,"12345");
		mov[0].tipo = 'S';
		mov[0].movimenta = 150;
		fwrite(&mov[0],sizeof(struct movimenta),1,movimenta);
	}
	while(!feof(conta)){
		fread(&cont[contador1],sizeof(struct contas),1,conta);
		contador1++;
	}
	while(!feof(movimenta)){
		fread(&mov[contador2],sizeof(struct movimenta),1,movimenta);
		contador2++;
	}
	printf("Nome:%s\tConta:%s\tSaldo:R$%f\n\n",cont[0].nomecliente,cont[0].conta,cont[0].saldo);
	if(strcmp(cont[0].conta,mov[0].conta)==0){
		cont[0].saldo = cont[0].saldo-mov[0].movimenta;
		fwrite(&cont[0],sizeof(struct contas),1,conta);
		printf("Nome:%s\tConta:%s\tSaldo:R$%f\n\n",cont[0].nomecliente,cont[0].conta,cont[0].saldo);
	}
		cont[0].saldo = (cont[0].saldo-mov[0].movimenta);
		fwrite(&cont[0],sizeof(struct contas),1,conta);
		printf("Nome:%s\tConta:%s\tSaldo:R$%f\n\n",cont[0].nomecliente,cont[0].conta,cont[0].saldo);
	
	fclose(movimenta);
	fclose(conta);
}

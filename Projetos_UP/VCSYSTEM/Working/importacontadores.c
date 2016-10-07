#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *arquivo;
	arquivo = fopen("/home/calebe94/Projetos/VCSystem/Working/SISTEMADADOS.txt","r+");
	if(arquivo == NULL)
		arquivo = fopen("/home/calebe94/Projetos/VCSystem/Working/SISTEMADADOS.txt","a+");
	int contadorcliente = 0;
	int contadorproduto = 0;
	int contadoracougue = 0;
	int contadorhortifruti = 0;
	int contadorpadaria = 0;
	int contadorhigiene = 0;
	int contadorbebida = 0;
	int contadorchurrasco = 0;
	int contadoralimenta = 0;
	int contadorfrios = 0;
	fread(&contadorcliente,sizeof(contadorcliente),1,arquivo);
	fread(&contadorproduto,sizeof(contadorproduto),1,arquivo);
	fread(&contadoracougue,sizeof(contadoracougue),1,arquivo);
	fread(&contadorhortifruti,sizeof(contadorhortifruti),1,arquivo);
	fread(&contadorpadaria,sizeof(contadorpadaria),1,arquivo);
	fread(&contadorhigiene,sizeof(contadorhigiene),1,arquivo);
	fread(&contadorbebida,sizeof(contadorbebida),1,arquivo);
	fread(&contadorchurrasco,sizeof(contadorchurrasco),1,arquivo);
	fread(&contadoralimenta,sizeof(contadoralimenta),1,arquivo);
	fread(&contadoralimenta,sizeof(contadorfrios),1,arquivo);
	fclose(arquivo);
}

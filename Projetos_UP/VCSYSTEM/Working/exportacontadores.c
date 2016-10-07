#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *arquivo;
	arquivo = fopen("/home/calebe94/Projetos/VCSystem/Working/SISTEMADADOS.txt","w+");
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
	contadorcliente = rand();
	contadorproduto = rand();
	contadoracougue = rand();
	contadorhortifruti = rand();
	contadorpadaria = rand();
	contadorhigiene = rand();
	contadorbebida = rand();
	contadorchurrasco = rand();
	contadoralimenta = rand();
	contadorfrios = rand();
	fwrite(&contadorcliente,sizeof(contadorcliente),1,arquivo);
	fwrite(&contadorproduto,sizeof(contadorproduto),1,arquivo);
	fwrite(&contadoracougue,sizeof(contadoracougue),1,arquivo);
	fwrite(&contadorhortifruti,sizeof(contadorhortifruti),1,arquivo);
	fwrite(&contadorpadaria,sizeof(contadorpadaria),1,arquivo);
	fwrite(&contadorhigiene,sizeof(contadorhigiene),1,arquivo);
	fwrite(&contadorbebida,sizeof(contadorbebida),1,arquivo);
	fwrite(&contadorchurrasco,sizeof(contadorchurrasco),1,arquivo);
	fwrite(&contadoralimenta,sizeof(contadoralimenta),1,arquivo);
	fwrite(&contadoralimenta,sizeof(contadorfrios),1,arquivo);
	fclose(arquivo);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define charmax 100
struct Produtos
{
  char categoria[charmax];
  int auxcategoria;
  char nome[charmax];
  char descricao[charmax];
  char codigobarra[charmax];
  int quantidade;
  int quantidademin;
  float valorcompra;
  float valorvenda;
  float lucro;
  float lucrototal;
  float valortotal;
  int codigo;
}produtos[100];
/*Para Ler os arquivos eu deverei criar uma cópia desta estrutura para facilitar a busca. */
int main(void)
{
	FILE *arquivo;
	arquivo = fopen("SISTEMAPRODUTOS.txt","r");
	char *categoria,*nome,*descricao,leitura[100];
	float codigo,valorcompra,valorvenda,lucrouni,total,lucrogeral;
	int quantidade,quantidadeestoque,cont = 0;
	if(arquivo == NULL)
		printf("Arquivo não encontrado!\n");
	while(!feof(arquivo))
	{
		fread(&produtos[cont], sizeof(struct Produtos), 1, arquivo);
		cont++;
	}
	fclose(arquivo);
}

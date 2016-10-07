/* PROGRAMA DESENVOLVIDO POR: Edimar Calebe Castanho e Vanessa Castro Eler
  TRABALHO BIMESTRAL DA DISCIPLINA DE PROGRAMAÇÃO II DA UNIVERSIDADE POSITIVO:
  #DESENVOLVIMENTO DE UM SISTEMA DE SUPERMERCADO.
    * O sistema conta com cadastro de Clientes(INATIVO NO MOMENTO), e de Produtos.
    * O sistema conta com exportação das Vendas(500 vendas)
    * "    ""     ""   ""      ""    de Produtos e Clientes
    * "    ""     ""   ""      ""    do código dos produtos para auxiliar os funcionarios.
  */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#define charmax 100
void recuperacontadores();
void verificasenha();
void menuselecao();
void menugeral();
void menuvendas();
void menucadastro();
void menuformvendas();
void menuconsultas();
void menucadastroclientes();
void menucadastroprodutos();
void cadastroclientes();
void exportaclientes();
void cadastroprodutos();
void exportaprodutos();
void exportadados();
void alterarclientes();
void excluirclientes();
void alterarprodutos();
void excluirprodutos();
void listaclientes();
void pesquisaclientes();
void listaprodutos();
void pesquisaprodutos();
/* Funções Desenvolvidas por Vanessa Eler no dia 31/05/16:
 *hortifruti()
 *acougue()
 *padaria()
 *iniciavenda()
 *caixa()
 *exportapedidos()
 *exportavenda()
 *pesquisacodigoproduto()
 */
void hortifruti();
void acougue();
void padaria();
void iniciavenda();
void caixa();
void exportapedidos();
void exportavenda();
float pesquisacodigoproduto(int codigoproduto, char *nome);
void baixaquantproduto();
int contadorcliente = 0;
int contadorproduto = 0;
int contadoracougue = 0,contadorhortifruti = 0,contadorpadaria = 0,contadorhigiene = 0;
int contadorbebida = 0,contadorchurrasco = 0,contadoralimenta = 0,contadorfrios = 0;
struct clientes
{
  char nome[charmax];
  char cpf[charmax];
  char telefone[charmax];
  char celular[charmax];
  char endereco[charmax];
  char numero[charmax];
  char credito[charmax];
  char codigo;
}cliente[charmax];
struct Produtos
{
  char categoria[charmax];
  int auxcategoria;
  char nome[charmax];
  char descricao[charmax];
  int codigobarra;
  int quantidade;
  int quantidademin;
  float valorcompra;
  float valorvenda;
  float lucro;
  float lucrototal;
  float valortotal;
  int codigo;
}produtos[charmax];
struct RecuperaProdutos
{
  char categoria[charmax];
  int auxcategoria;
  char nome[charmax];
  char descricao[charmax];
  int codigobarra;
  int quantidade;
  int quantidademin;
  float valorcompra;
  float valorvenda;
  float lucro;
  float lucrototal;
  float valortotal;
  int codigo;
}recuperaprodutos[charmax];
void categorias()
{
  char categoria[8][charmax]={"Açougue","Hortifruti","Padaria","Hig. Pessoal","Bebidas","Churrasco","Alimentação","Frios e Laticínios"};
  for(int cont=0;cont<8;cont++)
  {
    printf("%d-) %s\n",cont+1,categoria[cont]);
  }
  scanf("%d",&produtos[contadorproduto].auxcategoria);
  getchar();
  switch (produtos[contadorproduto].auxcategoria) {
    case 1:
      strcpy(produtos[contadorproduto].categoria,categoria[0]);
      srand( (unsigned)time(NULL) );
      produtos[contadorproduto].codigo = contadoracougue++;
      produtos[contadorproduto].codigobarra = 1000 + ( rand() % 10000 );
      break;
    case 2:
      strcpy(produtos[contadorproduto].categoria,categoria[1]);
      srand( (unsigned)time(NULL) );
      produtos[contadorproduto].codigo = contadorhortifruti++;
      produtos[contadorproduto].codigobarra = 1000 + ( rand() % 10000 );
      break;
    case 3:
      strcpy(produtos[contadorproduto].categoria,categoria[2]);
      srand( (unsigned)time(NULL) );
      produtos[contadorproduto].codigo = contadorpadaria++;
      produtos[contadorproduto].codigobarra = 1000 + ( rand() % 10000 );
      break;
    case 4:
      strcpy(produtos[contadorproduto].categoria,categoria[3]);
      srand( (unsigned)time(NULL) );
      produtos[contadorproduto].codigo = contadorhigiene++;
      produtos[contadorproduto].codigobarra = 1000 + ( rand() % 10000 );
      break;
    case 5:
      strcpy(produtos[contadorproduto].categoria,categoria[4]);
      srand( (unsigned)time(NULL) );
      produtos[contadorproduto].codigo = contadorbebida++;
      produtos[contadorproduto].codigobarra = 1000 + ( rand() % 10000 );
      break;
    case 6:
      strcpy(produtos[contadorproduto].categoria,categoria[5]);
      srand( (unsigned)time(NULL) );
      produtos[contadorproduto].codigo = contadorchurrasco++;
      produtos[contadorproduto].codigobarra = 1000 + ( rand() % 10000 );
      break;
    case 7:
      strcpy(produtos[contadorproduto].categoria,categoria[6]);
      srand( (unsigned)time(NULL) );
      produtos[contadorproduto].codigo = contadoralimenta++;
      produtos[contadorproduto].codigobarra = 1000 + ( rand() % 10000 );
      break;
    case 8:
      strcpy(produtos[contadorproduto].categoria,categoria[7]);
      srand( (unsigned)time(NULL) );
      produtos[contadorproduto].codigo = contadorfrios++;
      produtos[contadorproduto].codigobarra = 1000 + ( rand() % 10000 );
      break;
    default:
      categorias();
  }
}
void encriptar(char *password,int key)
{
	for(int cont = 0; cont< strlen(password);cont++)
		password[cont] = password[cont]-key;
}
void decriptar(char *password,int key)
{
	for(int cont = 0; cont < strlen(password);cont++)
		password[cont] = password[cont]+key;
}
void mensagem()
{
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf("+------------------------------------------------------------+\n");
  printf("|VCSystem * BETA VERSION *%s",asctime(timeinfo));
  printf("+------------------------------------------------------------+\n");
}
int main(void)
{
  recuperacontadores();
  menuselecao();
}
void recuperacontadores()
{

  FILE *arquivo,*arquivo1;
	char leitura[100],*ch[100],leitura1[100];
	int contador = 0;
	arquivo = fopen("/home/calebe94/VCSystem/SISTEMADADOS.txt","r");
	if(arquivo == NULL)
		printf("Erro Ao Abrir.");
	else
		arquivo = fopen("/home/calebe94/VCSystem/SISTEMADADOS.txt","r+");
	while(fgets(leitura,sizeof(leitura),arquivo)!=NULL)
		if(strstr(leitura,"Contador Produto"))
		{
			*ch = strchr(strstr(leitura,"Contador Produto"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadorproduto=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador Cliente"))
		{
			*ch = strchr(strstr(leitura,"Contador Cliente"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadorcliente=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador Açougue"))
		{
			*ch = strchr(strstr(leitura,"Contador Açougue"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadoracougue=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador HortiFruti"))
		{
			*ch = strchr(strstr(leitura,"Contador HortiFruti"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadorhortifruti=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador Padaria"))
		{
			*ch = strchr(strstr(leitura,"Contador Padaria"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadorpadaria=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador Higiene"))
		{
			*ch = strchr(strstr(leitura,"Contador Higiene"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadorhigiene=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador Bebida"))
		{
			*ch = strchr(strstr(leitura,"Contador Bebida"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadorbebida=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador Churrasco"))
		{
			*ch = strchr(strstr(leitura,"Contador Churrasco"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadorchurrasco=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador Alimentação"))
		{
			*ch = strchr(strstr(leitura,"Contador Alimentação"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadoralimenta=atoi(leitura1);
		}
		else if(strstr(leitura,"Contador Frios"))
		{
			*ch = strchr(strstr(leitura,"Contador Frios"),':');
			strcpy(leitura1,*ch);
			for(int cont = 0; cont < strlen(leitura1);cont++)
			leitura1[cont] = leitura1[cont+2];
			contadorfrios=atoi(leitura1);
		}
  arquivo1 = fopen("/home/calebe94/SISTEMAPRODUTOS.txt","r");
  int cont = 0;
  char buffer[100];
	if(arquivo == NULL)
  		printf("Arquivo não encontrado!\n");
while(!feof(arquivo1))
	{
    if(cont == contadorproduto)
      break;
    fread(&recuperaprodutos[cont], sizeof(struct RecuperaProdutos), 1, arquivo1);
  	cont++;
  }
  fclose(arquivo);
	fclose(arquivo1);
}
void verificasenha()
{
  FILE *arquivo;
	arquivo = fopen("senhas","r+");
	if(arquivo == NULL)
		printf("Foram encontrados problemas ao abrir o arquivo!\n");
	else
		arquivo = fopen("senhas","a+");
	char *password,confirmpassword[100],*password1;
	REFAZ:password = (char*)getpass("Entre com sua senha:");
	while(fgets(confirmpassword,sizeof(confirmpassword),arquivo) != NULL)
	{
		if(strstr(confirmpassword,"Senha"))
		{
			password1 = strchr(confirmpassword,':');
				for(int contador = 0 ; contador < strlen(password1);contador ++)
					password1[contador]=password1[contador+1];
			decriptar(password1,0xFACA);
			if(strcmp(password,password1) == 0)
			{
        	printf("Senha correta!\n");
          sleep(2);
          menugeral();
      }
			else
			{
				printf("Senha Incorreta!\n");
        sleep(2);
        menuselecao();
			}
		}
	}
}
void menuselecao()
{
  system("clear");
  mensagem();
  printf(" BEM VINDOWS");
  int selec;
  printf("\n*Para selecionar uma opção digite:\n");
  printf("\t1-) ENTRAR;\n\t2-) SAIR\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
      case 1:
        system("clear");
        verificasenha();
        break;
      case 2:
        system("clear");
        exportadados();
        exit(EXIT_SUCCESS);
        break;
      default:
        system("clear");
        menuselecao();
  }
}
void menugeral()
{
  system("clear");
  mensagem();
  printf(" MENU GERAL");
  int selec;
  printf("\n*Para selecionar uma opção digite:\n");
  printf("\t1-) Cadastros;\n\t2-) Formulário de Vendas;\n\t3-) Consultas;\n\t4-) Iniciar Vendas\n\t5-) Sair\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
      case 1:
          system("clear");
          menucadastro();
          break;
      case 2:
          system("clear");
          menuformvendas();
          break;
      case 3:
          system("clear");
          menuconsultas();
          break;
      case 4:
          system("clear");
          menuvendas();
          break;
      case 5:
          system("clear");
          exportadados();
          exit(EXIT_SUCCESS);
          break;
      default:
          system("clear");
          menugeral();
  }
}
void menuvendas()
{
  system("clear");
  mensagem();
  printf(" MENU VENDAS");
  int selec;
  printf("\n*Para selecionar uma opção digite:\n");
  printf("\t1-) Iniciar Caixa;\n\t2-) Iniciar Açougue;\n\t3-) Iniciar Hortfruti;\n\t4-) Iniciar Padaria\n\t5-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
      case 1:
          system("clear");
          caixa();
          break;
      case 2:
          system("clear");
          acougue();
          break;
      case 3:
          system("clear");
          hortifruti();
          break;
      case 4:
          system("clear");
          padaria();
          break;
      case 5:
          system("clear");
          menugeral();
          break;
      default:
          system("clear");
          menuvendas();
  }
}
void menucadastro()
{
  system("clear");
  mensagem();
  printf(" MENU DE CADASTROS");
  int selec;
  printf("\n*Para selecionar uma opção digite:\n");
  printf("\t1-) Clientes;\n\t2-) Produtos;\n\t3-) Voltar;\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
      case 1:
          menucadastroclientes();
          break;
      case 2:
          system("clear");
          menucadastroprodutos();
          break;
      case 3:
          system("clear");
          menugeral();
          break;
      default:
          system("clear");
          menucadastro();
  }
}
void menuformvendas()
{
  system("clear");
  mensagem();
  printf(" MENU FORMULÁRIO DE VENDAS");
  int selec;
  printf("\n*Para selecionar uma opção digite:\n");
  printf("\t1-) Histórico de Vendas do Dia;\n\t2-) Histórico das Últimas 500 Vendas;\n\t3-) Voltar;\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
      case 1:
          system("clear");
          printf("Função Indisponível no Momento! \n");
          getchar();
          menuformvendas();
          break;
      case 2:
          system("clear");
          printf("Função Indisponível no Momento! \n");
          getchar();
          menuformvendas();
          break;
      case 3:
          system("clear");
          menugeral();
          break;
      default:
          system("clear");
          menuformvendas();
  }
}
void menuconsultas()
{
  system("clear");
  mensagem();
  printf(" MENU DE CONSULTAS");
  int selec;
  printf("\n*Para selecionar uma opção digite:\n");
  printf("\t1-) Lucro do Mercado;\n\t2-) Quantidade de Itens em Estoque;\n\t3-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
      case 1:
          system("clear");
          printf("Função Indisponível no Momento! \n");
          getchar();
          menuconsultas();
          break;
      case 2:
          system("clear");
          printf("Função Indisponível no Momento! \n");
          getchar();
          menuconsultas();
          break;
      case 3:
          system("clear");
          menugeral();
          break;
      default:
          system("clear");
          menuconsultas();
  }
}
void menucadastroclientes()
{
  system("clear");
  mensagem();
  printf(" MENU DE CADASTRO DE CLIENTES");
  int selec;
  printf("\n*Para selecionar uma opção digite:\n");
  printf("\t1-) Novo Cadastro;\n\t2-) Alterar Cadastro;\n\t3-) Excluir Cadastro;\n\t4-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
      case 1:
          system("clear");
          cadastroclientes();
          break;
      case 2:
          system("clear");
          printf("Função Indisponível no Momento!\n");
          getchar();
          menucadastroclientes();
          //alterarclientes();
          break;
      case 3:
          system("clear");
          printf("Função Indisponível no Momento!\n");
          getchar();
          menucadastroclientes();
          break;
      case 4:
          system("clear");
          menucadastro();
          break;
      default:
          system("clear");
          menucadastroclientes();
  }
}
void menucadastroprodutos()
{
  system("clear");
  mensagem();
  printf(" MENU DE CADASTRO DE PRODUTOS");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Novo Cadastro;\n\t2-) Alterar Cadastro;\n\t3-) Excluir Cadastro;\n\t4-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
      case 1:
          system("clear");
          cadastroprodutos();
          break;
      case 2:
          system("clear");
          alterarprodutos();
          break;
      case 3:
          system("clear");
          excluirprodutos();
          break;
      case 4:
          system("clear");
          menucadastro();
          break;
      default:
          system("clear");
          menucadastroprodutos();
  }
}
void cadastroclientes()
{
  system("clear");
  mensagem();
  printf("CADASTRO DE CLIENTES");
  cliente[contadorcliente].codigo = contadorcliente+1;
  printf("\nDigite o Nome do Cliente %d:\t",contadorcliente+1);
  scanf("%[^\n]s",&cliente[contadorcliente].nome);
  getchar();
  printf("\nDigite o CPF do Cliente %d:\t",contadorcliente+1);
  scanf("%[^\n]s",&cliente[contadorcliente].cpf);
  getchar();
  printf("\nDigite o Telefone do Cliente %d:\t",contadorcliente+1);
  scanf("%[^\n]s",&cliente[contadorcliente].telefone);
  getchar();
  printf("\nDigite o Celular do Cliente %d:\t",contadorcliente+1);
  scanf("%[^\n]s",&cliente[contadorcliente].celular);
  getchar();
  printf("\nDigite o Endereço do Cliente %d:\t",contadorcliente+1);
  scanf("%[^\n]s",&cliente[contadorcliente].endereco);
  getchar();
  printf("\nDigite o Número da casa do Cliente %d:\t", contadorcliente+1);
  scanf("%[^\n]s",&cliente[contadorcliente].numero);
  getchar();
  printf("\nDigite o quanto de Crédito o Cliente %d possui:\t",contadorcliente+1);
  scanf("%[^\n]s",&cliente[contadorcliente].credito);
  getchar();
  exportaclientes();
}
void exportaclientes()
{
      FILE *arquivo;
      arquivo = fopen("SISTEMACLIENTES.txt","r+");
      if(arquivo==NULL)
          arquivo = fopen("SISTEMACLIENTES.txt","w");
      else
          arquivo = fopen("SISTEMACLIENTES.txt","a+");
      fwrite(&cliente[contadorcliente], sizeof(struct clientes),1, arquivo);
      getchar();
      fclose(arquivo);
      contadorcliente++;
      menucadastroclientes();
}
void cadastroprodutos()
{
    system("clear");
    mensagem();
    printf("CADASTRO DE PRODUTOS");
    produtos[contadorproduto].codigo = contadorproduto+1;
    printf("\nDigite o Nome do Produto %d:\t",contadorproduto+1);
    scanf("%[^\n]s",&produtos[contadorproduto].nome);
    getchar();
    printf("\nDigite uma Descrição do Produto %d:\t",contadorproduto+1);
    scanf("%[^\n]s",&produtos[contadorproduto].descricao);
    getchar();
    printf("\nDigite a Quantidade em estoque do  Produto %d:\t",contadorproduto+1);
    scanf("%d",&produtos[contadorproduto].quantidade);
    getchar();
    printf("\nDigite a Quantidade Mínima do Produto %d:\t",contadorproduto+1);
    scanf("%d",&produtos[contadorproduto].quantidademin);
    getchar();
    printf("\nDigite o Valor de Compra do Produto %d: R$\t",contadorproduto+1);
    scanf("%f",&produtos[contadorproduto].valorcompra);
    getchar();
    printf("\nDigite o Valor da Venda do Produto %d: R$\t", contadorproduto+1);
    scanf("%f",&produtos[contadorproduto].valorvenda);
    getchar();
    printf("\nSelecione a categoria do Produto:\n");
    categorias();
    produtos[contadorproduto].valortotal = produtos[contadorproduto].valorvenda*produtos[contadorproduto].quantidade;
    produtos[contadorproduto].lucro = produtos[contadorproduto].valorvenda - produtos[contadorproduto].valorcompra;
    produtos[contadorproduto].lucrototal = produtos[contadorproduto].valortotal - (produtos[contadorproduto].valorcompra*30);
    exportaprodutos();
  }
void exportaprodutos()
{
        FILE *arquivo;
        arquivo = fopen("SISTEMAPRODUTOS.txt","r+");
        if(arquivo==NULL)
            arquivo = fopen("SISTEMAPRODUTOS.txt","w");
        else
            arquivo = fopen("SISTEMAPRODUTOS.txt","a+");
        fwrite(&produtos[contadorproduto], sizeof(struct Produtos),1, arquivo);
        printf("Dados Exportados ! \n");
        getchar();
        fclose(arquivo);
        contadorproduto++;
        menucadastroprodutos();
    }
void exportadados()
{
    FILE *arquivo;
    arquivo = fopen("SISTEMADADOS.txt","w+");
    if(arquivo == NULL)
      arquivo = fopen("SISTEMADADOS.txt","w+");
    else
      arquivo = fopen("SISTEMADADOS.txt","w+");
    fprintf(arquivo,"Contador Produto: %d \n",contadorproduto);
    fprintf(arquivo,"Contador Cliente: %d \n",contadorcliente);
    fprintf(arquivo,"Contador Açougue: %d \n",contadoracougue);
    fprintf(arquivo,"Contador HortiFruti: %d \n",contadorhortifruti);
    fprintf(arquivo,"Contador Padaria: %d \n",contadorpadaria);
    fprintf(arquivo,"Contador Higiene: %d \n",contadorhigiene);
    fprintf(arquivo,"Contador Bebida: %d \n",contadorbebida);
    fprintf(arquivo,"Contador Churrasco: %d \n",contadorchurrasco);
    fprintf(arquivo,"Contador Alimentação: %d \n",contadoralimenta);
    fprintf(arquivo,"Contador Frios: %d \n",contadorfrios);
    fclose(arquivo);
  }
void alterarclientes()
{
  system("clear");
  mensagem();
  printf(" MENU ALTERAÇÃO DE CLIENTES");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Listar Cadastros;\n\t2-) Pesquisar;\n\t3-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
    case 1:
        system("clear");
        listaclientes();
        break;
    case 2:
        system("clear");
        pesquisaclientes();
        break;
    case 3:
        system("clear");
        menucadastroclientes();
        break;
    default:
        system("clear");
        alterarclientes();
      }
}
void listaclientes()
{
  system("clear");
  mensagem();
  printf(" MENU PARA LISTAR CLIENTES");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("*Listar Cadastro por:\n");
  printf("\t1-) Ordem de Código;\n\t2-) Nome;\n\t3-) CPF;\n\t4-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
    case 1:
        system("clear");
        //Ordem de Codigo
        break;
    case 2:
        system("clear");
        //Nome
        break;
    case 3:
        system("clear");
        //CPF
        break;
    case 4:
        system("clear");
        alterarclientes();
        break;
    default:
        system("clear");
        excluirclientes();
      }
}
void pesquisaclientes()
{
  system("clear");
  mensagem();
  printf(" MENU PARA PESQUISAR CLIENTES");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("*Pesquisar Cadastro por:\n");
  printf("\t1-) Código;\n\t2-) Nome;\n\t3-) CPF;\n\t4-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
    case 1:
        system("clear");
        //Ordem de Codigo
        break;
    case 2:
        system("clear");
        //Nome
        break;
    case 3:
        system("clear");
        //CPF
        break;
    case 4:
        system("clear");
        alterarclientes();
        break;
    default:
        system("clear");
        excluirclientes();
      }
}
void excluirclientes()
{
  system("clear");
  mensagem();
  printf(" MENU PARA EXCLUIR CLIENTES");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Listar Cadastros;\n\t2-) Pesquisar;\n\t3-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
    case 1:
        system("clear");
        listaclientes();
        break;
    case 2:
        system("clear");
        pesquisaclientes();
        break;
    case 3:
        system("clear");
        menucadastroclientes();
        break;
    default:
        system("clear");
        excluirclientes();
      }
}
void alterarprodutos()
{
  system("clear");
  mensagem();
  printf(" MENU DE ALTERAÇÃO DE PRODUTOS");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Listar Cadastros;\n\t2-) Pesquisar;\n\t3-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
    case 1:
        system("clear");
        listaprodutos();
        break;
    case 2:
        system("clear");
        pesquisaprodutos();
        break;
    case 3:
        system("clear");
        menucadastroprodutos();
        break;
    default:
        system("clear");
        alterarprodutos();
      }
}
void listaprodutos()
{
  system("clear");
  mensagem();
  printf(" MENU PARA LISTAR PRODUTOS");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("*Listar Produto por:\n");
  printf("\t1-) Ordem de Código;\n\t2-) Nome do Produto;\n\t3-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
    case 1:
      system("clear");
      printf("Função Indisponível no Momento! \n");
      getchar();
      listaprodutos();
      break;
    case 2:
      system("clear");
      printf("Função Indisponível no Momento! \n");
      getchar();
      listaprodutos();
      break;
    case 3:
      system("clear");
      alterarprodutos();
      break;
    default:
      system("clear");
      listaprodutos();
    }
}
void pesquisaprodutos()
{
  system("clear");
  mensagem();
  printf(" MENU PARA PESQUISAR PRODUTOS");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("*Pesquisar Produto por:\n");
  printf("\t1-) Código;\n\t2-) Nome do Produto;\n\t3-) Código de Barras;\n\t4-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
    case 1:
      system("clear");
      printf("Função Indisponível no Momento! \n");
      getchar();
      pesquisaprodutos();
      break;
    case 2:
      system("clear");
      printf("Função Indisponível no Momento! \n");
      getchar();
      pesquisaprodutos();
      break;
    case 3:
      system("clear");
      printf("Função Indisponível no Momento! \n");
      getchar();
      pesquisaprodutos();
    case 4:
        system("clear");
        alterarprodutos();
        break;
    default:
        system("clear");
        pesquisaprodutos();
      }
}
void excluirprodutos()
{
  system("clear");
  mensagem();
  printf(" MENU PARA EXCLUIR PRODUTOS");
  int selec;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Listar Cadastros;\n\t2-) Pesquisar;\n\t3-) Voltar\n");
  scanf("%d",&selec);
  getchar();
  switch(selec){
    case 1:
        system("clear");
        listaprodutos();
        break;
    case 2:
        system("clear");
        pesquisaprodutos();
        break;
    case 3:
        system("clear");
        menucadastroprodutos();
        break;
    default:
        system("clear");
        excluirprodutos();
      }
}
void caixa()
{
	int opcao;
	printf("\n\t\t- CAIXA LIVRE -\t");
  printf("Função em testes\n");
	printf("Deseja iniciar nova compra?\n1 - Sim \n2 - Nao\n");
  scanf("%d",&opcao);
  switch (opcao) {
	case 1:
		system("clear");
		iniciavenda();
		break;
	case 2:
		system("clear");
		exportavenda();
		break;
	default:
		system("clear");
		caixa();
	}
}
void iniciavenda()
{
	char continuar = 'S', nome[30];
	float  precototal=0, precoparcial=0,preco;
	int codigoproduto,quantidade;
	while (toupper(continuar) == 'S')
	{
		printf("\nInsira o codigo do produto:\t");
    printf("Função em testes\n");
    do{
		    scanf("%d", &codigoproduto);
		    preco = pesquisacodigoproduto(codigoproduto, nome);
        printf("%s\n",nome);
        printf("Produto correto (S/N): ");
        scanf("%c",&continuar);
    }while(toupper(continuar)!='S');
		printf("\nInforme a quantidade\t");
    printf("Função em testes\n");
		scanf("%d", &quantidade);
		precoparcial = quantidade* preco;
		baixaquantproduto(codigoproduto,quantidade);
		precototal = precototal + precoparcial;
		precoparcial = 0;
		printf("\nInserir novo produto? S/N\n");
		continuar = getchar();
	}
	exportavenda();
	caixa();
}
void acougue()
{
	int selec=0, selec2=0;
	float quantidade,preco,precocarne;
  int codigoproduto;
	char *nomecarne;
  printf("\nInforme o codigo da carne desejada:\t");
  printf("Função em testes\n");
  scanf("%d", &codigoproduto);
	preco = pesquisacodigoproduto(codigoproduto,nomecarne);
	printf("\nInforme a quntidade desejada:\t");
  printf("Função em testes\n");
	scanf("%f", &quantidade);
	precocarne = preco*quantidade;
	printf("Deseja informar outra carne? 1 - Sim\n");
	scanf("%d", &selec2);
	switch (selec2) {
	case 1:
		system("clear");
		acougue();
		break;
	default:
		exportapedidos();
	}
}
void padaria()
{
	int selec = 0, selec2 = 0,codigoproduto;
	float quantidade, preco,precopadaria;
	char *nomepadaria;
  preco = pesquisacodigoproduto(codigoproduto,nomepadaria);
	printf("\nInforme a quntidade desejada:\t");
  printf("Função em testes\n");
	scanf("%f", &quantidade);
	precopadaria = preco*quantidade;
	printf("Deseja informar outro produto? 1 - Sim\t");
  printf("Função em testes\n");
	scanf("%d", &selec2);
	switch (selec2) {
	case 1:
		system("clear");
		padaria();
		break;
	default:
		exportapedidos();
	}
}
void hortifruti()
{
	int selec = 0, selec2 = 0,codigoproduto;
	float quantidade, preco,precofruta;
	char *nomefruta;
  preco = pesquisacodigoproduto(codigoproduto,nomefruta);
	printf("\nInforme a quntidade desejada:\t");
  printf("Função em testes\n");
	scanf("%f", &quantidade);
	precofruta = preco*quantidade;
	printf("Deseja informar outra fruta? 1 - Sim\t");
  printf("Função em testes\n");
	scanf("%d", &selec2);
	switch (selec2) {
	case 1:
		system("clear");
		hortifruti();
		break;
	default:
		exportapedidos();
	}
}
void exportapedidos(){}
void exportavenda(){}
float pesquisacodigoproduto(int codigoproduto, char*nome)
{
  for(int cont = 0; cont < contadorproduto ; cont ++)
  {
    if(codigoproduto == recuperaprodutos[cont].codigobarra);
    {
      strcpy(nome,recuperaprodutos[cont].nome);
      return recuperaprodutos[cont].valorvenda;
    }
  }
}
void baixaquantproduto(){}
/*  KBHIT padrão ANSI */


  #include"VCSystem.h"
  #define charmax 100
  void recuperacontadores();
  void menuselecao();
  void menugeral();
  void menuvendas();
  void menucadastro();
  void menuformvendas();
  void menuconsultas();
  void menucadastroclientes();
  void menucadastroprodutos();
  void cadastroclientes();
  void cadastroprodutos();
  void exportadados();
  void alterarclientes();
  void excluirclientes();
  void alterarprodutos();
  void excluirprodutos();
  void listaclientes();
  void pesquisaclientes();
  void listaprodutos();
  void pesquisaprodutos();
  void cadastrasenha();
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
// Definição do caminho do Programa - LINUX
/*
	char diretorio[30];
	strcpy(diretorio,argv[18]);
	strchr(diretorio,'=');
	strcat(diretorio,"/sistema.txt");
	TEMOS QUE REMOVER A STRING "PWD=" do começo do caminho
*/
  struct clientes{
    char nome[100];
    char cpf[15];
    char telefone[15];
    char celular[15];
    char endereco[100];
    char numero[10];
    char credito[10];
    char codigo;
  }cliente[charmax];
  struct Produtos{
    char categoria[20];
    int auxcategoria;
    char nome[50];
    char descricao[100];
    int codigobarra;
    int quantidade;
    int quantidademin;
    float valorcompra;
    float valorvenda;
    float lucro;
    float lucrototal;
    float valortotal;
  }produtos[charmax];
  struct registrador{
    char *nome;
    int quantidade;
    int codigo;
  };
int main(int argv,char *argc[]){
    recuperacontadores();
    menuselecao();
  }
  void recuperacontadores(){
    FILE *arquivo,*arquivo1,*arquivo2;
  	char leitura[100],*ch[100],leitura1[100];
  	int contador = 0;
  	arquivo = fopen(sistemadados,"r");
  	if(arquivo == NULL) arquivo = fopen(sistemadados,"r+");
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
    arquivo1 = fopen(sistemaprodutos,"r");
    int cont = 0;
    char buffer[100];
  	if(arquivo1 == NULL)  arquivo1 = fopen(sistemaprodutos,"a+");
    while(!feof(arquivo1) && cont < contadorproduto+1){
      if(cont == contadorproduto)    break;
      fread(&produtos[cont], sizeof(struct Produtos), 1, arquivo1);
    	cont++;
    }
    arquivo2 = fopen(sistemaclientes,"r");
    int cont2 = 0;
  	if(arquivo2 == NULL)  arquivo2 = fopen(sistemaclientes,"a+");
    while(!feof(arquivo2) && cont2 < contadorcliente+1){
      if(cont2 == contadorproduto)    break;
      fread(&cliente[cont2], sizeof(struct clientes), 1, arquivo2);
      cont2++;
    }
    fclose(arquivo);
  	fclose(arquivo1);
    fclose(arquivo2);
  }
  void menuselecao(){
    mensagem();
    printf(" BEM VINDOWS");
    char selec=0;
    printf("\n*Para selecionar uma opção digite:\n");
    printf("\t1-) ENTRAR;\n\t2-) SAIR\n");
    selec = (int)getchar();
    switch(selec){
        case 49:
          do{if(verificasenha()==1)
			menugeral();
		  }while(verificasenha() == 0);
          break;
        case 50:
          exit(EXIT_SUCCESS);
          break;
        default:
          menuselecao();
    }
  }
  void menugeral(){
    mensagem();
    printf(" MENU GERAL");
    char selec = 0;
    printf("\n*Para selecionar uma opção digite:\n");
    printf("\t1-) Cadastros;\n\t2-) Formulário de Vendas;\n\t3-) Consultas;\n\t4-) Iniciar Vendas\n\t5-) Configurações\n\t6-) Sair\n");
    selec = (int)getchar();
    switch(selec){
        case 49:
            menucadastro();
            break;
        case 50:
            menuformvendas();
            break;
        case 51:
            menuconsultas();
            break;
        case 52:
            menuvendas();
            break;
        case 53:
            printf("Funções Indisponíveis no Momento...\n");
            printf("Este menu Deverá ter:\n*Alterar Senha[s];\n*Alterar cor do Painel;\n*E outras coisas\n");
            getchar();
            menugeral();
            break;
        case 54:
            exportadados();
            exit(EXIT_SUCCESS);
            break;
        default:
            menugeral();
    }
  }
  void menuvendas(){
    mensagem();
    printf(" MENU VENDAS");
    char selec=0;
    printf("\n*Para selecionar uma opção digite:\n");
    printf("\t1-) Iniciar Caixa;\n\t2-) Iniciar Açougue;\n\t3-) Iniciar Hortfruti;\n\t4-) Iniciar Padaria\n\t5-) Voltar\n");
    selec = (int)getchar();
    switch(selec){
        case 49:
            caixa();
            break;
        case 50:
            acougue();
            break;
        case 51:
            hortifruti();
            break;
        case 52:
            padaria();
            break;
        case 53:
            menugeral();
            break;
        default:
            menuvendas();
    }
  }
  void menucadastro(){
    mensagem();
    printf(" MENU DE CADASTROS");
    char selec=0;
    printf("\n*Para selecionar uma opção digite:\n");
    printf("\t1-) Clientes;\n\t2-) Produtos;\n\t3-) Voltar;\n");
    selec = (int)getchar();
    switch(selec){
        case 49:
            menucadastroclientes();
            break;
        case 50:
            menucadastroprodutos();
            break;
        case 51:
            menugeral();
            break;
        default:
            menucadastro();
    }
  }
  void menuformvendas(){
    mensagem();
    printf(" MENU FORMULÁRIO DE VENDAS");
    char selec=0;
    printf("\n*Para selecionar uma opção digite:\n");
    printf("\t1-) Histórico de Vendas do Dia;\n\t2-) Histórico das Últimas 500 Vendas;\n\t3-) Voltar;\n");
    selec = (int)getchar();
    switch(selec){
        case 49:
            printf("Função Indisponível no Momento! \n");
            getchar();
            menuformvendas();
            break;
        case 50:
            printf("Função Indisponível no Momento! \n");
            getchar();
            menuformvendas();
            break;
        case 51:
            menugeral();
            break;
        default:
            menuformvendas();
    }
  }
  void menuconsultas(){
    mensagem();
    printf(" MENU DE CONSULTAS");
    char selec=0;
    printf("\n*Para selecionar uma opção digite:\n");
    printf("\t1-) Lucro do Mercado;\n\t2-) Quantidade de Itens em Estoque;\n\t3-) Voltar\n");
    selec = (int)getchar();
    switch(selec){
        case 49:
            printf("Função Indisponível no Momento! \n");
            getchar();
            menuconsultas();
            break;
        case 50:
            printf("Função Indisponível no Momento! \n");
            getchar();
            menuconsultas();
            break;
        case 51:
            menugeral();
            break;
        default:
            menuconsultas();
    }
  }
  void menucadastroclientes(){
    mensagem();
    printf(" MENU DE CADASTRO DE CLIENTES");
    char selec=0;
    printf("\n*Para selecionar uma opção digite:\n");
    printf("\t1-) Novo Cadastro;\n\t2-) Alterar Cadastro;\n\t3-) Excluir Cadastro;\n\t4-) Voltar\n");
    selec = (int)getchar();
    switch(selec){
        case 49:
            cadastroclientes();
            break;
        case 50:
            printf("Função Indisponível no Momento!\n");
            getchar();
            menucadastroclientes();
            break;
        case 51:
            printf("Função Indisponível no Momento!\n");
            getchar();
            menucadastroclientes();
            break;
        case 52:
            menucadastro();
            break;
        default:
            menucadastroclientes();
    }
  }
  void menucadastroprodutos(){
    mensagem();
    printf(" MENU DE CADASTRO DE PRODUTOS");
    char selec=0;
    printf("\n*Para selecionar uma opção  digite:\n");
    printf("\t1-) Novo Cadastro;\n\t2-) Alterar Cadastro;\n\t3-) Excluir Cadastro;\n\t4-) Voltar\n");
    selec = (int)getchar();
    switch(selec){
        case 49:
            cadastroprodutos();
            break;
        case 50:
            alterarprodutos();
            break;
        case 51:
            excluirprodutos();
            break;
        case 52:
            menucadastro();
            break;
        default:
            menucadastroprodutos();
    }
  }
  void cadastroclientes(){
	system("clear");
    FILE *arquivo;
    mensagem();
    char *nome,*cpf,*telefone,*celular,*endereco,*numero,*credito;
    printf("CADASTRO DE CLIENTES");
    printf("\nDigite o Nome do Cliente %d:                      ",contadorcliente+1);
    nome = lestring(5,100);
    strcpy(cliente[contadorcliente].nome,nome);
    printf("Digite o CPF do Cliente %d:                       ",contadorcliente+1);
    cpf = lestring(3,15);
    strcpy(cliente[contadorcliente].cpf,cpf);
    printf("Digite o Telefone do Cliente %d:                  ",contadorcliente+1);
    telefone = lestring(6, 15);
    strcpy(cliente[contadorcliente].telefone,telefone);
    printf("Digite o Celular do Cliente %d:                   ",contadorcliente+1);
    celular = lestring(6, 15);
    strcpy(cliente[contadorcliente].celular,celular);
    printf("Digite o Endereço do Cliente %d:                  ",contadorcliente+1);
    endereco = lestring(12, 100);
    strcpy(cliente[contadorcliente].endereco,endereco);
    printf("Digite o Número da casa do Cliente %d:            ", contadorcliente+1);
    numero = lestring(2, 10);
    strcpy(cliente[contadorcliente].numero,numero);
    printf("Digite o quanto de Crédito o Cliente %d possui:   ",contadorcliente+1);
    credito = lestring(1 , 10);
    strcpy(cliente[contadorcliente].credito,credito);
    arquivo = fopen("SISTEMACLIENTES.txt","a");
    if(arquivo==NULL) arquivo = fopen("SISTEMACLIENTES.txt","a+");
    fwrite(&cliente[contadorcliente], sizeof(struct clientes),1,arquivo);
    printf("Dados Exportados com Sucesso !\n");
    getchar();
    fclose(arquivo);
    contadorcliente++;
    exportadados();
    menucadastroclientes();
  }
void cadastroprodutos(){
    FILE *arquivo,*arquivo1;
    char *nome,*descricao;
    mensagem();
    printf("CADASTRO DE PRODUTOS");
    printf("\nDigite o Nome do Produto %d:                  ",contadorproduto+1);
    nome = lestring(1,20);
    strcpy(produtos[contadorproduto].nome,nome);
    printf("Digite uma Descrição do Produto %d:           ",contadorproduto+1);
    descricao = lestring(5,100);
    strcpy(produtos[contadorproduto].descricao,descricao);
    printf("Digite a Quantidade em estoque do  Produto %d:",contadorproduto+1);
    scanf("%d",&produtos[contadorproduto].quantidade);
    printf("Digite a Quantidade Mínima do Produto %d:     ",contadorproduto+1);
    scanf("%d",&produtos[contadorproduto].quantidademin);
    printf("Digite o Valor de Compra do Produto %d: R$    ",contadorproduto+1);
    scanf("%f",&produtos[contadorproduto].valorcompra);
    printf("Digite o Valor da Venda do Produto %d: R$     ", contadorproduto+1);
    scanf("%f",&produtos[contadorproduto].valorvenda);
    printf("Selecione a categoria do Produto:\n");
    char categoria[8][charmax]={"Açougue","Hortifruti","Padaria","Hig. Pessoal","Bebidas","Churrasco","Alimentação","Frios e Laticínios"};
    srand((unsigned)time(NULL));
    for(int cont=0;cont<8;cont++) printf("%d-) %s\n",cont+1,categoria[cont]);
    do{scanf("%d",&produtos[contadorproduto].auxcategoria);
    }while(produtos[contadorproduto].auxcategoria<0 || produtos[contadorproduto].auxcategoria>8);
    strcpy(produtos[contadorproduto].categoria,categoria[(produtos[contadorproduto].auxcategoria - 1)]);
    produtos[contadorproduto].codigobarra = 1000 +(rand()%10000);
    produtos[contadorproduto].valortotal = produtos[contadorproduto].valorvenda*produtos[contadorproduto].quantidade;
    produtos[contadorproduto].lucro = produtos[contadorproduto].valorvenda - produtos[contadorproduto].valorcompra;
    produtos[contadorproduto].lucrototal = produtos[contadorproduto].valortotal - (produtos[contadorproduto].valorcompra*30);
    exportadados();
    arquivo = fopen("SISTEMAPRODUTOS.txt","a");
    if(arquivo==NULL) arquivo = fopen("SISTEMAPRODUTOS.txt","a+");
    arquivo1 = fopen("SISTEMAREFERENCIA.txt","a");
    if(arquivo1 == NULL) arquivo1 = fopen("SITEMAREFERENCIA.txt","a+");
    fwrite(&produtos[contadorproduto], sizeof(struct Produtos),1, arquivo);
    fprintf(arquivo1, "Item:%d\t",contadorproduto);
    fprintf(arquivo1,"Nome do Produto: %s\t",produtos[contadorproduto].nome);
    fprintf(arquivo1,"Código de Barra: %d\t",produtos[contadorproduto].codigobarra);
    fprintf(arquivo1,"Descrição: %s\n",produtos[contadorproduto].descricao);
    printf("Dados Exportados ! \n");
    getchar();
    fclose(arquivo);
    fclose(arquivo1);
    contadorproduto++;
    menucadastroprodutos();
}
void exportadados(){
  FILE *arquivo;
  arquivo = fopen("SISTEMADADOS.txt","w");
  if(arquivo == NULL) arquivo = fopen("SISTEMADADOS.txt","wb");
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
void alterarclientes(){
  mensagem();
  printf(" MENU ALTERAÇÃO DE CLIENTES");
  char selec=0;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Listar Cadastros;\n\t2-) Pesquisar;\n\t3-) Voltar\n");
  selec = (int)getchar();
  switch(selec){
    case 49:
        listaclientes();
        break;
    case 50:
        pesquisaclientes();
        break;
    case 51:
        menucadastroclientes();
        break;
    default:
        alterarclientes();
    }
}
void listaclientes(){
  mensagem();
  printf(" MENU PARA LISTAR CLIENTES");
  char selec=0;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("*Listar Cadastro por:\n");
  printf("\t1-) Ordem de Código;\n\t2-) Nome;\n\t3-) CPF;\n\t4-) Voltar\n");
  selec = (int)getchar();
  switch(selec){
  case 49:
    //Ordem de Codigo
    break;
  case 50:
    //Nome
    break;
  case 51:
    //CPF
    break;
  case 52:
    alterarclientes();
    break;
  default:
    excluirclientes();
  }
}
void pesquisaclientes(){
  mensagem();
  printf(" MENU PARA PESQUISAR CLIENTES");
  char selec=0;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("*Pesquisar Cadastro por:\n");
  printf("\t1-) Código;\n\t2-) Nome;\n\t3-) CPF;\n\t4-) Voltar\n");
  selec = (int)getchar();
  switch(selec){
    case 49:
        //Ordem de Codigo
        break;
    case 50:
        //Nome
        break;
    case 51:
        //CPF
        break;
    case 52:
        alterarclientes();
        break;
    default:
        excluirclientes();
  }
}
void excluirclientes(){
  mensagem();
  printf(" MENU PARA EXCLUIR CLIENTES");
  char selec=0;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Listar Cadastros;\n\t2-) Pesquisar;\n\t3-) Voltar\n");
  selec = (int)getchar();
  switch(selec){
    case 49:
        listaclientes();
        break;
    case 50:
        pesquisaclientes();
        break;
    case 51:
        menucadastroclientes();
        break;
    default:
        excluirclientes();
    }
}
void alterarprodutos(){
  mensagem();
  printf(" MENU DE ALTERAÇÃO DE PRODUTOS");
  char selec=0;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Listar Cadastros;\n\t2-) Pesquisar;\n\t3-) Voltar\n");
  selec = (int)getchar();
  switch(selec){
    case 49:
        listaprodutos();
        break;
    case 50:
        pesquisaprodutos();
        break;
    case 51:
        menucadastroprodutos();
        break;
    default:
        alterarprodutos();
    }
}
void listaprodutos(){
  mensagem();
  printf(" MENU PARA LISTAR PRODUTOS");
  char selec=0;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("*Listar Produto por:\n");
  printf("\t1-) Ordem de Código;\n\t2-) Nome do Produto;\n\t3-) Voltar\n");
  selec = (int)getchar();
  switch(selec){
    case 49:
      printf("Função Indisponível no Momento! \n");
      getchar();
      listaprodutos();
      break;
    case 50:
      printf("Função Indisponível no Momento! \n");
      getchar();
      listaprodutos();
      break;
    case 51:
      alterarprodutos();
      break;
    default:
      listaprodutos();
    }
}
void pesquisaprodutos(){
  mensagem();
  printf(" MENU PARA PESQUISAR PRODUTOS");
  char selec=0;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("*Pesquisar Produto por:\n");
  printf("\t1-) Código;\n\t2-) Nome do Produto;\n\t3-) Código de Barras;\n\t4-) Voltar\n");
  selec = (int)getchar();
  switch(selec){
      case 49:
      printf("Função Indisponível no Momento! \n");
      getchar();
      pesquisaprodutos();
      break;
    case 50:
      printf("Função Indisponível no Momento! \n");
      getchar();
      pesquisaprodutos();
      break;
    case 51:
      printf("Função Indisponível no Momento! \n");
      getchar();
      pesquisaprodutos();
    case 52:
      alterarprodutos();
      break;
    default:
      pesquisaprodutos();
    }
}
void excluirprodutos(){
  mensagem();
  printf(" MENU PARA EXCLUIR PRODUTOS");
  char selec=0;
  printf("\n*Para selecionar uma opção  digite:\n");
  printf("\t1-) Listar Cadastros;\n\t2-) Pesquisar;\n\t3-) Voltar\n");
  selec = (int)getchar();
  switch(selec){
    case 49:
        listaprodutos();
        break;
    case 50:
        pesquisaprodutos();
        break;
    case 51:
        menucadastroprodutos();
        break;
    default:
        excluirprodutos();
  }
}
void caixa(){
  mensagem();
  char opcao=0;
  printf("\n\t\t- CAIXA LIVRE -\t");
  printf("Função em testes\n");
  printf("Deseja iniciar nova compra?\n1 - Sim \n2 - Nao\n");
  opcao = (int)getchar();
  switch (opcao){
	case 49:
		iniciavenda();
		break;
	case 50:
	  printf("Função em Desenvolvimento!");
    getchar();
    menugeral();
  	break;
	default:
		caixa();
	}
}
void iniciavenda(){
  mensagem();
	char  nome[30];
	float  precototal=0, precoparcial=0,preco=0,dinheiro = 0;
	int continuar = 0,codigoproduto=0,quantidade = 0,correto = 0;
	  do{
      //quantidade = 0; PARA COMPRAS COM MAIS DE UM PRODUTO, QUANTIDADE TAMBÉM DEVERÁ SEM PARÂMETRO DE pesquisacodioprodutos()
      printf("Função em testes\t");
      printf("\nInsira o codigo do produto:\t");
      do{}while(scanf("%d", &codigoproduto) == 0);
      getchar();
		  preco = pesquisacodigoproduto(codigoproduto, nome);
      printf("%s\n",nome);
      printf("Produto correto (S[1]/N[2]): ");
      do{}while(scanf("%d",&correto)==0);
  }while(correto !=1);
	printf("\nInforme a quantidade\t");
  printf("Função em testes\n");
	scanf("%d", &quantidade);
	precoparcial = quantidade * preco;
  printf("Preço do Produto:R$%.2f\n",precoparcial);
	baixaquantproduto(codigoproduto,quantidade);
	precototal = precototal + precoparcial;
  getchar();
	printf("\nInserir novo produto? (S[1]/N[2])\n");
  do{}while(scanf("%d",&continuar)==0);
  getchar();
  if(continuar == 1){
    printf("Subtotal:R$%.2f\n",precototal);
    getchar();
  }
  else if(continuar == 2){
    printf("Total:R$%.2f\n",precototal);
    getchar();
    int forma = 0;
    printf("Informe a Forma de Pagamento:\n");
    printf("\t[1]Dinheiro\n\t[2]Cartão\n\t[3]Cartão da Loja\n");
    forma = (int)getchar();
    switch(forma){
      case 49:
        dinheiro = 0;
        printf("Dinheiro:");
        scanf("%f",&dinheiro);
        printf("Troco:%.2f\n",dinheiro-precototal);
        printf("Finge que a Venda Foi exportada!\n");
        printf("O sistem ainda está em desenvolvimento... Dá um desconto ( T_T) \n");
        getchar();
        caixa();
      case 50:
        printf("No momento Só aceitamos Débito :/ \n");
        sleep(2);
        printf("Transação Aceita!");
        getchar();
        caixa();
      case 51:
        printf("No momento nosso Sistema de Clientes está em manutenção :/ \n");
        printf("Para a sua alegria a sua compra será por nossa compra ! \n\t\t : (^_^)");
        getchar();
        caixa();
    }
    //caixa();
  }
}
void acougue(){
  mensagem();
	int selec=0, selec2=0;
	float quantidade,preco,precocarne;
  int codigoproduto;
	char nomecarne[30];
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
		acougue();
		break;
	default:
		exportapedidos();
	}
}
void padaria(){
  mensagem();
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
  	   padaria();
  	   break;
      default:
  	   exportapedidos();
  }
}
void hortifruti(){
  mensagem();
	int quantidade = 0,selec = 0, selec2 = 0,codigoproduto =0;
	float preco,precofruta;
	char *nomefruta;
  preco = pesquisacodigoproduto(codigoproduto,nomefruta);
	printf("\nInforme a quntidade desejada:\t");
  printf("Função em testes\n");
	scanf("%f", &quantidade);
	precofruta = preco*quantidade;
	printf("Deseja informar outra fruta? 1 - Sim\t");
  printf("Função em testes\n");
	scanf("%d", &selec2);
	switch(selec2) {
	case 1:
		hortifruti();
		break;
	default:
		exportapedidos();
	}
}
void exportapedidos(){}
void exportavenda(){}
float pesquisacodigoproduto(int codigoproduto, char* nome){
  for(int cont = 0; cont < contadorproduto ; cont ++){
    if(codigoproduto == produtos[cont].codigobarra){
      strcpy(nome,produtos[cont].nome);
      return produtos[cont].valorvenda;
    }
    else{}
  }
}
void baixaquantproduto(){}

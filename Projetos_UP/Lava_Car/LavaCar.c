#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef _WIN32
#define limpa "cls"
#else
#define limpa "clear"
#endif
#define ncarros 5 //Constante para Facilitar na hora dos testes
#define charmax 100 // Constante para numeros de characteres em uma string
struct carro{
	char nome[charmax];
	char telefone[charmax];
	char placa[charmax];
	int tipo;
    int prioridade;
    int servico;
    int aspirador;
}carro[ncarros];
void menu();
void cadastro();
void continuacadastro();
void listagem();
int prioridade();
void listaprioridades();
void crescente();
void decrescente();
int poscliente=0; // Variável que indica a posição do cliente na ordem de cadastro, se comporta como um contador.
void main(){
    menu();
}
void menu(){   
    system("clear");
    int selec=0;
    printf(" ___      _______  __   __  _______  _______  _______  ______\n");   
    printf("|   |    |   _   ||  | |  ||   _   ||       ||   _   ||    _ |\n");  
    printf("|   |    |  |_|  ||  |_|  ||  |_|  ||       ||  |_|  ||   | ||\n");  
    printf("|   |    |       ||       ||       ||       ||       ||   |_||_\n"); 
    printf("|   |___ |       ||       ||       ||      _||       ||    __  |\n");
    printf("|       ||   _   | |     | |   _   ||     |_ |   _   ||   |  | |\n");
    printf("|_______||__| |__|  |___|  |__| |__||_______||__| |__||___|  |_|\n");   
    printf("*Para selecionar uma opção digite:\n");
    printf("\t1-) Cadastro de Clientes;\n\t2-) Listar Cadastros;\n\t3-) Listar Prioridades;\n\t4-) SAIR\n");
    fflush(stdin);  scanf("%d",&selec);
    getchar();
    switch(selec){
        case 1:
            system("clear");
            cadastro();
            break;
        case 2:
            system("clear");
            listagem();
            break;
        case 3:
            printf("Este menu é para Listar as Prioridades de Serviços!\n");
            system("clear");
            listaprioridades();
            break;
        case 4:
            system("clear");
            exit(EXIT_SUCCESS);
            break;
        default:
            system("clear");
            menu();
    }
}
void cadastro(){
    char aspira='c';
    int retnome=0,rettelefone=0,retplaca=0,rettipo=0,retservico=0,retaspirador=0;
    printf("################### Menu do LavaCar ########################\n");                                                 
    REFAZCLIENTE: printf("\nInsira o Nome do Cliente %d:\t",poscliente+1);
    fflush(stdin);    retnome=scanf("%[^\n]s",carro[poscliente].nome);
    getchar();
  	if(retnome==0)	goto REFAZCLIENTE;
    REFAZTELEFONE: printf("\nInsira o telefone do Cliente %d:\t",poscliente+1);
    fflush(stdin);    rettelefone=scanf("%[^\n]s",carro[poscliente].telefone);
    getchar();
  	if(rettelefone==0) goto REFAZTELEFONE;
    REFAZPLACA: printf("\nInsira a Placa do Carro:\t",poscliente+1);
    fflush(stdin);    retplaca = scanf("%[^\n]s",carro[poscliente].placa);
    getchar();
    system(limpa);
  	if(retplaca==0)	goto REFAZPLACA;
    REFAZCARRO: printf("\nInsira o Tipo do Carro do Cliente %d:\t",poscliente+1);
    printf("\nDigite: \n 1 para carro Hatch;\n 2 para carro Sedan;\n 3 para Motos;\n 4 para Vans.\n");
    fflush(stdin);    rettipo = scanf("%d",&carro[poscliente].tipo);
    getchar();
    system(limpa);
    if(carro[poscliente].tipo>4 || carro[poscliente].tipo<1 || rettipo == 0) goto REFAZCARRO;
    REFAZLAVA: printf("\nSelecione o Tipo de Lavagem que você deseja:");
    printf("\nPressione 1 para Lavagem Completa;\nou,\nPressione 2 Para Lavagem Ecológica\n");
    fflush(stdin);    retservico = scanf("%d",&carro[poscliente].servico);
    getchar();
    system(limpa);
    if(carro[poscliente].servico<1 || carro[poscliente].servico>2 || retservico==0)  goto REFAZLAVA;
    REFAZASP: printf("\nNessecita da passagem do Aspirador de Pó no interior do Veículo? \nS/N ");
    fflush(stdin);    retaspirador = scanf("%c",&aspira);
    getchar();
    if(aspira =='s' || aspira == 'S')
        carro[poscliente].aspirador = -1;
    else if(aspira == 'n' || aspira == 'N')
        carro[poscliente].aspirador = 0;
    else
        goto REFAZASP;
    carro[poscliente].prioridade = prioridade();
    system("clear");
    printf("\nO Valor da sua Prioridade é %d \n\n",carro[poscliente].prioridade);
    aspira = 'c'; 
    poscliente++;
    continuacadastro();
}
void continuacadastro(){   
    char decisao;
    printf("Deseja continuar com o Cadastro? \n");
    printf("S/N \n");
    fflush(stdin);    scanf("%c",&decisao);
    getchar();
    switch(decisao){
        case 's':
            system("clear");
            cadastro();
            break;
        case 'S':
            system("clear");
            cadastro();
            break;
        case 'n':
            system("clear");
            menu();
            break;
        case 'N':
            system("clear");
            menu();
            break;
        default:
            continuacadastro();
    }
}
void listagem(){
    int cont=0;
    for(cont=0;cont<poscliente;cont++){
        printf("\n############ Cliente %d #####################\n\n",cont+1);
        printf("O nome do cliente %d é: %s\n",cont+1,carro[cont].nome);
        printf("O número de telefone do cliente %d é: %s\n",cont+1,carro[cont].telefone);
        printf("O placa do carro do cliente %d é:%s\n",cont+1,carro[cont].placa);
        printf("O tipo do carro do cliente %d é: %d\n",cont+1,carro[cont].tipo);
        printf("O tipo de serviço requisitado pelo cliente %d é: %d\n",cont+1,carro[cont].servico);
        printf("O Cliente %d requisitou aspirador?(Num 1 = SIM, Num 0 = NÃO): %i\n",cont+1,-1*carro[cont].aspirador);
        printf("A Prioridade do Cliente %d é: %d\n",cont+1,carro[cont].prioridade);
    }
    printf("\nPressione qualquer tecla para Retornar para o Menu! \n");
    getchar();
    menu();
}
int prioridade(int n,int m,int o){
    //Variavel 'n' é para tipo do carro
    //Variável 'm' é para Tipo de Serviços
    //Variável 'o' é para aspirador
    int retorno;
    if(carro[poscliente].tipo ==1)
        n= -1;
    else if(carro[poscliente].tipo == 2)
        n = -2;
    else if(carro[poscliente].tipo == 3)
        n = 1;
    else if(carro[poscliente].tipo == 4)
        n = -4;
    else
        printf("Valor não reconhecido!\n");
    if(carro[poscliente].servico == 1)
        m = -2;
    else if(carro[poscliente].servico == 2)
        m = 1;
    else 
        printf("Valor não Reconhecido! \n");
    o = carro[poscliente].aspirador;
    retorno = n+m+o;
    return retorno;
}
void listaprioridades(){
    int selec=0;
    printf("#################### Menu de prioridades ###############\n\n");
    printf("*1-) Insira 1 para listar de forma crescente;\n");
    printf("*2-) Insira 2 para listar de forma decrescente.\n");
    fflush(stdin);    scanf("%d",&selec);
    getchar();
    system(limpa);
    switch(selec){
        case 1:
            crescente();
            break;
        case 2:
            decrescente();
            break;
        default:
            listaprioridades();
    }
}
void crescente(){
     int cont=0,cont1=0,aux=0;
            char name[charmax],tel[charmax],tag[charmax];
            int type=0,service=0,aspirator=0;
            for(cont=0;cont<poscliente;cont++){
                for(cont1=cont+1;cont1<poscliente;cont1++){
                    if(carro[cont].prioridade < carro[cont1].prioridade){
                        aux = carro[cont].prioridade;
                        carro[cont].prioridade=carro[cont1].prioridade;
                        carro[cont1].prioridade=aux;
                        strcpy(name,carro[cont].nome);
                        strcpy(carro[cont].nome,carro[cont1].nome);
                        strcpy(carro[cont1].nome,name);
                        strcpy(tel,carro[cont].telefone);
                        strcpy(carro[cont].telefone,carro[cont1].telefone);
                        strcpy(carro[cont1].telefone,tel);
                        strcpy(tag,carro[cont].placa);
                        strcpy(carro[cont].placa,carro[cont1].placa);
                        strcpy(carro[cont1].placa,tag);
                        type = carro[cont].tipo;
                        carro[cont].tipo=carro[cont1].tipo;
                        carro[cont1].tipo = type;
                        aspirator = carro[cont].aspirador;
                        carro[cont].aspirador = carro[cont1].aspirador;
                        carro[cont1].aspirador = aspirator;
                        service = carro[cont].servico;
                        carro[cont].servico = carro[cont1].servico;
                        carro[cont1].servico = service;
                    }
                }
            }
            listagem();
}
void decrescente(){
     int cont=0,cont1=0,aux=0;
            char name[charmax],tel[charmax],tag[charmax];
            int type=0,service=0,aspirator=0;
            for(cont=0;cont<poscliente;cont++){
                for(cont1=cont+1;cont1<poscliente;cont1++){
                    if(carro[cont].prioridade > carro[cont1].prioridade){
                        aux = carro[cont].prioridade;
                        carro[cont].prioridade=carro[cont1].prioridade;
                        carro[cont1].prioridade=aux;
                        strcpy(name,carro[cont].nome);
                        strcpy(carro[cont].nome,carro[cont1].nome);
                        strcpy(carro[cont1].nome,name);
                        strcpy(tel,carro[cont].telefone);
                        strcpy(carro[cont].telefone,carro[cont1].telefone);
                        strcpy(carro[cont1].telefone,tel);
                        strcpy(tag,carro[cont].placa);
                        strcpy(carro[cont].placa,carro[cont1].placa);
                        strcpy(carro[cont1].placa,tag);
                        type = carro[cont].tipo;
                        carro[cont].tipo=carro[cont1].tipo;
                        carro[cont1].tipo = type;
                        aspirator = carro[cont].aspirador;
                        carro[cont].aspirador = carro[cont1].aspirador;
                        carro[cont1].aspirador = aspirator;
                        service = carro[cont].servico;
                        carro[cont].servico = carro[cont1].servico;
                        carro[cont1].servico = service;
                    }
                }
            }
            listagem();
}
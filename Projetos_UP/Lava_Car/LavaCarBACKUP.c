#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ncarros 5 //Constante para Facilitar na hora dos testes
#define charmax 100 // Constante para numeros de characteres em uma string
struct carro
{
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
void exporta();
//void pesquisa();
int prioridade();
void listaprioridades();
void crescente();
void decrescente();
//void aloca();
int poscliente=0; // Variável que indica a posição do cliente na ordem de cadastro, se comporta como um contador.
void main()
{
    menu();
}
void menu()
{   
    system("clear");
    int selec=0;
    printf("####### MENU DO LAVA CAR #######\n");
    printf("Para selecionar uma opção digite:\n");
    printf("\t1-) Cadastro de Clientes;\n\t2-) Listar Cadastros;\n\t3-) Listar Prioridades;\n\t4-) Exportar Dados;\n");
    printf("\t5-) SAIR\n");
    scanf("%d",&selec);
    getchar();
    switch(selec)
    {
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
            //printf("Esse Menu é para exportar dados!\n");
            exporta();
            break;
        case 5:
            system("clear");
            exit(EXIT_SUCCESS);
            break;
        default:
            system("clear");
            menu();
    }
}
void cadastro()
{
    char aspira='c';
    printf("############## Menu do LavaCar ##############\n");
    printf("Insira o Nome do Cliente %d:\n",poscliente+1);
    scanf("%[^\n]s",carro[poscliente].nome);
    getchar();
    printf("Insira o telefone do Cliente %d:\n",poscliente+1);
    scanf("%[^\n]s",carro[poscliente].telefone);
    getchar();
    printf("Insira a Placa do Carro:\n",poscliente+1);
    scanf("%[^\n]s",carro[poscliente].placa);
    getchar();
    REFAZCARRO: printf("Insira o Tipo do Carro do Cliente %d:\n",poscliente+1);
    printf("Digite: \n 1 para carro Hatch;\n 2 para carro Sedan;\n 3 para Motos;\n 4 para Vans.\n");
    scanf("%d",&carro[poscliente].tipo);
    getchar();
    if(carro[poscliente].tipo>4 || carro[poscliente].tipo<1) goto REFAZCARRO;
    REFAZLAVA: printf("Selecione o Tipo de Lavagem que você deseja:\n");
    printf("Pressione 1 para Lavagem Completa;\nou,\nPressione 2 Para Lavagem Ecológica\n");
    scanf("%d",&carro[poscliente].servico);
    getchar();
    if(carro[poscliente].servico<1 || carro[poscliente].servico>2)  goto REFAZLAVA;
    REFAZASP: printf("Nessecita da passagem do Aspirador de Pó no interior do Veículo? \nS/N \n");
    scanf("%c",&aspira);
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
    // Ao fim de cada cadastro chama a função Alocação de memória. que testa a condição da struct
    //aloca();
    aspira = 'c'; 
    poscliente++;
    continuacadastro();
}
void continuacadastro()
{   
    char decisao;
    printf("Deseja continuar com o Cadastro? \n");
    printf("S/N \n");
    scanf("%c",&decisao);
    getchar();
    switch(decisao)
    {
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
void listagem()
{
    int cont=0;
    for(cont=0;cont<poscliente;cont++)
    {
        printf("\n############ Cliente %d #####################\n",cont+1);
        printf("O nome do cliente %d é: %s\n",cont+1,carro[cont].nome);
        printf("O número de telefone do cliente %d é: %s\n",cont+1,carro[cont].telefone);
        printf("O placa do carro do cliente %d é:%s\n",cont+1,carro[cont].placa);
        printf("O tipo do carro do cliente %d é: %d\n",cont+1,carro[cont].tipo);
        printf("O tipo de serviço requisitado pelo cliente %d é: %d\n",cont+1,carro[cont].servico);
        printf("O Cliente %d requisitou aspirador?(Num 1 = SIM, Num 0 = NÃO): %i\n",cont+1,-1*carro[cont].aspirador);
        printf("A Prioridade do Cliente %d é: %d",cont+1,carro[cont].prioridade);
    }
    printf("\nPressione enter para Retornar para o Menu! \n");
    getchar();
    menu();
}
void exporta()
{
    int cont;
    FILE *arquivo;
    arquivo = fopen("lavacar.txt","r+");
    if(arquivo==NULL)
        arquivo = fopen("lavacar.txt","w");
    else
        arquivo = fopen("lavacar.txt","a+");
   for(cont=0;cont<ncarros;cont++)
   {
       fprintf(arquivo,"\n-------------------------------------------------\n");
       fprintf(arquivo,"Nome do Cliente %d: %s \n",cont+1,carro[cont].nome);
       fprintf(arquivo,"Número de Telefone do Cliente %d: %s\n",cont+1,carro[cont].telefone);
       fprintf(arquivo,"Placa do Carro do Cliente %d: %s\n",cont+1,carro[cont].placa);
       fprintf(arquivo,"Tipo do Carro do Cliente %d: %d",cont+1,carro[cont].tipo);
   }
   fprintf(arquivo,"\n#==================================================#\n");
   printf("Dados Exportados ! \n");
   getchar();
   fclose(arquivo);
   menu();
}
/*
void pesquisa()
{
    
}
*/

int prioridade(int n,int m,int o)
{   //Variavel 'n' é para tipo do carro
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
void listaprioridades()
{
    int selec=0;
    printf("#################### Menu de prioridades ###############\n");
    printf("Insira 1 para listar de forma crescente;\n");
    printf("Insira 2 para listar de forma decrescente.\n");
    scanf("%d",&selec);
    getchar();
    switch(selec)
    {
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
void crescente()
{
     int cont=0,cont1=0,aux=0;
            char name[charmax],tel[charmax],tag[charmax];
            int type=0,service=0,aspirator=0;
            for(cont=0;cont<poscliente;cont++)
            {
                for(cont1=cont+1;cont1<poscliente;cont1++)
                {
                    if(carro[cont].prioridade < carro[cont1].prioridade)
                    {
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
void decrescente()
{
     int cont=0,cont1=0,aux=0;
            char name[charmax],tel[charmax],tag[charmax];
            int type=0,service=0,aspirator=0;
            for(cont=0;cont<poscliente;cont++)
            {
                for(cont1=cont+1;cont1<poscliente;cont1++)
                {
                    if(carro[cont].prioridade > carro[cont1].prioridade)
                    {
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
/*
void aloca()
{
    Esta função irá testar o mínimo do "VETOR" da struct. Se eu já estiver na posição final do vetor- 50 - e eu precisar cadastrar
    mais um cliente, o próprio programa irá alogar mais espaço na memória.
    //Exemplo:
    // ncarros = malloc();
 }
 */
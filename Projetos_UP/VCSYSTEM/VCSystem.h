#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
//#include<ncurses.h>
#include<locale.h>
#define sistemadados "SISTEMADADOS.txt"
#define sistemaprodutos "SISTEMAPRODUTOS.txt"
#define sistemaclientes "SISTEMACLIENTES.txt"
//char sistemadados[]={"/home/calebe94/VCSystem/SISTEMADADOS.txt"};
char *lestring(int min,int max){
	int tamanho = 0;
	if(max == 0)	max = BUFSIZ;
	char aux;
	char *string;
	string = (char *)malloc(tamanho);
	do{tamanho = 0;
	while((aux = getchar()) != '\n'){
	string = (char *)realloc(string,tamanho + 1*sizeof(char));
	string[tamanho++] = aux ;
	}
	}while(strlen(string)<min || strlen(string)>=max);
	string[tamanho++] = '\0';
	return realloc(string,sizeof(char)*tamanho);
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
  int verificasenha()
  {
    /*Verificar a passagem de Strings para funções*/
  	FILE *arquivo;
  	arquivo = fopen("SISTEMASENHAS.txt","r+");
  	if(arquivo == NULL){
      printf("Na pasta ""/VCSystem/"",\n ");
      printf("Compile o arquivo cadastra_senha-criptografiahexadecimal.c,\n");
      printf("E execute o arquivo executável gerado para gerar uma senha.\n");
      printf("\t\tAtenciosamente, Equipe SIGLEV!\n");
    }
  	char confirmpassword[100],password[100],*password1;
  	char username[30],confirmusername[30];
  	fread(username,sizeof(username),1,arquivo);
  	fread(confirmpassword,sizeof(confirmpassword),1,arquivo);
    do{
    printf("Insira o nome de Usuário:");
  	while(scanf("%s",confirmusername)==0){scanf("%s",confirmusername);getchar();}
  	password1 = (char*)getpass("Entre com sua senha:");
  	decriptar(confirmpassword,0xFACA);
  	strcpy(password,confirmpassword);
  	strcpy(confirmpassword,password1);
  	if(strcmp(password,confirmpassword) == 0){
      printf("Senha correta!\n");
      sleep(2);
      fclose(arquivo);
      return 1;
    }
  	else{
  		printf("Senha errada:\n");
      sleep(2);
      fclose(arquivo);
      return 0;
  	}
  }while(strcmp(confirmusername,username) != 0);
}
void mensagem(){
  system("clear");
  setlocale(LC_ALL,"");
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf("+------------------------------------------------------------+\n");
  printf("|VCSystem * BETA VERSION *%s",asctime(timeinfo));
  printf("+------------------------------------------------------------+\n");
}

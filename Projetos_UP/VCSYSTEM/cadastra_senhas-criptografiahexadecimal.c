#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
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
int main(void)
{
	FILE *arquivo;
	arquivo = fopen("/home/calebe94/Projetos/VCSystem/SISTEMASENHAS.txt","w");
	if(arquivo == NULL)
		printf("Deu bode!\n");
	char *password,*confirmpassword,senha[30],senha1[30];
	char username[30],confirmusername[30];
	system("clear");
	REFAZNOME:printf("Insira o nome de Usuário desejado:\t");
	while(scanf("%s",username) == 0)
		scanf("%s",username);
	printf("Confime o Nome de Usuário:\t");
	while(scanf("%s",confirmusername) == 0)
		scanf("%s",confirmusername);
	if(strcmp(username,confirmusername) == 0)
	{
		REFAZ:
		password = (char*)getpass("Entre com sua senha:");
		strcpy(senha,password);
		confirmpassword = (char*)getpass("Confirme sua senha:");
		strcpy(senha1,confirmpassword);
		if(strcmp(senha,senha1) == 0)	
		{	
			encriptar(senha,0xFACA);
			fwrite(username,sizeof(username),1,arquivo);
			fwrite(senha,sizeof(senha),1,arquivo);
			fclose(arquivo);
		}
		else
			goto REFAZ;
	}
	else
		goto REFAZNOME;
}


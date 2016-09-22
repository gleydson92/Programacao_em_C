#include<stdio.h>
int main(void){
	FILE *sudo = popen("sudo su","r");
	if(sudo == NULL)	printf("Deu ruim na Hora de Abrir!\n");
	else{
		sudo = popen("sudo cp ~/Projetos/PlayMyGamesOnLinux/MafiaII/MafiaII /opt/","w");
		if(sudo == NULL)	printf("Deu ruim na Hora de Mover!\n");
	}	
	pclose(sudo);
	printf("Fim do Programa!\n");
}

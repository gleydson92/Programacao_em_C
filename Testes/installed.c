#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void){
	char path[]={"/usr/bin/"},instalado[30];
	//system("which nome_do_pacote");
	snprintf(instalado,30,"%s%s",path,"atom");
	//if(access(path,_OK) == 0)
		printf("%d\n",access(path,F_OK));
	//else system("pacman -S opera");
	printf("Acabou!\n");
}

#include<stdio.h>
/*
//Método Com Manipulação de Arquivos
int main(void){
	FILE *distro;
	char distros[1024];
	distro = fopen("/etc/lsb-release","r");
	if(distro == NULL)	printf("Sem permissão para Abrir o Arquivo!\n");
	while(!feof(distro))	fgets(distros,1024,distro);
	printf("%s\n",distros);
}*/
/*
// Método com UTSNAME
#include <sys/utsname.h>
int main(void){
	char distro[1024];
	struct utsname Distro;
	uname(&Distro);
	printf("Sysname:%s\n",Distro.sysname);
	printf("Nodename:%s\n",Distro.nodename);
	printf("Release:%s\n",Distro.release);
	printf("Version:%s\n",Distro.version);
	printf("Machine:%s\n",Distro.machine);
	printf("Domainname:%s\n",Distro.__domainname);
}*/
#include<stdlib.h>
#include<string.h>
int main(void){
FILE *distro;
	char distros[1024]="";
	const char Arch[]={"\"Arch Linux\""};
	//printf("%s\n",Arch);
	distro = popen("/usr/bin/lsb_release -ds","r");
	if(distro == NULL)	printf("Sem permissão para Abrir o Arquivo!\n");
//	while(!feof(distro))
	fgets(distros,1024,distro);
	if(strcmp(distros,Arch) == 10)
		printf("%s\n",distros);	
	else printf("Other Distro!\n");
	//printf("%s\n",distros);
	
	pclose(distro);
}

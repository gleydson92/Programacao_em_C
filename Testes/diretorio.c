#include <unistd.h>
#include <stdio.h>
#include<string.h>
int getCurrentDir(char *dir){
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL){
		strcpy(dir,cwd);	
		return 1;
	}else return 0;
}
int main() {
	char dir[1024];
	getCurrentDir(dir);
	printf("Seu diretorio atual é:%s\n",dir);
   return 0;
}

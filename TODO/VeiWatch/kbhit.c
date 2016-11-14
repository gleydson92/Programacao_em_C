#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <termios.h>
int kbhit(void);
int getch(void);
int getnum(void);
int main(void){
	while(1){
		//while(!kbhit()){}
		//int leitura=(int)getchar();
		//int leitura = getch()-48;
		int leitura = getnum();
		printf("Você pressionou '%d'!\n",leitura);	
		//char caractere = (char)leitura;		printf("Você pressionou '%c'!\n",caractere);	
	}	
}
int getnum(void){
	while(!kbhit()){}
	return getchar()-48;	
}
int getch(void){
	while(!kbhit()){}
	return getchar();
}
int kbhit(void){
  struct termios oldt, newt;
  int ch=0;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF){
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}

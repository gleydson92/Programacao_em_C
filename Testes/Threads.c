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
struct arg_struct{
	int row;
	int col;
};
void *testThread(void *argumentos){
	struct arg_struct *args = argumentos;
	while(1){
		printf("Mensagem C/ Thread!\n");
		while(!kbhit()){} 
		getchar();
		printf("Linha:%d\tColuna;%d\n",args->row++,args->col++);
	}
	//	printf("Você pressionou '%c'!\n",getchar());		
	pthread_exit(NULL);
}

int main(void){
	pthread_t thread;
	int threadcriada;
	struct arg_struct args;
	args.row = 5;
	args.col = 7;
	threadcriada = pthread_create(&thread,NULL,testThread,(void*)&args);
	while(1){
		printf("Mensagem S/ Thread!\n");
		while(!kbhit()){}	printf("Você pressionou '%c'!\n",getchar());	
		printf("Linha:%d\tColuna;%d\n",args.row++,args.col++);
	}
}
int kbhit(void){
  struct termios oldt, newt;
  int ch=0;
  int oldf;
  static int chamada;
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

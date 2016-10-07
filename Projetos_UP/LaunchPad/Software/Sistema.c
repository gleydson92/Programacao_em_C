#include"Sistema.h"
int MIDILogo(char *cMenssagen){
	unsigned int iSize=0;
	system("clear -all");

	printf(" __                    _             _ \n");
	printf("|  |   ___ _ _ ___ ___| |_ ___ ___ _| |\n");
	printf("|  |__| .'| | |   |  _|   | . | .'| . |\n");
	printf("|_____|__,|___|_|_|___|_|_|  _|__,|___|\n");
	printf("                          |_|          \n");

	printf("\t\t\t\t ___ __  ____  ____  ____\n");
	printf("\t\t\t\t(   V  )(_  _)(  _ |(_  _)\n");
	printf("\t\t\t\t )    (  _)(_  )(_) )_)(_ \n");
	printf("\t\t\t\t(__V V_)(____)(____/(____)\n");
	
	iSize = printf("%s\n",cMenssagen);
	return iSize;
}
int my_system (const char *command){
  int status;
  pid_t pid;
  pid = fork ();
  if (pid == 0){
      execl (SHELL, SHELL, "-c", command, NULL);
      _exit (EXIT_FAILURE);
  }else if (pid < 0)    status = -1;
  else
	  if (waitpid (pid, &status, 0) != pid)		status = -1;
  return status;
}

int getch(void){
	while(!kbhit()){}
	return getchar();
}

int getnum(void){
	while(!kbhit()){}
	return getchar()-48;	
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

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
/* Execute the command using this shell program.  */
#define SHELL "/bin/sh"

int my_system (const char *command)
{
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
int main(int argc,char *argv[]){
	for(register unsigned int cont = 1 ; cont < 5 ; cont++){
		for(register unsigned int cont1 = 1 ; cont1 < 5 ; cont1 ++){
			char type[1024];
			snprintf(type,1024,"aplay -q ~/Projetos/MIDI/Software/Tones/%d%d.wav",cont,cont1);
			my_system(type);	
		}		
	}
}

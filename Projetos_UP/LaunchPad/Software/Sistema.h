#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <termios.h>
#include <sys/wait.h>

#define SHELL "/bin/sh"

int my_system (const char *command);

int kbhit(void);

int getnum(void);

int getch(void);

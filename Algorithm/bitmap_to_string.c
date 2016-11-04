#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *p, *pp;
    int c;
    char d[4];

    p = fopen("logo_arduino.bmp","rb");
    
    for (int x = 1; x<=4; x++)
    {
      fseek(p, 6-x, 0);
      c = getc(p);
      d[x-1] = c;
      printf("%d ", d[x-1]);
    }

    fclose(p);
    printf ("\n");
  
    //system("PAUSE");    
    return 0;
}

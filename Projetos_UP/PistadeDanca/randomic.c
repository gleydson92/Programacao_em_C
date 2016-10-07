#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
   int i, n;
   time_t t;
   n = 5;
   srand((unsigned) time(&t));
   for( i = 0 ; i < n ; i++ ) 
      printf("%d\n",1+rand()%2);
   return(0);
}

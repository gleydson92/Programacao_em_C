#include<ncurses.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
void display(char jogada[3][3]){
	system("clear");
   printf("   1   2   3   Y\n");
   printf(" 1 %c | %c | %c \n",jogada[0][0],jogada[0][1],jogada[0][2]);
   printf("  ---|---|--- \n ");
   printf("2 %c | %c | %c \n",jogada[1][0],jogada[1][1],jogada[1][2]);
   printf("  ---|---|--- \n ");
   printf("3 %c | %c | %c \n",jogada[2][0],jogada[2][1],jogada[2][2]);	/*printf("%c|\t",jogada[row][col]);
	if(col == 0){	
		printf("\n");
	}*/
}
int main(void){
	char play[3][3];
	while(1){
		for(int count = 0 ; count < 3 ; count ++){
			for(int count1 = 0 ; count1 < 3 ; count1++){
				play[count][count1] = getchar();
				display(play);
			}
		}
	}
}

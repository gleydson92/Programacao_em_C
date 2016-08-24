#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
void display(char jogada[3][3]){
	system("clear");
	printf("  %c  |  %c  |  %c  \n",jogada[0][0],jogada[0][1],jogada[0][2]);
	printf("----+----+----\n");
	printf("  %c  |  %c  |  %c \n",jogada[1][0],jogada[1][1],jogada[1][2]);
	printf("----+----+----\n");
	printf("  %c  |  %c  |  %c\n",jogada[2][0],jogada[2][1],jogada[2][2]);
}
int main(void){
	while(1){
		for(int count = 0 ; count < 3 ; count ++){
			char play[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
			for(int count1 = 0 ; count1 < 3 ; count1++){
				display(play);
				play[count][count1] = getchar();
			}
		}
	}
}

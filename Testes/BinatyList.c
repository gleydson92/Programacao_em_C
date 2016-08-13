#include<stdio.h>
int main(void){
	for(int iCount=0;iCount<256;iCount++){
		printf("%d em Binario = ",iCount);
		for(int cont=0;cont<8;cont++){
			printf("%d",!!(iCount&(1 <<(7-cont))));
		}
		printf("\n");
	}
}

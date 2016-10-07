#include"FilaCircular.c"
int main(void){
	fila fila;
	int cheio=10;
	if(iniciar(cheio,&fila)==false)	printf("Deu Problema no iniciar()!\n");
	for(int cont = 9 ; cont >= 0 ; cont--)
			push(9-cont,cont,&fila);
	if(cheia(fila)){
		printf("Fila Cheia!\n");
		printf("%d\n",fila.col[fila.fim-1]);
		printf("Fila.fim:%d\n",fila.fim);
	}
	else	printf("Fila não está Cheia!\n");
	/*for(int cont = fila.inicio ; cont < fila.fim ; cont++)
		printf("Linha:%d Coluna:%d\n",fila.row[cont],fila.col[cont]);
	for(int cont = fila.inicio;cont<fila.fim-3;cont++)	pop(&fila);	
	printf("\n\n");
	for(int cont = fila.inicio ; cont < fila.fim ; cont++)
		printf("Linha:%d Coluna:%d\n",fila.row[cont],fila.col[cont]);*/
	int linha,coluna;
	for(int cont = fila.inicio;cont < fila.fim;cont++){
		pop(&fila,&linha,&coluna);
		printf("\tInicio:%d \n",fila.inicio);
		printf("Linha:%d \tColuna:%d\n",	linha,coluna);
	}
	if(vazia(fila))	printf("Fila Vazia!\n");
	else	printf("Fila ainda Contêm elementos!\n");
}

#include"FilaCircular.h"
bool iniciar(unsigned int tamanho,fila *qual){
	qual->tamanho = tamanho;
	qual->row = (int*)malloc(sizeof(int)*tamanho);
	qual->col = (int*)malloc(sizeof(int)*tamanho);
	qual->run = (int*)malloc(sizeof(int)*tamanho);
	if(qual->row == NULL || qual->col == NULL || qual->run == NULL)	return false;
	qual->fim = 0;
	qual->inicio = 0;
	return qual->row!=0;
}
bool encerrar(fila *qual){
	free(qual->row);
	free(qual->col);
	free(qual->run);
}
bool push(unsigned int row,unsigned int col, fila *qual){
	if(cheia(*qual))	return false;
	else{
		qual->col[qual->fim] = col;
		qual->row[qual->fim] = row;
		qual->fim++;
		return true;
	}
}
bool pop(fila *qual,unsigned int *row, unsigned int *col){
	if(vazia(*qual))	return false;
	else{
		*row = qual->row[qual->inicio];	
		*col = qual->col[qual->inicio];
		qual->inicio++;
		return true;
	}
}
bool listar(fila qual,unsigned int *qtde, unsigned int *row, unsigned int *col){
	int *retorno;
	int iCount = 0,iCountinicio=0;
	*qtde = (qual.fim>=qual.inicio)? qual.fim - qual.inicio:qual.tamanho-(qual.inicio-qual.fim);
	if(*qtde != 0){
		row = (int*)malloc(sizeof(int)*(*qtde));
		col = (int*)malloc(sizeof(int)*(*qtde));
		for(iCount = 0, iCountinicio = qual.inicio ; iCount < *qtde ; iCount++, iCountinicio++){
			if(iCountinicio == qual.tamanho)	iCountinicio = 0;
			row[iCount] = qual.row[iCountinicio];
			col[iCount] = qual.col[iCountinicio];	
		}
	}else	return false;
}
bool cheia(fila qual){
	if(qual.fim == qual.tamanho && qual.inicio < 2 || qual.fim == qual.inicio-1)	return true;
	else return false;
}
bool vazia(fila qual){
	if(qual.inicio == qual.fim)	return true;
	else return false;
}

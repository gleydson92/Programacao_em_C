#include"FilaCircular.h"
bool iniciar(unsigned int tamanho,fila *qual){
	qual->tamanho = tamanho;
	qual->elementos = (int*)malloc(sizeof(int)*tamanho);
	qual->fim = qual ->inicio =0;
	return qual->elementos!=0;
}
bool push(int info,fila *qual){ // Para fila Linear 
	if(cheia(*qual))	return false;
		qual->elementos[qual->fim] = info;
		qual->fim++;
		return true;
}
bool pop(fila *qual){
	if(vazia(*qual))	return false;
	qual->inicio++;
	return true;
}
int	*listar(fila qual,unsigned int *qtde){
	int *retorno;
	int iCount = 0,iCountinicio=0;
	*qtde = (qual.fim>=qual.inicio)? qual.fim - qual.inicio:qual.tamanho-(qual.inicio-qual.fim);
	retorno = (int*)malloc(sizeof(int)*(*qtde));
	for(iCount = 0, iCountinicio = qual.inicio ; iCount < *qtde ; iCount++, iCountinicio++){
		if(iCountinicio == qual.tamanho)	iCountinicio = 0;
		retorno[iCount] = qual.elementos[iCountinicio];
	}
	return retorno;
}
bool cheia(fila qual){
	if(qual.fim == qual.tamanho && qual.inicio < 2 || qual.fim == qual.inicio-1)	return true;
	else return false;
}
bool vazia(fila qual){
	if(qual.inicio == qual.fim)	return true;
	else return false;
}

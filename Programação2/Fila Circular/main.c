#include"FilaCircular.h"
#include<unistd.h>
#include<string.h>
char music[4][4][30]={"11.wav","12.wav","13.wav","14.wav",
					  "21.wav","22.wav","23.wav","24.wav",
					  "31.wav","32.wav","33.wav","34.wav",
					  "41.wav","42.wav","43.wav","44.wav"};
bool getCurrentDir(char *dir){
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL){
		strcpy(dir,cwd);	
		return true;
	}else return false;
}
bool songControl(unsigned const int row, unsigned const int col){
	FILE *ton;
	/*	*Denecessário chamar a função getCurrentDir() toda vez que songControl é chamada,
	  	 Logo, ao final dos testes se faz necessário criar uma variável global com o diretório atual
			char DIR[1024];
			getCurrentDir(DIR);
		*O Ponteiro para arquivo "FILE *ton" talvez precisará ser um vetor de ponteiros para arquivo de 4(quatro)
		posições pois serão executados até 4 sons simultaneamente. 
			FILE *ton[4]; 
		Logo o protótipo da função "songControl()" deverá possuir um novo atributo para identificar quantos sons 
		que já estão sendo executados.
			songControl(unsigned const int row, unsigned const int col, unsigned const int POS);
	*/
	char CUR_DIR[1024],TONE_DIR[1024];
	if(!getCurrentDir(CUR_DIR))	return false;
	else	snprintf(TONE_DIR,1024,"mplayer %s/Tones/%d%d.wav",CUR_DIR,row+1,col+1);
	printf("%s\n",TONE_DIR);
	//ton	= popen(TONE_DIR,"w");
	// Deverá haver o pclose(ton); não sei como... mas tem que existir.
}
int main(void){
	fila fila1;
	int iTamanho=10;
	iniciar(iTamanho,&fila1);
	for(int cont = 0 ; cont < 10;cont++)
			push(cont,&fila1);
	int itens=0;
	listar(fila1,&itens);
	for(int cont=fila1.inicio;cont<fila1.fim;cont++){
		printf("%d\n",fila1.elementos[cont]);
		printf("Quantidade de Itens:%d\n",itens);
	}
	for(int cont=fila1.inicio;cont<7;cont++)		
		pop(&fila1);
	int *lista=listar(fila1,&itens);
	printf("\n\n\tRemoção de Itens!\n\n");
	for(int cont=fila1.inicio;cont<fila1.fim;cont++){
		printf("%d\n",*lista++);
		//printf("%d\n",fila1.elementos[cont]);
		printf("Quantidade de Itens:%d\n",itens);
	}
	printf("\n\n\tRemoção de Itens!\n\n");
	for(int cont = fila1.inicio;cont<fila1.fim;cont++){		
		lista=listar(fila1,&itens);
		pop(&fila1);
		printf("%d\n",*lista);
		printf("Quantidade de Itens:%d\n",itens);
	}
	if(vazia(fila1)==true)	printf("\tLista Vazia!\n");
	else	printf("\tLista Não Vazia!\n");
	printf("\n\n\tInserindo Outras Coisas na Lista Na lista\n\n");
	
	for(int cont = 9 ; cont >= 0;cont--)
			push(cont,&fila1);
	listar(fila1,&itens);
	for(int cont=fila1.inicio;cont<fila1.fim;cont++){
		printf("%d\n",fila1.elementos[cont]);
		printf("Quantidade de Itens:%d\n",itens);
	}
	if(cheia(fila1)==true)	printf("Lista cheia Novamente!\n");
	else	printf("Lista não está cheia ! \n");
	printf("Teste das Músicas!\n");
	for(int cont=0;cont<4;cont++)
		for(int cont1=0;cont1<4;cont1++)	songControl(cont,cont1);
}

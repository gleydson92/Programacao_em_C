#include"RaspberryGPIO.h"
#include"FilaCircular.h"
#include<stdint.h>
#include<string.h>
#include<pthread.h>
#include"Sistema.h"
/*
const uint8_t colLed[4]={21,20,16,12};
const uint8_t rowLed[4]={26,19,13,6};
const uint8_t colBot[4]={25,24,23,18};
const uint8_t rowBot[4]={5,17,22,27};
*/
// VETORES ALTERADOS PARA A PCB 

const uint8_t colLed[4]={22,10,9,11};
const uint8_t rowLed[4]={3,14,17,27};
const uint8_t colBot[4]={23,24,25,8};
const uint8_t rowBot[4]={4,2,15,18};

const uint8_t botTocar = 19 , botGravar = 26;
const uint8_t letTocar = 20 , ledGravar = 16;


char CUR_DIR[1024],TONES_DIR[30];

struct Argumentos{
	unsigned int row;
	unsigned int col;
};

fila sFila[4]; // Inicialização da Fila

bool getCurrentDir();
void *buttonVerify();

bool ledControl(uint8_t row, uint8_t col, uint8_t state){
	state == HIGH?HIGH:LOW;
	if(!GPIOWrite(rowLed[row],!state)) return false;
	if(!GPIOWrite(colLed[col],state)) return false;
	else return true;
}
void *songControl(void *sFilas);
int main(void){
	MIDILogo("\n\nDeseja Iniciar o Programa S[1]/N[0] ?\n");

	unsigned int iInicia;
	
	do{iInicia = getnum();}while((iInicia<0)||iInicia>2);

	if(iInicia == 1){
		printf("Exportando Terminais...\n");	
		GPIOSetup(colLed[0],SAIDA);	GPIOSetup(colLed[1],SAIDA);	GPIOSetup(colLed[2],SAIDA);	GPIOSetup(colLed[3],SAIDA);	
		GPIOSetup(rowLed[0],SAIDA); GPIOSetup(rowLed[1],SAIDA); GPIOSetup(rowLed[2],SAIDA); GPIOSetup(rowLed[3],SAIDA);
		GPIOSetup(colBot[0],ENTRADA); GPIOSetup(colBot[1],ENTRADA); GPIOSetup(colBot[2],ENTRADA); GPIOSetup(colBot[3],ENTRADA);
		GPIOSetup(rowBot[0],SAIDA); GPIOSetup(rowBot[1],SAIDA); GPIOSetup(rowBot[2],SAIDA); GPIOSetup(rowBot[3],SAIDA);
		printf("Terminais Exportados!!!\n");

		pthread_t pBotControl,pSongControl[4];

		if(pthread_create(&pBotControl,NULL,buttonVerify,NULL)){
			printf("Não Conseguiu Criar a Thread para o Controle dos Botões!\n");
			return 0;
		}

		struct Argumentos col[4];
		for(register unsigned int iCount=0;iCount<4;iCount++){
			col[iCount].col = iCount;
			if(pthread_create(&pSongControl[iCount],NULL,songControl,(void*)&col[iCount])){
				printf("Não Conseguiu Criar a Thread %d para o Controle dos Tons!\n",iCount);
				return 0;
			}
			if(iniciar(100,&sFila[iCount])==false){
				printf("Problemas ao iniciar a Fila %d!\n",iCount);
				return 0;
			}
		}
		
		int iSelec = 10;

		do{
			MIDILogo("\n\nInsira uma Opção:\n");
			printf("[1]-Skrillex_-_Bangarang\n");
			printf("[2]-Skrillex_-_Cinema\n");
			printf("[3]-Skrillex_-_First Of The Year\n");
			printf("[4]-Avicii_-_Levels (Skrillex Remix)\n");
			printf("[5]-Clássicos dos GAMES\n");//Até a conversão dos sons Para .wav
			iSelec = getnum();//scanf("%d",&iSelec);
			if(iSelec == 1) strcpy(TONES_DIR,"Bangarang");
			else if(iSelec == 2) strcpy(TONES_DIR,"Cinema");
			else if(iSelec == 3) strcpy(TONES_DIR,"FOTY");
			else if(iSelec == 4) strcpy(TONES_DIR,"Levels");
			else if(iSelec == 5) strcpy(TONES_DIR,"Sons");
			else	strcpy(TONES_DIR,"Levels");
	 	}while(iSelec != 0);
		for(register unsigned int iCount=0;iCount<4;iCount++){
			encerrar(&sFila[iCount]);
			if(pthread_cancel(pSongControl[iCount])!=0)	printf("Não Cancelou a Thread %d \n",iCount);
			GPIOUnexport(colLed[iCount]);
			GPIOUnexport(colBot[iCount]);
			GPIOUnexport(rowLed[iCount]);
			GPIOUnexport(rowBot[iCount]);
		}
		return EXIT_SUCCESS;
	}else	return EXIT_SUCCESS;
}

bool getCurrentDir(char *dir){
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL){
		strcpy(dir,cwd);	
		return true;
	}else return false;
}

void *buttonVerify(){
	while(1){
		for(register unsigned int iRow = 0 ; iRow < 4 ; iRow++){
			for(register unsigned int iCol = 0; iCol < 4; iCol++){
				GPIOWrite(rowBot[iRow],HIGH);
				if(GPIORead(colBot[iCol])==HIGH){
					while(GPIORead(colBot[iCol])==HIGH){}
					push(iRow,iCol,&sFila[iCol]);
				}
			}
			GPIOWrite(rowBot[iRow],LOW);
		}
	}
}

void *songControl(void *sFilas){
	while(1){
		struct Argumentos *Arg = sFilas;
		unsigned int iThreadCol = Arg->col,row,col;
		if(cheia(sFila[iThreadCol])==true && sFila[sFila->fim-1].run == (int*)1){
			sFila->inicio = 0;
			sFila->fim = 0;
		}
		if(vazia(sFila[iThreadCol])==false){
			pop(&sFila[iThreadCol],&row,&col);
			if(strcmp(TONES_DIR,"\0") == 0){ // PISCA LED 3 VEZES
				printf("Nenhum Som Associado!\n");
				unsigned int estado = HIGH;
				for(register unsigned int cont=0 ; cont < 6 ; cont ++){
					ledControl(row,col,estado);
					delay_ms(500);
					estado = !estado;
				}
			}else{
				ledControl(row,col,HIGH); //LED ON
				char TONE_DIR[1024];
				snprintf(TONE_DIR,1024,"aplay -q %s/Tones/%s/%d%d.wav",CUR_DIR,TONES_DIR,row+1,col+1);
				my_system(TONE_DIR);
				my_system("clear");
				sFila[iThreadCol].run = (int*)1;
				ledControl(row,col,LOW);//LED OFF
			}
		}
	}
}

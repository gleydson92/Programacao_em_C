### To Do ###

	**************FEITO*********************
%Implementar a fila nas Threads
*Exemplo:
 ...
struct arg_struct {
    int arg1;
    int arg2;
};
...
void *print_the_arguments(void *arguments){
struct arg_struct *args = arguments;

	args -> arg1;
	args -> arg2;
}
...
int main(){
	struct arg_struct args;
	...
   pthread_create(&some_thread, NULL, &print_the_arguments, (void *)&args);
...
	**************FEITO*********************

	**************FEITO*********************
# Encontrar novos tocadores de Músicas 
	* aplay(ALSA):	aplay [flags] [filename [filename]]
				aplay a.wav	
				-q --quiet:	Quiet mode. Suppress messages (not sound :))
	* play(sox):	play something.wav
	* vlc:	cvlc --play-and-exit something.wav	
			cvlc something.wav
	* mplayer 
	**************FEITO*********************

	**************FEITO*********************
% Alterar os Vetores dos Terminais GPIO:
	GPIO02 - 2 linha botão
	GPIO03 - 1 linha led
	GPIO04 - 1 linha botão
	GPIO14 - 2 linha led
	GPIO15 - 3 linha botão
	GPIO17 - 3 linha led
	GPIO18 - 4 linha botão
	GPIO27 - 4 linha led
	

	GPIO22 - 1 coluna led
	GPIO23 - 1 coluna botão
	GPIO24 - 2 coluna botão
	GPIO10 - 2 coluna led
	GPIO09 - 3 coluna led
	GPIO25 - 3 coluna botão
	GPIO11 - 4 coluna led 
	GPIO08 - 4 coluna botão


	GPIO19 - botão tocar
	GPIO26 - botão gravar
	GPIO16 - led gravando
	GPIO20 - led tocando
	**************FEITO*********************

	**************FEITO*********************
% Retirar a tentativa de leitura simultânea dos Botões
	**************FEITO*********************

	**************FEITO*********************
% Inserir Fila e Threads para a execução dos Tons
	**************FEITO*********************

	**************FEITO*********************
% Inserir a Função kbhit() para a leitura das Opções de Pasta
	**************FEITO*********************

% Inserir as funções: Gravar Toques e Reproduzir Toques utilizando os botões botTocar,botGravar e LEDS ledGravar e ledTocar

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
	while(1){
		FILE *ton;
		ton	= popen("mplayer ~/Projetos/MIDI/Software/Tones/11.wav","w");
		ton	= popen("mplayer ~/Projetos/MIDI/Software/Tones/12.wav","w");
		ton = popen("mplayer ~/Projetos/MIDI/Software/Tones/13.wav","w");
		ton = popen("mplayer ~/Projetos/MIDI/Software/Tones/14.wav","w");
		usleep(1000000);
	}
}

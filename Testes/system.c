#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	for(register unsigned int cont = 1 ; cont < 5 ; cont++){
		for(register unsigned int cont1 = 1 ; cont1 < 5 ; cont1 ++){
			char type[1024];
			snprintf(type,1024,"aplay -q ~/Projetos/MIDI/Software/Tones/%d%d.wav",cont,cont1);
			system(type);	
		}		
	}
}

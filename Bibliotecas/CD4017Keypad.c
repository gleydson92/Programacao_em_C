#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
typedef struct{
	unsigned int row,col,clock,keyOut,keyNumber,initialised;
}keyInit;
keyInit *keyPads[8];
int CDInit(const uint8_t rows,const uint8_t cols,const uint8_t clockPin,const uint8_t readPin){
	static unsigned int iInitialised = 0;
	int keyFd = -1;
	keyInit *key;
	if(iInitialised == 0){
		iInitialised = 1;
		for(register unsigned int iCount=0;iCount<8;iCount++)	keyPads[iCount] == NULL;
	}
	for(register unsigned int iCount=0;iCount<8;iCount++){
		if(keyPads[iCount] == NULL){
			keyFd = iCount;
			break;
		}
	}
	if(keyFd == -1)	return -1;
	key = (keyInit*)malloc(sizeof(keyInit));
	key->row = rows;
	key->col = cols;
	key->clock = clockPin;
	key->keyOut=readPin;
	key->initialised = 1;
	key->keyNumber = key->row*key->col;
	keyPads[keyFd] = key;
	GPIOSetup(key->clock,OUTPUT);
	GPIOSetup(key->keyOut,INPUT);
	GPIOWrite(key->clock,LOW);
	return keyFd;
}
unsigned int CDRead(const uint8_t fd){
	keyInit *newPad = keyPads[fd];
	unsigned const int clockPin = newPad->clock;
	unsigned const int readPin = newPad-> keyOut;
	if(newPad->initialised == 0)	return 0;
	static unsigned int iCount=0;
	for (iCount;iCount<newPad->keyNumber;iCount++){
			while(iCount == 16)	iCount = 0;
			GPIOWrite(clockPin,HIGH);
			if(GPIORead(readPin)==HIGH){
				while(GPIORead(readPin)==HIGH){}
				return iCount;
			}
	}
}
int main(){
	int keyControll = 0,keyPressed;
	keyControll = CDInit(4,4,2,3);
	keyPressed=CDRead(keyControll);
}x

/******************************************************************************************************
	Autor(es): Edimar Calebe Castanho
		   Vanessa Castro Eler
		   Luan Janckovsky
		   Julle(kkkkkkkkk) Gleydson 
	Participação Especial: Lenon Christians 
	Matrícula: 1521998
	Projeto: Contador Binário.
	
#Comentários: Retirei as definições Macros: HIGH e LOW para manter os valores 0 e 1, assim posso usar
para a escrita os próprios valores binários armazenados no vetor.
******************************************************************************************************/
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#define ENTRADA 1
#define SAIDA 	0

bool GPIOexport(int pino);
bool GPIOdirection(int pino, int direcao);
bool GPIOWrite(int pino,int valor);
bool GPIORead(int pino);
bool GPIOUnexport(int pino);
void binario();
int main(void)
{	
	GPIOexport(14);
	GPIOexport(15);
	GPIOexport(18);
	GPIOexport(23);
	GPIOexport(25);
	GPIOdirection(14,SAIDA);
	GPIOdirection(15,SAIDA);
	GPIOdirection(18,SAIDA);
	GPIOdirection(23,SAIDA);
	GPIOdirection(25,ENTRADA);
	int decimal = 0,binario[4],resto=0;
	while(1)
	{
		for(int cont = 0; cont<4;cont++)
			binario[cont]=0;
		int cont = 0;
		while(decimal!=0)
		{
			resto = decimal%2;
			binario[cont] = resto == 0? 0:1;
			decimal = decimal/2;
			cont++;
		}
		if(GPIORead(25)==1)		
		{
			GPIOWrite(14,binario[0]);
			GPIOWrite(15,binario[1]);
			GPIOWrite(18,binario[2]);
			GPIOWrite(23,binario[3]);
			decimal++;
		}
	}
	GPIOUnexport(14);
	GPIOUnexport(15);
	GPIOUnexport(18);
	GPIOUnexport(23);
	GPIOUnexport(25);
}
bool GPIOexport(int pino)
{
	char buffer[3];
	int arquivo;
	arquivo = open("/sys/class/gpio/export",O_WRONLY);
	if( arquivo == -1)
		return false;
	snprintf( buffer, 3 , "%d", pino);
	if( write(arquivo,buffer,3) == -1 )
	{	
		close(arquivo);
		return false;
	}
	close(arquivo);
	return true;	
}
bool GPIOUnexport(int pino)
{
	char buffer[3];
	int arquivo;
	arquivo = open("/sys/class/gpio/unexport",O_WRONLY);
	if( arquivo == -1)
		return false;
	snprintf( buffer, 3 , "%d", pino);
	if( write(arquivo,buffer,3) == -1 )
	{	
		close(arquivo);
		return false;
	}
	close(arquivo);
	return true;	
}
bool GPIOdirection(int pino,int direcao)
{
	char caminho[35];
	int arquivo;
	
	snprintf(caminho,35,"/sys/class/gpio/gpio%d/direction",pino);
	if(arquivo == -1)
		return false;
if( write(arquivo,(direcao == ENTRADA)?"in":"out",(direcao== ENTRADA)?2:3) == -1 )
{
	close(arquivo);
	return false;
}
close(arquivo);
return true;
}
bool GPIOWrite(int pino,int valor)
{
	char caminho[35];
	int arquivo;
	
	snprintf(caminho,35,"/sys/class/gpio/gpio%d/value",pino);
	if(arquivo == -1)
		return false;
	if( write(arquivo,(valor == 1)?"1":"0",1) == -1 )
	{
		close(arquivo);
		return false;
	}
	close(arquivo);
	return true;	
}
bool GPIORead(int pino)
{
	char caminho[35];
	int arquivo;
	char retorno[2];
	snprintf(caminho,35,"/sys/class/gpio/gpio%d/value",pino);
	if(arquivo == -1)
		return false;
	if( read(arquivo,retorno,2)==-1)
	{
		close(arquivo);
		return false;
	}	
	close(arquivo);
	return (int)retorno[0]-48;	
	//return retorno[0]-'0';
}

#include <stdio.h>
#include <time.h>
#include <string.h>
char *format(int number){		
	char 	*retorno,ret[100];
	int 	i;

	if (number < 10){
		sprintf(ret,"0%d",number);
		retorno = ret;
		return retorno;
	}
	else{
		sprintf(ret,"%d",number);
		retorno = ret;
		return retorno;
	}
}		
char *data(void){

	int dia,mes,ano;
	char	
		var1[100],
		var2[100],
		var3[100],
		var4[100],
		*dataPtr;
	struct tm *local;
	time_t t;

	t = time(NULL);
	local = localtime(&t);

	dia = local -> tm_mday;
	mes = local -> tm_mon + 1;
	ano = local -> tm_year + 1900;

	sprintf(var1,"%s",format(dia));
	sprintf(var2,"%s",format(mes));
	sprintf(var3,"%s",format(ano));

	sprintf(var4,"%s/%s",var1,var2);

	dataPtr = var4;
	return dataPtr;
}

char *hora(void){
		
	int	hora,minuto,segundo;
	char	
		var1[100],
		var2[100],
		var3[100],
		var5[100],
		*retorno;
	struct tm *local;
	time_t t;

	t = time(NULL);
	local = localtime(&t);
		
	// obtem hora, minuto e segundo e os aloca em uma variavel do tipo inteiro
	hora	=	local -> tm_hour;
	minuto	= 	local -> tm_min;
	segundo =	local -> tm_sec;
	
	// por algum motivo precisa converter os valores retornados pelos ponteiros
	// da funcao em variaveis do tipo char
	sprintf(var1,"%s",format(hora));
	sprintf(var2,"%s",format(minuto));
	sprintf(var3,"%s",format(segundo));
	
	// cria a variavel de retorno dos dados e cria um ponteiro para essa variavel
	sprintf(var5,"%s:%s",var1,var2);
	
	// retorna hora no formato hh:mm:ss com um ponteiro
	retorno = var5;
	return retorno;	
}

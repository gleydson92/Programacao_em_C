/*
Considere um arquivo binário de registros (denominado “alunos.bin”) onde
cada registro armazena as seguintes informações sobre um aluno qualquer
de uma turma de, no máximo, 50 alunos: matrícula (cadeia de 3 caracteres),
nome (cadeia de 30 caracteres) e três notas referentes às avaliações feitas
pelo aluno (valores reais entre 0 e 10). Faça um programa que leia este
arquivo e apresente a matrícula, o nome, a nota média (a soma das três
notas dividida por três) e o conceito (“excelente” se a média for maior ou igual
a 8.5, “bom” se a média for maior ou igual a 7.0 e menor que 8.5, e
“preocupante” se a média for menor que 7.0) de cada aluno da turma.
*/
#include<stdio.h>
#include<string.h>
struct aluno{
	int matricula;
	char nome[30];
	int nota1;
	int nota2;
	int nota3;
	int media;
}aluno[50];
int main(void){
	FILE *alunos;
	alunos = fopen("alunos.bin","r");
	int contador=0;
	if(alunos == NULL){
		printf("Houve problemas Ao abrir o Arquivo ! \n");
		strcpy(aluno[0].nome,"Edimar");
		aluno[0].matricula = 123;
		aluno[0].nota1=85;
		aluno[0].nota2=aluno[0].nota1;
		aluno[0].nota3=65;
		alunos = fopen("alunos.bin","w+");
		fwrite(&aluno[0],sizeof(struct aluno),1,alunos);
	}
	while(!feof(alunos)){
		fread(&aluno[contador],sizeof(struct aluno),1,alunos);
		contador++;
	}
	for(int cont=0;cont<contador-1;cont++){
	aluno[cont].media=(aluno[cont].nota1+aluno[cont].nota2+aluno[cont].nota3)/3;
	printf("Contador:%d\n",contador);
	printf("Aluno:%s\tMatricula:%d\tNota1:%d\t\tNota2:%d\t\tNota3:%d\n\t\tMedia:%d\n",aluno[cont].nome,aluno[cont].matricula,aluno[cont].nota1,aluno[cont].nota2,aluno[cont].nota3,aluno[cont].media);
	}
	fclose(alunos);
}

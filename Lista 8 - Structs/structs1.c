/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 04/04/2022
	
	Structs
*/

//importação de bibliotecas
#include <stdio.h>

//definição de tipos
typedef struct {
	char nome[30];
	float av1, av2, media;
	char situacao[15];
} TALuno;

//main
void main ()
{
	//declaração de variáveis
	TAluno aluno;
	
	//preenchendo os campos da variável 'aluno'
	printf ("Nome: ");
	gets (aluno.nome);
	
	printf ("AV1: ");
	scanf ("%f", &aluno.av1);
	
	printf ("AV2: ");
	scanf ("%f", &aluno.av2);
	
	//calculando a média do aluno
	aluno.media = (aluno.av1 + aluno.av2)/2;
	
	if (aluno.media >= 6)
	{
		strcpy (aluno.situacao, "APROVADO");
	}
	else
	{
		if (aluno.media < 4)
		{
			strcpy (aluno.situacao, "REPROVADO");
		}
		else
		{
			strcpy (aluno.situacao, "AVF");
		}
	}
}

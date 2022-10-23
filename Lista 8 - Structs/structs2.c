/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 04/04/2022
	
	Vetor de Structs
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define QUANT 3

//definição de tipos
typedef struct {
	char nome[30];
	float av1, av2, media;
	char situacao[15];
} TAluno;

//main
void main ()
{
	//declaração de variáveis
	TAluno turma[QUANT];
	int i;
	
	//preenchendo os dados dos 30 alunos
	for (i=0;i<QUANT;i++)
	{
		//preenchendo os campos da variável 'aluno'
		fflush (stdin);
		printf ("Nome: ");
		gets (turma[i].nome);
		
		printf ("AV1: ");
		scanf ("%f", &turma[i].av1);
		
		printf ("AV2: ");
		scanf ("%f", &turma[i].av2);
		
		//calculando a média do aluno
		turma[i].media = (turma[i].av1 + turma[i].av2)/2;
		
		if (turma[i].media >= 6)
		{
			strcpy (turma[i].situacao, "APROVADO");
		}
		else
		{
			if (turma[i].media < 4)
			{
				strcpy (turma[i].situacao, "REPROVADO");
			}
			else
			{
				strcpy (turma[i].situacao, "AVF");
			}
		}
	}
}

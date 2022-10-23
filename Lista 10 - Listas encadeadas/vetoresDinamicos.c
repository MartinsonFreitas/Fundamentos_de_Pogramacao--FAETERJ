/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR
	2022/1  -  Turma: Noite
	
	Data: 30/05/2022
	
	Ponteiros
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//main 
void main ()
{
	//declaração de variáveis
	int *v;			//declaração do vetor (sem alocar memória para o mesmo)
	int tamanho;
	
	//leitura da tamanho de elementos do vetor
	printf ("Entre com o tamanho do vetor: ");
	scanf ("%d", &tamanho);
	
	//alocar memória para o vetor já declarado
	v = (int*) malloc (tamanho*sizeof(int));    ///memory alocation	
	
	if (v == NULL)
	{
		printf ("\nNao foi possivel alocar a memoria solicitada!");
	}
	else
	{
		.
		.
		.
	}
}

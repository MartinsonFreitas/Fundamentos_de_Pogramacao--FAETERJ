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
	int **m;			//declaração do vetor (sem alocar memória para o mesmo)
	int linha, coluna, i;
	
	//leitura das dimensões da matriz
	printf ("Entre com o numero de linhas: ");
	scanf ("%d", &linha);
	
	printf ("Entre com o numero de colunas: ");
	scanf ("%d", &coluna);

	//alocando memória dinamicamente para a matriz
	
	//1. Alocando o número de linhas da matriz
	m = (int**) malloc (linha*sizeof(int*));
	
	//2. Para cada linha da matriz, alocar a quantidade de colunas
	for (i=0;i<linha;i++)
	{
		m[i] = (int*) malloc (coluna*sizeof(int));	
	}	
	
	.
	.
	.
}

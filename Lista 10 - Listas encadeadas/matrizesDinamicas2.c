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
	
	//1. Alocando o número de linhas da matriz
	m = (int**) malloc (10*sizeof(int*));
	
	//2. Para cada linha da matriz, alocar a quantidade de colunas
	for (i=0;i<linha;i++)
	{
		m[i] = (int*) malloc ((i+1)*sizeof(int));	
	}	
	
	.
	.
	.
}

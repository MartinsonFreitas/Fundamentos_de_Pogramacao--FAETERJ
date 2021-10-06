/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 20/09/2021
	
	MATRIZES
	
	Exemplo 1: Desenvolver uma função que zere os elementos de uma matriz M10x5
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 10
#define C 5

//protótipos/cabeçalhos das funções
void zerar (int matriz[L][C]);
void exibir (int matriz[L][C]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int m[L][C];
	
	//exibindo a matriz
	exibir (m);	
	
	//zerando a matriz
	zerar (m);
	
	//exibindo a matriz
	exibir (m);	
}

//implementação das demais funções
void zerar (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo todas as posições da matriz
	for (i=0;i<L;i++)			//percorrendo todas as linhas da matriz
	{
		for (j=0;j<C;j++)		//percorrendo todas as colunas da matriz
		{
			//zerar cada elemento da matriz
			matriz[i][j] = 0;
		}
	}
}


void exibir (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo todas as posições da matriz
	for (i=0;i<L;i++)			//percorrendo todas as linhas da matriz
	{
		for (j=0;j<C;j++)		//percorrendo todas as colunas da matriz
		{
			printf ("%11d ", matriz[i][j]);
		}
		printf ("\n");
	}	
	printf ("\n\n");
}

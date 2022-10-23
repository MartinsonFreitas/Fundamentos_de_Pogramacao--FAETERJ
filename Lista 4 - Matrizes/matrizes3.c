/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 20/09/2021
	
	MATRIZES
	
	Exemplo 3: Desenvolver uma função que preencha uma matriz 30x20 com números aleatórios (função rand).

*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define L 30
#define C 20

//protótipos/cabeçalhos das funções
void preencherAleatorio (int matriz[L][C]);
void exibir (int matriz[L][C]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int m[L][C];
	
	//preenchendo a matriz
	preencherAleatorio (m);
	
	//exibindo a matriz
	exibir (m);	
}

//implementação das demais funções
void preencherAleatorio (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	srand (time(NULL));
	
	//percorrendo todas as posições da matriz
	for (i=0;i<L;i++)			//percorrendo todas as linhas da matriz
	{
		for (j=0;j<C;j++)		//percorrendo todas as colunas da matriz
		{
			matriz[i][j] = 1+rand()%100; //preenchendo a matriz com valores aleatórios no intervalo de 1 a 100
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
			printf ("%3d ", matriz[i][j]);
		}
		printf ("\n");
	}	
	printf ("\n\n");
}

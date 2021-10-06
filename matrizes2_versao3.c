/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 20/09/2021
	
	MATRIZES
	
	Exemplo 2: Desenvolver uma função que armazene o valor 1 em todas as posições da 1ª linha 
	           de uma matriz 20 x 15, o número 2 na 2ª, e assim por diante.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 20
#define C 15

//protótipos/cabeçalhos das funções
void preencherOrdenado (int matriz[L][C]);
void exibir (int matriz[L][C]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int m[L][C];
	
	//preenchendo a matriz
	preencherOrdenado (m);
	
	//exibindo a matriz
	exibir (m);	
}

//implementação das demais funções
void preencherOrdenado (int matriz[L][C])
{
	//declaração de variáveis
	int i, j, numero;
	
	//percorrendo todas as posições da matriz
	for (i=0;i<L;i++)			//percorrendo todas as linhas da matriz
	{
		numero = i+1;
		for (j=0;j<C;j++)		//percorrendo todas as colunas da matriz
		{
			matriz[i][j] = numero;
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

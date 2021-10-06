/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 27/09/2021
	
	Lista de Exercícios IV - Matrizes
	
	QUESTÃO 03:
	Desenvolver uma função que gere a seguinte matriz M5x5:

			1	2	3	4	5	
			2	3	4	5	6	
			3	4	5	6	7	
			4	5	6	7	8	
			5	6	7	8	9	
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define L 5
#define C 5

//protótipos/cabeçalhos das funções
void exibir (int matriz[L][C]);

void geraMatriz(int matriz[L][C]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int m[L][C];
		
	//gerando a matriz conforme o enunciado
	geraMatriz (m);
	
	//exibindo a matriz
	exibir (m);	
}

//implementação das demais funções
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

void geraMatriz(int matriz[L][C])
{
	//declaração de variáveis
    int i, j;
    
    for (i = 0; i < L; i++)
    {
        for (j = 0; j < C; j++)
        {
            matriz[i][j] = i + j + 1;
        }
    }
}

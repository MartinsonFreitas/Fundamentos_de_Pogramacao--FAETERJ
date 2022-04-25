/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 27/09/2021
	
	Lista de Exercícios IV - Matrizes
	
	QUESTÃO 04:
	Fazer uma função que, dada uma matriz M6×6, determine se ela é simétrica.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define L 6
#define C 6

#define TRUE 1
#define FALSE 0

//protótipos/cabeçalhos das funções
int determinaSimetrica (int matriz[L][C]);

void exibir (int matriz[L][C]);
void preencherAleatorio (int matriz[L][C]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int m1[L][C];
	int m2[L][C] = { {5,4,2,6,7,8},
	                 {4,3,4,8,1,1},
	                 {2,4,3,6,4,7},
	                 {6,8,6,5,1,4},
	                 {7,1,4,1,2,7},
	                 {8,1,7,4,7,5} };


	//gerando a matriz m1 aleatoriamente
	preencherAleatorio (m1);
	
	//exibindo a matriz m1
	exibir (m1);
	
	if (determinaSimetrica (m1) == TRUE)
	{
		printf ("\nA matriz m1 e' simetrica!\n");
	}
	else
	{
		printf ("\nA matriz m1 nao e' simetrica!\n");
	}
	
	//exibindo a matriz m2
	exibir (m2);
	
	if (determinaSimetrica (m2) == TRUE)
	{
		printf ("\nA matriz m2 e' simetrica!\n");
	}
	else
	{
		printf ("\nA matriz m2 nao e' simetrica!\n");
	}
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

int determinaSimetrica (int matriz[L][C])
{
	//declaração de variáveis
    int i, j;//, cont = 0;
    
    for ( i = 0; i < L; i++)
    {
        for ( j = 0; j < C; j++)
        {
        	//cont++;
            if ( matriz[i][j] != matriz [j][i] )
            {
            	//printf ("\n\nforam feitas %d comparacoes\n\n", cont);
                return FALSE;
            }            
        }        
    }
    
    //printf ("\n\nforam feitas %d comparacoes\n\n", cont);
    return TRUE;
}

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


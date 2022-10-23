/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 27/09/2021
	
	Lista de Exercícios IV - Matrizes
	
	QUESTÃO 02:
	Desenvolver uma função que, dada uma matriz M15×20, determine se um número X se encontra na linha L 
	da matriz.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define L 15
#define C 20

#define TRUE 1
#define FALSE 0

//protótipos/cabeçalhos das funções
void preencherAleatorio (int matriz[L][C]);
void exibir (int matriz[L][C]);

int buscaNumero (int matriz[L][C], int linha, int numero);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int m[L][C];
	int valor, linha;
	
	//preenchendo a matriz com números aleatórios
	preencherAleatorio (m);
	
	//exibindo a matriz
	exibir (m);	
	
	//perguntando o número a ser buscado na matriz
	printf ("\n\nQual numero deseja buscar? ");
	scanf ("%d", &valor);
	
	//perguntando em qual linha o elemento será buscado
	printf ("\n\nEm qual linha deseja buscar? ");
	scanf ("%d", &linha);
		
	//chamando a função e exibindo o resultado
	if (buscaNumero (m, linha, valor) == TRUE)
	{
		printf ("\nO valor %d foi encontrado na linha %d da matriz", valor, linha);
	}
	else
	{
		printf ("\nO valor %d nao foi encontrado na linha %d da matriz", valor, linha);
	}
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

int buscaNumero (int matriz[L][C], int linha, int numero)
{
    //declaração de variáveis
	int j;
    
    //percorrendo a linha da matriz
    for (j=0;j<C;j++)
    {
       	//verificando se está na linha desejada
        if (matriz[linha][j]==numero)
        {
        	return TRUE;
        }
    }
    
	return FALSE;
}

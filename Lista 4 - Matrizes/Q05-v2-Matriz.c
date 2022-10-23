/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	Data: 27/09/2021
	
	Lista de Exercícios IV - Matrizes
	
	QUESTÃO 05:
	Implementar uma função que, dada uma matriz M10×8, gere um vetor V de tamanho 8, onde cada elemento 
	do vetor consiste na soma dos elementos de uma coluna de M. Ou seja, o elemento V[0] consiste na soma 
	dos elementos da primeira coluna de M, o elemento V[1] consiste na soma dos elementos da segunda 
	coluna de M, e assim por diante.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define L 10
#define C 8

//protótipos/cabeçalhos das funções
void geraSomaColuna (int matriz [L][C], int v[C]);

void exibirMatriz (int matriz[L][C]);
void exibirVetor (int vetor[], int tamanho);
void preencherAleatorio (int matriz[L][C]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int m[L][C];
	int vet[C];

	//gerando a matriz aleatoriamente
	preencherAleatorio (m);
	
	//exibindo a matriz m
	exibirMatriz (m);
	
	//chamando a função 
	geraSomaColuna (m, vet);
	
	//exibindo o vetor resultado
	exibirVetor (vet, C);
}

//implementação das demais funções
void exibirMatriz (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\n");
	
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

void exibirVetor (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\n");
	
	//percorrendo todas as posições do vetor
	for (i=0;i<tamanho;i++)			
	{
		printf ("%3d ", vetor[i]);
	}

	printf ("\n\n");
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

void geraSomaColuna (int matriz [L][C], int v[C])
{
	//declaração de variáveis
    int i,j;
    
    //calculando as somas, como descrito no enunciado    
    for (j=0;j<C;j++)
    {
    	v[j] = 0;
        for (i=0;i<L;i++)
        {
            v[j]+=matriz[i][j];   //v[j] = v[j] + matriz[i][j];
        }
    }    
}

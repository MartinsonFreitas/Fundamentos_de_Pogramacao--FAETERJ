/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 20/09/2021
	
	MATRIZES
	
	Exemplo 5: Desenvolver uma função que determine o número de ocorrências de um número na linha L 
			   de uma matriz M50x20
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define L 50
#define C 20

//protótipos/cabeçalhos das funções
void preencherAleatorio (int matriz[L][C]);
void exibir (int matriz[L][C]);

int buscaNumero (int matriz[L][C], int linha, int numero);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int m[L][C];
	int valor, qdade, linha;
	
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
		
	//chamando a função
	qdade = buscaNumero (m, linha, valor);
	
	//exibindo o resultado
	printf ("\nO valor %d foi encontrado %d vezes na linha %d da matriz", valor, qdade, linha);
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
	int i,j,qtvezes=0;
    
    //percorrendo a matriz
    for ( i = 0; i < L; i++)
    {
        for ( j = 0; j < C; j++)
        {
        	//verificando se está na linha desejada
        	if (i == linha)		//solução muito cara, pois percorre sem necessidade toda a matriz (ao invés de percorrer apenas a linha desejada)
        	{
        		if (matriz[i][j]==numero)
        		{
            		qtvezes++;
        		}
        	}
        }        
    }
    
	return qtvezes;
}

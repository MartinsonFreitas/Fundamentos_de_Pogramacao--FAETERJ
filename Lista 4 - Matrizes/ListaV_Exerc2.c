/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 28/03/2022
	
	Lista de Exercícios V (matrizes):
	
	QUESTÃO 02: Desenvolver uma função que, dada uma matriz M15×20, 
	determine se um número X se encontra na linha L da matriz.  
	
	versão 1: não eficiente, pois percorre toda a matriz ao invés de 
	percorrer apenas os elementos da linha desejada.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 15
#define C 20

//protótipos das funções
int verificaOcorrencia (int m[L][C], int linha, int numero);

void preencher (int m[L][C]);
void exibir (int m[L][C]);

//main
void main ()
{
	//declaração de variáveis
	int matriz[L][C], resp;
	
	//preenchendo a matriz com números aleatórios
	preencher (matriz);
	
	//exibindo a matriz
	printf ("Exibindo a matriz:\n\n");
	exibir (matriz);
	
	//chamando a função
	resp = verificaOcorrencia (matriz, 3, 10);
	
	//exibindo o resultado
	if (resp == 1)
	{
		printf ("\n\nElemento encontrado na linha desejada.");
	}
	else
	{
		printf ("\n\nElemento nao encontrado na linha desejada.");
	}
}

//implementação das funções
int verificaOcorrencia (int m[L][C], int linha, int numero)
{
	//declaração de variáveis
	int i, j;
	
	//varrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//varrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			//verificando se está na linha desejada
			if (i == linha)
			{
				//verificando se o elemento foi encontrado
				if (m[i][j] == numero)
				{
					return 1;
				}
			}
		}
	}
	
	//se chegou neste ponto, o numero nao foi encontrado.
	return 0;
}

void preencher (int m[L][C])
{
	//declaração de variáveis
	int i, j;

	//garantindo que as sequências aleatórias são diferentes
	srand (time(NULL));
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			m[i][j] = rand()%20 + 1;
		}
	}
}

void exibir (int m[L][C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
}

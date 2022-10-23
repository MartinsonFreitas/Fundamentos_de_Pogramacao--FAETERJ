/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 04/04/2022
	
	Lista de Exercícios V (matrizes):
	
	QUESTÃO 05:
	
	Implementar uma função que, dada uma matriz M10×8, gere um vetor V 
	de tamanho 8, onde cada elemento do vetor consiste na soma dos 
	elementos de uma coluna de M. Ou seja, o elemento V[0] consiste na 
	soma dos elementos da primeira coluna de M, o elemento V[1] consiste 
	na soma dos elementos da segunda coluna de M, e assim por diante.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 10
#define C 8

//protótipos das funções
void calcularVetorSoma (int m[L][C], int v[C]);

void preencher (int m[L][C]);
void exibirMatriz (int m[L][C]);
void exibirVetor (int v[], int tamanho);

//main
void main ()
{
	//declaração de variáveis
	int matriz[L][C], vetor[C];
	
	//preenchendo a matriz com números aleatórios
	preencher (matriz);
	
	//exibindo a matriz 
	printf ("Exibindo a matriz:\n\n");
	exibirMatriz (matriz);
	
	//chamando a função
	calcularVetorSoma (matriz, vetor);
	
	//exibindo o resultado
	exibirVetor (vetor, C);
}

//implementação das funções
void calcularVetorSoma (int m[L][C], int v[C])
{
	//declaração de variáveis
	int i, j, soma;
	
	//varrendo as colunas da matriz
	for (j=0;j<C;j++)
	{
		//para cada coluna da matriz, zerar o somatório
		soma = 0;
		
		//varrendo as linhas da matriz
		for (i=0;i<L;i++)
		{
			soma = soma + m[i][j];
		}
		
		//armazenando o somatório no vetor
		v[j] = soma;
	}
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

void exibirMatriz (int m[L][C])
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

void exibirVetor (int v[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nElementos do vetor: ");
	
	for (i=0;i<tamanho;i++)
	{
		printf ("%d ", v[i]);
	}
}

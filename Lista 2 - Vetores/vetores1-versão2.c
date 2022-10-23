/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 13/09/2021
	
	Revisão - FAC   [vetores e funções]
	
	1. desenvolver uma função que leia 100 valores para um vetor
	
	[versão 2: implementando a função de forma que possa receber vetores de diferentes tamanhos.]
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TAM1 5
#define TAM2 10

//protótipos/cabeçalhos das funções
void leitura (float vetor[], int tamanho);
void exibir (float vetor[], int tamanho);

//implementação da função main
void main ()
{
	//declaração de variáveis
	float v1[TAM1], v2[TAM2];
	
	//lendo valores para o vetor v1, e exibindo o vetor
	leitura (v1, TAM1);
	exibir (v1, TAM1);
	
	//lendo valores para o vetor v2, e exibindo o vetor
	leitura (v2, TAM2);
	exibir (v2, TAM2);
}

//implementação das demais funções
void leitura (float vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//leitura dos valores
		printf ("Entre com um numero: ");
		scanf ("%f", &vetor[i]);
	}
}

void exibir (float vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nVetor: ");
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//exibindo os valores do vetor
		printf ("%.1f ", vetor[i]);
	}
	
	printf ("\n");
}

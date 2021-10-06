/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 13/09/2021
	
	Revisão - FAC   [vetores e funções]
	
	desenvolver uma função que preencha um vetor com números randômicos/aleatórios
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define TAM 10000

//protótipos/cabeçalhos das funções
void preencherAleatorio (int vetor[], int tamanho);
void exibir (int vetor[], int tamanho);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	
	//preenchendo o vator com números aleatórios, e exibindo o vetor
	preencherAleatorio (v, TAM);
	exibir (v, TAM);
}

//implementação das demais funções
void preencherAleatorio (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	srand (time(NULL));
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//gerando um novo número aleatório e armazenando-o no vetor
		vetor[i] = 1 + rand()%100;   // % : resto da divisão
		//rand(): gerando aleatoriamente um número inteiro positivo
		//rand()%100: gerando aleatoriamente um número inteiro positivo no intervalo de 0 a 99
		//1 + rand()%100: gerando aleatoriamente um número inteiro positivo no intervalo de 1 a 100
	}
}

void exibir (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nVetor: ");
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//exibindo os valores do vetor
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n");
}

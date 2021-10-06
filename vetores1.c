/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 13/09/2021
	
	Revisão - FAC   [vetores e funções]
	
	1. desenvolver uma função que leia 100 valores para um vetor
	
	[versão 1: deixando o vetor com tamanho fixo na declaração do parâmetro.
	Problema: a função só funcionará se a main passar um vetor exatamente do tamanho definido na função.]
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TAM 100

//protótipos/cabeçalhos das funções
void leitura (int vetor[TAM]);
void exibir (int vetor[TAM]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	
	leitura (v);
	exibir (v);
}

//implementação das demais funções
void leitura (int vetor[TAM])
{
	//declaração de variáveis
	int i;
	
	//variando todas as posições do vetor
	for (i=0;i<TAM;i++)
	{
		//leitura dos valores
		printf ("Entre com um numero: ");
		scanf ("%f", &vetor[i]);
	}
}

void exibir (int vetor[TAM])
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nVetor: ");
	
	//variando todas as posições do vetor
	for (i=0;i<TAM;i++)
	{
		//exibindo os valores do vetor
		printf ("%.1f ", vetor[i]);
	}
	
	printf ("\n");
}

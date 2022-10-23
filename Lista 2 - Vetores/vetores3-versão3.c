/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 13/09/2021
	
	Revisão - FAC   [vetores e funções]
	
	desenvolver uma função que preencha um vetor de tamanho 'tam' com os números de 1 a 'tam'.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TAM 10000

//protótipos/cabeçalhos das funções
void preencher (int vetor[], int tamanho);
void exibir (int vetor[], int tamanho);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	
	//preenchendo o vetor, e exibindo-o
	preencher (v, TAM);
	exibir (v, TAM);
}

//implementação das demais funções
void preencher (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
		
	//variando as demais posições do vetor
	for (i=1;i<=tamanho;i++)
	{
		vetor[i-1] = i;
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

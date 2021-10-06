/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 13/09/2021
	
	Revisão - FAC   [vetores e funções]
	
	desenvolver uma função que inverta os elementos de um vetor.

	Exemplo:
			vetor antes da inversão:
			1  2  3  4  5  6  7  8  9  10
			
			vetor depois da inversão:
			10  9  8  7  6  5  4  3  2  1	           

*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TAM 100

//protótipos/cabeçalhos das funções
void preencherAleatorio (int vetor[], int tamanho);
void exibir (int vetor[], int tamanho);

void inverter (int vetor[], int tamanho);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int v[TAM];
		
	//preenchendo o vetor, e exibindo-o
	preencherAleatorio (v, TAM);
	exibir (v, TAM);
	
	//chamando a função
	inverter (v, TAM);
	
	//exibindo o vetor após a inversão
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
		vetor[i] = 1 + rand()%50;
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

void inverter (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i, j, aux;
	
	for (i=0,j=tamanho-1;i<j;i++,j--)
	{
		//trocando os elementos que estão nas posições 'i' e 'j'
		aux = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = aux;
	}
}

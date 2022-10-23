/*
	FAC - 2021/1
	Data: 24/06/2021
	
	Lista de Exercícios X
	
	QUESTÃO 02:
	Implementar uma função que, dado um vetor de reais, troque o 1º e o 2º elementos, 
	em seguida o 3º e o 4º elementos e assim sucessivamente, até se chegar ao final 
	do vetor.
	
	Exemplos:
	
	suponha o seguinte vetor com 10 elementos
		vet: 1  2  3  4  5  6  7  8  9  0
		vet: 2  1  4  3  6  5  8  7  0  9

	suponha o seguinte vetor com 5 elementos
		vet: 1  2  3  4  5 
		vet: 2  1  4  3  5
*/

//importação de bibliotecas
#include<stdio.h>

//definição de constantes
#define TAMANHO 11

//protótipos das funções
void preencheVetor (float vetor[], int quant);
void exibirVetor (float vetor[], int quant);

void trocar (float vetor[], int quant);

//main
void main()
{
	//declaração de variáveis
	float vet[TAMANHO];

	//preenchendo o vetor
	preencheVetor (vet, TAMANHO);
	
	//antes da troca
	printf ("\nAntes da troca:\n");
	exibirVetor (vet, TAMANHO);
	
	//chamando a função de troca
	trocar (vet, TAMANHO);

	//depois da troca
	printf ("\nDepois da troca:\n");
	exibirVetor (vet, TAMANHO);
}

//implementação das funções
void preencheVetor (float vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//garantindo que cada sequência de valores gerados será diferente
	srand(time(NULL));
	
	//gerando números aleatórios com a função 'rand'
	for (i=0;i<quant;i++)
	{
		vetor[i] = (float)(rand()%50)+1; //gerando números aleatórios de 1 a 50
	}		
}

void exibirVetor (float vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//exibindo os elementos do vetor
	printf ("\n\nElementos do vetor: ");
	
	for (i=0;i<quant;i++)
	{
		printf ("%.1f ", vetor[i]);
	}
	
	printf ("\n\n");
}

void trocar (float vetor[], int quant)
{
	//declaração de variáveis
	int i, j;
	float aux;
	
	for (i=0, j=1; j<quant; i+=2, j+=2)
	{
		//trocando os valores que estão nas posições i e j
		aux = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = aux;
	}
}

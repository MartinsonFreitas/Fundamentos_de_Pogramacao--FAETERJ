/*
	FAC - 2021/1
	Data: 24/06/2021
	
	Lista de Exercícios X

	QUESTÃO 04:
	Fazer uma função que armazene em um vetor os 50 primeiros termos da seguinte 
	sequência:

							S = 1, 2, 4, 7, 11, 16, ...

	Nota: observem que a diferença entre o 1º e 2º elementos é igual a 1, entre o 2º 
	e 3º é igual a 2, entre o 3º e o 4º é igual a 3, e assim sucessivamente.
*/

//importação de bibliotecas
#include<stdio.h>

//declaração de constantes
#define TAM 50

//protótipos das funções
void exibirVetor (int vetor[], int quant);

void gerarSequencia (int vetor[], int quant);

//main
void main()
{
	//declaração de variáveis
	int vet[TAM];
	
	//preenchendo o vetor com a sequência
	gerarSequencia (vet, TAM);
	
	//exibindo o vetor
	exibirVetor (vet, TAM);
}

//implementação das funções
void exibirVetor (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//exibindo os elementos do vetor
	printf ("\n\nElementos do vetor: ");
	
	for (i=0;i<quant;i++)
	{
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n\n");
}

void gerarSequencia (int vetor[], int quant)
{
	//declaração de variáveis
	int i, j;
	
	//atribuindo o primeiro valor da sequência à primeira posição do vetor
	vetor[0] = 1;
	
	//preenchendo as demais posições do vetor
	for (i=0,j=1;j<quant;i++,j++)
	{
		vetor[j] = vetor[i] + j;	
	}	
}

							//S = 1, 2, 4, 7, 11, 16, ...


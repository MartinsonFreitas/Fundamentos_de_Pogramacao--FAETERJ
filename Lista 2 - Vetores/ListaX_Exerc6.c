/*
	FAC - 2021/1
	Data: 24/06/2021
	
	Lista de Exercícios X

	QUESTÃO 06:
	Faça uma função que, dado um vetor de reais, altere todas as ocorrências do 
	número A pelo número B.
*/

//importação de bibliotecas
#include<stdio.h>

//declaração de constantes
#define TAM 50

//protótipos das funções
void exibirVetor (float vetor[], int quant);
void preencheVetor (float vetor[], int quant);

int alterar (float vetor[], int quant, float numA, float numB);

//main
void main()
{
	//declaração de variáveis
	float vet[TAM];
	float num1, num2;
	int result;
	
	//preenchendo o vetor com números aleatórios
	preencheVetor (vet, TAM);
	
	//exibindo o vetor para o usuário
	exibirVetor (vet, TAM);
	
	//perguntando os valores ao usuário
	printf ("\n\nQual valor deseja alterar? ");
	scanf ("%f", &num1);
	
	printf ("\nPor qual valor deseja alterar? ");
	scanf ("%f", &num2); 	
	
	//chamando a função alterar
	result = alterar (vet, TAM, num1, num2);
	
	//exibindo o vetor depois da alteração
	exibirVetor (vet, TAM);

	//exibindo a quantidade de alterações realizadas
	printf ("\nForam realizadas %d substituicoes de %.1f pelo %.1f.\n", result, num1, num2);
}

//implementação das funções
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

int alterar (float vetor[], int quant, float numA, float numB)
{
	//declaração de variáveis
	int i, cont=0;
	
	//percorrendo todas as posições do vetor
	for (i=0;i<quant;i++)
	{
		//verificando se o numA foi encontrado
		if (vetor[i] == numA)
		{
			vetor[i] = numB;
			cont++;
		}
	}
	
	//retornando a quantidade de alterações realizadas
	return cont;
}

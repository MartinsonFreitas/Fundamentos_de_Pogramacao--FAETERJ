/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 13/09/2021
	
	Revisão - FAC   [vetores e funções]
	
	considerando um vetor com 'tam' números inteiros, determinar o maior e o menor elementos do conjunto.

	Exemplo:	vetor:  10 21 3 4 52 1 4 9 10 1 36
						maior: 52  /  menor: 1
*/

//importação de bibliotecas
#include <stdio.h>
#include <limits.h>

//definição de constantes
#define TAM 100

//protótipos/cabeçalhos das funções
void preencherAleatorio (int vetor[], int tamanho);
void exibir (int vetor[], int tamanho);

void determinarMaiorMenor (int vetor[], int tamanho, int *maior, int *menor);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	int maior, menor;
	
	//preenchendo o vetor, e exibindo-o
	preencherAleatorio (v, TAM);
	exibir (v, TAM);
	
	//chamando a função
	determinarMaiorMenor (v, TAM, &maior, &menor);
	
	//exibindo o resultado
	printf ("\nMaior: %d   -   Menor = %d", maior, menor);
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

void determinarMaiorMenor (int vetor[], int tamanho, int *maior, int *menor)
{
	//declaração de variáveis
	int i,
	    ma = INT_MIN,   //menor número inteiro armazenável
	    me = INT_MAX;	//maior número inteiro armazenável
	
	//percorrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//verificando se um número maior foi encontrado
		if (vetor[i] > ma)
		{
			ma = vetor[i];
		}
		else
		{
			//verificando se um número menor foi encontrado
			if (vetor[i] < me)
			{
				me = vetor[i];
			}			
		}
	}
	
	//retornando os valores
	*maior = ma;
	*menor = me;
}

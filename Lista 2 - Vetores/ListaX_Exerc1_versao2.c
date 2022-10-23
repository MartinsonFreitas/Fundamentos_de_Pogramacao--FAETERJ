/*
	FAC - 2021/1
	Data: 24/06/2021
	
	Lista de Exercícios X
	
	QUESTÃO 01:
	Desenvolver uma função que determine o número de ocorrências de um número 
	inteiro x em um vetor A.
*/

//importação de bibliotecas
#include<stdio.h>

//definição de constantes
#define TAMANHO 5

//protótipos das funções
int numOcorrencias (int numero, int vetor[TAMANHO]);
void preencheVetor (int vetor[TAMANHO]);

//main
void main()
{
	//declaração de variáveis
	int vet[TAMANHO];
	int resultado, valor;
	
	//preenchendo o vetor
	preencheVetor (vet);
	
	//perguntando ao usuário o valor a ser buscado
	printf ("\n\nQual valor deseja buscar no vetor? ");
	scanf ("%d", &valor);
	
	//chamando a função
	resultado = numOcorrencias (valor, vet);
	
	//exibindo o resultado
	printf ("Foram encontradas %d ocorrencias do numero %d no vetor.", resultado, valor);
}

//implementação das funções
int numOcorrencias (int numero, int vetor[TAMANHO])
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrer todas as posições do vetor
	//for (i=0;i<=TAMANHO-1;i++)
	for (i=0;i<TAMANHO;i++)
	{
		//comparar o numero sendo buscado com cada valor do vetor
		if (numero == vetor[i])
		{
			cont++;
		}
	}
	
	//retornando o resultado
	return cont;
}

void preencheVetor (int vetor[TAMANHO])
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor
	for (i=0;i<TAMANHO;i++)
	{
		printf ("Entre com um numero: ");
		scanf ("%d", &vetor[i]);
	}
}

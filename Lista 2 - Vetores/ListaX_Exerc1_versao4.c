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
#define TAMANHO1 5
#define TAMANHO2 10

//protótipos das funções
int numOcorrencias (int numero, int vetor[], int quant);
void preencheVetor (int vetor[], int quant);

//main
void main()
{
	//declaração de variáveis
	int vet1[TAMANHO1], vet2[TAMANHO2];
	int resultado, valor;
	
	//preenchendo os vetores
	printf ("Lendo valores para o primeiro vetor:\n");
	preencheVetor (vet1, TAMANHO1);

	printf ("\n\nLendo valores para o segundo vetor:\n");
	preencheVetor (vet2, TAMANHO2);
	
	//perguntando ao usuário o valor a ser buscado
	printf ("\n\nQual valor deseja buscar nos vetores? ");
	scanf ("%d", &valor);
	
	//chamando a função
	resultado = numOcorrencias (valor, vet1, TAMANHO1);
	
	//exibindo o resultado
	printf ("\nForam encontradas %d ocorrencias do numero %d no vetor1.", resultado, valor);

	//chamando a função
	resultado = numOcorrencias (valor, vet2, TAMANHO2);
	
	//exibindo o resultado
	printf ("\nForam encontradas %d ocorrencias do numero %d no vetor2.", resultado, valor);
}

//implementação das funções
int numOcorrencias (int numero, int vetor[], int quant)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrer todas as posições do vetor
	//for (i=0;i<=quant-1;i++)
	for (i=0;i<quant;i++)
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

void preencheVetor (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		printf ("Entre com um numero: ");
		scanf ("%d", &vetor[i]);
	}
}

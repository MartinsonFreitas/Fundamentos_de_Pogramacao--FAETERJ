/*
	FAC - 2021/1
	Data: 26/06/2021
	
	Lista de Exercícios X

	QUESTÃO 05:
	Elaborar uma função que, dado um conjunto de 300 valores inteiros, 
	distribua-os em 2 vetores conforme forem pares ou ímpares.
	
	Exemplo:
	
		vetor:		1  5  7  4  8  6  2  3  5  4  1  3
		            0  1  2  3  4  5  6  7  8  9 10 11 
				                                     i
		
		impar:		1  5  7  3  5  1  3
		auxI        0  1  2  3  4  5  6  7		
		
		par:        4  8  6  2  4
		auxP		0  1  2  3  4  5
*/

//importação de bibliotecas
#include<stdio.h>

//declaração de constantes
#define TAM 300

//protótipos das funções
void exibirVetor (int vetor[], int quant);
void preencheVetor (int vetor[], int quant);
void distribuirElementos (int orig[], int quantO, int pares[], int *quantP, int impares[], int *quantI);

//main
void main()
{
	//declaração de variáveis
	int vet[TAM], vetP[TAM], vetI[TAM];
	int contP, contI;

	//preenchendo o vetor aleatoriamente
	preencheVetor (vet, TAM);
	
	//exibindo o vetor original
	exibirVetor (vet, TAM);
	
	//chamando a função para criar os vetores de pares e ímpares
	distribuirElementos (vet, TAM, vetP, &contP, vetI, &contI);
	
	//exibindo os vetores vetP e vetI
	exibirVetor (vetP, contP);
	printf ("\n%d pares\n", contP);
	
	exibirVetor (vetI, contI);
	printf ("\n%d impares\n", contI);
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

void preencheVetor (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//garantindo que cada sequência de valores gerados será diferente
	srand(time(NULL));
	
	//gerando números aleatórios com a função 'rand'
	for (i=0;i<quant;i++)
	{
		vetor[i] = (rand()%100)+1; //gerando números aleatórios de 1 a 100
	}		
}

void distribuirElementos (int orig[], int quantO, int pares[], int *quantP, int impares[], int *quantI)
{
	//declaração de variáveis
	int i, auxP = 0, auxI = 0;
	
	//percorrendo o vetor original
	for (i=0;i<quantO;i++)
	{
		//verificando se o elemento é par ou ímpar
		if (orig[i] % 2 == 0)
		{
			//armazenando o elemento no vetor de pares
			pares[auxP] = orig[i];
			
			//incrementando o auxP que armazena a posição onde o próximo par deve ser inserido
			auxP++;
		}
		else
		{
			//armazenando o elemento no vetor de ímpares
			impares[auxI] = orig[i];

			//incrementando o auxI que armazena a posição onde o próximo ímpar deve ser inserido
			auxI++;
		}
	}
	
	//armazenando as quantidades de elementos de cada vetor em quantP e quantI
	*quantP = auxP;
	*quantI = auxI;
}

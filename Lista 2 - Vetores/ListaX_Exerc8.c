/*
	FAC - 2021/1
	Data: 01/07/2021
	
	Lista de Exercícios X

	QUESTÃO 08:
	Dados um vetor de reais (cujos elementos estão ordenados crescentemente) e 
	um número x, retornar a posição da primeira ocorrência de x (caso encontre-se 
	no vetor) ou a posição na qual deveria estar (caso contrário).
	
	Exemplos:
	
	vetor:   1   3   8   8   10   12   13   15
	         0   1   2   3   4    5    6    7 
	x: 8
			elemento encontrado: retornar a posição 2
				
	
	vetor:   1   3   8   8   10   12   13   15
	         0   1   2   3   4    5    6    7 
	x: 9
			elemento não encontrado: deveria estar na posição 4
	
	
	vetor:   1   3   8   8   10   12   13   15  
	         0   1   2   3   4    5    6    7  
	x: 20
			elemento não encontrado: deveria estar na posição 8
*/

//importação de bibliotecas
#include<stdio.h>

//declaração de constantes
#define TAM 20

//protótipos das funções
void exibirVetor (float vetor[], int quant);
void preencheVetorOrdenado (float vetor[], int quant);

int buscar (float vetor[], int quant, float x);

//main
void main()
{
	//declaração de variáveis
	float vet[TAM];
	float num;
	int result;
	
	//preenchendo o vetor aleatoriamente
	preencheVetorOrdenado (vet, TAM);
		
	//exibindo o vetor original
	exibirVetor (vet, TAM);
	
	//obtendo o valor a ser buscado
	printf ("Qual valor deseja buscar? ");
	scanf ("%f", &num);
	
	//chamando a função de remoção
	result = buscar (vet, TAM, num);

	//exibindo o resultado
	printf ("\nPosicao retornada: %d", result);	
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
		printf ("\n%.1f ", vetor[i]);
	}
	
	printf ("\n\n");
}

void preencheVetorOrdenado (float vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//garantindo que cada sequência de valores gerados será diferente
	srand(time(NULL));
	
	//inserindo o primeiro elemento do vetor
	vetor[0] = (float)(rand()%10)+1;    //o primeiro valor receberá um número entre 1 e 10
	
	//gerando números aleatórios com a função 'rand' para as demais posições
	for (i=1;i<quant;i++)
	{
		vetor[i] = vetor[i-1] + (float)(rand()%3); //gerando números aleatórios em função do anterior
	}		
}

int buscar (float vetor[], int quant, float x)
{
	//declaração de variáveis
	int i;
		
	//percorrendo todas as posições do vetor
	for (i=0;i<quant;i++)
	{
		//verificando se o elemento foi encontrado
		if (vetor[i] == x)
		{
			return i;
		}
		else
		{
			//se encontrar um valor maior do que x, conclui-se que este não está no vetor
			if (vetor[i] > x)
			{
				return i;				
			}
		}
	}
	
	//se chegou neste ponto, é pq o 'x' é maior do que todos os elementos
	return quant;
}

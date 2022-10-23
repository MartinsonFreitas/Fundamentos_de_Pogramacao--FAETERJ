/*
	FAC - 03/07/2021
	
	Lista XI 
	
	Questão 04:
	
	Implementar o algoritmo de busca binária apresentado na questão.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define TAM 1000

//protótipo das funções
int buscaBinaria (int vetor[], int quant, int valor);

void exibirVetor (int vetor[], int quant);
void preencheVetorOrdenado (int vetor[], int quant);

//main
void main ()
{
	//declaração de variáveis
	int vet[TAM];
	int numero, posicao;
	
	//inicializando o vetor
	preencheVetorOrdenado (vet, TAM);
	
	//exibindo o vetor
	exibirVetor (vet, TAM);		
	
	//perguntando ao usuário o valor a ser buscado
	printf ("\n\nQual valor deseja buscar? ");
	scanf ("%d", &numero);
	
	//chamando a função
	posicao = buscaBinaria (vet, TAM, numero);
	
	//testando se o elemento não foi encontrado
	if (posicao == -1)
	{
		printf ("\nO valor %d nao se encontra no vetor!\n", numero);
	}
	else
	{
		printf ("\nO valor %d se encontra na posicao %d do vetor!\n", numero, posicao);
	}	
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
		printf ("\n%d ", vetor[i]);
	}
	
	printf ("\n\n");
}

void preencheVetorOrdenado (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//garantindo que cada sequência de valores gerados será diferente
	srand(time(NULL));
	
	//inserindo o primeiro elemento do vetor
	vetor[0] = (rand()%10)+1;    //o primeiro valor receberá um número entre 1 e 10
	
	//gerando números aleatórios com a função 'rand' para as demais posições
	for (i=1;i<quant;i++)
	{
		vetor[i] = vetor[i-1] + (rand()%3) + 1; //gerando números aleatórios em função do anterior
	}		
}

int buscaBinaria (int vetor[], int quant, int valor)
{
	//declaração de variáveis
	int comeco, fim, meio;
	
	//inicialização
	comeco = 0;
	fim = quant-1;
	
	//enquanto existirem posições a serem percorridas e comparadas como valor...
	while (comeco <= fim)
	//for (comeco=0,fim=quant-1;comeco<=fim;)
	{
		//determinando a posição do elemento do meio
		meio = (comeco+fim)/2;
		
		//para visualizar os valores de comeco, meio e fim
		printf ("\n\t\tcomeco = %d, meio = %d, fim = %d", comeco, meio, fim);
		
		//verificando se o elemento do meio é o valor sendo buscado
		if (vetor[meio] == valor)
		{
			return meio;
		}
		else
		{
			//se o elemento do meio for maior do que o valor sendo buscado ...
			if (vetor[meio] > valor)		//ocorre na primeira rodada do exemplo com valor = 13
			{
				//atualiza o valor de 'fim'
				fim = meio-1;
			}
			else
			{								//ocorre na primeira rodada do exemplo com valor = 28
				//vetor[meio] < valor
				comeco = meio+1;
			}
		}		
	}
	
	//elemento não existe no vetor
	return -1;
}

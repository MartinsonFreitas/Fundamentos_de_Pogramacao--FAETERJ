/*
	FAC - 2021/1
	Data: 24/06/2021
	
	Lista de Exercícios X

	QUESTÃO 03:
	Pede-se a implementação de uma função que, dado um vetor contendo números reais, 
	determine se o mesmo encontra-se ordenado de forma crescente.	
*/

//importação de bibliotecas
#include<stdio.h>

//protótipos das funções
void exibirVetor (float vetor[], int quant);

int verificaOrdenacao (float vetor[], int quant);

//main
void main()
{
	//declaração de variáveis
	float vet1[5] = {1,2,3,4,5};
	float vet2[8] = {1,2,3,4,5,6,8,7};
	int resultado;
	
	//trabalhando com o primeiro vetor
	exibirVetor (vet1, 5);
	
	resultado = verificaOrdenacao (vet1, 5);
	
	if (resultado == 0)
	{
		printf ("vet1 nao esta ordenado!\n");
	}
	else
	{
		printf ("vet1 esta ordenado!\n");
	}


	//trabalhando com o segundo vetor
	exibirVetor (vet2, 8);
	
	resultado = verificaOrdenacao (vet2, 8);
	
	if (resultado == 0)
	{
		printf ("vet2 nao esta ordenado!\n");
	}
	else
	{
		printf ("vet2 esta ordenado!\n");
	}
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

int verificaOrdenacao (float vetor[], int quant)
{
	//declaração de variáveis
	int i, j;
	
	//comparando os elementos do vetor
	for (i=0, j=1;j<quant;i++,j++)
	{
		//verificando o erro!
		if (vetor[i] > vetor[j])
		{
			return 0;
		}
	}
	
	//vetor está ordenado
	return 1;
}

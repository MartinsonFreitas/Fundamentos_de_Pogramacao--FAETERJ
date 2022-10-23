#include <stdio.h>
#define TAM 5
/*

	"Desenvolver uma função que, dado um vetor com tam valores inteiros, 
	determine o maior e o menor dentre eles."

*/

void maiorMenor (int vetor[], int quant, int *maior, int *menor)
{
	//declaração de variaveis
	int i;
	
	//rodando o vetor inteiro
	for (i=0;i<quant;i++)
	{
		//verificando se o valor da posição do vetor é maior do que o valor guardado
		if(vetor[i]>=*maior)
		{
			*maior=vetor[i];
		}
		else
		{
			//Se entrou aqui, a condição if é falsa
			//Logo, o valor é menor.
			if (vetor[i] < *menor)
			{
				*menor=vetor[i];
			}
		}
	}
}

void main()
{
	int maior=-999999, menor=999999, 
	vetor[TAM] = {1,5,1,3,2}; // Vetor sendo inicializado
	
	/*
		Chamando a função e retornando os valores menor e maior
		por referência aos endereços de memória das respectivas 
		variáveis declaradas na main
	*/
	
	maiorMenor (vetor, TAM, &maior, &menor);
	
	printf("\nMaior valor: %d \n", maior);
	printf("\nMenor valor: %d", menor);
}

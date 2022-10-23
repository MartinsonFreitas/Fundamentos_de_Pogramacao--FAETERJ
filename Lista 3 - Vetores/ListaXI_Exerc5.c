/*
	FAC - 2021/1
	Resolução dos exercícios que não foram resolvidos em sala com o professor.
	
	Lista de Exercícios XI 
	
	Questão 05:
	Implementar uma função que, dado um vetor contendo números reais, determine 
	o maior e o segundo maior elementos.

	Nota: considerar que não há repetição de elementos no vetor.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void maiores (float vetor[], int quant, float *maior, float *segundoMaior);

void exibirVetor (float vetor[], int quant);

//main
void main ()
{
	//declaração de variáveis
	float vet[10] = {5,3,2,1,4,6,9,8,7,0};
	float primeiro, segundo;
	    
	//exibindo o vetor
	exibirVetor (vet, 10);		
	
	//chamando a função
	maiores (vet, 10, &primeiro, &segundo);
	
	//exibindo os resultados
	printf ("\nMaior: %.1f", primeiro);
	printf ("\nSegundo maior: %.1f", segundo);
}

//implementação das funções

//Determina o maior e o segundo maior valores do vetor, retornando-os em 'maior' e
//'segundoMaior'
void maiores (float vetor[], int quant, float *maior, float *segundoMaior)
{
	//declaração de variáveis
	int i;
	
	//inicializando *maior e *segundoMaior com os dois primeiros elementos do vetor
	if (vetor[0] < vetor[1])
	{
		*maior = vetor[1];
		*segundoMaior = vetor[0];
	}
	else
	{
		*maior = vetor[0];
		*segundoMaior = vetor[1];
	}
	
	//percorrendo as demais posições do vetor
	for (i=2;i<quant;i++)
	{
		//verificando se o elemento vetor[i] é o maior de todos
		if (vetor[i] > *maior)
		{
			//atualizando o maior e o segundo maior
			*segundoMaior = *maior;
			*maior = vetor[i];
		}
		else
		{
			//verificando se o elemento vetor[i] é o segundo maior valor do vetor
			if (vetor[i] > *segundoMaior)
			{
				//atualizando o segundo maior
				*segundoMaior = vetor[i];
			}
		}
	}
}

//Exibe na tela os elementos do vetor
void exibirVetor (float vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//exibindo os elementos do vetor
	printf ("\nElementos do vetor: ");
	
	for (i=0;i<quant;i++)
	{
		printf ("%.1f ", vetor[i]);
	}
	
	printf ("\n\n");
}

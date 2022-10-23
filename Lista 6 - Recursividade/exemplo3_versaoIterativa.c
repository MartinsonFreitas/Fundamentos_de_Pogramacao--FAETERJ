/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 23/10/2021 (aula extra)
	
	Desenvolver uma função recursiva que retorne a quantidade de ocorrências de um número 
	em um vetor de inteiros.
	
	[VERSÃO ITERATIVA, A PEDIDO DOS ALUNOS]
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int numOcorrencias (int numero, int vetor[], int quant);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int vet[10] = {1,8,1,2,6,4,1,3,6,1};
	int cont, numero = 1;
	
	//chamando a função
	cont = numOcorrencias (numero, vet, 10);	
	
	//exibindo o resultado
	printf ("Foram encontradas %d ocorrencias do numero %d no vetor.", cont, numero);
}

//implementação
int numOcorrencias (int numero, int vetor[], int quant)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo o vetor
	for (i=0;i<quant;i++)
	{
		//comparando cada elemento com o número sendo buscado
		if (vetor[i] == numero)
		{
			cont++;
		}
	}
	
	//retornando o número de ocorrência
	return cont;
}

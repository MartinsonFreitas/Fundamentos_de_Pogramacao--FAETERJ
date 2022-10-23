/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 23/10/2021 (aula extra)
	
	Recursividade
	
	Exemplo 5: Busca binária (busca de um número inteiro n em um vetor ordenado 
	crescentemente, retornando a sua posição (caso encontrado)).
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TAM 1000

//protótipos das funções
int buscaBinaria (int numero, int vetor[], int inicio, int fim);

void preencher(int vetor[], int tamanho);
void exibir (int vetor[], int tamanho);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int vetor[TAM], resp, num;
	
	//preenchendo o vetor com valores aleatórios
	preencher (vetor, TAM);
	
	//exibindo o vetor
    exibir (vetor, TAM);
	
	//lendo o valor a ser buscado
	printf ("Entre com o numero a ser buscado: ");
	scanf ("%d", &num);
	
	//buscando o elemento no vetor
	resp = buscaBinaria (num, vetor, 0, TAM-1);	  //inicialmente, a busca considerará todas as posições do vetor; ou seja, da posição 0 à posição TAM-1
	
	//verificando o retorno da função
	if (resp == -1)
	{
		printf ("O valor %d nao foi encontrado no vetor\n", num);
	}
	else
	{
		printf ("O valor %d foi encontrado na posicao %d do vetor\n", num, resp);
	}	
}

//implementação das funções
int buscaBinaria (int numero, int vetor[], int inicio, int fim)
{
	int meio;	//armazenará a posição do elemento do meio do vetor
	
	//verificando se ainda há posições a serem percorridas
	if (inicio <= fim)
	{	
		//calculando a posição 'meio'
		meio = (inicio + fim)/2;
		
		//verificando se o elemento do meio é aquele buscado
		if (vetor[meio] == numero)		//caso base 1
		{
			return meio;	
		}	
		else
		{
			//verificando se o elemento do meio é maior do que o numero
			if (vetor[meio] > numero)
			{
				//'fim' deve ser ajustado, de modo que o espaço de busca do vetor
				//passe a ser o subvetor à esquerda da posição 'meio'
				fim = meio-1;
				
				return buscaBinaria (numero, vetor, inicio, fim);
			}
			else
			{
				//o elemento do meio é menor do que o numero
			
				//'inicio' deve ser ajustado, de modo que o espaço de busca do vetor
				//passe a ser o subvetor à direita da posição 'meio'
				inicio = meio+1;
				
				return buscaBinaria (numero, vetor, inicio, fim);
			}
		}
	}
	else		//caso base 2
	{
		//ou seja, 'inicio' é maior do que 'fim'
		return -1; //o elemento não encontra-se no vetor
	}
}

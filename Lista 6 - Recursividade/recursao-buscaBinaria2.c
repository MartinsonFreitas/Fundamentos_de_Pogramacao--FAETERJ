/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 09/05/2022
	
	Recursividade
	
	Busca binária: buscar um elemento (e retornar a sua posição, caso encontrado) em um vetor cujos elementos 
	estão ordenados crescentemente. Caso o elemento não se encontre no vetor, o valor -1 será retornado.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define TAM 100

//protótipos das funções
int buscaBinaria (int v[], int tamanho, int numero);
int buscaBinariaAux (int v[], int numero, int inicio, int fim);

void preencher(int vetor[], int tamanho);
void exibir (int vetor[], int tamanho);

//função main
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
	resp = buscaBinaria (vetor, TAM, num);	
	
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

int buscaBinaria (int v[], int tamanho, int numero)
{
	return buscaBinariaAux (v, numero, 0, tamanho-1);	
}

int buscaBinariaAux (int v[], int numero, int inicio, int fim)
{
	//declaração de variáveis
	int meio;
	
	//caso base
	if (inicio > fim)
	{
		return -1;
	}
	else
	{
		//caso geral
		
		//determinando a posição do elemento do meio do vetor
		meio = (inicio + fim)/2;
		
		//verificando se o elemento buscado está no meio do vetor
		if (v[meio] == numero)
		{
			return meio;
		}
		else
		{
			//verificando se a busca deve continuar no subvetor à esquerda da posição meio
			if (v[meio] > numero)
			{
				return buscaBinariaAux (v, numero, inicio, meio-1);			
			}
			else
			{
				//... ou à direita da posição meio
				return buscaBinariaAux (v, numero, meio+1, fim);
			}
		}
	}
}

void preencher(int vetor[], int tamanho)
{
    //declaracao de variaveis
    int i;
    
    srand (time(NULL));
    
    //armazenando na primeira posição um valor de 1 a 10
    vetor[0] = 1 + rand()%10;
    
    //corpo da função
    for(i = 1; i < tamanho; i++)
	{
		vetor[i] = vetor[i-1] + rand()%5; //garantindo que o vetor estará ordenado crescentemente
    }
}

void exibir (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\nElementos do vetor: ");
	
	//percorrendo todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		printf ("%d  ", vetor[i]);
	}
	
	printf ("\n\n");
}

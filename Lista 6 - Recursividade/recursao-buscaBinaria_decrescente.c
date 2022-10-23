/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 23/10/2021 (aula extra)
	
	Recursividade
	
	Exemplo 6: Busca binária (busca de um número inteiro n em um vetor ordenado 
	decrescentemente, retornando a sua posição (caso encontrado)).
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
	int meio; //armazenará a posição do elemento do meio do vetor
	
	//verificando se ainda há posições a serem percorridas
	if (inicio <= fim)
	{	
		//calculando a posição 'meio'
		meio = (inicio + fim)/2;
		
		//printf ("\nComparando %d com o elemento da posicao %d (%d)", numero, meio, vetor[meio]);
		
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
				//'inicio' deve ser ajustado, de modo que o espaço de busca do vetor
				//passe a ser o subvetor à direita da posição 'meio'
				inicio = meio+1;
				
				return buscaBinaria (numero, vetor, inicio, fim);
			}
			else
			{
				//o elemento do meio é menor do que o numero
			
				//'fim' deve ser ajustado, de modo que o espaço de busca do vetor
				//passe a ser o subvetor à esquerda da posição 'meio'
				fim = meio-1;
				
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

void preencher(int vetor[], int tamanho)
{
    //declaracao de variaveis
    int i;
    
    srand (time(NULL));
    
    //armazenando na primeira posição um valor alto, de 10000 a 19999
    vetor[0] = 10000 + rand()%10000;
    
    //corpo da função
    for(i = 1; i < tamanho; i++)
	{
		vetor[i] = vetor[i-1] - rand()%30;   //cada valor do vetor será igual ao anterior menos um valor gerado randomicamente, garantindo que o vetor será decrescente.
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

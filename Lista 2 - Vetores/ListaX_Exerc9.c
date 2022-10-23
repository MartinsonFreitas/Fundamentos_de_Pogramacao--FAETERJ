/*
	FAC - 2021/1
	Data: 01/07/2021
	
	Lista de Exercícios X

	QUESTÃO 09:
	Implementar a função de inserção de determinado elemento em um vetor ordenado 
	crescentemente (dica: utilizar a função do item 08 para auxiliar).
	
	Exemplos:
	
	vetor:   1   3   8   8   10   12   13   15
	         0   1   2   3   4    5    6    7 
	x: 8
			função buscar: retorna a posição 2

	inserir: descloca todos da posição 2 em diante uma posição para a direita
	
	vetor:   1   3  |8|  8   8   10   12   13   15
	         0   1   2   3   4    5    6    7 
*/

//importação de bibliotecas
#include<stdio.h>

//declaração de constantes
#define CAP 5

#define TRUE 1
#define FALSE 0

//protótipos das funções
void exibirVetor (float vetor[], int quant);

int buscar (float vetor[], int quant, float x);
int inserir (float vetor[], int *quant, int capacidade, float x);

//main
void main()
{
	//declaração de variáveis
	float vet[CAP];
	int quantidade = 0;
	
	int sair = FALSE;
	char opcao;
	float numero;
	
	//inserindo valores até que o usuário opte por parar
	do
	{
		printf ("\n\nEntre com o elemento que deseja inserir: ");
		scanf ("%f", &numero);
		
		//inserindo o elemento no vetor
		if (inserir (vet, &quantidade, CAP, numero) == TRUE)
		{
			printf ("\n\tO numero %.1f foi inserido com sucesso.\n", numero);
			
			//exibindo o vetor
			exibirVetor (vet, quantidade);			
			
			//verificando se o usuário deseja inserir mais valores no vetor
			printf ("\nDeseja inserir um novo valor [S/N]? ");
			fflush (stdin);
			scanf ("%c", &opcao);
			opcao = toupper (opcao);			
		}
		else
		{
			printf ("\n\tERRO: nao ha mais espaco no vetor!\n");
			sair = TRUE;
		}
	}
	while ((opcao == 'S') && (sair == FALSE));
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

int inserir (float vetor[], int *quant, int capacidade, float x)
{
	//declaração de variáveis
	int i, pos;
	
	//verificando se o vetor está 'cheio'
	if (*quant == capacidade)
	{
		return FALSE;
	} 
	else
	{
		//se chegou aqui, há espaço no vetor para inserir o elemento
		
		//buscar em que posição o elemento será inserido
		pos = buscar (vetor, *quant, x);	
		
		//deslocar para a direita todos os elementos da posição 'pos' ao final do vetor
		for (i=*quant-1;i>=pos;i--)
		{
			vetor[i+1] = vetor[i];
		}
		
		//inserindo o elemento 'x' na posição 'pos'
		vetor[pos] = x;
		
		//atualizando a quantidade de elementos no vetor
		(*quant)++;
		
		return TRUE;
	}
}

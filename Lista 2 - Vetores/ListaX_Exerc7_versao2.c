/*
	FAC - 2021/1
	Data: 26/06/2021
	
	Lista de Exercícios X

	QUESTÃO 07:
	Desenvolver uma função que remova determinado elemento (todas as suas 
	ocorrências) de um vetor de float. Ao final, retornar o número de remoções 
	realizadas.
	
	Na versão 1, optamos por deslocar o último elemento para a posição do valor
	sendo removido.
	
	Nesta segunda versão, deslocaremos todos os elementos além da posição daquele 
	que será removido (sabendo que esta solução é mais demorada).
*/

//importação de bibliotecas
#include<stdio.h>

//declaração de constantes
#define TAM 10

//protótipos das funções
void exibirVetor (float vetor[], int quant);
void preencheVetor (float vetor[], int quant);

int remover (float vetor[], int *quant, float numero);

//main
void main()
{
	//declaração de variáveis
	float vet[TAM];
	float num;
	int result, qdade;
	
	//preenchendo o vetor aleatoriamente
	preencheVetor (vet, TAM);
	qdade = TAM;
	
	//exibindo o vetor original
	exibirVetor (vet, qdade);
	
	//obtendo o valor a ser removido
	printf ("Qual valor deseja remover? ");
	scanf ("%f", &num);
	
	//chamando a função de remoção
	result = remover (vet, &qdade, num);
	
	//exibindo o vetor original após a remoção do elemento
	exibirVetor (vet, qdade);
	printf ("%d remocoes de %.1f foram realizadas!", result, num);
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

void preencheVetor (float vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//garantindo que cada sequência de valores gerados será diferente
	srand(time(NULL));
	
	//gerando números aleatórios com a função 'rand'
	for (i=0;i<quant;i++)
	{
		vetor[i] = (float)(rand()%10)+1; //gerando números aleatórios de 1 a 10
	}		
}

int remover (float vetor[], int *quant, float numero)
{
	//declaração de variáveis
	int i, cont=0, pos;
	
	//percorrendo o vetor em busca do elemento a ser removido
	for (i=0;i<*quant;)
	{
		//verificando se o elemento foi encontrado
		if (vetor[i] == numero)
		{
			//Possibilidade 1 explicada em aula
			for (pos=i+1;pos<*quant;pos++)
			{
				vetor[pos-1] = vetor[pos];
			}
			
			(*quant)--;						//atualizando a quantidade de elementos
			
			cont++; //atualizando o número de remoções realizadas
		}
		else
		{
			i++;
			/*o incremento só será feito se a posição não estiver armazenando o valor
			sendo buscado. Dessa forma, caso seja feito o deslocamento, a posição 
			será novamente analisada*/
		}
	}
	
	//retornando o número de remoções
	return cont;
}

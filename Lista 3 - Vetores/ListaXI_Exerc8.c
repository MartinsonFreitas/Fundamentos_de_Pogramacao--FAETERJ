/*
	FAC - 2021/1
	Resolução dos exercícios que não foram resolvidos em sala com o professor.
	
	Lista de Exercícios XI 
	
	Questão 08:
	Faça uma função que, dado um vetor de números inteiros, exiba para cada um de 
	seus elementos a quantidade de vezes que o mesmo aparece no vetor.

	Exemplo:
		Vetor = {3,5,1,3,2,5,7,3,4,7,6,1}

	Saída:
		3: 3 vezes
		5: 2 vezes
		1: 2 vezes
		2: 1 vez
		7: 2 vezes
		4: 1 vez
		6: 1 vez
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
void exibirNumOcorrencias (int vetor[], int quant);

void exibirVetor (int vetor[], int quant);

//main
void main ()
{
	//declaração de variáveis
	int vet[12] = {3,5,1,3,2,5,7,3,4,7,6,1};
	    
	//exibindo o vetor
	exibirVetor (vet, 12);		
	
	//chamando a função
	exibirNumOcorrencias (vet, 12);
}

//implementação das funções

void exibirNumOcorrencias (int vetor[], int quant)
{
	//declaração de variáveis
	int i, j, cont, pos, continuar;
	
	//percorrendo todas as posições do vetor
	for (i=0;i<quant;i++)
	{
		//antes de verificar o número de ocorrências de vetor[i], verificar se
		//ele já foi exibido anteriormente para evitar que mensagens sejam repetidas
		continuar = TRUE;
		
		for (pos=0;(pos<i)&&(continuar == TRUE);pos++)
		{
			if (vetor[i] == vetor[pos])
			{
				continuar = FALSE;
			}
		}
		
		//só continuaremos, se o vetor[i] estiver aparecendo no vetor pela 1ª vez
		if (continuar == TRUE)
		{ 
			//para cada elemento vetor[i], contaremos o número de vezes que ele 
			//aparece no vetor
			cont = 0;
			
			for (j=0;j<quant;j++)
			{
				if (vetor[i] == vetor[j])
				{
					cont++;
				}
			}
			
			//exibindo a quantidade de vezes que vetor[i] aparecer no vetor
			printf (cont==1?"%d: %d vez primeira posicao %d\n":"%d: %d vezes primeira posicao %d\n", vetor[i], cont, pos);
		}
	}
}

void exibirVetor (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//exibindo os elementos do vetor
	printf ("\nElementos do vetor: ");
	
	for (i=0;i<quant;i++)
	{
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n\n");
}

/*
	FAC - 2021/1
	Data: 20/05/2021
	
	Lista de Exercícios VIII (Funções)
	
	QUESTÃO 03:
	Desenvolver uma função que calcule o n-ésimo termo da sequência de Fibonacci.
	
									1 1 2 3 5 8 13 21...
	
	Exemplos:
	
		n: 2		a função retorna: 2º termo: 1
		n: 8		a função retorna: 8º termo: 21
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções
int fibonacci (int n);

//main
void main()
{
	//declaração de variáveis
	int posicao, i;
	
	//leitura do elemento que o usuário deseja saber
	printf ("Qual a posicao ordinal da sequencia de fibonacci? ");
	scanf ("%d", &posicao);

	for (i=1;i<=posicao;i++)
	{
		printf ("%d ", fibonacci (i));	
	}	
}

//implementação das funções
int fibonacci (int n)
{
	//declaração de variáveis
	int i, t1, t2, resposta;
	
	//se for o 1º termo, retorna 1
	if (n==1)
	{
		resposta = 1;
	}
	else
	{
		//se for o 2º termo, retorna 1	
		if (n==2)
		{
			resposta = 1;
		}
		else
		{
			//se chegou aqui, é pq deseja-se calcular um valor que está da terceira posição em diante
			t1 = 1;
			t2 = 1;

			//calculando do 3º ao n-ésimo termo
			for (i=3;i<=n;i++)
			{
				resposta = t1 + t2;
				
				t1 = t2;
				t2 = resposta;
			}
     			// exemplo: n=6
				// 1  1  2  3  5  8  13  21...
				// 1  2  3  4  5  6  7   8
				//          t1 t2 r      
		}
	}
	
	//retornando o resultado
	return resposta;	
}

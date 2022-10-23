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
	
	//se for o 1º ou 2º termo, retorna 1
	if ((n==1) || (n==2))
	{
		return 1;
	}
	else   /*esse 'else' pode ser removido! Motivo: se a execução chegar ao comando 
	       "t2=1;", podemos garantir que o 'return 1' não foi executado. Afinal se tivesse
		   sido executado, a função teria terminado! Logo, se chegou a este comando, a 
		   condição do 'if' não foi verdadeira.
		   
		   ATENÇÃO: isso só é válido pois o return foi colocado no 'if'. Se, por outro
		   lado, o return for colocado ao final da função, o 'else' não poderia ser
		   omitido!*/
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
				
		return resposta;
	}
}

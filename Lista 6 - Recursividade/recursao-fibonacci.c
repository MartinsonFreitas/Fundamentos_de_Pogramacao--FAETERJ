/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 09/05/2022
	
	Recursividade
	
	Exemplo 4: Calcular o n-ésimo termo da sequência de fibonacci
	
						1,1,2,3,5,8,13,21,...
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int fibonacciI (int n);
int fibonacciR (int n);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int ordem = 10;
	
	printf ("%do. termo de Fibonacci (iterativo): %d\n", ordem, fibonacciI(ordem));    
	
	system ("pause");
	
	printf ("%do. termo de Fibonacci (recursivo): %d\n", ordem, fibonacciR(ordem));    
}

//implementações das funções
int fibonacciI (int n)
{
	//declaração de variáveis
	int i, a, b, c;
	
	if ((n==1) || (n==2))  //1º ou 2º termos
	{
		return 1;
	}
	else
	{
		//do 3º termo em diante
		a = 1;
		b = 1;
			
		for (i=3;i<=n;i++)
		{
			//calculando o i-ésimo termo
			c = a + b;
				
			//atualizando os dois últimos valores
			a = b;
			b = c;				
		}
			
		//retornando o resultado
		return c;
	}	
}

int fibonacciR (int n)
{
	if ((n==1) || (n==2))  //1º ou 2º termos  =  casos base
	{
		return 1;
	}
	else
	{
		//caso geral
		return fibonacciR (n-1) + fibonacciR (n-2);
	}	
}

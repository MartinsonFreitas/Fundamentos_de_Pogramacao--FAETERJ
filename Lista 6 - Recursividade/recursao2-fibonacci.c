/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 18/10/2021
	
	Recursividade
	
	Exemplo 4: Calcular o n-ésimo termo da sequência de fibonacci
	
						0,1,1,2,3,5,8,13,21,...
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
	int ordem = 60;
	
	printf ("%do. termo de Fibonacci (iterativo): %d\n", ordem, fibonacciI(ordem));    
	
	system ("pause");
	
	printf ("%do. termo de Fibonacci (recursivo): %d\n", ordem, fibonacciR(ordem));    
}

//implementações das funções
int fibonacciI (int n)
{
	//declaração de variáveis
	int i, a, b, c;
	
	if (n==1)  //1º termo
	{
		return 0;
	}
	else
	{
		if (n==2)  //2º termo
		{
			return 1;
		}
		else
		{
			//do 3º termo em diante
			a = 0;
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
}

int fibonacciR (int n)
{
	if (n==1)  //1º termo   = caso base
	{
		return 0;
	}
	else
	{
		if (n==2)  //2º termo  =  caso base
		{
			return 1;
		}
		else
		{
			//caso geral
			return fibonacciR (n-1) + fibonacciR (n-2);
		}	
	}
}

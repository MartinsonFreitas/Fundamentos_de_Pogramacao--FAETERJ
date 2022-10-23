/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 18/10/2021
	
	Recursividade
	
	Exemplo 3: Calcular o valor de a x b, através de sucessivas somas, onde a e b são 
	inteiros positivos.
	
	versão 2: permitindo que o segundo valor seja nulo!
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int produtoRecursivo (int a, int b);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int x = 1, y = 5;
	
	printf ("%d x %d = %d\n\n", x, y, produtoRecursivo (x, y));
}

//implementações das funções
int produtoRecursivo (int a, int b)
{
	//caso base
	if (b==0)
	{
    	return 0;
	}
	else 
	{
		//caso geral
		return a + produtoRecursivo (a,b-1);
	}
}

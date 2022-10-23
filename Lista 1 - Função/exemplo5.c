/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 30/08/2021
	
	Revisão - FAC
	
	Desenvolver uma função que exiba os números de 'num1' a 'num2'
	
	[SOLUÇÃO RECOMENDADA!!!] POIS USA PARÂMETROS!!!
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos/cabeçalhos das funções
void exibeNumeros (int num1, int num2);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int valor1, valor2;
	
	//1º exemplo de chamada à função
	exibeNumeros (10, 50);
	
	//2º exemplo de chamada à função
	printf ("\n\n\nEntre com um numero: ");
	scanf ("%d", &valor1);
	
	printf ("Entre com outro numero: ");
	scanf ("%d", &valor2);
	
	exibeNumeros (valor1, valor2);
}

//implementação das demais funções
void exibeNumeros (int num1, int num2)
{
	//declaração de variáveis
	int i;
	
	//variando os valores de 'num1' a 'num2' e exibindo-os
	for (i=num1; i<=num2; i++)
	{
		printf ("%d  ", i);
	}
}


/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 30/08/2021
	
	Revisão - FAC
	
	Desenvolver uma função que exiba os números de 'num1' a 'num2'
	
	[SOLUÇÃO NÃO RECOMENDADA!!!] POIS NÃO USA PARÂMETROS!!!
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos/cabeçalhos das funções
void exibeNumeros ();

//implementação da função main
void main ()
{
	exibeNumeros ();
}

//implementação das demais funções
void exibeNumeros ()
{
	//declaração de variáveis
	int i, num1, num2;
	
	//leitura dos valores de 'num1' e 'num2'
	printf ("Entre com o primeiro valor do intervalo: ");
	scanf ("%d", &num1);
	
	printf ("Entre com o segundo valor do intervalo: ");
	scanf ("%d", &num2);
	
	//variando os valores de 'num1' a 'num2' e exibindo-os
	for (i=num1;i<=num2;i++)
	{
		printf ("%d  ", i);
	}
}


/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 30/08/2021
	
	Revisão - FAC
	
	Desenvolver uma função que exiba os números de 1 a 1000 (incluindo protótipos)
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
	int i;
	
	//variando os valores de 1 a 1000 e exibindo-os
	for (i=1;i<=1000;i++)
	{
		printf ("%d  ", i);
	}
}


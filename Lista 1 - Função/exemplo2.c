/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 30/08/2021
	
	Revisão - FAC
	
	Desenvolver uma função que exiba os números de 1 a 1000
*/

//importação de bibliotecas
#include <stdio.h>

void exibeNumeros ()
{
	//declaração de variáveis
	int i;
	
	//variando os valores de 1 a 1000 e exibindo-os
	for (i=1; i<=1000; i++)
	{
		printf ("%d  ", i);
	}
	
}

void main ()
{
	exibeNumeros ();
}

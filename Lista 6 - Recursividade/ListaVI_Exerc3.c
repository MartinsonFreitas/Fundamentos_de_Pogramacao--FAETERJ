/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 25/10/2021
	
	Recursividade
	
	Lista de Exercícios VI
	
	Questão 03: Fazer uma função recursiva que, dado um número inteiro N, exiba o mesmo 
	na base 2 (binária).
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void binario (int N);

//implementação da função main
void main ()
{
	//chamando a função
	binario (100);
}

//implementações das funções
void binario (int N)
{
	if (N > 0)		//caso geral
	{
		binario (N/2);		
		printf ("%d", N%2);
	}
}

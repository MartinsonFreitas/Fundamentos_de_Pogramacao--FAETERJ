/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 01/11/2021
	
	Recursividade
	
	Lista de Exercícios VI
	
	Questão 04: Pede-se a implementação de uma função recursiva que exiba os n 
	primeiros termos de uma PG (Progressão Geométrica), onde a1 é o seu primeiro 
	termo e q a razão.
	
	Exemplo:
	
			n = 5, a1 = 2, q = 3
			PG: 2, 6, 18, 54, 162 
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void PG (int n, float a1, float q);

//implementação da função main
void main ()
{
	PG (10, 1, 2);
}

//implementações das funções
void PG (int n, float a1, float q)
{
	if (n>0)		//caso geral
	{
        printf("%.1f, ",a1);
        
		PG (n-1, a1*q, q);
    }
    //caso base (implícito): n = 0
}

/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 25/10/2021
	
	Recursividade
	
	Implementar uma função recursiva que resolva o problema das Torres de Hanói.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void hanoi (int n, char O, char D, char aux);

//implementação da função main
void main ()
{
	//chamando a função
	hanoi (5, 'A', 'C', 'B');
}

//implementações das funções
void hanoi (int n, char O, char D, char aux)
{
	if (n > 0)
	{
			hanoi (n-1, O, aux, D);
			printf  ("%c  ->  %c\n", O, D);
			hanoi (n-1, aux, D, O);
	}
}


/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 23/10/2021 (aula extra)
	
	O que é exibido pela função?
	
		Resposta: exibe os números de 1 até 'numero' 
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void exibir (int numero);

//implementação da função main
void main ()
{
	exibir (100);
}

void exibir (int numero)
{
	if (numero > 0)					//caso geral
	{
		//printf ("%d ", numero);
		exibir (numero-1);			//antes de exibir 'numero', é feita a chamada recursiva para exibir os demais valores, inferiores a 'numero'
		printf ("%d ", numero);		//por esse motivo, os números são apresentados em ordem crescente, de 'numero' a 1
	}
				
	//caso base implícito: numero <= 0
}

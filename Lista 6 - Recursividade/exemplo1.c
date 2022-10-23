/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 23/10/2021 (aula extra)
	
	O que é exibido pela função?
	
		Resposta: exibe os números de 'numero' até 1
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void exibir (int numero);

//implementação da função main
void main ()
{
	exibir (10);
}

void exibir (int numero)
{
	if (numero > 0)					//caso geral
	{
		printf ("%d ", numero);		//primeiro 'numero' é exibido e, em seguida, a chamada recursiva é feita para exibir os demais valores, inferiores a 'numero'
		exibir (numero-1);			//por esse motivo, os números são apresentados em ordem decrescente, de 'numero' a 1
	}
				
	//caso base implícito: numero <= 0
}

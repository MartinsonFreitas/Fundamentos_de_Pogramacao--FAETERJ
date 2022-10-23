/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 01/11/2021
	
	Recursividade
	
	Lista de Exercícios VI
	
	Questão 02: Desenvolver uma função recursiva que exiba todos os múltiplos do número N, inferiores ou iguais 
	ao valor V.
	
	Exemplo:
			N = 3
			V = 20
			Serão apresentados: 0, 3, 6, 9, 12, 15, 18			
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void exibirMultiplos (int n, int v);

//implementação da função main
void main ()
{
	exibirMultiplos (5, 100);
}

//implementações das funções
void exibirMultiplos (int n, int v)
{
	if (v!=0)			//caso geral
	{
		exibirMultiplos (n,v-1);
		
		if (v%n==0)		//verificando se 'v' é um múltiplo de 'n'
		{
			printf ("\n%d",v);
		}	
	}
	else 				//caso base
	{
    	printf("\n%d",v);
	}
}

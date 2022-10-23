/*
	FAETERJ-Rio
	Fundamentos de Programação - 2022/1 - Turma: Noite
	Data: 23/05/2022
	
	Lista de Exercícios IX (Recursividade + strings)
	
	Questão 04:
	Desenvolver uma função recursiva que, dada uma string, exiba-a 
	invertida.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//declaração de protótipos
void exibirInvertida (char string[]);		//essa será chamada pela main
void funcao (char string[], int posicao);	//a função recursiva

//main
void main ()
{
	//declaração de variáveis
	char str[30];
	
	//leitura dos dados de entrada
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (str);
	
	//chamando a função
	exibirInvertida (str);
}

//implementação das funções
void exibirInvertida (char string[])
{
  	funcao (string, strlen (string) - 1);
}

void funcao (char string[], int posicao)
{
	if (posicao >= 0)	//caso geral
	{
    	printf ("%c", string[posicao]);
    
		//chamando a função recursivamente
		funcao (string, posicao-1);
  	}
}

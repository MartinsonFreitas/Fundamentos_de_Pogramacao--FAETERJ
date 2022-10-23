/*
	FAETERJ-Rio
	Fundamentos de Programação - 2022/1 - Turma: Noite
	Data: 23/05/2022
	
	Lista de Exercícios VIII (Recursividade)
	
	Questão 05:
	Dada uma string s, desenvolver uma função recursiva que 
	determine se s é ou não um palíndromo.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//declaração de protótipos
int palindromo (char string[]);		//a função que será chamada na main
int verificarPalindromo (char string[], int inicio, int fim); //a função recursiva

//main
void main ()
{
	//declaração de variáveis
	char s[30];
	int resultado;
	
	//leitura dos dados de entrada
	printf ("Entre com uma string: ");
	fflush (stdin);
	gets (s);
	
	//chamando a função
	resultado = palindromo (s);
	
	//testando o resultado
	if (resultado == TRUE)
	{
		printf ("\n\nA string %s e' um palindromo!", s);
	}
	else
	{
		printf ("\n\nA string %s nao e' um palindromo!", s);
	}
}

//implementação das funções
int verificarPalindromo (char string[], int inicio, int fim)
{
	if (inicio < fim)  //caso geral: ainda há caracteres a serem comparados
	{
		//verificando se os caracteres são diferentes (e, portanto, a string não é um palíndromo)
    	if (string[inicio] != string[fim])
    	{
    		return FALSE;
    	} 
		else 
		{
			//chamando a função recursivamente, para fazer comparação
			//dos próximos caracteres
			return verificarPalindromo (string, inicio+1, fim-1);
    	}
  	}
  	else	//caso base: não há mais caracteres a comparar
  	{
  		return TRUE;
	}
}

int palindromo (char string[])
{
	return verificarPalindromo (string, 0, strlen(string)-1);
}

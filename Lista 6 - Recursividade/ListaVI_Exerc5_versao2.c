/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 01/11/2021
	
	Recursividade
	
	Lista de Exercícios VI
	
	Questão 05:
	Dada uma string s, desenvolver uma função recursiva que determine se s é ou 
	não um palíndromo.
	
	Exemplo:
			ABCDCBA
			
			ABCDCBX	
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int palindromo (char s[]);
int palindromo_aux (char s[], int pos1, int pos2);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int resp;
	char string[30];
	
	//armazenando um valor na string
	strcpy (string, "NATAN");
	
	//chamando a função
	resp = palindromo (string);
	
	//testando o retorno
	if (resp == 1)
	{
		printf ("\nA string %s e' um palindromo.", string);
	}
	else
	{
		printf ("\nA string %s nao e' um palindromo.", string);
	}
}

//implementações das funções
int palindromo (char s[])
{
	return palindromo_aux (s, 0, strlen(s)-1);	
}

int palindromo_aux (char s[], int pos1, int pos2)
{
	if (pos1 < pos2)
	{	
		if (s[pos1] != s[pos2])
		//if (toupper(s[pos1]) != toupper(s[pos2]))		Se quiser desconsiderar maíusculos/minúsculos
		{
			return 0;
		}
		else
		{
			return palindromo_aux (s, pos1+1, pos2-1);
		}
	}
	else
	{
		return 1;
	}
}

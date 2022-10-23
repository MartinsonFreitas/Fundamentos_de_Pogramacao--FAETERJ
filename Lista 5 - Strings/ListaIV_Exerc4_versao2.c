/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 28/03/2022
	
	Questão 04: Implementar uma função que remova todas as ocorrências 
	de determinado caracter em uma string. 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void removerCaracteres (char s[], char caracter);

//main
void main ()
{
	//declaração de variáveis
	char palavra[20], sub[20];
	
	//inicializando a palavra
	strcpy (palavra, "ALGORITMOS");
	
	//fazendo algumas chamadas à função 'substring'
	removerCaracteres (palavra, 'O');
	printf ("palavra apos a remocao: %s\n\n", palavra);

	//inicializando a palavra
	strcpy (palavra, "ASSADOS");
	
	//fazendo algumas chamadas à função 'substring'
	removerCaracteres (palavra, 'S');
	printf ("palavra apos a remocao: %s\n\n", palavra);
}

//implementação das funções
void removerCaracteres (char s[], char caracter)
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo a string
	for (i=0;s[i]!='\0';)
	{
		//verificando se o caracter desejado foi encontrado
		if (s[i] == caracter)
		{
			//deslocar todos os caracteres além de s[i] uma posição à esquerda
			for (j=i;s[j]!='\0';j++)
			{
				s[j] = s[j+1];
			}			
		}
		else
		{
			i++;
		}		
	}
}

/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 28/03/2022
	
	Questão 03: Desenvolver uma função que, dada uma string s, crie uma 
	substring que inicie na posição p de s e contenha n caracteres. 
 
	Observações: 
		i) se p e/ou n forem inválidos, a substring será vazia; 
		ii) se s não possuir n caracteres além de p, a substring a ser 
		criada começará em p e terminará no final de s. 
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void substring (char s[], int p, int n, char sub[]);

//main
void main ()
{
	//declaração de variáveis
	char palavra[20], sub[20];
	
	//inicializando a palavra
	strcpy (palavra, "ALGORITMOS");
	
	//fazendo algumas chamadas à função 'substring'
	substring (palavra, 3, 4, sub);
	printf ("substring: %s\n\n", sub);
	
	substring (palavra, -3, 4, sub);
	printf ("substring: %s\n\n", sub);
	
	substring (palavra, 3, 12, sub);
	printf ("substring: %s\n\n", sub);
	
	substring (palavra, 3, 10, sub);
	printf ("substring: %s\n\n", sub);
}

//implementação das funções
void substring (char s[], int p, int n, char sub[])
{
	//declaração de variáveis
	int i, j, tam = strlen(s);
	
	//verificando se os valores de 'p' e 'n' são inválidos
	if ((p < 0) || (n <= 0) || (p >= tam) || (n > tam))
	{
		strcpy (sub, "");	//ou:   sub[0] = '\0';
	}
	else
	{
		for (i=p,j=0;(i<tam) && (j<n);i++,j++)
		{
			sub[j] = s[i];
		}
	
		sub[j] = '\0';
	}	
}

/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	Data: 11/10/2021
	
	STRINGS
	
	Exercício 3: Verificar se uma string é um palíndromo.
	
	Exemplos: ovo, osso, marias sairam, ... 
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos/cabeçalhos das funções
int palindromo (char str[]);

void eliminarCaracteres (char original[], char nova[]);
int contandostring (char str[]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	char string[30];
	int resultado;
	
	fflush (stdin);  //standard input - entrada padrão
	
	//leitura de uma string
	printf ("Entre com uma string: ");
	gets (string);  //get string
	
	//chamando a função
	resultado = palindromo (string);
	
	//exibindo o resultado
	if (resultado == TRUE)
	{
		printf ("\n\nA string %s e' um palindromo", string);
	}
	else
	{
		printf ("\n\nA string %s nao e' um palindromo", string);
	}
}

//implementação das demais funções
int contandostring (char str[])
{
	//declaração de variáveis
	int i;
	
	//percorrendo os caracteres da string
	for (i=0;str[i]!='\0';i++);
		
	return i;
}

int palindromo (char str[])
{
	//declaração de variáveis
	int i, j;
	char nova[50];
	
	//eliminando da string os caracteres que não são letras
	eliminarCaracteres (str, nova);
	
	for (i=0,j=contandostring(nova)-1;i<j;i++,j--)
	{
		//verificando se dois caracteres distintos foram encontrados
		if (nova[i] != nova[j])
		{
			return FALSE;  //conclui-se que a string não representa um palíndromo
		}
	}	
	
	//conclui-se que é um palíndromo
	return TRUE;
}

void eliminarCaracteres (char original[], char nova[])
{
	//declaração de variáveis
	int i, posicao=0;
	char maiuscula;
	
	//percorrendo a string original
	for (i=0;original[i]!='\0';i++)
	{
		//verificando se é uma letra
		maiuscula = toupper(original[i]);
		if ((maiuscula >= 'A') && (maiuscula <= 'Z'))
		{
			nova[posicao] = original[i];
			posicao++;
		}
	}
	
	//terminando a string nova
	nova[posicao] = '\0';
}

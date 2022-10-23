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
	
	for (i=0,j=contandostring(str)-1;i<j;i++,j--)
	{
		//verificando se dois caracteres distintos foram encontrados
		if (str[i] != str[j])
		{
			return FALSE;  //conclui-se que a string não representa um palíndromo
		}
	}	
	
	//conclui-se que é um palíndromo
	return TRUE;
}



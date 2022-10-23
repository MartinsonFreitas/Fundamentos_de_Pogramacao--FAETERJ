/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 11/10/2021
	
	STRINGS
	
	Exercício 2: Determinar o número de ocorrências de um caracter em determinada string.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos/cabeçalhos das funções
int numOcorrencias (char str[], char caracter);

//implementação da função main
void main ()
{
	//declaração de variáveis
	char caracter, frase[30];
	int quant;
	
	fflush (stdin);  //standard input - entrada padrão
	
	//leitura de uma string
	printf ("Entre com uma frase: ");
	gets (frase);  //get string
	
	fflush (stdin);  //standard input - entrada padrão
	
	//leitura de um caracter
	printf ("Entre com o caracter a ser buscado: ");
	//scanf ("%c", &caracter);
	caracter = getche();   //get character
	
	//chamando a função
	quant = numOcorrencias (frase, caracter);
	
	//exibindo o resultado
	printf ("\nForam encontradas %d ocorrencias do caracter %c na string %s", quant, caracter, frase);
}

//implementação das demais funções
int numOcorrencias (char str[], char caracter)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo a string
	for (i=0;str[i]!='\0';i++)
	{
		//verificando se o 'caracter' foi encontrado em 'str'
		if (str[i] == caracter)
		{
			cont++;
		}
	}	
	
	//retornando o resultado
	return cont;
}

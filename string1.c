/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 04/10/2021
	
	STRINGS
	
	Exercício 1: Determinar o número de caracteres de uma string.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos/cabeçalhos das funções
int contandostring (char str[]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	char frase[30];
	int quant;
	
	fflush (stdin);  //standard input - entrada padrão
	
	//leitura de uma string
	printf ("Entre com uma frase: ");
	gets (frase);  //get string
	
	//chamando a função
	quant = contandostring (frase);
	
	//exibindo o resultado
	printf ("\nA frase %s possui %d caracteres", frase, quant);
}

//implementação das demais funções
int contandostring (char str[])
{
	//declaração de variáveis
	int cont=0;
	
	//percorre a string até que o caracter '\0' seja encontrado
	while(str[cont]!= '\0')
	{
		cont++;
	}
	
	//ao final, retorna o valor de 'cont'; ou seja, a posição na qual foi encontrado o '\0'
	return cont;
}

/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 30/08/2021
	
	Revisão - FAC
	
	Desenolver uma função que troque os conteúdos de duas variáveis
	
	[IMPLEMENTAÇÃO CORRIGIDA - USOU PONTEIROS - PARÂMETROS POR REFERÊNCIA]
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos/cabeçalhos das funções
void trocar (int *a, int *b);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int valor1, valor2;
	
	//lendo os valores de entrada
	printf ("Entre com um numero: ");
	scanf ("%d", &valor1);
	
	printf ("Entre com outro numero: ");
	scanf ("%d", &valor2);
	
	//exibindo os números antes de chamar a função
	printf ("\nAntes da chamada: %d e %d\n", valor1, valor2);
	
	//chamando a função
	trocar (&valor1, &valor2);
	
	//exibindo os números depois de chamar a função
	printf ("Depois da chamada: %d e %d\n", valor1, valor2);	
}

//implementação das demais funções
void trocar (int *a, int *b)
{
	//declaração de variáveis
	int c;
	
	c = *a;
	*a = *b;
	*b = c;
}

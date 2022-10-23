/*
	FAC - 2021/1
	Data: 20/05/2021
	
	Lista de Exercícios VIII (Funções)
	
	QUESTÃO 01:
	Desenvolver uma função que exiba os múltiplos de N compreendidos no intervalo 
	definido por A e B.
	
	Exemplo:
	
		N = 3
		A = 10 
		B = 25
		
		Serão exibidos: 12 15 18 21 24
		
		
		N = 8
		A = 20
		B = 40
		
		Serão exibidos: 24 32 40		
*/

//importação de bibliotecas
#include <stdio.h>

//implementação das funções
void exibaMultiplos (int n, int a, int b) 
{
	//declaração de variáveis
	int i;
	
	//variando os números no intervalo de 'a' a 'b'
	for (i=a;i<=b;i++)
	{
		//verificando se 'i' é múltiplo de 'n'
		if (i%n==0)
		{
			printf ("%d ", i);
		}
	}
}

//main
void main ()
{
	//declaração de variáveis
	int numero, inf, sup;
	
	//perguntando os valores ao usuário
	printf ("Entre com um numero: ");
	scanf ("%d", &numero);
	
	printf ("Entre com o intervalo: ");
	scanf ("%d %d", &inf, &sup);
		
	//chamando a função
	exibaMultiplos (numero, inf, sup);
}

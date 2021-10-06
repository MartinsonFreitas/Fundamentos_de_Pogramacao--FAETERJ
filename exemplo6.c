/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 30/08/2021
	
	Revisão - FAC
	
	Desenvolver uma função que calcule a soma dos números de 'num1' a 'num2'
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos/cabeçalhos das funções
int somaNumeros (int num1, int num2);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int valor1, valor2, resultado;
	
	//lendo os valores que representam o intervalo
	printf ("\n\n\nEntre com um numero: ");
	scanf ("%d", &valor1);
	
	printf ("Entre com outro numero: ");
	scanf ("%d", &valor2);
	
	//chamando a função
	resultado = somaNumeros (valor1, valor2);
	
	//exibe o resultado
	printf ("\n\nSoma = %d", resultado);
}

//implementação das demais funções
int somaNumeros (int num1, int num2)
{
	//declaração de variáveis
	int i, soma = 0;
	
	//variando os valores de 'num1' a 'num2' e somando-os
	for (i=num1;i<=num2;i++)
	{
		soma = soma+i;   // soma += i;
	}
	
	//retornar o resultado
	return soma;
}

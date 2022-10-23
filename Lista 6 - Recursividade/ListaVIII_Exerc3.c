/*
	FAETERJ-Rio
	Fundamentos de Programação - 2022/1 - Turma: Noite
	Data: 23/05/2022
	
	Lista de Exercícios VIII (Recursividade)
	
	Questão 03: Fazer uma função recursiva que, dado um número 
	inteiro N, exiba o mesmo na base 2 (binária).
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de protótipos
void binario (int n);

//main
void main ()
{
	//declaração de variáveis
	int numero;
	
	//leitura dos dados de entrada
	printf ("Entre com um numero: ");
	scanf ("%d", &numero);
	
	//chamando a função
	binario (numero);
}

//implementação das funções
void binario (int n)
{
	if (n > 0)	//caso geral
	{
    	binario (n/2);
    	printf ("%d", n%2);		//nessa ordem, garante-se que os restos 
								//serão exibidos na ordem correta
  	}
  	//caso base implícito: n <= 0
}

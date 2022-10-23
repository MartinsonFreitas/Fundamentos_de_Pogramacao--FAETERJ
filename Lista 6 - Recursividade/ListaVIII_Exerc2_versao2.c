/*
	FAETERJ-Rio
	Fundamentos de Programação - 2022/1 - Turma: Noite
	Data: 23/05/2022
	
	Lista de Exercícios VIII (Recursividade)
	
	Questão 02: Desenvolver uma função recursiva que exiba todos os 
	múltiplos do número N, inferiores ou iguais ao valor V.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de protótipos
void funcao (int n, int v, int x);		//a função recursiva
void exibirMultiplos (int n, int v);	//a função que será chamada na main

//main
void main ()
{
	//declaração de variáveis
	int numero, limite;
	
	//leitura dos dados de entrada
	printf ("Entre com um numero: ");
	scanf ("%d", &numero);
	
	printf ("Entre com o limite: ");
	scanf ("%d", &limite);
	
	//chamando a função
	exibirMultiplos (numero, limite);
}

//implementação das funções
void funcao (int n, int v, int x)
{
	if(x <= v)		//caso geral
	{
		//exibindo ca múltiplo de n
		printf ("%d ", x);
    	    	
    	//chamando a função recursivamente
    	funcao (n, v, x + n);  //pulando de 'n' em 'n'
  	}
  	//caso base implícito: x > v
}

void exibirMultiplos(int n, int v)
{
  	funcao (n, v, 0);	//começando a variação com 0
}

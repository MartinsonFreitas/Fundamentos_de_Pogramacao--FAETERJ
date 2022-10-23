/*
	FAETERJ-Rio
	Fundamentos de Programação - 2022/1 - Turma: Noite
	Data: 23/05/2022
	
	Lista de Exercícios VIII (Recursividade)
	
	Questão 04: Pede-se a implementação de uma função recursiva que 
	exiba os n primeiros termos de uma PG (Progressão Geométrica), 
	onde a1 é o seu primeiro termo e q a razão.
	
	Observação: uma PG consiste em uma sequência de valores, 
	iniciadas pelo valor a1. Os demais elementos são definidos como 
	o anterior multiplicado pela razão.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de protótipos
void PG (int n, int a1, int q);

//main
void main ()
{
	//declaração de variáveis
	int termo1, razao, quantidade;
	
	//leitura dos dados de entrada
	printf ("Entre com o primeiro termo: ");
	scanf ("%d", &termo1);
	
	printf ("Entre com a razao: ");
	scanf ("%d", &razao);
	
	printf ("Entre com a quantidade: ");
	scanf ("%d", &quantidade);
	
	//chamando a função
	PG (quantidade, termo1, razao);
}

//implementação das funções
void PG (int n, int a1, int q)
{
	if (n > 0)	//caso geral: "enquanto" existirem valores a exibir...
	{
    	printf ("%d ", a1);
    	PG (n-1, a1*q, q);
  	}
}

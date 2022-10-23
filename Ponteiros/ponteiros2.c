/*
	FAETERJ-Rio
	FPR - Noite		Professor Leonardo Vianna
	Data: 29/11/2021
	
	Ponteiros
*/

//importação de bibliotecas
#include <stdio.h>

void main ()
{
	//declaração de variáveis
	int a, b;		//armazenam números inteiros
	int *p, *q;		//armazenam endereços de memórias nos quais encontramos números inteiros
	
	...
	
	a = b;		//válido; o valor armazenado em 'b' é copiado para 'a'
	
	a = *p;		//válido
		
	p = &b;		//válido
	
	p = q;		//válido; o endereço de memória armazenado em 'q' é copiado para 'p'
	
	...
}

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
	int i;
	char vetor[5] = {'R', 'G', 'Y', 'O', 'F'};
	char *p;
	
	//vetor: endereço de memória inicial do vetor
	//ou: endereço da posição vetor[0]
	
	p = vetor;
	
	for (i=0;i<5;i++)
	{
		printf ("%c (endereço %p)", *p, p);
		p++;
	}
}

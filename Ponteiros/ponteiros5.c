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
	int vetor[5] = {5,1,8,9,7};
		
	//vetor: endereço de memória inicial do vetor
	//ou: endereço da posição vetor[0]
			
	for (i=0;i<5;i++)
	{
		printf ("%d ", *(vetor+i));  //vetor[i]  =   *(vetor+i)
	}
}

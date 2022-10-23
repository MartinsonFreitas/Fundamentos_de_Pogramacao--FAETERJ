/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR
	2022/1  -  Turma: Noite
	
	Data: 30/05/2022
	
	Ponteiros
*/

//importação de bibliotecas
#include <stdio.h>

//main 
void main ()
{
	//declaração de variáveis
	int v[5] = {1,2,3,4,5};
	int i, *x;

	x = v;
	
	for (i=0;i<5;i++)
	{
		printf ("%d ", *(x+i));	
	}
}

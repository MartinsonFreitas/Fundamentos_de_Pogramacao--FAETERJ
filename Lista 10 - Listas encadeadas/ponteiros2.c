/*
	FAETERJ-Rio
	Fundamentos de Programa��o - FPR
	2022/1  -  Turma: Noite
	
	Data: 30/05/2022
	
	Ponteiros
*/

//importa��o de bibliotecas
#include <stdio.h>

//main 
void main ()
{
	//declara��o de vari�veis
	int a, b,		//armazenam valores inteiros
	    *p, *q;		//armazenam endere�os de mem�ria cujos conte�dos s�o valores inteiros

	...
	
	a = b;  //comando v�lido
	a = *p; //comando tornou-se v�lido com a inclus�o do *
	q = &b;	//comando tornou-se v�lido com a inclus�o do &    
	p = q;	//comando v�lido	
}

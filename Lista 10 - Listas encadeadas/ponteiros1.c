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
	int a, b,		//armazenam valores inteiros
	    *p, *q;		//armazenam endereços de memória cujos conteúdos são valores inteiros

	...
	
	a = b;  //comando válido
	a = p;  //comando inválido, pois manipula variáveis de tipos incompatíveis
	q = b;	//comando inválido, pois manipula variáveis de tipos incompatíveis	    
	p = q;	//comando válido	
}

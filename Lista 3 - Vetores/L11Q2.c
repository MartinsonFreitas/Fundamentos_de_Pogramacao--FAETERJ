/*

	Questao 02:
		
		Considere a existencia de dois conjuntos
		numericos A e B contendo n1 e n2 elementos,
		respectivamente. 
		Pede-se o desenvolvimento de uma funcao
		que determine se um dos	conjuntos esta 
		contido no outro, retornando os seguintes codigos:
		
		- 1, se A estiver contido em B;
		- 2, se B estiver contido em A;
		- 0, caso contrario.

*/

#include <stdio.h>

int contido (int A[], int B[], int quantA, int quantB)
{
	//Variáveis locais da função
	int i, j, contBA=0, contAB=0;
	
	//Verificando se B está contido em A
	//Percorrendo vetor A
	for (i=0; i<quantA; i++)
	{
		//Percorrendo vetor B
		for (j=0; j<quantB; j++)
		{
			if (A[i] == B[j])
			{
				contBA++;
			}
		}
	} 
	
	//Verificando se A está contido em B
	//Percorrendo vetor B
	for (i=0; i<quantB; i++)
	{
		//Percorrendo vetor A
		for (j=0; j<quantA; j++)
		{
			if (B[i] == A[j])
			{
				contAB++;
			}
		}
	} 
	
	if ((contAB == quantA) && (contBA == quantB))
	{
		return 0;
	}
	else
	{
		if(contAB == quantA)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}

void main ()
{
	int A[3] = {1,2,3};
	int B[3] = {1,2,3};
	int retorno;
	
	retorno = contido (A, B, 3, 3); //5 = quantA, 3 = quantB
	
	if (retorno == 1)
	{
		printf("A esta contido em B");
	}
	else
	{
		if (retorno == 2)
		{
			printf("B esta contido em A");
		}
		else
		{
			printf("Nao atende nenhuma das condicoes do enunciado");
		}	
	}
}

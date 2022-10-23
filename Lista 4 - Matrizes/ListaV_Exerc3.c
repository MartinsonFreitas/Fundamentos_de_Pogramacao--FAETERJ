/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 28/03/2022
	
	Lista de Exercícios V (matrizes):
	
	QUESTÃO 03: Desenvolver uma função que gere a seguinte matriz M5x5: 
 
 						1 2 3 4 5   
						2 3 4 5 6   
						3 4 5 6 7   
						4 5 6 7 8   
						5 6 7 8 9  
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 5
#define C 5

//protótipos das funções
void preencher (int m[L][C]);
void exibir (int m[L][C]);

//main
void main ()
{
	//declaração de variáveis
	int matriz[L][C];
	
	//preenchendo a matriz conforme especificado no enunciado
	preencher (matriz);
	
	//exibindo a matriz
	printf ("Exibindo a matriz:\n\n");
	exibir (matriz);
}

//implementação das funções
void preencher (int m[L][C])
{
	//declaração de variáveis
	int i, j, cont = 1;

	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			m[i][j] = j+cont;
		}
		
		//atualizando o contador
		cont++;
	}
}

void exibir (int m[L][C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		
		printf ("\n");
	}
}

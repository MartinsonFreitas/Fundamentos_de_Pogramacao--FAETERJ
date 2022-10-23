/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 20/09/2021
	
	MATRIZES
	
	Exemplo 6: Com quais valores é preenchida a matriz pela função "preencher"?
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define L 15
#define C 15

//declaração de protótipos
void preencher (int matriz[L][C]);
void exibir (int matriz[L][C]);

//main
void main ()
{
	//declaração da matriz
	int m[L][C];
		
	//preenchendo a matriz
	preencher (m);
	
	//exibindo a matriz
	exibir (m);
}

//implementação das funções
void preencher (int matriz[L][C])    //O que é feito por esta função???
{
	//declaração de variáveis
	int i, j;
	
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			if (i==j)			//se o nº da linha for igual ao nº da coluna (ou seja, se o elemento pertencer à diagonal principal), esta posição armaxenará o valor 0
			{
				matriz[i][j] = 0;  
			}
			else
			{
				if (i>j)		//se o nº da linha for maior do que nº da coluna (ou seja, se o elemento estiver abaixo da diagonal principal), esta posição armaxenará o valor -1
				{
					matriz[i][j] = -1;
				}
				else
				{
					matriz[i][j] = 1;   //se o nº da linha for menor do que nº da coluna (ou seja, se o elemento estiver acima da diagonal principal), esta posição armaxenará o valor 1
				}
			}
		}
	}
}

void exibir (int matriz[L][C])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\nElementos da matriz:\n");
	for (i=0;i<L;i++)
	{
		for (j=0;j<C;j++)
		{
			printf ("%3d ", matriz[i][j]);
		}
		
		printf ("\n");
	}
}

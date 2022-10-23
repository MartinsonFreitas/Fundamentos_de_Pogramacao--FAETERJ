/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 04/04/2022
	
	Lista de Exercícios V (matrizes):
	
	QUESTÃO 04:
	Fazer uma função que, dada uma matriz M6×6, determine se ela é 
	simétrica.
	
	versão 2: diminuindo o número de comparações, percorrendo apenas
	a matriz triangular superior.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 6
#define C 6

//protótipos das funções
int verificarSimetria (int m[L][C]);

void preencher (int m[L][C]);
void exibir (int m[L][C]);

//main
void main ()
{
	//declaração de variáveis
	int m1[L][C], 
	    m2[L][C] = { {1,3,6,4,7,8},
		             {3,7,5,6,9,8},
		             {6,5,2,5,3,4},
		             {4,6,5,1,7,8},
		             {7,9,3,7,4,1},
		             {8,8,4,8,1,9} },
		resp;
	
	//preenchendo a matriz m1 com números aleatórios
	preencher (m1);
	
	//exibindo a matriz m1
	printf ("Exibindo a matriz m1:\n\n");
	exibir (m1);
	
	//chamando a função
	resp = verificarSimetria (m1);
	
	//exibindo o resultado
	if (resp == 1)
	{
		printf ("\n\nA matriz m1 eh simetrica.");
	}
	else
	{
		printf ("\n\nA matriz m1 nao eh simetrica.");
	}

	
	//exibindo a matriz m2
	printf ("\n\n\nExibindo a matriz m2:\n\n");
	exibir (m2);
	
	//chamando a função
	resp = verificarSimetria (m2);
	
	//exibindo o resultado
	if (resp == 1)
	{
		printf ("\n\nA matriz m2 eh simetrica.");
	}
	else
	{
		printf ("\n\nA matriz m2 nao eh simetrica.");
	}
}

//implementação das funções
int verificarSimetria (int m[L][C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo todas as linhas da matriz
	for (i=0;i<L-1;i++)
	{
		//percorrendo todas as colunas da matriz
		for (j=i+1;j<C;j++)
		{
			//verificando se mij é diferente de mji (e, portanto, a matriz não é simétrica
			if (m[i][j] != m[j][i])
			{
				return 0;			
			}
		}
	}
	
	//se chegou até aqui, é porque todo mij = mji
	return 1;
}

void preencher (int m[L][C])
{
	//declaração de variáveis
	int i, j;

	//garantindo que as sequências aleatórias são diferentes
	srand (time(NULL));
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			m[i][j] = rand()%20 + 1;
		}
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

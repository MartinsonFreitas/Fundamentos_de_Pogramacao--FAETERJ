/*
	FAC - 2021/1
	Data: 29/05/2021
	
	Lista de Exercícios VIII (Funções)
	
	QUESTÃO 08:
	Desenvolver uma função que exiba todos os números primos inferiores a 
	determinado valor inteiro N.
*/

//importação de bibliotecas
#include<stdio.h>

//protótipos das funções
void primo (int n);

//main
void main()
{
	//declaração de variáveis
	int n;
	
	//leitura do valor de entrada
	printf("Digite um numero: ");
	scanf("%d", &n);
	
	//chamando a função
	printf("\nNumeros classifcados como primos menores que %d: ", n);
	primo(n);
}

//implementação das funções
void primo (int n)
{
	//declaração de variáveis
	int i, j, cont;

	//variando os valores no intervalo de 1 a n-1 (ou seja, números inferiores a n)
	for (i=1; i<n; i++)
	{
		//zerando a quantidade de divisores do número do intervalo (i)
		cont=0;

		//verificando quantos divisores o número 'i' possui
		for(j=1; j<=i; j++)
		{
			//verificando se 'j' é divisor de 'i'
			if(i%j==0)
			{
				cont++;
			}
		}
		
		//verificando se 'i' é primo (ou seja, se possui 2 divisores)
		if (cont==2)
		{
			printf("%d ", i);
		}
	}
}


/*
	FAC - 2021/1
	Data: 29/05/2021
	
	Lista de Exercícios VIII (Funções)
	
	QUESTÃO 06:
	Implementar uma função que, dado um número inteiro N, exiba uma sequência de 
	números como as ilustradas nos exemplos a seguir:

	Exemplo 1:  N = 3
 	(1 2) (1 3) (2 1) (2 3) (3 1) (3 2)

	Exemplo 2:  N = 5
 	(1 2) (1 3) (1 4) (1 5) (2 1) (2 3) (2 4) (2 5) (3 1) (3 2) (3 4) (3 5) (4 1) 
	(4 2) (4 3) (4 5) (5 1) (5 2) (5 3) (5 4)
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void sequencia(int n);

//main
void main ()
{
	//declaração de variáveis
    int n;
    
    //leitura do valor de n
    printf ("Entre com um valor: ");
    scanf ("%d", &n);
    printf ("\n");
    
    //chamando a função
	sequencia (n);
}

//implementação das funções
void sequencia(int n)
{
	//declaração de variáveis 
    int i, j;
    
    
    for(i=1;i<=n;i++)
    {
	    for(j=1;j<=n;j++)
	    {	
		    if(j!=i)
		    {
			    printf("(%d %d) ", i, j);	
		    }
		}
		printf ("\n");
    }
}

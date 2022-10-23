/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 25/10/2021
	
	Recursividade
	
	O que é retornado pela função abaixo?
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int funcao (int A, int B);

//implementação da função main
void main ()
{
	//chamando a função
	int x = funcao (32, 6);
	
	//exibindo o resultado
	printf ("\nResultado = %d", x);
}

//implementações das funções
int funcao (int A, int B)
{
   if (A >= B)
   {
      return 1+ funcao (A-B, B);
   }
   else
   {
      return 0;
   }
}


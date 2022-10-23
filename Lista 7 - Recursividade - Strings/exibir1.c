/********************************************************************************************

	FPR - Manhã/Noite
	Professor Leonardo Vianna
	2021/2
	Data: 06/11/2021 (Aula extra)
	
	Exibindo números de maneira recursiva	
		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
void exibir (int n);

//main
void main ()
{
	//chamando a função
	exibir (20);
}

//implementação das funções
void exibir (int n)
{
	if (n > 0)
	{
		printf ("%d ", n);
		exibir (n-1);
	}
}

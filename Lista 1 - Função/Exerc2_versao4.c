/*
	FAC - 2021/1
	Data: 20/05/2021
	
	Lista de Exercícios VIII (Funções)
	
	QUESTÃO 02:
	Implementar uma função que converta determinada temperatura em graus Celsius 
	para graus Fahrenheit.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções
float converte (float tempC);

//main
void main()
{
	int temp;
	
	printf ("Celsius\tFahrenheit\n");
	printf ("--------------\n");
	for (temp=0;temp<=100;temp++)
	{
		printf ("%d C\t%.1f F\n", temp, converte(temp));
	}
}
//implementação das funções
float converte(float tempC)
{
    return (tempC*9/5)+32;
}



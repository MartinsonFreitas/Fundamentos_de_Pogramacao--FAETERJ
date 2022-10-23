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
    float tempC, novaTemp;

    printf("ENTRE COM A TEMPERATURA (C): ");
    scanf("%f",&tempC);

    novaTemp = converte(tempC);
    
    printf("%.1f Celsius para:\n %.1f Fahrenheit",tempC, novaTemp);
}
//implementação das funções
float converte(float tempC)
{
    float tempF;

    tempF = (tempC*9/5)+32;

    return tempF;
}



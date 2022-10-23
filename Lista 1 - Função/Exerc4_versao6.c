/*
	FAC - 2021/1
	Data: 29/05/2021
	
	Lista de Exercícios VIII (Funções)
	
	QUESTÃO 04:
	Fazer uma função que calcule o MDC (máximo divisor comum) entre dois números.
	
	versão 6: variando o FOR descrescentemente, objetivando diminuir o número de 
	iterações (visto que, assim, o resultado será o primeiro divisor comum
	encontrado).
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções

int mdc (int num1, int num2);
int calculaMenor (int a, int b);

//main
void main()
{
	//declaração de variáveis
	int valor1, valor2, resp;
	
	//lendo os valores de entrada
	printf ("Entre com o primeiro valor: ");
	scanf ("%d", &valor1);
	
	printf ("\nEntre com o segundo valor: ");
	scanf ("%d", &valor2);
	
	//chamando a função
	resp = mdc(valor1,valor2);
	
	//exibindo o resultado
	printf ("MDC (%d,%d) = %d", valor1, valor2, resp);
}

//implementação das funções
int mdc (int num1, int num2)
{
	//declaração de variáveis
	int menor, i;
	
	//determinando o menor valor entre num1 e num2
	menor = calculaMenor (num1, num2);

	//===> variando de 'menor' até 1, em busca do MDC
	for (i=menor;i>=1;i--)
	{
		//verificando se 'i' é um divesor comum de 'num1' e 'num2'
		if ((num1%i==0) && (num2%i==0))
		{
			return i;
		}	
	}
}

int calculaMenor (int a, int b)
{
	//determinando quem é o menor entre 'a' e 'b'
	/*if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}*/
	
	return (a<b)?a:b;
}

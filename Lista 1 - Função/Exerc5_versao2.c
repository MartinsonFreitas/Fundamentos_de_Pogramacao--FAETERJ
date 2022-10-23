/*
	FAC - 2021/1
	Data: 29/05/2021
	
	Lista de Exercícios VIII (Funções)
	
	QUESTÃO 05:
	Fazer uma função que calcule o MMC (mínimo múltiplo comum) entre dois números.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração dos protótipos das funções

int mmc (int num1, int num2);
int calculaMaior (int a, int b);

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
	resp = mmc(valor1,valor2);
	
	//exibindo o resultado
	printf ("MMC (%d,%d) = %d", valor1, valor2, resp);
}

//implementação das funções
int mmc (int num1, int num2)
{
	//declaração de variáveis
	int maior, i;
	
	//determinando o maior valor entre num1 e num2
	maior = calculaMaior (num1, num2);

	//variando de 'maior' até ser encontrado um número que seja mútiplo de 'num1' e 'num2'; este será o MMC
	for (i=maior;;i++)
	{
		//verificando se 'i' é um múltiplo comum de 'num1' e 'num2'
		if ((i%num1==0) && (i%num2==0))
		{
			return i;
		}	
	}
	
	/*
	Observação: notem que omitimos a condição de permanência do FOR. Se não existisse
	o comando 'return' dentro do FOR, este ficaria rodando infinitamente por não ter uma 
	condição que o faça parar! Como sabemos que existirá o MMC dos dois números (no pior
	dos casos, o MMC será o produto entre os dois valores), temos a certeza de que o return
	será executado! 
	*/
}

int calculaMaior (int a, int b)
{
	//determinando quem é o menor entre 'a' e 'b'
	/*if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}*/
	
	return (a>b)?a:b;
}

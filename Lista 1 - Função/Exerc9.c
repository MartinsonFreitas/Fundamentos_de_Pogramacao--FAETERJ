/*
	FAC - 2021/1
	Data: 17/06/2021
	
	Lista de Exercícios VIII (Funções)
	
	QUESTÃO 09:
	Implementar uma função que, dado um número inteiro, calcule (e retorne) a soma 
	e a média de seus divisores.
*/

//importação de bibliotecas
#include<stdio.h>

//protótipos das funções
void somaMediaDivisores (int numero, int *soma, float *media);

//main
void main()
{
	//declaração de variáveis
	int n, s;
	float m;
	
	//leitura do valor de entrada
	printf("Digite um numero: ");
	scanf("%d", &n);

	//chamando a função
	somaMediaDivisores (n, &s, &m);
	
	//exibindo os resultados
	printf ("\nSoma dos divisores de %d: %d\n", n, s);
	printf ("\nMedia dos divisores de %d: %.1f\n", n, m);
}

//implementação das funções

/*Dado um número inteiro (numero), calcula a soma e a média de seus divisores.
  Entrada: numero
  Saída:   soma, media   */
void somaMediaDivisores (int numero, int *soma, float *media)
{
	//declaração de variáveis
	int i, sum = 0, cont = 0;
	
	//variando todos os "possíveis" divisores de 'numero'
	for (i=1;i<=numero;i++)
	{
		//verificando se cada valor do intervao é divisor de 'numero'
		if (numero % i == 0)
		{
			//sendo 'i' divisor de 'numero', acumulá-lo no somatório
			sum = sum + i;    //soma += i;
			cont++;
		}
	}
	
	//armazenando os resultados nos parâmetros de saída
	*soma = sum;
	*media = (float)sum/cont;	
}

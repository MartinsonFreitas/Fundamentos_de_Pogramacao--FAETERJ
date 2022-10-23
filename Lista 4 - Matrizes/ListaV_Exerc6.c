/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Professor Leonardo Vianna
	
	Data: 04/04/2022
	
	Lista de Exercícios V (matrizes):
	
	QUESTÃO 06:
	Considere uma loja que mantém em uma matriz o total vendido por cada 
	funcionário pelos diversos meses do ano. Ou seja, uma matriz de 12 
	linhas (uma por mês) e 10 colunas (10 funcionários). Pede-se o 
	desenvolvimento de uma função para cada item abaixo:

	a. Calcular o total vendido durante o ano;
	b. Dado um mês fornecido pelo usuário, determinar o total vendido 
	nesse mês;
	c. Dado um funcionário fornecido pelo usuário, determinar o total 
	vendido por ele durante o ano;
	d. Determinar o mês com maior índice de vendas;
	e. Determinar o funcionário que menos vendeu durante o ano.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define L 12
#define C 10

//protótipos das funções
float totalVendidoAno (float m[L][C]);
float totalVendidoMes (float m[L][C], int mes);
float totalVendidoFuncionario (float m[L][C], int funcionario);
int mesMaiorIndiceVendas (float m[L][C]);
int funcionarioMenorIndiceVendas (float m[L][C]);

void preencher (float m[L][C]);
void exibirMatriz (float m[L][C]);

//main
void main ()
{
	//declaração de variáveis
	int mes, funcionario;
	float matriz[L][C];
	float total, totalMes, totalFuncionario;

	//preenchendo a matriz com valores randômicos
	preencher (matriz);
	
	//exibindo a matriz
	exibirMatriz (matriz);
	
	//calculando o total vendido no ano
	total = totalVendidoAno (matriz);
	printf ("Total vendido no ano: R$ %.2f\n\n", total);

	//calculando o total vendido em determinado mês
	printf ("Entre com o mes desejado: ");
	scanf ("%d", &mes);
	
	totalMes = totalVendidoMes (matriz, mes);
	printf ("Total vendido no mes %d: R$ %.2f\n\n", mes, totalMes);

	//calculando o total vendido por determinado funcionário
	printf ("Entre com o funcionario desejado: ");
	scanf ("%d", &funcionario);
	
	totalFuncionario = totalVendidoFuncionario (matriz, funcionario);
	printf ("Total vendido pelo funcionario %d: R$ %.2f\n\n", funcionario, totalFuncionario);

	//determinando o mês com maior índice de vendas
	printf ("\nMes com maior indice de vendas: %d\n\n", mesMaiorIndiceVendas (matriz));

	//determinando o funcionário com menor índice de vendas
	printf ("\nFuncionario com menor indice de vendas: %d\n\n", funcionarioMenorIndiceVendas (matriz));
}

//implementação das funções
void preencher (float m[L][C])
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
			m[i][j] = rand()%5 + 1;
		}
	}
}

void exibirMatriz (float m[L][C])
{
	//declaração de variáveis
	int i, j;
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			printf ("%.2f ", m[i][j]);
		}
		
		printf ("\n");
	}
}

float totalVendidoAno (float m[L][C])
{
	//declaração de variáveis
	int i, j;
	float soma = 0;
	
	//percorrendo as linhas da matriz
	for (i=0;i<L;i++)
	{
		//percorrendo as colunas da matriz
		for (j=0;j<C;j++)
		{
			soma = soma + m[i][j]; //soma += m[i][j];
		}
	}
	
	//retornando o resultado
	return soma;
}

float totalVendidoMes (float m[L][C], int mes)
{
	//declaração de variáveis
	int j;
	float soma = 0;
	
	//convertendo mês de 1..12 para o intervalo de 0..11
	mes--;
	
	//calculando o total vendido no mês fornecido
	for (j=0;j<C;j++)
	{
		soma += m[mes][j];	
	}
	
	//retornando o resultado
	return soma;
}

float totalVendidoFuncionario (float m[L][C], int funcionario)
{
	//declaração de variáveis
	int i;
	float soma = 0;
	
	//convertendo funcionário de 1..10 para o intervalo de 0..9
	funcionario--;
	
	//calculando o total vendido pelo funcionário fornecido
	for (i=0;i<L;i++)
	{
		soma += m[i][funcionario];	
	}
	
	//retornando o resultado
	return soma;	
}

int mesMaiorIndiceVendas (float m[L][C])
{
	//declaração de variáveis
	int mes, maiorMes;
	float resultado, maior = -1;
	
	//percorrendo todos os meses do ano
	for (mes=1;mes<=L;mes++)
	{
		//calculando o total vendido em cada mês
		resultado = totalVendidoMes (m, mes);
		
		//verificando se o total vendido no mês corrente é o maior de todos
		if (resultado > maior)
		{
			//atualizando os dados do mês com maior índice de vendas
			maior = resultado;
			maiorMes = mes;
		}
	}
	
	//retornando o mês com maior índice de vendas
	return maiorMes;
}

int funcionarioMenorIndiceVendas (float m[L][C])
{
	//declaração de variáveis
	int funcionario, menorFuncionario = 1;
	float resultado, menor = totalVendidoFuncionario (m,1);
	
	//percorrendo todos os funcionários
	for (funcionario=2;funcionario<=C;funcionario++)
	{
		//calculando o total vendido por cada funcionário
		resultado = totalVendidoFuncionario (m, funcionario);
		
		//verificando se o total vendido pelo funcionário corrente é o menor de todos
		if (resultado < menor)
		{
			//atualizando os dados do funcionário com menor índice de vendas
			menor  = resultado;
			menorFuncionario = funcionario;
		}
	}
	
	//retornando o funcionário com menor índice de vendas
	return menorFuncionario;
}

/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna
	Data: 04/10/2021
	
	Lista de Exercícios IV - Matrizes
	
	QUESTÃO 06:
	Considere uma loja que mantém em uma matriz o total vendido por cada funcionário pelos diversos meses 
	do ano. Ou seja, uma matriz de 12 linhas (uma por mês) e 10 colunas (10 funcionários). Pede-se o 
	desenvolvimento de uma função para cada item abaixo:
	a.	Calcular o total vendido durante o ano;
	b.	Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês;
	c.	Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano;
	d.	Determinar o mês com maior índice de vendas;
	e.	Determinar o funcionário que menos vendeu durante o ano.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definição de constantes
#define MESES 12
#define FUNC 10

//protótipos/cabeçalhos das funções

//Calcular o total vendido durante o ano
float totalVendido (float matriz[MESES][FUNC]);

//Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês
float totalVendidoMes (float matriz[MESES][FUNC], int mes);

//Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano
float totalVendidoFuncionario (float matriz[MESES][FUNC], int funcionario);

//Determinar o mês com maior índice de vendas
int mesMaiorIndiceVendas (float matriz[MESES][FUNC]);

//Determinar o funcionário que menos vendeu durante o ano
int funcMenorIndiceVendas (float matriz[MESES][FUNC]);

//funções auxiliares
void preencherAleatorio (float matriz[MESES][FUNC]);
void exibirMatriz (float matriz[MESES][FUNC]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	float m[MESES][FUNC];
	float total;
	int mes, funcionario;
	
	//preenchendo a matriz com valores aleatórios
	preencherAleatorio (m);
	
	//exibindo a matriz
	exibirMatriz (m);	
	
	//Total vendido durante o ano
	total = totalVendido (m);
	printf ("\n\nTotal vendido no ano: R$ %.2f\n", total);

	//Total vendido em determinado mês
	printf ("\nEntre com o mes desejado (de 1 a 12): ");
	scanf ("%d", &mes);
	total = totalVendidoMes (m, mes);
	printf ("\nTotal vendido no mes %d: R$ %.2f\n", mes, total);

	//Total vendido por determinado funcionário
	printf ("\nEntre com o funcionario desejado (de 1 a 10): ");
	scanf ("%d", &funcionario);
	total = totalVendidoFuncionario (m, funcionario);
	printf ("\nTotal vendido pelo funcionario %d: R$ %.2f\n", funcionario, total);

	//Mes com maior índice de vendas
	mes = mesMaiorIndiceVendas (m);
	printf ("\nMes com maior indice de vendas: %d\n", mes);
	
	//Funcionário com menor índice de vendas
	funcionario = funcMenorIndiceVendas (m);
	printf ("\nFuncionario com menor indice de vendas: %d\n", funcionario);	
}

//implementação das demais funções
void exibirMatriz (float matriz[MESES][FUNC])
{
	//declaração de variáveis
	int i, j;
	
	printf ("\n\n");
	
	//percorrendo todas as posições da matriz
	for (i=0;i<MESES;i++)			//percorrendo todas as linhas da matriz
	{
		for (j=0;j<FUNC;j++)		//percorrendo todas as colunas da matriz
		{
			printf ("R$ %8.2f    ", matriz[i][j]);
		}
		printf ("\n");
	}	
	printf ("\n\n");
}

void preencherAleatorio (float matriz[MESES][FUNC])
{
	//declaração de variáveis
	int i, j;
	
	srand (time(NULL));
	
	//percorrendo todas as posições da matriz
	for (i=0;i<MESES;i++)			//percorrendo todas as linhas da matriz
	{
		for (j=0;j<FUNC;j++)		//percorrendo todas as colunas da matriz
		{
			matriz[i][j] = 1+rand()%10000; //preenchendo a matriz com valores aleatórios no intervalo de 1 a 10000
		}
	}
}

//Calcular o total vendido durante o ano
float totalVendido (float matriz[MESES][FUNC])
{
	//declaração de variáveis
	int i,j;
	float total=0;
	
	for(i=0;i<MESES;i++)		//variando as linhas da matriz
	{
    	for(j=0;j<FUNC;j++)		//variando as colunas da matriz
		{
        	total=total+matriz[i][j]; // soma+= m[i][j];
    	}
	}
	
	//retornando o resultado
	return total;
}

//Dado um mês fornecido pelo usuário, determinar o total vendido nesse mês
float totalVendidoMes (float matriz[MESES][FUNC], int mes)
{
	//declaração de variáveis
	int j;
	float totalMes=0;
	
	//converteu o mês do intervalo de 1 a 12 (fornecido pelo usuário) para 
	//o intervalo de 0 a 11 (compreendido pela linguagem C)
	mes--;

	//percorrendo todas as colunas da linha representada pelo mês escolhido			
	for(j=0;j<FUNC;j++)
	{
		totalMes += matriz[mes][j];
	}
	
	//retornando o resultado (ou seja, o total vendido no mês passado por parâmetro)
	return totalMes;
}

/* outra versão da função acima. Porém, ao percorrer toda a matriz, esta versão mostra-se muito CARA!
Se colocar na prova, perderá ponto! :)
float totalVendidoMes (float matriz[MESES][FUNC], int mes)
{
	//declaração de variáveis
	int j;
	float totalMes=0;
	
	//converteu o mês do intervalo de 1 a 12 (fornecido pelo usuário) para o intervalo de 0 a 11 (compreendido pela linguagem C)
	mes--;
	//percorrendo todas as linhas da matriz
	for (i=0;i<MESES;i++)
	{
		//percorrendo todas as colunas da matriz
		for(j=0;j<FUNC;j++)
		{
			if (i == mes)
			{
				totalMes += matriz[i][j];
			}
		}
	}
	
	//retornando o resultado (ou seja, o total vendido no mês passado por parâmetro)
	return totalMes;
}
*/

//Dado um funcionário fornecido pelo usuário, determinar o total vendido por ele durante o ano
float totalVendidoFuncionario (float matriz[MESES][FUNC], int funcionario)
{
	//declaração de variáveis
	int i;
	float totalFunc=0;
	
	//converteu o funcionário do intervalo de 1 a 10 (fornecido pelo usuário) para o intervalo de 0 a 9 (compreendido pela linguagem C)
	funcionario--;

	//percorrendo todas as linhas da coluna representada pelo funcionário escolhido			
	for(i=0;i<MESES;i++)
	{
		totalFunc += matriz[i][funcionario];
	}
	
	//retornando o resultado (ou seja, o total vendido pelo funcionário passado por parâmetro)
	return totalFunc;
}

//Determinar o mês com maior índice de vendas
int mesMaiorIndiceVendas (float matriz[MESES][FUNC])
{
	//declaração de variáveis
	int mes, maiorMes;
	float total, totalMaiorMes;
	
	//inicializando 'janeiro' como o mês com maior índice de vendas
	totalMaiorMes = totalVendidoMes (matriz, 1);
	maiorMes = 1;
	
	//percorrendo os demais meses; ou seja, de 'fevereiro' a 'dezembro'
	for (mes=2;mes<=MESES;mes++)
	{
		//calculando o quanto foi vendido no mês 'mes'
		total = totalVendidoMes (matriz, mes);
		
		//verificando se o total vendido no mês 'mes' é o maior até o momento
		if(total > totalMaiorMes)
		{
			totalMaiorMes = total;
			maiorMes = mes;
		}
	}
	
	//retornar o resultado (ou seja, o mês com maior índice de vendas)
	return maiorMes;
}

//Determinar o funcionário que menos vendeu durante o ano
int funcMenorIndiceVendas (float matriz[MESES][FUNC])
{
	//declaração de variáveis
	int funcionario, menorFuncionario = 1;
	float total, totalMenorFuncionario;
	
	//inicializando o funcionário 1 como aquele com menor índice de vendas
	totalMenorFuncionario = totalVendidoFuncionario (matriz, 1);
	//menorFuncionario = 1;
	
	//percorrendo os demais funcionários ou seja, do 2º ao 10º
	for (funcionario=2;funcionario<=FUNC;funcionario++)
	{
		//calculando o quanto foi vendido pelo funcionário 'funcionario'
		total = totalVendidoFuncionario (matriz, funcionario);
		
		//verificando se o total vendido pelo funcionário 'funcionario' é o menor até o momento
		if(total < totalMenorFuncionario)
		{
			totalMenorFuncionario = total;
			menorFuncionario = funcionario;
		}
	}
	
	//retornar o resultado (ou seja, o funcionário com menor índice de vendas)
	return menorFuncionario;
}

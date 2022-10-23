/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Data: 18/04/2022
	
	Arquivos
	
	Exemplo 1: desenvolver um programa que escreva em um arquivo os números de 1 a N.
*/

//importação de bibliotecas
#include <stdio.h>

//main
void main ()
{
	//declaração de variáveis
	int n, i;
	FILE *arquivo;			//1. declarar uma variável do tipo FILE*
	char nomeArq[20];
	
	//lendo o valor de N
	printf ("Entre com um numero inteiro: ");
	scanf ("%d", &n);
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser criado: ");
	fflush (stdin);
	gets (nomeArq);
	
	//2.abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
	arquivo = fopen (nomeArq, "w");  //w - write    r - read    a - append
	
	//testando se houve falha na abertura
	if (arquivo == NULL)
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		//escrevendo os elementos de 1 até N no arquivo
		for (i=1;i<=n;i++)
		{
			fprintf (arquivo, "%d\n", i);		//3. manipular o arquivo
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		//exibindo uma mensagem de sucesso
		printf ("\nArquivo gerado com sucesso!");
	}
}

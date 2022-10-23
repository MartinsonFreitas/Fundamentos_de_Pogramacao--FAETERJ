/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Data: 18/04/2022
	
	Arquivos
	
	Exemplo 3: desenvolver uma função que escreva em um arquivo os números de 1 a N (usando append).
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int gerarArquivo (char nomeArq[], int n);

//main
void main ()
{
	//declaração de variáveis
	int n;
	char nomeArq[20];
	
	//lendo o valor de N
	printf ("Entre com um numero inteiro: ");
	scanf ("%d", &n);
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser criado: ");
	fflush (stdin);
	gets (nomeArq);
	
	//chamando a função
	if (gerarArquivo (nomeArq, n) == FALSE)
	{
		printf ("\nErro na geracao do arquivo!");
	}
	else
	{
		printf ("\nArquivo gerado com sucesso!");
	}
}

int gerarArquivo (char nomeArq[], int n)
{
	//declaração de variáveis
	int i;
	FILE *arquivo;			//1. declarar uma variável do tipo FILE*
		
	//2.abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
	arquivo = fopen (nomeArq, "a");  //w - write    r - read    a - append
	
	//testando se houve falha na abertura
	if (arquivo == NULL)
	{
		return FALSE;
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
		
		return TRUE;
	}
}

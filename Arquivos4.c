/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Data: 18/04/2022
	
	Arquivos
	
	Exemplo 4: lendo os dados de um arquivo.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int lerArquivo (char nomeArq[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeArq[20];
	
	//lendo o nome do arquivo
	printf ("Entre com o nome do arquivo a ser lido: ");
	fflush (stdin);
	gets (nomeArq);
	
	//chamando a função
	if (lerArquivo (nomeArq) == FALSE) 
	{
		printf ("\nErro na abertura do arquivo!");
	}
	else
	{
		printf ("\nArquivo aberto com sucesso!");
	}
}

int lerArquivo (char nomeArq[])
{
	//declaração de variáveis
	FILE *arquivo;			//1. declarar uma variável do tipo FILE*
	int numero;
		
	//2.abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
	arquivo = fopen (nomeArq, "r");  //w - write    r - read    a - append
	
	//testando se houve falha na abertura
	if (arquivo == NULL)
	{
		return FALSE;
	}
	else
	{
		//lendo os elementos do arquivo
		while (fscanf (arquivo, "%d", &numero) != EOF)    //EOF - End Of File
		{
			//exibindo na tela os valores lidos do arquivo
			printf ("%d\n", numero);
		}
		
		//4. fechar o arquivo
		fclose (arquivo);
		
		return TRUE;
	}
}

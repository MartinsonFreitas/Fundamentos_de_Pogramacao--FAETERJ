/*
	FAETERJ-Rio
	FPR - Noite - 2022/1
	Data: 18/04/2022
	
	Arquivos
	
	Exemplo 6: copiando o conteúdo de um arquivo para outro.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int copiarArquivo (char origem[], char destino[]);

//main
void main ()
{
	//declaração de variáveis
	char nomeOrigem[20], nomeDestino[20];
	
	//lendo o nome do arquivo origem
	printf ("Entre com o nome do arquivo a ser copiado: ");
	fflush (stdin);
	gets (nomeOrigem);
	
	//lendo o nome do arquivo destino
	printf ("Entre com o nome do arquivo a ser gerado: ");
	fflush (stdin);
	gets (nomeDestino);
	
	//chamando a função
	if (copiarArquivo (nomeOrigem, nomeDestino) == FALSE) 
	{
		printf ("\nErro na copia dos arquivos!");
	}
	else
	{
		printf ("\nCopia realizada com sucesso!");
	}
}

int copiarArquivo (char origem[], char destino[])
{
	//declaração de variáveis
	FILE *arqO, *arqD;			//1. declarar uma variável do tipo FILE*
	char caracter;
		
	//2.abrir o arquivo (associa a variável FILE à string que representa o arquivo / define o tipo de acesso)
	arqO = fopen (origem, "r");
	arqD = fopen (destino, "w");
	
	//testando se houve falha na abertura
	if ((arqO == NULL) || (arqD == NULL))
	{
		return FALSE;
	}
	else
	{
		//lendo os elementos do arquivo de origem
		while (fscanf (arqO, "%c", &caracter) != EOF)    //EOF - End Of File
		{
			//escrevendo no arquivo de destino os valores lidos do arquivo de origem
			fprintf (arqD, "%c", caracter);
		}
		
		//4. fechar os arquivos
		fclose (arqO);
		fclose (arqD);
		
		return TRUE;
	}
}

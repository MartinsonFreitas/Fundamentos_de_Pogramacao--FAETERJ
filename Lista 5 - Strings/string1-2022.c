/*	FAETERJ-Rio
	FPR - Fundamentos de Programação			2022/1
	Professor Leonardo Vianna
	Data: 14/03/2022
	
	STRINGS
	
	Exemplo 1: Desenvolver uma função que, dadas uma string 's' e uma letra 'l', 
	           determinar o número de ocorrências de 'l' em 's'
	           
	           (versão 01: usando scanf para strings)
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos de funções
int numOcorrencias (char s[]/*, int tamanho*/, char L);
//O parâmetro 'tamanho' foi removido, uma vez que a presença do caracter '\0' auxilia na determinação do tamanho da string

//main
void main ()
{	
	//declaração de variáveis
	char palavra[20];	//string
	char letra;
	int quant;
	
	//leitura dos dados de entrada
	printf ("Entre com a palavra: ");
	fflush (stdin);
	scanf ("%s", palavra);
	
	printf ("Entre com a letra a ser buscada: ");
	fflush (stdin);  //esvaziando o buffer de entrada
	scanf ("%c", &letra);
	
	//chamando a função
	quant = numOcorrencias (palavra, letra);
	
	//exibindo o resultado 
	printf ("\nA letra %c foi encontrada %d vezes na string %s.", letra, quant, palavra);
}


//implementação das funções
int numOcorrencias (char s[]/*, int tamanho*/, char L)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo o vetor
	for (i=0;s[i]!='\0';i++)
	{
		//verificando se o valor buscado foi encontrado
		if (s[i] == L)
		{
			cont++;
		}
	}
	
	//retornando o resultado
	return cont;
}

/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 11/10/2021
	
	STRINGS
	
	Exercício 5: Remover todas as ocorrências de determinado caracter em uma string.
	
	Exemplo: 	string: 		ALGORITMOS
				caracter: O		ALG RITM S
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos/cabeçalhos das funções
//void inverteString (char *string);  ou
void removeLetra (char string[], char letra);

int contandostring (char str[]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	char string[30];	
	char caracter;
		
	fflush (stdin);  //standard input - entrada padrão	
	//leitura de uma string
	printf ("Entre com uma string: ");
	gets (string);  //get string
	
	fflush (stdin);  //standard input - entrada padrão	
	//leitura de um caracter
	printf ("Entre com o caracter a ser removido: ");
	caracter = getche();
	
	//exibindo a string antes da remoção
	printf ("\nString: %s\n", string);
	
	//chamando a função
	removeLetra (string, caracter);
	
	//exibindo a string depois da remoção
	printf ("\nString: %s\n", string);
}

//implementação das demais funções
int contandostring (char str[])
{
	//declaração de variáveis
	int i;
	
	//percorrendo os caracteres da string
	for (i=0;str[i]!='\0';i++);
		
	return i;
}

void removeLetra (char string[], char letra)
{
	//declaração de variáveis
    int i, j, tamanhoString;
    
    //recuperando a posição do último caracter
    tamanhoString = contandostring(string);
    
    //percorrendo toda a string
    i=0;
    while (string[i]!='\0')
    {
    	//verificando se é o caracter a ser removido
        if (string[i] == letra)
        {
        	//deslocando todos os caracteres à direita de string[i] (incluindo o \0) uma posição para a esquerda
            for (j=i;j<tamanhoString;j++)
            {
                string[j] = string[j+1];
            }
            
			//uma vez que um caracter foi removido da string, o tamanho da string diminuiu de uma unidade
			tamanhoString--;            
        }
        else
        {
        	i++;
		}
    }
}

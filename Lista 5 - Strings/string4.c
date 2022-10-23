/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 11/10/2021
	
	STRINGS
	
	Exercício 4: Inverter uma string.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos/cabeçalhos das funções
//void inverteString (char *string);  ou
void inverteString (char string[]);

int contandostring (char str[]);

//implementação da função main
void main ()
{
	//declaração de variáveis
	char string[30];	
	
	fflush (stdin);  //standard input - entrada padrão
	
	//leitura de uma string
	printf ("Entre com uma string: ");
	gets (string);  //get string
	
	//chamando a função
	inverteString (string);
	
	//exibindo o resultado
	printf ("\n\nApos inversao: %s", string);
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

void inverteString (char string[])
{
	//declaração de variáveis
    int i,j;
    char aux;
    
    //j apontando para o último caracter
    j=contandostring(string)-1;    
    
    for (i=0;i<j;i++,j--)
    {
    	//troca de posições os caracteres string[i] e string[j]
        aux=string[i];
        string[i]=string[j];
        string[j]=aux;
    }    
}

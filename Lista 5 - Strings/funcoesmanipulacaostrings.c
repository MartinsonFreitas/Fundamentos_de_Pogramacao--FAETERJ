/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 11/10/2021
	
	STRINGS
	
	Exemplo do uso das funções strlen, strcpy, strcat, strcmp
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//implementação da função main
void main ()
{
	//declaração de variáveis
	char s1[30], s2[30], s3[30], s4[30];
	
	//inicializando as strings
	strcpy (s1, "ALGORITMOS");
	strcpy (s2, "FPR");
	strcpy (s3, s1);
	strcpy (s4, s2);
	strcat (s4, s3);
		
	//exibindo as strings e seus tamanhos
	printf ("Valores das strings:\n\n");
	printf ("s1: %s (%d caracteres)\n", s1, strlen(s1));
	printf ("s2: %s (%d caracteres)\n", s2, strlen(s2));
	printf ("s3: %s (%d caracteres)\n", s3, strlen(s3));
	printf ("s4: %s (%d caracteres)\n", s4, strlen(s4));
	
	//comparando as strings e exibindo o retorno de strcmp
	printf ("\n\nstrcmp (%s,%s) = %d\n", s1, s2, strcmp(s1,s2));
	printf ("strcmp (%s,%s) = %d\n", s1, s3, strcmp(s1,s3));
	printf ("strcmp (%s,%s) = %d\n", s4, s2, strcmp(s4,s2));
}


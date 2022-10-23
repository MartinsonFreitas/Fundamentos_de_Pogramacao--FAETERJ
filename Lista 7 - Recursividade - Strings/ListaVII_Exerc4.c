/********************************************************************************************

	FPR - Manhã/Noite
	Professor Leonardo Vianna
	2021/2
	Data: 06/11/2021 (Aula extra)
	
	Lista de Exercícios VII
	
	Questão 04:
	Desenvolver uma função recursiva que, dada uma string, exiba-a invertida.
		
*******************************************************************************************/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
void exibirInvertido (char s[]);
void exibirInvertidoAux (char s[], int pos);

//função main
void main ()
{
	exibirInvertido ("ALGORITMOS");
}
	
//implementação das funções
void exibirInvertido (char s[])
{
	//passando, inicialmente, a última posição da string
	exibirInvertidoAux (s, strlen(s)-1);
}

void exibirInvertidoAux (char s[], int pos)
{
	//exibirá os caracteres até a posição 0
	if (pos >= 0)
	{
		printf ("%c", s[pos]);			//printa o caracter atual
		exibirInvertidoAux (s, pos-1);	//chama a recursão para exibir os caracteres anteriores
	}
}

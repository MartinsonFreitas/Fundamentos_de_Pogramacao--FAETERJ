/*
	FPR - Manhã/Noite
	Professor Leonardo Vianna
	2021/2
	Data: 06/11/2021 (Aula extra)
	
	Lista de Exercícios VII

	Questão 06:
	Implementar uma função recursiva que, dados uma string str e um caracter ch, remova 
	de str todas as ocorrências de ch, retornando o total de remoções realizadas.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int remover (char str[], char ch);
int removerAux (char str[], char ch, int pos);

void main ()
{
	//declaração de variáveis
	int quant;
	char s[30];
	char letra = 'O';				//caracter a ser removido da string
	
	//inicializando a string
	strcpy (s, "ALGORITMOS");
	
	//chamando a função
	quant = remover (s, letra);		

	//exibindo o resultado
	printf ("\nForam realizadas %d remocoes do caracter %c.\nString apos a remocao: %s", quant, letra, s);
}

//implementação das funções
int remover (char str[], char ch)
{
	return removerAux (str, ch, 0);		//começando da posição 0
}

int removerAux (char str[], char ch, int pos)
{
	//declaração de variáveis
	int i;
	
	//caso base: terminou a string 'str'
	if (str[pos] == '\0')
	{
		return 0;
	}
	else
	{
		//verificando se o caracter foi encontrado
		if (str[pos] == ch)
		{
			//remover o caracter, através do deslocamento dos próximos caracteres para a esquerda
			for (i=pos;i<strlen(str);i++)
			{
				str[i] = str[i+1];
			}
			
			return 1 + removerAux (str, ch, pos+1); //+1, pois foi feita mais uma alteração
		}
		else
		{
			return removerAux (str, ch, pos+1);
		}
	}
}

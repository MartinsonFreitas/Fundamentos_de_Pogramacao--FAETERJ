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
int contar (char str[], char ch);
int contarAux (char str[], char ch, int pos);

void main ()
{
	//declaração de variáveis
	int quant, i;
	char s[30];
	
	
	//inicializando a string
	strcpy (s, "ALGORITMOS");
	
	for(i=0; i<strlen(s); ){
		char letra = s[i];				//caracter a ser removido da string
		//chamando a função
		quant = contar (s, letra);		
	
		//exibindo o resultado
		printf ("\nForam encontradas %d ocorrencia(s) do caracter %c.\n", quant, letra);
	}
	
}

//implementação das funções
int contar (char str[], char ch)
{
	return contarAux (str, ch, 0);		//começando da posição 0
}

int contarAux (char str[], char ch, int pos)
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
			
			return 1 + contarAux (str, ch, pos+1); //+1, pois foi feita mais uma alteração
		}
		else
		{
			return contarAux (str, ch, pos+1);
		}
	}
}

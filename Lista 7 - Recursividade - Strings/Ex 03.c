/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 06/11/2021 - Aula extra
	
	Questão 03:
		Considere a função cuja assinatura é apresentada a seguir:
		int pesquisa (char s1[], char s2[], int ordem) onde:
		
		s1 string contendo diversas informações sobre uma pessoa, 
		separadas pelo caracter | (também termina com |)
		s2 uma informação a ser buscada em s1
		ordem ordem na qual s2 deve ser buscada em s1. 
		
			Por exemplo, se for igual a 3, 
			a função deve verificar se s2 é a terceira informação dentro de s1.
			Pede-se a implementação desta função, 
			sabendo que ela deve retornar 1 se s2 estiver em s1 
			na posição definida por ordem; caso contrário, deve retornar 0.
	
	*/
	
#include <stdio.h>
#include (string.h)

// protótipos das funções
int pesquisa (char s1[], char s2[], int ordem);


// main
void main () {
	
	//declaração de variáveis
	char str1[30], str2[30];
	int resp;
	
	//inicialização de strings
	strcpy(str1, "JOAO DA SILVA|123.456.789-00|06/11/1980|GERENTE|");
	strcpy(str2, "06/11/1980");
	
	//iniciando a ordem
	ordem = 3;
	
	//chamando a função
	resp = pesquisa (str1, str2, ordem);
	
	//exibindo resultado
	if (resp==1){
		printf("\n A string %s esta´ na posicao %d de %s", str2, ordem, str1);
	} else {
		printf("\n A string %s nao esta´ na posicao %d de %s", str2, ordem, str1);
	}

}

//implementação das funções
int pesquisa (char s1[], char s2[], int ordem){
	//declarando variaveis
	int i, pos, cont = 1;
	char nova[30];
	
	//posicionando o 'i' no primeiro caracter que está na posição 'ordem' de 's1'
	for (i=0, cont<ordem;i++){
		
		//sempre que encontrar o caracter '|' chegou-se a uma nova informação
		if (s1[i] == '|'){
			cont++
		}
		
	}
	
	//montando uma string com a informação de 's1' que está na posição de 'ordem'
	do{
		nova[pos] = s1[i];
		pos++;
		i++;
	}
	
	while (s1[i] != '|');
	
	
}




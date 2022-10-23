/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 06/11/2021 - Aula extra
	
	Questão 01:
	Desenvolver uma função recursiva que determine o número de
	caracteres comuns entre duas strings s1 e s2.
	
	Atenção: Não se preocupar se o mesmo caracter aparecer mais de uma vez na string.
	
	Exemplo:
		s1: CASA
		s2: CADERNO
		
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//protótipos das funções
int caracteresComuns (char s1[], char s2[], int pos1, int pos2);

// função main
main() {
	
	//declaração de variáveis
	char str1[30], str2[30];
	int resp;
	
	// inicialização as strings
	//strcpy(str1, "CASA");
	//strcpy(str2, "CADERNO");
	
	strcpy(str1, "CAIPIRA");
	strcpy(str2, "C");
	
	//Chamando a função
	resp = caracteresComuns (str1, str2, 0, 0);
	
	// exibindo o resultado
	printf ("Foram encontrados %d caracteres comuns entre as strings %s e %s\n\n", resp, str1, str2 );	
	
}

//implementações das funções
int caracteresComuns (char s1[], char s2[], int pos1, int pos2){
	if (pos1 == strlen(s1)){
		return 0; // funciona como --> cont = 0
	} else {
		if (pos2 == strlen (s2)){
			return caracteresComuns (s1, s2, pos1+1, 0);
		} else {
			// verificando se os caracteres são iguais
			if (s1[pos1] == s2[pos2]){
				return 1 + caracteresComuns (s1, s2, pos1+1, 0); // funciona como cont++ // Interessante!
			} else {
				return caracteresComuns (s1, s2, pos1, pos2+1);
			}
		}
	}
}

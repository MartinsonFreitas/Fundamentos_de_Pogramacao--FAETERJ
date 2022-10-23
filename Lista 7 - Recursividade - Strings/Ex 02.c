/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 06/11/2021 - Aula extra
	
	Questão 02:
	Dado o programa abaixo, pede-se avaliar a sua execução e, 
	ao final, informar o valor que é exibido. 
	Para isto, é obrigatório apresentar o passo a passo de sua execução, 
	com a sequência de chamadas à função, 
	assim como o valor retornado por cada uma delas.
	
	*/
	
	#include <stdio.h>
		int funcao (int a, int b) {
			if (a > 0) {
				if (a > b) {
					return funcao (a-1, b+2) + funcao (b-a, b);
				} else {
					return funcao (a-2, b);
				}
			} else {
				return b;
			}
		}
		void main () {
			printf ("Resposta = %d", funcao (10, 5));
		}
		



/*
	FAETERJ-Rio
	FPR - Noite		Professor Leonardo Vianna
	Data: 29/11/2021
	
	STRUCTS
	
	Lista de Exercícios VIII:
	
	Questão 02: 
	Determinada zona eleitoral possui N eleitores inscritos que poderão votar, uma única vez, em
	um dos C candidatos para o único cargo a ser definido. Pede-se:
		a. A declaração de todo(s) o(s) tipo(s) de dados necessário(s) para o armazenamento
		dos números dos candidatos, assim como a quantidade de votos brancos, nulos e votos
		para cada candidato;
		
		b. Uma função que leia o voto de cada eleitor, considerando que o processo terminará
		quando os N eleitores votarem ou quando o número -1 for digitado como voto;
		
		c. Uma função que exiba:		
			i. O total de votos para cada candidato, assim com a quantidade de votos
			brancos (código 0) e de nulos (código sem candidato associado);
			ii. A quantidade de abstenções (eleitores que não votaram);
			iii. O número do candidato vencedor (caso tenha mais de 50% dos votos válidos) ou
			dos que irão para o segundo turno (os dois mais votados).
*/


//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TAM 5

//definição de tipos
typedef struct {
	char nome[30];
} TCandidato;

//protótipos das funções


//main
void main ()
{
}

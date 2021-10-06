/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 27/09/2021
	
	Lista de Exercícios IV - Matrizes
	
	QUESTÃO 01:
	Faça um função que, dada uma matriz M8×5 de reais, gere a matriz Mt, sua transposta.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaração de constantes
#define L 8
#define C 5

//Protótipo da função
void transposta (float m[L][C], float mt[C][L]);

void preencherAleatorio(float m[L][C]);
void exibir(float m[L][C]);
void exibirTransp(float m[C][L]);

//Implementando a main
int main(void)
{
	//declaração de variáveis
	float matriz[L][C];
	float transp[C][L];
		
	preencherAleatorio(matriz);
	exibir(matriz);
	printf("\n");
	
	transposta(matriz, transp);
	exibirTransp(transp);
	return 0;
}

//Funções

void transposta (float m[L][C], float mt[C][L])
{
	//declaração de variáveis
	int i,j;
		
	//preenchendo a matriz transposta
	for(i=0;i<L;i++){
	    for(j=0;j<C;j++){
	        mt[j][i]=m[i][j];
	    }
	}
}

void exibir(float m[L][C]){
	int i,j;
	for(i=0;i<L;i++){
    	for(j=0;j<C;j++){
	        printf("%6.2f ",m[i][j]);
	    }
	    printf("\n");
	}
}

void preencherAleatorio(float m[L][C]){
	int i,j;

	srand(time(NULL));
	for(i=0;i<L;i++){
    	for(j=0;j<C;j++){
           m[i][j]=rand()%101;  //gerar números de 0 a 100
        }
    }
}

void exibirTransp(float m[C][L])
{
	int i,j;
	for(i=0;i<C;i++){
    	for(j=0;j<L;j++){
	        printf("%6.2f ",m[i][j]);
	    }
	    printf("\n");
	}
}

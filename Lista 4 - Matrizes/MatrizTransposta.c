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
void transposta (int m[L][C], int mt[C][L]);

void preencherAleatorio(int m[L][C]);
void exibir(int m[L][C]);
void exibirTransp(int t[C][L]);

//Implementando a main
int main(void)
{
	//declaração de variáveis
	int matriz[L][C];
	int transp[C][L];
		
	preencherAleatorio(matriz);
	exibir(matriz);
	printf("\n");
	
	transposta(matriz, transp);
	exibirTransp(transp);
	return 0;
}

//Funções

void transposta (int m[L][C], int mt[C][L])
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

void exibir(int m[L][C]){
	int i,j;
	for(i=0;i<L;i++){
    	for(j=0;j<C;j++){
	        printf("%2d ",m[i][j]);
	    }
	    printf("\n");
	}
}

void preencherAleatorio(int m[L][C]){
	int i,j;

	srand(time(NULL));
	for(i=0;i<L;i++){
    	for(j=0;j<C;j++){
           m[i][j]=rand()%100;  //gerar números de 0 a 99
        }
    }
}

void exibirTransp(int t[C][L])
{
	int i,j;
	for(i=0;i<C;i++){
    	for(j=0;j<L;j++){
	        printf("%2d ",t[i][j]);
	    }
	    printf("\n");
	}
}

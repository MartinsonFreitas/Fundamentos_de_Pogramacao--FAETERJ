/*
	FAC - 2021/1
	Data: 01/07/2021
	
	Lista de Exerc�cios XI

	QUEST�O 01
*/

//importa��o de bibliotecas
#include <stdio.h>

void funcao01 (int v[], int tam, int pos) {
	int i;

	for (i=tam-1;i>=pos;i-=2) {
		v[i] = v[i]*2;
	}
}

void funcao02 (int x) {
	x++;
}	

void funcao03 (int v[], int tam) {
	int i;

	for (i=0;i<tam;i++) {
		printf ("%d   ", v[i]);
	}
	printf ("\n");
}

int main () {
	int i, vet[5] = {1,2,3,4,5};
	int quant = 5;

	for (i=0;i<quant;i++) {
		if (i%2==0) 	{
			funcao01 (vet, quant, i);
		}
		else {
			funcao02 (vet[i]);
		}

		funcao03 (vet, quant);
	}
}


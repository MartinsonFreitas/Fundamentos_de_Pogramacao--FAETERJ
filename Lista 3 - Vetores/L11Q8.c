/*

	Questão 08:
	
	Faça uma função que, dado um vetor de
	números inteiros, exiba para cada um de seus
	elementos a quantidade de vezes que o mesmo
	aparece no vetor.
	
	Exemplo:
	Vetor = {3,5,1,3,2,5,7,3,4,7,6,1}
	
	Saída:
	3: 3 vezes
	5: 2 vezes
	1: 2 vezes
	2: 1 vez
	7: 2 vezes
	4: 1 vez
	6: 1 vez
	
*/
#include<stdio.h>

void preencheSemRepeticao (int vetorOri[], int vetorAux[], int quantOri, int *quantAux)
{
	int i, j, cont=0;
	
	//Percorrendo vetorOriginal
	for(i=0; i<quantOri; i++)
	{
		cont=0; //contador de elementos diferentes
		
		//Percorrendo vetorAuxiliar
		for (j=0; j<(*quantAux); j++)
		{
			if (vetorAux[j] != vetorOri[i])
			{
				cont++;
			}
		}
		
		if (cont == (*quantAux) || (*quantAux) == 0)
		{
			vetorAux[(*quantAux)] = vetorOri[i];
			(*quantAux)++;
		}
	}
}

void exibeVetor (int vetor[], int cap)
{
	int i;
	
	for (i=0;i<cap;i++)
	{
		printf("[%d] ", vetor[i]);
	}
	printf("\n ----- \n");
}

void exibeOcorrencias (int vetor[], int quant)
{
	int i, j, vetor_aux[quant], quant_aux=0, cont;
		
	//Carregando o vetor_aux 
	//com os elementos únicos do vetor original
	preencheSemRepeticao(vetor, vetor_aux, quant, &quant_aux);
	
	/*
		Testando a função 'preencheSemRepeticao'
		
		printf("Vetor Original: ");
		exibeVetor(vetor, quant);
		printf("\nVetor Aux (sem repeticao): ");
		exibeVetor (vetor_aux, quant_aux);
	*/
	
	//Percorrendo Vetor Auxiliar
	for (i=0; i<quant_aux; i++)
	{
		cont=0; //zerando o cont
		
		//Percorrendo Vetor Original
		for (j=0; j<quant; j++)
		{
			if (vetor[j] == vetor_aux[i])
			{
				cont++;
			}
		}
		
		printf("%d: %d vezes\n", vetor_aux[i], cont);
	}
}

void main ()
{
	
	int vetor[12] = {3,5,1,3,2,5,7,3,4,7,6,1};
	exibeOcorrencias (vetor, 12);
	
}

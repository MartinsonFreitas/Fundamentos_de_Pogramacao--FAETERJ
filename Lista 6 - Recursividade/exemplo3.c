/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 23/10/2021 (aula extra)
	
	Desenvolver uma função recursiva que retorne a quantidade de ocorrências de um número 
	em um vetor de inteiros.
*/

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int numOcorrencias (int numero, int vetor[], int quant, int pos);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int vet[10] = {1,8,1,2,6,4,1,3,6,1};
	int cont, numero = 1;
	
	//chamando a função
	cont = numOcorrencias (numero, vet, 10, 0);		//iniciando a busca na posição 0 [como é feito com o for na versão iterativa, começando o i na posição 0]
	
	//exibindo o resultado
	printf ("Foram encontradas %d ocorrencias do numero %d no vetor.", cont, numero);
}

//implementação
int numOcorrencias (int numero, int vetor[], int quant, int pos)
{
	if (pos < quant)  //verificando se é uma posição válida do vetor
	{
		if (vetor[pos] == numero)	//verificando se o elemento foi encontrado na posição 'pos'
		{
			return 1 + numOcorrencias (numero, vetor, quant, pos+1); //caso seja encontrado, acumular 1 na soma para o cálculo do número de ocorrências e seguir para a busca nas demais posições do vetor
		}
		else
		{
			return /*0 +*/ numOcorrencias (numero, vetor, quant, pos+1); //se 'numero' não for encontrado na posição 'pos', segue-se para a busca nas demais posições do vetor
		}		
	}
	else		//caso base
	{
		return 0;	//"zerando o contador", considerando que chegou-se ao caso base no qual não há mais posições a verificar
	}
}

/*
vetor: 4 2 4 1			numero: 4

		1ª chamada: pos 0 (vetor[pos] = 4)
			
				1 + 2ª chamada
					pos 1 (vetor[pos] = 2)
						0 + 3ª chamada
							pos 2 (vetor[pos] = 4)
							    1 + 4ª chamada
									pos 3 (vetor[pos] = 1) 
									    0 + 5ª chamada
									        pos 4 ==> caso base!!!
									                  retorna 0									                  
*/

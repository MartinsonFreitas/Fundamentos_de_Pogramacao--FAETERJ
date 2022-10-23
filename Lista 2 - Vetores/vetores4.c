/*
	FPR - Fundamentos de Programação
	Professor Leonardo Vianna

	Data: 13/09/2021
	
	Revisão - FAC   [vetores e funções]
	
	desenvolver uma função que, dado um número inteiro x, determine o número de vezes que ele 
	aparece em um vetor de tamanho 'tam'.
*/

//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TAM 100

//protótipos/cabeçalhos das funções
void preencherAleatorio (int vetor[], int tamanho);
void exibir (int vetor[], int tamanho);
int conta_elemento(int v[], int tamanho, int n);

//implementação da função main
void main ()
{
	//declaração de variáveis
	int v[TAM];
	int numero, quant;
	
	//preenchendo o vetor, e exibindo-o
	preencherAleatorio (v, TAM);
	exibir (v, TAM);
	
	//lendo o número a ser buscado
	printf ("\n\nEntre com o numero a ser buscado no vetor: ");
	scanf ("%d", &numero);
	
	//chamando a função
	quant = conta_elemento (v, TAM, numero);
	
	//exibindo o resultado
	printf ("\nForam encontradas %d ocorrencias do numero %d", quant, numero);
}

//implementação das demais funções
void preencherAleatorio (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	srand (time(NULL));
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//gerando um novo número aleatório e armazenando-o no vetor
		vetor[i] = 1 + rand()%50;
	}
}
void exibir (int vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nVetor: ");
	
	//variando todas as posições do vetor
	for (i=0;i<tamanho;i++)
	{
		//exibindo os valores do vetor
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n");
}

int conta_elemento(int v[], int tamanho, int n)
{
	//declaração de variáveis
    int c=0, i;
    
    for (i=0;i<tamanho;i++){

        if (v[i]==n){
            c++;
        }
    }

    return c;

}

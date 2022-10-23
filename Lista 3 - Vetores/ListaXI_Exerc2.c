/*
	FAC - 2021/1
	Resolução dos exercícios que não foram resolvidos em sala com o professor.
	
	Lista de Exercícios XI 
	
	Questão 02:
	
	Considere a existência de dois conjuntos numéricos A e B contendo n1 e n2 
	elementos, respectivamente. Pede-se o desenvolvimento de uma função que 
	determine se um dos conjuntos está contido no outro, retornando os seguintes 
	códigos:
 		- 1, se A estiver contido em B;
 		- 2, se B estiver contido em A;
 		- 0, caso contrário.
*/

//importação de bibliotecas
#include <stdio.h>

//declaração de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int questao02 (int vet1[], int quant1, int vet2[], int quant2);

int estahContido (int vet1[], int quant1, int vet2[], int quant2);
int buscar (int vetor[], int quant, int numero);
void exibirVetor (int vetor[], int quant);

//main
void main ()
{
	//declaração de variáveis
	int vetA[5]  = {1,2,3,4,5},
	    vetB[10] = {5,3,2,1,4,6,9,8,7,0},
	    vetC[4]  = {6,7,8,9};
	    
	//exibindo os vetores
	printf ("Vetor A:\n");
	exibirVetor (vetA, 5);		

	printf ("Vetor B:\n");
	exibirVetor (vetB, 10);		
	
	printf ("Vetor C:\n");
	exibirVetor (vetC, 4);		
	
	//testando a função
	
	//sabemos que A está contido em B. Então, a função deve retornar 1
	switch (questao02 (vetA, 5, vetB, 10))
	{
		case 1:	printf ("\n\tO vetor A esta' contido no vetor B!\n");
		        break;
		case 2:	printf ("\n\tO vetor B esta' contido no vetor A!\n");
		        break;
		case 0:	printf ("\n\tA e B: nenhum vetor esta' contido no outro!\n");
		        break;
	}
	

	//sabemos que C está contido em B. Então, a função deve retornar 2
	switch (questao02 (vetB, 10, vetC, 4))
	{
		case 1:	printf ("\n\tO vetor B esta' contido no vetor C!\n");
		        break;
		case 2:	printf ("\n\tO vetor C esta' contido no vetor B!\n");
		        break;
		case 0:	printf ("\n\tB e C: nenhum vetor esta' contido no outro!\n");
		        break;
	}
	
	//sabemos que A não está contido em C e vice-versa. Então, a função deve retornar 0
	switch (questao02 (vetA, 5, vetC, 4))
	{
		case 1:	printf ("\n\tO vetor A esta' contido no vetor C!\n");
		        break;
		case 2:	printf ("\n\tO vetor C esta' contido no vetor A!\n");
		        break;
		case 0:	printf ("\n\tA e C: nenhum vetor esta' contido no outro!\n");
		        break;
	}
}

//implementação das funções

/*Função que responde ao que foi solicitado no enunciado. Para isso, chama uma
  função auxiliar que verificar se determinado vetor está contido em outro.
  Chamando a função duas vezes, trocando a ordem dos argumentos, chega-se à 
  solução esperada para o problema.*/
int questao02 (int vet1[], int quant1, int vet2[], int quant2)
{
	//verificando se vet1 está contido em vet2
	if (estahContido (vet1, quant1, vet2, quant2) == TRUE)
	{
		return 1;
	}
	else
	{
		//verificando se vet2 está contido em vet1
		if (estahContido (vet2, quant2, vet1, quant1) == TRUE)
		{
			return 2;
		}
		else
		{
			//se chegou aqui, nenhum vetor está contido no outro
			return 0;
		}
	}
}

//Verificar se vet1 está contido em vet2, retornando TRUE ou FALSE
//Para isso, verifica se todos os elementos de vet1 estão também em vet2
int estahContido (int vet1[], int quant1, int vet2[], int quant2)
{
	//declaração de variáveis
	int i;
	
	//varrendo todas as posições do vetor vet1
	for (i=0;i<quant1;i++)
	{
		//chamando a função buscar para saber se o elemento vet[i] está em vet2.
		//Se não estiver, já sabemos que vet1 não está contido em vet2
		if (buscar (vet2, quant2, vet1[i]) == FALSE)
		{
			return FALSE;
		}
	}
	
	//se chegou até aqui, é pq todos os elementos de vet1 estão em vet2.
	//Logo, vet1 está contido em vet2.
	return TRUE;
}

//função que verifica se o número encontra-se no vetor
int buscar (int vetor[], int quant, int numero)
{
	//declaração de variáveis
	int i;
	
	//percorrendo todas as posições do vetor
	for (i=0;i<quant;i++)
	{
		//verificando se o elemento foi encontrado no vetor
		if (vetor[i] == numero)
		{
			return TRUE;
		}
	}
	
	//se chegou até aqui, é pq o elemento não encontra-se no vetor
	return FALSE;
}

//Exibe na tela os elementos do vetor
void exibirVetor (int vetor[], int quant)
{
	//declaração de variáveis
	int i;
	
	//exibindo os elementos do vetor
	printf ("\nElementos do vetor: ");
	
	for (i=0;i<quant;i++)
	{
		printf ("%d ", vetor[i]);
	}
	
	printf ("\n\n");
}


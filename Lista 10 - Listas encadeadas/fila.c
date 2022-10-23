/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR
	2022/1  -  Turma: Noite
	
	Data: 13/06/2022
	
	Filas Encadeadas (Filas Dinâmicas)
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//declaração dos protótipos das funções
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *numero);

int menu ();

//main 
void main ()
{
	//declaração de variáveis
	TLista F = NULL, U = NULL;
	int num, op;
		
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Enfilar
			case 1: printf ("\nEntre com o valor a ser inserido na fila: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (enfilar (&F, &U, num) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso na fila!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada na fila!");
					}
					break;

			//Desenfilar
			case 2: //chamando a função
			        if (desenfilar (&F, &U, &num) == TRUE)
			        {
			        	printf ("\n\tO valor %d foi removido da fila!", num);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Primeiro
			case 3: if (primeiro (F, &num) == TRUE)
			        {
			        	printf ("\n\tPrimeiro elemento da fila: %d.", num);
					}
					else
					{
						printf ("\n\tERRO: fila vazia!");
					}
					break;
			
			//Saída
			case 4: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
		
		system ("PAUSE");
	}
	while (op != 4);
}

//implementação das funções
int enfilar (TLista *F, TLista *U, int numero)
{
	//declaração de variáveis;
	TLista aux;
	
	//1º passo: alocar memória para o novo nó	
	aux = (TLista) malloc (sizeof(TNo));
	
	//verificando se houve erro na alocação de memória
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//2º passo: armazenar 'numero' na memória recém-alocada
		aux->valor = numero;
		
		//3º passo: fazer o campo 'prox' do novo nó apontar para NULL
		aux->prox = NULL;
		
		if (*U != NULL) //ou seja, já existem elementos na fila
		{
			//4º passo: fazer o campo 'prox' do último nó apontar para o novo nó
			(*U)->prox = aux;
		}
		else	//fila vazia
		{
			*F = *U = aux;
		}
		
		//5º passo: atualizar o ponteiro U
		*U = aux;   //ou *U = (*U)->prox;
		
		return TRUE;
	}	
}

int desenfilar (TLista *F, TLista *U, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a fila está vazia
	if (*F == NULL)
	{
		return FALSE;
	}
	else
	{
		//salvar em 'aux' o endereço do nó que representa o primeiro elemento da fila
		aux = *F;
		
		//atualizar *F para apontar para o "próximo" elemento
		*F = aux->prox;   //ou *F = (*F)->prox;
		
		//verificando se a fila se tornou vazia com a remoção
		if (*F == NULL)
		{
			//atualizar o valor de *U
			*U = NULL;
		}
		
		//armazenar em 'numero' o elemento sendo removido
		*numero = aux->valor;
		
		//liberando a memória do primeiro elemento da fila
		free (aux);
		
		return TRUE;
	}
}

int primeiro (TLista F, int *numero)
{
	//verificando se a fila está vazia
	if (F == NULL)
	{
		return FALSE;
	}
	else
	{	
		//armazenando em 'numero' o primeiro elemento da fila
		*numero = F->valor;
		 	
		return TRUE;
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Enfilar\n");
	printf ("(2) Desenfilar\n");
	printf ("(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

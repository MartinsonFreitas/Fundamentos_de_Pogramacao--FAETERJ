/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR
	2022/1  -  Turma: Noite
	
	Data: 13/06/2022
	
	Pilhas Encadeadas (Pilhas Dinâmicas)
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
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *numero);

int menu ();

//main 
void main ()
{
	//declaração de variáveis
	TLista P = NULL;
	int num, op;
		
	do
	{
		system ("CLS");		//limpar tela    clrscr();
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Empilhar
			case 1: printf ("\nEntre com o valor a ser inserido na pilha: ");
			        scanf ("%d", &num);
			        
			        //chamando a função
			        if (empilhar (&P, num) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso na pilha!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada na pilha!");
					}
					break;

			//Desempilhar
			case 2: //chamando a função
			        if (desempilhar (&P, &num) == TRUE)
			        {
			        	printf ("\n\tO valor %d foi removido da pilha!", num);
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Topo
			case 3: if (topo (P, &num) == TRUE)
			        {
			        	printf ("\n\tTopo da pilha: %d.", num);
					}
					else
					{
						printf ("\n\tERRO: pilha vazia!");
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
int empilhar (TLista *P, int numero)
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
		
		//3º passo: mandar o campo 'prox' do novo nó apontar para o 
		//"até então" primeiro elemento	da lista
		aux->prox = *P;
		
		//4º passo: fazer com que L aponte para o novo nó da lista		
		*P = aux;
		
		return TRUE;
	}	
}

int desempilhar (TLista *P, int *numero)
{
	//declaração de variáveis
	TLista aux;
	
	//verificando se a pilha está vazia
	if (*P == NULL)
	{
		return FALSE;
	}
	else
	{
		//salvar em 'aux' o endereço do nó que representa o topo da pilha
		aux = *P;
		
		//atualizar *P para apontar para o "próximo" elemento
		*P = aux->prox;   //ou *P = (*P)->prox;
		
		//armazenar em 'numero' o elemento sendo removido
		*numero = aux->valor;
		
		//liberando a memória do primeiro elemento da pilha (que era o seu topo)
		free (aux);
		
		return TRUE;
	}
}

int topo (TLista P, int *numero)
{
	//verificando se a pilha está vazia
	if (P == NULL)
	{
		return FALSE;
	}
	else
	{	
		//armazenando em 'numero' o valor que está no topo da pilha
		*numero = P->valor;
		 	
		return TRUE;
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Empilhar\n");
	printf ("(2) Desempilhar\n");
	printf ("(3) Topo\n");
	printf ("(4) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

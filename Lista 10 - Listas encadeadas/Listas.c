/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR
	2022/1  -  Turma: Noite
	
	Data: 30/05/2022
	
	Listas Encadeadas (Listas Dinâmicas)
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
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int velho, int novo);
TLista buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main 
void main ()
{
	//declaração de variáveis
	TLista L = NULL;
	int num1, num2, op, quant;
	TLista pos;
	
	do
	{
		system ("CLS");
		
		//exibindo o meu ao usuário
		op = menu ();
		
		//verificando a opção escolhida
		switch (op)
		{
			//Inserção
			case 1: printf ("\nEntre com o valor a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (inserir (&L, num1) == TRUE)
			        {
			        	printf ("\n\tInsercao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: insercao nao realizada!");
					}
					break;

			//Remoção
			case 2: printf ("\nEntre com o valor a ser removido: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (remover (&L, num1) == TRUE)
			        {
			        	printf ("\n\tRemocao realizada com sucesso!");
					}
					else
					{
						printf ("\n\tERRO: remocao nao realizada!");
					}
					break;

			//Alteração
			case 3: printf ("\nEntre com o valor a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("\nEntre com o novo valor: ");
			        scanf ("%d", &num2);
			        
			        //chamando a função
			        quant = alterar (L, num1, num2);
			        
			        if (quant > 0)
			        {
			        	printf ("\n\t%d alteracoes realizadas!", quant);
					}
					else
					{
						printf ("\n\tERRO: alteracao nao realizada!");
					}
					break;

			//Busca
			case 4: printf ("\nEntre com o valor a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        pos = buscar (L, num1);
			        
					if (pos != NULL)
			        {
			        	printf ("\n\tO valor %d foi encontrado na lista!", num1);
					}
					else
					{
						printf ("\n\tO valor %d NAO foi encontrado na lista!", num1);
					}
					break;

			//Exibir
			case 5: exibir (L);
					break;
					
			//Saída
			case 6: printf ("\n\nPrograma finalizado!");
			        break;
			        
			default: printf ("\n\nOpcao invalida! Tente novamente.");
		}
	}
	while (op != 6);
}

//implementação das funções
int inserir (TLista *L, int numero)
{
	
}

int remover (TLista *L, int numero)
{
	
}

int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista aux = L;
	int cont = 0;
	
	//percorrendo toda a lista
	while (aux != NULL)
	{
		//verificando se o elemento 'velho' foi encontrado
		if (aux->valor == velho)
		{
			//alterando o 'velho' pelo 'novo'
			aux->valor = novo;
			
			//atualizando o número de atualizações realizadas
			cont++;
		}
		
		//fazendo o aux apontar para o próximo nó da lista
		aux = aux->prox;		
	}
	
	//retornando a quantidade de alterações realizadas
	return cont;
}

TLista buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;
	
	//percorrendo a lista até o seu final
	while (aux != NULL)
	{
		//testando se é o valor sendo buscado
		if (aux->valor == numero)
		{
			//retornando o endereço do nó que contém o valor buscado
			return aux;
		}
			
		//atualizando o 'aux' para apontar para o próximo nó
		aux = aux->prox;
	}
	
	//se chegou a este ponto, o número buscado não existe
	return NULL;	
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux = L;
	
	//testando se a lista está vazia
	if (L == NULL)
	{
		printf ("\nLista vazia!");
	}
	else
	{
		printf ("\nElementos da lista: ");
		
		//percorrendo a lista até o seu final
		while (aux != NULL)
		{
			//exibindo o valor apontado pelo 'aux'
			printf ("%d ", aux->valor);
			
			//atualizando o 'aux' para apontar para o próximo nó
			aux = aux->prox;
		}
	}
}

int menu ()
{
	//declaração de variáveis
	int opcao;
	
	//exibindo o meu ao usuário
	printf ("Menu de Operacoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção do usuário
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &opcao);
	
	//retornando a opção escolhida
	return opcao;
}

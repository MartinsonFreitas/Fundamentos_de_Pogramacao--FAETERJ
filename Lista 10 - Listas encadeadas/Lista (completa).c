/*
	FAETERJ-Rio
	Fundamentos de Programação - FPR
	2022/1  -  Turma: Noite
	
	Data: 06/06/2022
	
	Listas Encadeadas (Listas Dinâmicas) - conclusão da implementação
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
		system ("CLS");		//limpar tela    clrscr();
		
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
			        quant = remover (&L, num1);
			        
					if (quant > 0)
			        {
			        	printf ("\n\t%d remocoes realizadas!", quant);
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
		
		system ("PAUSE");
	}
	while (op != 6);
}

//implementação das funções
int inserir (TLista *L, int numero)
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
		aux->prox = *L;
		
		//4º passo: fazer com que L aponte para o novo nó da lista		
		*L = aux;
		
		return TRUE;
	}
	
}

int remover (TLista *L, int numero)
{
	//declaração de variáveis
	TLista aux1, aux2;
	int cont = 0;
	
	//verificando se o primeiro elemento da lista é aquele a ser removido
	while ((*L != NULL) && ((*L)->valor == numero))
	{
		//remoção na primeira posição da lista
		
		//Passo 1: fazer um 'auxiliar' apontar para o primeiro nó da lista
		aux1 = *L;
		
		//Passo 2: fazer com que o L aponte para o segundo elemento da lista (que passará a ser o primeiro)
		*L = (*L)->prox; 
		
		//Passo 3: liberar a memória do nó a ser removido
		free (aux1);
		
		//atualizando a quantidade de remoções realizadas
		cont++;
	}
	
	//a função continuará apenas se ainda existirem nós na lista 
	if (*L != NULL)   	
	{
		//remoção da segunda posição em diante
		aux2 = *L;
		aux1 = (*L)->prox;  //ou aux1 = aux2->prox;
		
		//percorrendo toda a lista com 'aux1' (e 'aux2' na sua sombra)
		
		//1º passo: Andar com 'aux1' até encontrar o elemento a ser removido			
		//(e garantir que 'aux2' estará apontando para o nó anterior)	
		while (aux1 != NULL)
		{
			//verificando se o elemento foi encontrado
			if (aux1-> valor == numero)
			{
				//2º passo: fazer com que o nó apontado por 'aux2' aponte 
				//para o nó seguinte àquele a ser removido
				aux2->prox = aux1->prox;
				
				//3º passo: liberar a memória do nó que deve ser removido
				free (aux1);
				
				//4º passo: fazer com que 'aux1' aponte para o próximo elemento 
				//a ser analisado.		
				aux1 = aux2->prox;
				
				//atualizando a quantidade de remoções realizadas
				cont++;
			}
			else
			{
				//andando com os dois auxiliares
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}
	
	//retornando a quantidade de remoções realizadas
	return cont;	
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

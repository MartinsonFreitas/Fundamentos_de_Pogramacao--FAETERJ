/*
	FAETERJ-Rio
	FPR - Noite - 2021/2
	Professor Leonrdo Vianna
	Data: 06/12/2021
	
	Listas encadeadas (listas por ponteiros)
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//declaração de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//protótipos das funções
//int inserir (TNo** L, int numero);
int inserir (TLista* L, int numero);
int remover (TLista* L, int numero);
int alterar (TLista L, int velho, int novo);	//L não é passado por referência, pois o endereço não muda!
int buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista lista = NULL;
	int opcao, num1, num2;
	
	do
	{
		//o menu de opções será apresentado ao usuário até que ele opte por sair do sistema
		opcao = menu ();
		
		//testando a opção escolhida
		switch (opcao)
		{
			//Inserção
			case 1: printf ("Numero a ser inserido: ");
					scanf ("%d", &num1);
			
					//chamando a função
					if (inserir (&lista, num1) == TRUE)
					{
						printf ("\n\tInsercao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tInsercao nao realizada!\n");
					}
					break;
			
			//Remoção
			case 2: printf ("Numero a ser removido: ");
					scanf ("%d", &num1);
			
					//chamando a função
					if (remover (&lista, num1) != 0)
					{
						printf ("\n\tRemocao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tRemocao nao realizada!\n");
					}
					break;
			
			//Alteração
			case 3: printf ("Numero a ser alterado: ");
					scanf ("%d", &num1);
					
					printf ("Novo valor: ");
					scanf ("%d", &num2);
			
					//chamando a função
					if (alterar (lista, num1, num2) != 0)
					{
						printf ("\n\tAlteracao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tAlteracao nao realizada!\n");
					}
					break;
					
			//Busca
			case 4: printf ("Numero a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        //chamando a função
			        if (buscar (lista, num1) == TRUE)
			        {
			        	printf ("\n\tElemento encontrado na lista!\n");
					}
					else
					{
						printf ("\n\tElemento nao encontrado na lista!\n");
					}
					break;
			
			//Exibição
			case 5: //chamando a função
			        exibir (lista);
			        break;
			       
			//saída do programa 
			case 6: printf ("Fim do programa!\n");
			        break;
			        
			//opção inválida
			default:printf ("Opcao invalida! Tente novamente.\n");
			        break;
		}
		
		system ("pause");
	}
	while (opcao != 6);	  //6 - opção de saída
}

//implementação das funções
int inserir (TLista* L, int numero)
{
	//declaração de variáveis
	TLista aux;
	
	//Passo 1: alocar memória 
	aux = (TLista) malloc (sizeof(TNo));      //malloc: argumento -> quantos bytes vc quer?   (retorna *void)
	
	//verificando se a memória foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: armazenando 'numero' na posição alocada
		aux->valor = numero;
		
		//Passo 3: fazendo o novo nó apontar para aquele que até então era o primeiro nó da lista
		aux->prox = *L;
		
		//Passo 4: fazer com que a lista aponte para o novo elemento (uma vez que está sendo inserido no início da lista)
		*L = aux;
		
		return TRUE;
	}
}

int remover (TLista* L, int numero)
{
}

//versão da função alterar retornando a quantidade de alterações feitas
int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	int cont = 0;		//armazenará o número de alterações realizadas
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' é o número a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'
			cont++;					//atualizando o número de alterações realizadas
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o próximo nó da lista
	}
	
	//retornando a quantidade de alterações realizadas
	return cont;
}

/*
//versão da função alterar retornando TRUE ou FALSE
int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	int alterou = FALSE;
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' é o número a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'			
			alterou = TRUE;
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o próximo nó da lista
	}
	
	//retornando TRUE ou FALSE
	return alterou;
}
*/

int buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
	{
		if (aux->valor == numero)	//verificando se o elemento apontado por 'aux' é o número sendo buscado
		{
			return TRUE;
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o próximo nó da lista
	}
	
	//se chegou neste ponto, o 'numero' não existe em 'L'
	return FALSE;
}

void exibir (TLista L)
{
	//declaração de variáveis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro nó (ou seja, aquele apontado por 'L')
	
	if (L == NULL)	//testando se a lista está vazia
	{
		printf ("Lista vazia!");
	}
	else
	{
		printf ("Lista:  ");
			
		while (aux != NULL)	//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir nó na lista.
		{
			//printf ("%d ", (*aux).valor));
			printf ("%d ", aux->valor);		//exibindo o valor que está no nó apontado por 'aux'
			
			aux = aux->prox;	//fazendo com que 'aux' aponte para o próximo nó da lista
		}
	}
}

int menu ()
{
	//declaração de vairáveis
	int op;
	
	//limpando a tela
	system ("cls");
	
	//exibindo o menu de opções ao usuário	
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a opção desejada
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	//retornando a opção
	return op;
}

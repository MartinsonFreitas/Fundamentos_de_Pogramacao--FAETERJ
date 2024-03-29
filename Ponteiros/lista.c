/*
	FAETERJ-Rio
	FPR - Noite - 2021/2
	Professor Leonrdo Vianna
	Data: 06/12/2021
	
	Listas encadeadas (listas por ponteiros)
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//defini��o de constantes
#define TRUE 1
#define FALSE 0

//declara��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//prot�tipos das fun��es
//int inserir (TNo** L, int numero);
int inserir (TLista* L, int numero);
int remover (TLista* L, int numero);
int alterar (TLista L, int velho, int novo);	//L n�o � passado por refer�ncia, pois o endere�o n�o muda!
int buscar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista lista = NULL;
	int opcao, num1, num2;
	
	do
	{
		//o menu de op��es ser� apresentado ao usu�rio at� que ele opte por sair do sistema
		opcao = menu ();
		
		//testando a op��o escolhida
		switch (opcao)
		{
			//Inser��o
			case 1: printf ("Numero a ser inserido: ");
					scanf ("%d", &num1);
			
					//chamando a fun��o
					if (inserir (&lista, num1) == TRUE)
					{
						printf ("\n\tInsercao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tInsercao nao realizada!\n");
					}
					break;
			
			//Remo��o
			case 2: printf ("Numero a ser removido: ");
					scanf ("%d", &num1);
			
					//chamando a fun��o
					if (remover (&lista, num1) != 0)
					{
						printf ("\n\tRemocao realizada com sucesso!\n");
					}
					else
					{
						printf ("\n\tRemocao nao realizada!\n");
					}
					break;
			
			//Altera��o
			case 3: printf ("Numero a ser alterado: ");
					scanf ("%d", &num1);
					
					printf ("Novo valor: ");
					scanf ("%d", &num2);
			
					//chamando a fun��o
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
			        
			        //chamando a fun��o
			        if (buscar (lista, num1) == TRUE)
			        {
			        	printf ("\n\tElemento encontrado na lista!\n");
					}
					else
					{
						printf ("\n\tElemento nao encontrado na lista!\n");
					}
					break;
			
			//Exibi��o
			case 5: //chamando a fun��o
			        exibir (lista);
			        break;
			       
			//sa�da do programa 
			case 6: printf ("Fim do programa!\n");
			        break;
			        
			//op��o inv�lida
			default:printf ("Opcao invalida! Tente novamente.\n");
			        break;
		}
		
		system ("pause");
	}
	while (opcao != 6);	  //6 - op��o de sa�da
}

//implementa��o das fun��es
int inserir (TLista* L, int numero)
{
	//declara��o de vari�veis
	TLista aux;
	
	//Passo 1: alocar mem�ria 
	aux = (TLista) malloc (sizeof(TNo));      //malloc: argumento -> quantos bytes vc quer?   (retorna *void)
	
	//verificando se a mem�ria foi alocada
	if (aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: armazenando 'numero' na posi��o alocada
		aux->valor = numero;
		
		//Passo 3: fazendo o novo n� apontar para aquele que at� ent�o era o primeiro n� da lista
		aux->prox = *L;
		
		//Passo 4: fazer com que a lista aponte para o novo elemento (uma vez que est� sendo inserido no in�cio da lista)
		*L = aux;
		
		return TRUE;
	}
}

int remover (TLista* L, int numero)
{
}

//vers�o da fun��o alterar retornando a quantidade de altera��es feitas
int alterar (TLista L, int velho, int novo)
{
	//declara��o de vari�veis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro n� (ou seja, aquele apontado por 'L')
	int cont = 0;		//armazenar� o n�mero de altera��es realizadas
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir n� na lista.
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' � o n�mero a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'
			cont++;					//atualizando o n�mero de altera��es realizadas
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o pr�ximo n� da lista
	}
	
	//retornando a quantidade de altera��es realizadas
	return cont;
}

/*
//vers�o da fun��o alterar retornando TRUE ou FALSE
int alterar (TLista L, int velho, int novo)
{
	//declara��o de vari�veis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro n� (ou seja, aquele apontado por 'L')
	int alterou = FALSE;
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir n� na lista.
	{
		if (aux->valor == velho)	//verificando se o elemento apontado por 'aux' � o n�mero a ser alterado
		{
			aux->valor = novo;		//alterando o 'velho' pelo 'novo'			
			alterou = TRUE;
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o pr�ximo n� da lista
	}
	
	//retornando TRUE ou FALSE
	return alterou;
}
*/

int buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro n� (ou seja, aquele apontado por 'L')
	
	while (aux != NULL)		//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir n� na lista.
	{
		if (aux->valor == numero)	//verificando se o elemento apontado por 'aux' � o n�mero sendo buscado
		{
			return TRUE;
		}
		
		aux = aux->prox; 	//fazendo com que 'aux' aponte para o pr�ximo n� da lista
	}
	
	//se chegou neste ponto, o 'numero' n�o existe em 'L'
	return FALSE;
}

void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista aux = L;		//fazendo 'aux' apontar, inicialmente, para o primeiro n� (ou seja, aquele apontado por 'L')
	
	if (L == NULL)	//testando se a lista est� vazia
	{
		printf ("Lista vazia!");
	}
	else
	{
		printf ("Lista:  ");
			
		while (aux != NULL)	//enquanto 'aux' for diferente de NULL; ou seja, enquanto existir n� na lista.
		{
			//printf ("%d ", (*aux).valor));
			printf ("%d ", aux->valor);		//exibindo o valor que est� no n� apontado por 'aux'
			
			aux = aux->prox;	//fazendo com que 'aux' aponte para o pr�ximo n� da lista
		}
	}
}

int menu ()
{
	//declara��o de vair�veis
	int op;
	
	//limpando a tela
	system ("cls");
	
	//exibindo o menu de op��es ao usu�rio	
	printf ("Menu de opcoes:\n\n");
	printf ("(1) Inserir\n");
	printf ("(2) Remover\n");
	printf ("(3) Alterar\n");
	printf ("(4) Buscar\n");
	printf ("(5) Exibir\n");
	printf ("(6) Sair\n\n");
	
	//lendo a op��o desejada
	printf ("Entre com a sua opcao: ");
	scanf ("%d", &op);
	
	//retornando a op��o
	return op;
}

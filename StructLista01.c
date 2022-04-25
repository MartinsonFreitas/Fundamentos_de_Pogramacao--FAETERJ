/*
	FAETERJ-Rio
	FPR - Noite		Professor Leonardo Vianna
	Data: 22/11/2021
	
	STRUCTS
	
	Lista de Exercícios VIII:
	
	Questão 01:
	Uma loja de automóveis mantém os carros à venda sob a forma de um vetor de 
	structs contendo as seguintes informações, para cada veículo: placa, modelo, marca, 
	cor, quilometragem, ano modelo/fabricação (deve ser um struct), valor e 
	tipo (usado ou 0 km, conforme o valor do campo quilometragem). 

	Pede-se a declaração de uma variável que represente o estoque de veículos da 
	loja, incluindo todas as declarações de tipos que possam ser necessárias.

	Além disso, implementar as seguintes funções: 
	i.   Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), 
	     com valor não superior a x reais;
	ii.  Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
	iii. Retirar do estoque um determinado veículo, dada a sua placa.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 5

//definição de tipos
typedef struct {
	int modelo, fabricacao;
} TAno;

typedef struct {
    char placa[8];
    char modelo[20];
    char marca[20];
    char cor[20];
    char tipo[10];			//0 KM e USADO
    TAno ano;
    float quilometragem;
    float valor;
} TCarro;

//protótipos das funções
void lerDadosCarros (TCarro *vetor, int quantidade);
void exibirCarrosFiltro (TCarro *vetor, int quantidade, char *modelo, int ano1, int ano2, float valor);
void reajustarCarros (TCarro *vetor, int quantidade);
int removerCarro (TCarro *vetor, int *quantidade, char *placa);
void exibirCarro (TCarro c);
void exibirTodosCarros (TCarro *vetor, int quantidade);

//main
void main ()
{
	//declaração de variáveis
	TCarro loja[TAM];
	int quantCarros = TAM;
	char placa[8];
	
	//preenchendo o vetor de structs
	lerDadosCarros (loja, quantCarros);
	
	//exibindo os dados dos carros
	exibirTodosCarros (loja, quantCarros);
	
	//a partir de agora, serão feitas chamadas para testar se as funções estão corretas
	
	//exibindo carros a partir de alguns filtros
	exibirCarrosFiltro (loja, quantCarros, "HB20", 2015, 2020, 25000);
	
	//reajustando os valores dos carros 0 km (2.5%)
	reajustarCarros (loja, quantCarros);
	
	//tentando remover um carro cuja placa não existe na loja
	strcpy (placa, "XYZ1234");
	if (removerCarro (loja, &quantCarros, placa) == 1)
	{
		printf ("\n\tO carro de placa %s foi retirado do cadastro com sucesso!\n", placa);
	}
	else
	{
		printf ("\n\tErro: o carro de placa %s nao encontra-se no cadastro!\n", placa);
	}
	
	//tentando remover um carro cuja placa existe na loja
	strcpy (placa, "ABC1234");
	if (removerCarro (loja, &quantCarros, placa) == 1)
	{
		printf ("\n\tO carro de placa %s foi retirado do cadastro com sucesso!\n", placa);
	}
	else
	{
		printf ("\n\tErro: o carro de placa %s nao encontra-se no cadastro!\n", placa);
	}
	
	//exibindo os carros da loja, após as operações realizadas
	exibirTodosCarros (loja, quantCarros);	
}

//implementação das funções
void lerDadosCarros (TCarro *vetor, int quantidade)
{
	//declaração de variáveis
	int i, tipoCarro;
	
	//lendo os dados dos carros da loja
	for (i=0;i<quantidade;i++)
	{
		fflush (stdin);
		printf ("Placa: ");
		gets (vetor[i].placa);
		
		fflush (stdin);
		printf ("Modelo: ");
		gets (vetor[i].modelo);
		
		fflush (stdin);
		printf ("Marca: ");
		gets (vetor[i].marca);
		
		fflush (stdin);
		printf ("Cor: ");
		gets (vetor[i].cor);
		
		printf ("Tipo (digite 0 para 0 KM ou 1 para USADO): ");
		scanf ("%d", &tipoCarro);
		
		if (tipoCarro == 0)
		{
			strcpy (vetor[i].tipo, "0 KM");
			vetor[i].quilometragem = 0;
		}
		else
		{
			strcpy (vetor[i].tipo, "USADO");
			printf ("Quilometragem: ");
			scanf ("%f", &vetor[i].quilometragem);
		}
		
		printf ("Ano do modelo: ");
		scanf ("%d", &vetor[i].ano.modelo);
		
		printf ("Ano de fabricacao: ");
		scanf ("%d", &vetor[i].ano.fabricacao);
		
		printf ("Valor: ");
		scanf ("%f", &vetor[i].valor);
		
		printf ("\n\n");
	}
}

//Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), 
//com valor não superior a x reais
void exibirCarrosFiltro (TCarro *vetor, int quantidade, char *modelo, int ano1, int ano2, float valor)
//void exibeCarrosFiltro (TCarro vetor[], int tamanho, char modelo[], int ano1, int ano2, float valor)
{
	//declaração de variáveis
    int i;
    
    //percorrendo todos os carros do vetor
    for (i = 0; i < quantidade; i++)
    {
        if ((strcmp(vetor[i].modelo, modelo) == 0) && 
		    (vetor[i].ano.fabricacao >= ano1) && (vetor[i].ano.fabricacao <= ano2) && 
			(vetor[i].valor <= valor) )
        {
        	exibirCarro (vetor[i]);                      
        }
    }
}

//Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%
void reajustarCarros (TCarro *vetor, int quantidade)
{
	//declaração de variáveis
    float aumento = 0.025;     
    int i;
    
    //varrendo o vetor de carros
    for (i = 0; i < quantidade; i++)
    {
    	//verificando se é um carro zero
        if (strcmp(vetor[i].tipo,"0 KM") == 0)
        {
        	//aplica o aumento
            vetor[i].valor += vetor[i].valor *  aumento ;
        }
    }
}

//Retirar do estoque um determinado veículo, dada a sua placa
int removerCarro (TCarro *vetor, int *quantidade, char *placa)
{
	//declaração de variáveis
	int i;
	
	//varrendo o vetor
    for (i = 0; i < *quantidade; i++)
    {
    	//verificando se o carro desejado foi encontrado
        if (strcmp(vetor[i].placa, placa) == 0)        
		{
			//optou-se por deslocar o último carro para a posição daquele a ser removido
            vetor[i] = vetor[(*quantidade) - 1];
            (*quantidade)--;
            
            return 1;
        }
    }
    
    //a placa desejada não foi encontrada no vetor
    return 0;
}

void exibirCarro (TCarro c)
{
	printf("Placa: %s\n", c.placa);
    printf("Modelo: %s\n", c.modelo);
    printf("Marca: %s\n", c.marca);
    printf("Cor: %s\n", c.cor);
    printf("Ano: %d/%d\n", c.ano.modelo, c.ano.fabricacao);
    printf("Quilometragem: %.1f\n", c.quilometragem);
    printf("Valor: %.2f\n", c.valor);
    printf("Tipo: %s\n\n", c.tipo); 
}

void exibirTodosCarros (TCarro *vetor, int quantidade)
{
	//declaração de variáveis
	int i;
	
	printf ("\n\nExibindo todos os carros da loja:\n\n");
	
	//exibindo todos os carros da loja
	for (i=0;i<quantidade;i++)
	{
		exibirCarro (vetor[i]);
	}
}

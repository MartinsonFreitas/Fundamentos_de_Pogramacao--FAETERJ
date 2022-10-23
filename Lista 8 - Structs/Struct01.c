/*
	FAETERJ-Rio
	FPR - Noite		Professor Leonardo Vianna
	Data: 22/11/2021
	
	STRUCTS
	
	Exercício:
	
	Considere a existência de um vetor no qual cada posição pode armazenar o nome do 
	aluno, as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). 
	Pede-se:
	i.   A declaração do vetor, assim como de todos os tipos de dados necessários, 
	     caso existam;
	ii.  Uma função que leia os dados de todos os alunos da turma;
	iii. Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como 
	     a sua situação;
	iv.  Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), 
	     exiba todos os alunos que estão nesta situação.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 2

//definição de tipos
typedef struct {
	char nome[50];
	float av1, av2, media;
	char situacao[15];
} TAluno;

//protótipos das funções
void leituraDados (TAluno vetor[], int tamanho);
void calculaMediaSituacao (TAluno vetor[], int tamanho);
void exibirAlunosPorSituacao (TAluno vetor[], int tamanho, int sit);

//main
void main ()
{
	//declaração de variáveis
	TAluno turma[TAM];
	
	//preenchendo o vetor
	leituraDados (turma, TAM);
	
	//calculando (e armazenando) a média e a situação de todos os alunos
	calculaMediaSituacao (turma, TAM);
	
	//exibindo os alunos aprovados
	printf ("\n\nAlunos aprovados:\n\n");
	exibirAlunosPorSituacao (turma, TAM, 1);
	
	//exibindo os alunos reprovados
	printf ("\n\nAlunos reprovados:\n\n");
	exibirAlunosPorSituacao (turma, TAM, 2);
	
	//exibindo os alunos em AVF
	printf ("\n\nAlunos em AVF:\n\n");
	exibirAlunosPorSituacao (turma, TAM, 3);
}

//implementação das funções

//função para a leitura dos dados de todos os alunos da turma
void leituraDados (TAluno vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		fflush (stdin);
		printf ("Nome: ");
		gets (vetor[i].nome);
		
		printf ("AV1: ");
		scanf ("%f", &vetor[i].av1);
		
		printf ("AV2: ");
		scanf ("%f", &vetor[i].av2);
	}
}

//função que calcula a média de cada aluno (e a armazene no vetor), assim como a sua situação
void calculaMediaSituacao (TAluno vetor[], int tamanho)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor
	for (i=0;i<tamanho;i++)
	{
		//calculando a média do i-ésimo aluno
		vetor[i].media = (vetor[i].av1 + vetor[i].av2)/2;
		
		//calculando a situação do i-ésimo aluno
		if (vetor[i].media >= 6)
		{
			strcpy (vetor[i].situacao, "APROVADO");
		}
		else
		{
			if (vetor[i].media < 4)
			{
				strcpy (vetor[i].situacao, "REPROVADO");
			}
			else
			{
				strcpy (vetor[i].situacao, "AVF");
			}
		}
	}
}

//função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba todos os 
//alunos que estão nesta situação
void exibirAlunosPorSituacao (TAluno vetor[], int tamanho, int sit)
{
	//declaração de variáveis
	char busca[15];
	int i;
	
	//mapeando o parâmetro 'sit' para a variável 'busca'
	switch (sit)
	{
		case 1: strcpy (busca, "APROVADO");
		        break;
		case 2: strcpy (busca, "REPROVADO");
		        break;
		case 3: strcpy (busca, "AVF");
		        break;
	}
	
	//varrendo o vetor em busca da situação desejada
	for (i=0;i<tamanho;i++)
	{
		if (strcmp (vetor[i].situacao,busca) == 0)
		{
			printf ("\nNome: %s\nAV1: %.1f - AV2: %.1f - Media: %.1f\n", 
			         vetor[i].nome, vetor[i].av1, vetor[i].av2, vetor[i].media);
		}
	}
}

/*

Questão 03 [2,5 pontos]:
Pede-se o desenvolvimento de uma função que, dada uma string representando um 
número binário (ou seja, contendo apenas os caracteres 0 e 1), converta-o para a base decimal.

Notas:
? A função solicitada deverá chamar outra função que validará se a string representa 
um número binário. Se não consistir em um número binário, o valor -1 deverá ser retornado; 
caso contrário, o número inteiro decimal equivalente será retornado;

? Durante a leitura das questões da prova, será apresentado um exemplo que evidencie o 
processo de transformação de um número binário em decimal.

*/

#include <stdio.h>
#include<string.h>

//Protótipo das funções
int verificar (char *a);
void converter (char *a);
int potencia(int i);

//Implementando a main
int main(void){
	char a[200] = "010010000100010101001100c0100110001001111";
	char b[200]="010010000110010101101100011011000110111100100000010101110110111101101100011100100110010000101100001000000100110100101010010001100010101000100001";
	int x, resp, quant;
	
	printf("%s \n", b);
	
	resp = verificar(b);
	
	if (resp < 0 ){
		printf("\nString nao e' valida!\n");
	} else {
		printf("\nString e' valida!\n\n");
		converter(b);
	}
		
	return 0;
}

//Implementando as Funções
int verificar (char *a) 
{
	int i=0;
	char c;
		
	while(a[i]!='\0'){
		
		c=a[i];
		
		if (! ( (c == '0') || (c == '1') ) )
		{
			return -1;
		}
		
		i++;       
    }
		
}

void converter (char *a){
	
	int i=0, cont=0, pot;
	char c;
	
	while(a[cont]!='\0'){
		pot=0;
		
		for(i=0; i<8; i++){
			
			c=a[cont];
						
			if(c == '1'){
				pot = pot + potencia(7-i);
			} 
			
			cont++;
		}
	
		printf("%c", pot);
	
	}	
}

int potencia(int i){
    if(i == 0){
    	return 1;
	}        
    else
    {
    	return 2 * potencia(i - 1);
	}
        
}

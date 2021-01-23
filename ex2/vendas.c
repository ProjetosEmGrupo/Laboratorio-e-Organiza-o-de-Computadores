#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(void){

	FILE *arq;	
	// fopen abre um arquivo TEXTO para LEITURA indicado por "r" (read)
	arq = fopen("vendas.txt", "r");

	// Se houve erro na abertura, exibe essa mensagem
	if (arq == NULL)  {
		printf("Problemas na abertura do arquivo \n");
     return 0;
	}

  int *codigo, c, *quantidade, q, tam = 0;
  float *preco, p;
  codigo = NULL;
  preco = NULL;
  quantidade = NULL;
  while (fscanf(arq,"%d;%d;%f\n", &c, &q, &p)!= EOF){
	// Lê uma linha (inclusive com o '\n')	
	tam++;
	codigo = (int *)realloc(codigo, sizeof(int)*tam);
	quantidade = (int *)realloc(quantidade, sizeof(int)*tam);
	preco = (float *)realloc(preco, sizeof(float)*tam);
	codigo[tam-1] = c;
	quantidade[tam-1] = q;
	preco[tam-1] = p;  
  }
  int n = 1;
  while(n!=0){
  	double total = 0;
  	int i=0;
	printf("Digite o codigo: ");
	scanf("%d",&n);
	if(n>=10000 && n<=21000){
		for(i; i<=tam-1;i++){
			if(codigo[i] == n){
				total = total + quantidade[i] * preco[i];
			}
		}
		printf("Total vendido do produto %d = R$ %.2lf\n\n",n,total);
	}
	else if(n!=0){
		printf("%d Codigo invalido (deve ser entre 10000 e 21000)\n\n",n);
	}
  }
  printf("\n\nFim do Programa\n");
  fclose(arq);
  
  return(0);
}


#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(void){

	FILE *arq;

	
	// fopen abre um arquivo TEXTO para LEITURA indicado por "r" (read)
	arq = fopen("ALUNOS.txt", "r");

	// Se houve erro na abertura, exibe essa mensagem
	if (arq == NULL)  {
		printf("Problemas na abertura do arquivo \n");
     return 0;
	}
	
	//Cabeçalho da exibição
	printf("Matricula: Nome Do aluno:\tMedia Final: \tSituacao: \n");

  int *codigo, c;
  double *valor, n1, n2, n3, conta;
  char n[4001];


  while (fscanf(arq,"%d;%lf;%lf;%lf;%[^\n]s\n", &c, &n1, &n2, &n3, n)!= EOF){
	// Lê uma linha (inclusive com o '\n')	
   	
    conta = (4*n1+4*n2+2*n3)/10;

    printf("%d %s \t%.1lf\t %s\n", c, n, conta, (conta>=6 ? "Aprovado": "Reprovado"));
	conta = (4*n1+4*n2+2*n3)/10;
  
  }
  fclose(arq);
}


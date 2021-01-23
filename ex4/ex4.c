#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int particiona(int v[], int p, int u){
	int x = v[p];
	int i = p-1, j = u+1;
	while(1){
		j--;
		i++;
		while (v[j]>x) j--;
		while (v[i]<x) i++;
		if (i<j){
			int aux; 
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
		else return j;
	}
}
	
void qs(int v[], int p, int u){
	if(p==u) return;
	int m;
	m = particiona(v,p,u);
	qs(v,p,m);
	qs(v,m+1,u);
}

int main(void){
  srand(time(NULL));
  FILE *arq;  
  FILE *arq2; 
  int *codigo, c, tam = 0, tipo = 0;
  codigo = NULL;
  arq = fopen("ENTRADA_50k.txt", "r");
  arq2 = fopen("saida.txt", "w");

  if (arq == NULL || arq2 == NULL)  {
    printf("Problemas na abertura dos arquivos \n");
    return 0;
  }
  
  while (tipo < 1 || tipo > 2){//valida tipo
    printf("Digite para ordenar\n1-)Crescente\n2-)Decrescente\n");
    scanf("%d", &tipo);
  }
  
  while (fscanf(arq,"%d\n", &c)!= EOF){//le arquivo
    tam++;
    codigo = (int *)realloc(codigo, sizeof(int)*tam);
    codigo[tam-1] = c;
  }
  qs(codigo,0,tam-1);//ordena
   
 
  
  if(tipo == 1){
  		int i = 0;//contador
  		for (i; i<=tam-1;i++){//escreve arquivo
  			fprintf(arq2,"%d\n",  codigo[i]);
  		}
  }
  else{
  	int i = tam-1;//contador
  		for (i; i>=0;i--){//escreve arquivo
  			fprintf(arq2, "%d\n",  codigo[i]);
  		}
  }
  
 
	
printf("\n\nFim do Programa\n");
fclose(arq);
fclose(arq2);
return(0);
}




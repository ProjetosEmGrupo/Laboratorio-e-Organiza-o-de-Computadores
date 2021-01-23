#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int round(double number){
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

int main(void){
  	srand(time(NULL));
 	FILE *arq;  
  	FILE *arq2; 
  
  	int *codigo, c, tam = 0;
 	float *quantidade, q;  
  	float *preco, p, *margem, m;
  	char *controle_estoque, ce;
  
  	preco = NULL;
  	margem = NULL;
 	quantidade = NULL;  
  	codigo = NULL;
  	controle_estoque = NULL;
  	arq = fopen("produtos.txt", "r");
  	arq2 = fopen("saida.txt", "w");

  	if (arq == NULL || arq2 == NULL)  {
    	printf("Problemas na abertura dos arquivos \n");
    	return 0;
  	}
  	/*
  	while (tipo < 1 || tipo > 2){//valida tipo
    	printf("Digite para ordenar\n1-)Crescente\n2-)Decrescente\n");
    	scanf("%d", &tipo);
  	}*/
  
  	while (fscanf(arq,"%d;%c;%f;%f;%f;\n", &c, &ce, &q, &p, &m)!= EOF){ //le arquivo
    	tam++;
    	codigo = (int *)realloc(codigo, sizeof(int)*tam);
		controle_estoque = (char *)realloc(controle_estoque, sizeof(char)*tam);
    	quantidade = (float *)realloc(quantidade, sizeof(float)*tam);
    	preco = (float *)realloc(preco, sizeof(float)*tam);
    	margem = (float *)realloc(margem, sizeof(float)*tam);
    	codigo[tam-1] = c;
    	controle_estoque[tam-1] = ce;
    	quantidade[tam-1] = q;
    	preco[tam-1] = p;
    	margem[tam-1] = m;
	}
		
	int valida=0, ano, mes, dias, i, qtdvendas = 0, k = 0, taxa, sinal;	
	float ocorrencias,qtd;
	ano = 1970;
	while(ano<2016 || (mes<1 || mes>12)){
		printf("Digite o ano da compra (Min. 2016) ");
		scanf("%d", &ano);
		printf("Digite o mes da compra (Em Numeros: 1 a 12) ");
		scanf("%d", &mes);
	}//valida mes
	 
	while (qtdvendas<1){
		printf("Digite a quantidade de vendas diaria ");
		scanf("%d", &qtdvendas);
	}//valida quantidade de vendas por dia
	
	if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) dias = 31;	
	else if(mes == 4 || mes == 6 || mes == 9 || mes == 11) dias = 30;
	else if(mes == 2)
		if((ano % 4 == 0 && ano % 100 !=0) || (ano % 400 == 0))
			dias = 29;
		else 
			dias = 28;
			//valida dias mes
				
	
	for (i = 1; i<=dias; i++){
		int j = 1;
		for (j; j<=qtdvendas;j++){
			int busca = -1;
			printf("Venda %d do Dia %d \n", j, i);
			while (busca == -1){
				int cont;
				printf("Digite o Codigo do Produto ");
				scanf("%d", &c);
				for (cont=0; cont < tam-1; cont++){
					if(codigo[cont] == c){
						busca  = cont;
					}
				}
			}//valida codigo produto
			printf("Digite a quantidade que foi comprada ");
			scanf("%f", &qtd);
						
			//gravação de dados no arquivo
			
			ocorrencias = round((dias * qtdvendas) * 0.35);
			if(k % (int)ocorrencias == 0){
				taxa = rand()%9;
				sinal = rand()%2;
				if(sinal == 0){
					taxa = taxa * -1;
				}
			}
			else{
				taxa = 0;
			}
			if(mes<10 && dias<10){				
				fprintf(arq2,"%d;0%d;0%d;%d;%.3f;%.2f;\n",  ano, mes, i, codigo[busca], qtd, (preco[busca] * ((margem[busca] * 0.01) + 1)) + ((preco[busca] * ((margem[busca] * 0.01) + 1)) * (taxa * 0.01)));
			}
			else if(mes<10 && dias>9){
				fprintf(arq2, "%d;0%d;%d;%d;%.3f;%.2f;\n",  ano, mes, i, codigo[busca], qtd, (preco[busca] * ((margem[busca] * 0.01) + 1)) + ((preco[busca] * ((margem[busca] * 0.01) + 1)) * (taxa * 0.01)));
			}
			else if(mes>9 && dias<9){
				fprintf(arq2, "%d;%d;0%d;%d;%.3f;%.2f;\n",  ano, mes, i, codigo[busca], qtd, (preco[busca] * ((margem[busca] * 0.01) + 1)) + ((preco[busca] * ((margem[busca] * 0.01) + 1)) * (taxa * 0.01)));
			}
			else{
				fprintf(arq2, "%d;%d;%d;%d;%.3f;%.2f;\n",  ano, mes, i, codigo[busca], qtd, (preco[busca] * ((margem[busca] * 0.01) + 1)) + ((preco[busca] * ((margem[busca] * 0.01) + 1)) * (taxa * 0.01)));
			}			
			k++;			
		}
	}
	
  	printf("\n\nFim do Programa\n");
	fclose(arq);
	fclose(arq2);
	return(0);
}




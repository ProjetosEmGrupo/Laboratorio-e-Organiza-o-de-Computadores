#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int main(void){
  srand(time(NULL));
  FILE *arq;  
  FILE *arq2; 
  int *codigo, c, tam = 0, tipo = 0, tamanho=0;
  codigo = NULL;
  arq = fopen("matr.txt", "r");
  arq2 = fopen("senhas.txt", "w");

  if (arq == NULL || arq2 == NULL)  {
    printf("Problemas na abertura dos arquivos \n");
    return 0;
  }
  
  while (tipo < 1 || tipo > 5){//valida tipo
    printf("Digite um tipo de senha que deseja criar\n1-)Numerica\n2-)Alfabetica\n3-)Alfanumerica 1 (Maiusculas e Algarismos)\n4-)Alfanumerica 2 (Minusculas e Algarismos)\n5-)Geral\n");
    scanf("%d", &tipo);
  }
  while (tamanho <= 0 ){// valida tamanho
    printf("\nDigite um tamanho para a senha\n");
    scanf("%d", &tamanho);
  }


  while (fscanf(arq,"%d\n", &c)!= EOF){//le arquivo
    tam++;
    codigo = (int *)realloc(codigo, sizeof(int)*tam);
    codigo[tam-1] = c;
  }
  

  int i = 0;//contador
  char senha[tamanho]; 
  for (i; i<=tam-1;i++){//escreve arquivo
    
    int l=0;//contador da senha
    if (tipo == 1){
      for(l;l <=tamanho-1;l++){
        senha[l] = (rand()% 10) + 48;
      }
    } 
    else if(tipo == 2){
      for(l;l <=tamanho-1;l++){
      int numero = (rand() % 58) + 'A'; //65 a 90 / 97 a 122
      while(numero < 97 && numero >90){
        numero = (rand() % 58 )+ 'A';
      }
      senha[l] = numero;
    }
  }
  else if(tipo == 3){
   for(l;l <=tamanho-1;l++){

      int numero = (rand() % 43) + '0';
      while(numero < 65 && numero > 57){

        numero = (rand() % 43) + '0';
      }
      senha[l] = numero;        
    }   
  }
  else if(tipo == 4){
    for(l;l <=tamanho-1;l++){
      int numero = (rand() % 75) + '0';
      while(numero < 'A' && numero > '9'){
        numero = (rand() % 75) + '0';
      }
      senha[l] = numero;        
    }   
  }
  else if(tipo == 5){
    for(l;l <=tamanho-1;l++){
      int numero = (rand() % 90) + '!';
      while(numero < 'a' && numero > 'Z' || numero == '/'){
        numero = (rand() % 90) + '!';
      }
      senha[l] = numero;        
    }   
  }
	
  fprintf(arq2, "%d;%s;\n",  codigo[i], senha);
}
printf("\n\nFim do Programa\n");
fclose(arq);
fclose(arq2); 
return(0);
}


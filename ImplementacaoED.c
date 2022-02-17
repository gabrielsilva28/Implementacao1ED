#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

float *MultMat ( float * vma, float *vmb, int n, int m, int p, int q);

float *TranspostadeMatA( float* vma, int n, int m);

float *MultMatATranspB ( float * vma, float *vmb, int n, int m, int p, int q);

void MostrarMatriz (float *vmx, int x, int y);

int main(void) {
  int opcao,n,m,p,q,k, verificaMA=0, verificaMB=0,mostraM;
  float *vma,*vmb,*calcula,*transp;
  do{
    
    printf("\n1-Ler a Matriz A\n2-Ler a Matriz B\n3-Multiplicar a Matriz A pela Matriz B\n4-Calcular a Transposta da Matriz A\n5-Multiplicar a Matriz A pela Transposta da Matriz B\n6-Mostrar Matriz A ou Matriz B\n0-Sair\n\n");
    scanf("%d",&opcao);
    switch(opcao){
      case 0:
        
        printf("Programa encerrado com sucesso!");
        break;
      case 1:
        
        printf("Digite nº de linhas e o nº de colunas\n");
        scanf("%d %d",&n,&m);
        vma = (float *) malloc (sizeof (float)*n*m);
        if ( vma != NULL && n>0 && m>0) {
          printf("\nDigite os valores da Matriz A: \n");
          for (int i=0; i<n; i++ ){
            for (int j=0; j<m; j++ ) {
              k = i*m+j;
              scanf( "%f", &vma[k]);
            }
          }
        
          verificaMA = 1;

        }

        else{
          printf("\nOcorreu um erro ao ler a Matriz A\n");
          verificaMA=0;
        }

        break;

      case 2:

        printf("Digite nº de linhas e o nº de colunas\n");
        scanf("%d %d",&p,&q);
        
        vmb = (float *) malloc (sizeof (float )*p*q);
        
        if ( vmb != NULL && p>0 && q>0) {
          printf("\nDigite os valores da Matriz B: \n");
          for (int i=0; i<p; i++ ){
            for (int j=0; j<q; j++ ) {
              k = i*q+j;
              scanf( "%f", &vmb[k]);
            }
          }

          verificaMB = 1;
        }

        else{
          printf("\nOcorreu um erro ao ler a Matriz B\n");
          verificaMB=0;
        }

        break;

      case 3:
        
        if(verificaMA == 1 && verificaMB == 1){
          if(m == p ){
            printf("Multiplicao da matriz A pela B\n");
			calcula = (float *)malloc(sizeof(float)*n*q); 
			if(calcula != NULL){
			  calcula=MultMat (vma,vmb,n,m,p,q);
			 
			  for (int i=0; i<n; i++ ){
                for (int j=0; j<q; j++ ) {
                  printf("%.2f ",calcula[i*q+j]);
                }
                printf("\n");
              }  
            }
          }
        
          else{
            printf("Esse calculo nao pode ser feito\n");
          }
        }
        else{
            printf("Falta matriz\n");
        }
        
        
        break;
      case 4:
        
        if(verificaMA == 1){
          printf("Transposta da matriz A\n");
          transp = (float *)malloc(sizeof(float)*n*m);
          if(transp != NULL){
         
            transp=TranspostadeMatA(vma, n,  m);
            
            for (int i=0; i<m; i++ ){
              for (int j=0; j<n; j++ ) {
                printf("%.2f ",transp[i*n+j]);
              }
              printf("\n");
            }  
          }
        }
        else{
          printf("A matriz A nao foi digitada\n");
        }

        break;

      case 5:
       
        if(verificaMA == 1 && verificaMB == 1){
          if (m==q){
            printf("Multiplicao da matriz A pela Transposta de Matriz B\n");
            calcula = (float *)malloc(sizeof(float)*n*q);
            
            if(calcula != NULL){
              calcula=MultMatATranspB(vma,vmb,n,m,p,q);
              for (int i=0; i<n; i++ ){
                for (int j=0; j<p; j++ ) {
                  printf("%.2f ",calcula[i*p+j]);
                
                }
                printf("\n");
              }
            }  
          }
          else{
            printf("Esse calculo nao pode ser feito\n");
          }
        }
        else{
          printf("Falta matriz\n");
        } 
        
        break;
      

      case 6:

        printf("\nQual matriz a ser mostrada?\n 1 - Matriz A\n 2 - Matriz B\n Escolha uma opcao: ");
        scanf("%d", &mostraM);
        if(mostraM == 1 && verificaMA == 1){
          printf("\nOs valores da matriz A sao:\n");
          MostrarMatriz(vma, n, m);
        }
        else if (mostraM == 2 && verificaMB == 1){
          printf("\nOs valores da matriz B sao:\n");
          MostrarMatriz(vmb, p, q);
        }
        else{
          printf("\nOpcao invalida, tente novamente.\n");
        }
        
        break;	
          
      default:
        
        printf("Tente novamente\n");
        break;
    }

  }while(opcao!=0);

  
}

float *MultMat ( float * vma, float *vmb, int n, int m, int p, int q){
  float *valor;
  if(vma != NULL && vmb != NULL){
    valor = (float *)malloc(sizeof(float)*n*q);
    if(valor != NULL){     
      if(m == p ){
        for(int i = 0; i < n; i++){ 
          for(int j = 0; j < q; j++){ 
            valor[i*q+j]=0;
            for(int k = 0; k < m; k++){
              valor[i*q+j] += vma[i*m+k]*vmb[k*q+j];
            }         
          }
        }
        return valor;  
      }
    }
  }
  
 return FALSE;
}

float *TranspostadeMatA( float* vma, int n, int m){
  float *transp;
    if(vma != NULL){
    transp= (float *) malloc (sizeof (float )*n*m);
    if ( transp != NULL) {
      for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++ ) {
          transp[j*n+i]=vma[i*m+j];
        }
      }
    return transp;
    }
  }
  return FALSE; 
}

float *MultMatATranspB( float * vma, float *vmb, int n, int m, int p, int q){
  float *valor,*transpB;
  if(vma != NULL && vmb != NULL){  
    valor = (float *)malloc(sizeof(float)*n*q);
    if(valor != NULL){  
      transpB= (float *) malloc (sizeof (float )*p*q);
      if ( transpB != NULL) {
        for (int i=0; i<p; i++) {
          for (int j=0; j<q; j++ ) {
            transpB[j*p+i]=vmb[i*q+j];
          }
        }
        if(m == q ){
          for(int i = 0; i < n; i++){ 
            for(int j = 0; j < p; j++){ 
              valor[i*p+j]=0;
              for(int k = 0; k < m; k++){
                valor[i*p+j] += vma[i*m+k]*transpB[k*p+j];
              }
                     
            }
          }  
          return valor;
        }
      }
    }
  }
  return FALSE;
}

void MostrarMatriz (float *vmx, int x, int y){
	int k;
  	for (int i=0; i<x; i++ ){
      for (int j=0; j<y; j++ ) {
      	k = i*y+j;
      	printf("%.2f ",vmx[k]);
      }
    	printf("\n");
    }
  
}



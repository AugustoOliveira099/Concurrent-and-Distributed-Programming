#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// http://www.trsampaio.com/2014/08/31/calculo-numerico-computacional-decomposicao-lu/
// Fonte: http://www.trsampaio.com/
#define n 8000
 
/* void show_matrix(float *mat){
    int i,j;
    for(i=0;i<n;i++){
        printf("|");
        for(j=0;j<n;j++){
            printf(" %.2f",mat[(i*n)+j]);
        }
        printf(" |\n");
    }    
} */

void preencheMatriz(float *A) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            A[(i*n)+j] = j;
        }
    }
}

void calculaMatrizes(int i, int j, float *aux, float *M) {
    M[(i*n)+j] = aux[(i*n)+j]/aux[(j*n)+i];
    
    //multiplica a linha do multiplicar por -(multiplicador)              
    //Movimenta a coluna
    for(int c=j; c<n; c++){
        aux[(i*n)+c] = aux[(i*n)+c]+aux[(j*n)+c]*(-1*(M[(i*n)+j]));
    }  
}
 
void gauss(float *A){
    float *M = (float *)malloc(n*n*sizeof(float));
    float *aux = (float *)malloc(n*n*sizeof(float));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            M[(i*n)+j] = 0;
            aux[(i*n)+j] = A[(i*n)+j];
        }
    }
    //Calculando os multiplicadores da Gauss
    //Movimenta a coluna
    for(int j=0; j<(n-1); j++) {  
        //Movimenta a linha
    	for(int i=j+1; i<n; i++) {
    	    if (aux[(i*n)+j] != 0) {
    	    	calculaMatrizes(i, j, aux, M);
    	    }
         }//Todos os multiplicadores da coluna j estão definidos      
    }

    printf("\n*********RESULTADO FINAL**********\n");
    for(int i=0; i<n; i++) M[(i*n)+i]=1;

    /*printf("\n----Matriz L----\n");
    show_matrix(M);
   
    printf("\n----Matriz U----\n");
    show_matrix(aux);*/
}

 
int main(){
    float *A = (float *)malloc(n*n*sizeof(float));

    preencheMatriz(A);

    /*printf("***Seja A a matriz original***\n");
    printf("----Matriz A----\n");
    show_matrix(A);*/
   
    gauss(A);	
   
    //system("pause");
    return 0;  
}

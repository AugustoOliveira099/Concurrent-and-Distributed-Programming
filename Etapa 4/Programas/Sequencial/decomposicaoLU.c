#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
 
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

void preencheMatriz(float *A, int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            // A[(i*n)+j] = rand()%100000;
            A[(i*n)+j] = j;
        }
    }
}

void calculaMatrizes(int i, int j, float *aux, float *M, int n) {
    M[(i*n)+j] = aux[(i*n)+j]/aux[(j*n)+i];
    
    //multiplica a linha do multiplicar por -(multiplicador)              
    //Movimenta a coluna
    for(int c=j; c<n; c++){
        aux[(i*n)+c] = aux[(i*n)+c]+aux[(j*n)+c]*(-1*(M[(i*n)+j]));
    }  
}
 
void gauss(float *A, float *M, float *aux, int n){
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                M[(i*n)+j] = 0;
                aux[(i*n)+j] = A[(i*n)+j];
            }
        }
        //Calculando os multiplicadores da Gauss
        //Movimenta a coluna
        for(int j=0; j<(n-1); j++){      
        //Movimenta a linha
            for(int i=j+1; i<n; i++){
                ( aux[(i*n)+j] != 0 ) ? calculaMatrizes(i, j, aux, M, n) : NULL;
            }//Todos os multiplicadores da coluna j estão definidos      
        }

        for(int i=0; i<n; i++) M[(i*n)+i]=1;

    printf("\n*********RESULTADO FINAL**********\n");

    /*printf("\n----Matriz L----\n");
    show_matrix(M);
   
    printf("\n----Matriz U----\n");
    show_matrix(aux);*/
}

 
int main(int argc, char* argv[]){
    int n;

    n = strtol(argv[1], NULL, 10);

    float *A = (float *)malloc(n*n*sizeof(float));
    float *M = (float *)malloc(n*n*sizeof(float));
    float *aux = (float *)malloc(n*n*sizeof(float));

    // srand( (unsigned)time(NULL) );
    
    preencheMatriz(A, n);

    /*printf("***Seja A a matriz original***\n");
    printf("----Matriz A----\n");
    show_matrix(A);*/

    gauss(A, M, aux, n);
   
    //system("pause");
    return 0;  
}

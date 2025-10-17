#include "include/matIO.h"

void readMatrix(Matrix *A){

    for(int i=0; i<(A->rows); i++){
        for(int j=0; j<(A->cols); j++){
            scanf("%d", &(A->mat[i][j]));
        }
    }
}

void printMatrix(Matrix A){
    for(int i=0; i<A.rows; i++){
        for(int j=0; j<A.cols; j++){
            printf("%d ", (A.mat[i][j]));
        }
        printf("\n");
    }
}

#include "include/matAlg.h"

int addMatrix(Matrix A, Matrix B){
    if(A.rows!=B.rows || A.cols!=B.cols){
        printf("The Matrices are not compatible for addition!!\n");
        return -1;
    }
    
    printf("Resultant after Addition:\n");
    for(int i=0; i<A.rows; i++){
        for(int j=0; j<B.rows; j++) {
            printf("%d ", A.mat[i][j]+B.mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int subMatrix(Matrix A, Matrix B){
    if(A.rows!=B.rows || A.cols!=B.cols){
        printf("The Matrices are not compatible for subtraction!!\n");
        return -1;
    }
    
    printf("Resultant after Subtraction:\n");
    for(int i=0; i<A.rows; i++){
        for(int j=0; j<B.rows; j++) {
            printf("%d ", A.mat[i][j]-B.mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int multMatrix(Matrix A, Matrix B){
    if(A.cols!=B.rows){
        printf("The Matrices are not compatible for multiplication!!\n");
        return -1;
    }
    printf("Resultant after Multiplication:\n");
    for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < B.cols; j++) {
			int res= 0;

			for (int k = 0; k < A.cols; k++) {
				res += A.mat[i][k] * B.mat[k][j];
			}

			printf("%d ", res);
		}

		printf("\n");
	}

    return 0;
}

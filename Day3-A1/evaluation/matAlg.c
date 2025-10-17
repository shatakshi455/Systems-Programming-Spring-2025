#include "matAlg.h"

int addMat(Matrix matA, Matrix matB)
{
	int i,j;
	Matrix matC;

	matC.row=matA.row;
	matC.col=matA.col;
	for(i=0;i<matA.row;i++) {
		for(j=0;j<matA.col;j++) {
			matC.elem[i][j]=matA.elem[i][j]+matB.elem[i][j];
		}
	}
	printf("Resultant Matrix after addition\n");
	printMatrix(matC);
	return 0;
}

int subMat(Matrix matA, Matrix matB)
{
	int i,j;
	Matrix matC;

	matC.row=matA.row;
	matC.col=matA.col;
	for(i=0;i<matA.row;i++) {
		for(j=0;j<matA.col;j++) {
			matC.elem[i][j]=matA.elem[i][j]-matB.elem[i][j];
		}
	}
	printf("Resultant Matrix after subtraction\n");
	printMatrix(matC);
	return 0;
}


int multMat(Matrix matA, Matrix matB)
{
	int i,j,k;
	Matrix matC;
	
	matC.row=matA.row;
	matC.col=matB.col;
	for(i=0;i<matA.row;i++) {
		for(k=0;k<matA.col;k++) {
			matC.elem[i][j]=0;
			for(j=0;j<matB.col;j++) {
				matC.elem[i][j]+=matA.elem[i][k]*matB.elem[k][j];
			}
		}
	}
	printf("Resultant Matrix after multiplication\n");
	printMatrix(matC);
	return 0;
}

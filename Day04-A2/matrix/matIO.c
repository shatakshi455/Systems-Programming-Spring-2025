#include "matIO.h"

void readMatrix(Matrix *mat) 
{
	int i,j;
	printf("Enter the Matrix elements: ");
	for(i=0;i<mat->row;i++) {
		for(j=0;j<mat->col;j++) {
			scanf("%d",&mat->elem[i][j]);
		}
	}
}

void printMatrix(Matrix mat) 
{
	int i,j;
	for(i=0;i<mat.row;i++) {
		for(j=0;j<mat.col;j++) {
			printf("%d ",mat.elem[i][j]);
		}
		printf("\n");
	}
}

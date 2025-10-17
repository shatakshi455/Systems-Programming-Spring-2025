#include "defs.h"
#include "matIO.h"
#include "matAlg.h"

int main()
{
	int choice;
	Matrix matA, matB;

	printf("Enter the details of the first matrix.\n");
	printf("Dimension of the Matrix [row col]: ");
        scanf("%d %d",&matA.row,&matA.col);
	readMatrix(&matA);
	printMatrix(matA);

	printf("Enter the details of the second matrix.\n");
	printf("Dimension of the Matrix [row col]: ");
        scanf("%d %d",&matB.row,&matB.col);
	readMatrix(&matB);
	printMatrix(matB);

	printf("Enter your choice for matrix operation 1 for addition, 2 for subtraction, 3 for multiplication, else no operation.");
	scanf("%d",&choice);
	if(choice==1 || choice==2) {
		if(matA.row==matB.row && matA.col==matB.col) {
			(choice==1)? addMat(matA,matB):subMat(matA,matB);
		} else {
                	printf("Dimensionality issue .... addition is not possible!");
		}
	} else if(choice==3){
		if(matA.col==matB.row) {
			multMat(matA,matB);
	        } else {
               		printf("Dimensionality issue .... multiplication is not possible!");
		}
	}

	return 0;
}

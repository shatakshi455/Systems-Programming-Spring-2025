#include "include/matIO.h"
#include "include/matAlg.h"

int main(){
    Matrix A, B;

    printf("Enter the details of the first matrix.\nDimension of the Matrix [row, col]: ");
    scanf("%d %d", &(A.rows), &(A.cols));
    printf("\nEnter the matrix elements: ");
    readMatrix(&A);
    printMatrix(A);

    printf("Enter the details of the second matrix.\nDimension of the Matrix [row, col]: ");
    scanf("%d %d", &(B.rows), &(B.cols));
    printf("\nEnter the matrix elements: ");
    readMatrix(&B);
    printMatrix(B);

    printf("type 1 for addition, 2 for subtraction, 3 for multiplication, else no operation.\n");
    int op=0;
    scanf("%d", &op);
    if(op==1) addMatrix(A, B);
    else if(op==2) subMatrix(A, B);
    else if(op==3) multMatrix(A, B);
    return 0;
}

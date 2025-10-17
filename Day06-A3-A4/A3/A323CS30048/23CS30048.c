#include <stdlib.h>
#include <stdio.h>

int isPrime(int n){
    if(n==2) return 1;
    for(int i=2; i<n; i++) {
        if(n%i==0) return 0;
    }
    return 1;
}

void factor(int A[], int st[], int* size, int num){
    for(int i=1; i<=1000; i++){
        if(num%i==0 && !A[i]) {
            st[*size]=i;
            (*size)++;
            A[i]=1;
        }
    }

    for(int i=1001; i<num; i++){
        if(num%i==0 && !isPrime(i)) factor(A, st, size, i);
        else if(num%i==0 && isPrime(i)) factor(A, st, size, i+1);
    }
    
}
int main()
{
    int n,m,num;
    printf("Enter your number: ");
    scanf("%d",&num);

    int A[1001], st[1001];
    int size=0;
    for(int i=0; i<=1000; i++) {A[i]=0; st[i]=0;}

    factor(A, st, &size, num);
    for(int i=0; i<size; i++) printf("%d ", st[i]);
    return 0;
}
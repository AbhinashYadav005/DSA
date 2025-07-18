#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void InsertionSort(int *A,int n){
    int j,temp;
    for(int i=0; i<n ;i++){
        j=i-1;
        temp = A[i];
        while( j >= 0 && temp < A[j]){
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = temp;
    }
    printf("The sorted elements: \n");
    for(int i=0; i<n ; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}


int main(){
    int *A,i,n;

    printf("Enter the total numbers to be sorted: ");
    scanf("%d",&n);

    A=(int *)malloc(n * sizeof(int));
    
    if(A == NULL){
        printf("Memory allocation failed!!");
        return 1;
    }

    for(i=0;i<n;i++){
        printf("Enter A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    InsertionSort(A,n);

    free(A);
    return 0;
}
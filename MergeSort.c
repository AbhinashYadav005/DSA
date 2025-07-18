#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

void Merge(int *A,int l,int m,int r){
    int i,j,k;
    int *B;
    B = (int *) malloc(r * sizeof(int));
    i = l;
    j = m;
    k = l;
    while( i < m && j <= r){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for( ; i<m ; i++,k++)
        B[k] = A[i];
    for( ; j<=r ; j++,k++)
        B[k] = A[j];
    for( i=l ; i<=r ; i++)
        A[i] = B[i];
}

void MergeSort(int *A,int l,int r){
    int m;
    if(l < r){
        m = floor((l+r)/2);
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m+1,r);
    }
}

int main(){
    int *A,i,l,r;

    printf("Enter the total numbers to be sorted: ");
    scanf("%d",&r);

    A=(int *)malloc(r * sizeof(int));
    
    if(A == NULL){
        printf("Memory allocation failed!!");
        return 1;
    }

    for(i=0;i<r;i++){
        printf("Enter A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    MergeSort(A,l=0,r-1);

    printf("The sorted elements: \n");
    for(int i=0;i<r;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
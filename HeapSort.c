#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void MAX_HEAP(int *A, int i, int n){
    
    int l = left(i);
    int r = right(i);
    int largest = i;

    if( l < n && A[l] > A[largest])
        largest = l;
    if( r < n && A[r] > A[largest])
        largest = r;

    if( largest != i){
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MAX_HEAP(A,largest,n);
    }
}

void BuildHeap(int *A, int n){

    for(int i = n / 2 - 1; i >= 0; i--){
        MAX_HEAP(A,i,n);
    }
}

void HeapSort(int *A, int n){
    BuildHeap(A,n);
    for(int i = n-1; i > 0; i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        MAX_HEAP(A,0,i);
    }
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

    HeapSort(A,n);
    
    printf("The sorted elements: \n");
    for(int i=0 ;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
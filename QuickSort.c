#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int Partition(int *A, int l, int r){
    int x,y,pivot,temp;
    x=l;
    y=r;
    pivot = A[l];
    while( x < y){
        while(A[x] <= pivot && x<=r)
             x++;
        while(A[y] > pivot)
             y--;
        if( x < y){
           temp = A[x];
           A[x] = A[y];
           A[y] = temp;
        }
    }
    temp = A[l];
    A[l] = A[y];
    A[y] = temp;

    return y;
}

void QuickSort(int *A, int l, int r){
    int p;
    if(l < r){
        p = Partition(A,l,r);
        QuickSort(A,l,p-1);
        QuickSort(A,p+1,r);
    }
}


int main(){
    int *A,i,r,l;

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
    QuickSort(A,l=0,r-1);

    printf("The sorted elements: \n");
    for(int i=0;i<r;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
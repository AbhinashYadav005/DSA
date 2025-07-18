#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void BubbleSort(int *A,int n){

    int i,j;
    int temp;
    for(i = 0; i<n-1; i++){

        for(j=0;j<n-i-1;j++){

            if(A[j]>A[j+1]){

                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    printf("The sorted array is: \n");
    for(i = 0;i<n;i++ ){
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

    BubbleSort(A,n);

    free(A);
    return 0;
}
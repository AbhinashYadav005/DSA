#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void SelectionSort(int *A,int n){
    int least, i,pos,temp;
    for(i=0; i<n; i++){
        least = A[i];
        pos = i;
        for(int j=i+1;j<n;j++){
            
            if(least>A[j]){
                 least = A[j];
                 pos = j; 
            }
        }
        if(i != pos){
             temp = A[i];
             A[i] = A[pos];
             A[pos] = temp;
        }
    }
    printf("The sorted array is: \n");
    for(i=0;i<n;i++){
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

    SelectionSort(A,n);

    free(A);
    return 0;
}
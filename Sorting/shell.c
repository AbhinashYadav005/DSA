#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000


void shellSort(int A[], int n){
    
    int temp, i, j, gap;
    
    for (gap = n/2; gap > 0; gap /= 2){
        
        for(i = gap; i < n; i++ ){
            temp = A[i];
            j = i;

            while ( j >= gap && A[j - gap] > temp){
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = temp;
        }
    }
}

void Display(int A[], int n){
    for(int i=0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){
    int A[MAX], i, n;
    long diff;
    time_t t1, t2;
    printf("Enter the n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Enter A[%d]: ",i);
        scanf("%d",&A[i]);
    }
    Display(A,n);
    t1 = time(NULL);
    shellSort(A,n);
    t2 = time(NULL);
    printf("The sorted array:\n");
    Display(A,n);
    diff = difftime(t2,t1);
    printf("The time required is %lf seconds",diff);
    return 0;
}
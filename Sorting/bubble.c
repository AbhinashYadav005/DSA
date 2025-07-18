#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

void bubble_sort(int A[], int n){
    int i, j, temp;
    for(i = 0; i<n-1; i++){
        for(j=0 ; j<n-i-1; j++){
            if (A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void display(int A[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d  ",A[i]);
    }
    printf("\n");
}

int main(){
    int i, A[MAX], n;
    double diff;
    time_t t1, t2;
    printf("Enter n: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        A[i] = rand();
    }

    display(A, n);
    t1 = time(NULL);
    bubble_sort(A, n);
    t2 = time(NULL);
    printf("After Sorting: \n");
    display(A, n);
    diff = difftime(t2, t1);
    printf("The time taken is %lf sec",diff);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 100000

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

void MAX_HEAP(int A[], int i, int n){
    
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

void BuildHeap(int A[], int n){

    for(int i = n / 2 - 1; i >= 0; i--){
        MAX_HEAP(A,i,n);
    }
}

void HeapSort(int A[], int n){
    BuildHeap(A,n);
    for(int i = n-1; i > 0; i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        MAX_HEAP(A,0,i);
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
    HeapSort(A, n);
    t2 = time(NULL);
    printf("After Sorting: \n");
    display(A, n);
    diff = difftime(t2, t1);
    printf("The time taken is %lf sec",diff);
    return 0;
}
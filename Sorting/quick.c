#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

int Partition(int A[], int l, int r){
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

void QuickSort(int A[], int l, int r){
    int p;
    if(l < r){
        p = Partition(A,l,r);
        QuickSort(A,l,p-1);
        QuickSort(A,p+1,r);
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
    QuickSort(A, 0, n-1);
    t2 = time(NULL);
    printf("After Sorting: \n");
    display(A, n);
    diff = difftime(t2, t1);
    printf("The time taken is %lf sec",diff);
    return 0;
}
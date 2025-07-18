#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 100000


void Merge(int A[], int l, int m, int r){
    int B[MAX];
    int i =l;
    int j = m;
    int k = l;
    while( i<m && j<=r){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for( ; i<m; i++,k++)
        B[k] = A[i];
    for( ; j<=r; j++, k++)
        B[k] = A[j];
    for (i = l;i<=r; i++)
        A[i] = B[i];
}


void Merge_sort(int A[], int l, int r){
    int m;
    if(l < r){
        m = floor((l+r)/2);
        Merge_sort(A, l, m);
        Merge_sort(A, m+1, r);
        Merge(A, l, m+1, r);
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
    int i, A[MAX], n, l, r;
    double diff;
    time_t t1, t2;
    printf("Enter n: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
        A[i] = rand();
    }
    display(A, n);
    t1 = time(NULL);
    Merge_sort(A, 0, n-1);
    t2 = time(NULL);
    printf("After Sorting: \n");
    display(A, n);
    diff = difftime(t2, t1);
    printf("The time taken is %lf sec",diff);
    return 0;
}
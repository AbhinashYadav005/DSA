// This program is Selection sort of one dimensional array
#include<stdio.h>
#include<conio.h>
#define MAX_SIZE 50

void Display_Array_Element(int A[], int len){
    int i;
    for(i = 0; i < len; i++)
       printf("\t%d",A[i]);
}

void Selection_sort(int A[], int len){
    int i, j, max, index;
    for(i=(len-1); i>0; i--){
        max = A[0]; 
        index = 0;
        for(j=0; j<=i; j++){
            if(A[i]>max){
                max = A[j];
                index = j;
            }
        }
        A[index] = A[i];
        A[i] = max;
    }
}

void main(){
    int len = 7;
    int A[] = {21, 32, 4, 54, 43, 23, 10};
    printf("\nBefore sorting:");
    Display_Array_Element(A, len);
    Selection_sort(A, len);
    printf("\nAfter sorting: ");
    Display_Array_Element(A, len);
}
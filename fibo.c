#include<stdio.h>
#define MAX 100

long int table[MAX]= {0};

long int Fibo(int n){
    if( n == 1 || n==2)
       return 1;
    else{
        if(table[n]==0){    //the value is not in table
            table[n] = Fibo(n-1) + Fibo(n-2);
        }
        return table[n];
    }
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("The fibonacci is %ld \n",Fibo(n));
    return 0;
}
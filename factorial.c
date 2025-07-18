#include<stdio.h>

long int tailFact(int n, long int a){
    if(n == 1)
       return a;
    else
      return tailFact(n-1,a*n);
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("The factorial is %ld\n",tailFact(n,1));
}
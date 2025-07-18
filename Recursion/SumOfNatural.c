#include<stdio.h>

long int SUM(int n){
    if(n == 1)
       return 1;
    else
       return n+SUM(n-1);
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("The sum is %ld\n",SUM(n));
    return 0;
}
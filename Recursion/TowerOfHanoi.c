#include<stdio.h>
#include<time.h>

void TOH(int n, char src, char dest, char tmp){
    if(n == 1)
       printf("Move disc %d from %c to %c\n",n,src,dest);
    else{
        TOH(n-1,src,tmp,dest);
        printf("Move disc %d from %c to %c\n",n,src,dest);
        TOH(n-1,dest,tmp,src);
    }
}

int main(){
    int n;
    time_t start,end;
    double seconds;
    printf("Enter the no. of dics: ");
    scanf("%d",&n);
    start = time(NULL);
    TOH(n,'A','C','B');
    end = time(NULL);
    seconds = difftime(end,start);
    printf("The time required is %lf seconds\n",seconds);
    return 0;
}
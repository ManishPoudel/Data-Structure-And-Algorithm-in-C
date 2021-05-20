/*Recursion with memorization.
    Fibonnaci series with memorization.*/
#include<stdio.h>

int f[51];
int fib(int n){
    if(f[n]!=-1){
        return f[n];
    }
    f[n]=fib(n-1)+fib(n-2);
    return f[n];
}

int main(){

    for(int i=0;i<51;i++){
        f[i]=-1;
    }
    f[0]=0;
    f[1]=1;

    int j;
    j=40;
    printf("%d",fib(j));
    
}
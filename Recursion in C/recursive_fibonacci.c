/* Fibonacci series using recursion.*/
#include <stdio.h>

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    n=7;
    printf("%d ",fib(n));
}
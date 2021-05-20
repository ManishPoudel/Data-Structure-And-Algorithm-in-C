/* Fibonacci series in C without recursion.*/
#include <stdio.h>

int fib(int n){
    if(n<=1){
        return n;
    }
    int f1,f2,f;
    f1=0;
    f2=1;
    for(int i=2;i<=n;i++){
        f=f1+f2;
        f1=f2;
        f2=f;
    }
    return f;
}

int main (){
   printf("%d",fib(40));
}
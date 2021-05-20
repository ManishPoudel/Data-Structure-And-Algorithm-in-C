/* Recursive method of factorial in c.*/

#include <stdio.h>

int factorial(int i){
    if(i==0){
        return 1;
    }
    else{
        return i*factorial(i-1);
    }
}

int main(){
    int i=5;
    printf("%d",factorial(i));
}
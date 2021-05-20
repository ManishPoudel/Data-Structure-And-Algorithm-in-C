/* If even then does -1 and if odd then does +1 and prints.*/
#include <stdio.h>

void odd(int n);

void even(int n){
    if(n<10){  
    printf("%d ",n-1);
    n++;
    odd(n);
    }
    return;
}

void odd(int n){
    if(n<10){
    printf("%d ",n+1);
    printf("\n %d is n \n",n);
    n++;
    
    even(n);
    }
    return;
}

int main(){
    odd(1);
}
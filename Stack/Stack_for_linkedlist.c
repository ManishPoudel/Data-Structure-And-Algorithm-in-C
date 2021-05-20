#include <stdio.h>
#include "Stack_for_linkedlist.h"

int top=-1;

void push(struct node *b){
    if(top==maxsize-1){
        printf("The stack is full:StackOverFlow.");
        return;
    }
    top++;
    A[top]=b;   //or combine and write A[++top]=a;.
}

void pop (){
    if(top==-1){
        printf("Error:No Elements left.");
        return;
    }
    top--;
}

struct node *gettop(){
    if(top==-1){
        printf("Nothing to show.");
    }
    return A[top];
}

int empty(){
    if(top==-1){
        return 0;
    }
    return 1;
}

void print(){
    for(int i=0;i<top+1;i++){   //top starts form -1.
        printf("%d ",A[i]);
    }
    printf("\n");
}
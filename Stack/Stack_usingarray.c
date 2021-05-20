#include <stdio.h>

#define maxsize 101

int A[maxsize];
int top=-1;

void push(int a);
void pop();
int gettop();
void print();

int main(){
    push(7);
    push(4);
    push(55);
    push(34);
    pop();
    push(33);
    print();
    int a;
    a=gettop();
    printf("%d ",a);

}

void push(int a){
    if(top==maxsize-1){
        printf("the stack is full:StackOverflow");
        return;
    }
    top++;
    A[top]=a;   //or combine and write A[++top]=a;.
}

void pop (){
    if(top==-1){
        printf("Error:noelement;");
        return;
    }
    top--;
}

int gettop(){
    if(top==-1){
        printf("nothing to show");
        return -1;
    }
    return A[top];
}

void print(){
    for(int i=0;i<top+1;i++){   //top starts form -1.
        printf("%d ",A[i]);
    }
    printf("\n");
}
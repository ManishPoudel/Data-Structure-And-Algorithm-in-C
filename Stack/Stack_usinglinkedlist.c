#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *da;
};
struct node *top;

void pop();
void push(int b);
void print();
int gettop();

int main (){
    push(44);
    push(43);
    push(33);
    printf("\n");
    pop();
    push(32);
    int c;
     c=gettop();      //doesnt works after print();.
     printf("%d \n",c); 
     print();
            
}

void push(int b){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=b;
    temp->da=top;
    top=temp;
}

void pop(){
    struct node *temp1;
    temp1=top;
    if(top==NULL){
        return;
    }
    top=top->da;
    free(temp1);
}

void print(){
    while (top!=NULL){
        printf("%d ",top->data);
        top=top->da;
    }
}

int gettop(){
    return (top->data);
}
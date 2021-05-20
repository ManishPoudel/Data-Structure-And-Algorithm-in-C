#include <stdio.h>
#include "Queue_fortree.h"

int isempty(){
    return (front==-1 && rear==-1)?1:0;
    
}

int isfull(){
    return ((rear+1)%max==front)?1:0;
}

void enqueue(struct node *a){
    if(isfull()){
        printf("queue full");
            return;
    }
    if(isempty()){
        front=rear=0;
    }
    else{
        rear=(rear+1)%max;
    }
    A[rear]=a;
}

struct node *dequeue(){
    struct node *b;
    b=A[front];
    if(isempty()){
        printf("the queue is empty");
    }
    else if(front==rear){
        front=rear=-1;
    }else {
        front=(front+1) %max;
    }
    return b;
}

struct node *fron(){
    return A[front];
}
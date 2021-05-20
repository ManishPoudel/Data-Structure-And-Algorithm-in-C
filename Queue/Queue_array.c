#include <stdio.h>

#define max 9

int A[max];
int front,rear;

void enQueue(int a);
int deQueue();
int isfull();
int isempty();
void print();

int main(){
    front=-1;
    rear=-1;
    enQueue(91);
    enQueue(92);
    enQueue(93);
   int a= deQueue();
    print();
}

void enQueue(int a){
    if(isfull()){
        printf("Queue Full");
        return;
    }
    if(isempty()){
    front=rear=0; //cause 0 doesn't work nice with %.
    }
    else{
        rear=(rear+1)% max;
    }
    A[rear]=a;
}

int deQueue(){
    int a;
    a=A[front];
    if(isempty()){
        printf("Queue Empty");
        return -1;
    }
    else if(front == rear){
        front=rear=-1;
    }else{
        front=(front+1) % max;
    }
    return a;
}

int isfull(){
    return ((rear+1) % max==front)?1:0;
}

int isempty(){
    return (rear==-1 && front==-1)?1:0;
}

void print(){
    int length=(rear+max-front)%max+1;  //since rear can be just at back of front.
    int i;
    for(i=0;i<length;i++){
        printf("%d ",A[(front+i)%max]);//since we need to know where does queue starts
    }
    printf("\n");
}
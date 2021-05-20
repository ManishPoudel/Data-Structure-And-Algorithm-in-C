#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enQueue(int a){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    rear->next=temp;
    rear=temp;

}

int deQueue(){
    struct node *temp2=front;
    int a;
    a=temp2->data;
    if(front==NULL){
        printf("queue empty");
        return 0;
    }else { 
    front=front->next;
    }
    free(temp2);
    return a;
}

void print(){
    struct node *temp3=front;
    while(temp3!=NULL){
        printf("%d ",temp3->data);
        temp3=temp3->next;
    }
    printf("\n");
}
int main(){
    enQueue(10);
    enQueue(11);
    enQueue(12);
    enQueue(13);
    deQueue();
    print();
    printf ("  %d \n ",deQueue());
    print();
}

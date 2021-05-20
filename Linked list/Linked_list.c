#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *da;
};

 struct node *head;

void print();
void insert(int b,int nth); 
void delete(int d);
void reverse();
void recsprint(struct node *r);
void recsrevprint(struct node* t);
void recsrev(struct node *q);

int main (){
    head=NULL;
    insert(2,1);         //to insert elements.
    insert(3,2);
    insert(2,2);
    insert(5,3);   
    print();   
    delete(4);          //to delete the element.
    print();
    reverse(); 
    print();  
    struct node *p=head;      
    recsrevprint(p);   //recursive reverse print.
    printf("\n");
    recsrev(head);          //recursive reversing of list.
    print();
    struct node *sa=head;
    recsprint(sa);
    printf("\n");
    print();    
}

void insert(int b,int nth){
    struct node *temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=b;
    temp1->da=NULL;
    if(nth == 1){
        temp1->da=head;
        head=temp1;
        return;
        }
    struct node *temp2=head;
    for(int i=0;i<nth-2;i++){
        temp2=temp2->da;
    }
    temp1->da=temp2->da;
    temp2->da=temp1;
}

void print(){
    struct node *temp=head;
    if(temp==NULL){
        return;
    }
   while(temp!=NULL){  
        printf("%d ",temp->data);
        temp=temp->da;
    } 
    printf("\n");
}

void delete(int d){
    struct node *temp1=head;
    if(d==1){
        head=temp1->da;
        free(temp1);
        return;
    }
    for(int j=0;j<d-2;j++){
        temp1=temp1->da;
    }
    struct node *temp2=temp1->da;
    temp1->da=temp2->da;            //temp2->next is n^th-1 node address.
    free(temp2);
}

void reverse(){
    struct node *current,*prev,*next;
    current=head;
    prev=NULL;
    do{
        next=current->da;
        current->da=prev;
        prev=current;
        current=next;
    }while(current!=NULL);
    head=prev;
}

void recsprint(struct node *r){           //recursive printing
    if(r==NULL){
    return;
    }  
    printf("%d ",r->data);   // 1.
    recsprint(r->da);
    /*
    : we can combine 1&2 by passing head as argument.
    Now this code works only if head is local:-
    void recsprint(struct node *head){
    if(head==NULL) return;
    printf("%d",head->data);
    recsprint(head->da);
    }
    also we need to pass head as argument in 
    main function 
    struct node *head;
    head=NULL;
    . . . . . 
    recsprint(head)
    */ 
}

void recsrevprint(struct node *t){            //recursive reverse print.
    if(t==NULL){  
        return;   }    
    recsrevprint(t->da);   //when the head is passed locally.
    printf("%d ",t->data);
}

void recsrev(struct node *q){
    if(q->da==NULL){
        head=q;
        return;
    }
    recsrev(q->da);
    struct node *s=q->da;
    s->da=q;
    q->da=NULL;
}
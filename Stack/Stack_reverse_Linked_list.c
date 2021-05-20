/* this program has a header and module so
to use this do :
gcc Stack_reverse_Linked_list.c Stack_for_linkedlist.c -o mainprog
and run mainprog.exe.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack_for_linkedlist.h"

struct node{
    int data;
    struct node* da;
};
struct node *head;

struct node *getnode(int a);
void insertathead(int b);
void insertattail(int c);
void printlist();
void reverse();

int main(){
    head=NULL;
    insertathead(11);
    insertathead(22);
    insertathead(33);
    insertattail(44);
    insertathead(55);
    insertattail(66);
    printlist();
    reverse();
    printlist();

}

struct node *getnode(int a){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=a;
    new->da=NULL;
    return new; 
}

void insertathead(int b){
    struct node *temp1=getnode(b);
    temp1->da=head;     //since head points to begining.
    head=temp1;
}

void insertattail(int c){
    struct node *temp2=getnode(c);
    struct node *temp3=head;
    while(temp3->da!=NULL){
        temp3=temp3->da;
    }
    temp3->da=temp2;
}

void printlist(){
    struct node *temp4=head;
    while(temp4!=NULL){     //put temp4 upto null i.e. temp4.da upto null.
        printf("%d ",temp4->data);
        temp4=temp4->da;
    }
    printf("\n");
}

void reverse(){
    if(head==NULL){
        return;
    }
    struct node *temp5=head;
    while(temp5!=NULL){     //write temp5 not temp5.da to make temp5 NULL.
        push(temp5);
        temp5=temp5->da;
    }

    struct node *temp6=gettop();
    head=temp6;
    pop();
    while(empty()){
        temp6->da=gettop();
        pop();
        temp6=temp6->da;
    }
    temp6->da=NULL;
}
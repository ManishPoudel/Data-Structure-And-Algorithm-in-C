#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

struct node *getnode(int y);    //struct node since it returns node.
void insertathead(int x);
void print();
void revprint();
void insertattail(int z);
void insertat(int a,int b);
void recsprint();
void delete(int c);

int main(){
    head=NULL;
    insertathead(5);
    insertathead(20);
    insertathead(55);
    insertathead(98);
    insertathead(33);
    insertattail(22);
    print();
    //insertat(3,14);
    delete(6);      //doesn't deletes the last element.(bug)
    //print();
    print();
    //recsprint();
    //revprint();       //doesnt prints element inserted by insert(); (bud)
}

struct node *getnode(int y){    //makes and gives new node.
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=y;
    temp->prev=NULL;
    temp->next=NULL;
    return(temp); // this is important 
    /* since we allocated memory in heap passing of local 
    varaiable is very legal. though temp ends its life 
    but its address will have been already asssigned to 
    calling function which let us use the 
    memory we allocated. note that we couldn't have done
    it if we didnt used malloc. */ 

}

void insertathead(int x){   //to insert at begining"head".
    struct node *node1=getnode(x);
    if(head==NULL){
        head=node1;
        return;
    }
    head->prev=node1;    //it puts address of node in the existing head's prev addrs.
    node1->next=head;
    head=node1;
}

void insertattail(int z){
    struct node *tailnode=getnode(z);
    if(head==NULL){
        head=tailnode;
        return;
    }
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=tailnode;
    tailnode->prev=head;
    head=tailnode;
}

void insertat(int a,int b){
    struct node *make=getnode(b);
    if(a==1){
        make->prev=NULL;
        make->next=head;
        head=make;
        return;
    }
    if(head->prev!=NULL){
        while(head->prev!=NULL){
            head=head->prev;
        }
    }
    for(int j=0;j<a-2;j++){
        head=head->next;
    }
    make->prev=head;
    make->next=head->next;
    head->next=make;
    head=make;
}
void print(){
    struct node *temp1=head;
    if(temp1==NULL){
        return;
    }
    if(temp1->prev!=NULL){
        while(temp1->prev!=NULL){
            temp1=temp1->prev;
        }
    }
     while(temp1!=NULL){
         printf("%d ",temp1->data);
        temp1=temp1->next;
        }
    printf("\n");

    while(head->prev!=NULL){
        head=head->prev;
    }
}

void revprint(){
    struct node *temp2=head;
    if (temp2==NULL){
        return;
    }
        while(head->prev!=NULL){
        head=head->prev;
         }
    while(temp2->next!=NULL){   //(->next) since temp2 if null 
        temp2=temp2->next;      //then it would have no prev.
    }
    while(temp2->prev!=NULL){
        printf("%d ",temp2->data);
        temp2=temp2->prev;
    }
    printf("\n");
}

void recsprint(){
    if(head==NULL){
        return;
    }
    
    printf("%d ",head->data);
    head=head->next;
    recsprint();
}

void delete(int c){
    struct node *del=head;
    struct node *temp5;
   
    while(del->prev!=NULL){
        del=del->prev;
    }
     if(c==1){
         temp5=del;
         del=del->next;
         del->prev=NULL;
         free(temp5);
         return;
     }
    for(int k=0;k<c-2;k++){
        del=del->next;
    }
    temp5=del->next;
    del->next=temp5->next;
    temp5->next->prev=del;
    free(temp5);
}
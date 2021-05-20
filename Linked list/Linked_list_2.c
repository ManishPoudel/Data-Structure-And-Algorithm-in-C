#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *da;
};


struct node *insert(struct node *head,int b);
void print(struct node *head);

int main (){
    struct node *head;
    head=NULL;
    head=insert(head,3);            // to collect the data 
    head=insert(head,5);            // so that head is changed
    head=insert(head,7);            // everytime.
    head=insert(head,9);
    head=insert(head,1);
    print(head);
    /* or we can do like this 
    insert(&head,2);
    insert(&head,5);
    insert(&head,..);
    and then in insert change to make 
    head a pointer to pointer.
    (i.e. *insert(struct node ** head,int b)*/
}

struct node *insert(struct node *head,int b){       /* to give pointer to 
node as a return form this function so that head is changed or we can do
    void insert(struct node **head,int b){
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=b;
        tem->da=*head;
        *head=temp;
        return head;
    } 
*/
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=b;
    temp->da=head;
    head=temp;
    return head;
}

void print(struct node *head){
/*
this is easy recursion after head is reached to null 
then the if condition is true and so the return is executed 
which returns back to previus blocks and printf() being executed
simeltenously.And node that after null is reached by head 
null is not changed ,head is always null after head reached null
so print(head->da) is not executed cause da is null 
*/
if(head == NULL){
    return ;
}
print(head->da);
printf("%d ",head->data);
}
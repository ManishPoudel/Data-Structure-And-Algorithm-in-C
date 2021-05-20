/* Run this program in command line because
this has module for header to link to.
gcc Binary_search_tree.c Queue_fortree.c -o man
.\man "enter" : this is simple method for effective
debugging you first convert .c to .o and then 
compile .o files. Do:
gcc Binary_search_tree.c -o Binary_search_tree.o -c
gcc Queue_fortree.c -o Queue_fortree.o -c
gcc -o main_program Binary_search_tree.o Queue_fortree.o
press tab key to autoload name.
this program works perfect  */

#include <stdio.h>
#include <stdlib.h>
#include "Queue_fortree.h"

int main(){
    struct node *root;
    root=NULL;
    front=-1 ;
    rear=-1;
    int v;
    root=Insert(root,66);
    root=Insert(root,22);
    root=Insert(root,18);
    root=Insert(root,65);
    root=Insert(root,100);
    root=Insert(root,60);
    root=Insert(root,4);
    root=Insert(root,2);
    root=Insert(root,13);
    root=Insert(root,65);
    printf("Max value is %d rec %d.\n",findmax(root),recfindmax(root));
    printf("Min value is %d rec %d.\n",findmin(root),recfindmin(root));
    printf("Enter the no to be searched :");
    scanf("%d",&v);
    if(Search(root,v)){
        printf("Found.");
    }else {
        printf("Not found.");
    }
    printf("\nHeight is %d.",findheight(root));
    printf("\nLevel Order.\n");
    levelOrder(root);
    printf("\nPreorder.\n");
    preorder(root);
    printf("\nInorder.\n");
    inorder(root);
    printf("\nPost Order.\n");
    postorder(root);
    int a;
    a=isBStree(root);
    if(a==1){
        printf("\nThe tree is BST");
    }
    else{
        printf("The tree is not BST");
    }
    //printf("\nThe tree is BST 0 or 1 >: %d",a);
    
}

struct node *getnode(int c){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=c;
    new->left=new->right=NULL;
    return new;
}

int Search(struct node *d,int s){
    if(d==NULL){
        return 0;
    }
    else if(d->data==s){
        return 1;
    }
    else if(s<=d->data){
        return Search(d->left,s);
    }
    else{
    return Search(d->right,s);
    }
    
}

struct node *Insert(struct node *a,int b){
    if (a==NULL){
        a=getnode(b);
    }
    else if(b<=a->data){
         a->left=Insert(a->left,b);
    }
    else{
        a->right=Insert(a->right,b);
    }
    return a;
}

int findmin(struct node *b){
    if(b==NULL){
        printf("tree is empty");
        return -1;
    }
    while(b->left!=NULL){
        b=b->left;
    }
    return b->data;
}

int findmax(struct node *c){
    if(c==NULL){
        printf("tree is empty");
        return -1;
    }
    while(c->right!=NULL){
        c=c->right;
    }
    return c->data;
}

int recfindmin(struct node *j){
    if(j==NULL){
        printf("tree is empty");
        return -1;
    }
    else if(j->left==NULL){
        return j->data;
    }
    return recfindmin(j->left);
}

int recfindmax(struct node *h){
    if(h==NULL){
        printf("tree is empty");
        return -1;
    }
    else if(h->right==NULL){
        return h->data;
    }
    return recfindmin(h->right);
}

int findheight(struct node *g){
    if(g==NULL){
        return -1;
    }
    return maxv(findheight(g->left),findheight(g->right))+1;

}

int maxv(int a,int b){
    if(b>a){
        return b;
    }else if(a>b)
    {
        return a;
    }
    else if(a==b){
        return a;
    }
}

void levelOrder(struct node *t){
    if(t==NULL){
        printf("empty");
        return;
    }
    enqueue(t);
    while(!isempty()){
        struct node *current=dequeue();
        printf(" %d ",current->data);
        if(current->left!=NULL){
            enqueue(current->left);
        }
        if(current->right!=NULL){
            enqueue(current->right);
        }
    }
}

void preorder(struct node *i){
    if(i==NULL){
        return;
    }
    printf(" %d",i->data);
    preorder(i->left);
    preorder(i->right);
}

void inorder(struct node *l){
    if(l==NULL){
        return;
    }
    inorder(l->left);
    printf(" %d",l->data);
    inorder(l->right);
}

void postorder(struct node *q){
    if(q==NULL){
        return;
    }
    postorder(q->left);
    postorder(q->right);
    printf(" %d",q->data);
}

int issubtreeGreater(struct node *ro,int value){
    if(ro==NULL){
        return 1;
    }
    if(ro->data > value && issubtreeGreater(ro->right,value)
    && issubtreeGreater(ro->left,value)){ 
        return 1;
    }
    else return 0;
}

int issubtreeLesser(struct node *r,int value){
    if(r==NULL){
        return 1;
    }
    if(r->data<=value && issubtreeLesser(r->left,value)
    &&issubtreeLesser(r->right,value)){
        return 1;
    }
    else return 0;
}

int isBStree(struct node *rt){
    if(rt==NULL){
        return 1;
    }
    if(issubtreeLesser(rt->left,rt->data)
    && issubtreeGreater(rt->right,rt->data)
    && isBStree(rt->left)
    && isBStree(rt->right)){
    return 1;
    } else return 0;
}
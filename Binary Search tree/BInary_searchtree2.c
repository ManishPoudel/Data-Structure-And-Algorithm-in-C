#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getnode(int a){
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=a;
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct node *insert(struct node *root,int value){
    if(root==NULL){
        root=getnode(value);
    }else if(value<=root->data){
        root->left=insert(root->left,value);
    }else{
        root->right=insert(root->right,value);
    }
    return root;
}

int isBST(struct node *root,int min,int max){ //more benifitial way.
    if(root==NULL){                             //effective way
    return 1;
    }  
    if(root->data>=min && root->data<=max
    && isBST(root->left,min,root->data)&&
    isBST(root->right,root->data,max)){
    return 1;
    }else
     return 0;
}

int isbstutil(struct node *root){
    return isBST(root,INT_MIN,INT_MAX);//macro for -infinity,+infinity.
}

struct node *findmin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node *Delete(struct node *root,int val){
    if(root==NULL)return root;
    else if(val<root->data){
        root->left=Delete(root->left,val);
    }else if(val>root->data){
        root->right=Delete(root->right,val);
    }else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }else if(root->left==NULL){
            struct node *temp=root;
            root=root->right;
            free(temp);
        }else if(root->right==NULL){
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        else{
            struct node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}

void print(struct node *root){
    if(root==NULL){
        return;
    }
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}

struct node *search(struct node *root,int data){
    if(root==NULL){
        return NULL;
    }else if(root->data==data){
        return root;
    }else if(root->data<data){
        return search(root->right,data);
    }else{
        return search(root->left,data);
    }
}

struct node *getsuccessor(struct node *root,int data){
    struct node *current=search(root,data);
    if(current==NULL){
        return NULL;
    }
    if(current->right!=NULL){
        struct node *temp=current->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    else {
        struct node *successor=NULL;
        struct node *ancestor=root;
        while(ancestor!=current){
            if(current->data<ancestor->data){
            successor=ancestor;
            ancestor=ancestor->left;
            }
            else {
                ancestor=ancestor->right;
            }
            return successor;
        }
        
    }

}

int main(){
    struct node *root;
    root=NULL;
    root=insert(root,66);
    root=insert(root,55);
    root=insert(root,20);
    root=insert(root,29);
    root=insert(root,23);
    root=insert(root,53);
    root=insert(root,11);
    root=insert(root,20);
     
    int a;
    a=isbstutil(root);
    printf("The tree is BST 1,0,>%d",a);
   // root=Delete(root,20);
   // root=Delete(root,66);
    printf("\n");
    print(root);
    struct node *d;
    d=getsuccessor(root,20 );
    printf("\n%d is the the succesor\n",d->data);
    print(root);
}
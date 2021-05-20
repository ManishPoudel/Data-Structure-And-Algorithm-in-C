#ifndef stackylib
#define stackylib


#define maxsize 101

struct node *A[maxsize];

void push(struct node *b);

void pop ();

struct node *gettop();

int empty();

void print();

#endif
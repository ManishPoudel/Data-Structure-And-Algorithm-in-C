#ifndef stackofchar
#define stackofchar
#define maxsize 101
int top=-1;
char A[maxsize];

void push(char b){  top++;  A[top]=b;   }

void pop(){ top--; }

char gettop(){ return A[top];  }

int empty(){ return (top==-1)?1:0; }

#endif
#ifndef stackyfix
#define stackyfix
#define maxsize 111
int a2[maxsize];
int top22=-1;

void push12(int r){ top22++;    a2[top22]=r;   }

void pop12(){ top22--;  }

int gettop12(){   return a2[top22];  }

#endif
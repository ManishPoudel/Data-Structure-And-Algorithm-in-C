#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define maxsize 101

int top=-1;
char A[maxsize];

void pop();
char agettop();
void push(char a);

void reverse(char *c);  //we can pass the size of the string too.

int main (){
    char s[55];
    printf("enter a strings");
    scanf("%s",s);
    reverse(s);
    printf("output=%s",s);

}

void push(char a){
    if(top==maxsize-1){
        printf("stack overflow");
        return;
    }
    A[++top]=a;
}

void pop(){
    top--;
}

char gettop(){
    if(top==-1){
        printf("nothing to show");
        return -1;
    }
    return A[top];
}

void reverse(char *c){
    for(int i=0;i<strlen(c);i++){
        push(c[i]);
    }
    for(int j=0;j<strlen(c);j++){
        c[j]=gettop();
        pop();  //to pop the c[j1]and put c[j2].
    }

}
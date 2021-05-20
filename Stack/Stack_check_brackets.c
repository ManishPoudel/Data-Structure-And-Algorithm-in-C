#include <stdio.h>
#include <string.h>

#define maxsize 101

char A[maxsize];
int top=-1;


int checkbraces(char *str);
void push(char a);
char gettop();
void pop();
int empty();


int main (){
    int a;
    a=checkbraces("(){0manish}");   //you can enter any thing in it .
    if(a==1){
        printf("The Paranthesis are balanced");
    }
    else{
        printf("Paranthesis missing");
    }
    
}

int checkbraces(char *str){
    int a;
    a=strlen(str);
    for(int i=0;i<a;i++){
        char b=gettop();
            switch (str[i]){
            case '(':
            case '{':
            case '[':
            push(str[i]);
            break;
            case ')':
            if(b=='('){
                pop();
            }else{ 
             push(str[i]);
            }
            break;
            case '}':
            if(b=='{'){
                pop();
            }else{ 
             push(str[i]);
            }
            break;
            case ']':
             if(b=='['){
                pop();
            }else{ 
             push(str[i]);
             }
            break;
         }  
     }
     if (empty()){
                return 1;
                }
                return 0;
}

void push(char a){
    top++;
    A[top]=a;
}

void pop(){
    if(top==-1){
        printf("noelement");
    }
    top--;
}

char gettop(){
    
    return(A[top]);
}

int empty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
    
}
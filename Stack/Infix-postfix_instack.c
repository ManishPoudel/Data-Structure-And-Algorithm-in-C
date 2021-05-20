/* The code for infix to postfix
expression conversion.*/
#include <stdio.h>
#include "stack_of_char.h"
#include <string.h>

char *infToPost(char b[]);
int higherPrecedence(char oper1,char oper2);
int isOperator(char d);
int isOperand(char e);

char str[50];  //initialize postfix as empty string.

int main (){
    char b[100];
    printf("Enter expresson-");    // 9 + 9 .
    fgets(b,sizeof(b),stdin);
    char *c=infToPost(b);
    printf("Postfix is:%s",c);
}

char *infToPost(char b[]){
    int j=0;
    for(int i=0;i<strlen(b);i++){
        if(b[i]==' ' || b[i]==','){
            continue;
        }

        else if(isOperator(b[i])){
            str[j]=' ';
            j++;
            while(!empty() && gettop() != '(' && higherPrecedence(gettop(),b[i])){
                str[j]=gettop();
                j++;
                pop();
            }
            push(b[i]);
        }

        else if(isOperand(b[i])){
            str[j]=b[i];
            j++;
        }
        else if(b[i]=='('){
            push(b[i]);
        }
        else if(b[i]==')'){
            while(!empty() && gettop() !='('){
                str[j]=gettop();
                j++;
                pop();
            }
            pop();
        }
    }
    while(!empty()){
        str[j]=gettop();
        j++;
        pop();
    }
    return str;
}

int isOperand(char e){
    if(e>='0' && e<='9'){
    return 1;
    }
    return 0;
}

int isOperator(char d){
    if(d=='+' || d=='-' || d=='*' || d=='/'){
        return 1;
    }
    return 0;
}

int getOperatorWt(char f){
    int wt=-1;
    switch(f){
        case '+':
        case '-':
        wt=1;
        break;
        case '*':
        case '/':
        wt=2;
        break;
    }
    return wt;
}

int higherPrecedence(char oper1,char oper2){
    int op1wt=getOperatorWt(oper1);
    int op2wt=getOperatorWt(oper2);
    return op1wt>=op2wt?1:0;
}
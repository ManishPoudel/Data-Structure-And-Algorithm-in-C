//not working proto type.
#include <stdio.h>
#include <strings.h>
#include "stack_of_char.h"

void inftopost(char *exp);
int isoperator(char d);
int isoperand(char c);
int ishighprecdence(char op1,char op2);

int main (){
    char a[100];
    printf("Enter Expression\n");
    fgets(a,sizeof(a),stdin);
    printf("  %s  ",a);
    inftopost(a);
    printf("your solution is\n %s ",a);
}

void inftopost(char *exp){
    int i,k;
    char h[100];
    printf("strlen is %d",strlen(exp));
    for(i=0,k=-1;i<strlen(exp);i++){
        printf(" ->%c\n",exp[i]);
        if(exp[i]==' '||exp[i]==','|| exp[i]=='\n'){
            continue;
        }
        else if(isoperand(exp[i])){
            h[i]=exp[i];
            k++;
            exp[k]=h[i];
            printf(" I %c I",exp[k]);
        }
        else if(isoperator(exp[i])){
            while(!empty() && ishighprecdence(gettop(),exp[i])){
                k++;
                exp[k]=gettop();
                pop();
            }
            push(exp[i]);
        }
        else if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(!empty() && gettop()!='('){ 
                k++;
                exp[k]=gettop();
                pop();
                //if(empty() && exp[k]!='('){
                   // printf("unbalanced brackets");
            }
            pop();
        }
            
    }
    //while(!empty()){
    //    char r=gettop();
    //    exp+=r;
    //    pop();
    //}
    printf(" u %s u",exp);
}
    
int isoperand(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    return 0;
}

int isoperator(char d){
    if(d=='-' || d=='+'|| d=='*' || d=='/'){
        return 1;
    }
    return 0;
}

int getwt(char g){
    int wt=0;
    switch(g){
        case '-':
        case '+':
        wt=1;
        break;
        case '*':
        case '/':
        wt=2;
        break;
    }
    return wt;
}
int ishighprecdence(char op1,char op2){
    int op1wt=getwt(op1);
    int op2wt=getwt(op2);

    if(op1wt==op2wt){
        return 1;
    }
    return op1wt>op2wt?1:0;
}
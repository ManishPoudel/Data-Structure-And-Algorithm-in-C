#include <stdio.h>
#include <string.h>
#include "stack_forpostfix.h"

int postfix(char *exp);
int isoperator1(char b);
int isnumericdigit1(char c);
int doevaluation(int oper1,char optr,int oper2);

int main(){
    char exp1[119];     //cause with fgets() you need to specify it
    int a;
    printf("Enter the postfix expresssion\n");    
    fgets(exp1,sizeof(exp1),stdin);       //2 3 * 5 4 * + 9 -
    a=postfix(exp1);       //scanf doesnt work after space so use fgets();
    printf("%d\n",a);
    getch();
}

int postfix(char *exp){
    
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]==' ' || exp[i]==','){
            continue;
        }
        else if(isoperator1(exp[i])){
            int op2=gettop12();
            pop12();
            int op1=gettop12();
            pop12();
            int result=doevaluation(op1,exp[i],op2);
            push12(result);
        }

        else if(isnumericdigit1(exp[i])){
            int oper=0;
            while(i<strlen(exp) && isnumericdigit1(exp[i])){
                oper=(oper*10)+(exp[i]-'0');
                i++;
            }  //since i++ is there if no i-- exp[i] will escape one further
            i--;
            push12(oper); 
        }
    }
    return gettop12();    
}

int isnumericdigit1(char c){
    if (c>='0' && c<='9'){
        return 1;
    }
    else {
        return 0;
    }
}

int isoperator1(char b){
    if(b=='+'||b=='-'||b=='*'||b=='/'){
        return 1;
    }
    else {
        return 0;
    }
}

int doevaluation(int oper1,char optr,int oper2){

    if(optr=='+'){
        return oper1+oper2;
    }else if (optr=='-'){
        return oper1-oper2;
    }else if (optr=='*'){
        return oper1*oper2;
    }else if (optr=='/'){
        return oper1/oper2;
    }else {
        printf("not valid");
        return -1;
    }
}
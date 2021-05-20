/* Modular exponential means 
modualr(5,2,7)=(5^2)%7. Here also for b odd we do
modualr(a,b,c)=((a%c)*(a^(n-1)%c))%c. For b even
moduar(a,b,c)=((x^(b/2)%c)*(x^(b/2)%c)) */

#include <stdio.h>

int modular(int a,int b,int c){
    if(b==0){
        return 1;
    }
    else if((b%2)==0){
        int y=modular(a,b/2,c);
        return ((y*y)%c);
    }
    else{
        return (((a%c)*modular(a,b-1,c))%c);
    }
}

int main(){
    int d=modular(5,2,7);
    printf("%d",d);
}
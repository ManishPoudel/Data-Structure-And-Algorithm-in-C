/* Calculate Power: eg 2^2=4.
Note that: for odd power: pow(a,b)=a*(a^b-1)
but for even we do: pow(a,b)=a^(b/2)*a(b/2) */

#include <stdio.h>

int power(int a,int b){
    if(b==0){
        return 1;
    }else if((b%2)==0){
        int y=power(a,b/2);
        return y*y;
    }
    else{
        return a*power(a,b-1);
    }
}

int main(){
    int a=power(2,3);
    printf("%d",power(2,3));
}
/*Iterative method for Binary searching an sorted array*/
#include <stdio.h>

int search(int A[],int b,int n){
    int mid;
    int high=n-1,low=0;
    int result=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(low>high){
            return -1;
        }
        else if(b==A[mid]){
            return mid+1;
        }
        else if(b<A[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int A[]={1,2,3,4,5,33,42,43,45,56,98};
    int b;
    printf("What no to search:");
    scanf("%d",&b);
    printf("Index:%d\nNumber:%d\n",search(A,b,11),b);
}
/*Recursive method of Binary search a sorted array*/
#include <stdio.h>

int binarySearch(int A[],int low,int high,int b){
    if(low>high){
        return -1;
    }
    int mid=low+(high - low)/2;
    if (b==A[mid]){
        return mid+1;
    }
    else if(b<A[mid]){
        return binarySearch(A,low,mid-1,b);
    }
    else return binarySearch(A,mid+1,high,b);
    return -1;  //returns -1 if not found.
}

int main(){
    int A[]={1,2,3,4,44,55,66,87,89,90,100};
    int i;
    printf("Enter the no you want to search:\n");
    scanf("%d",&i);
    printf("Index: %d \nNumber: %d",binarySearch(A,0,10,i),i);
}

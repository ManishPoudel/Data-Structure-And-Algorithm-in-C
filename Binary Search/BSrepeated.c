/* Binary search for last and first occurance
of number in sorted array. And also to find 
how many times the number is repeated. */
#include <stdio.h>

int findCount(int A[],int n,int b){
    int count=0;
    for(int i=0;i<n;i++){
        if(b==A[i]){
            count=count+1;
        }
        else if (b<A[i]){
            break;
        }
    }
    return count;
}
/* or we can also do:
(first occurance-last occurance +1)*/


int binarySearch(int A[],int n,int b){
    int low=0,high=n-1;
    int result=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(b==A[mid]){
            /* 
           result=mid;
            high=mid-1;  //For first Occurance.
            */
            result=mid;
            low=mid+1;  //for last occurance.
        }
        else if(b<A[mid]){
            high =mid-1;
        }
        else low=mid+1;
    }
    return result;
}

int main(){
    int A[]={1,23,45,65,76,91,91,91,91,91,95,96,97,99};
    //      {1 2  3  4  5  6  7  8  9  10 11 12 13 14}
    int i;
    printf("Number you want to search:\n");
    scanf("%d",&i);
    printf("Index: %d \n Number: %d",binarySearch(A,12,i),i);
    printf("\nAnd the number is repeated %d times",findCount(A,14,i));
}
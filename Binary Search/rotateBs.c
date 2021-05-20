/* Count how many times is the circular array rotated,
and also search a circularly sorted array.
 No of rotation = index of minimum element.*/

#include <stdio.h>

int countrotate(int A[],int n){
    int min=A[0];
    int minindex=0;
    for(int i=0;i<n-1;i++){
    if(A[i]<min){
        min=A[i];
        minindex=i;
    }
    }
    return minindex;
}

int rotatecount(int A[],int n){ //Find rotation using recursion.
    int low,high=n-1;
    while(low<=high){
        if(A[low]<=A[high]){
            return low;
        } 
        int mid=(low+high)/2;
        int next=(mid+1)%n,prev=(mid+n-1)%n;
        if(A[mid]<=A[next] && A[mid]<=A[prev]){
            return mid;
        }
        else if(A[mid]<=A[high]){
            high=mid-1;
        }
    }
    return -1;
}

int circulararraySearch(int A[],int n,int x){
    int low=0,high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(x==A[mid]){
            return mid;
        }else if(A[mid]<=A[high]){
            if(x>A[mid] && x<=A[high]){ //'=' necessery
                low =mid+1;
            }
            else high=mid-1;
        }
        else if(A[mid]>=A[low]){
            if(x>=A[low] && x<A[mid]){  //'=' necessery
            high=mid-1;
            }
            else low=mid+1;
        }
    }
    return -1;
}
int main(){
    int A[]={13,14,2,3,4,5,8,11,12};
    //      {0 , 1,2,3,4,5,6, 7, 8}
    int s;
    int b=countrotate(A,8);
    int c=rotatecount(A,8);
    printf("%d and %d \n",b,c);
    printf("Search for:\n");
    scanf("%d",&s);
    int f=circulararraySearch(A,8,s);
    printf("your no index is %d",f);
}
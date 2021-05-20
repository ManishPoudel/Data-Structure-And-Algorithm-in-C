// In-place selection sort in c.
#include <stdio.h>

void selectionSort(int arr[],int n){

    for(int i=0;i<n;i++){
        int imin = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[imin]){
                imin=j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
    }
}

int main(){
    int arr[6]={33,55,77,22,11,88};
    selectionSort(arr,6);
    for(int i = 0; i < 6; i++){
        printf("%d\n",arr[i]);
    }
    getch();
}
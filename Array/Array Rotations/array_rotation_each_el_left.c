#include<stdio.h>

int main(){

    int arr[] = { 1,2,3,4,5,6 };
    int d = 2;
    int i,j,temp;
    for(i = 0; i < d; i++){
        temp = arr[0];
        for(j = 1; j < 6; j++){
            arr[j - 1] = arr[j];
        }
        arr[j - 1] = temp;
    }

    for(i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
}
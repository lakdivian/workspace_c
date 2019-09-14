#include <stdio.h>

// n - number of rows given
void printPattern(int n){
	// Write your code here
    int arr[n][n];
    int top = 0;
    int bottom = n-1;
    int start = 1,i,j;
    int left=0;
    int curr; 
    for(i = 1; i <= n * n; i++){
        if(start % 2 != 0){
            curr = 0;
            arr[top][left] = i;
            left++;
        } else{
            curr = 1;
            arr[bottom][left] = i;
            left++;
        }
        
        if(i%n == 0){
            start++;
            left = 0;
            if(curr == 0){
                top++;
            } else {
                bottom--;
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

}

int main(){

    int n;
    scanf("%d",&n);
    printPattern(n);
}

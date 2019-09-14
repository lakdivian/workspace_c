/*
// Sample code to perform I/O:
#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// Check the array vertical symmetric or not
bool is_vertical_symmetric(int **arr,int N){
        int i,j,k,flag;
        flag = 1,k = N / 2;
        for(i=0;i<k;i++){
            for(j=0;j<N;j++){
                if(arr[i][j] != arr[N-i-1][j]){
                    flag = 0;
                    break;
                }
            }
            
            if(flag==0){
                break;
            }
        }
        
        if(flag==0){
            return false;
        } else {
            return true;
        }
}

// Check the array horizontal symmetric or not
bool is_horizontal_symmetric(int **arr,int N){
        int i,j,k,flag;
        flag = 1,k = N / 2;
        for(i=0;i<k;i++){
            for(j=0;j<N;j++){
                if(arr[j][i] != arr[j][N-i-1]){
                    flag = 0;
                    break;
                }
            }
            
            if(flag==0){
                break;
            }
        }
        
        if(flag==0){
            return false;
        } else {
            return true;
        }
}

int main(){
    
    int T,N,t_case,i,j,flag;
    long k;
    int **arr;
    char num_arr[32],*ch;
    scanf("%d",&T);
    for(t_case=0;t_case<T;t_case++){
        scanf("%d",&N);
        
        // Dynamic array allocation
        arr = (int **)malloc(N * sizeof(int *));
        for(i=0;i<N;i++){
            arr[i] = (int *)malloc(N * sizeof(int));
        }
        // Read elements to Matrix
        for(i=0;i<N;i++){
            scanf("%s",num_arr);
            for(j=0;j<N;j++){
                arr[i][j] = (int)(num_arr[j] - '0');
            }

        }

        // Check the Matrix is symmetric or not

        if(is_horizontal_symmetric(arr,N) && is_vertical_symmetric(arr,N)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
        free(arr);
        
    }
}

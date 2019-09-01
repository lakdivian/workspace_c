#include <stdio.h>
#include <stdbool.h>
#include<string.h>
int N,M;

void markLands(int mat[][M],bool vert[][M],int from_row,int from_col){
    
    if(from_row >= 0 && from_row < N && from_col >= 0 && from_col < M && mat[from_row][from_col] && !vert[from_row][from_col]){
    	 vert[from_row][from_col] = true;   
//          call neighbours
        markLands(mat,vert,from_row,from_col - 1);
        markLands(mat,vert,from_row + 1,from_col);
        markLands(mat,vert,from_row, from_col + 1);
        markLands(mat,vert,from_row - 1, from_col);
        return; 
    }
    return;
    
}

int findNumberOfIslands(int mat[][M],bool vert[][M]){
    int i,j,count=0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(mat[i][j] && !vert[i][j]){
                count++;
                markLands(mat,vert,i,j);
            }
        }
    }
    return count;
}

int main(){
	//Write your code here
    scanf("%d %d",&N,&M);
    int mat[N][M];
    bool vert[N][M];
    memset(vert,0,sizeof(vert));
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    int islands = findNumberOfIslands(mat,vert);
    printf("%d\n",islands);
    return 0;
}
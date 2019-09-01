#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdint.h>

int M,N;

struct Cell {
    int row;
    int col;
    int dist;
};

struct Queue {
    struct Cell cell;
    struct Queue *next;
};

struct Queue *front;
struct Queue *tail;

void enque(struct Cell cell){
    struct Queue *dummy;
    struct Queue *temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp -> cell = cell;
    temp -> next = NULL;
    if(front == NULL){
        front = temp;
        tail = front;
    } else {
        temp -> next = front;
        front = temp;
    }
}

struct Cell deque(){
    struct Queue *dummy;
    struct Cell ret_cell = front -> cell;
    dummy = front;
    front = front -> next;
    free(dummy);
    return ret_cell;
}

bool isValid(int row, int col, int Mat[][4]){
    if(row >= 0 && row < 4 && col >= 0 && col < 4 && Mat[row][col])
        return true;
    return false;
}

int shortest_distance(struct Cell start,struct Cell end, int Mat[][4],bool Vert[][4]){

       enque(start);
       Vert[start.row][start.col] = true;
       struct Cell new;

       while(front != NULL){
           struct Cell temp = deque();

           if(temp.row == end.row && temp.col == end.col){
               Vert[temp.row][temp.col] = true;
               return temp.dist;
           }

           if(isValid(temp.row - 1, temp.col, Mat) && !Vert[temp.row - 1][temp.col]){
               new.row = temp.row - 1;
               new.col = temp.col;
               new.dist = temp.dist + 1;
               enque(new);
               Vert[new.row][new.col] = true;
           }
           if(isValid(temp.row, temp.col + 1, Mat) && !Vert[temp.row][temp.col + 1]){
               new.row = temp.row;
               new.col = temp.col + 1;
               new.dist = temp.dist + 1;
               enque(new);
               Vert[new.row][new.col] = true;
           }
           if(isValid(temp.row + 1, temp.col, Mat) && !Vert[temp.row + 1][temp.col]){
               new.row = temp.row + 1;
               new.col = temp.col;
               new.dist = temp.dist + 1;
               enque(new);
               Vert[new.row][new.col] = true;
           }  
           if(isValid(temp.row, temp.col - 1, Mat) && !Vert[temp.row][temp.col - 1]){
               new.row = temp.row;
               new.col = temp.col - 1;
               new.dist = temp.dist + 1;
               enque(new);
               Vert[new.row][new.col] = true;
           }                    
       }

       return INT16_MAX;
}

int main(){

    scanf("%d%d", &N,&M);
    int i,j;
    int Mat[N][M];
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&Mat[i][j]);
        }
    } 

    bool Vert[4][4];
    memset(Vert,false,sizeof(Vert));

    front = NULL;
    tail = front;

    struct Cell start;
    struct Cell end;

    scanf("%d%d%d%d", &start.row, &start.col, &end.row, &end.col);
    start.dist = 0, end.dist = 0;

    int dist = shortest_distance(start,end,Mat,Vert);
    
    if(dist == INT16_MAX || !Vert[end.row][end.col]){
        printf("-1\n");
        return 0;
    }

    printf("%d\n", dist);
    return 0;
}


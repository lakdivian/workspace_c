/*It's sweet distribution day in Micro's school. He's very happy. All the students in Micro's 
class are sitting on chairs which are arranged in a matrix of size NxM i.e. there are N rows of 
chairs numbered from 1 to N and in each row there are M chairs numbered from 1 to M. Micro is sitting at 
coordinate (X,Y) ( Yth chair of Xth row). Teacher gives the box to a student sitting in one of the 
four corners: (1,1),(1,M),(N,1) or (N,M). Students have to take one sweet from the box and 
pass the box to the next student (student sitting to left, right, front or back). 
For a student sitting at coordinate (x,y) , he'll follow the following priority order:

* If there is a student in the Right who has not received sweet, then pass it right (x,y+1).
* If there is a student in the Left who has not received sweet, then pass it left (x,y-1).
* If there is a student in the Front who has not received sweet, then pass it front (x-1,y).
* If there is a student in the Back who has not received sweet, then pass it back (x+1,y).
* Shout Over, meaning that all students have received sweets.

Now, Micro is curious to find out the direction in which he'll have to pass the sweet box. 
Since there are a lot of students in Micro's class, it will take long for the box to reach 
him, and you know Micro, he just can't wait. So he asks you to find out the direction in 
which he'll have to pass the box, or will he have to shout Over.

Input:
 * First line consists of a single integer, T, denoting the number of test cases. Each test 
   case consists of three lines.
* First line of each test consists of two space separated integer denoting N and M.
* Second line of each test case consists of two space separated integers  and , 
  denoting the coordinate of the corner from which sweet distribution starts.
* Third line of each test case consists of two space separated integers denoting  
  and , coordinates of Micro.
  
  URL:- https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/micro-and-sweet-distribution/
  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Location {
  int row,col;
};

int main(){
    int T,t_case,i,j,N,M,k;
    struct Location start,micro;
    scanf("%d",&T);
    for(t_case=0;t_case<T;t_case++){
        scanf("%d%d",&N,&M);
        scanf("%d%d",&start.row,&start.col);
        scanf("%d%d",&micro.row,&micro.col);

        // Making the locations similar to the array indexes
        start.row--,start.col--,micro.row--,micro.col--;

        // if starting point is (0,0)
        if(start.row == 0 && start.col == 0){
            k = micro.row - start.row < 0 ? start.row - micro.row : micro.row - start.row;
            if(k % 2 == 0){
                if(micro.col == M-1){
                    if(micro.row == N-1){
                        printf("Over\n");
                    } else{
                        printf("Back\n");
                    }
                } else {
                    printf("Right\n");
                }
            } else {
                if(micro.col == 0){
                    if(micro.row == N-1){
                        printf("Over\n");
                    } else{
                        printf("Back\n");
                    }
                } else {
                    printf("Left\n");
                }
            }
        }

        // if starting point is (0,M-1)
        else if(start.row == 0 && start.col == M - 1){
            k = micro.row - start.row < 0 ? start.row - micro.row : micro.row - start.row;
            if(k % 2 == 0){
                if(micro.col == 0){
                    if(micro.row == N - 1){
                        printf("Over\n");
                    } else {
                        printf("Back\n");
                    }
                } else {
                    printf("Left\n");
                }
            } else {
                    if(micro.col == M-1){
                        if(micro.row == N - 1){
                            printf("Over\n");
                        } else {
                            printf("Back\n");
                        }
                    } else {
                        printf("Right\n");
                    }
                }   
        }

        // if starting point is (N-1,0)
        else if(start.row == N - 1 && start.col == 0){
            k = micro.row - start.row < 0 ? start.row - micro.row : micro.row - start.row;
            if(k % 2 == 0){
                if(micro.col == M - 1){
                    if(micro.row == 0){
                        printf("Over\n");
                    } else {
                        printf("Front\n");
                    }
                } else {
                    printf("Right\n");
                }
              } else {
                  if(micro.col == 0){
                    if(micro.row == 0){
                        printf("Over\n");
                    } else {
                        printf("Front\n");
                    }
                } else {
                    printf("Left\n");
                }
              }
        }

        // if starting point is (N-1,0)
        else if(start.row == N - 1 && start.col == M - 1){
            k = micro.row - start.row < 0 ? start.row - micro.row : micro.row - start.row;
            if(k % 2 == 0){
                if(micro.col == 0){
                    if(micro.row == 0){
                        printf("Over\n");
                    } else {
                        printf("Front\n");
                    }
                } else {
                    printf("Left\n");
                }
              } else {
                  if(micro.col == M - 1){
                    if(micro.row == 0){
                        printf("Over\n");
                    } else {
                        printf("Front\n");
                    }
                } else {
                    printf("Right\n");
                }
              }
        }
     

      }
 }
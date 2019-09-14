#include<stdio.h>
#include<stdlib.h>


int main(){

    int row,col,i,j;
    int **B;
    scanf("%d%d",&row,&col);
    int A[row][col];
    int *C[row];
    printf("Enter elements for A array\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("Printing elements for array A\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("=====================A array ends here========================\n");

    printf("For B array\n");
    B = (int **)malloc(row * sizeof(int *));
    for(i=0;i<row;i++){
        B[i] = (int *)malloc(col * sizeof(int));
    }

    printf("Enter elements for B array\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&B[i][j]);
        }
    }
    printf("Printing elements for array B\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

    printf("=====================B array ends here========================\n");

    printf("For C array\n");
    // B = (int **)malloc(row * sizeof(int *));
    for(i=0;i<row;i++){
        C[i] = (int *)malloc(col * sizeof(int));
    }

    printf("Enter elements for C array\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&C[i][j]);
        }
    }
    printf("Printing elements for array C\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    printf("=====================C array ends here========================\n");


}
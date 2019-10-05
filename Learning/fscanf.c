#include<stdio.h>
#include<stdlib.h>


int main(){
    char buff[100];
    int a, b;
    char c;
    fscanf(stdin,"%d %d %c", &a,&b,&c);
    printf("%d %d %c\n", a,b,c);
}

#include<stdio.h>


int main(){

    struct student
    {
        int rollNo;
        int mark;
    };

    struct student s[5];
    int i,j;

    for(i = 0; i < 5; i++){
        printf("Enter rollNo of student: ");
        scanf("%d",&s[i].rollNo);
        printf("Enter the mark of this student: ");
        scanf("%d",&s[i].mark);
    }

    printf("The student data that you have entered is\n");

    printf("Roll No         Marks\n");
    for(j = 0; j < 5; j++){
        printf("%2d%18d\n", s[j].rollNo,s[j].mark);
    }
    
}
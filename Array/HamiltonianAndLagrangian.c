/*
Question:- Students have become secret admirers of SEGP. They find the course exciting and the professors amusing. 
After a superb Mid Semester examination its now time for the results. The TAs have released the marks of students 
in the form of an array, where arr[i] represents the marks of the ith student.Since you are a curious kid, 
you want to find all the marks that are not smaller than those on its right side in the array.
*/

// Write your code here
#include <stdio.h>

int N;
int top = -1;


void push(int el, int stack[N]){
    top++;
    stack[top] = el;
}

int pop(int stack[N]){
    int k = stack[top];
    top--;
    return k;
}

int main(){
	int i,j,flag,max;
	scanf("%d", &N);   
	int arr[N],stack[N];
	for(i=0;i<N;i++)
	    scanf("%d",&arr[i]);
	    
	push(arr[N-1],stack);
	max = arr[N-1];
	for(i=N-2;i>=0;i--){
	    if(arr[i] >= max){
	        max = arr[i];
	        push(max,stack);
	    }
	}
	
	while(top>=0){
	    printf("%d ", pop(stack));
	}
}

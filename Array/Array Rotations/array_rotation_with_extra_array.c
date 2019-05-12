//  Second approach of array rotation
//  n => array size, d => number of rotations
//  Time complexity:- O(n), Space complexity:- O(d)
/*
  Method Explanation:-
        loop through the array till index 'd' and stores the elements in an array called add_array
        then loop from dth (index) element to the last element and move each element 'd' cell 
        towards left, after this loop we will store the elements in add_array at the end of the array.
        Then the final array will be printed out.
*/

// Importing the library
#include<stdio.h>
#include<stdlib.h>

//  Main function
int main(){

    // Initializing the array
    int arr[] = {1,2,3,4,5,6,7,8,9};

    // Initializing the variables
    int d = 2,n = 9,i,j = 0;

    // Initializing the additional array and allocating memory using malloc
    int* add_array = (int *) malloc(d * sizeof(int));

    // Looping through the array for storing the d elements to the additional array
    for(i = 0; i < 2; i++){
        add_array[i] = arr[i];
    }

    // Looping through the array and moving each element 'd' cells towards left
    for(i = d; i < n; i++){
        arr[i - d] = arr[i];
    }

    // Looping through the array and inserting 'd' elements to the end of the array
    for(i = n - d; i < n; i++){
       arr[i] = add_array[j];
       j++;
    }
    
    // printing the final array 
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

}
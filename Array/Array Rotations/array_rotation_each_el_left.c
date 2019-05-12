//  First approach of array rotation
//  n => array size, d => number of rotations
//  Time complexity:- O(n * d), Space complexity:- O(1)
/*
  Method Explanation:-
           loop through the array 'd' times and each time will store the 0th element in a variable (temp) 
           then loop from 1st (index 1) element to the last element and move each element one cell 
           towards left, after this loop we will store the 0th element ( element in temp variable ) at the end 
           of the array. Then the final array will be printed out.
*/

// Importing the library
#include<stdio.h>

//  Main function
int main(){

    // Initailizing the array
    int arr[] = { 1,2,3,4,5,6 };

    // Initializing integer variables
    int d = 2,n = 6,i,j,temp;

    // Looping through the array for 'd' times
    for(i = 0; i < d; i++){

        // Storing the 0th element in temp variable
        temp = arr[0];

        // Looping from 1st element till the end and moving eacn element towards the left
        for(j = 1; j < n; j++){
            arr[j - 1] = arr[j];
        }

        //  storing the value of temp at the end of the array
        arr[j - 1] = temp;
    }

    // printing the final array 
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}
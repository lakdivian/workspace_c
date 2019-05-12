// Algorithm for finding the gcd of two numbers
// gcd(a,b) = b = a * q + r , move 'a' to 'b' and 'r' to "a" repeat the process until yo get the 'r' as 0


// Importing libraries
#include<stdio.h>

// functionfor finding the gcd
int gcd(int a,int b){

    // checking whether b is 0, if b is 0 the gcd is a
    if(b == 0){
        return a;
    }

    // finding the remainder by dividing the bigger number with smaller, and giving the bigger number to a and smaller to a
    // after finding the remainder
    else{
        return gcd(b,a % b);
    }
    
}


// Main function
int main(){

    int a = 45,b = 10;

    printf("gcd of %d and %d is %d\n", a , b , gcd(a,b));
}
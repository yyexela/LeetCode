#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// An integer divisible by the sum of its digits is said to be a Harshad number. You are given an integer x. Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.

int sum_of_digits(int x){
    int sum = 0;
    while(x != 0){
        int digit = x % 10;
        int remainder = x / 10;
        sum += digit;
        x = remainder;
    }
    return sum;
}

int main(){
    int x = 18;
    
    // First, find sum of the digits
    int sum = sum_of_digits(x);
    // See if it's divisible
    int ret = ((x % sum) == 0) ? sum : -1;

    printf("Returning %d\n", ret);

    return ret;
}
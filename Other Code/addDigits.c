#include <stdio.h>
/*
Assignment 1
Author: Nick Keirstead

This program prompts user for an integer and
prints the sum of the integer's digits.
*/



int main (void) {
    int x;
    int oldx;
    int sum = 0;
    printf("Enter an integer:  ");
    scanf("%d",&x);
    oldx = x;
    while (x != 0) {
        sum += x % 10;
        x /= 10; //integer division, so decimal chopped away
    }
    printf("\nThe sum of the digits in %d = %d\n", oldx, sum);
    return 0;
}



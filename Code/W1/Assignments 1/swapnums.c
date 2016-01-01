#include <stdio.h>
/*
Assignment 2
Author: Nick Keirstead

This program prompts user for two ints,
stores the ints in two variables,
swaps the values of the variables (with
no temporary variables), and prints the
swapped values of the variables.
*/

int main (void) {
    int x,y;
    printf("Enter First Integer:  ");
    scanf("%d", &x);
    printf("\nEnter Second Integer:  ");
    scanf("%d", &y);
    x = x+y;
    y = x-y;
    x = x-y;
    printf("\nAfter swapping: Num 1 = %d, Num 2 = %d\n",x,y);
    return 0;
}

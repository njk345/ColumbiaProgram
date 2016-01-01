#include <stdio.h>

/*
Problem 1
Author: Nick Keirstead

This program prompts user for two integers
and prints <<yes>> if one divides the other evenly,
and <<no>> if not.
*/

int main (void) {
    int x,y;
    printf("Enter Two Integers:  ");
    scanf("%d %d", &x, &y);
    if ((x == 0 || y == 0) || (x % y != 0 && y % x != 0)) printf("<<no>>\n");    
    else printf("<<yes>>\n");
    return 0;
}

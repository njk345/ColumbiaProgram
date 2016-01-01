#include <stdio.h>
#include <math.h>
/*
Assignment 4
Author: Nick Keirstead

This program prompts user for an integer,
and calculates and stores all prime numbers
up to and including the number in an array,
the contents of which are printed. It then prints
whether the inputted integer itself is prime.

The "Sieve of Eratosthenes" method of finding primes
is used. The program begins with an array of zeroes
and finds elements that equal 0 (numbers that have not yet been
marked as composite),adds them to a primes array,
and marks all its multiples as composite by 
changing their value to 1. After looping through the array, the
array index of all the remaining 0 elements are added to the
primes array.

Note:
    When Program is compiled, add -lm flag to link
    math.h library
*/

int main (void) {
    int max;
    printf("\nPrimes Up to What Number?  ");
    scanf("%d",&max);
    
    int allnums[max];
    int i;
    //fill nums array with "unmarked" nums
    for (i = 2; i <= max; i++) {
        allnums[i] = 0; 
    }

    int x;
    int primes[max]; //to be filled
    int p = 0; //counter variable for current index in primes array
    int j; //counter for inner loop searching for multiples

    for (x = 2; x < (int)sqrt(max); x++) {
        if (allnums[x] == 0) {
            primes[p] = x; //add to primes array
           // printf("%d\n",x);
            p++;
            for (j = x * 2; j <= max; j += x) {
                allnums[j] = 1; //mark multiples as composite
                //printf("%d\n",j);
            }
        }
    }
    
    //add all remaining unmarked nums to primes array
    for (x = (int) sqrt(max); x <= max; x++) {
        if (allnums[x] == 0) {
            primes[p] = x;
            p++;
        }
    }

    int a;
    for (a = 0; a < p; a++) {
        printf("%d\n",primes[a]);
    }

    if (primes[p-1] == max) {
        printf("%d is prime.\n\n", max);
    }
    else {
        printf("%d is not prime.\n\n", max);
    }
    return 0;
}

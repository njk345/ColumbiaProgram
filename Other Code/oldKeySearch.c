#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Assignment 6: Version 1
Author: Nick Keirstead

This program prompts user for the size of an array,
and fills it with random ints < size of array.
Then prompts user for integer to find in the array,
and prints whether it successfully found it and, if so,
it prints its index in the array.

Searches for the key by checking each random int as they
are placed in the array. Worst case, however, requires each
element to be checked.
*/


int main(int argc, char *argv[]) {
	srand(time(NULL));
	int n,key;
	printf("Enter Size for Random Integer Array:  ");
	scanf("%d",&n);
	printf("\nEnter Number to Find:  ");
	scanf("%d",&key);
	
	int nums[n];
	int i;
	for (i = 0; i < n; i++) {
		nums[i] = rand() % n;
		if (nums[i] == key) {
			printf("\nSuccess: Index = %d\n", i);
			return 0; //stops program here
		}
	}
	
	printf("\nFailure: Could Not Find %d in Array\n", key);
	return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
Assignment 3
Author: Nick Keirstead

Program prompts for a string and its length,
and an analysis of the string is performed,
printing back each unique character in the string (in
the order the characters appear) and the number of times
each character is present in the string. Only characters
in the range A-Z and a-z are counted.

A two-dimensional array is used to store ASCII values of unique
chars and the number of times the character occurs.
*/

bool arrHasChar(int d1, int x[d1][2], char c);
int firstIndexOf(int d1, int x[d1][2], char c);

int main(void) {
	int n;
	printf("\nEnter Length of String:  ");
	scanf("%d",&n);
	char s[n+1];
	
	printf("\nEnter String For Analysis:  ");
	scanf("%s",s);
	
	//fill counts array with zeroes
	int counts[n][2];
	int a;
	for (a = 0; a < n; a++) {
		counts[a][0] = 0;
		counts[a][1] = 0;
	}
	
	int i;
	int x = 0; //count var for position in counts array while filling it
	for (i = 0; i < n; i++) {
		if (isalpha((int) s[i])) {
			//if char not in counts array, add it and increment occurrence count
			if (!arrHasChar(n,counts,s[i])) {
				counts[x][0] = (int) s[i];
				counts[x][1] += 1;
				x++;
			}
			//char is in counts array, so find its index and increment its occurrence count
			else {
				counts[firstIndexOf(n,counts,s[i])][1] += 1;
			}
		}
	}
	
	int b;
	for (b = 0; b < x; b++) {
		printf("%c=%d\n", counts[b][0], counts[b][1]);
	}
    printf("\n"); //extra new line for aesthetic pleasure:)
    return 0;
}

bool arrHasChar (int d1, int x[d1][2], char c) {
	int i;
	for (i = 0; i < d1; i++) {
		if (x[i][0] == (int) c ) {
			return true;
		}
	}
	return false;
}

int firstIndexOf (int d1, int x[d1][2], char c) {
	int i;
	for (i = 0; i < d1; i++) {
		if (x[i][0] == (int) c) {
			return i;
		}
	}
	return -1; //if c not found in array x
}

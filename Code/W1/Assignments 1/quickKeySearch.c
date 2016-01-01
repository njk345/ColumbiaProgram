#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Assignment 6: Second Version (w/ bonus)
Author: Nick Keirstead

This program does the same as version one,
searching for key in a randomly generated array,
yet it does so by sorting the array in ascending 
numerical order (using quicksort) and using a binary
search to try to locate the key.

A binary search on a sorted array makes it such that
not every element must be checked when searching for 
a key.
*/


void sortarray(int arr[], int len);
void quickSort(int a[], int l, int r);
int partition(int a[], int l, int r);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int n,key;
	printf("Enter Max Value of Array's Integers:  ");
	scanf("%d",&n);
	printf("\nEnter Number to Find:  ");
	scanf("%d",&key);
	
	int nums[n];
	int i;
	for (i = 0; i < n; i++) {
		nums[i] = rand() % n;
	}
	
	quickSort(nums,0,n-1);
	
	int start = 0;
	int end = n-1;
	int middle = (start + end)/2;
	
	while (start <= end) {
		if (nums[middle] < key) {
			start = middle+1;
		}
		else if (nums[middle] == key) {
			printf("\nSuccess: %d Found At Index %d.\n", key, middle+1);
			break;
		}
		else {
			end = middle - 1;
		}
		middle = (start + end)/2;
	}
	
	if (start > end) {
		printf("\nFailure: Could Not Find %d in Array.\n", key);
	}
	
	return 0;
}

void quickSort( int a[], int l, int r) {
   int j;

   if( l < r ) {
       j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }	
}



int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while(1) {
		do ++i; while( a[i] <= pivot && i <= r );
   		do --j; while( a[j] > pivot );
   		if( i >= j ) break;
   		t = a[i];
 		a[i] = a[j]; 
		a[j] = t;
   }
   t = a[l];
   a[l] = a[j]; 
   a[j] = t;
   return j;
}

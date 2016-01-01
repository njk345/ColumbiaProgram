#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Assignment - Sorting
Author: Nick Keirstead

This program fills an array length 100 of random ints
and sorts the array using the bubblesort() function, which
implements the bubble sort method on a given array of a given length.
*/

void bubblesort(int arr[], int len);

int main (void) {   
    srand(time(NULL));
    int i;
    int nums[100];
    printf("Unsorted Array:\n");
    for (i = 0; i < 100; i++) {
        nums[i] = (rand() % 100) + 1;
        printf("%d : %d\n", i+1, nums[i]);
    }

    printf("\nSorted Array:\n");
    bubblesort(nums,100);
    for (i = 0; i < 100; i++) {
        printf("%d : %d\n", i+1, nums[i]);
    }
    return 0;
}

void bubblesort (int arr[], int len) {
    int i,j,temp;
    for (i = 1; i < len; i++) {
        for (j = 0; j < len-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

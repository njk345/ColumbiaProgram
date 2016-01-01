#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Project 1
Author: Nick Keirstead

This program randomly generates an array of 99 unsigned ints
and performs mean, median, and mode on the array and creates
a formatted, printed report for the user.

Mean and median return floats, and the function analyze() handles
printing these values. Mode, however, returns void and handles 
formatted printing on its own, in order to account for cases
in which multiple modes (nums w/ same frequency) are present.

A separate sort() function is used to take an array and sort its
elements in ascending numerical order using bubble sort. sort() is
made use of in median().
*/


void analyze(unsigned int arr[], int len, int func);
float mean(unsigned int arr[], int len);
float median(unsigned int arr[], int len);
void mode(unsigned int arr[], int len);
void sort(unsigned int arr[], int len);
char sep1[] = "/*****************";
char sep2[] = "*****************/";

//void return b/c mode requires more than simply returning a value
//especially if more than one mode is present

int main (void) {
    srand(time(NULL));
    unsigned int responses[99];
    int i,j;
    for (i = 0; i < 99; i++) {
        responses[i] = (unsigned)((rand() % 9) + 1);
    }
    printf("\nData Analysis: Customer Satisfaction Survey\n\n");
    for (j = 1; j <= 3; j++) {
        analyze(responses, 99, j);
    }
    
    return 0;
}

void analyze (unsigned int arr[], int len, int func) {
    printf("%s\n",sep1);
    if (func == 1) {
        printf("Mean = %.1f\n",mean(arr,len));
    }
    else if (func == 2) {
        printf("Median = %.1f\n",median(arr,len));
    }
    else if (func == 3) {
        mode(arr,len);
    }
    else {
        return; //do nothing if bad func input
    }
    if (func != 3) printf("%s\n", sep2);
    printf("\n"); //extra new line to separate analysis sections
}

float mean (unsigned int arr[], int len) {
    int i, sum = 0;
    for (i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum / (float)len;
}

float median (unsigned int arr[], int len) {
    sort(arr,len);
    if (len % 2 == 0) { //if even-sized, average middle two elements
        return (arr[len/2] + arr[len/2 - 1]) / 2.0;
    }
    return arr[len/2]; //if odd-sized, simply return middle element
}

void mode (unsigned int arr[], int len) {
    int frequencies[10];
    int modes[10]; 
    int i,j,k,w,x,y,z;//all loop variables
    for (i = 0; i < 10; i++) {
        frequencies[i] = 0; //fill frequencies w/ 0's
    }
    for (j = 0; j < len; j++) {
        frequencies[arr[j]] += 1;
    }
    int max = frequencies[1];
    int maxIndex = 1;
    /* max stores largest integer in the frequency array
       maxIndex stores index of max in the frequencies array
    */

    //walk through array and find biggest frequency int,
    //and where in the array this biggest int occurs
    for (k = 2; k < 10; k++) {
        if (frequencies[k] > max ) {
            max = frequencies[k];
            maxIndex = k;
        }
    }
    modes[0] = maxIndex;
    int c = 1; //counter for position in modes array
    /* Loop again through frequencies array, and check if 
    any elements equal the max element found first time. If one is found,
    its index is added to the modes array. This is in order to check whether
    there are multiple numbers (indexes in the frequencies array) that 
    appear with the same frequency in the inputted array --> allows
    multiple modes to be found, if there are in fact multiple modes.
    */
    for (x = 1; x < 10; x++) {
        if (frequencies[x] == max && x != maxIndex) {
            modes[c] = x;
            c++;
        }
    }
    printf("Mode");
    (c > 1)? printf("s = ") : printf(" = "); //singular if one mode, plural if > 1
    for (y = 0; y < c; y++) {
        if (y>0) printf(" and");
        printf(" %d", modes[y]);
    }
    printf("\n%s\n", sep2);
   
   printf("Response       Frequency       Histogram\n");
   for (z = 1; z < 10; z++) {
        printf("   %d              %d            ", z, frequencies[z]);
        if (frequencies[z] < 10) printf(" "); //single dig. needs extra space to line up columns
        for (w = 0; w < frequencies[z]; w++) {
            printf("*");
        }
        printf("\n");
   }
}

void sort (unsigned int arr[], int len) {
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

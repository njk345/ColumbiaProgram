#include <stdio.h>
#include <stdlib.h>

/*
Problem 4
Author: Nick Keirstead

This program takes in an int from 0-99 (inclusive)
and prints the english representation of the number.
*/



int main()
{
    char *units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                   "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                   "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                  "eighty", "ninety"};



        int n;
        printf("Enter Integer (0-99):  ");
        scanf("%d",&n);

        int onesDigit = n % 10;
        int tensDigit = n / 10;
    
        printf("%d ==> ", n);
    
        if (n < 20) {
            printf("%s\n", units[n]);
        }
        else {
            printf("%s", tens[tensDigit]);
            if (onesDigit > 0) {
                printf("-%s", units[onesDigit]);
            }
            printf("\n");
        }
        return 0;
}

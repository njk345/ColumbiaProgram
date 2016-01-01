#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *units[] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                   "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                   "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
                  "eighty", "ninety"};

    for (int n = 0; n < 100; n++) {
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
    }
}

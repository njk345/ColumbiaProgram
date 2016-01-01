#include <stdio.h>

int main (void) {
    int i;
    int sum;
    for (i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("Sum of numbers from 1 to 100 = %d\n",sum);
    return 0;
}

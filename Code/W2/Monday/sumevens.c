#include <stdio.h>

int main (void) {
    int sum = 0;
    int i;
    for (i = 2; i <= 100; i+=2) {
        sum += i;
    }
    printf("Sum of even ints from 2 to 100 = %d\n",sum);
    return 0;
}

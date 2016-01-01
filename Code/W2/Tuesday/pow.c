#include <stdio.h>

int power(int x, int y);

int main (void) {
    int x,y;
    printf("Enter base and exponent:  ");
    scanf("%d %d",&x, &y);
    printf("\n%d ^ %d = %d\n", x, y, power(x,y));
    return 0;
}

int power (int x, int y) {
    int rv,i;
    rv = 1;
    for (i = 0; i < y; i++) {
        rv *= x;
    }
    return rv;
}

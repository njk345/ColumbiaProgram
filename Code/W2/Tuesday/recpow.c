#include <stdio.h>

int power(int x, int y);

int main (void) {
    int b,p;
    printf("Enter Base and Exponent:  ");
    scanf("%d %d",&b, &p);
    printf("\n%d ^ %d = %d\n", b, p, power(b,p));
    return 0;
}

int power (int x, int y) {
    if (y == 0) return 1;
    return x*power(x,y-1);
}

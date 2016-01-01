#include <stdio.h>

int max(int a, int b, int c);

int main (void) {
    int a,b,c;
    printf("\nEnter Three Integers:  ");
    scanf("%d %d %d",&a, &b, &c);
    printf("\nMax is %d\n",max(a,b,c));
    return 0;
}

int max (int a, int b, int c) {
    int rv = a;
    if (b > a && b > c) {
        rv = b;
    }
    else if (c > a && c > b) {
        rv = c;
    }
    return rv;
}

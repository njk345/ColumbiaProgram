#include <stdio.h>
#include <stdlib.h>

int main () {
    float x,y;
    printf("Enter Two Nums To Add:  ");
    scanf("%f %f", &x, &y);

    float *ptrx = &x;
    float *ptry = &y;
    float sum = *ptrx + *ptry;

    printf("Sum = %.2f\n", sum);
    return 0;
}

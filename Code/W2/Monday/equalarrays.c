#include <stdio.h>
#include <stdbool.h>

bool arraysEqual (int x[],int xlen, int y[],int ylen);

int main (void) {
   
    int a1[4];
    int a2[4];
    int a3[4];

    printf("Enter 4 Integers in Array 1:  ");
    scanf("%d %d %d %d",&a1[0], &a1[1], &a1[2], &a1[3]);
    printf("\nEnter 4 Integers in Array 2:  ");
    scanf("%d %d %d %d",&a2[0], &a2[1], &a2[2], &a2[3]);
    printf("\nEnter 4 Integers in Array 3:  ");
    scanf("%d %d %d %d",&a3[0], &a3[1], &a3[2], &a3[3]);

    if (arraysEqual(a1,4,a2,4) && arraysEqual(a2,4,a3,4)) {
        printf("\nAll three arrays are equal.\n");
    }
    else {
        printf("\nAll three arrays are not equal.\n");
    }
    return 0;
}

bool arraysEqual (int x[],int xlen,int y[],int ylen) {
    if (xlen != ylen) return false;

    int i;
    for (i = 0; i < xlen; i++) {
        if (x[i] != y[i])   return false;
    }
    return true;
}

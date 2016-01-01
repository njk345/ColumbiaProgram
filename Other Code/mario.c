#include <stdio.h>

int main () {
    int h;
    printf("Enter pyramid height (> 0):  ");
    scanf("%d", &h);
    while (h <= 0) {
        printf("Retry:  ");
        scanf("%d", &h);
    }

    for (int i = 1; i <= h; i++) {
        for (int x = 0; x < h-i; x++) {
            printf(" ");
        }
        printf("##");
        for (int y = 1; y < i; y++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

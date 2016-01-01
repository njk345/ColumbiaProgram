#include <stdio.h>

//computes and prints all fibonacci numbers that have vaules ranging from a to b


int main () {
	int a,b;
	printf("\nEnter two numbers:  ");
	scanf("%d %d", &a, &b);

    int fold = 0, fnew = 1;

    while (1) {
        if (fnew >= a && fnew <= b) {
            printf("%d\n", fnew);
        }
        int tmp = fold;
        fold = fnew;
        fnew = tmp + fold;
        if (fnew > b) break;
    }
    return 0;
}

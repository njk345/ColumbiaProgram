#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getGrade();

int main (void) {
    srand(time(NULL));
    int grades[10];
    int i;
    for (i = 0; i < 10; i++) {
        grades[i] = getGrade();
    }
    int j;
    int numpassed = 0;
    for (j = 0; j < 10; j++) {
        if (grades[j] == 1) numpassed++;
    }

    printf ("%d students passed.\n",numpassed);
    if (numpassed > 8) printf("Raise Tuition.\n");
    return 0;
}

int getGrade () {
    return (rand() % 2) + 1;
}

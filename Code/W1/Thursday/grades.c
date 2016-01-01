#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randGrade();

int main (void) {
    srand(time(NULL));
    int grades[10];
    int i = 0;
    while (i < 10) {
        grades[i] = randGrade();
        i++;
    }
    int a = 0;
    printf("\nClass Grades: ");
    while (a < 10) {
        printf("%d ",grades[a]);
        a++;
    }
    int sum = 0;
    int x = 0;
    float avg;
    while (x < 10) {
        sum += grades[x];
        x++;
    }
    avg = sum/10;
    printf("\nThe class average is %.2f\n",avg);
    return 0;
}

int randGrade () {
    int n = (rand() % 100) + 1;
    return n;
}

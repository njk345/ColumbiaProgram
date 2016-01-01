#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int size, newsize;
    printf("Enter Initial Array Size: ");
    scanf("%d", &size);

    int* arr = (int*) malloc(size * sizeof(int));
    
    printf("Enter New Array Size: ");
    scanf("%d", &newsize);

    arr = (int*) realloc(arr, newsize);
    return 0;
}

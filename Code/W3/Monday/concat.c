#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strconcat(char* s1, char* s2) {
    int newlen = strlen(s1) + strlen(s2);
    char* rv = (char*) malloc(newlen * sizeof(char));
    int i = 0, j = 0;
    while (i < strlen(s1)) {
        rv[i] = s1[i];
        i++;
    }
    while (j < strlen(s2)) {
        rv[i] = s2[j];
        i++;
        j++;
    }
    rv[i] = '\0';
    return rv;
}

int main (void) {
    char s1[20];
    char s2[20];
    printf("Enter String 1: ");
    scanf("%s", s1);
    printf("Enter String 2: ");
    scanf("%s", s2);

    printf("Concatenation: %s\n", strconcat(s1, s2));
    return 0;
}

#include <stdio.h>
#include <string.h>

/*
Problem 2
Author: Nick Keirstead

This program takes in a string and converts all
lowercase alphabetic characters to uppercase.
*/


int main (void) {
    char s[20]; //make it nice and long
    printf("Enter a string:  ");
    scanf("%s",s);
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] >= 97 && s[i] <= 122) {//if in lowercase range
            s[i] -= 32; //kick its ascii value down into capital range
        }
    }
    printf("%s\n",s);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Problem 1
Author: Nick Keirstead
*/

bool isPal(char s[], int start, int end) {
  if (start == end || start == end-1) 
    return true;
  else if (s[start] != s[end]) 
    return false;
  else return isPal(s, start+1, end-1);  
}

char* removeSpaces(char* s, int slen) {
    char* rv = (char*) malloc(slen); //slen * sizeof(char) = slen
    int i, x = 0;
    for (i = 0; i < slen; i++) {
        if (s[i] != ' ') {
            rv[x] = s[i];
            x++;
        }
    }
    rv[x] = '\0';
    return rv;
}

void toLower(char* s, int slen) {
    int i;
    for (i = 0; i < slen; i++) {
        if (s[i] >= 65 && s[i] <= 90) s[i] += 32;
    }
}

int main (void) {
    char s[50];
    void *s2;
    printf("Enter String: ");
    fgets(s,50,stdin);
    
    s2 = removeSpaces(s,strlen(s)-1);
    toLower(s2,strlen(s2));
    
    isPal((char*) s2,0,strlen(s2)-1) ? printf("Yes. Palindrome\n") : printf("No. Not Palindrome\n");
    return 0;
}

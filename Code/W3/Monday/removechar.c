#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeCharacter(int *num, char* s, char* tr, char c) {
    int offset = 0;
    if (c >= 65 && c <= 90) offset = 32;
    else if (c >= 97 && c <= 122) offset = -32;
    
    *num = 0;
    int i, x = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == c + offset) {
            *num += 1;
        }
        else {
            tr[x] = s[i];
            x++;
        }
    }
    tr[x] = '\0';
}

int main (void) {
    int num;
    char s[20];
    char tr[20];
    char c;
    
    printf("Enter String: ");
    scanf("%s",s);

    printf("Enter Char to Remove: ");
    scanf(" %c", &c);

    removeCharacter(&num, s, tr, c);
    
    printf("New String: %s\n", tr);
    printf("%d %c's removed.\n", num, c);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main (void) {
    char str2[12];
    char str3[12];
    long a,b,c,d;
    printf("Enter a string:  ");
    fgets(str2, sizeof(str2), stdin);
    printf("\nEnter another string:  ");
    scanf("%s",str3);
    a = sizeof(str2);
    b = sizeof(str3);
    c = strlen(str2);
    d = strlen(str3);
    printf("\nSizeof str2 is %ld, sizeof str3 is %ld.\nLength of str2 is %ld, length of str3 is %ld.\n",a,b,c,d);
    return 0;
}

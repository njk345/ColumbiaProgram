#include <stdio.h>
#include <string.h>

int main () {
    char str1[6] = {'H','E','L','L','O','\0'};
    printf("The sizeof str1 is %ld and the length is %ld\n", sizeof(str1), strlen(str1));
    return 0;
}

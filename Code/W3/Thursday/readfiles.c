#include <stdio.h>

int main (void) {
    FILE *f1;
    f1 = fopen("test1.txt","r");
    FILE *f2;
    f2 = fopen("test2.txt","w");
    
    char c;

    do {
        c = fgetc(f1);
        if (c == EOF) break;
        fprintf(f2,"%c",c);
    } while(1);
    
    fclose(f1);
    fclose(f2);
    return 0;
}

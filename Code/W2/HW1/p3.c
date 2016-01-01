#include <stdio.h>
#include <stdbool.h>

/*
Problem 3
Author: Nick Keirstead

This program allows a checkerboard to 
be printed of any dimensions, using two functions.
One function prints rows of a given width and
the other function uses the first to print rows of
a given length a certain number of times (adds height).
*/


void checkerBoard(int w, int h);
void checkerRow(int w, bool bottomedge);

int main (void) {
    checkerBoard(8,8);
    return 0;
}

void checkerBoard (int w, int h) {
    int i;
    for (i = 0; i < h; i++) {
        if (i == h-1) checkerRow(w,true);
        else checkerRow(w,false);
    }
}

void checkerRow (int w,bool bottomedge) {
    char edge [] = "+-----";
    char inside [] = "|     ";
    int i,j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < w+1; j++) {
            if (j == w) {
                (i == 0) ? printf("+\n") : printf("|\n");
            }
            else {
                (i == 0) ? printf("%s",edge) : printf("%s",inside);
            }
        }
    }
    if (bottomedge) {
        int x;
        for (x = 0; x < w+1; x++) {
            if (x == w) printf("+\n");
            else printf("%s",edge);
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
Excerise 1
Author: Nick Keirstead

This program generates an array of 10 player structs with 
one of 5 random names, one of 3 random teams, and a random
batting average (float from 0 to 100).

It then prints a list of players under each team heading organized
in descending order of batting average and displaying each player's
name and average.
*/


struct cricket {
    char pname[4];
    char tname[30];
    float avg;
};

float randFloat () {
    float r =  100 * (float)rand() / (float)RAND_MAX;
    return r;
}

int main (void) {
    srand(time(NULL));
    struct cricket player [10];
    char names[5][3] = {{'J','o','e'},{'S','a','m'},{'B','o','b'},{'D','o','n'},{'J','a','y'}};
    int i;
    for (i = 0; i < 10; i++) {
        //assign random name
        int r = rand() % 5;
        char randname[4];
        int w;
        for (w = 0; w < 3; w++) {
            randname[w] = names[r][w];
        }
        strcpy(player[i].pname,randname);
        
        //assign random team
        int r2 = rand() % 3;
        if (r2 == 0) strcpy(player[i].tname,"South Africa");
        else if (r2 == 1) strcpy(player[i].tname,"England");
        else strcpy(player[i].tname,"India");

        //assign random batting average
        player[i].avg = randFloat();  
    }

    //sort in descending order of averages w/ bubble sort
    int j,k;
    float temp;
    for (j = 1; j < 10; j++) {
        for (k = 0; k < 9; k++) {
            if (player[k].avg < player[k+1].avg) {
                temp = player[k].avg;
                player[k].avg = player[k+1].avg;
                player[k+1].avg = temp;
            }
        }
    }

    int s = 0,e = 0,n = 0; //counters in team arrays
    struct cricket sa[10]; //south africans
    struct cricket eng[10]; //englishmen
    struct cricket ind[10]; //indians

    int y;
    for (y = 0; y < 10; y++) {
        if (strcmp(player[y].tname,"South Africa") == 0) {
            sa[s] = player[y];
            s++;
        }
        else if (strcmp(player[y].tname,"England") == 0) {
            eng[e] = player[y];
            e++;
        }
        else {
            ind[n] = player[y];
            n++;
        }
    }


    printf("\n");
    int a,b,c;
    printf("South African Team:\n");
    for (a = 0; a < s; a++) {
        printf("Player Name = %s  ||  Batting Average = %.1f\n", sa[a].pname, sa[a].avg);
    }
    
    printf("\nEnglish Team:\n");
    for (b = 0; b < e; b++) {
        printf("Player Name = %s  ||  Batting Average = %.1f\n", eng[b].pname, eng[b].avg);
    }

    printf("\nIndian Team:\n");
    for (c = 0; c < n; c++) {
        printf("Player Name = %s  ||  Batting Average = %.1f\n", ind[c].pname, ind[c].avg);
    }
    printf("\n");
    return 0;
}

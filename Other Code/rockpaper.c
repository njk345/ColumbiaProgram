#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

/*
Assignment 5
Author: Nick Keirstead

Program implements Rock, Paper, Scissors.
Generates random cpu move and prompts user
for their move. Uses function that compares two
moves (strings) and returns an int representing a
game scenario. Switch statement used to print the
right result (who wins and loses) based on the returned
scenario integer.
*/

int getresult(char r1[], char r2[]);

int main (void) {
    char rock[] = "Rock";
    char paper[] = "Paper";
    char scissors[] = "Scissors";
    char cpuresponse[9]; //long enough to hold any of responses
    char userresponse[9];
    char playAgainResponse;
   
    bool playAgain = false;
    
    srand(time(NULL));

    do {
        int r = (rand() % 3) + 1;
        if (r == 1) sprintf(cpuresponse,"%s",rock);
        else if (r == 2) sprintf(cpuresponse,"%s",paper);
        else sprintf(cpuresponse,"%s",scissors);

        do {
            printf("\nRock, Paper, or Scissors?  ");
            scanf("%s",userresponse);
        }
        while (strcmp(userresponse,"Rock") != 0 && strcmp(userresponse,"Paper") != 0 && strcmp(userresponse,"Scissors") != 0);
    
        printf("\nCPU chooses %s.\n", cpuresponse);

        int res = getresult(userresponse,cpuresponse);
        switch (res) {
            case 0:
                printf("%s ties %s.\n", userresponse, cpuresponse);
                break;
            case 1:
                printf("Rock is covered by paper.\n");
                printf("You Lose.\n");
                break;
            case 2:
                printf("Rock crushes scissors.\n");
                printf("You win.\n");
                break;
            case 3:
                printf("Paper covers rock.\n");
                printf("You win.\n");
                break;
            case 4:
                printf("Paper is cut by scissors.\n");
                printf("You Lose.\n");
                break;
            case 5:
                printf("Scissors are crushed by rock.\n");
                printf("You Lose.\n");
                break;
            case 6:
                printf("Scissors cut paper.\n");
                printf("You win.\n");
        }
        printf("\nPlay again?(y/n)  ");
        scanf(" %c",&playAgainResponse);
        (playAgainResponse == 'y')? (playAgain = true) : (playAgain = false);
    }
    while (playAgain);
    
    return 0;
}

int getresult (char r1[], char r2[]) {
    if (strcmp(r1,r2) == 0) return 0; //it's a tie
    
    if (strcmp(r1,"Rock") == 0) {
        if (strcmp(r2,"Paper") == 0) return 1;
        else return 2;
    }
    else if (strcmp(r1,"Paper") == 0) {
        if (strcmp(r2,"Rock") == 0) return 3;
        else return 4;
    }
    else {
        if (strcmp(r2,"Rock") == 0) return 5;
        else return 6;
    }
}

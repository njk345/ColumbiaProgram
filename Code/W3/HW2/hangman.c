#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/*
Hangman Game
Author: Nick Keirstead

This program implements the hangman game.
A random word from an array of c-terminology is selected.
A do-while loop continuously prints out spaces in place of
the word to-be-guessed, asks the user for a letter, and
replaces the spaces with the letter where it appears in the word.

The user gets to choose whether they will guess a letter or a word
on each turn. If they guess a word, their guess is compared directly
to the actual word. If it is correct, they win. If it is wrong, they
immediately lose.

An ASCII man being hanged is printed based on number of lives remaining.

The user has 6 lives (wrong guesses) and 50 total attempts (guesses).
The game ends if the user: (1) runs out of lives; (2) runs out of attempts;
(3) guesses all the letters; (4) incorrectly guesses the whole word on any
turn.
*/

char* terms[] = {"auto","break","case","char","const","continue","default","do",
                "double","else","enum","extern","float","for","goto","if","int",
                "long","switch","typedef","union","unsigned","void","volatile",
                "while","argument","block","function","library","header",
                "variable","operator","compiler","assembly","preprocessor",
                "byte"};


char * body[] = {
                " ____________",
                "|            |",
                "|            0",
                "|           /  ",
                "|           /| ",
                "|           /|\\",
                "|           /  ",
                "|           / \\"
                };

/*this function takes string s, char c, and pointer to int array indices.
It fills indices array with the index of each time c appears in s.
It is not case sensitive regarding c.
*/
void strIndexOf(char* s, char c, int* indices) {
    int j;
    for (j = 0; j < strlen(s); j++) {
        indices[j] = -1;
    }

    int i;
    int x = 0;
    int offset = 0;
    if (c >= 65 && c <= 90) offset = 32; //if c capital, set offset to move into lowercase range

    for (i = 0; i < strlen(s); i++) {
        if (s[i] == c + offset) {
           indices[x] = i;
           x++;
        }
    }
}

void printBody(int lives) {
    int i;
    switch(lives) {
        case 6:
            for (i = 0; i < 2; i++) {
                printf("%s\n", body[i]);
            }
            break;
        case 5:
            for (i = 0; i < 3; i++) {
                printf("%s\n", body[i]);
            }
            break;
        case 4:
            for (i = 0; i < 4; i++) {
                printf("%s\n", body[i]);
            }
            break;
        case 3:
            printBody(5);
            printf("%s\n", body[4]);
            break;
        case 2:
            printBody(5);
            printf("%s\n", body[5]);
            break;
        case 1:
            printBody(2);
            printf("%s\n", body[6]);
            break;
        case 0:
            printBody(2);
            printf("%s\n", body[7]);
            break;
        default:
            printf(" "); //bad input
    }       
}

void strLower(char* s) {
    char *ptr = s;
    while (*ptr != '\0') {
        if (*ptr >= 65 && *ptr <= 90) {
            *ptr += 32;
        }
        ptr++;
    }
}

int main (void) {
    int lives = 6;
    int attempts = 50;

    srand(time(NULL));
    int r = rand() % 36;
    char* word = terms[r];

    char guesses[100];
    strcpy(guesses,word);

    int i;
    for (i = 0; i < strlen(guesses); i++) {
        guesses[i] = '_';
    }
    char wrongguesses[7] = {' ',' ',' ',' ',' ',' ','\n'};
    int w = 0; //counter for wrongguesses array

    do {
        printf("\n");
        printBody(lives);
        printf("\n");
        int j;
        for (j = 0; j < strlen(guesses); j++) {
            printf("%c ",guesses[j]);
        }
        printf("\n\n");
        int choice;
        printf("(1) Guess Letter. (2) Guess Word: ");
        scanf("%d",&choice);

        if (choice == 1) {
        
            printf("Guess a Letter: ");
            char g;
            scanf(" %c", &g);

            int indices[strlen(word)];
            strIndexOf(word,g,indices);

            if (indices[0] != -1) {
                int k = 0;
                while (indices[k] != -1) {
                    guesses[indices[k]] = word[indices[k]];
                    k++;
                }
                printf("Yes! %c is in the word.\n", g);
            }
            else {
                printf("No. %c is not in the word.\n", g);
                int windices[7];
                strIndexOf(wrongguesses,g,windices);
                if (windices[0] == -1) {
                    //if this wrong guess has not already been made,
                    //add it to the wrongguesses array, increment
                    //wrongguesses array counter, and subtract 1 from lives
                    wrongguesses[w] = g;
                    w++;
                    lives--;
                }
            }         
            attempts--;
            printf("%d Total Guesses Left, %d Wrong Guesses Left.\n", attempts, lives);
        }

        else {
            printf("Enter Word Guess: ");
            char sg[20];
            scanf("%s",sg);
            strLower(sg);
            if (strcmp(sg,word) == 0) {
                strcpy(guesses,word);
            }
            else {
                lives = 0;
            }
        }
    }
    while (attempts > 0 && strcmp(guesses,word) != 0 && lives > 0);
    
    printf("\n");
    printBody(lives);
    printf("\n");

    if (strcmp(guesses,word) == 0) {
        int i;
        for (i = 0; i < strlen(guesses); i++) {
            printf("%c ", guesses[i]);
        }
        printf("\nYou win!\n");
    }
    else {
        printf("You lose! ");
        if (lives == 0) printf("Out of Lives!\n");
        else printf("Out of Guesses.\n");
    }
    printf("The Word Was %s.\n", word);

    return 0;
}

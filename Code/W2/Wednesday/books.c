#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

/*
Assignment 2 - Structs
Author: Nick Keirstead

This program implements a limited-scale
virtual library system, in which the user
can enter their name and UNI and borrow and
return books out of a selection (currently size 5).

Structs are used to hold collections of data about
books and students, and an array of structs is used to
hold the available books.

The user cannot borrow another book while they currently
have one out. Likewise, they may not return a book unless 
they have taken one out.

The virtual library console exists in a do-while loop, asking
the user each time whether they wish to make another transaction
or exit the system.
*/

typedef struct book {
    int book_id;
    char book_name[20];
    int pages;
}Book;

typedef struct student {
    int uni;
    char name[30];
    int book_id;
}Student;

void borrowBook(int bid, Student* stud) {
    //pass pointer to struct to modify members directly
    stud->book_id = bid; //stud can no longer borrow
    printf("You Have Taken Out Book ID #%d.\n", bid);
}

void returnBook(int bid, Student* stud) {
    stud->book_id = 0; //stud can now borrow again
    printf("You Have Returned Book #%d.\n",bid);
}

int main (void) {
    srand(time(NULL));
    Book archive[5];
    Student user;
   
    int i;
    for (i = 0; i < 5; i++) {
        archive[i].book_id = (i+1) * 100;
        if (i == 0) {
            strcpy(archive[i].book_name,"Hobbit");
            archive[i].pages = 320;
        }
        else if (i == 1) {
            strcpy(archive[i].book_name,"1984");
            archive[i].pages = 267;
        }
        else if (i == 2) {
            strcpy(archive[i].book_name,"Macbeth");
            archive[i].pages = 240;
        }
        else if (i == 3) {
            strcpy(archive[i].book_name,"Frankenstein");
            archive[i].pages = 352;
        }
        else if (i == 4) {
            strcpy(archive[i].book_name,"Matilda");
            archive[i].pages = 232;
        }
    }
   
    bool again = false;
    int choice;
    
    printf("Enter Your Name:  ");
    scanf("%s",user.name);
    printf("Enter Your UNI:  ");
    scanf("%d",&user.uni);
    printf("\nWelcome %s.\n",user.name);
    
    user.book_id = 0;
        
    do {
        CHOOSE_TRANSACTION:
        printf("Enter 1 to Borrow Book or 2 to Return Book:  ");
        scanf("%d",&choice);
       
        if (choice == 1 && user.book_id == 0) {
            printf("\nAvailable Books:\n");
            int i;
            for (i = 0; i < 5; i++) {
                printf("%s - %d pages\n",archive[i].book_name,archive[i].pages);
            }
           
           CHOOSE_BOOK: //label for goto
            printf("\nEnter Title Choice:  ");
            char title[20];
            int titleid = 0;
            scanf("%s",title);
            int j;
            for (j = 0; j < 5; j++) {
                if (strcmp(archive[j].book_name,title) == 0) {
                    titleid = archive[j].book_id;
                }
            }
            if (titleid == 0) {
                printf("Invalid Choice.\n");
                goto CHOOSE_BOOK;
                //Sorry, I know goto's are terrible practice and are never
                //necessary to the program, but I think it's fairly easy
                //to follow in this instance, so I'm went the lazy route!
            }
            borrowBook(titleid,&user);
        }
        else if (choice == 2 && user.book_id != 0) {
            returnBook(user.book_id,&user);
        }
        else {
            printf("Invalid Choice.\n");
            if (choice == 1) printf("Must Return Book #%d.\n",user.book_id);
            else if (choice == 2) printf("Must Borrow Book First.\n");
            goto CHOOSE_TRANSACTION; //sorry again..
        }

        char response;
        printf("\nMake Another Transaction (y/n)?  ");
        scanf(" %c", &response);
        (response == 'y')? (again = true) : (again = false);
    }
    while (again);
   
    printf("\nThank You For Using the Virtual Library.\n");
    
    return 0;
}

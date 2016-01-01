#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

void filldata (node *n) {
  n -> data = (rand() % 100) + 1;
}

void giveNextNode (node *n) {
  n -> next = (node *) malloc(sizeof(node));
  filldata(n -> next);
}

int main (void) {
  srand(time(NULL));
  node *head = (node *) malloc(sizeof(node));
  filldata(head);
   
  node *counter = head;
  int i = 1;

  while (counter -> data != 100) {
    printf("Node %d: Data = %d\n", i, counter -> data);
    i++;
    giveNextNode(counter);
    counter = counter -> next;
  }
  printf("Node %d: Data = %d\n", i , counter -> data);
  return 0;
}

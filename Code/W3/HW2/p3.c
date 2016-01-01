#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define MAX_SIZE 100

/*
Problem 3
Author: Nick Keirstead
*/

typedef struct Stack {
	int data[MAX_SIZE];
	int *top;
} Stack; //make instance of Stack called stack

void push(Stack *s, int val) {
	assert(s->top - s->data < MAX_SIZE);
	//assert will make program instantly crash if condition not met.
	
	*s->top = val;
	s->top++;
}

int pop(Stack *s) {
	assert(s->top != s->data);
	
	s->top--;
	return *s->top;
}

void print(Stack *s) {
	int *curr;
	for (curr = s->top-1; curr >= s->data; curr--) {
		printf("Data = %d\n", *curr);
	}
}

int main(void) {
	srand(time(NULL));
	Stack s;	
	s.top = s.data;
	
	int i; 
	for (i = 0; i < 5; i++) {
		int r = rand() % 100;
		push(&s,r);
	}
	print(&s);
	
	printf("\n");
	
	for (i = 0; i < 5; i++) {
		int p = pop(&s);
		printf("%d Popped\n", p);
	}
	
	return 0;
}
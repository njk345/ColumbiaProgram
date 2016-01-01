#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 25

/*
Problem 6
Author: Nick Keirstead
*/

typedef struct List {
	int head;
	struct List *tail;
} List;


bool isEmpty(List *l) {
	return l == NULL;
}

int head(List *l) {
	return l->head;
}

List* tail(List *l) {
	return l->tail;
}

List* cons(int val, List *l) {
	List *rv = malloc(sizeof *rv);
	rv->head = val;
	rv->tail = l;
	return rv;
}

List* append(List *l1, List *l2) {
	if (isEmpty(l1)) 
		return l2;
	else if (isEmpty(l2)) 
		return l1;
	else 
		return cons(head(l1), append(tail(l1), l2));
}

List* filter_lt(List *l, int val) {
	if (isEmpty(l))
		return NULL;
	else if (head(l) < val)
		return cons(head(l), filter_lt(tail(l), val));
	else
		return filter_lt(tail(l), val);
}

List* filter_ge(List *l, int val) {
	if (isEmpty(l))
		return NULL;
	else if (head(l) >= val)
		return cons(head(l), filter_ge(tail(l), val));
	else
		return filter_ge(tail(l), val);
}

List* quickSort(List *l) {
	if (isEmpty(l))
		return NULL;
	else {
		List *lt = filter_lt(tail(l), head(l));
		List *ge = filter_ge(tail(l), head(l));
		return append(quickSort(lt), cons(head(l), quickSort(ge)));
	}
}

void print(List *l) {
	List *p;
	for (p = l; p != NULL; p = p->tail) {
		printf("%d ", p->head);
	}
	printf("\n");
}

int length(List *l) {
	if (isEmpty(l))
		return 0;
	else
		return 1 + length(tail(l));
}

int main(void) {
	srand(time(NULL));
	List *l = NULL;
	int i, r;
	for (i = 0; i < SIZE; i++) {
		r = rand() % 100;
		l = cons(r, l);
	}
	
	printf("Random List[%d]:\n", length(l));
	print(l);
	
	printf("Sorted List[%d]:\n", length(l));
	l = quickSort(l);
	print(l);
	
	return 0;
}
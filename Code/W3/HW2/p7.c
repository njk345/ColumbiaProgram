#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct Node {
	int val;
	struct Node *prev;
	struct Node *next;
} Node;

typedef struct Dll {
	Node *head;
	Node *tail;
} Dll;

Dll* new() {
	Dll *list = malloc(sizeof *list);
	list->head = NULL;
	list->tail = NULL;
	return list;
}

bool isHead(Node *list) {
	//guaranteed a non-null input
	return (list->prev == NULL);
}

bool isTail(Node *list) {
	return (list->next == NULL);
}

void add(Dll *list, int val) {
	Node *c = NULL; //curr
	Node *p = NULL; //prev
	Node *n = malloc(sizeof *n); //new
	n->val = val;
	
	if (val >= 0) {
		for (c = list->head; c != NULL; c = c->next) {
			if (val > c->val)
				break;
			p = c;
		}
		n->prev = p;
		n->next = c;
		
		if (list->head == NULL) {
			//adding to empty list
			list->head = n;
			list->tail = list->head;
		}
		else if (c == NULL) {
			//adding to end of list
			p->next = n;
			list->tail = n;
		}
		else if (isHead(c)) {
			//adding to head of list
			c->prev = n;
			list->head = n;
		}
		else {
			p->next = n;
			c->prev = n;
		}
	}
	else {
		for (c = list->tail; c != NULL; c = c->prev) {
			if (val < c->val)
				break;
			p = c;
		}
		n->prev = c;
		n->next = p;
		
		if (list->head == NULL) {
			//adding to empty list
			list->head = n;
			list->tail = n;
		}
		else if (c == NULL) {
			//adding to front of list
			p->prev = n;
			list->head = n;
		}
		else if (isTail(c)) {
			c->next = n;
			list->tail = n;
		}
		else {
			c->next = n;
			p->prev = n;
		}
	}
}

void delete(Dll *list, int val) {
	Node *c = NULL;
	for (c = list->head; c != NULL; c = c->next) {
		if (c->val == val) {
			if (isHead(c) && isTail(c)) {
				//removing from single-node list
				list->head = NULL;
				list->tail = NULL;
			}
			else if (isHead(c)) {
				//removing head of list
				list->head = c->next;
			}
			else if (isTail(c)) {
				//removing tail of list
				c->prev->next = NULL;
				list->tail = c->prev;
			}
			else {
				//removing between two nodes
				c->prev->next = c->next;
			}
		}
	}
}

void print(Dll *list) {
	Node *c = list->head;
	while (c != NULL) {
		printf("%d\n", c->val);
		c = c->next;
	}
}

int getSize(Dll *list) {
	int size = 0;
	Node *c = NULL;
	for (c = list->head; c != NULL; c = c->next) {
		size++;
	}
	return size;
}

int main(void) {
	srand(time(NULL));
	
	Dll *d = new();

  	int i,s,r;
	s = rand() % 100;
	
	for (i = 0; i < s; i++) {
		r = (rand() % 100) - 10;
		add(d, r);
	}
  	print(d);
	printf("Initial Size = %d\n", getSize(d));

	r = (rand() % 100) - 10;
	delete(d, r);
	printf("\nAll %d's deleted.\n", r);
	printf("New Size = %d\n", getSize(d));
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
Problem 4
Author: Nick Keirstead
*/

typedef struct bst {
	int val;
	struct bst *left;
	struct bst *right;	
} bst;

bst* new(int val, bst *left, bst *right) {
	bst *t = malloc(sizeof *t);
	t->val = val;
	t->left = left;
	t->right = right;
	return t;
}

bool isEmpty(bst *root) {
	return root == NULL;
}

bst* insert(bst *root, int val) {
	if (isEmpty(root)) {
		return new(val,NULL,NULL);
	}
	else if (val < root->val) {
		return new(root->val, insert(root->left, val), root->right);
	}
	else if (val > root->val) {
		return new(root->val, root->left, insert(root->right, val));
	}
	else {
		return root;
	}
}

bool search(bst *root, int val) {
	if (isEmpty(root)) {
		return false;
	}
	else if (root->val == val) {
		return true;
	}
	else if (val < root->val) {
		return search(root->left, val);
	}
	else {
		return search(root->right, val);
	}
}

//this is the traverse function
void printbst(bst *root) {
	if (isEmpty(root)) {
		return;
	}
	else {
		printbst(root->left);
		printf("%d ", root->val);
		printbst(root->right);
	}
}


int main(void) {
	srand(time(NULL));
	
	bst *tree = NULL;
	int i;
	for (i = 0; i < 25; i++) {
		int r = rand() % 100;
		tree = insert(tree,r);
	}
	
	printbst(tree);
	printf("\n\n");
	
	for (i = 0; i < 100; i++) {
		if (search(tree,i)) {
			printf("%d Found In Tree\n", i);
		}
	}
	
}
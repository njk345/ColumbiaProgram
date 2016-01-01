#include <stdio.h>

int main () {
	char relationship[20];
	int x,y;
	printf("Enter Two Integers:  ");
	scanf("%d %d",&x, &y);
	if (x == y) {
		sprintf(relationship,"equal to");
	}
	else if (x > y) {
		sprintf(relationship,"greater than");
	}
	else {
		sprintf(relationship,"less than");
	}
	printf("%d is %s %d.\n", x, relationship, y);
	return 0;
}	

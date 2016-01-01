#include <stdio.h>

int main () {
	float l;
	float w;
	printf("Enter length of rectangle:\n");
	scanf("%f",&l);
	printf("Enter width of rectangle:\n");
	scanf("%f",&w);
	printf("Area of a %.1f x %.1f rectangle = %.1f\n", l, w, (l*w));
	return 0;
}

#include <stdio.h>
#include <math.h>

int main () {
	float r;
	printf("Enter radius of circle:\n");
	scanf("%f", &r);
	printf("Area of a %.1f radius circle is %.1f\n\n", r, (r*r*M_PI));
	return 0;
}

#include <stdio.h>

int main () {
	float c;
	printf("\nEnter a celcius temperature:\n");
	scanf("%f",&c);
	float f = 1.8 * c + 32;
	char deg1[20];
	char deg2[20];
	if (c == 1 || c == -1) {
		sprintf(deg1,"%s","degree");
	}
	else {
		sprintf(deg1,"%s","degrees");
	}
	if (f == 1 || f == -1) {
		sprintf(deg2,"%s","degree");
	}
	else {
		sprintf(deg2, "%s","degrees");
	}	

	printf("%.2f %s celcius converts to: %.2f %s fahrenheit.\n\n", c, deg1, f, deg2);
	return 0;
}

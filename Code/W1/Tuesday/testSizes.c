#include <stdio.h>

int main () {
	int num1 = 0;
	double num2 = 3.14159;
	char letter = 'N';
	
	
	//printf("Hello World!\n");
	//printf("The sizeof(in bytes) of num1 is %ld\n", sizeof(num1)); //%ld = long integer
	//printf("The sizeof(in bytes) of num2 is %ld\n", sizeof(num2));
	//printf("The sizeof(in bytes) of letter is %ld\n", sizeof(letter));
	printf("The sizeof num1 is %ld, num2 is %ld, letter is %ld.\n",sizeof(num1),sizeof(num2),sizeof(letter));
	return 0;
}

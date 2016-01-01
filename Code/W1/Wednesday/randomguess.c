#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	//int N = (int)((float) rand()) / (RAND_MAX+1) * 100 + 0.5);
    if (argc != 2) {
        printf("usage: %s <nmax>\n", argv[0]);
        return 0;
    }
    int nmax = atoi(argv[1]);

	time_t t;
	srand((unsigned) time(&t));
	int N = (rand() % nmax)+1;

	int guess;
	do {
		printf("Enter a guess:  ");
		scanf("%d",&guess);
		if (guess > N) {
			printf("\nToo big. ");
		}
		else if (guess < N) {
			printf("\nToo small. ");
		}
	}
	while (guess != N);
	printf("\nYou guessed it correctly!\n\n");
	return 0;
}

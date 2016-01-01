#include <stdio.h>
#include <math.h>

double mean(int arr[], int len) {
    double tot = 0;
    int i;
    for (i = 0; i < len; i++) {
        tot += arr[i];
    }
    return tot / len;
}

double stddev(int arr[], int len, double mean) {
    double tot = 0;
    int i;
    for (i = 0; i < len; i++) {
        tot += pow((arr[i] - mean), 2);
    }
    tot /= len;
    tot = sqrt(tot);
    return tot;
}

int main (void) {
    FILE *scorefile;
    scorefile = fopen("scores.txt","r");
    
    int scores[100];

    char throwaway[40];
    fgets(throwaway,40,scorefile);
    int i;
    int s = 0;
    for (i = 0; i < 10; i++) {
        int freq;
        int score;
        fscanf(scorefile, "%d\t\t\t%d", &score, &freq);
        int x;
        for (x = 0; x < freq; x++) {
            scores[s] = score;
            s++;
        }
    }

    double avg = mean(scores, s);
    double dev = stddev(scores, s, avg);
    printf("Mean = %.2lf\n", avg);
    printf("Standard Deviation = %.2lf\n", dev);
    return 0;
}

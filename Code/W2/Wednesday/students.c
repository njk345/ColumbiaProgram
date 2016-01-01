#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50


struct student {
    char name[30];
    int rollnum;
    int grades[3]; //grades for classes
};

int main (void) {
    struct student studs[SIZE];
    srand(time(NULL));

    //fill each student's class array w/ random grades
    int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < 3; j++) {
            studs[i].grades[j] = (rand() % 100 + 1);
        }
        studs[i].rollnum = i+1; //roll num is index + 1 in students array
    }

/****************************************************/
    printf("GRADES:\n");
    int k;
    for (k = 0; k < SIZE; k++) {
        printf("Student %d:  %d %d %d\n",k+1, studs[k].grades[0], studs[k].grades[1], studs[k].grades[2]);
    }
    
    //max grades for each class
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    //roll nums of students with max grades in each respective class
    int maxroll1 = 0;
    int maxroll2 = 0;
    int maxroll3 = 0;

    int maxes[] = {max1,max2,max3};
    int maxrollnums[] = {maxroll1,maxroll2,maxroll3};

    int x,y;
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < 3; y++) {
            if (studs[x].grades[y] > maxes[y]) {
                maxes[y] = studs[x].grades[y]; //replace largest grade in subject (1,2,or 3)
                maxrollnums[y] = studs[x].rollnum;//replace rollnum of stud w/ largest grade in subj.
            }
        }
    }

/*****************************************************************/
    printf("\nLargest Grade By Subject:\n");
    int w;

    for (w = 0; w < 3; w++) {
        printf("Subject %d:  %d; Student rollnum = %d\n",w+1,maxes[w],maxrollnums[w]);
    }
/****************************************************************/
    int v;
    float maxavg = 0;
    int maxstud;
    for (v = 0; v < SIZE; v++) {
        float tempavg = (studs[v].grades[0] + studs[v].grades[1] + studs[v].grades[2]) / 3.0;
        if (tempavg > maxavg) {
            maxavg = tempavg;
            maxstud = v+1;
        }
    }
    
    printf("\nStudent With Highest Total Marks:\n");
    printf("Student %d:  Grade Avg = %f\n", maxstud, maxavg);
    return 0;
}

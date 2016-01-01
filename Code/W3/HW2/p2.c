#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DAYS_PER_4YEARS 1461

/*
Problem 2
Author: Nick Keirstead
*/

typedef struct {
    unsigned int minute;
    unsigned int hour;
    unsigned int day;
    unsigned int month;
    unsigned int year;
} Time;

int minSinceEpoch(Time t) {
	//"Epoch" is defined as 00:00 Jan 1, 1600.
	//purpose of the function is to take Time struct and return
	//number of minutes between the Time and the Epoch
	
	int days = 0;
	
	days += (t.year - 1600) / 4 * DAYS_PER_4YEARS; //number of full 4 year periods * num days in 4 years
	
	int remainder = (t.year - 1600) % 4; //years left after 4 year periods allocated
	int remdays[4] = {0, 366, (366+365), (366+2*365)};
	days += remdays[remainder];
	
	int monthdays[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
	int monthdaysleap[12] = {0,31,60,91,121,152,182,213,244,274,305,335};
	
	(t.year % 4 != 0) ? (days += monthdays[t.month-1]) : (days += monthdaysleap[t.month - 1]);
	
	days += t.day - 1;
	
	int hours = days * 24;
	hours += t.hour - 1;
	
	int minutes = hours * 60;
	minutes += t.minute;
	
	return minutes;
}

int diffmin(Time t1, Time t2) {
   return abs(minSinceEpoch(t1) - minSinceEpoch(t2)); 
 }

int main (void) {
    
    Time t1, t2;
    t1.year = 1961;
    t1.month = 6;
    t1.day = 16;
    t1.hour = 0;
    t1.minute = 0;

    t2.year = 2015;
    t2.month = 7;
    t2.day = 15;
    t2.hour = 0;
    t2.minute = 0;

    int diff = diffmin(t1,t2);
    printf("%d\n", diff);
    return 0;
}

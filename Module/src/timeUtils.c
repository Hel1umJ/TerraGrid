//TODO: PUT INTO TIME UTILITIES

#include <time.h>
#include <stdio.h>
#include "config.h"

long int secondsToday(){
    time_t timer;
    struct tm y2k = {0}; //Struct holding date for Jan 1, 2000, reference point
    long int seconds;
    y2k.tm_hour = 0;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = 0;
    y2k.tm_mon = 0;
    y2k.tm_mday = 0;
    y2k.tm_isdst = DLST;
    time(&timer); //get current time, same as timer = time(NULL);
    seconds = difftime(timer,mktime(&y2k));

    
    //Note: decimal DT cannot have % done on them, must be cast to discrete numerical 
    //type first.
    long int secondsToday = seconds%(24*60*60);

    return secondsToday;
}

void delay10(){
	long int secondsNow = time(NULL);
	while((time(NULL) - secondsNow)<10 ){
		;
	}
	printf("Delayed 10 seconds\n");
	return;
}


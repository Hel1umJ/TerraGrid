//TODO: PUT INTO TIME UTILITIES

#include <time.h>
#include <stdio.h>
#include "config.h"

long int secondsToday(){
    long int seconds;
    time_t timer;

    time(&timer); //get current time, same as timer = time(NULL);
    struct tm y2k = {0,0,0,0,0,0,0,0,DLST,0,0};
    seconds = difftime(timer,mktime(&y2k));

    //Note: decimal DT cannot have % done on them, must be cast to discrete numerical 
    //type first.
    long int secondsToday = seconds%(24*60*60);

    return secondsToday;
}

void delay(int n){
	long int secondsNow = time(NULL);
	while((time(NULL) - secondsNow)<n ){;}
	return;
}


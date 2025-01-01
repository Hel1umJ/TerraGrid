#ifndef TIMEUTILS
#define TIMEUTILS

#include "config.h"
/*
*Prototypes
*/
//Returns the number of seconds elapsed over the current day.
long int secondsToday();

//Delays for n seconds
void delay(int n);


/*
*DT Declarations
*/
struct tm Y2K = {0,0,0,0,0,0,0,0,DLST,0,0};

#endif
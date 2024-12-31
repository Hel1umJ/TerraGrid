#ifndef CONFIG
#define CONFIG

/*
*General
*/


/*
*GPIO Pins
*/
#define LIGHT_PIN 2 //GPIO 2; PIN 3
#define WATER_PIN 3 //GPIO 3; PIN 5

/*
*Lighting
*/
#define LIGHT_DURATION 10.5 //Float [0.0,24.0]; Num hours light should stay on for
#define LIGHT_ENABLE 8//Float [0.0, 24.0]; time of day to turn on lights


/*
*Watering
*/
#define WATER_DURATION 30 //Int; Seconds

/*
*Time
*/
#define DLST 0 //IF DLST, set to 1; 0 OW


#endif
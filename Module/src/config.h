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
#define LIGHT_ENABLE 8.0//Float [0.0, 24.0]; time of day to turn on lights
#define LIGHT_DISABLE 16.0//Float [0.0, 24.0]; time of day to turn on lights


/*
*Watering
*/
#define WATER_DURATION 16 //Int; Seconds
#define WATER_MOISTURE_THRESHOLD 128//TODO: Change to adequate level via testing 
#define WATER_FAILSAFE_INTERVAL 5 //Int; Days

/*
*Time
*/
#define DLST 0 //IF DLST, set to 1; 0 OW

/*
*MQTT
*/
/* Change these to match your setup */
#define BROKER_ADDRESS  "tcp://192.168.1.100:1883"  // IP of RPI5; broker service running on port 1883
#define QOS         2 //Quality Of Service; 0: at most once (no confirmation receipt from broker) 1: at least once (retry sending until receives confirmation from broker; can have duplicates) 2: exactly once
#define TIMEOUT     10000L


#endif
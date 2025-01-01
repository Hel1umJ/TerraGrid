//Board: Pi Zero W C1.1

/*
*STD Lib includes
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//#include <libwebsockets.h> //apt/pacman installs

/*
*External Lib includes
*/
#include "pigpio.h"

/*
*Projet includes
*/
#include "config.h"
#include "timeUtils.h"


/*
*Global variables
*/
//general
long moduleID;

//light

//water

struct tm lastWateringTime = time(NULL);


int main(int argc, char** argv){
    /*
    *Setup
    */
    //Configure moduleID
    moduleID = 1;//TODO: hardcoded for testing purposes; change to a unique identifier using init procedure over mqtt to acknowledge existence of other modules.

    //setup pigpio & I/O pins
    int rc = gpioInitialise();
    if(rc < 0){
        printf("gpio initialization failed; Error code: %d", rc);
    }

    gpioSetMode(WATER_PIN, PI_OUTPUT);
    gpioWrite(WATER_PIN, 0);

    gpioSetMode(LIGHT_PIN, PI_OUTPUT);
    gpioWrite(LIGHT_PIN, 0);
    
    //Super-loop
    while(1){
    /*
    *Read Sensor data
    */

    //DHT11 temp/humidity
    
    //capacitive moisture sensor

    /*
    *Manipulate Hardware
    */
    //light actuation
    double currentHour = secondsToday()/(60 * 60 * 24); //Hour (float)
    if( (currentHour >= LIGHT_ENABLE) && (currentHour < LIGHT_DISABLE) ){
        gpioWrite(LIGHT_PIN, 1); // Turn light on
    } else {
        gpioWrite(LIGHT_PIN, 0); // Turn light off
    }

    //Water solenoid actuation
    time_t now = time(NULL);
    double elapsed = difftime(now, lastWateringTime);

    if (elapsed >= (WATER_FAILSAFE_INTERVAL * 24 * 60 * 60)) { // 5 days in seconds
        gpioWrite(WATER_PIN, 1); // Turn water on
        delay(WATER_DURATION);   //TODO: Multithread this; replaced with call to sleep()
        gpioWrite(WATER_PIN, 0); // Turn water off
        lastWateringTime = now;  // Reset last watering time
    }

    /*
    *Transmit log data via mqtt to central server
    */
    }

    gpioTerminate();
    return 0;
}





























//#define WATER_DURATION 30 //seconds; Water for [config] seconds
//#define LIGHT_ON 8.0F //hours; float number from [0,24], decimal for partial hours
//#define LIGHT_OFF 21.0F //hours; float number from [0,24], decimal for partial hours

///*
//*Pinout declarations
//*/

//#define LIGHT_PIN //GPIO6
//#define WATER_PIN //GPIO13
////TODO: Add any Sensor input pins, case by case, as needed
//#define DHT_PIN //GPIO19
//#define MOISTURE_PIN //GPIO26

//int main(int argc, char* argv[]) {
//    // Initialize WiringPi and pin modes + outputs

//    long int openSeconds = openTime*60*60;
//    long int closingSeconds = closingTime*60*60;

//    //Infinite control loop

//    for(;;){
//        long int doorActivationTime = 30;
//        long int seconds = daySeconds();
//        float hours = ((float)seconds)/(60*60);
//        printf("Hours: %9.6f\n", hours);

//        //TODO: put this if statement in a timer that makes sure door is open/closed (make it like 5 mins long)
//        if((daySeconds() >= openSeconds) && (daySeconds() <= closingSeconds)){
//            time_t startTime = time(NULL);
//            //while((time(NULL) - startTime) < doorActivationTime){
//                openDoor();
//		printf("Door opening\n");
//		delay10();
//            //}
//        }else{
//            time_t startTime = time(NULL);
//            //while((time(NULL) - startTime) < doorActivationTime){
//                closeDoor();
//		printf("Door closing\n");
//		delay10();
//            //}
            
//         }
				
//        resetDirectionPins();
//	delay(10);
//    }

//    return 0;
//}



    


////sensor pin declarations. 
//uint8_t sPin0 = A0;
//uint8_t sPin1 = A1;
//uint8_t sPin2 = A2;
//uint8_t sPin3 = A3;
//uint8_t sPin4 = A4;
//uint8_t sPin5 = A5;

////watering pin
//int waterPin = 2;

////light pin
//int lightPin = 4;

////Light variables. 
//bool lightState = true;
//int lastLightToggle = 0;

////watering variables. 
//double moisture = 0.0;
//int lastWatering = 0;
////bool watering = false;
//int wateringTime = 3000;//change this to however many miliseconds you want to water for. (testing purposes - 3 seconds) 

////loop variables. 
//long fiveSeconds = 5000;
//int fiveSecondIntervals = 0;// number of 5 second intervals. 
//unsigned long lastTime = 0;
//unsigned long currentTime = millis();


//void setup() {
//  //setup lights
//  pinMode(lightPin, OUTPUT);
//  digitalWrite(lightPin,HIGH);

//  pinMode(waterPin,OUTPUT);
//  digitalWrite(waterPin,LOW);
//  Serial.begin(9600);
//}

//void loop() {
//  currentTime = millis();
//  int delta = currentTime - lastTime;//time passed since last 5 second interval. 
  
//  //Intervals of 5 seconds. 
//  if(delta >= fiveSeconds){


//    //1.update lastTime and update threeHourInterval counter. (before everything b/c otherwise time difference wouldnt be reflected 
//    //in comparisons) 
//    lastTime = millis();
//    fiveSecondIntervals = fiveSecondIntervals +1;


//    //2.Collect moisture reading (gather data (100 data points on every sensor), average them, and then average all sensor values). 
//    //Sensor values
//    float s0 = 0.0;
//    float s1 = 0.0;
//    float s2 = 0.0;
//    float s3 = 0.0;
//    float s4 = 0.0;
//    float s5 = 0.0;
//    for(int i = 0;i<100;i++){
//      s0 = s0 + analogRead(sPin0);
//      s1 = s1 + analogRead(sPin1);
//      s2 = s2 + analogRead(sPin2);
//      s3 = s3 + analogRead(sPin3);
//      s4 = s4 + analogRead(sPin4);
//      s5 = s5 + analogRead(sPin5);
//      delay(10);//wait for 1/100 of a second before next data collection
//    }
//    //average sensor values. 
//    s0 = s0/100;
//    s1 = s1/100;
//    s2 = s2/100;
//    s3 = s3/100;
//    s4 = s4/100;
//    s5 = s5/100;
    
//    //final moisture reading:
//    moisture = (s0+s1+s2+s3+s4+s5)/6;
//    Serial.println(moisture);

    
//    //3: Water (if needed) (based on time and moisture content) (315 is sensor value cutoff for too dry) 
//    int waterDelta = fiveSecondIntervals - lastWatering;

//    //edit this if statement to change how many "ticks" it takes to initiate watering. 
//    if(waterDelta >= 2 || moisture > 315 ){
//      //water
//      digitalWrite(waterPin,HIGH);
//      Serial.println("Watering");
//      //watering = true;
//      unsigned long wateringStart = millis();

//     //unintrusively pauses the program for wateringTime miliseconds. 
//      while((millis()- wateringStart) <= wateringTime){
//        continue;
//      }
//      digitalWrite(waterPin,LOW);


//      lastWatering = fiveSecondIntervals;

//    }
    
//    //ALT method with 2 if statements, uncomment this and comment out the while loop + next line in the above if statement. 
//    //While loop: unintrusively pauses further execution of the program; if statements only: Don't pause execution of the program and only use conditionals (this method is useful if any delays would hinder the rapid exectuion of other parts of the program)
////    if(watering){
////      //TODO: test how long you should water for, and update delay accordingly. 
////      
////      //Controls how long to water for.
////      if( (millis()- wateringStart) >= wateringTime ){
////         digitalWrite(waterPin,LOW);
////         watering = false;
////      }
////      
////    }

    
//    //4: Toggles light state every 10 seconds. 
//    int lightToggleDelta = fiveSecondIntervals - lastLightToggle;
    
//    //edit this if statement to change how many "ticks" it takes to switch lights. 
//    if(lightToggleDelta >= 2){
//      //turnLights on/off using boolean
//      if(lightState){
//        //turn lights off
//        Serial.println("Switching lights off");
//        digitalWrite(lightPin,LOW);
//        lightState = !lightState;
//      }else{
//        //turn lights on
//        Serial.println("Switching lights on");
//        digitalWrite(lightPin,HIGH);
//        lightState = !lightState;
//      }
//      lastLightToggle = fiveSecondIntervals;
//    }

    
//    //5: Transmit data to website
    
//  }

//  //this resets all values back to zero once 49 days have been reached. 
//  if(millis()>= 4233600000){
//    //reset all values back to zero. 
//    fiveSecondIntervals = 0;
//    lastWatering = 0;
//    lastLightToggle = 0;
//  }
  
//}

//TODO: Serial read via A2D converter OR intermediate Arduino (built in A2D). 
  //https://www.switchdoc.com/2020/06/tutorial-capacitive-moisture-sensor-grove/ 
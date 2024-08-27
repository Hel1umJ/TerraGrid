#Description: This directory contains everything relevant to controlling an individual esp32 based unit of the modular plant grid. 

#Hardware: 
    -Esp32 Microcontroller

#Dependencies:
    -Platform.IO VSCode extension for flashing the esp32

    https://docs.platformio.org/en/stable/tutorials/espressif32/arduino_debugging_unit_testing.html#id2 


#Communication: 
    -Hardwired: I2C over a 2 line communication channel.
    -Wireless: MQTT
        -Requires internet access for each individual module.


#Requirements: 
    -Sensor data from each module is reported every hour. 
    -Modularity has to be maintained, just by uploading a program to a new unit and plugging it into power/communication 
    channel it should seamlessly work and interface with the rest of the system. 
    -The number of modules should not be bounded. 

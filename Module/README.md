#Description: This directory contains everything relevant to controlling an individual raspberry pi zero based unit of the modular plant grid. 

#Hardware: 
    -Raspberry pi zero V1.1
    -DHT11 Temperature & Humidity sensor
    -Capacitative Moisture Sensor & MCP3008 B2D converters
    -12v to 5V converter
    -12V LED light bar
    -12V Solenloid

#Communication scheme: 
    -Hardwired: I2C over a 2 line communication channel.
    -Wireless: MQTT
        -Requires internet access for each individual module.


#Requirements: 
    -Sensor data from each module is reported every hour. 
    -Modularity has to be maintained, just by uploading a program to a new unit and plugging it into power/communication 
    channel it should seamlessly work and interface with the rest of the system. 
    -The number of modules should not be bounded. 

#Raspberry Pi Zero V1.1 Wiring Diagram: 
https://peppe8o.com/raspberry-pi-zero-pinout/


#Dependencies:
    -pigpio: https://abyz.me.uk/rpi/pigpio/
        -Installation: place pigpio-master library file in a known location
            wget https://github.com/joan2937/pigpio/archive/master.zip
            unzip master.zip
            cd pigpio-master
            make
            sudo make install

            If the Python part of the install fails it may be because you need the setup tools.

            sudo apt install python-setuptools python3-setuptools
            sudo pacman -S python-setuptools

        -Compilation:
            -See example makefile in pigpio-master directory
            -Set dynamic link path using command line option. Ex:
                gcc -Wl,-rpath=/home/heliumj/Downloads/pigpio-master -o x_pigpio x_pigpio.o -L. -lpigpio -pthread -lrt







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
        -Installation: 
            1. Fetch & place pigpio-master library file in a known location (/home/heliumj/Coding/lib)
                Fetch + compile
                wget https://github.com/joan2937/pigpio/archive/master.zip
                unzip master.zip
                cd pigpio-master

            2. Compile (from within install dir.)
                make
                or
                sudo make install

                -If the Python part of the install fails it may be because you need the setup tools:
                sudo apt install python-setuptools python3-setuptools
                sudo pacman -S python-setuptools

            3. Update static linker & dynamic linker environment variables to make library visible to them (add these to .bashrc) (and then refresh terminal)
                export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/heliumj/Coding/lib/pigpio-master
                export LIBRARY_PATH=$LIBRARY_PATH:/home/heliumj/Coding/lib/pigpio-master

                or
                run make install to place compiled libs into standard lib locations

            -Note: pigpio comes standard on raspbian, and no installation or config is needed


        -Compilation:
            -See example makefile in pigpio-master directory or makefile in current directory (link against -lrt -lpigpio)
            -Specify lib path for dynamic linker using -Wl,-rpath command line option: (Note: option no longer needed b/c of setting LD_LIBRARY_PATH and LIBRARY_PATH env variables) 
                gcc -Wl,-rpath=/home/heliumj/Coding/lib/pigpio-master -o module *.o -lpigpio -pthread -lrt

            -Note: pigpio comes standard on raspbian and libs already installed in default system locations, so no need to specify lib source files with -L
        
        -Execution:
            1. add sudo /home/admin/TerraGrid/build/module to .bashrc to execute it automatically on startup.

    -Eclipse Paho C MQTT Client Library: https://www.hivemq.com/blog/implementing-mqtt-in-c/ 
        -Installation: 
            git clone https://github.com/eclipse-paho/paho.mqtt.c.git
            make
            sudo make install

        -




           











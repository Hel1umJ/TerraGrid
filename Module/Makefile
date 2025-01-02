######################################################################
# Global variables.
######################################################################
#Compiler; gcc (C), g++ (C++)
CC=gcc
#LD is for any dynamically linked libs (libs derrived from .so files)
LD=ld
WARNS=-Wall -pedantic -Wextra
CFLAGS=-g3 -std=gnu11 ${WARNS}
CPPFLAGS = -g3 -std=c++14 ${WARNS}

SRC_PATH = ./src
BUILD_PATH = ./build


all: module

#only link libraries when building final executable; dont need to link when compiling into .o files
#${CC} ${CFLAGS} -L/home/heliumj/Coding/lib/pigpio-master -o ./build/$@ ./build/$^ -lpigpiod_if2 -lrt -lpigpio
module: main.o timeUtils.o
	${CC} ${CFLAGS} -L/home/heliumj/Coding/lib/pigpio-master -o ./build/$@ ./build/*.o -lrt -lpigpio -lpaho-mqtt3c

main.o: ${SRC_PATH}/main.c
	${CC} ${CFLAGS} -c -o ${BUILD_PATH}/$@ $^ 

timeUtils.o: ${SRC_PATH}/timeUtils.c
	${CC} ${CFLAGS} -c -o ${BUILD_PATH}/$@ $^ 

clean:
	rm ${BUILD_PATH}/*.o
	rm ${BUILD_PATH}/module








#all: [name of executable rule] [any additional rules to zip or further build your final proj]


#[name of executable]: [all .o (or src files to compile into exec if not using .o princip.)]
#	${CC} ${CFLAGS} -o ./Build/$@ ./Build/$^

##use one of every build rule below if you want to 
##intermediately compile to .o first
## serialRead.o: serialRead.c
## 	${CC} ${CFLAGS} -c -o ./build/$@ $^


## removes all .o's, the generated zip, and all exe's. 
#clean: 
##	 rm -rf *.o lab2.zip *.exe headers_timestamp tags *.vs *.h
#	 rm -rf ./Build/*.o ./Build/[any executable files]




#SRC_FILES = ./src/*
#SRC_LOC = ./src

#OPENCV_HEADER_LOC = -I/usr/include/opencv4 
#OPENCV_LIB_LOC = -L/usr/lib
#OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_arucoall: arucoScanner

#GTK_HEADER_LOC = -I/usr/include/gtk-3.0
#GDK_HEADER_LOC = -I/user/include/gdk-pixbuf

#arucoScanner:
##	${CC} -o ./bin/arucoScanner ${CFLAGS} ${SRC_LOC}/arucoScanner.cpp ${OPENCV_HEADER_LOC} ${OPENCV_LIB_LOC} ${GTK_HEADER_LOC} ${GDK_HEADER_LOC} -I/usr/include/glib-2.0 -I/usr/include ${OPENCV_LIBS}
#	${CC} -o ./bin/arucoScanner ${CFLAGS} ${SRC_LOC}/arucoScanner.cpp `pkg-config --cflags --libs opencv4 gtk+-3.0`


#window: ./src/window.cpp
#	${CC} -o ./bin/window.exe ${CFLAGS} ${SRC_LOC}/window.cpp

#circle:	./src/circle.cpp
#	${CC} -o ./bin/circle.exe ${CFLAGS} ${SRC_LOC}/circle.cpp

#clean:
#	rm ./bin/*

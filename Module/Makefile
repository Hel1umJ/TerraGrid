######################################################################
# Global variables.
######################################################################
#Compiler; gcc (C), g++ (C++)
CC=g++
#LD is for any dynamically linked libs (libs derrived from .so files)
LD=ld
WARNS=-Wall -pedantic -Wextra
#g3: adds debugging info
#Include C or CPP flags based on what lang you're compiling
CFLAGS=-g3 -std=gnu11 ${WARNS}
CPPFLAGS = -g3 -std=c++14 ${WARNS}
#Include next line if you're using any standard libraries you want to link
#STD_LIBS= -lpthread -lrt

#target = [execName] (and then use this variable in your build rules)

# hello is an executable I want to build, the rest are handy things
#all: [finalExecutable] [any other final build commands]
all: [name of executable rule] [any additional rules to zip or further build your final proj]


[name of executable]: [all .o (or src files to compile into exec if not using .o princip.)]
	${CC} ${CFLAGS} -o ./Build/$@ ./Build/$^

#use one of every build rule below if you want to 
#intermediately compile to .o first
# serialRead.o: serialRead.c
# 	${CC} ${CFLAGS} -c -o ./build/$@ $^


#This next rule is champion's black magic to generate all .o
# This is our master compiler rule to generate .o files.
# It needs all 4 warnings (see WARNS variable defined above)
#%.o:%.c #*.h
#	${CC} ${CFLAGS} -c $< -o $@

#Include a *.h in the requirements for any programs with header files
zip: headers.awk headers.sh headers_timestamp Makefile README.txt tags *.c *.h
	zip lab2.zip headers.awk headers.sh Makefile README.txt *.c

# removes all .o's, the generated zip, and all exe's. 
clean: 
#	 rm -rf *.o lab2.zip *.exe headers_timestamp tags *.vs *.h
	 rm -rf ./Build/*.o ./Build/[any executable files]






[Honda Makefile]: manually include and specify source locations 
CC = g++
#Win g++ compiler: x86_64-w64-mingw32-g++, STD linux: g++, 
CFLAGS = -g3 -Wall -Wpedantic -Wextra -std=c++11
SRC_FILES = ./src/*
SRC_LOC = ./src

OPENCV_HEADER_LOC = -I/usr/include/opencv4 
OPENCV_LIB_LOC = -L/usr/lib
OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_arucoall: arucoScanner

GTK_HEADER_LOC = -I/usr/include/gtk-3.0
GDK_HEADER_LOC = -I/user/include/gdk-pixbuf

arucoScanner:
#	${CC} -o ./bin/arucoScanner ${CFLAGS} ${SRC_LOC}/arucoScanner.cpp ${OPENCV_HEADER_LOC} ${OPENCV_LIB_LOC} ${GTK_HEADER_LOC} ${GDK_HEADER_LOC} -I/usr/include/glib-2.0 -I/usr/include ${OPENCV_LIBS}
	${CC} -o ./bin/arucoScanner ${CFLAGS} ${SRC_LOC}/arucoScanner.cpp `pkg-config --cflags --libs opencv4 gtk+-3.0`


window: ./src/window.cpp
	${CC} -o ./bin/window.exe ${CFLAGS} ${SRC_LOC}/window.cpp

circle:	./src/circle.cpp
	${CC} -o ./bin/circle.exe ${CFLAGS} ${SRC_LOC}/circle.cpp

clean:
	rm ./bin/*

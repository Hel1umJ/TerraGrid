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



Using external libs (repeat?):
    Compilation flags:
        1. Include Directories: Use the -I flag to add include directories to your compiler command. This tells the compiler where to find the header files.

        2. Library Directories: Use the -L flag in your linker command to specify the directory where the linker can find the .so files for symbol resolution.

        3. Link Libraries: Use the -l flag to link against the specific OpenCV libraries you need. The names of these libraries typically follow the opencv_<module> pattern.

	-I (Include Path):
        Specifies a directory where the compiler should look for header files.
        If you use #include "somefile.h", the compiler will look for somefile.h in the directories specified by -I before looking in the default directories (like /usr/include).
        Example: gcc -I/path/to/headers myfile.c -o myprogram
        This command tells the compiler to look in /path/to/headers for any header files used in myfile.c.
		-Note: compiler implicitly searches /usr/include (equivelant to compiling with -I /usr/include), and don't need
		to specify if lib headers are placed in this location.

    -L (Library Path):
        Specifies a directory where the linker should look for libraries during the linking stage.
        It tells the linker where to find the library files (such as .so files on Linux or .dll files on Windows) that are not in the standard library paths.
        Example: gcc -L/path/to/libs myfile.o -o myprogram -lmylib
        This command tells the linker to look in /path/to/libs for libraries.
		-Note: Linker implicitly searches in /lib and /usr/lib (equiveland to compiling with -L /lib and -L /usr/lib), 
		and dont need to specify if compiled code are in these locations.

    -l (Link Library):
        Specifies a library to link against during the linking stage.
        The linker will look for a library file named lib<name>.so (or lib<name>.a for static libraries).
        Example: gcc myfile.o -o myprogram -lm
        This tells the linker to link against the math library, which is typically named libm.so.

	Putting It All Together

	Suppose you have a C++ project with source code in main.cpp that depends on a custom library (mylib) and a standard library (e.g., the math library libm). The headers for mylib are in ./include, and the compiled library (libmylib.so) is in ./lib. To compile and link this project, you might use a command like this:

	bash

	g++ -I./include -L./lib -o myprogram main.cpp -lmylib -lm

	Here’s what each part does:

		-I./include: Tells the compiler to look for header files in the ./include directory.
		-L./lib: Tells the linker to look in the ./lib directory for libraries.
		-o myprogram: Specifies the name of the output executable (myprogram).
		main.cpp: The source file to compile.
		-lmylib: Links against libmylib.so found in the ./lib directory.
		-lm: Links against the standard math library.




	Compiling: 
		1. Use Compiled binaries + headers: Use -I and -L flags.
		2. Use compiled library binaries (.a or .dll) + header files: Use -L and -l flags for every lib you want to use. 
			-Note: to do this, you have to specially compile into a lib file (.a or .so) to denote your code as library files.
			    Compiling Source Files:
					1. Sttaic libraries (.a)
						First, you compile the source files into object files (.o files) as usual.
							Example: gcc -c file1.c -o file1.o and gcc -c file2.c -o file2.o
						Creating the Static Library:
							Use the ar (archive) tool to package the object files into a static library.
							Example: ar rcs libmylib.a file1.o file2.o
							Here, libmylib.a is the static library file. The lib prefix is a convention that the linker expects when you use the -l flag. The rcs options stand for "replace or add files," "create if not already existing," and "write an index to the archive."
						Using the Static Library:
							To link against this static library, you use the -l flag with the library name without the lib prefix and the .a extension.
							Example: gcc main.o -L. -lmylib -o myprogram
							This command tells the linker to look in the current directory (-L.) for a file named libmylib.a and link it with main.o to create myprogram.

					2. Dynamic Libraries (.so files on Unix-like systems, .dll on Windows):

						Compiling Source Files:
							Similar to static libraries, first compile the source files into object files.
							Example: gcc -fPIC -c file1.c -o file1.o and gcc -fPIC -c file2.c -o file2.o
							The -fPIC flag is important for dynamic libraries as it generates position-independent code, which is necessary for shared libraries.
						Creating the Dynamic Library:
							Use the gcc command to link the object files into a shared library (.so file).
							Example: gcc -shared -o libmylib.so file1.o file2.o
							The -shared flag tells the compiler to produce a shared (dynamic) library, and libmylib.so is the resulting file.
						Using the Dynamic Library:
							To link against this dynamic library, you again use the -l flag with the library name without the lib prefix and the .so extension.
							Example: gcc main.o -L. -lmylib -o myprogram
							This command tells the linker to look in the current directory (-L.) for a file named libmylib.so and link it with main.o to create myprogram.
							When running the program, the dynamic linker needs to find the shared library. You can set the LD_LIBRARY_PATH environment variable to include the directory containing libmylib.so, or you can install the library in a standard location like /usr/lib or /usr/local/lib.


			-Note: alternatively you could just use 
				--libs [all lib names seperated by space] instead of prefacing them all with their own -l




	-Compiling addition: 
	-C++ linker auto looks in common src dir; to manually link, 1. Use -I,-L, amd -l for each indiv. lib. (and if lib in common default place OR addex to path, dont have to explocotly link amd let linker auto-search)
		-Note: linker recursively searches every specified directory
		-Note: you have to use -I, -L, and -l flags for every single lib that you use
		-Note: you can alternatively just use package config instead of doing it all manually.

	Default linux lib locations: 
		-Compiled libraries (.o): /lib or /usr/lib
		-Header files: /usr/include

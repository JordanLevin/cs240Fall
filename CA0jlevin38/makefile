#
# Specifiy the target
all:	Levin_Jordan_jlevin38_Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Levin_Jordan_jlevin38_Hello:	Levin_Jordan_jlevin38_Hello.o Hello_Class.o
	g++  Levin_Jordan_jlevin38_Hello.o Hello_Class.o  -o Levin_Jordan_jlevin38_Hello.exe

Hello_Class.o: Hello_Class.cpp Hello_Class.h
	g++ -c Hello_Class.cpp
# Specify how the object files should be created from source files
Levin_Jordan_jlevin38_Hello.o:	Levin_Jordan_jlevin38_Hello.cpp
	g++ -c Levin_Jordan_jlevin38_Hello.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Levin_Jordan_jlevin38_Hello.exe


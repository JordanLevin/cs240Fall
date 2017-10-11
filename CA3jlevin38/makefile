FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++17

all: main FBLPost FBLUser
	g++ $(FLAGS) main.o FBLPost.o FBLUser.o -o main

main: main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o

FBLPost: FBLPost.cpp FBLPost.h
	g++ $(FLAGS) -c FBLPost.cpp -o FBLPost.o

FBLUser: FBLUser.cpp FBLUser.h
	g++ $(FLAGS) -c FBLUser.cpp -o FBLUser.o

clean:
	rm -f *.o main

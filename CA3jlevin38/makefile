FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++17
CLFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++1z

all: main FBLPost FBLUser
	g++ $(FLAGS) main.o FBLPost.o FBLUser.o -o main

main: main.cpp
	g++ $(FLAGS) -c main.cpp -o main.o

FBLPost: FBLPost.cpp FBLPost.h
	g++ $(FLAGS) -c FBLPost.cpp -o FBLPost.o

FBLUser: FBLUser.cpp FBLUser.h
	g++ $(FLAGS) -c FBLUser.cpp -o FBLUser.o

clang: main_clang FBLPost_clang FBLUser_clang
	clang $(CLFLAGS) main.o FBLPost.o FBLUser.o -o main

main_clang: main.cpp
	clang $(CLFLAGS) -c main.cpp -o main.o

FBLPost_clang: FBLPost.cpp FBLPost.h
	clang $(CLFLAGS) -c FBLPost.cpp -o FBLPost.o

FBLUser_clang: FBLUser.cpp FBLUser.h
	clang $(CLFLAGS) -c FBLUser.cpp -o FBLUser.o

clean:
	rm -f *.o main

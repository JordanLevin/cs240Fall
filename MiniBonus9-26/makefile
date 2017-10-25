FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++17

all: ExpandableList

ExpandableList: ExpandableList.h main.o 
	g++ $(FLAGS) main.o -o main

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

clean:
	rm -f *.o main

run: all
	./main

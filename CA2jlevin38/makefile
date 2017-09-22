FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++17

all: donor

donor: Donor.o CA1.o 
	g++ $(FLAGS) Donor.o CA1.o -o donor

donor.o: Donor.cpp Donor.h
	g++ $(FLAGS) -c Donor.cpp 

CA1.o: CA1.cpp
	g++ $(FLAGS) -c CA1.cpp

clean:
	rm -f *.o donor

run: all
	./donor

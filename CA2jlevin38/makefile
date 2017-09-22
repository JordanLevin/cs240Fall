FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++17

all: Donor

Donor: Donor.o DonorDatabase.o CA1.o 
	g++ $(FLAGS) Donor.o DonorDatabase.o CA1.o -o donor

Donor.o: Donor.cpp Donor.h
	g++ $(FLAGS) -c Donor.cpp 

DonorDatabase.o: DonorDatabase.cpp DonorDatabase.h
	g++ $(FLAGS) -c DonorDatabase.cpp 

CA1.o: CA1.cpp
	g++ $(FLAGS) -c CA1.cpp

clean:
	rm -f *.o donor

run: all
	./donor

FLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++17

all: Donor

Donor: Donor.o DonorDatabase.o CA2.o CheckInput.o 
	g++ $(FLAGS) Donor.o DonorDatabase.o CA2.o CheckInput.o -o donor

Donor.o: Donor.cpp Donor.h
	g++ $(FLAGS) -c Donor.cpp 

DonorDatabase.o: DonorDatabase.cpp DonorDatabase.h
	g++ $(FLAGS) -c DonorDatabase.cpp 

CheckInput.o: CheckInput.h CheckInput.cpp
	g++ $(FLAGS) -c CheckInput.cpp

CA2.o: CA2.cpp
	g++ $(FLAGS) -c CA2.cpp

clean:
	rm -f *.o donor

run: all
	./donor

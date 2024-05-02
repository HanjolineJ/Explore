CXXFLAGS = -Wall -g -std=c++11

all: Finaltrial

# Object files
intro.o: intro.cpp map.h fight.h character.h
	g++ $(CXXFLAGS) -c intro.cpp

map.o: map.cpp map.h
	g++ $(CXXFLAGS) -c map.cpp

fight.o: fight.cpp fight.h character.h
	g++ $(CXXFLAGS) -c fight.cpp

character.o: character.cpp character.h
	g++ $(CXXFLAGS) -c character.cpp

# Main executable
Finaltrial: intro.o map.o fight.o character.o
	g++ $(CXXFLAGS) -o Finaltrial intro.o map.o fight.o character.o

# Clean the build directory
clean:
	@rm -f *.o Finaltrial


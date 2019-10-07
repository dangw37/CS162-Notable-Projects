# Project3Main makefile
# Author: William Dang
# Date: 8/4/2019

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

HEADERS = Barbarian.hpp BlueMen.hpp Character.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp
OBJECTS = Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o main.o


all: ${OBJECTS} ${HEADERS}
	g++ $(CXXFLAGS) ${OBJECTS} -o Project3Main

Barbarian.o: Barbarian.cpp Barbarian.hpp Character.hpp
	g++ $(CXXFLAGS) -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp Character.hpp
	g++ $(CXXFLAGS) -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp Character.hpp
	g++ $(CXXFLAGS) -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp Character.hpp
	g++ $(CXXFLAGS) -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp Character.hpp
	g++ $(CXXFLAGS) -c Vampire.cpp

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o Project3Main
	

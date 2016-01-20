#Date: 9/25/2015
#Description: This is my makefile for Lab 1

all: roll

roll: Game.o Die.o LoadedDie.o
	g++ Game.o Die.o LoadedDie.o -o GameOfWar

main.o: Game.cpp
	g++ -c Game.cpp

Die.o: Die.cpp
	g++ -c Die.cpp

LoadedDie.o: LoadedDie.cpp
	g++ -c LoadedDie.cpp

clean:
	rm *o GameOfWar

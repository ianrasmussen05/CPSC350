# A simple Makefile for CPSC 350
# Assumes the following directory hierarchy:
# Assignment 3



EXECUTABLE := TestStack

SOURCES := *.cpp

INCLUDES := -I ../include
EXT := out
CC := g++

all:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)

realclean:
	find . -type f -name "*.o" -exec rm '{}' \;
	find . -type f -name "*.exe" -exec rm '{}' \;
	find . -type f -name "*.out" -exec rm '{}' \;

# this line required by make - don't delete

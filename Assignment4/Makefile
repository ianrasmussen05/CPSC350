# I used this to link each class of .cpp and .h into .o and compile it all as
# one executable
# Assumes the following directory hierarchy:
# Assignment 4


EXECUTABLE := OfficeSimulation

SOURCES := *.cpp

INCLUDES := -I .
EXT := out
CC := g++

# -Wall checks for any warnings
CFLAGS  := -g -Wall

# typing 'make' will invoke the first target entry in the file
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
default: $(EXECUTABLE)

# To create the executable file count we need the object files
# Student.o, Window.o, Simulation.o, and main.o:
$(EXECUTABLE):   Student.o Window.o Simulation.o main.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE)  Student.o Window.o Simulation.o main.o


# To create the object file Student.o, we need the source files
# Student.cpp, Student.h:
Student.o: Student.cpp Student.h
	$(CC) $(CFLAGS) -c Student.cpp

# To create the object file Window.o, we need the source files
# WIndow.cpp, Window.h, Student.cpp, and Student.h:
Window.o: Window.cpp Window.h Student.cpp Student.h
	$(CC) $(CFLAGS) -c Window.cpp

# To create the object file main.o, we need the source files
# main.cpp, GenStack.cpp, GenStack.h, SyntaxCheck.cpp, and SyntaxCheck.h:
Simulation.o: Simulation.cpp Simulation.h ListNode.h LinkedList.h Queue.h Student.cpp Student.h Window.cpp Window.h
	$(CC) $(CFLAGS) -c Simulation.cpp

# To create the object file main.o, we need the source files
# main.cpp, ListNode.h, LinkedList.h, Queue.h, Student.cpp, Student.h, Window.cpp, Window.h, Simulation.cpp, and Simulation.h:
main.o: main.cpp ListNode.h LinkedList.h Queue.h Student.cpp Student.h Window.cpp Window.h Simulation.cpp Simulation.h
	$(CC) $(CFLAGS) -c main.cpp

# Removes any files that end in .ghc and .o to clean the folder
clean:
	rm $(EXECUTABLE) *.gch *.o
# this line required by make - don't delete

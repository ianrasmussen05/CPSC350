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
# GenStack.o, SyntaxCheck.o, and main.o:
$(EXECUTABLE):   Student.o Window.o Simulation.o main.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE)  Student.o Window.o Simulation.o main.o

# To create the object file GenStack.o, we need the source files
# GenStack.cpp and GenStack.h:

# To create the object file SyntaxCheck.o, we need the source
# files SyntaxCheck.cpp, SyntaxCheck.h, and GenStack.h:
# Need GenStack.h in order to compile with the SyntaxCheck

Student.o: Student.cpp Student.h
	$(CC) $(CFLAGS) -c Student.cpp

Window.o: Window.cpp Window.h Student.cpp Student.h
	$(CC) $(CFLAGS) -c Window.cpp

Simulation.o: Simulation.cpp Simulation.h ListNode.h LinkedList.h Queue.h Student.cpp Student.h Window.cpp Window.h
	$(CC) $(CFLAGS) -c Simulation.cpp

# To create the object file main.o, we need the source files
# main.cpp, GenStack.cpp, GenStack.h, SyntaxCheck.cpp, and SyntaxCheck.h:
main.o: main.cpp ListNode.h LinkedList.h Queue.h Student.cpp Student.h Window.cpp Window.h Simulation.cpp Simulation.h
	$(CC) $(CFLAGS) -c main.cpp

# Removes any files that end in .o to clean the folder
clean:
	rm $(EXECUTABLE) *.gch *.o
# this line required by make - don't delete

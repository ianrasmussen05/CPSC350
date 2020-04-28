# I used this to link each class of .cpp and .h into .o and compile it all as
# one executable
# Assumes the following directory hierarchy:
# Assignment 5


EXECUTABLE := Database

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
# Student.o, Faculty.o, Simulation.o, and main.o:
$(EXECUTABLE):   Student.o Faculty.o Simulation.o main.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE)  Student.o Faculty.o Simulation.o main.o


# To create the object file Student.o, we need the source files
# Student.cpp, Student.h:
Student.o: Student.cpp Student.h
	$(CC) $(CFLAGS) -c Student.cpp

# To create the object file Window.o, we need the source files
# Faculty.cpp, Faculty.h:
Faculty.o: Faculty.cpp Faculty.h
	$(CC) $(CFLAGS) -c Faculty.cpp

# To create the object file main.o, we need the source files
# Simulation.cpp, Simulation.h:
Simulation.o: Simulation.cpp Simulation.h
	$(CC) $(CFLAGS) -c Simulation.cpp

# To create the object file main.o, we need the source files
# main.cpp, ListNode.h, LinkedList.h, Queue.h, Student.cpp, Student.h, Window.cpp, Window.h, Simulation.cpp, and Simulation.h:
main.o: main.cpp TreeNode.h BinarySearchTree.h Student.cpp Student.h Faculty.cpp Faculty.h Simulation.cpp Simulation.h
	$(CC) $(CFLAGS) -c main.cpp

# Removes any files that end in .ghc and .o to clean the folder
clean:
	rm $(EXECUTABLE) *.gch *.o *.out
# this line required by make - don't delete

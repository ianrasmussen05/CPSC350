# I used this to link each class of .cpp and .h into .o and compile it all as
# one executable
# Assumes the following directory hierarchy:
# Assignment 3


EXECUTABLE := TestStack

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
$(EXECUTABLE):  GenStack.o SyntaxCheck.o main.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) GenStack.o SyntaxCheck.o main.o

# To create the object file GenStack.o, we need the source files
# GenStack.cpp and GenStack.h:
GenStack.o:  GenStack.cpp GenStack.h
	$(CC) $(CFLAGS) -c GenStack.cpp

# To create the object file SyntaxCheck.o, we need the source
# files SyntaxCheck.cpp, SyntaxCheck.h, and GenStack.h:
# Need GenStack.h in order to compile with the SyntaxCheck
SyntaxCheck.o:  SyntaxCheck.cpp SyntaxCheck.h GenStack.h
	$(CC) $(CFLAGS) -c SyntaxCheck.cpp

# To create the object file main.o, we need the source files
# main.cpp, GenStack.cpp, GenStack.h, SyntaxCheck.cpp, and SyntaxCheck.h:
main.o: main.cpp GenStack.cpp GenStack.h SyntaxCheck.cpp SyntaxCheck.h
	$(CC) $(CFLAGS) -c main.cpp

# Removes any files that end in .o to clean the folder
clean:
	rm $(EXECUTABLE) *.o
# this line required by make - don't delete

// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 3
// GenStack.h

// It is bad practice to have the includes inside the header files, so I went with
// the 'if not defined' and 'define' operations to check if the file is defined previous
// to it being compiled
// https://www.cprogramming.com/reference/preprocessor/ifndef.html
#ifndef _GENSTACK_H
#define _GENSTACK_H


template <typename T>
class GenStack // Based on the Last-in, First-out concept
{
  private:
    // No private variables needed

  public:
    GenStack(); // The default constructor
    GenStack(int maxSize); // Overloaded constructor
    ~GenStack(); // Destructor

    void push(T data); // Pushes value at top of stack
    T pop(); // Returns and removes the top value of stack
    T peek(); // Returns teh top value of stack

    bool isFull(); // Checks if stack is full
    bool isEmpty(); // Checks if stack is empty

    int mSize; // The integer representing the size of the stack
    int top; // The integer that represents the top of the stack

    T *myStack; // A pointer to a value that will be determined based on set value, turned into an array
};

// This is how you end the #define operation above to let the compiler know the
// class has ended
#endif

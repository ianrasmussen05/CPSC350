// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 3
// GenStack.cpp

// This is the file where I attempted to have the template class have its own .cpp

/*
#include "GenStack.h"

// The default constructor setting a type name for an array of 64
template <typename T>
GenStack<T>::GenStack()
{
  myStack = new T[64];
  mSize = 64;
  top = -1;
}

// Overloaded constructor that sets the size of the array for a type name
template <typename T>
GenStack<T>::GenStack(int maxSize)
{
  myStack = new T[maxSize];
  mSize = maxSize;
  top = -1;
}

// Destructor that destroys the pointer myStack
template <typename T>
GenStack<T>::~GenStack()
{
  delete []myStack;
}

// This function pushes a variable of a given type to the top of the stack
template <typename T>
void GenStack<T>::push(T data)
{
  // Must check to see if the array is full before adding it to the array
  if (isFull() == true)
  {
    cout << "The stack is full" << endl;
    exit(1);
  }

  myStack[++top] = data;
}

// This function returns the value at the top of the stack, then changes the top position
template <typename T>
T GenStack<T>::pop()
{
  // Must check if the array is empty because you can't pop a null value
  try
  {
    if (isEmpty() == true) throw exception();
  }
  catch (exception e)
  {
    cout << "The stack is empty" << endl;

    return myStack[0];
  }

  return myStack[top--]; // Changes to the next value of the stack; "the value bellow top"
}

// This function takes a look at the top of the stack, without changing the top position
template <typename T>
T GenStack<T>::peek()
{
  if (isEmpty() == true)
  {
    cout << "The stack is empty" << endl;

    return myStack[0];
  }

  return myStack[top];
}

// Checks to see if the array set if full
template <typename T>
bool GenStack<T>::isFull()
{
  return (top == mSize - 1);
}

// Checks to see if the array set is empty
template <typename T>
bool GenStack<T>::isEmpty()
{
  return (top == -1);
}
*/

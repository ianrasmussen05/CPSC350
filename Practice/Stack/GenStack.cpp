#include "GenStack.h"

// Default consturctor
GenStack::GenStack()
{
  myArray = new char[128];
  mSize = 128;
  top = -1;
}

// Overloaded consturctor
GenStack::GenStack(int maxSize)
{
  myArray = new char[maxSize];
  mSize = maxSize;
  top = -1;
}

// Destructor
GenStack::~GenStack()
{
  delete []myArray;
}

void GenStack::push(char data)
{
  // check if full before inserting
  if (isFull())
  {
    cout << "The array is full..." << endl;
    exit(1);
  }

  myArray[++top] = data;
}

char GenStack::pop()
{
  // check if empty before proceeding to remove
  if (isEmpty())
  {
    cout << "The array is empty..." << endl;
    exit(1);
  }

  return myArray[top--];
}

char GenStack::peek()
{
  // check if empty before proceeding to remove
  if (isEmpty())
  {
    cout << "The array is empty..." << endl;
    return 1;
  }

  return myArray[top];
}

bool GenStack::isFull()
{
  return (top == mSize-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}

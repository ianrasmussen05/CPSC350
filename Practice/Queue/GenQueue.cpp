#include "GenQueue.h"

// Default consturctor
GenQueue::GenQueue()
{
  myArray = new char[128];
  mSize = 128;
  front = 0;
  rear = -1;
  numElements = 0;
}

// Overloaded consturctor
GenQueue::GenQueue(int maxSize)
{
  myArray = new char[maxSize];
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

// Destructor
GenQueue::~GenQueue()
{
  delete []myArray;
}

void GenQueue::insert(char data)
{
  myArray[++rear] = data;
  ++numElements;
}

char GenQueue::remove()
{
  char c = '\0';
  c = myArray[front];
  ++front;
  --numElements;

  return c;
}

char GenQueue::peek()
{
  return myArray[front];
}

bool GenQueue::isFull()
{
  return (numElements == mSize);
}

bool GenQueue::isEmpty()
{
  return (numElements == 0);
}

int GenQueue::getSize()
{
  return numElements;
}

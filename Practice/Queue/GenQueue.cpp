#include "GenQueue.h"

// Overloaded consturctor
GenQueue::GenQueue(int maxSize)
{
  myArray = new char[maxSize];
  mSize = maxSize;
  top = 0;
  front = 0;
}

// Default consturctor
GenQueue::GenQueue()
{
  myArray = new char[128];
  mSize = 128;
  top = 0;
  front = 0;
}

// Destructor
GenQueue::~GenQueue()
{
  delete []myArray;
  cout << "Object Deleted" << endl;
}

void GenQueue::push(char data)
{
  // check if full before inserting
  if (isFull())
  {
    cout << "The array is full..." << endl;
    exit(1);
  }

  myArray[top++] = data;
}

char GenQueue::pop()
{
  // check if empty before proceeding to remove
  if (isEmpty())
  {
    cout << "The array is empty..." << endl;
    exit(1);
  }

  return myArray[front++];
}

char GenQueue::peek()
{
  // check if empty before proceeding to remove
  if (isEmpty())
  {
    cout << "The array is empty..." << endl;
    return 1;
  }

  return myArray[front];
}

bool GenQueue::isFull()
{
  return (top == mSize-1);
}

bool GenQueue::isEmpty()
{
  return (top == -1);
}

// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Queue.h

#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <string>

using namespace std;

#include "LinkedList.h"

// A linked Queue class using a template abstract class

template <typename T>
class Queue
{
  private:
    // No private variables

  public:
    Queue(); // Consturctor
    Queue(int maxSize); // Overloaded constructor
    ~Queue(); // Destructor

    void insert(T value); // Insert function that inserts in the back
    T remove(); // Removes and returns the front value
    T peek(); // Returns the front value

    bool isFull(); // Checks if Queue is full (Not needed for this assignment)
    bool isEmpty(); // Checks if Queue is empty

    int getSize(); // Gets the size of the Queue

    int size; // integer representing size of queue
    int numElements;

    LinkedList<T> *myArray; // A pointer of a linked list
};

#endif


template <typename T>
Queue<T>::Queue()
{
  myArray = new LinkedList<T>();
  size = 0;
  numElements = 0;
}

template <typename T>
Queue<T>::Queue(int maxSize)
{
  myArray = new LinkedList<T>();
  size = maxSize;
  numElements = 0;
}

template <typename T>
Queue<T>::~Queue()
{
  delete myArray;
}

template <typename T>
void Queue<T>::insert(T value)
{
  // Inserts at the back of the list using the insertBack() function in the linked list class
  ++numElements;
  myArray->insertBack(value);
}

template <typename T>
T Queue<T>::remove()
{
  // Removes from the front of the queue using the removeFront() function in the linked list class
  --numElements;
  return myArray->removeFront();
}

template <typename T>
T Queue<T>::peek()
{
  // Return data from front of the linked list
  return myArray->front->data;
}

template <typename T>
bool Queue<T>::isEmpty()
{
  // Gets the size of list and compares it to zero, return True or false
  return (myArray->getSize() == 0);
}

template <typename T>
bool Queue<T>::isFull()
{
  return (numElements == myArray->getSize());
}

template <typename T>
int Queue<T>::getSize()
{
  // Calls onto the getSize() of the linked list 
  return myArray->getSize();
}

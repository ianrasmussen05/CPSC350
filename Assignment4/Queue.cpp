// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Queue.cpp

#include <iostream>
#include <string>

using namespace std;

#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
  myArray = new T[128];
  size = 128;
  front = 0;
  rear = -1;
  numElements = 0;
}

template <typename T>
Queue<T>::Queue(int maxSize)
{
  myArray = new T[maxSize];
  size = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

template <typename T>
Queue<T>::~Queue()
{
  delete []myArray;
}

template <typename T>
void Queue<T>::insert(T data)
{
  myArray[++rear] = data;
  ++numElements;
}

template <typename T>
T Queue<T>::remove()
{
  T temp = 0;
  temp = myArray[front];
  ++front;
  --numElements;

  return temp;
}

template <typename T>
T Queue<T>::peek()
{
  return myArray[front];
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return (numElements == 0);
}

template <typename T>
bool Queue<T>::isFull()
{
  return (numElements == size);
}

template <typename T>
int Queue<T>::getSize()
{
  return numElements;
}

template class Queue<int>;

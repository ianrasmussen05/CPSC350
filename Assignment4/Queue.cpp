// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Queue.cpp

#include <iostream>
#include <string>

using namespace std;

#include "ListNode.h"
#include "LinkedList.h"
#include "Queue.h"

template <typename T>
Queue<T>::Queue()
{
  myArray = new LinkedList<T>();
  /*
  size = 0;
  front = 0;
  rear = -1;
  */
  numElements = 0;
}

template <typename T>
Queue<T>::Queue(int maxSize)
{
  myArray = new LinkedList<T>();
  /*
  size = maxSize;
  front = 0;
  rear = -1;
  */
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
  myArray->insertBack(value);
  ++numElements;
}

template <typename T>
T Queue<T>::remove()
{
  ListNode<T> *temp = new ListNode<T>();
  temp = myArray->front;
  myArray->front = myArray->front->next;
  --numElements;

  return temp->data;
}

template <typename T>
T Queue<T>::peek()
{
  return myArray->front->data;
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return (numElements == 0);
}

template <typename T>
bool Queue<T>::isFull()
{
  return (numElements == myArray->size);
}

template <typename T>
int Queue<T>::getSize()
{
  return numElements;
}

template class Queue<int>;

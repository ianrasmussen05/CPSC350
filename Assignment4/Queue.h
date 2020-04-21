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



template <typename T>
class Queue
{
  private:
    // No private variables

  public:
    Queue();
    Queue(int maxSize);
    ~Queue();

    void insert(T value);
    T remove();
    T peek();

    bool isFull();
    bool isEmpty();

    int getSize();

    int size;
    int numElements;

    LinkedList<T> *myArray;
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

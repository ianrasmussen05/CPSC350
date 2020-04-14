// Ian Rasmussen 
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// Queue.h

#ifndef _QUEUE_H
#define _QUEUE_H

template <typename T>
class Queue
{
  private:
    // No private variables

  public:
    Queue();
    Queue(int maxSize);
    ~Queue();

    void insert(T data);
    T remove();
    T peek();

    bool isFull();
    bool isEmpty();

    int getSize();

    int size;
    int front;
    int rear;
    int numElements;

    T *myArray;
};

#endif

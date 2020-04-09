#ifndef _QUEUE_H
#define _QUEUE_H

class Queue
{
  private:
    // No private variables

  public:
    Queue();
    Queue(int maxSize);
    ~Queue();

    void insert(int data);
    char remove();
    char peek();

    bool isFull();
    bool isEmpty();

    int getSize();

    int size;
    int front;
    int rear;
    int numElements;

    char *myArray;
}

#endif

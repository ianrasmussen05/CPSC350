// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// LinkedList.h

// This is the implementation of the doubly linked list

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <typename T>
class LinkedList
{
  private:
    ListNode<T> *front;
    ListNode<T> *last;
    int size;

  public:
    LinkedList();
    ~LinkedList();

    void insertFront(T data);
    void insertBack(T data);
    T removeFront();
    T remove(T val);
    T search(T val);
    T removeAtPosition(int position);

    int getSize();
    bool isEmpty();
    void printList();
};

#endif

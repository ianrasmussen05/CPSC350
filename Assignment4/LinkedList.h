// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// LinkedList.h

// This is the implementation of the double linked list

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

class LinkedList
{
  private:
    ListNode *front;
    ListNode *last;
    int size;

  public:
    LinkedList();
    ~LinkedList();

    // Where the member functions will go


    int getSize();
    bool isEmpty();
    void printList();
}

#endif

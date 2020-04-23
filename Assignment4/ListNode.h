// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// ListNode.h

#ifndef _LISTNODE_H
#define _LISTNODE_H

#include <iostream>
#include <string>

using namespace std;

// Just a basic list node class using template abstract class

template <typename T>
class ListNode
{
  private:
    // No private variables

  public:
    ListNode(); // Default constructor
    ListNode(T d); // Overloaded constructor
    ~ListNode(); // Destructor

    T data; // A template variable of data
    ListNode<T> *next; // Listnode for the left
    ListNode<T> *prev; // ListNode for the right
};

#endif


template <typename T>
ListNode<T>::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

template <typename T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

template <typename T>
ListNode<T>::~ListNode()
{
  delete next;
  delete prev;
}

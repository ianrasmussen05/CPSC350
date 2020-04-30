// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// ListNode.h

#ifndef _LISTNODE_H
#define _LISTNODE_H

template <typename T>
class ListNode
{
  public:
    T data;
    ListNode<T> *next;

    ListNode(); // Default constructor
    ListNode(T d); // Overloaded constructor
    ~ListNode(); // Destructor
};

#endif


template <typename T>
ListNode<T>::ListNode()
{
  data = 0;
  next = NULL;
}

template <typename T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL;
}

template <typename T>
ListNode<T>::~ListNode()
{
  delete next;
}

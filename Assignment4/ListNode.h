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



template <typename T>
class ListNode
{
  private:
    // No private variables

  public:
    ListNode();
    ListNode(T d);
    ~ListNode();

    T data;
    ListNode<T> *next;
    ListNode<T> *prev;
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

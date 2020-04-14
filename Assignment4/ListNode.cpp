// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// ListNode.cpp

#include <iostream>
#include <string>

using namespace std;

#include "ListNode.h"

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

template class ListNode<int>;

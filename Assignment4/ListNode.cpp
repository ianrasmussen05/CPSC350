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


ListNode::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

ListNode::ListNode(int d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

ListNode::~ListNode()
{
  delete next;
  delete prev;
}

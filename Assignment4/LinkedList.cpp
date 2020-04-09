// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// LinkedList.cpp

#include <iostream>
#include <string>

using namespace std;

#include "ListNode.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{
  size = 0;
  front = NULL;
  last = NULL;
}

LinkedList::~LinkedList()
{
  delete front;
  delete last;
}

int LinkedList::getSize()
{
  return size;
}

bool LinkedList::isEmpty()
{
  if (size == 0)
  {
    return true;
  }

  return false;
}

void LinkedList::printList()
{
  LinkedList *curr = front;

  if (isEmpty())
  {
    cout << "The list is empty" << endl;
    return;
  }

  while (curr != NULL)
  {
    cout << curr->data << endl;

    curr = curr->next;
  }
}

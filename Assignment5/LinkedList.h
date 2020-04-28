// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 5
// LinkedList.h

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

#include "ListNode.h"


template <typename T>
class LinkedList
{
  private:
    unsigned int size;
    ListNode<T> *front;

  public:
    LinkedList(); // Default constructor
    ~LinkedList(); // Destructor

    void insertFront(T data);
    int removeFront();
    int search(T value); // can return value or position of value
    int removeAtPosition(int position);

    unsigned int getSize();
    bool isEmpty();
    void printList();
};

#endif


template <typename T>
LinkedList<T>::LinkedList()
{
  front = NULL;
  size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //delete front;
}

template <typename T>
unsigned int LinkedList<T>::getSize()
{
  return size;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
  return (size == 0);
}

template <typename T>
void LinkedList<T>::printList()
{
  ListNode<T> *curr = front;

  while (curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <typename T>
void LinkedList<T>::insertFront(T d)
{
  ++size;
  ListNode<T> *node = new ListNode<T>(d);
  node->next = front;
  front = node;
}

template <typename T>
int LinkedList<T>::removeFront()
{
  T temp = front->data;
  ListNode<T> *ft = front;
  front = front->next;
  ft->next = NULL;
  delete ft;
  --size;

  return temp;
}

template <typename T>
int LinkedList<T>::search(T value)
{
  int position = -1;
  ListNode<T> *curr = front;

  while (curr != NULL)
  {
    // Iterate and attempt to find the value
    ++position;

    if (curr->data == value)
    {
      break;  // If i find it
    }
    else
    {
      curr = curr->next;
    }
  }

  if (curr == NULL)
  {
    position = -1; // We did not find the value
  }

  return position;
}

template <typename T>
int LinkedList<T>::removeAtPosition(int position)
{
  // error checking
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  // now lets loop until position
  while (idx != position)
  {
    ++idx;
    prev = curr;
    curr = curr->next;
    idx++;
  }

  // We found the position of the node to be deleted
  prev->next = curr->next;
  curr->next = NULL; // Delete the pointer to the next value
  T temp = curr->data;
  delete curr;
  size--;

  return temp;
}
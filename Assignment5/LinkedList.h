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

    void insertFront(T data); // Inserts a value in the front of the list
    int removeFront(); // Removes the front node
    int search(T value); // can return value or position of value
    int removeAtPosition(T position);

    unsigned int getSize(); // Returns the size
    ListNode<T> *getFront(); // Returns the front node
    bool isEmpty(); // Checks if the list is empty
    void printList(); // Prints list, one by one
};

#endif

// Default constructor
template <typename T>
LinkedList<T>::LinkedList()
{
  front = NULL;
  size = 0;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
  //delete front;
}

// Returns the size of list
template <typename T>
unsigned int LinkedList<T>::getSize()
{
  return size;
}

// Returns the front node of list
template <typename T>
ListNode<T> *LinkedList<T>::getFront()
{
  return front;
}

// Checks to see if the list is empty
template <typename T>
bool LinkedList<T>::isEmpty()
{
  return (size == 0);
}

// Prints the entire list, starting at front
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

// Insert a node to the front of the list
template <typename T>
void LinkedList<T>::insertFront(T d)
{
  ++size;
  ListNode<T> *node = new ListNode<T>(d);
  node->next = front;
  front = node;
}
 // Removes the node at the front of the list
template <typename T>
int LinkedList<T>::removeFront()
{
  T temp = front->data;
  ListNode<T> *ft = front;
  front = front->next;
  ft->next = NULL;
  delete ft;
  --size; // Size is less

  return temp;
}

// Searches to determine if the node is in the list, compares ID
template <typename T>
int LinkedList<T>::search(T value)
{
  int position = -1;
  ListNode<T> *curr = front;

  while (curr != NULL)
  {
    // Iterate and attempt to find the value
    ++position;

    if (curr->data->getID() == value->getID())
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

// Remove a node at the given position
template <typename T>
int LinkedList<T>::removeAtPosition(T position)
{
  // error checking
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  // now lets loop until position
  while (curr->data != position)
  {
    prev = curr;
    curr = curr->next;
  }

  // We found the position of the node to be deleted
  prev->next = curr->next;
  curr->next = NULL; // Delete the pointer to the next value
  T temp = curr->data;
  delete curr;
  size--;

  return temp;
}

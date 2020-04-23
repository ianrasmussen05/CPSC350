// Ian Rasmussen
// 2317200
// irasmussen@chapman.edu
// CPSC 350-01
// Assignment 4
// LinkedList.h

// This is the implementation of the doubly linked list

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

#include "ListNode.h"

// A basic doubly linked list class using template abstract classes

template <typename T>
class LinkedList
{
  private:
    // No private variables

  public:
    LinkedList(); // constructor
    ~LinkedList(); // Destructor

    void insertFront(T data); // Inserts a value at the front of the list
    void insertBack(T data); // Inserts a value at the back of the list
    T removeFront(); // Removes the value at the front of the list
    T remove(T val); // Removes a value in the list
    T search(T val); // Searches and returns the position in the list
    T removeAtPosition(int position); // Searches and returns the value at the position in the list

    int getSize(); // Returns size of list
    bool isEmpty(); // Checks if the list has any nodes
    void printList(); // Prints the list of nodes

    ListNode<T> *front; // A pointer to keep track of front node
    ListNode<T> *last; // A pointer to keep track of the last node
    int size; // Integer representing size of list
};

#endif



template <typename T>
LinkedList<T>::LinkedList()
{
  size = 0;
  front = NULL;
  last = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{

}

template <typename T>
void LinkedList<T>::insertFront(T data)
{
  ListNode<T> *node = new ListNode<T>(data); // create a node

  if (isEmpty()) // Checks if list is empty
  {
    last = node; // Replaces last position as node
  }
  else
  {
    front->prev = node; // Replaces node previous from front as node
    last->next = node; // Replaces node next from last node to the data
  }

  front = node; // Changes the front node to the input
  size++; // Update size
}

template <typename T>
void LinkedList<T>::insertBack(T data)
{
  ListNode<T> *node = new ListNode<T>(data);

  if (isEmpty())
  {
    front = node;
  }
  else
  {
    last->next = node;
    node->prev = last;
  }

  last = node; // Changes the last node to the input
  size++; // Update size
}

template <typename T>
T LinkedList<T>::removeFront()
{
  ListNode<T> *temp = front;

  if (temp->next == NULL)
  {
    last = NULL;
  }
  else
  {
    front->next->prev = NULL;
  }

  front = front->next;
  temp->next = NULL;
  T tmp = temp->data;

  delete temp;

  size--;
  return tmp;
}

template <typename T>
T LinkedList<T>::remove(T val)
{
  ListNode<T> *curr = front;

  while (curr->data != val)
  {
    curr = curr->next;

    if (curr == NULL)
    {
      return 0;
    }
  }

  if (curr == front)
  {
    front = curr->next;
  }
  else
  {
    curr->prev->next = curr->next;
  }

  if (curr == last)
  {
    last = curr->prev;
  }
  else
  {
    // node to deleted is not the front or back, its in between
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  T temp = curr->data;

  delete curr;
  size--;

  return temp;
}

template <typename T>
T LinkedList<T>::search(T val)
{
  int position = -1;
  ListNode<T> *curr = front;

  while (curr != NULL)
  {
    ++position;

    if (curr->data == val)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }

  if (curr == NULL)
  {
    position = -1;
  }

  delete curr;

  return position;
}

template <typename T>
T LinkedList<T>::removeAtPosition(int position)
{
  // error checking
  int posCounter = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  // now lets looop until position
  while (posCounter != position)
  {
    ++posCounter;
    prev = curr;
    curr = curr->next;
    posCounter++;
  }

  // We found the position of the node to be deleted
  prev->next = curr->next;
  curr->next = NULL; // Delete the pointer to the next value
  int temp = curr->data;

  delete curr;
  size--;

  return temp;
}

template <typename T>
int LinkedList<T>::getSize()
{
  return size;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
  if (size == 0)
  {
    return true;
  }

  return false;
}

template <typename T>
void LinkedList<T>::printList() // Iterates through the entire list and prints each node data
{
  ListNode<T> *curr = front;

  if (isEmpty()) // Must check if list is empty first
  {
    cout << "The list is empty" << endl;
    return;
  }

  // Iterates through the list and checks if value is not null
  while (curr != NULL)
  {
    cout << curr->data << endl; // Prints then goes to next value in list

    curr = curr->next;
  }

  delete curr;
}

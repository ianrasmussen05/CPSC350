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



template <typename T>
class LinkedList
{
  private:
    //ListNode<T> *front;
    //ListNode<T> *last;
    //int size;

  public:
    LinkedList();
    ~LinkedList();

    void insertFront(T data);
    void insertBack(T data);
    T removeFront();
    T remove(T val);
    T search(T val);
    T removeAtPosition(int position);

    int getSize();
    bool isEmpty();
    void printList();

    ListNode<T> *front;
    ListNode<T> *last;
    int size;
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
  ListNode<T> *node = new ListNode<T>(data);

  if (isEmpty())
  {
    last = node;
  }
  else
  {
    front->prev = node;
    last->next = node;
  }

  front = node;
  size++;
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

  last = node;
  size++;
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
void LinkedList<T>::printList()
{
  ListNode<T> *curr = front;

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

  delete curr;
}

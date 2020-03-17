#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
  front = NULL;
  back = NULL;
  size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
  // build some character
}

unsigned int DoublyLinkedList::getSize()
{
  return size;
}

bool DoublyLinkedList::isEmpty()
{
  return (size == 0);
}

void DoublyLinkedList::printList()
{
  ListNode *curr = front;

  while (curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

void DoublyLinkedList::insertFront(int d)
{
  ListNode *node = new ListNode(d);

  if (isEmpty())
  {
    back = node;
  }
  else
  {
    front->prev = node;
    node->next = front;
  }

  front = node;
  size++;
}

void DoublyLinkedList::insertBack(int d)
{
  ListNode *node = new ListNode(d);

  if (isEmpty())
  {
    front = node;
  }
  else
  {
    back->next = node;
    node->prev = back;
  }

  back = node;
  size++;
}

int DoublyLinkedList::removeFront()
{
  ListNode *temp = front;

  if (front->next == NULL)
  {
    // we have one node in the list
    back = NULL;
  }
  else
  {
    // There is more than one node in the list
    front->next->prev = NULL;
  }

  front = front->next;
  temp->next = NULL;
  int tmp = temp->data;

  delete temp;

  size--;
  return tmp;
}

// need to to find the value in the list before we can delete
// this functin does not take in a position as a parameter
int DoublyLinkedList::remove(int val)
{
  ListNode *curr = front;

  while (curr->data != val)
  {
    // Keep iterating until we find our value
    curr = curr->next;

    if (curr == NULL)
    {
      return 0; // might have to return 0
    }
  }

  // We found the value, now lets proceed to delete
  if (curr == front)
  {
    // check if node to be deleted is the front
    front = curr->next;
  }
  else
  {
    // node to deleted is not the front or back
    curr->prev->next = curr->next;
  }

  if (curr == back)
  {
    back = curr->prev;
  }
  else
  {
    // node to deleted is not the front or back, its in between
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  int temp = curr->data;
  delete curr;
  size--;

  return temp;
}

int DoublyLinkedList::search(int value)
{
  int position = -1;
  ListNode *curr = front;

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

int DoublyLinkedList::removeAtPosition(int position)
{
  // error checking
  int idx = 0;
  ListNode *curr = front;
  ListNode *prev = front;

  // now lets looop until position
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
  int temp = curr->data;
  delete curr;
  size--;

  return temp;
}

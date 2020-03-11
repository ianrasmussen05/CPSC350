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

bool DoublyLinkedList:isEmpty()
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
    nod->prev = back;
  }

  back = node;
  size++;
}

int DoublyLinkedList::removeFront()
{
  int temp = front->data;
  ListNode *ft = front;
  front = front->next;
  ft->next = NULL;
  delete ft;
  --size;

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

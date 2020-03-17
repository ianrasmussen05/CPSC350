#include "NaiveList.h"

NaiveList::NaiveList()
{
  front = NULL;
  size = 0;
}

NaiveList::~NaiveList()
{
  // build some character
}

unsigned int NaiveList::getSize()
{
  return size;
}

bool NaiveList::isEmpty()
{
  return (size == 0);
}

void NaiveList::printList()
{
  ListNode *curr = front;

  while (curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

void NaiveList::insertFront(int d)
{
  ++size;
  ListNode *node = new ListNode(d);
  node->next = front;
  front = node;
}

int NaiveList::removeFront()
{
  int temp = front->data;
  ListNode *ft = front;
  front = front->next;
  ft->next = NULL;
  delete ft;
  --size;

  return temp;
}

int NaiveList::search(int value)
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

int NaiveList::removeAtPosition(int position)
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

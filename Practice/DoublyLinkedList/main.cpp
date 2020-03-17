#include "DoublyLinkedList.h"

int main (int argc, char **argv)
{
  DoublyLinkedList *newList = new DoublyLinkedList();

  newList->insertFront(5);

  for (int i = 0; i < 10; ++i)
  {
    newList->insertBack(i);
  }

  newList->printList();

  newList->remove(6);

  cout << "New List: " << endl;

  newList->printList();

  delete newList;

  return 0;
}

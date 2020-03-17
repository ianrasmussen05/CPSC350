#include "NaiveList.h"

int main (int argc, char **argv)
{
  NaiveList *newList = new NaiveList();

  for (int i = 10; i >= 0; --i)
  {
    newList->insertFront(i);
  }

  newList->printList();

  cout << newList->search(5) << endl;

  delete newList;

  return 0;
}

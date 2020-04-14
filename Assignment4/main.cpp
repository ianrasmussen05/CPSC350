#include <iostream>
#include <string>

using namespace std;

#include "ListNode.h"
#include "LinkedList.h"
#include "Queue.h"

int main(int argc, char **argv)
{
  LinkedList<int> *list = new LinkedList<int>();

  for (int i = 1; i <= 10; ++i)
  {
    list->insertBack(i);
  }

  list->printList();

  delete list;

  return 0;
}

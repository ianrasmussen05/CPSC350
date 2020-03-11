#include <iostream>

using namespace std;

class ListNode
{
public:
  int data;
  ListNode *next;
  ListNode *prev;

  ListNode(); // Default constructor
  ListNode(int d); // Overloaded constructor
  ~ListNode(); // Destructor
};

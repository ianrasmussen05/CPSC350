#include "ListNode.h"

class DoublyLinkedList
{
private:
  ListNode *front;
  ListNode *back;
  unsigned int size;

public:
  DoublyLinkedList(); // Default constructor
  ~DoublyLinkedList(); // Destructor

  void insertFront(int data);
  void insertBack(int data);
  int removeFront();
  int remove(int val);
  int search(int val); // can return value or position of value
  int removeAtPosition(int position);

  unsigned int getSize();
  bool isEmpty();
  void printList();
};

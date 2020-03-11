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
  int search(int value); // can return value or position of value
  int removeAtPosition(int position);

  unsigned int getSize();
  bool isEmpty();
  void printList();
};

class NaiveList
{
private:
  ListNode *front;
  unsigned int size;

public:
  NaiveList(); // Default constructor
  ~NaiveList; // Destructor

  void insertFront(int d);
  int removeFront();
  int search(int value); // can return value or position of value
  int removeAtPosition(int position);

  unsigned int getSize();
  bool isEmpty();
  void printList();
};

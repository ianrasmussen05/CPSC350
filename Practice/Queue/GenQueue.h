#include <iostream>

using namespace std;

class GenQueue
{
  public:
    GenQueue(); // Default consturctor
    GenQueue(int maxSize); // overloaded consturctor
    ~GenQueue(); // Destructor

    // Functions
    void insert(char data); // insert
    char remove(); // remove

    // Helper Functions
    bool isFull();
    bool isEmpty();
    char peek();
    int getSize();
    
    int mSize; // max size of myStack
    int front; // variable to keep track of front of our myStack
    int rear;
    int numElements;

    char *myArray; // array to be used dynamically
};

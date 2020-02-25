#include <iostream>

using namespace std;

class GenQueue
{
  public:
    GenQueue(); // Default consturctor
    GenQueue(int maxSize); // overloaded consturctor
    ~GenQueue(); // Destructor

    // Functions
    void push(char data); // insert
    char pop(); // remove

    // Helper Functions
    bool isFull();
    bool isEmpty();
    char peek();
    int mSize; // max size of myStack
    int top; // variable to keep track of indices representing the
            // top of our myStack
    int front; // variable to keep track of front of our myStack

    char *myArray;
};

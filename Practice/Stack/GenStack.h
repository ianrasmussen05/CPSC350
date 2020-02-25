#include <iostream>

using namespace std;

class GenStack
{
  public:
    GenStack(); // Default consturctor
    GenStack(int maxSize); // overloaded consturctor
    ~GenStack(); // Destructor

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

    char *myArray;
};

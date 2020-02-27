#include "GenStack.h"

int main(int argc, char** argv)
{
  GenStack *myStack = new GenStack(10);
  GenStack *newStack = new GenStack();

  myStack->push('I');
  myStack->push('a');
  myStack->push('n');

  /*
  while (!myStack->isEmpty())
  {
    cout << myStack->pop() << endl;
  }
  */

  for (int i = 0; i < myStack->mSize; ++i)
  {
    cout << myStack->myArray[i];
  }
  cout << endl;

  cout << "Now popping '" << myStack->pop() << "'" << endl;

  cout << "Peek '" << myStack->peek() << "'" << endl;

  delete myStack;
  delete newStack;

  return 0;
}

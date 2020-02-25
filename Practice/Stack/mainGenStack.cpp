#include "GenStack.h"

int main(int argc, char** argv)
{
  GenStack *myStack = new GenStack(14);
  GenStack *newStack = new GenStack();

  myStack->push('I');
  myStack->push('a');
  myStack->push('n');
  myStack->push(' ');
  myStack->push('R');
  myStack->push('a');
  myStack->push('s');
  myStack->push('m');
  myStack->push('u');
  myStack->push('s');
  myStack->push('s');
  myStack->push('e');
  myStack->push('n');


  for (int i = 0; i < myStack->mSize; ++i)
  {
    cout << myStack->myArray[i];
  }
  cout << endl;

  cout << "Now popping '" << myStack->pop() << "'" << endl;

  cout << "Peek '" << myStack->peek() << "'" << endl;

  return 0;
}

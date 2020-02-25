#include "GenQueue.h"

using namespace std;

int main(int argc, char** argv)
{
  GenQueue *myQueue = new GenQueue(14);

  myQueue->push('I');
  myQueue->push('a');
  myQueue->push('n');
  myQueue->push(' ');
  myQueue->push('R');
  myQueue->push('a');
  myQueue->push('s');
  myQueue->push('m');
  myQueue->push('u');
  myQueue->push('s');
  myQueue->push('s');
  myQueue->push('e');
  myQueue->push('n');

  for (int i = 0; i < myQueue->mSize; ++i)
  {
    cout << myQueue->myArray[i];
  }
  cout << endl;
  cout << endl;

  for (int i = 0; i < myQueue->mSize; ++i)
  {
    cout << "Pop: '" << myQueue->pop() <<"'" << endl;
  }

  return 0;
}
